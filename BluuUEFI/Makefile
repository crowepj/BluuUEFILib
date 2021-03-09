SRC = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRC))
CFLAGS=-fno-stack-protector -ffreestanding -nostdlib
objs : $(OBJS)