# =========================================================================
#     This makefile was generated by
#     Bakefile 0.2.0 (http://bakefile.sourceforge.net)
#     Do not modify, all changes will be overwritten!
# =========================================================================




prefix = /usr/local
exec_prefix = ${prefix}
INSTALL = /usr/bin/install -c
EXEEXT = 
WINDRES = 
REZ = /Developer/Tools/Rez
SETFILE = /Developer/Tools/SetFile
NM = nm
srcdir = ..
top_srcdir = ..
top_builddir = ./
LDFLAGS_GUI = 
CXX = g++
#DEBUG = -D__WXDEBUG__
DEBUGTRUE = no
#ARCH_FLAGS = "-arch i386"
#ARCH_FLAGS = ""
CXXFLAGS = ${ARCH_FLAGS} -O2 -fno-strict-aliasing -Wall -Wundef -Wno-ctor-dtor-privacy -fno-common
CPPFLAGS = ${ARCH_FLAGS} -DWX_PRECOMP ${DEBUG} -I/opt/local/include -lusb -I${top_builddir}lib/wx/include/osx_cocoa-unicode-2.9  `/opt/local/bin/wx-config --cxxflags --debug=${DEBUGTRUE}`  -fpascal-strings -I${top_srcdir}/src/mac/carbon/morefilex -I/Developer/Headers/FlatCarbon 
LDFLAGS =  `/opt/local/bin/wx-config --libs` -L/opt/local/include -lusb
WX_LIB_FLAVOUR = 
TOOLKIT = MAC
TOOLKIT_LOWERCASE = osx_cocoa
TOOLKIT_VERSION = 
TOOLCHAIN_FULLNAME = mac-ansi-release-static-2.9
EXTRALIBS =  
EXTRALIBS_GUI = -framework WebKit
EXTRALIBS_SDL = 
HOST_SUFFIX = 
SAMPLES_RPATH_FLAG = 
SAMPLES_RPATH_POSTLINK = 

### Variables: ###

DESTDIR = 
WX_RELEASE = 2.9
WX_VERSION = $(WX_RELEASE).3
LIBDIRNAME = $(top_builddir)lib
SPOKEPOV_CXXFLAGS = -D__WX$(TOOLKIT)__ ${DEBUG} $(__WXUNIV_DEFINE_p) \
	$(__EXCEPTIONS_DEFINE_p) $(__RTTI_DEFINE_p) $(__THREAD_DEFINE_p) \
	-I$(srcdir) $(__DLLFLAG_p) $(CPPFLAGS) $(CXXFLAGS)
SPOKEPOV_OBJECTS =  \
	$(__spokepov___win32rc) \
	$(__spokepov_os2_lib_res) \
	spokepov.o wheelpanel.o communication.o serbb_posix.o imagemessagebox.o

### Conditionally set variables: ###

#CXXC = $(CXX)
CXXC = $(top_builddir)./bk-deps $(CXX)
PLUGIN_ADV_EXTRALIBS = $(EXTRALIBS_SDL)
#PORTNAME = base
PORTNAME = $(TOOLKIT_LOWERCASE)$(TOOLKIT_VERSION)
WXBASEPORT = 
#WXDEBUGFLAG = d
#WXDEBUGFLAG = d
WXUNICODEFLAG = u
#WXUNIVNAME = univ
EXTRALIBS_FOR_BASE = $(EXTRALIBS)
#EXTRALIBS_FOR_BASE = $(EXTRALIBS) $(EXTRALIBS_GUI)
EXTRALIBS_FOR_GUI = $(EXTRALIBS_GUI)
#EXTRALIBS_FOR_GUI = 
__spokepov___mac_setfilecmd = \
	$(SETFILE) -a C spokepov$(EXEEXT)
__spokepov___mac_rezcmd = $(__MACOSX_RESOURCES_p_1)
#__WXUNIV_DEFINE_p = -D__WXUNIVERSAL__
#__WXUNIV_DEFINE_p_1 = -d __WXUNIVERSAL__
#__WXUNIV_DEFINE_p_2 = --define __WXUNIVERSAL__
#__EXCEPTIONS_DEFINE_p = -DwxNO_EXCEPTIONS
#__EXCEPTIONS_DEFINE_p_1 = -d wxNO_EXCEPTIONS
#__EXCEPTIONS_DEFINE_p_2 = --define wxNO_EXCEPTIONS
#__RTTI_DEFINE_p = -DwxNO_RTTI
#__RTTI_DEFINE_p_1 = -d wxNO_RTTI
#__RTTI_DEFINE_p_2 = --define wxNO_RTTI
#__THREAD_DEFINE_p = -DwxNO_THREADS
#__THREAD_DEFINE_p_1 = -d wxNO_THREADS
#__THREAD_DEFINE_p_2 = --define wxNO_THREADS
#__DLLFLAG_p = -DWXUSINGDLL
#__DLLFLAG_p_1 = -d WXUSINGDLL
#__DLLFLAG_p_2 = --define WXUSINGDLL
COND_PLATFORM_OS2_1___spokepov___os2_emxbindcmd = $(NM) spokepov$(EXEEXT) | if grep \
	-q pmwin.763 ; then emxbind -ep spokepov$(EXEEXT) ; fi
