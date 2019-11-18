SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(notdir ${SRC}))

TARGET = test_bin
CC = gcc
CFLAGS = -I ./../include/
LIB = -L ../lib/ -lu8g2

${TARGET}:${OBJ}
	$(CC) $(OBJ) -o  $@ $(LIB)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ 
clean:
	rm *.o ${TARGET}