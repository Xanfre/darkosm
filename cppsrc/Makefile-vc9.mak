CPU=i386
NODEBUG=1
!include <win32.mak>

objdir = .\objs

CFLAGS = $(cflags) $(cvarsdll) $(cdebug)
CPPFLAGS = -D_CRT_SECURE_NO_WARNINGS -I..\include -DNEWDARK
LDFLAGS = $(dlllflags)

LIBS = uuid.lib

OSM_NAME = script

OBJS = $(objdir)\module.obj \
	$(objdir)\$(OSM_NAME).obj \
	$(objdir)\alloc.obj \
	$(objdir)\api.obj

all: $(objdir) $(OSM_NAME).osm

$(objdir)\module.obj: module.cpp api.hpp module.hpp script.hpp
	$(cc) $(CFLAGS) $(CPPFLAGS) /Fo$(objdir)\ /Fd$(objdir)\ /c module.cpp

$(objdir)\script.obj: script.cpp api.hpp script.hpp
	$(cc) $(CFLAGS) $(CPPFLAGS) /Fo$(objdir)\ /Fd$(objdir)\ /c script.cpp

$(objdir)\alloc.obj: alloc.cpp api.hpp
	$(cc) $(CFLAGS) $(CPPFLAGS) /Fo$(objdir)\ /Fd$(objdir)\ /c alloc.cpp

$(objdir)\api.obj: api.cpp api.hpp
	$(cc) $(CFLAGS) $(CPPFLAGS) /Fo$(objdir)\ /Fd$(objdir)\ /c api.cpp

$(OSM_NAME).osm: $(OBJS)
	$(link) $(LDFLAGS) -out:$@ $** $(LIBS)

clean:
	-rmdir /s /q $(objdir) >nul 2>&1
	-del /q $(OSM_NAME).osm $(OSM_NAME).osm.manifest $(OSM_NAME).exp $(OSM_NAME).lib >nul 2>&1

$(objdir):
	mkdir $@

