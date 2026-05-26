CFLAGS=-std=c11 -g -static -fno-common

MyC: main.o
	$(CC) -o $@ $? $(LDFLAGS)

test: MyC 
	./test.sh

clean: 
	rm -f MyC *.o *~ tmp*

.PHONY: test clean