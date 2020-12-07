CPPFLAGS += -Wall -Wextra -Weffc++ -Wsign-conversion -std=c++17 -MD
CPPFLAGS += $(shell pkg-config --cflags sdl2)
LDFLAGS += $(shell pkg-config --libs sdl2)

SOURCES = $(wildcard *.cpp)
OBJECTS = ${SOURCES:.cpp=.o}
	DEPS = $(OBJECTS:.o=.d)
	HEADERS = $(wildcard *.h)
BINARY = age

.PHONY: all release clean

all: CPPFLAGS += -DDEBUG -O0 -g
all: ${BINARY}

release: CPPFLAGS += -O3
release: ${BINARY}
	strip ${BINARY}

${BINARY}: ${OBJECTS}
	${LINK.cpp} ${OUTPUT_OPTION} $^

clean:
	${RM} ${BINARY} ${OBJECTS} ${DEPS}

-include ${DEPS}
