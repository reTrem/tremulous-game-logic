#
# Tremulous Makefile
#
# GNU Make required

#############################################################################
# *** WARNING ***
# DO NOT MODIFY THIS FILE.
#
# If you require a different configuration from the defaults below, create a
# new file named "GNUmakefile.local" in the same directory as this file and define
# your parameters there. This allows you to change configuration without
# causing problems with keeping up to date with the repository.
#
#############################################################################

COMPILE_PLATFORM=$(shell uname|sed -e s/_.*//|tr '[:upper:]' '[:lower:]'|sed -e 's/\//_/g')

COMPILE_ARCH=$(shell uname -m | sed -e s/i.86/x86/)

ifeq ($(COMPILE_PLATFORM),sunos)
  # Solaris uname and GNU uname differ
  COMPILE_ARCH=$(shell uname -p | sed -e s/i.86/x86/)
endif

#############################################################################
#
# Switches that can be defined in your GNUmakefile.local file
#
#############################################################################

# Build the client executable
ifndef BUILD_CLIENT
  BUILD_CLIENT          =
endif

# Build the server executable
ifndef BUILD_SERVER
  BUILD_SERVER          =
endif

# Build game shared libraries
ifndef BUILD_GAME_SO
  BUILD_GAME_SO         =
endif

# Build cgame and ui Quake virtual machine files
ifndef BUILD_CGAME_UI_QVM
  BUILD_CGAME_UI_QVM    =
endif

#Build cgame and ui shared libraries
ifndef BUILD_CGAME_UI_SO
  BUILD_CGAME_UI_SO     =
endif

# Build game Quake virtual machine files for GPP
ifndef BUILD_CGAME_UI_QVM_11
  BUILD_CGAME_UI_QVM_11 =
endif

#Build cgame and ui shared libraries for GPP
ifndef BUILD_CGAME_UI_SO_11
  BUILD_CGAME_UI_SO_11  =
endif

ifndef BUILD_RENDERER_OPENGL2
  BUILD_RENDERER_OPENGL2=
endif

# Include local customizations
-include GNUmakefile.local

include $(SETTINGS_MAKEFILES)

ifeq ($(COMPILE_PLATFORM),cygwin)
  PLATFORM=mingw32
endif

ifndef PLATFORM
PLATFORM=$(COMPILE_PLATFORM)
endif
export PLATFORM

ifeq ($(COMPILE_ARCH),i86pc)
  COMPILE_ARCH=x86
endif

ifeq ($(COMPILE_ARCH),amd64)
  COMPILE_ARCH=x86_64
endif
ifeq ($(COMPILE_ARCH),x64)
  COMPILE_ARCH=x86_64
endif

ifeq ($(COMPILE_ARCH),powerpc)
  COMPILE_ARCH=ppc
endif
ifeq ($(COMPILE_ARCH),powerpc64)
  COMPILE_ARCH=ppc64
endif

ifeq ($(COMPILE_ARCH),axp)
  COMPILE_ARCH=alpha
endif

ifndef ARCH
ARCH=$(COMPILE_ARCH)
endif
export ARCH

ifneq ($(PLATFORM),$(COMPILE_PLATFORM))
  CROSS_COMPILING=1
else
  CROSS_COMPILING=0

  ifneq ($(ARCH),$(COMPILE_ARCH))
    CROSS_COMPILING=1
  endif
endif
export CROSS_COMPILING

ifndef VERSION
VERSION=gpp1
endif

ifndef CLIENTBIN
CLIENTBIN=tremulous
endif

ifndef SERVERBIN
SERVERBIN=tremded
endif

ifndef BASEGAME
BASEGAME=gpp
endif

ifndef BASEGAME_CFLAGS
BASEGAME_CFLAGS=
endif

ifndef COPYDIR
COPYDIR="/usr/local/games/tremulous"
endif

ifndef COPYBINDIR
COPYBINDIR=$(COPYDIR)
endif

ifndef MOUNT_DIR
MOUNT_DIR=src
endif

ifndef DEP_DIR
DEP_DIR=dep
endif

ifndef BUILD_DIR
BUILD_DIR=bld
endif

ifndef TEMPDIR
TEMPDIR=/tmp
endif

ifndef GENERATE_DEPENDENCIES
GENERATE_DEPENDENCIES=1
endif

ifndef USE_OPENAL
USE_OPENAL=1
endif

ifndef USE_OPENAL_DLOPEN
USE_OPENAL_DLOPEN=1
endif

ifndef USE_CURL
USE_CURL=1
endif

ifndef USE_CURL_DLOPEN
  ifeq ($(PLATFORM),mingw32)
    USE_CURL_DLOPEN=0
  else
    USE_CURL_DLOPEN=1
  endif
endif

ifndef USE_CODEC_VORBIS
USE_CODEC_VORBIS=0
endif

ifndef USE_CODEC_OPUS
USE_CODEC_OPUS=1
endif

ifndef USE_MUMBLE
USE_MUMBLE=0
endif

ifndef USE_VOIP
USE_VOIP=0
endif

ifndef USE_FREETYPE
USE_FREETYPE=0
endif

ifndef USE_INTERNAL_LIBS
USE_INTERNAL_LIBS=1
endif

ifndef USE_INTERNAL_SPEEX
USE_INTERNAL_SPEEX=$(USE_INTERNAL_LIBS)
endif

ifndef USE_INTERNAL_OGG
USE_INTERNAL_OGG=$(USE_INTERNAL_LIBS)
endif

ifndef USE_INTERNAL_VORBIS
USE_INTERNAL_VORBIS=$(USE_INTERNAL_LIBS)
endif

ifndef USE_INTERNAL_OPUS
USE_INTERNAL_OPUS=$(USE_INTERNAL_LIBS)
endif

ifndef USE_INTERNAL_ZLIB
USE_INTERNAL_ZLIB=$(USE_INTERNAL_LIBS)
endif

ifndef USE_INTERNAL_MINIZIP
USE_INTERNAL_MINIZIP=$(USE_INTERNAL_LIBS)
endif

ifndef USE_INTERNAL_JPEG
USE_INTERNAL_JPEG=$(USE_INTERNAL_LIBS)
endif

ifndef BUILD_MASTER_SERVER
BUILD_MASTER_SERVER=0
endif

ifndef USE_RENDERER_DLOPEN
USE_RENDERER_DLOPEN=1
endif

ifndef DEBUG_CFLAGS
DEBUG_CFLAGS=-g -O0
endif

#############################################################################

BD=$(BUILD_DIR) # /debug-$(PLATFORM)-$(ARCH)
BR=$(BUILD_DIR) # /release-$(PLATFORM)-$(ARCH)
OUT=out
CDIR=$(MOUNT_DIR)/client
SDIR=$(MOUNT_DIR)/server
RCOMMONDIR=$(MOUNT_DIR)/renderercommon
RGL1DIR=$(MOUNT_DIR)/renderergl1
RGL2DIR=$(MOUNT_DIR)/renderergl2
CMDIR=$(MOUNT_DIR)/qcommon
SDLDIR=$(MOUNT_DIR)/sdl
ASMDIR=$(MOUNT_DIR)/asm
SYSDIR=$(MOUNT_DIR)/sys
GDIR=$(MOUNT_DIR)/game
CGDIR=$(MOUNT_DIR)/cgame
NDIR=$(MOUNT_DIR)/null
UIDIR=$(MOUNT_DIR)/ui
JPDIR=$(DEP_DIR)/jpeg-8c
SPEEXDIR=$(DEP_DIR)/libspeex
OGGDIR=$(DEP_DIR)/libogg-1.3.1
VORBISDIR=$(DEP_DIR)/libvorbis-1.3.4
OPUSDIR=$(DEP_DIR)/opus-1.1
OPUSFILEDIR=$(DEP_DIR)/opusfile-0.5
ZDIR=$(DEP_DIR)/zlib
MINIZIPDIR=$(DEP_DIR)/minizip
Q3ASMDIR=$(MOUNT_DIR)/tools/asm
LBURGDIR=$(MOUNT_DIR)/tools/lcc/lburg
Q3CPPDIR=$(MOUNT_DIR)/tools/lcc/cpp
Q3LCCETCDIR=$(MOUNT_DIR)/tools/lcc/etc
Q3LCCSRCDIR=$(MOUNT_DIR)/tools/lcc/src
SDLHDIR=$(DEP_DIR)/sdl2
LIBSDIR=$(DEP_DIR)/libs
MASTERDIR=$(MOUNT_DIR)/master
TEMPDIR=/tmp

bin_path=$(shell which $(1) 2> /dev/null)

# We won't need this if we only build the server
ifneq ($(BUILD_CLIENT),0)
  # set PKG_CONFIG_PATH to influence this, e.g.
  # PKG_CONFIG_PATH=/opt/cross/i386-mingw32msvc/lib/pkgconfig
  ifneq ($(call bin_path, pkg-config),)
    CURL_CFLAGS ?= $(shell pkg-config --silence-errors --cflags libcurl)
    CURL_LIBS ?= $(shell pkg-config --silence-errors --libs libcurl)
    OPENAL_CFLAGS ?= $(shell pkg-config --silence-errors --cflags openal)
    OPENAL_LIBS ?= $(shell pkg-config --silence-errors --libs openal)
    SDL_CFLAGS ?= $(shell pkg-config --silence-errors --cflags sdl2)
    SDL_LIBS ?= $(shell pkg-config --silence-errors --libs sdl2)
  else
    # assume they're in the system default paths (no -I or -L needed)
    CURL_LIBS ?= -lcurl
    OPENAL_LIBS ?= -lopenal
  endif
endif

# Add git version info
ifneq ($(USE_GIT),0)
  USE_GIT=
  ifeq ($(wildcard .git),.git)
    GIT_REV=$(shell git show -s --pretty=format:%h-%ad --date=short)
    ifneq ($(GIT_REV),)
      VERSION:=$(VERSION)_GIT_$(GIT_REV)
      USE_GIT=1
    endif
  endif
endif


#############################################################################
# SETUP AND BUILD -- LINUX
#############################################################################

## Defaults
LIB=lib

INSTALL=install
MKDIR=mkdir
EXTRA_FILES=
CLIENT_EXTRA_FILES=

ifneq (,$(findstring "$(PLATFORM)", "linux" "gnu_kfreebsd" "kfreebsd-gnu"))

  ifeq ($(ARCH),x86_64)
    LIB=lib64
  else
  ifeq ($(ARCH),ppc64)
    LIB=lib64
  else
  ifeq ($(ARCH),s390x)
    LIB=lib64
  endif
  endif
  endif

  BASE_CFLAGS = -Wall -fno-strict-aliasing -Wimplicit -Wstrict-prototypes \
    -pipe -DUSE_ICON
  CLIENT_CFLAGS += $(SDL_CFLAGS)

  OPTIMIZEVM = -O3
  OPTIMIZE = $(OPTIMIZEVM)

  ifeq ($(ARCH),x86_64)
    OPTIMIZEVM = -O3
    OPTIMIZE = $(OPTIMIZEVM)
    HAVE_VM_COMPILED = true
  else
  ifeq ($(ARCH),x86)
    OPTIMIZEVM = -O3 -march=i586
    OPTIMIZE = $(OPTIMIZEVM)
    HAVE_VM_COMPILED=true
  else
  ifeq ($(ARCH),ppc)
    BASE_CFLAGS += -maltivec
    HAVE_VM_COMPILED=true
  endif
  ifeq ($(ARCH),ppc64)
    BASE_CFLAGS += -maltivec
    HAVE_VM_COMPILED=true
  endif
  ifeq ($(ARCH),sparc)
    OPTIMIZE += -mtune=ultrasparc3 -mv8plus
    OPTIMIZEVM += -mtune=ultrasparc3 -mv8plus
    HAVE_VM_COMPILED=true
  endif
  ifeq ($(ARCH),alpha)
    # According to http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=410555
    # -ffast-math will cause the client to die with SIGFPE on Alpha
    OPTIMIZE = $(OPTIMIZEVM)
  endif
  endif
  endif

  SHLIBEXT=so
  SHLIBCFLAGS=-fPIC -fvisibility=hidden
  SHLIBLDFLAGS=-shared $(LDFLAGS)

  THREAD_LIBS=-lpthread
  LIBS=-ldl -lm

  CLIENT_LIBS=$(SDL_LIBS)
  RENDERER_LIBS = $(SDL_LIBS) -lGL

  ifeq ($(USE_OPENAL),1)
    CLIENT_CFLAGS += $(OPENAL_CFLAGS)
    ifneq ($(USE_OPENAL_DLOPEN),1)
      CLIENT_LIBS += $(THREAD_LIBS) $(OPENAL_LIBS)
    endif
  endif

  ifeq ($(USE_CURL),1)
    CLIENT_CFLAGS += $(CURL_CFLAGS)
    ifneq ($(USE_CURL_DLOPEN),1)
      CLIENT_LIBS += $(CURL_LIBS)
    endif
  endif

  ifeq ($(USE_MUMBLE),1)
    CLIENT_LIBS += -lrt
  endif

  ifeq ($(ARCH),x86)
    # linux32 make ...
    BASE_CFLAGS += -m32
  else
  ifeq ($(ARCH),ppc64)
    BASE_CFLAGS += -m64
  endif
  endif
else # ifeq Linux

#############################################################################
# SETUP AND BUILD -- MAC OS X
#############################################################################

ifeq ($(PLATFORM),darwin)
  HAVE_VM_COMPILED=true
  LIBS = -framework Cocoa
  CLIENT_LIBS=
  RENDERER_LIBS=
  OPTIMIZEVM=

  BASE_CFLAGS = -Wall -Wimplicit -Wstrict-prototypes -mmacosx-version-min=10.5 \
    -DMAC_OS_X_VERSION_MIN_REQUIRED=1050

  ifeq ($(ARCH),ppc)
    BASE_CFLAGS += -arch ppc -faltivec
    OPTIMIZEVM += -O3
  endif
  ifeq ($(ARCH),ppc64)
    BASE_CFLAGS += -arch ppc64 -faltivec
  endif
  ifeq ($(ARCH),x86)
    OPTIMIZEVM += -march=prescott -mfpmath=sse
    # x86 vm will crash without -mstackrealign since MMX instructions will be
    # used no matter what and they corrupt the frame pointer in VM calls
    BASE_CFLAGS += -arch i386 -m32 -mstackrealign
  endif
  ifeq ($(ARCH),x86_64)
    OPTIMIZEVM += -arch x86_64 -mfpmath=sse
  endif

  # When compiling on OSX for OSX, we're not cross compiling as far as the
  # Makefile is concerned, as target architecture is specified as a compiler
  # argument
  ifeq ($(COMPILE_PLATFORM),darwin)
    CROSS_COMPILING=0
  endif

  ifeq ($(CROSS_COMPILING),1)
    ifeq ($(ARCH),x86_64)
      CC=x86_64-apple-darwin13-cc
      RANLIB=x86_64-apple-darwin13-ranlib
    else
      ifeq ($(ARCH),x86)
        CC=i386-apple-darwin13-cc
        RANLIB=i386-apple-darwin13-ranlib
      else
        $(error Architecture $(ARCH) is not supported when cross compiling)
      endif
    endif
  else
    TOOLS_CFLAGS += -DMACOS_X
  endif

  BASE_CFLAGS += -fno-strict-aliasing -DMACOS_X -fno-common -pipe

  #
  # FIXME: This is a workaround for broken OSX build. BASE_CFLAGS is either
  # not setup correctly, or is being reset durring the build.
  #
  BASE_CFLAGS += -I$(SDLHDIR)/include \
				 -I$(OPUSFILEDIR)/include \
    			 -DOPUS_BUILD -DHAVE_LRINTF -DFLOATING_POINT -DUSE_ALLOCA \
          		 -I$(OPUSDIR)/include -I$(OPUSDIR)/celt -I$(OPUSDIR)/silk \
          		 -I$(OPUSDIR)/silk/float -I$(OPUSFILEDIR)/include


  ifeq ($(USE_OPENAL),1)
    CLIENT_CFLAGS += $(OPENAL_CFLAGS)
    ifneq ($(USE_OPENAL_DLOPEN),1)
      CLIENT_LIBS += -framework OpenAL
    endif
  endif

  ifeq ($(USE_CURL),1)
    CLIENT_CFLAGS += $(CURL_CFLAGS)
    ifneq ($(USE_CURL_DLOPEN),1)
      CLIENT_LIBS += $(CURL_LIBS)
    endif
  endif

  BASE_CFLAGS += -D_THREAD_SAFE=1

  BASE_CFLAGS += -I$(SDLHDIR)/include
  BASE_CFLAGS += -I$(DEP_DIR)

  # We copy sdlmain before ranlib'ing it so that subversion doesn't think
  #  the file has been modified by each build.
  LIBSDLMAIN=$(B)/libSDL2main.a
  LIBSDLMAINSRC=$(LIBSDIR)/macosx/libSDL2main.a
  CLIENT_LIBS += -framework IOKit \
    $(LIBSDIR)/macosx/libSDL2-2.0.0.dylib
  RENDERER_LIBS += -framework OpenGL $(LIBSDIR)/macosx/libSDL2-2.0.0.dylib
  CLIENT_EXTRA_FILES += $(LIBSDIR)/macosx/libSDL2-2.0.0.dylib

  OPTIMIZE = $(OPTIMIZEVM)

  SHLIBEXT=dylib
  SHLIBCFLAGS=-fPIC -fno-common
  SHLIBLDFLAGS=-dynamiclib $(LDFLAGS) -Wl,-U,_com_altivec

  NOTSHLIBCFLAGS=-mdynamic-no-pic

else # ifeq darwin


#############################################################################
# SETUP AND BUILD -- MINGW32
#############################################################################

ifeq ($(PLATFORM),mingw32)

  ifeq ($(CROSS_COMPILING),1)
    # If CC is already set to something generic, we probably want to use
    # something more specific
    ifneq ($(findstring $(strip $(CC)),cc gcc),)
      CC=
    endif

    # We need to figure out the correct gcc and windres
    ifeq ($(ARCH),x86_64)
      MINGW_PREFIXES=amd64-mingw32msvc x86_64-w64-mingw32
    endif
    ifeq ($(ARCH),x86)
      MINGW_PREFIXES=i586-mingw32msvc i686-w64-mingw32
    endif

    ifndef CC
      CC=$(strip $(foreach MINGW_PREFIX, $(MINGW_PREFIXES), \
         $(call bin_path, $(MINGW_PREFIX)-gcc)))
    endif

    ifndef WINDRES
      WINDRES=$(strip $(foreach MINGW_PREFIX, $(MINGW_PREFIXES), \
         $(call bin_path, $(MINGW_PREFIX)-windres)))
    endif
  else
    # Some MinGW installations define CC to cc, but don't actually provide cc,
    # so check that CC points to a real binary and use gcc if it doesn't
    ifeq ($(call bin_path, $(CC)),)
      CC=gcc
    endif

    ifndef WINDRES
      WINDRES=windres
    endif
  endif

  ifeq ($(CC),)
    $(error Cannot find a suitable cross compiler for $(PLATFORM))
  endif

  BASE_CFLAGS = -Wall -fno-strict-aliasing -Wimplicit -Wstrict-prototypes \
    -DUSE_ICON

  # In the absence of wspiapi.h, require Windows XP or later
  ifeq ($(shell test -e $(CMDIR)/wspiapi.h; echo $$?),1)
    BASE_CFLAGS += -DWINVER=0x501
  endif

  ifeq ($(USE_OPENAL),1)
    CLIENT_CFLAGS += $(OPENAL_CFLAGS)
    ifneq ($(USE_OPENAL_DLOPEN),1)
      CLIENT_LDFLAGS += $(OPENAL_LIBS)
    endif
  endif

  ifeq ($(ARCH),x86_64)
    OPTIMIZEVM = -O3
    OPTIMIZE = $(OPTIMIZEVM)
    HAVE_VM_COMPILED = true
  endif
  ifeq ($(ARCH),x86)
    OPTIMIZEVM = -O3 -march=i586
    OPTIMIZE = $(OPTIMIZEVM)
    HAVE_VM_COMPILED = true
  endif

  SHLIBEXT=dll
  SHLIBCFLAGS=
  SHLIBLDFLAGS=-shared $(LDFLAGS)

  BINEXT=.exe

  ifeq ($(CROSS_COMPILING),0)
    TOOLS_BINEXT=.exe
  endif

  ifeq ($(COMPILE_PLATFORM),cygwin)
    TOOLS_BINEXT=.exe
    TOOLS_CC=$(CC)
  endif

  LIBS= -lws2_32 -lwinmm -lpsapi
  # clang 3.4 doesn't support this
  ifneq ("$(CC)", $(findstring "$(CC)", "clang" "clang++"))
    CLIENT_LDFLAGS += -mwindows
  endif
  CLIENT_LIBS = -lgdi32 -lole32
  RENDERER_LIBS = -lgdi32 -lole32 -lopengl32

  ifeq ($(USE_FREETYPE),1)
    FREETYPE_CFLAGS = -Ifreetype2
  endif

  ifeq ($(USE_CURL),1)
    CLIENT_CFLAGS += $(CURL_CFLAGS)
    ifneq ($(USE_CURL_DLOPEN),1)
      CLIENT_LIBS += $(CURL_LIBS)
    endif
  endif

  ifeq ($(ARCH),x86)
    # build 32bit
    BASE_CFLAGS += -m32
  else
    BASE_CFLAGS += -m64
  endif

  # libmingw32 must be linked before libSDLmain
  CLIENT_LIBS += -lmingw32
  RENDERER_LIBS += -lmingw32

  CLIENT_CFLAGS += $(SDL_CFLAGS)
  CLIENT_LIBS += $(SDL_LIBS)
  RENDERER_LIBS += $(SDL_LIBS)

else # ifeq mingw32

#############################################################################
# SETUP AND BUILD -- FREEBSD
#############################################################################

ifeq ($(PLATFORM),freebsd)

  # flags
  BASE_CFLAGS = -Wall -fno-strict-aliasing -DUSE_ICON
  CLIENT_CFLAGS += $(SDL_CFLAGS)
  HAVE_VM_COMPILED = true

  OPTIMIZEVM = -O3
  OPTIMIZE = $(OPTIMIZEVM)

  SHLIBEXT=so
  SHLIBCFLAGS=-fPIC
  SHLIBLDFLAGS=-shared $(LDFLAGS)

  THREAD_LIBS=-lpthread
  # don't need -ldl (FreeBSD)
  LIBS=-lm

  CLIENT_LIBS =

  CLIENT_LIBS += $(SDL_LIBS)
  RENDERER_LIBS = $(SDL_LIBS) -lGL

  # optional features/libraries
  ifeq ($(USE_OPENAL),1)
    CLIENT_CFLAGS += $(OPENAL_CFLAGS)
    ifeq ($(USE_OPENAL_DLOPEN),1)
      CLIENT_LIBS += $(THREAD_LIBS) $(OPENAL_LIBS)
    endif
  endif

  ifeq ($(USE_CURL),1)
    CLIENT_CFLAGS += $(CURL_CFLAGS)
    ifeq ($(USE_CURL_DLOPEN),1)
      CLIENT_LIBS += $(CURL_LIBS)
    endif
  endif

  # cross-compiling tweaks
  ifeq ($(ARCH),x86)
    ifeq ($(CROSS_COMPILING),1)
      BASE_CFLAGS += -m32
    endif
  endif
  ifeq ($(ARCH),x86_64)
    ifeq ($(CROSS_COMPILING),1)
      BASE_CFLAGS += -m64
    endif
  endif
else # ifeq freebsd

#############################################################################
# SETUP AND BUILD -- OPENBSD
#############################################################################

ifeq ($(PLATFORM),openbsd)

  BASE_CFLAGS = -Wall -fno-strict-aliasing -Wimplicit -Wstrict-prototypes \
    -pipe -DUSE_ICON -DMAP_ANONYMOUS=MAP_ANON
  CLIENT_CFLAGS += $(SDL_CFLAGS)

  OPTIMIZEVM = -O3
  OPTIMIZE = $(OPTIMIZEVM)

  ifeq ($(ARCH),x86_64)
    OPTIMIZEVM = -O3
    OPTIMIZE = $(OPTIMIZEVM)
    HAVE_VM_COMPILED = true
  else
  ifeq ($(ARCH),x86)
    OPTIMIZEVM = -O3 -march=i586
    OPTIMIZE = $(OPTIMIZEVM)
    HAVE_VM_COMPILED=true
  else
  ifeq ($(ARCH),ppc)
    BASE_CFLAGS += -maltivec
    HAVE_VM_COMPILED=true
  endif
  ifeq ($(ARCH),ppc64)
    BASE_CFLAGS += -maltivec
    HAVE_VM_COMPILED=true
  endif
  ifeq ($(ARCH),sparc64)
    OPTIMIZE += -mtune=ultrasparc3 -mv8plus
    OPTIMIZEVM += -mtune=ultrasparc3 -mv8plus
    HAVE_VM_COMPILED=true
  endif
  ifeq ($(ARCH),alpha)
    # According to http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=410555
    # -ffast-math will cause the client to die with SIGFPE on Alpha
    OPTIMIZE = $(OPTIMIZEVM)
  endif
  endif
  endif

  ifeq ($(USE_CURL),1)
    CLIENT_CFLAGS += $(CURL_CFLAGS)
    USE_CURL_DLOPEN=0
  endif

  # no shm_open on OpenBSD
  USE_MUMBLE=0

  SHLIBEXT=so
  SHLIBCFLAGS=-fPIC
  SHLIBLDFLAGS=-shared $(LDFLAGS)

  THREAD_LIBS=-lpthread
  LIBS=-lm

  CLIENT_LIBS =

  CLIENT_LIBS += $(SDL_LIBS)
  RENDERER_LIBS = $(SDL_LIBS) -lGL

  ifeq ($(USE_OPENAL),1)
    CLIENT_CFLAGS += $(OPENAL_CFLAGS)
    ifneq ($(USE_OPENAL_DLOPEN),1)
      CLIENT_LIBS += $(THREAD_LIBS) $(OPENAL_LIBS)
    endif
  endif

  ifeq ($(USE_CURL),1)
    ifneq ($(USE_CURL_DLOPEN),1)
      CLIENT_LIBS += $(CURL_LIBS)
    endif
  endif
else # ifeq openbsd

#############################################################################
# SETUP AND BUILD -- NETBSD
#############################################################################

ifeq ($(PLATFORM),netbsd)

  LIBS=-lm
  SHLIBEXT=so
  SHLIBCFLAGS=-fPIC
  SHLIBLDFLAGS=-shared $(LDFLAGS)
  THREAD_LIBS=-lpthread

  BASE_CFLAGS = -Wall -fno-strict-aliasing -Wimplicit -Wstrict-prototypes

  ifeq ($(ARCH),x86)
    HAVE_VM_COMPILED=true
  endif

  BUILD_CLIENT = 0
else # ifeq netbsd

#############################################################################
# SETUP AND BUILD -- IRIX
#############################################################################

ifeq ($(PLATFORM),irix64)

  ARCH=mips

  CC = c99
  MKDIR = mkdir -p

  BASE_CFLAGS=-Dstricmp=strcasecmp -Xcpluscomm -woff 1185 \
    -I. -I$(ROOT)/usr/include
  CLIENT_CFLAGS += $(SDL_CFLAGS)
  OPTIMIZE = -O3

  SHLIBEXT=so
  SHLIBCFLAGS=
  SHLIBLDFLAGS=-shared

  LIBS=-ldl -lm -lgen
  # FIXME: The X libraries probably aren't necessary?
  CLIENT_LIBS=-L/usr/X11/$(LIB) $(SDL_LIBS) \
    -lX11 -lXext -lm
  RENDERER_LIBS = $(SDL_LIBS) -lGL

else # ifeq IRIX

#############################################################################
# SETUP AND BUILD -- SunOS
#############################################################################

ifeq ($(PLATFORM),sunos)

  CC=gcc
  INSTALL=ginstall
  MKDIR=gmkdir
  COPYDIR="/usr/local/share/games/tremulous"

  ifneq ($(ARCH),x86)
    ifneq ($(ARCH),sparc)
      $(error arch $(ARCH) is currently not supported)
    endif
  endif

  BASE_CFLAGS = -Wall -fno-strict-aliasing -Wimplicit -Wstrict-prototypes \
    -pipe -DUSE_ICON
  CLIENT_CFLAGS += $(SDL_CFLAGS)

  OPTIMIZEVM = -O3 -funroll-loops

  ifeq ($(ARCH),sparc)
    OPTIMIZEVM += -O3 \
      -fstrength-reduce -falign-functions=2 \
      -mtune=ultrasparc3 -mv8plus -mno-faster-structs
    HAVE_VM_COMPILED=true
  else
  ifeq ($(ARCH),x86)
    OPTIMIZEVM += -march=i586 -fomit-frame-pointer \
      -falign-functions=2 -fstrength-reduce
    HAVE_VM_COMPILED=true
    BASE_CFLAGS += -m32
    CLIENT_CFLAGS += -I/usr/X11/include/NVIDIA
    CLIENT_LDFLAGS += -L/usr/X11/lib/NVIDIA -R/usr/X11/lib/NVIDIA
  endif
  endif

  OPTIMIZE = $(OPTIMIZEVM)

  SHLIBEXT=so
  SHLIBCFLAGS=-fPIC
  SHLIBLDFLAGS=-shared $(LDFLAGS)

  THREAD_LIBS=-lpthread
  LIBS=-lsocket -lnsl -ldl -lm

  BOTCFLAGS=-O0

  CLIENT_LIBS +=$(SDL_LIBS) -lX11 -lXext -liconv -lm
  RENDERER_LIBS = $(SDL_LIBS) -lGL

else # ifeq sunos

#############################################################################
# SETUP AND BUILD -- GENERIC
#############################################################################
  BASE_CFLAGS=
  OPTIMIZE = -O3

  SHLIBEXT=so
  SHLIBCFLAGS=-fPIC
  SHLIBLDFLAGS=-shared

endif #Linux
endif #darwin
endif #mingw32
endif #FreeBSD
endif #OpenBSD
endif #NetBSD
endif #IRIX
endif #SunOS

ifndef CC
  CC=gcc
endif

ifndef RANLIB
  RANLIB=ranlib
endif

ifneq ($(HAVE_VM_COMPILED),true)
  BASE_CFLAGS += -DNO_VM_COMPILED
  BUILD_QVM=0
endif

TARGETS =

ifndef FULLBINEXT
  FULLBINEXT=$(BINEXT)
endif

ifndef SHLIBNAME
  SHLIBNAME=.$(SHLIBEXT)
endif

ifeq ($(USE_INTERNAL_MINIZIP),1)
  MINIZIP_CFLAGS ?= -I$(MINIZIPDIR)
else
  MINIZIP_CFLAGS ?= $(shell pkg-config --silence-errors --cflags minizip)
  MINIZIP_LIBS ?= $(shell pkg-config --silence-errors --libs minizip)
endif

ifneq ($(BUILD_SERVER),0)
  SERVER_CFLAGS += $(MINIZIP_CFLAGS)
  SERVER_LIBS += $(MINIZIP_LIBS)
  TARGETS += $(B)/$(OUT)/$(SERVERBIN)$(FULLBINEXT)
endif

ifneq ($(BUILD_CLIENT),0)
  CLIENT_CFLAGS += $(MINIZIP_CFLAGS)
  CLIENT_LIBS += $(MINIZIP_LIBS)
  ifneq ($(USE_RENDERER_DLOPEN),0)
    TARGETS += $(B)/$(OUT)/$(CLIENTBIN)$(FULLBINEXT) $(B)/$(OUT)/renderer_opengl1$(SHLIBNAME)
    ifneq ($(BUILD_RENDERER_OPENGL2),0)
      TARGETS += $(B)/$(OUT)/renderer_opengl2$(SHLIBNAME)
    endif
  else
    TARGETS += $(B)/$(OUT)/$(CLIENTBIN)$(FULLBINEXT)
    ifneq ($(BUILD_RENDERER_OPENGL2),0)
      TARGETS += $(B)/$(OUT)/$(CLIENTBIN)_opengl2$(FULLBINEXT)
    endif
  endif
endif

ifneq ($(BUILD_GAME_SO),0)
  TARGETS += \
    $(B)/$(OUT)/$(BASEGAME)/game$(SHLIBNAME)
endif

ifneq ($(BUILD_CGAME_UI_QVM),0)
  TARGETS += \
    $(B)/$(OUT)/$(BASEGAME)/vm/cgame.qvm \
    $(B)/$(OUT)/$(BASEGAME)/vm/ui.qvm
endif

ifneq ($(BUILD_CGAME_UI_SO),0)
  TARGETS += \
    $(B)/$(OUT)/$(BASEGAME)/cgame$(SHLIBNAME) \
    $(B)/$(OUT)/$(BASEGAME)/ui$(SHLIBNAME)
endif

ifneq ($(BUILD_CGAME_UI_QVM_11),0)
  TARGETS += \
    $(B)/$(OUT)/$(BASEGAME)_11/vm/cgame.qvm \
    $(B)/$(OUT)/$(BASEGAME)_11/vm/ui.qvm
endif

ifneq ($(BUILD_CGAME_UI_SO_11),0)
  TARGETS += \
    $(B)/$(OUT)/$(BASEGAME)_11/cgame$(SHLIBNAME) \
    $(B)/$(OUT)/$(BASEGAME)_11/ui$(SHLIBNAME)
endif

ifeq ($(USE_OPENAL),1)
  CLIENT_CFLAGS += -DUSE_OPENAL
  ifeq ($(USE_OPENAL_DLOPEN),1)
    CLIENT_CFLAGS += -DUSE_OPENAL_DLOPEN
  endif
endif

ifeq ($(USE_CURL),1)
  CLIENT_CFLAGS += -DUSE_CURL
  ifeq ($(USE_CURL_DLOPEN),1)
    CLIENT_CFLAGS += -DUSE_CURL_DLOPEN
  endif
endif

ifeq ($(USE_CODEC_OPUS),1)
  CLIENT_CFLAGS += -DUSE_CODEC_OPUS
  ifeq ($(USE_INTERNAL_OPUS),1)
    OPUS_CFLAGS = -DOPUS_BUILD -DHAVE_LRINTF -DFLOATING_POINT -DUSE_ALLOCA \
      -I$(OPUSDIR)/include -I$(OPUSDIR)/celt -I$(OPUSDIR)/silk \
      -I$(OPUSDIR)/silk/float -I$(OPUSFILEDIR)/include
  else
    OPUS_CFLAGS ?= $(shell pkg-config --silence-errors --cflags opusfile opus || true)
    OPUS_LIBS ?= $(shell pkg-config --silence-errors --libs opusfile opus || echo -lopusfile -lopus)
  endif
  CLIENT_CFLAGS += $(OPUS_CFLAGS)
  CLIENT_LIBS += $(OPUS_LIBS)
  NEED_OGG=1
endif

ifeq ($(USE_CODEC_VORBIS),1)
  CLIENT_CFLAGS += -DUSE_CODEC_VORBIS
  ifeq ($(USE_INTERNAL_VORBIS),1)
    CLIENT_CFLAGS += -I$(VORBISDIR)/include -I$(VORBISDIR)/lib
  else
    VORBIS_CFLAGS ?= $(shell pkg-config --silence-errors --cflags vorbisfile vorbis || true)
    VORBIS_LIBS ?= $(shell pkg-config --silence-errors --libs vorbisfile vorbis || echo -lvorbisfile -lvorbis)
  endif
  CLIENT_CFLAGS += $(VORBIS_CFLAGS)
  CLIENT_LIBS += $(VORBIS_LIBS)
  NEED_OGG=1
endif

ifeq ($(NEED_OGG),1)
  ifeq ($(USE_INTERNAL_OGG),1)
    OGG_CFLAGS = -I$(OGGDIR)/include
  else
    OGG_CFLAGS ?= $(shell pkg-config --silence-errors --cflags ogg || true)
    OGG_LIBS ?= $(shell pkg-config --silence-errors --libs ogg || echo -logg)
  endif
  CLIENT_CFLAGS += $(OGG_CFLAGS)
  CLIENT_LIBS += $(OGG_LIBS)
endif

ifeq ($(USE_RENDERER_DLOPEN),1)
  CLIENT_CFLAGS += -DUSE_RENDERER_DLOPEN
endif

ifeq ($(USE_MUMBLE),1)
  CLIENT_CFLAGS += -DUSE_MUMBLE
endif

ifeq ($(USE_VOIP),1)
  CLIENT_CFLAGS += -DUSE_VOIP
  SERVER_CFLAGS += -DUSE_VOIP
  ifeq ($(USE_INTERNAL_SPEEX),1)
    SPEEX_CFLAGS += -DFLOATING_POINT -DUSE_ALLOCA -I$(SPEEXDIR)/include
  else
    SPEEX_CFLAGS ?= $(shell pkg-config --silence-errors --cflags speex speexdsp || true)
    SPEEX_LIBS ?= $(shell pkg-config --silence-errors --libs speex speexdsp || echo -lspeex -lspeexdsp)
  endif
  CLIENT_CFLAGS += $(SPEEX_CFLAGS)
  CLIENT_LIBS += $(SPEEX_LIBS)
endif

ifeq ($(USE_INTERNAL_ZLIB),1)
  ZLIB_CFLAGS = -DNO_GZIP -I$(ZDIR)
else
  ZLIB_CFLAGS ?= $(shell pkg-config --silence-errors --cflags zlib || true)
  ZLIB_LIBS ?= $(shell pkg-config --silence-errors --libs zlib || echo -lz)
endif
BASE_CFLAGS += $(ZLIB_CFLAGS)
LIBS += $(ZLIB_LIBS)

ifeq ($(USE_INTERNAL_JPEG),1)
  BASE_CFLAGS += -DUSE_INTERNAL_JPEG
  BASE_CFLAGS += -I$(JPDIR)
else
  # IJG libjpeg doesn't have pkg-config, but libjpeg-turbo uses libjpeg.pc;
  # we fall back to hard-coded answers if libjpeg.pc is unavailable
  JPEG_CFLAGS ?= $(shell pkg-config --silence-errors --cflags libjpeg || true)
  JPEG_LIBS ?= $(shell pkg-config --silence-errors --libs libjpeg || echo -ljpeg)
  BASE_CFLAGS += $(JPEG_CFLAGS)
  RENDERER_LIBS += $(JPEG_LIBS)
endif

ifeq ($(USE_FREETYPE),1)
  FREETYPE_CFLAGS ?= $(shell pkg-config --silence-errors --cflags freetype2 || true)
  FREETYPE_LIBS ?= $(shell pkg-config --silence-errors --libs freetype2 || echo -lfreetype)

  BASE_CFLAGS += -DBUILD_FREETYPE $(FREETYPE_CFLAGS)
  RENDERER_LIBS += $(FREETYPE_LIBS)
endif

ifeq ("$(CC)", $(findstring "$(CC)", "clang" "clang++"))
  BASE_CFLAGS += -Qunused-arguments
endif

ifdef DEFAULT_BASEDIR
  BASE_CFLAGS += -DDEFAULT_BASEDIR=\\\"$(DEFAULT_BASEDIR)\\\"
endif

ifeq ($(GENERATE_DEPENDENCIES),1)
  DEPEND_CFLAGS = -MMD
else
  DEPEND_CFLAGS =
endif

ifeq ($(NO_STRIP),1)
  STRIP_FLAG =
else
  STRIP_FLAG = -s
endif

BASE_CFLAGS += -DPRODUCT_VERSION=\\\"$(VERSION)\\\"

ifeq ($(V),1)
echo_cmd=@:
Q=
else
echo_cmd=@echo
Q=@
endif

define DO_CC
$(echo_cmd) "CC $<"
$(Q)$(CC) $(NOTSHLIBCFLAGS) $(CFLAGS) $(CLIENT_CFLAGS) $(OPTIMIZE) -o $@ -c $<
endef

define DO_REF_CC
$(echo_cmd) "REF_CC $<"
$(Q)$(CC) $(SHLIBCFLAGS) $(CFLAGS) $(CLIENT_CFLAGS) $(OPTIMIZE) -o $@ -c $<
endef

define DO_REF_STR
$(echo_cmd) "REF_STR $<"
$(Q)rm -f $@
$(Q)echo "const char *fallbackShader_$(notdir $(basename $<)) =" >> $@
$(Q)cat $< | sed 's/^/\"/;s/$$/\\n\"/' >> $@
$(Q)echo ";" >> $@
endef

ifeq ($(GENERATE_DEPENDENCIES),1)
  DO_QVM_DEP=cat $(@:%.o=%.d) | sed -e 's/\.o/\.asm/g' >> $(@:%.o=%.d)
endif

define DO_SHLIB_CC
$(echo_cmd) "SHLIB_CC $<"
$(Q)$(CC) $(BASEGAME_CFLAGS) $(SHLIBCFLAGS) $(CFLAGS) $(OPTIMIZEVM) -o $@ -c $<
$(Q)$(DO_QVM_DEP)
endef

define DO_GAME_CC
$(echo_cmd) "GAME_CC $<"
$(Q)$(CC) $(BASEGAME_CFLAGS) -DGAME $(SHLIBCFLAGS) $(CFLAGS) $(OPTIMIZEVM) -o $@ -c $<
$(Q)$(DO_QVM_DEP)
endef

define DO_CGAME_CC
$(echo_cmd) "CGAME_CC $<"
$(Q)$(CC) $(BASEGAME_CFLAGS) -DCGAME $(SHLIBCFLAGS) $(CFLAGS) $(OPTIMIZEVM) -o $@ -c $<
$(Q)$(DO_QVM_DEP)
endef

define DO_UI_CC
$(echo_cmd) "UI_CC $<"
$(Q)$(CC) $(BASEGAME_CFLAGS) -DUI $(SHLIBCFLAGS) $(CFLAGS) $(OPTIMIZEVM) -o $@ -c $<
$(Q)$(DO_QVM_DEP)
endef

define DO_AS
$(echo_cmd) "AS $<"
$(Q)$(CC) $(CFLAGS) $(OPTIMIZE) -x assembler-with-cpp -o $@ -c $<
endef

define DO_DED_CC
$(echo_cmd) "DED_CC $<"
$(Q)$(CC) $(NOTSHLIBCFLAGS) -DDEDICATED $(CFLAGS) $(SERVER_CFLAGS) $(OPTIMIZE) -o $@ -c $<
endef

define DO_WINDRES
$(echo_cmd) "WINDRES $<"
$(Q)$(WINDRES) -i $< -o $@
endef


#############################################################################
# MAIN TARGETS
#############################################################################

default: release
all: debug release

debug:
	@$(MAKE) targets B=$(BD) CFLAGS="$(CFLAGS) $(BASE_CFLAGS) $(DEPEND_CFLAGS)" \
	  OPTIMIZE="$(DEBUG_CFLAGS)" OPTIMIZEVM="$(DEBUG_CFLAGS)" \
	  CLIENT_CFLAGS="$(CLIENT_CFLAGS)" SERVER_CFLAGS="$(SERVER_CFLAGS)" V=$(V)
ifeq ($(BUILD_MASTER_SERVER),1)
	$(MAKE) -C $(MASTERDIR) debug
endif

release:
	@$(MAKE) targets B=$(BR) CFLAGS="$(CFLAGS) $(BASE_CFLAGS) $(DEPEND_CFLAGS)" \
	  OPTIMIZE="-DNDEBUG $(OPTIMIZE)" OPTIMIZEVM="-DNDEBUG $(OPTIMIZEVM)" \
	  CLIENT_CFLAGS="$(CLIENT_CFLAGS)" SERVER_CFLAGS="$(SERVER_CFLAGS)" V=$(V)
ifeq ($(BUILD_MASTER_SERVER),1)
	$(MAKE) -C $(MASTERDIR) release
endif

ifneq ($(call bin_path, tput),)
  TERM_COLUMNS=$(shell echo $$((`tput cols`-4)))
else
  TERM_COLUMNS=76
endif

define ADD_COPY_TARGET
TARGETS += $2
$2: $1
	$(echo_cmd) "CP $$<"
	@cp $1 $2
endef

# These functions allow us to generate rules for copying a list of files
# into the base directory of the build; this is useful for bundling libs,
# README files or whatever else
define GENERATE_COPY_TARGETS
$(foreach FILE,$1, \
  $(eval $(call ADD_COPY_TARGET, \
    $(FILE), \
    $(addprefix $(B)/,$(notdir $(FILE))))))
endef

$(call GENERATE_COPY_TARGETS,$(EXTRA_FILES))

ifneq ($(BUILD_CLIENT),0)
  $(call GENERATE_COPY_TARGETS,$(CLIENT_EXTRA_FILES))
endif

NAKED_TARGETS=$(shell echo $(TARGETS) | sed -e "s!$(B)/!!g")

print_list=@for i in $(1); \
     do \
             echo "    $$i"; \
     done

ifneq ($(call bin_path, fmt),)
  print_wrapped=@echo $(1) | fmt -w $(TERM_COLUMNS) | sed -e "s/^\(.*\)$$/    \1/"
else
  print_wrapped=$(print_list)
endif

# Create the build directories, check libraries and print out
# an informational message, then start building
targets: makedirs
	@echo ""
	@echo "Building in $(B):"
	@echo "  PLATFORM: $(PLATFORM)"
	@echo "  ARCH: $(ARCH)"
	@echo "  VERSION: $(VERSION)"
	@echo "  COMPILE_PLATFORM: $(COMPILE_PLATFORM)"
	@echo "  COMPILE_ARCH: $(COMPILE_ARCH)"
	@echo "  CC: $(CC)"
ifeq ($(PLATFORM),mingw32)
	@echo "  WINDRES: $(WINDRES)"
endif
	@echo ""
	@echo "  CFLAGS:"
	$(call print_wrapped, $(CFLAGS) $(OPTIMIZE))
	@echo ""
	@echo "  CLIENT_CFLAGS:"
	$(call print_wrapped, $(CLIENT_CFLAGS))
	@echo ""
	@echo "  SERVER_CFLAGS:"
	$(call print_wrapped, $(SERVER_CFLAGS))
	@echo ""
	@echo "  LDFLAGS:"
	$(call print_wrapped, $(LDFLAGS))
	@echo ""
	@echo "  LIBS:"
	$(call print_wrapped, $(LIBS))
	@echo ""
	@echo "  CLIENT_LIBS:"
	$(call print_wrapped, $(CLIENT_LIBS))
	@echo ""
	@echo "  Output:"
	$(call print_list, $(NAKED_TARGETS))
	@echo ""
ifneq ($(TARGETS),)
  ifndef DEBUG_MAKEFILE
	@$(MAKE) $(TARGETS) $(B).zip V=$(V)
  endif
endif

$(B).zip: $(TARGETS)
ifeq ($(PLATFORM),darwin)
  ifdef ARCHIVE
	@("./make-macosx-app.sh" release $(ARCH); if [ "$$?" -eq 0 ] && [ -d "$(B)/tremulous.app" ]; then rm -f $@; cd $(B) && zip --symlinks -r9 ../../$@ `find "tremulous.app" -print | sed -e "s!$(B)/!!g"`; else rm -f $@; cd $(B) && zip -r9 ../../$@ $(NAKED_TARGETS); fi)
  endif
endif
ifneq ($(PLATFORM),darwin)
  ifdef ARCHIVE
	@rm -f $@
	@(cd $(B) && zip -r9 ../../$@ $(NAKED_TARGETS))
  endif
endif

makedirs:
	@if [ ! -d $(BUILD_DIR) ];then $(MKDIR) $(BUILD_DIR);fi
	@if [ ! -d $(B) ];then $(MKDIR) $(B);fi
	@if [ ! -d $(B)/client ];then $(MKDIR) $(B)/client;fi
	@if [ ! -d $(B)/client/minizip ];then $(MKDIR) $(B)/client/minizip;fi
	@if [ ! -d $(B)/client/opus ];then $(MKDIR) $(B)/client/opus;fi
	@if [ ! -d $(B)/client/vorbis ];then $(MKDIR) $(B)/client/vorbis;fi
	@if [ ! -d $(B)/renderergl1 ];then $(MKDIR) $(B)/renderergl1;fi
	@if [ ! -d $(B)/renderergl2 ];then $(MKDIR) $(B)/renderergl2;fi
	@if [ ! -d $(B)/renderergl2/glsl ];then $(MKDIR) $(B)/renderergl2/glsl;fi
	@if [ ! -d $(B)/ded ];then $(MKDIR) $(B)/ded;fi
	@if [ ! -d $(B)/ded/minizip ];then $(MKDIR) $(B)/ded/minizip;fi
	@if [ ! -d $(B)/cgame ];then $(MKDIR) $(B)/cgame;fi
	@if [ ! -d $(B)/game ];then $(MKDIR) $(B)/game;fi
	@if [ ! -d $(B)/ui ];then $(MKDIR) $(B)/ui;fi
	@if [ ! -d $(B)/qcommon ];then $(MKDIR) $(B)/qcommon;fi
	@if [ ! -d $(B)/11 ];then $(MKDIR) $(B)/11;fi
	@if [ ! -d $(B)/11/cgame ];then $(MKDIR) $(B)/11/cgame;fi
	@if [ ! -d $(B)/11/ui ];then $(MKDIR) $(B)/11/ui;fi
	@if [ ! -d $(B)/$(OUT) ];then $(MKDIR) $(B)/$(OUT);fi
	@if [ ! -d $(B)/$(OUT)/$(BASEGAME) ];then $(MKDIR) $(B)/$(OUT)/$(BASEGAME);fi
	@if [ ! -d $(B)/$(OUT)/$(BASEGAME)/vm ];then $(MKDIR) $(B)/$(OUT)/$(BASEGAME)/vm;fi
	@if [ ! -d $(B)/$(OUT)/$(BASEGAME)_11 ];then $(MKDIR) $(B)/$(OUT)/$(BASEGAME)_11;fi
	@if [ ! -d $(B)/$(OUT)/$(BASEGAME)_11/vm ];then $(MKDIR) $(B)/$(OUT)/$(BASEGAME)_11/vm;fi
	@if [ ! -d $(B)/tools ];then $(MKDIR) $(B)/tools;fi
	@if [ ! -d $(B)/tools/asm ];then $(MKDIR) $(B)/tools/asm;fi
	@if [ ! -d $(B)/tools/etc ];then $(MKDIR) $(B)/tools/etc;fi
	@if [ ! -d $(B)/tools/rcc ];then $(MKDIR) $(B)/tools/rcc;fi
	@if [ ! -d $(B)/tools/cpp ];then $(MKDIR) $(B)/tools/cpp;fi
	@if [ ! -d $(B)/tools/lburg ];then $(MKDIR) $(B)/tools/lburg;fi

#############################################################################
# QVM BUILD TOOLS
#############################################################################

ifndef TOOLS_CC
  # A compiler which probably produces native binaries
  TOOLS_CC=$(CC)
endif

TOOLS_OPTIMIZE = -g -Wall -fno-strict-aliasing
TOOLS_CFLAGS += $(TOOLS_OPTIMIZE) \
                -DTEMPDIR=\"$(TEMPDIR)\" -DSYSTEM=\"\" \
                -I$(Q3LCCSRCDIR) \
                -I$(LBURGDIR)
TOOLS_LIBS =
TOOLS_LDFLAGS =

ifeq ($(GENERATE_DEPENDENCIES),1)
  TOOLS_CFLAGS += -MMD
endif

define DO_TOOLS_CC
$(echo_cmd) "TOOLS_CC $<"
$(Q)$(TOOLS_CC) $(TOOLS_CFLAGS) -o $@ -c $<
endef

define DO_TOOLS_CC_DAGCHECK
$(echo_cmd) "TOOLS_CC_DAGCHECK $<"
$(Q)$(TOOLS_CC) $(TOOLS_CFLAGS) -Wno-unused -o $@ -c $<
endef

LBURG       = $(B)/tools/lburg/lburg$(TOOLS_BINEXT)
DAGCHECK_C  = $(B)/tools/rcc/dagcheck.c
Q3RCC       = $(B)/tools/q3rcc$(TOOLS_BINEXT)
Q3CPP       = $(B)/tools/q3cpp$(TOOLS_BINEXT)
Q3LCC       = $(B)/tools/q3lcc$(TOOLS_BINEXT)
Q3ASM       = $(B)/tools/q3asm$(TOOLS_BINEXT)

LBURGOBJ= \
  $(B)/tools/lburg/lburg.o \
  $(B)/tools/lburg/gram.o

$(B)/tools/lburg/%.o: $(LBURGDIR)/%.c
	$(DO_TOOLS_CC)

$(LBURG): $(LBURGOBJ)
	$(echo_cmd) "LD $@"
	$(Q)$(TOOLS_CC) $(TOOLS_CFLAGS) $(TOOLS_LDFLAGS) -o $@ $^ $(TOOLS_LIBS)

Q3RCCOBJ = \
  $(B)/tools/rcc/alloc.o \
  $(B)/tools/rcc/bind.o \
  $(B)/tools/rcc/bytecode.o \
  $(B)/tools/rcc/dag.o \
  $(B)/tools/rcc/dagcheck.o \
  $(B)/tools/rcc/decl.o \
  $(B)/tools/rcc/enode.o \
  $(B)/tools/rcc/error.o \
  $(B)/tools/rcc/event.o \
  $(B)/tools/rcc/expr.o \
  $(B)/tools/rcc/gen.o \
  $(B)/tools/rcc/init.o \
  $(B)/tools/rcc/inits.o \
  $(B)/tools/rcc/input.o \
  $(B)/tools/rcc/lex.o \
  $(B)/tools/rcc/list.o \
  $(B)/tools/rcc/main.o \
  $(B)/tools/rcc/null.o \
  $(B)/tools/rcc/output.o \
  $(B)/tools/rcc/prof.o \
  $(B)/tools/rcc/profio.o \
  $(B)/tools/rcc/simp.o \
  $(B)/tools/rcc/stmt.o \
  $(B)/tools/rcc/string.o \
  $(B)/tools/rcc/sym.o \
  $(B)/tools/rcc/symbolic.o \
  $(B)/tools/rcc/trace.o \
  $(B)/tools/rcc/tree.o \
  $(B)/tools/rcc/types.o

$(DAGCHECK_C): $(LBURG) $(Q3LCCSRCDIR)/dagcheck.md
	$(echo_cmd) "LBURG $(Q3LCCSRCDIR)/dagcheck.md"
	$(Q)$(LBURG) $(Q3LCCSRCDIR)/dagcheck.md $@

$(B)/tools/rcc/dagcheck.o: $(DAGCHECK_C)
	$(DO_TOOLS_CC_DAGCHECK)

$(B)/tools/rcc/%.o: $(Q3LCCSRCDIR)/%.c
	$(DO_TOOLS_CC)

$(Q3RCC): $(Q3RCCOBJ)
	$(echo_cmd) "LD $@"
	$(Q)$(TOOLS_CC) $(TOOLS_CFLAGS) $(TOOLS_LDFLAGS) -o $@ $^ $(TOOLS_LIBS)

Q3CPPOBJ = \
  $(B)/tools/cpp/cpp.o \
  $(B)/tools/cpp/lex.o \
  $(B)/tools/cpp/nlist.o \
  $(B)/tools/cpp/tokens.o \
  $(B)/tools/cpp/macro.o \
  $(B)/tools/cpp/eval.o \
  $(B)/tools/cpp/include.o \
  $(B)/tools/cpp/hideset.o \
  $(B)/tools/cpp/getopt.o \
  $(B)/tools/cpp/unix.o

$(B)/tools/cpp/%.o: $(Q3CPPDIR)/%.c
	$(DO_TOOLS_CC)

$(Q3CPP): $(Q3CPPOBJ)
	$(echo_cmd) "LD $@"
	$(Q)$(TOOLS_CC) $(TOOLS_CFLAGS) $(TOOLS_LDFLAGS) -o $@ $^ $(TOOLS_LIBS)

Q3LCCOBJ = \
	$(B)/tools/etc/lcc.o \
	$(B)/tools/etc/bytecode.o

$(B)/tools/etc/%.o: $(Q3LCCETCDIR)/%.c
	$(DO_TOOLS_CC)

$(Q3LCC): $(Q3LCCOBJ) $(Q3RCC) $(Q3CPP)
	$(echo_cmd) "LD $@"
	$(Q)$(TOOLS_CC) $(TOOLS_CFLAGS) $(TOOLS_LDFLAGS) -o $@ $(Q3LCCOBJ) $(TOOLS_LIBS)

define DO_Q3LCC
$(echo_cmd) "Q3LCC $<"
$(Q)$(Q3LCC) $(BASEGAME_CFLAGS) -o $@ $<
endef

define DO_CGAME_Q3LCC
$(echo_cmd) "CGAME_Q3LCC $<"
$(Q)$(Q3LCC) $(BASEGAME_CFLAGS) -DCGAME -o $@ $<
endef

define DO_CGAME_Q3LCC_11
$(echo_cmd) "CGAME_Q3LCC_11 $<"
$(Q)$(Q3LCC) $(BASEGAME_CFLAGS) -DCGAME -DMODULE_INTERFACE_11 -o $@ $<
endef

define DO_UI_Q3LCC
$(echo_cmd) "UI_Q3LCC $<"
$(Q)$(Q3LCC) $(BASEGAME_CFLAGS) -DUI -o $@ $<
endef

define DO_UI_Q3LCC_11
$(echo_cmd) "UI_Q3LCC_11 $<"
$(Q)$(Q3LCC) $(BASEGAME_CFLAGS) -DUI -DMODULE_INTERFACE_11 -o $@ $<
endef


Q3ASMOBJ = \
  $(B)/tools/asm/q3asm.o \
  $(B)/tools/asm/cmdlib.o

$(B)/tools/asm/%.o: $(Q3ASMDIR)/%.c
	$(DO_TOOLS_CC)

$(Q3ASM): $(Q3ASMOBJ)
	$(echo_cmd) "LD $@"
	$(Q)$(TOOLS_CC) $(TOOLS_CFLAGS) $(TOOLS_LDFLAGS) -o $@ $^ $(TOOLS_LIBS)


#############################################################################
# CLIENT/SERVER
#############################################################################

Q3OBJ = \
  $(B)/client/cl_cgame.o \
  $(B)/client/cl_cin.o \
  $(B)/client/cl_console.o \
  $(B)/client/cl_input.o \
  $(B)/client/cl_keys.o \
  $(B)/client/cl_main.o \
  $(B)/client/cl_net_chan.o \
  $(B)/client/cl_parse.o \
  $(B)/client/cl_scrn.o \
  $(B)/client/cl_ui.o \
  $(B)/client/cl_avi.o \
  \
  $(B)/client/cm_load.o \
  $(B)/client/cm_patch.o \
  $(B)/client/cm_polylib.o \
  $(B)/client/cm_test.o \
  $(B)/client/cm_trace.o \
  \
  $(B)/client/cmd.o \
  $(B)/client/common.o \
  $(B)/client/cvar.o \
  $(B)/client/files.o \
  $(B)/client/md4.o \
  $(B)/client/md5.o \
  $(B)/client/msg.o \
  $(B)/client/net_chan.o \
  $(B)/client/net_ip.o \
  $(B)/client/huffman.o \
  $(B)/client/parse.o \
  $(B)/client/packing.o \
  \
  $(B)/client/snd_adpcm.o \
  $(B)/client/snd_dma.o \
  $(B)/client/snd_mem.o \
  $(B)/client/snd_mix.o \
  $(B)/client/snd_wavelet.o \
  \
  $(B)/client/snd_main.o \
  $(B)/client/snd_codec.o \
  $(B)/client/snd_codec_wav.o \
  $(B)/client/snd_codec_ogg.o \
  $(B)/client/snd_codec_opus.o \
  \
  $(B)/client/qal.o \
  $(B)/client/snd_openal.o \
  \
  $(B)/client/cl_curl.o \
  \
  $(B)/client/sv_ccmds.o \
  $(B)/client/sv_client.o \
  $(B)/client/sv_game.o \
  $(B)/client/sv_init.o \
  $(B)/client/sv_main.o \
  $(B)/client/sv_net_chan.o \
  $(B)/client/sv_snapshot.o \
  $(B)/client/sv_world.o \
  $(B)/client/sv_database.o \
  $(B)/client/sv_sqlite.o \
  $(B)/client/sqlite3.o \
  \
  $(B)/client/q_math.o \
  $(B)/client/q_shared.o \
  \
  $(B)/client/puff.o \
  $(B)/client/vm.o \
  $(B)/client/vm_interpreted.o \
  \
  \
  $(B)/client/sdl_input.o \
  $(B)/client/sdl_snd.o \
  \
  $(B)/client/con_log.o \
  $(B)/client/sys_main.o

ifeq ($(PLATFORM),mingw32)
  Q3OBJ += \
    $(B)/client/con_passive.o
else
  Q3OBJ += \
    $(B)/client/con_tty.o
endif

Q3R2OBJ = \
  $(B)/renderergl2/tr_animation.o \
  $(B)/renderergl2/tr_backend.o \
  $(B)/renderergl2/tr_bsp.o \
  $(B)/renderergl2/tr_cmds.o \
  $(B)/renderergl2/tr_curve.o \
  $(B)/renderergl2/tr_extramath.o \
  $(B)/renderergl2/tr_extensions.o \
  $(B)/renderergl2/tr_fbo.o \
  $(B)/renderergl2/tr_flares.o \
  $(B)/renderergl2/tr_font.o \
  $(B)/renderergl2/tr_glsl.o \
  $(B)/renderergl2/tr_image.o \
  $(B)/renderergl2/tr_image_png.o \
  $(B)/renderergl2/tr_image_jpg.o \
  $(B)/renderergl2/tr_image_bmp.o \
  $(B)/renderergl2/tr_image_tga.o \
  $(B)/renderergl2/tr_image_pcx.o \
  $(B)/renderergl2/tr_init.o \
  $(B)/renderergl2/tr_light.o \
  $(B)/renderergl2/tr_main.o \
  $(B)/renderergl2/tr_marks.o \
  $(B)/renderergl2/tr_mesh.o \
  $(B)/renderergl2/tr_model.o \
  $(B)/renderergl2/tr_model_iqm.o \
  $(B)/renderergl2/tr_noise.o \
  $(B)/renderergl2/tr_postprocess.o \
  $(B)/renderergl2/tr_scene.o \
  $(B)/renderergl2/tr_shade.o \
  $(B)/renderergl2/tr_shade_calc.o \
  $(B)/renderergl2/tr_shader.o \
  $(B)/renderergl2/tr_shadows.o \
  $(B)/renderergl2/tr_sky.o \
  $(B)/renderergl2/tr_surface.o \
  $(B)/renderergl2/tr_vbo.o \
  $(B)/renderergl2/tr_world.o \
  \
  $(B)/renderergl1/sdl_gamma.o \
  $(B)/renderergl1/sdl_glimp.o

Q3R2STRINGOBJ = \
  $(B)/renderergl2/glsl/bokeh_fp.o \
  $(B)/renderergl2/glsl/bokeh_vp.o \
  $(B)/renderergl2/glsl/calclevels4x_fp.o \
  $(B)/renderergl2/glsl/calclevels4x_vp.o \
  $(B)/renderergl2/glsl/depthblur_fp.o \
  $(B)/renderergl2/glsl/depthblur_vp.o \
  $(B)/renderergl2/glsl/dlight_fp.o \
  $(B)/renderergl2/glsl/dlight_vp.o \
  $(B)/renderergl2/glsl/down4x_fp.o \
  $(B)/renderergl2/glsl/down4x_vp.o \
  $(B)/renderergl2/glsl/fogpass_fp.o \
  $(B)/renderergl2/glsl/fogpass_vp.o \
  $(B)/renderergl2/glsl/generic_fp.o \
  $(B)/renderergl2/glsl/generic_vp.o \
  $(B)/renderergl2/glsl/lightall_fp.o \
  $(B)/renderergl2/glsl/lightall_vp.o \
  $(B)/renderergl2/glsl/pshadow_fp.o \
  $(B)/renderergl2/glsl/pshadow_vp.o \
  $(B)/renderergl2/glsl/shadowfill_fp.o \
  $(B)/renderergl2/glsl/shadowfill_vp.o \
  $(B)/renderergl2/glsl/shadowmask_fp.o \
  $(B)/renderergl2/glsl/shadowmask_vp.o \
  $(B)/renderergl2/glsl/ssao_fp.o \
  $(B)/renderergl2/glsl/ssao_vp.o \
  $(B)/renderergl2/glsl/texturecolor_fp.o \
  $(B)/renderergl2/glsl/texturecolor_vp.o \
  $(B)/renderergl2/glsl/tonemap_fp.o \
  $(B)/renderergl2/glsl/tonemap_vp.o

Q3ROBJ = \
  $(B)/renderergl1/tr_animation.o \
  $(B)/renderergl1/tr_backend.o \
  $(B)/renderergl1/tr_bsp.o \
  $(B)/renderergl1/tr_cmds.o \
  $(B)/renderergl1/tr_curve.o \
  $(B)/renderergl1/tr_flares.o \
  $(B)/renderergl1/tr_font.o \
  $(B)/renderergl1/tr_image.o \
  $(B)/renderergl1/tr_image_png.o \
  $(B)/renderergl1/tr_image_jpg.o \
  $(B)/renderergl1/tr_image_bmp.o \
  $(B)/renderergl1/tr_image_tga.o \
  $(B)/renderergl1/tr_image_pcx.o \
  $(B)/renderergl1/tr_init.o \
  $(B)/renderergl1/tr_light.o \
  $(B)/renderergl1/tr_main.o \
  $(B)/renderergl1/tr_marks.o \
  $(B)/renderergl1/tr_mesh.o \
  $(B)/renderergl1/tr_model.o \
  $(B)/renderergl1/tr_model_iqm.o \
  $(B)/renderergl1/tr_noise.o \
  $(B)/renderergl1/tr_scene.o \
  $(B)/renderergl1/tr_shade.o \
  $(B)/renderergl1/tr_shade_calc.o \
  $(B)/renderergl1/tr_shader.o \
  $(B)/renderergl1/tr_shadows.o \
  $(B)/renderergl1/tr_sky.o \
  $(B)/renderergl1/tr_surface.o \
  $(B)/renderergl1/tr_world.o \
  \
  $(B)/renderergl1/sdl_gamma.o \
  $(B)/renderergl1/sdl_glimp.o

ifneq ($(USE_RENDERER_DLOPEN), 0)
  Q3ROBJ += \
    $(B)/renderergl1/q_shared.o \
    $(B)/renderergl1/puff.o \
    $(B)/renderergl1/q_math.o \
    $(B)/renderergl1/tr_subs.o

  Q3R2OBJ += \
    $(B)/renderergl1/q_shared.o \
    $(B)/renderergl1/puff.o \
    $(B)/renderergl1/q_math.o \
    $(B)/renderergl1/tr_subs.o
endif

ifneq ($(USE_INTERNAL_JPEG),0)
  JPGOBJ = \
    $(B)/renderergl1/jaricom.o \
    $(B)/renderergl1/jcapimin.o \
    $(B)/renderergl1/jcapistd.o \
    $(B)/renderergl1/jcarith.o \
    $(B)/renderergl1/jccoefct.o  \
    $(B)/renderergl1/jccolor.o \
    $(B)/renderergl1/jcdctmgr.o \
    $(B)/renderergl1/jchuff.o   \
    $(B)/renderergl1/jcinit.o \
    $(B)/renderergl1/jcmainct.o \
    $(B)/renderergl1/jcmarker.o \
    $(B)/renderergl1/jcmaster.o \
    $(B)/renderergl1/jcomapi.o \
    $(B)/renderergl1/jcparam.o \
    $(B)/renderergl1/jcprepct.o \
    $(B)/renderergl1/jcsample.o \
    $(B)/renderergl1/jctrans.o \
    $(B)/renderergl1/jdapimin.o \
    $(B)/renderergl1/jdapistd.o \
    $(B)/renderergl1/jdarith.o \
    $(B)/renderergl1/jdatadst.o \
    $(B)/renderergl1/jdatasrc.o \
    $(B)/renderergl1/jdcoefct.o \
    $(B)/renderergl1/jdcolor.o \
    $(B)/renderergl1/jddctmgr.o \
    $(B)/renderergl1/jdhuff.o \
    $(B)/renderergl1/jdinput.o \
    $(B)/renderergl1/jdmainct.o \
    $(B)/renderergl1/jdmarker.o \
    $(B)/renderergl1/jdmaster.o \
    $(B)/renderergl1/jdmerge.o \
    $(B)/renderergl1/jdpostct.o \
    $(B)/renderergl1/jdsample.o \
    $(B)/renderergl1/jdtrans.o \
    $(B)/renderergl1/jerror.o \
    $(B)/renderergl1/jfdctflt.o \
    $(B)/renderergl1/jfdctfst.o \
    $(B)/renderergl1/jfdctint.o \
    $(B)/renderergl1/jidctflt.o \
    $(B)/renderergl1/jidctfst.o \
    $(B)/renderergl1/jidctint.o \
    $(B)/renderergl1/jmemmgr.o \
    $(B)/renderergl1/jmemnobs.o \
    $(B)/renderergl1/jquant1.o \
    $(B)/renderergl1/jquant2.o \
    $(B)/renderergl1/jutils.o
endif

ifeq ($(ARCH),x86)
  Q3OBJ += \
    $(B)/client/snd_mixa.o \
    $(B)/client/matha.o \
    $(B)/client/snapvector.o \
    $(B)/client/ftola.o
endif
ifeq ($(ARCH),x86_64)
  Q3OBJ += \
    $(B)/client/snapvector.o \
    $(B)/client/ftola.o
endif

ifeq ($(USE_VOIP),1)
ifeq ($(USE_INTERNAL_SPEEX),1)
Q3OBJ += \
  $(B)/client/bits.o \
  $(B)/client/buffer.o \
  $(B)/client/cb_search.o \
  $(B)/client/exc_10_16_table.o \
  $(B)/client/exc_10_32_table.o \
  $(B)/client/exc_20_32_table.o \
  $(B)/client/exc_5_256_table.o \
  $(B)/client/exc_5_64_table.o \
  $(B)/client/exc_8_128_table.o \
  $(B)/client/fftwrap.o \
  $(B)/client/filterbank.o \
  $(B)/client/filters.o \
  $(B)/client/gain_table.o \
  $(B)/client/gain_table_lbr.o \
  $(B)/client/hexc_10_32_table.o \
  $(B)/client/hexc_table.o \
  $(B)/client/high_lsp_tables.o \
  $(B)/client/jitter.o \
  $(B)/client/kiss_fft.o \
  $(B)/client/kiss_fftr.o \
  $(B)/client/lpc.o \
  $(B)/client/lsp.o \
  $(B)/client/lsp_tables_nb.o \
  $(B)/client/ltp.o \
  $(B)/client/mdf.o \
  $(B)/client/modes.o \
  $(B)/client/modes_wb.o \
  $(B)/client/nb_celp.o \
  $(B)/client/preprocess.o \
  $(B)/client/quant_lsp.o \
  $(B)/client/resample.o \
  $(B)/client/sb_celp.o \
  $(B)/client/smallft.o \
  $(B)/client/speex.o \
  $(B)/client/speex_callbacks.o \
  $(B)/client/speex_header.o \
  $(B)/client/stereo.o \
  $(B)/client/vbr.o \
  $(B)/client/vq.o \
  $(B)/client/window.o
endif
endif

ifeq ($(USE_CODEC_OPUS),1)
ifeq ($(USE_INTERNAL_OPUS),1)
Q3OBJ += \
  $(B)/client/opus/analysis.o \
  $(B)/client/opus/mlp.o \
  $(B)/client/opus/mlp_data.o \
  $(B)/client/opus/opus.o \
  $(B)/client/opus/opus_decoder.o \
  $(B)/client/opus/opus_encoder.o \
  $(B)/client/opus/opus_multistream.o \
  $(B)/client/opus/opus_multistream_encoder.o \
  $(B)/client/opus/opus_multistream_decoder.o \
  $(B)/client/opus/repacketizer.o \
  \
  $(B)/client/opus/bands.o \
  $(B)/client/opus/celt.o \
  $(B)/client/opus/cwrs.o \
  $(B)/client/opus/entcode.o \
  $(B)/client/opus/entdec.o \
  $(B)/client/opus/entenc.o \
  $(B)/client/opus/kiss_fft.o \
  $(B)/client/opus/laplace.o \
  $(B)/client/opus/mathops.o \
  $(B)/client/opus/mdct.o \
  $(B)/client/opus/modes.o \
  $(B)/client/opus/pitch.o \
  $(B)/client/opus/celt_encoder.o \
  $(B)/client/opus/celt_decoder.o \
  $(B)/client/opus/celt_lpc.o \
  $(B)/client/opus/quant_bands.o \
  $(B)/client/opus/rate.o \
  $(B)/client/opus/vq.o \
  \
  $(B)/client/opus/CNG.o \
  $(B)/client/opus/code_signs.o \
  $(B)/client/opus/init_decoder.o \
  $(B)/client/opus/decode_core.o \
  $(B)/client/opus/decode_frame.o \
  $(B)/client/opus/decode_parameters.o \
  $(B)/client/opus/decode_indices.o \
  $(B)/client/opus/decode_pulses.o \
  $(B)/client/opus/decoder_set_fs.o \
  $(B)/client/opus/dec_API.o \
  $(B)/client/opus/enc_API.o \
  $(B)/client/opus/encode_indices.o \
  $(B)/client/opus/encode_pulses.o \
  $(B)/client/opus/gain_quant.o \
  $(B)/client/opus/interpolate.o \
  $(B)/client/opus/LP_variable_cutoff.o \
  $(B)/client/opus/NLSF_decode.o \
  $(B)/client/opus/NSQ.o \
  $(B)/client/opus/NSQ_del_dec.o \
  $(B)/client/opus/PLC.o \
  $(B)/client/opus/shell_coder.o \
  $(B)/client/opus/tables_gain.o \
  $(B)/client/opus/tables_LTP.o \
  $(B)/client/opus/tables_NLSF_CB_NB_MB.o \
  $(B)/client/opus/tables_NLSF_CB_WB.o \
  $(B)/client/opus/tables_other.o \
  $(B)/client/opus/tables_pitch_lag.o \
  $(B)/client/opus/tables_pulses_per_block.o \
  $(B)/client/opus/VAD.o \
  $(B)/client/opus/control_audio_bandwidth.o \
  $(B)/client/opus/quant_LTP_gains.o \
  $(B)/client/opus/VQ_WMat_EC.o \
  $(B)/client/opus/HP_variable_cutoff.o \
  $(B)/client/opus/NLSF_encode.o \
  $(B)/client/opus/NLSF_VQ.o \
  $(B)/client/opus/NLSF_unpack.o \
  $(B)/client/opus/NLSF_del_dec_quant.o \
  $(B)/client/opus/process_NLSFs.o \
  $(B)/client/opus/stereo_LR_to_MS.o \
  $(B)/client/opus/stereo_MS_to_LR.o \
  $(B)/client/opus/check_control_input.o \
  $(B)/client/opus/control_SNR.o \
  $(B)/client/opus/init_encoder.o \
  $(B)/client/opus/control_codec.o \
  $(B)/client/opus/A2NLSF.o \
  $(B)/client/opus/ana_filt_bank_1.o \
  $(B)/client/opus/biquad_alt.o \
  $(B)/client/opus/bwexpander_32.o \
  $(B)/client/opus/bwexpander.o \
  $(B)/client/opus/debug.o \
  $(B)/client/opus/decode_pitch.o \
  $(B)/client/opus/inner_prod_aligned.o \
  $(B)/client/opus/lin2log.o \
  $(B)/client/opus/log2lin.o \
  $(B)/client/opus/LPC_analysis_filter.o \
  $(B)/client/opus/LPC_inv_pred_gain.o \
  $(B)/client/opus/table_LSF_cos.o \
  $(B)/client/opus/NLSF2A.o \
  $(B)/client/opus/NLSF_stabilize.o \
  $(B)/client/opus/NLSF_VQ_weights_laroia.o \
  $(B)/client/opus/pitch_est_tables.o \
  $(B)/client/opus/resampler.o \
  $(B)/client/opus/resampler_down2_3.o \
  $(B)/client/opus/resampler_down2.o \
  $(B)/client/opus/resampler_private_AR2.o \
  $(B)/client/opus/resampler_private_down_FIR.o \
  $(B)/client/opus/resampler_private_IIR_FIR.o \
  $(B)/client/opus/resampler_private_up2_HQ.o \
  $(B)/client/opus/resampler_rom.o \
  $(B)/client/opus/sigm_Q15.o \
  $(B)/client/opus/sort.o \
  $(B)/client/opus/sum_sqr_shift.o \
  $(B)/client/opus/stereo_decode_pred.o \
  $(B)/client/opus/stereo_encode_pred.o \
  $(B)/client/opus/stereo_find_predictor.o \
  $(B)/client/opus/stereo_quant_pred.o \
  \
  $(B)/client/opus/apply_sine_window_FLP.o \
  $(B)/client/opus/corrMatrix_FLP.o \
  $(B)/client/opus/encode_frame_FLP.o \
  $(B)/client/opus/find_LPC_FLP.o \
  $(B)/client/opus/find_LTP_FLP.o \
  $(B)/client/opus/find_pitch_lags_FLP.o \
  $(B)/client/opus/find_pred_coefs_FLP.o \
  $(B)/client/opus/LPC_analysis_filter_FLP.o \
  $(B)/client/opus/LTP_analysis_filter_FLP.o \
  $(B)/client/opus/LTP_scale_ctrl_FLP.o \
  $(B)/client/opus/noise_shape_analysis_FLP.o \
  $(B)/client/opus/prefilter_FLP.o \
  $(B)/client/opus/process_gains_FLP.o \
  $(B)/client/opus/regularize_correlations_FLP.o \
  $(B)/client/opus/residual_energy_FLP.o \
  $(B)/client/opus/solve_LS_FLP.o \
  $(B)/client/opus/warped_autocorrelation_FLP.o \
  $(B)/client/opus/wrappers_FLP.o \
  $(B)/client/opus/autocorrelation_FLP.o \
  $(B)/client/opus/burg_modified_FLP.o \
  $(B)/client/opus/bwexpander_FLP.o \
  $(B)/client/opus/energy_FLP.o \
  $(B)/client/opus/inner_product_FLP.o \
  $(B)/client/opus/k2a_FLP.o \
  $(B)/client/opus/levinsondurbin_FLP.o \
  $(B)/client/opus/LPC_inv_pred_gain_FLP.o \
  $(B)/client/opus/pitch_analysis_core_FLP.o \
  $(B)/client/opus/scale_copy_vector_FLP.o \
  $(B)/client/opus/scale_vector_FLP.o \
  $(B)/client/opus/schur_FLP.o \
  $(B)/client/opus/sort_FLP.o \
  \
  $(B)/client/http.o \
  $(B)/client/info.o \
  $(B)/client/internal.o \
  $(B)/client/opusfile.o \
  $(B)/client/stream.o \
  $(B)/client/wincerts.o
endif
endif

ifeq ($(NEED_OGG),1)
ifeq ($(USE_INTERNAL_OGG),1)
Q3OBJ += \
  $(B)/client/bitwise.o \
  $(B)/client/framing.o
endif
endif

ifeq ($(USE_CODEC_VORBIS),1)
ifeq ($(USE_INTERNAL_VORBIS),1)
Q3OBJ += \
  $(B)/client/vorbis/analysis.o \
  $(B)/client/vorbis/bitrate.o \
  $(B)/client/vorbis/block.o \
  $(B)/client/vorbis/codebook.o \
  $(B)/client/vorbis/envelope.o \
  $(B)/client/vorbis/floor0.o \
  $(B)/client/vorbis/floor1.o \
  $(B)/client/vorbis/info.o \
  $(B)/client/vorbis/lookup.o \
  $(B)/client/vorbis/lpc.o \
  $(B)/client/vorbis/lsp.o \
  $(B)/client/vorbis/mapping0.o \
  $(B)/client/vorbis/mdct.o \
  $(B)/client/vorbis/psy.o \
  $(B)/client/vorbis/registry.o \
  $(B)/client/vorbis/res0.o \
  $(B)/client/vorbis/smallft.o \
  $(B)/client/vorbis/sharedbook.o \
  $(B)/client/vorbis/synthesis.o \
  $(B)/client/vorbis/vorbisfile.o \
  $(B)/client/vorbis/window.o
endif
endif

ifeq ($(USE_INTERNAL_ZLIB),1)
Q3OBJ += \
  $(B)/client/adler32.o \
  $(B)/client/crc32.o \
  $(B)/client/inffast.o \
  $(B)/client/inflate.o \
  $(B)/client/inftrees.o \
  $(B)/client/zutil.o
endif

ifeq ($(USE_INTERNAL_MINIZIP),1)
Q3OBJ += \
  $(B)/client/minizip/ioapi.o \
  $(B)/client/minizip/unzip.o
endif

ifeq ($(HAVE_VM_COMPILED),true)
  ifneq ($(findstring $(ARCH),x86 x86_64),)
    Q3OBJ += \
      $(B)/client/vm_x86.o
  endif
  ifneq ($(findstring $(ARCH),ppc ppc64),)
    Q3OBJ += $(B)/client/vm_powerpc.o $(B)/client/vm_powerpc_asm.o
  endif
  ifeq ($(ARCH),sparc)
    Q3OBJ += $(B)/client/vm_sparc.o
  endif
endif

ifeq ($(PLATFORM),mingw32)
  Q3OBJ += \
    $(B)/client/win_resource.o \
    $(B)/client/sys_win32.o
else
  Q3OBJ += \
    $(B)/client/sys_unix.o
endif

ifeq ($(PLATFORM),darwin)
  Q3OBJ += \
    $(B)/client/sys_osx.o
endif

ifeq ($(USE_MUMBLE),1)
  Q3OBJ += \
    $(B)/client/libmumblelink.o
endif

ifneq ($(USE_RENDERER_DLOPEN),0)
$(B)/$(OUT)/$(CLIENTBIN)$(FULLBINEXT): $(Q3OBJ) $(LIBSDLMAIN)
	$(echo_cmd) "LD $@"
	$(Q)$(CC) $(CLIENT_CFLAGS) $(CFLAGS) -rdynamic $(CLIENT_LDFLAGS) $(LDFLAGS) -o $@ $(Q3OBJ) $(LIBSDLMAIN) $(CLIENT_LIBS) $(LIBS) -lpthread

$(B)/$(OUT)/renderer_opengl1$(SHLIBNAME): $(Q3ROBJ) $(JPGOBJ)
	$(echo_cmd) "LD $@"
	$(Q)$(CC) $(CFLAGS) $(SHLIBLDFLAGS) -o $@ $(Q3ROBJ) $(JPGOBJ) $(THREAD_LIBS) $(LIBSDLMAIN) $(RENDERER_LIBS) $(LIBS) -lpthread

$(B)/$(OUT)/renderer_opengl2$(SHLIBNAME): $(Q3R2OBJ) $(Q3R2STRINGOBJ) $(JPGOBJ)
	$(echo_cmd) "LD $@"
	$(Q)$(CC) $(CFLAGS) $(SHLIBLDFLAGS) -o $@ $(Q3R2OBJ) $(Q3R2STRINGOBJ) $(JPGOBJ) $(LIBSDLMAIN) $(RENDERER_LIBS) $(LIBS) -lpthread
else
$(B)/$(OUT)/$(CLIENTBIN)$(FULLBINEXT): $(Q3OBJ) $(Q3ROBJ) $(JPGOBJ) $(LIBSDLMAIN)
	$(echo_cmd) "LD $@"
	$(Q)$(CC) $(CLIENT_CFLAGS) $(CFLAGS) -rdynamic $(CLIENT_LDFLAGS) $(LDFLAGS) -o $@ $(Q3OBJ) $(Q3ROBJ) $(JPGOBJ) $(LIBSDLMAIN) $(CLIENT_LIBS) $(RENDERER_LIBS) $(LIBS) -lpthread

$(B)/$(OUT)/$(CLIENTBIN)_opengl2$(FULLBINEXT): $(Q3OBJ) $(Q3R2OBJ) $(Q3R2STRINGOBJ) $(JPGOBJ) $(LIBSDLMAIN)
	$(echo_cmd) "LD $@"
	$(Q)$(CC) $(CLIENT_CFLAGS) $(CFLAGS) -rdynamic $(CLIENT_LDFLAGS) $(LDFLAGS) \
		-o $@ $(Q3OBJ) $(Q3R2OBJ) $(Q3R2STRINGOBJ) $(JPGOBJ) \
		$(LIBSDLMAIN) $(CLIENT_LIBS) $(RENDERER_LIBS) $(LIBS) -lpthread
endif

ifneq ($(strip $(LIBSDLMAIN)),)
ifneq ($(strip $(LIBSDLMAINSRC)),)
$(LIBSDLMAIN) : $(LIBSDLMAINSRC)
	cp $< $@
	$(RANLIB) $@
endif
endif



#############################################################################
# DEDICATED SERVER
#############################################################################

Q3DOBJ = \
  $(B)/ded/sv_client.o \
  $(B)/ded/sv_ccmds.o \
  $(B)/ded/sv_game.o \
  $(B)/ded/sv_init.o \
  $(B)/ded/sv_main.o \
  $(B)/ded/sv_net_chan.o \
  $(B)/ded/sv_snapshot.o \
  $(B)/ded/sv_world.o \
  $(B)/ded/sv_database.o \
  $(B)/ded/sv_sqlite.o \
  $(B)/ded/sqlite3.o \
  \
  $(B)/ded/cm_load.o \
  $(B)/ded/cm_patch.o \
  $(B)/ded/cm_polylib.o \
  $(B)/ded/cm_test.o \
  $(B)/ded/cm_trace.o \
  $(B)/ded/cmd.o \
  $(B)/ded/common.o \
  $(B)/ded/cvar.o \
  $(B)/ded/files.o \
  $(B)/ded/md4.o \
  $(B)/ded/msg.o \
  $(B)/ded/net_chan.o \
  $(B)/ded/net_ip.o \
  $(B)/ded/huffman.o \
  $(B)/ded/parse.o \
  $(B)/ded/packing.o \
  \
  $(B)/ded/q_math.o \
  $(B)/ded/q_shared.o \
  \
  $(B)/ded/vm.o \
  $(B)/ded/vm_interpreted.o \
  \
  $(B)/ded/null_client.o \
  $(B)/ded/null_input.o \
  $(B)/ded/null_snddma.o \
  \
  $(B)/ded/con_log.o \
  $(B)/ded/sys_main.o

ifeq ($(ARCH),x86)
  Q3DOBJ += \
      $(B)/ded/matha.o \
      $(B)/ded/snapvector.o \
      $(B)/ded/ftola.o
endif
ifeq ($(ARCH),x86_64)
  Q3DOBJ += \
      $(B)/ded/snapvector.o \
      $(B)/ded/ftola.o
endif

ifeq ($(USE_INTERNAL_ZLIB),1)
Q3DOBJ += \
  $(B)/ded/adler32.o \
  $(B)/ded/crc32.o \
  $(B)/ded/inffast.o \
  $(B)/ded/inflate.o \
  $(B)/ded/inftrees.o \
  $(B)/ded/zutil.o
endif

ifeq ($(USE_INTERNAL_MINIZIP),1)
  Q3DOBJ += \
    $(B)/ded/minizip/ioapi.o \
    $(B)/ded/minizip/unzip.o
endif

ifeq ($(HAVE_VM_COMPILED),true)
  ifneq ($(findstring $(ARCH),x86 x86_64),)
    Q3DOBJ += \
      $(B)/ded/vm_x86.o
  endif
  ifneq ($(findstring $(ARCH),ppc ppc64),)
    Q3DOBJ += $(B)/ded/vm_powerpc.o $(B)/ded/vm_powerpc_asm.o
  endif
  ifeq ($(ARCH),sparc)
    Q3DOBJ += $(B)/ded/vm_sparc.o
  endif
endif

ifeq ($(PLATFORM),mingw32)
  Q3DOBJ += \
    $(B)/ded/win_resource.o \
    $(B)/ded/sys_win32.o \
    $(B)/ded/con_win32.o
else
  Q3DOBJ += \
    $(B)/ded/sys_unix.o \
    $(B)/ded/con_tty.o
endif

ifeq ($(PLATFORM),darwin)
  Q3DOBJ += \
    $(B)/ded/sys_osx.o
endif

$(B)/$(OUT)/$(SERVERBIN)$(FULLBINEXT): $(Q3DOBJ)
	$(echo_cmd) "LD $@"
	$(Q)$(CC) $(CFLAGS) -rdynamic $(LDFLAGS) -o $@ $(Q3DOBJ) $(SERVER_LIBS) $(LIBS) -lpthread



#############################################################################
## TREMULOUS CGAME
#############################################################################

CGOBJ_ = \
  $(B)/cgame/cg_main.o \
  $(B)/cgame/bg_misc.o \
  $(B)/cgame/bg_pmove.o \
	$(B)/cgame/bg_entities.o \
  $(B)/cgame/bg_slidemove.o \
  $(B)/cgame/bg_lib.o \
  $(B)/cgame/bg_alloc.o \
	$(B)/cgame/bg_game_modes.o \
  $(B)/cgame/bg_voice.o \
  $(B)/cgame/bg_list.o \
  $(B)/cgame/cg_consolecmds.o \
  $(B)/cgame/cg_buildable.o \
  $(B)/cgame/cg_animation.o \
  $(B)/cgame/cg_animmapobj.o \
  $(B)/cgame/cg_draw.o \
  $(B)/cgame/cg_drawtools.o \
  $(B)/cgame/cg_ents.o \
  $(B)/cgame/cg_event.o \
  $(B)/cgame/cg_marks.o \
  $(B)/cgame/cg_players.o \
  $(B)/cgame/cg_playerstate.o \
  $(B)/cgame/cg_predict.o \
  $(B)/cgame/cg_servercmds.o \
  $(B)/cgame/cg_snapshot.o \
  $(B)/cgame/cg_view.o \
  $(B)/cgame/cg_weapons.o \
  $(B)/cgame/cg_scanner.o \
  $(B)/cgame/cg_attachment.o \
  $(B)/cgame/cg_trails.o \
  $(B)/cgame/cg_particles.o \
  $(B)/cgame/cg_tutorial.o \
  $(B)/cgame/ui_shared.o \
  \
  $(B)/qcommon/q_math.o \
  $(B)/qcommon/q_shared.o

CGOBJ11_ = \
  $(B)/11/cgame/cg_main.o \
  $(B)/cgame/bg_misc.o \
  $(B)/cgame/bg_pmove.o \
  $(B)/cgame/bg_entities.o \
  $(B)/cgame/bg_slidemove.o \
  $(B)/cgame/bg_lib.o \
  $(B)/cgame/bg_alloc.o \
  $(B)/cgame/bg_game_modes.o \
  $(B)/cgame/bg_voice.o \
  $(B)/cgame/bg_list.o \
  $(B)/11/cgame/cg_consolecmds.o \
  $(B)/cgame/cg_buildable.o \
  $(B)/cgame/cg_animation.o \
  $(B)/cgame/cg_animmapobj.o \
  $(B)/cgame/cg_draw.o \
  $(B)/cgame/cg_drawtools.o \
  $(B)/cgame/cg_ents.o \
  $(B)/cgame/cg_event.o \
  $(B)/cgame/cg_marks.o \
  $(B)/cgame/cg_players.o \
  $(B)/cgame/cg_playerstate.o \
  $(B)/cgame/cg_predict.o \
  $(B)/11/cgame/cg_servercmds.o \
  $(B)/11/cgame/cg_snapshot.o \
  $(B)/cgame/cg_view.o \
  $(B)/cgame/cg_weapons.o \
  $(B)/cgame/cg_scanner.o \
  $(B)/cgame/cg_attachment.o \
  $(B)/cgame/cg_trails.o \
  $(B)/cgame/cg_particles.o \
  $(B)/cgame/cg_tutorial.o \
  $(B)/cgame/ui_shared.o \
  \
  $(B)/qcommon/q_math.o \
  $(B)/qcommon/q_shared.o

CGOBJ = $(CGOBJ_) $(B)/cgame/cg_syscalls.o
CGVMOBJ = $(CGOBJ_:%.o=%.asm)
CGVMOBJ11 = $(CGOBJ11_:%.o=%.asm)

$(B)/$(OUT)/$(BASEGAME)/cgame$(SHLIBNAME): $(CGOBJ)
	$(echo_cmd) "LD $@"
	$(Q)$(CC) $(CFLAGS) $(SHLIBLDFLAGS) -o $@ $(CGOBJ)

$(B)/$(OUT)/$(BASEGAME)/vm/cgame.qvm: $(CGVMOBJ) $(CGDIR)/cg_syscalls.asm $(Q3ASM)
	$(echo_cmd) "Q3ASM $@"
	$(Q)$(Q3ASM) -o $@ $(CGVMOBJ) $(CGDIR)/cg_syscalls.asm

$(B)/$(OUT)/$(BASEGAME)_11/cgame$(SHLIBNAME): $(CGOBJ)
	$(echo_cmd) "LD $@"
	$(Q)$(CC) $(CFLAGS) $(SHLIBLDFLAGS) -o $@ $(CGOBJ)

$(B)/$(OUT)/$(BASEGAME)_11/vm/cgame.qvm: $(CGVMOBJ11) $(CGDIR)/cg_syscalls_11.asm $(Q3ASM)
	$(echo_cmd) "Q3ASM $@"
	$(Q)$(Q3ASM) -o $@ $(CGVMOBJ11) $(CGDIR)/cg_syscalls_11.asm



#############################################################################
## TREMULOUS GAME
#############################################################################

GOBJ_ = \
  $(B)/game/g_main.o \
  $(B)/game/bg_misc.o \
  $(B)/game/bg_pmove.o \
  $(B)/game/bg_entities.o \
  $(B)/game/bg_slidemove.o \
  $(B)/game/bg_lib.o \
  $(B)/game/bg_alloc.o \
  $(B)/game/bg_game_modes.o \
  $(B)/game/bg_voice.o \
  $(B)/game/bg_list.o \
  $(B)/game/g_active.o \
  $(B)/game/g_unlagged.o \
  $(B)/game/g_client.o \
  $(B)/game/g_cmds.o \
  $(B)/game/g_combat.o \
  $(B)/game/g_physics.o \
  $(B)/game/g_buildable.o \
  $(B)/game/g_misc.o \
  $(B)/game/g_missile.o \
  $(B)/game/g_mover.o \
  $(B)/game/g_session.o \
  $(B)/game/g_spawn.o \
  $(B)/game/g_svcmds.o \
  $(B)/game/g_target.o \
  $(B)/game/g_team.o \
  $(B)/game/g_trigger.o \
  $(B)/game/g_utils.o \
  $(B)/game/g_scrim.o \
  $(B)/game/g_maprotation.o \
  $(B)/game/g_weapon.o \
  $(B)/game/g_admin.o \
  $(B)/game/g_namelog.o \
  $(B)/game/g_playmap.o \
  $(B)/game/g_playermodel.o \
  $(B)/game/g_portal.o \
  \
  $(B)/qcommon/q_math.o \
  $(B)/qcommon/q_shared.o \
  $(B)/qcommon/packing.o

$(B)/$(OUT)/$(BASEGAME)/game$(SHLIBNAME): $(GOBJ_)
	$(echo_cmd) "LD $@"
	$(Q)$(CC) $(CFLAGS) $(SHLIBLDFLAGS) -o $@ $(GOBJ_)



#############################################################################
## TREMULOUS UI
#############################################################################

UIOBJ_ = \
  $(B)/ui/ui_main.o \
  $(B)/ui/ui_atoms.o \
  $(B)/ui/ui_shared.o \
  $(B)/ui/ui_gameinfo.o \
  \
  $(B)/ui/bg_alloc.o \
  $(B)/ui/bg_game_modes.o \
  $(B)/ui/bg_voice.o \
  $(B)/cgame/bg_list.o \
  $(B)/ui/bg_misc.o \
  $(B)/ui/bg_lib.o \
  $(B)/qcommon/q_math.o \
  $(B)/qcommon/q_shared.o

UIOBJ11_ = \
  $(B)/11/ui/ui_main.o \
  $(B)/ui/ui_atoms.o \
  $(B)/ui/ui_shared.o \
  $(B)/ui/ui_gameinfo.o \
  \
  $(B)/ui/bg_alloc.o \
  $(B)/ui/bg_game_modes.o \
  $(B)/ui/bg_voice.o \
  $(B)/cgame/bg_list.o \
  $(B)/ui/bg_misc.o \
  $(B)/ui/bg_lib.o \
  $(B)/qcommon/q_math.o \
  $(B)/qcommon/q_shared.o

UIOBJ = $(UIOBJ_) $(B)/ui/ui_syscalls.o
UIVMOBJ = $(UIOBJ_:%.o=%.asm)
UIVMOBJ11 = $(UIOBJ11_:%.o=%.asm)

$(B)/$(OUT)/$(BASEGAME)/ui$(SHLIBNAME): $(UIOBJ)
	$(echo_cmd) "LD $@"
	$(Q)$(CC) $(CFLAGS) $(SHLIBLDFLAGS) -o $@ $(UIOBJ)

$(B)/$(OUT)/$(BASEGAME)/vm/ui.qvm: $(UIVMOBJ) $(UIDIR)/ui_syscalls.asm $(Q3ASM)
	$(echo_cmd) "Q3ASM $@"
	$(Q)$(Q3ASM) -o $@ $(UIVMOBJ) $(UIDIR)/ui_syscalls.asm

$(B)/$(OUT)/$(BASEGAME)_11/ui$(SHLIBNAME): $(UIOBJ)
	$(echo_cmd) "LD $@"
	$(Q)$(CC) $(CFLAGS) $(SHLIBLDFLAGS) -o $@ $(UIOBJ)

$(B)/$(OUT)/$(BASEGAME)_11/vm/ui.qvm: $(UIVMOBJ11) $(UIDIR)/ui_syscalls_11.asm $(Q3ASM)
	$(echo_cmd) "Q3ASM $@"
	$(Q)$(Q3ASM) -o $@ $(UIVMOBJ11) $(UIDIR)/ui_syscalls_11.asm



#############################################################################
## CLIENT/SERVER RULES
#############################################################################

$(B)/client/%.o: $(ASMDIR)/%.s
	$(DO_AS)

# k8 so inline assembler knows about SSE
$(B)/client/%.o: $(ASMDIR)/%.c
	$(DO_CC) -march=k8

$(B)/client/%.o: $(CDIR)/%.c
	$(DO_CC)

$(B)/client/%.o: $(SDIR)/%.c
	$(DO_CC)

$(B)/client/%.o: $(CMDIR)/%.c
	$(DO_CC)

$(B)/client/%.o: $(SPEEXDIR)/%.c
	$(DO_CC)

$(B)/client/%.o: $(OGGDIR)/src/%.c
	$(DO_CC)

$(B)/client/vorbis/%.o: $(VORBISDIR)/lib/%.c
	$(DO_CC)

$(B)/client/minizip/%.o: $(MINIZIPDIR)/%.c
	$(DO_CC)

$(B)/client/opus/%.o: $(OPUSDIR)/src/%.c
	$(DO_CC)

$(B)/client/opus/%.o: $(OPUSDIR)/celt/%.c
	$(DO_CC)

$(B)/client/opus/%.o: $(OPUSDIR)/silk/%.c
	$(DO_CC)

$(B)/client/opus/%.o: $(OPUSDIR)/silk/float/%.c
	$(DO_CC)

$(B)/client/%.o: $(OPUSFILEDIR)/src/%.c
	$(DO_CC)

$(B)/client/%.o: $(ZDIR)/%.c
	$(DO_CC)

$(B)/client/%.o: $(SDLDIR)/%.c
	$(DO_CC)

$(B)/client/%.o: $(SYSDIR)/%.c
	$(DO_CC)

$(B)/client/%.o: $(SYSDIR)/%.m
	$(DO_CC)

$(B)/client/%.o: $(SYSDIR)/%.rc
	$(DO_WINDRES)


$(B)/renderergl1/%.o: $(CMDIR)/%.c
	$(DO_REF_CC)

$(B)/renderergl1/%.o: $(SDLDIR)/%.c
	$(DO_REF_CC)

$(B)/renderergl1/%.o: $(JPDIR)/%.c
	$(DO_REF_CC)

$(B)/renderergl1/%.o: $(RCOMMONDIR)/%.c
	$(DO_REF_CC)

$(B)/renderergl1/%.o: $(RGL1DIR)/%.c
	$(DO_REF_CC)

$(B)/renderergl2/glsl/%.c: $(RGL2DIR)/glsl/%.glsl
	$(DO_REF_STR)

$(B)/renderergl2/glsl/%.o: $(B)/renderergl2/glsl/%.c
	$(DO_REF_CC)

$(B)/renderergl2/%.o: $(RCOMMONDIR)/%.c
	$(DO_REF_CC)

$(B)/renderergl2/%.o: $(RGL2DIR)/%.c
	$(DO_REF_CC)


$(B)/ded/%.o: $(ASMDIR)/%.s
	$(DO_AS)

# k8 so inline assembler knows about SSE
$(B)/ded/%.o: $(ASMDIR)/%.c
	$(DO_CC) -march=k8

$(B)/ded/%.o: $(SDIR)/%.c
	$(DO_DED_CC)

$(B)/ded/%.o: $(CMDIR)/%.c
	$(DO_DED_CC)

$(B)/ded/%.o: $(ZDIR)/%.c
	$(DO_DED_CC)

$(B)/ded/%.o: $(SYSDIR)/%.c
	$(DO_DED_CC)

$(B)/ded/%.o: $(SYSDIR)/%.m
	$(DO_DED_CC)

$(B)/ded/%.o: $(SYSDIR)/%.rc
	$(DO_WINDRES)

$(B)/ded/%.o: $(NDIR)/%.c
	$(DO_DED_CC)

$(B)/ded/minizip/%.o: $(MINIZIPDIR)/%.c
	$(DO_DED_CC)

# Extra dependencies to ensure the git version is incorporated
ifeq ($(USE_GIT),1)
  $(B)/client/cl_console.o : .git/index
  $(B)/client/common.o : .git/index
  $(B)/ded/common.o : .git/index
endif


#############################################################################
## GAME MODULE RULES
#############################################################################

$(B)/cgame/bg_%.o: $(GDIR)/bg_%.c
	$(DO_CGAME_CC)

$(B)/cgame/ui_%.o: $(UIDIR)/ui_%.c
	$(DO_CGAME_CC)

$(B)/cgame/%.o: $(CGDIR)/%.c
	$(DO_CGAME_CC)

$(B)/cgame/bg_%.asm: $(GDIR)/bg_%.c $(Q3LCC)
	$(DO_CGAME_Q3LCC)

$(B)/cgame/ui_%.asm: $(UIDIR)/ui_%.c $(Q3LCC)
	$(DO_CGAME_Q3LCC)

$(B)/cgame/%.asm: $(CGDIR)/%.c $(Q3LCC)
	$(DO_CGAME_Q3LCC)

$(B)/11/cgame/%.asm: $(CGDIR)/%.c $(Q3LCC)
	$(DO_CGAME_Q3LCC_11)

$(B)/game/%.o: $(GDIR)/%.c
	$(DO_GAME_CC)

$(B)/ui/bg_%.o: $(GDIR)/bg_%.c
	$(DO_UI_CC)

$(B)/ui/%.o: $(UIDIR)/%.c
	$(DO_UI_CC)

$(B)/ui/bg_%.asm: $(GDIR)/bg_%.c $(Q3LCC)
	$(DO_UI_Q3LCC)

$(B)/ui/%.asm: $(UIDIR)/%.c $(Q3LCC)
	$(DO_UI_Q3LCC)

$(B)/11/ui/%.asm: $(UIDIR)/%.c $(Q3LCC)
	$(DO_UI_Q3LCC_11)


$(B)/qcommon/%.o: $(CMDIR)/%.c
	$(DO_SHLIB_CC)

$(B)/qcommon/%.asm: $(CMDIR)/%.c $(Q3LCC)
	$(DO_Q3LCC)


#############################################################################
# MISC
#############################################################################

OBJ = $(Q3OBJ) $(Q3ROBJ) $(Q3R2OBJ) $(Q3DOBJ) $(JPGOBJ) \
  $(GOBJ_) $(CGOBJ) $(UIOBJ) $(CGOBJ11) $(UIOBJ11) \
  $(CGVMOBJ) $(UIVMOBJ) $(CGVMOBJ11) $(UIVMOBJ11)
TOOLSOBJ = $(LBURGOBJ) $(Q3CPPOBJ) $(Q3RCCOBJ) $(Q3LCCOBJ) $(Q3ASMOBJ)
STRINGOBJ = $(Q3R2STRINGOBJ)

clean: clean-debug clean-release
	@$(MAKE) -C $(MASTERDIR) clean

clean-debug:
	@$(MAKE) clean2 B=$(BD)

clean-release:
	@$(MAKE) clean2 B=$(BR)

clean2:
	@echo "CLEAN $(B)"
	@rm -f $(OBJ)
	@rm -f $(OBJ_D_FILES)
	@rm -f $(STRINGOBJ)
	@rm -f $(TARGETS)

toolsclean: toolsclean-debug toolsclean-release

toolsclean-debug:
	@$(MAKE) toolsclean2 B=$(BD)

toolsclean-release:
	@$(MAKE) toolsclean2 B=$(BR)

toolsclean2:
	@echo "TOOLS_CLEAN $(B)"
	@rm -f $(TOOLSOBJ)
	@rm -f $(TOOLSOBJ_D_FILES)
	@rm -f $(LBURG) $(DAGCHECK_C) $(Q3RCC) $(Q3CPP) $(Q3LCC) $(Q3ASM)

distclean: clean toolsclean
	@rm -rf $(BUILD_DIR)

dist:
	git archive --format zip --output $(CLIENTBIN)-$(VERSION).zip HEAD

#############################################################################
# DEPENDENCIES
#############################################################################

ifneq ($(B),)
  OBJ_D_FILES=$(filter %.d,$(OBJ:%.o=%.d))
  TOOLSOBJ_D_FILES=$(filter %.d,$(TOOLSOBJ:%.o=%.d))
  -include $(OBJ_D_FILES) $(TOOLSOBJ_D_FILES)
endif

.PHONY: all clean clean2 clean-debug clean-release copyfiles \
	debug default dist distclean makedirs \
	release targets \
	toolsclean toolsclean2 toolsclean-debug toolsclean-release \
	$(OBJ_D_FILES) $(TOOLSOBJ_D_FILES)

# If the target name contains "clean", don't do a parallel build
ifneq ($(findstring clean, $(MAKECMDGOALS)),)
.NOTPARALLEL:
endif
