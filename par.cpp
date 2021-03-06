/*
 * avrdude - A Downloader/Uploader for AVR device programmers
 * Copyright (C) 2000-2004  Brian S. Dean <bsd@bsdhome.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* $Id: par.cpp,v 1.1 2007/02/18 06:11:30 lady_ada Exp $ */

#include "ac_cfg.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#if defined(__FreeBSD__)
# include "freebsd_ppi.h"
#elif defined(__linux__)
# include "linux_ppdev.h"
#elif defined(__sun__) && defined(__svr4__) /* Solaris */
# include "solaris_ecpp.h"
#endif

#include "avr.h"
#include "pindefs.h"
#include "pgm.h"
#include "ppi.h"
#include "bitbang.h"

#if HAVE_PARPORT

struct ppipins_t {
  int pin;
  int reg;
  int bit;
  int inverted;
};

struct ppipins_t ppipins[] = {
  {  1, PPICTRL,   0x01, 1 },
  {  2, PPIDATA,   0x01, 0 },
  {  3, PPIDATA,   0x02, 0 },
  {  4, PPIDATA,   0x04, 0 },
  {  5, PPIDATA,   0x08, 0 },
  {  6, PPIDATA,   0x10, 0 },
  {  7, PPIDATA,   0x20, 0 },
  {  8, PPIDATA,   0x40, 0 },
  {  9, PPIDATA,   0x80, 0 },
  { 10, PPISTATUS, 0x40, 0 },
  { 11, PPISTATUS, 0x80, 1 },
  { 12, PPISTATUS, 0x20, 0 },
  { 13, PPISTATUS, 0x10, 0 },
  { 14, PPICTRL,   0x02, 1 }, 
  { 15, PPISTATUS, 0x08, 0 },
  { 16, PPICTRL,   0x04, 0 }, 
  { 17, PPICTRL,   0x08, 1 }
};

#define NPINS (sizeof(ppipins)/sizeof(struct ppipins_t))

static int par_setpin(PROGRAMMER * pgm, int pin, int value)
{

  pin &= PIN_MASK;

  if (pin < 1 || pin > 17)
    return -1;

  pin--;

  if (ppipins[pin].inverted)
    value = !value;

  if (value)
    ppi_set(pgm->fd, ppipins[pin].reg, ppipins[pin].bit);
  else
    ppi_clr(pgm->fd, ppipins[pin].reg, ppipins[pin].bit);

  return 0;
}


static int par_getpin(int fd, int pin)
{
  int value;

  pin &= PIN_MASK;

  if (pin < 1 || pin > 17)
    return -1;

  pin--;

  value = ppi_get(fd, ppipins[pin].reg, ppipins[pin].bit);

  if (value)
    value = 1;
    
  if (ppipins[pin].inverted)
    value = !value;

  return value;
}


static int par_highpulsepin(int fd, int pin)
{

  if (pin < 1 || pin > 17)
    return -1;

  pin--;

  ppi_set(fd, ppipins[pin].reg, ppipins[pin].bit);
  ppi_clr(fd, ppipins[pin].reg, ppipins[pin].bit);

#if SLOW_TOGGLE
  usleep(1000);
#endif

  return 0;
}

int par_getpinmask(int pin)
{
  pin &= PIN_MASK;

  if (pin < 1 || pin > 17)
    return -1;

  return ppipins[pin-1].bit;
}


char vccpins_buf[64];
static char * vccpins_str(unsigned int pmask)
{
  unsigned int mask;
  int pin;
  char b2[8];
  char * b;

  b = vccpins_buf;

  b[0] = 0;
  for (pin = 2, mask = 1; mask < 0x80; mask = mask << 1, pin++) {
    if (pmask & mask) {
      sprintf(b2, "%d", pin);
      if (b[0] != 0)
        strcat(b, ",");
      strcat(b, b2);
    }
  }

  return b;
}


static int par_open(int fd, char * port)
{
  int rc;

  fd = ppi_open(port);
  if (pgm->fd < 0) {
    fprintf(stderr, "%s: failed to open parallel port \"%s\"\n\n",
            progname, port);
  }
  return 0;
}


