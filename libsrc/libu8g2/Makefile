CC    := $(CROSS)gcc
AR    := $(CROSS)ar
LD    := $(CROSS)ld
STRIP := $(CROSS)strip

CFLAGS  = -Wall -I ../../include
OUTPUTLIB = libu8g2.a
SRC = $(wildcard *.c)
OBJSLIB = $(patsubst %.c,%.o,$(notdir ${SRC}))

all: lib

lib: $(OBJSLIB)
	$(AR) rc $(OUTPUTLIB) $(OBJSLIB)
	cp $(OUTPUTLIB) ../../lib

clean:
	rm -f $(OUTPUTLIB) $(OBJSLIB)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
