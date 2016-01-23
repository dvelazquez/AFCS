# Daniel Velazquez
# January 2016 - GIT Test
CXX ?= gcc

CXXFLAGS += -c -Wall $(shell pkg-config --cflags opencv -lgobject-2.0)
LDFLAGS += $(shell pkg-config --libs --static opencv )

all: main

main: main.o; $(CXX) $< -o $@ $(LDFLAGS)

%.o: %.cpp; $(CXX) $< -o $@ $(CXXFLAGS)

clean: ; rm -f main.o main
