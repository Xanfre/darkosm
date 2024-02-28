CPU=i386
NODEBUG=1
!include <win32.mak>

objdir = .\objs

CFLAGS = $(cflags) $(cvarsdll) $(cdebug)
CPPFLAGS = -D_CRT_SECURE_NO_WARNINGS -I..\include
LDFLAGS = $(dlllflags)

LIBS = uuid.lib

OSM_NAME = script

OBJS = $(objdir)/module.obj \
	$(objdir)/$(OSM_NAME).obj

all: $(objdir) $(OSM_NAME).osm

$(objdir)\module.obj: module.c common.h module.h script.h
	$(cc) $(CFLAGS) $(CPPFLAGS) /Fo$(objdir)\ /Fd$(objdir)\ /c module.c

$(objdir)\script.obj: script.c common.h script.h
	$(cc) $(CFLAGS) $(CPPFLAGS) /Fo$(objdir)\ /Fd$(objdir)\ /c script.c

$(OSM_NAME).osm: $(OBJS)
	$(link) $(LDFLAGS) -out:$@ $** $(LIBS)

clean:
	-rmdir /s /q $(objdir) >nul 2>&1
	-del /q $(OSM_NAME).osm $(OSM_NAME).osm.manifest $(OSM_NAME).exp $(OSM_NAME).lib >nul 2>&1

$(objdir):
	mkdir $@

