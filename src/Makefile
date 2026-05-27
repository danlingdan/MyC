CFLAGS=-std=c11 -g -static -fno-common
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

huacc: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OBJS): hua.h

test: huacc
	./test.sh

clean:
	rm -f huacc *.o *~ tmp*

.PHONY: test clean