#__splash___os2_emxbindcmd = $(COND_PLATFORM_OS2_1___splash___os2_emxbindcmd)
#__RCDEFDIR_p = -i \
#	$(LIBDIRNAME)/wx/include/$(TOOLCHAIN_FULLNAME)
#__RCDEFDIR_p_1 = --include-dir \
#	$(LIBDIRNAME)/wx/include/$(TOOLCHAIN_FULLNAME)
#__splash_os2_lib_res = \
#	$(top_srcdir)/include/wx/os2/wx.res
__spokepov_bundle___depname = spokepov_bundle
#____splash_BUNDLE_TGT_REF_DEP = \
#	splash.app/Contents/PkgInfo
____spokepov_BUNDLE_TGT_REF_DEP = \
	spokepov.app/Contents/PkgInfo
#COND_MONOLITHIC_0___WXLIB_MEDIA_p = \
#	-lwx_$(PORTNAME)$(WXUNIVNAME)$(WXUNICODEFLAG)$(WXDEBUGFLAG)$(WX_LIB_FLAVOUR)_media-$(WX_RELEASE)$(HOST_SUFFIX)
#__WXLIB_MEDIA_p = $(COND_MONOLITHIC_0___WXLIB_MEDIA_p)
COND_MONOLITHIC_0___WXLIB_ADV_p = \
	-lwx_$(PORTNAME)$(WXUNIVNAME)$(WXUNICODEFLAG)$(WXDEBUGFLAG)$(WX_LIB_FLAVOUR)_adv-$(WX_RELEASE)$(HOST_SUFFIX)
__WXLIB_ADV_p = $(COND_MONOLITHIC_0___WXLIB_ADV_p)
COND_MONOLITHIC_0___WXLIB_CORE_p = \
	-lwx_$(PORTNAME)$(WXUNIVNAME)$(WXUNICODEFLAG)$(WXDEBUGFLAG)$(WX_LIB_FLAVOUR)_core-$(WX_RELEASE)$(HOST_SUFFIX)
__WXLIB_CORE_p = $(COND_MONOLITHIC_0___WXLIB_CORE_p)
COND_MONOLITHIC_0___WXLIB_BASE_p = \
	-lwx_base$(WXBASEPORT)$(WXUNICODEFLAG)$(WXDEBUGFLAG)$(WX_LIB_FLAVOUR)-$(WX_RELEASE)$(HOST_SUFFIX)
__WXLIB_BASE_p = $(COND_MONOLITHIC_0___WXLIB_BASE_p)
#__splash___win32rc = splash_sample_rc.o
COND_MONOLITHIC_1___WXLIB_MONO_p = \
	-lwx_$(PORTNAME)$(WXUNIVNAME)$(WXUNICODEFLAG)$(WXDEBUGFLAG)$(WX_LIB_FLAVOUR)-$(WX_RELEASE)$(HOST_SUFFIX)
#__WXLIB_MONO_p = $(COND_MONOLITHIC_1___WXLIB_MONO_p)
#__LIB_TIFF_p \
#	= \
#	-lwxtiff$(WXDEBUGFLAG)$(WX_LIB_FLAVOUR)-$(WX_RELEASE)$(HOST_SUFFIX)
#__LIB_JPEG_p \
	#= \
	#-lwxjpeg$(WXDEBUGFLAG)$(WX_LIB_FLAVOUR)-$(WX_RELEASE)$(HOST_SUFFIX)
#__LIB_PNG_p \
	#= \
	#-lwxpng$(WXDEBUGFLAG)$(WX_LIB_FLAVOUR)-$(WX_RELEASE)$(HOST_SUFFIX)
#__LIB_ZLIB_p = \
#	-lwxzlib$(WXDEBUGFLAG)$(WX_LIB_FLAVOUR)-$(WX_RELEASE)$(HOST_SUFFIX)
#__LIB_ODBC_p = \
#	-lwxodbc$(WXDEBUGFLAG)$(WX_LIB_FLAVOUR)-$(WX_RELEASE)$(HOST_SUFFIX)
COND_WXUSE_REGEX_BUILTIN___LIB_REGEX_p = \
	-lwxregex$(WXUNICODEFLAG)$(WXDEBUGFLAG)$(WX_LIB_FLAVOUR)-$(WX_RELEASE)$(HOST_SUFFIX)
#__LIB_REGEX_p = $(COND_WXUSE_REGEX_BUILTIN___LIB_REGEX_p)
#__LIB_EXPAT_p = \
	#-lwxexpat$(WXDEBUGFLAG)$(WX_LIB_FLAVOUR)-$(WX_RELEASE)$(HOST_SUFFIX)