static void par_close(int fd)
{
  ppi_close(fd);
}

static void par_display(int fd, char * p)
{
  char vccpins[64];
  char buffpins[64];

  if (pgm->pinno[PPI_AVR_VCC]) {
    snprintf(vccpins, sizeof(vccpins), " = pins %s",
             vccpins_str(pgm->pinno[PPI_AVR_VCC]));
  }
  else {
    strcpy(vccpins, " (not used)");
  }

  if (pgm->pinno[PPI_AVR_BUFF]) {
    snprintf(buffpins, sizeof(buffpins), " = pins %s", 
             vccpins_str(pgm->pinno[PPI_AVR_BUFF]));
  }
  else {
    strcpy(buffpins, " (not used)");
  }

  fprintf(stderr, 
          "%s  VCC     = 0x%02x%s\n"
          "%s  BUFF    = 0x%02x%s\n"
          "%s  RESET   = %d\n"
          "%s  SCK     = %d\n"
          "%s  MOSI    = %d\n"
          "%s  MISO    = %d\n"
          "%s  ERR LED = %d\n"
          "%s  RDY LED = %d\n"
          "%s  PGM LED = %d\n"
          "%s  VFY LED = %d\n",

          p, pgm->pinno[PPI_AVR_VCC], vccpins,
          p, pgm->pinno[PPI_AVR_BUFF], buffpins,
          p, pgm->pinno[PIN_AVR_RESET],
          p, pgm->pinno[PIN_AVR_SCK],
          p, pgm->pinno[PIN_AVR_MOSI],
          p, pgm->pinno[PIN_AVR_MISO],
          p, pgm->pinno[PIN_LED_ERR],
          p, pgm->pinno[PIN_LED_RDY],
          p, pgm->pinno[PIN_LED_PGM],
          p, pgm->pinno[PIN_LED_VFY]);
}

/*
 * parse the -E string
 */
static int par_getexitspecs(PROGRAMMER * pgm, char *s, int *set, int *clr)
{
  char *cp;

  while ((cp = strtok(s, ","))) {
    if (strcmp(cp, "reset") == 0) {
      *clr |= par_getpinmask(pgm->pinno[PIN_AVR_RESET]);
    }
    else if (strcmp(cp, "noreset") == 0) {
      *set |= par_getpinmask(pgm->pinno[PIN_AVR_RESET]);
    }
    else if (strcmp(cp, "vcc") == 0) {
      if (pgm->pinno[PPI_AVR_VCC])
        *set |= pgm->pinno[PPI_AVR_VCC];
    }
    else if (strcmp(cp, "novcc") == 0) {
      if (pgm->pinno[PPI_AVR_VCC])
        *clr |= pgm->pinno[PPI_AVR_VCC];
    }
    else {
      return -1;
    }
    s = 0; /* strtok() should be called with the actual string only once */
  }

  return 0;
}



void par_initpgm(PROGRAMMER * pgm)
{
  strcpy(pgm->type, "PPI");

  pgm->rdy_led        = bitbang_rdy_led;
  pgm->err_led        = bitbang_err_led;
  pgm->pgm_led        = bitbang_pgm_led;
  pgm->vfy_led        = bitbang_vfy_led;
  pgm->initialize     = bitbang_initialize;
  pgm->display        = par_display;
  pgm->enable         = par_enable;
  pgm->disable        = par_disable;
  pgm->powerup        = par_powerup;
  pgm->powerdown      = par_powerdown;
  pgm->program_enable = bitbang_program_enable;
  pgm->chip_erase     = bitbang_chip_erase;
  pgm->cmd            = bitbang_cmd;
  pgm->open           = par_open;
  pgm->close          = par_close;
  pgm->setpin         = par_setpin;
  pgm->getpin         = par_getpin;
  pgm->highpulsepin   = par_highpulsepin;
  pgm->getexitspecs   = par_getexitspecs;
}

#else  /* !HAVE_PARPORT */

void par_initpgm(PROGRAMMER * pgm)
{
  fprintf(stderr,
	  "%s: parallel port access not available in this configuration\n",
	  progname);
}

#endif /* HAVE_PARPORT */
