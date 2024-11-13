objdir = ./objs

CXX = i686-w64-mingw32-g++
DLLTOOL = i686-w64-mingw32-dlltool

CFLAGS_ALL = -std=c++98 -O2 -march=native -pipe $(CFLAGS)
CPPFLAGS_ALL = -Wall -Wextra -pedantic -I../include -DNEWDARK $(CPPFLAGS)
LDFLAGS_ALL = -shared -s $(LDFLAGS)

LIBS = -luuid

OSM_NAME ?= script

OSM_OBJS = $(objdir)/module.o \
		   $(objdir)/$(OSM_NAME).o \
		   $(objdir)/alloc.o \
		   $(objdir)/apiex.o
OBJS = $(OSM_OBJS) $(objdir)/exports.o

all: $(objdir) $(OSM_NAME).osm

$(objdir)/%.o: %.cpp
	$(CXX) $(CFLAGS_ALL) $(CPPFLAGS_ALL) -c -o $@ $<

$(objdir)/exports.o: $(OSM_OBJS)
	$(DLLTOOL) --add-underscore --dllname $(OSM_NAME) --output-exp $@ $^

$(OSM_NAME).osm: $(OBJS)
	$(CXX) $(CFLAGS_ALL) $(LDFLAGS_ALL) $^ -o $@ $(LIBS)

$(objdir)/module.o: apiex.hpp module.hpp script.hpp
$(objdir)/script.o: apiex.hpp script.hpp
$(objdir)/alloc.o: apiex.hpp
$(objdir)/apiex.o: apiex.hpp

clean:
	-rm -rf $(objdir)
	-rm -f $(OSM_NAME).osm

$(objdir):
	mkdir -p $@