COND_TOOLKIT_MAC___MACOSX_RESOURCES_p_1 = $(REZ) -d __DARWIN__ -t APPL -d \
	__WX$(TOOLKIT)__ $(__WXUNIV_DEFINE_p_1) $(__EXCEPTIONS_DEFINE_p_1) \
	$(__RTTI_DEFINE_p_1) $(__THREAD_DEFINE_p_1) -i $(srcdir) $(__DLLFLAG_p_1) -i \
	$(srcdir)/../../samples $(__RCDEFDIR_p) -i $(top_srcdir)/include -o \
	spokepov$(EXEEXT) Carbon.r
__MACOSX_RESOURCES_p_1 = $(COND_TOOLKIT_MAC___MACOSX_RESOURCES_p_1)

### Targets: ###

all: spokepov$(EXEEXT) $(__spokepov_bundle___depname) data

install: all

uninstall: 

install-strip: install

clean: 
	rm -rf ./.deps ./.pch
	rm -f ./*.o
	rm -f spokepov$(EXEEXT)
	rm -rf spokepov.app

distclean: clean
	rm -f config.cache config.log config.status bk-deps bk-make-pch shared-ld-sh Makefile

spokepov$(EXEEXT): $(SPOKEPOV_OBJECTS) $(__spokepov___win32rc)
	$(CXX) -o $@ $(SPOKEPOV_OBJECTS) $(LDFLAGS)  $(LDFLAGS_GUI) $(SAMPLES_RPATH_FLAG)  $(__WXLIB_MEDIA_p)  $(__WXLIB_ADV_p) $(PLUGIN_ADV_EXTRALIBS) $(__WXLIB_CORE_p)  $(__WXLIB_BASE_p)  $(__WXLIB_MONO_p) $(__LIB_TIFF_p) $(__LIB_JPEG_p) $(__LIB_PNG_p) $(__LIB_ZLIB_p) $(__LIB_ODBC_p) $(__LIB_REGEX_p) $(__LIB_EXPAT_p) $(EXTRALIBS_FOR_BASE) $(EXTRALIBS_FOR_GUI)
	$(__spokepov___mac_rezcmd)
	$(__spokepov___mac_setfilecmd)
	$(__spokepov___os2_emxbindcmd)
	$(SAMPLES_RPATH_POSTLINK)

spokepov.app/Contents/PkgInfo: spokepov$(EXEEXT) Info.plist.in wxmac.icns
	mkdir -p spokepov.app/Contents
	mkdir -p spokepov.app/Contents/MacOS
	mkdir -p spokepov.app/Contents/Resources
	
	
	sed -e "s/IDENTIFIER/`echo $(srcdir) | sed -e 's,\.\./,,g' | sed -e 's,/,.,g'`/" \
	-e "s/EXECUTABLE/spokepov/" \
	-e "s/VERSION/$(WX_VERSION)/" \
	Info.plist.in >spokepov.app/Contents/Info.plist
	
	
	echo -n "APPL????" >spokepov.app/Contents/PkgInfo
	
	
	ln -f spokepov$(EXEEXT) spokepov.app/Contents/MacOS/spokepov
	
	
	cp -f wxmac.icns spokepov.app/Contents/Resources/wxmac.icns

spokepov_bundle: $(____spokepov_BUNDLE_TGT_REF_DEP)

data: 
	@mkdir -p .
	@for f in ; do \
	if test ! -f ./$$f -a ! -d ./$$f ; \
	then x=yep ; \
	else x=`find $(srcdir)/$$f -newer ./$$f -print` ; \
	fi; \
	case "$$x" in ?*) \
	cp -pRf $(srcdir)/$$f . ;; \
	esac; \
	done


%.o: $(srcdir)/%.cpp
	$(CXXC) -c -o $@ $(SPOKEPOV_CXXFLAGS) $<

spokepov_rc.o: $(srcdir)/sample.rc
#	$(WINDRES) -i$< -o$@   --define __WX$(TOOLKIT)__ $(__WXUNIV_DEFINE_p_2)  $(__EXCEPTIONS_DEFINE_p_2) $(__RTTI_DEFINE_p_2) $(__THREAD_DEFINE_p_2)   --include-dir $(srcdir) $(__DLLFLAG_p_2) --include-dir $(__RCDEFDIR_p_1) --include-dir $(top_srcdir)/include --include-dir /opt/local/include/wx-2.8/wx
	$(WINDRES) -i$< -o$@   --define __WX$(TOOLKIT)__ $(__WXUNIV_DEFINE_p_2)  $(__EXCEPTIONS_DEFINE_p_2) $(__RTTI_DEFINE_p_2) $(__THREAD_DEFINE_p_2)   --include-dir $(srcdir) $(__DLLFLAG_p_2) --include-dir $(__RCDEFDIR_p_1) --include-dir $(top_srcdir)/include --include-dir /Users/ladyada/Desktop/wxMac-2.8.8/osxbuild/include



# Include dependency info, if present:
-include .deps/*.d

.PHONY: all install uninstall clean distclean spokepov_bundle data
