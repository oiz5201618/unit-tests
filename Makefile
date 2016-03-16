EXEC = bin-swap bin-bubble bin-merge
RESULT = result-bubble result-swap result-merge
.PHONY: all
all: $(EXEC)

CC ?= gcc
CFLAGS = -std=gnu99 -Wall -O2 -g
LDFLAGS =

OBJS := \
	swap.o \
	bubble.o \
	merge.o \
	stub.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

bin-%: %.o stub.o
	$(CC) -o $@ $^ $(LDFLAGS)

check: $(EXEC)
	bash test-swap.sh data-swap.in result-swap
	bash test-bubble.sh data-bubble.in result-bubble
	bash test-merge.sh data-merge.in result-merge

clean:
	$(RM) $(EXEC) $(OBJS) $(RESULT) _tmp.gdb
