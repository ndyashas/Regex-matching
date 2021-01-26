CC=gcc
INCLUDE_FLAGS=-Iinclude
LINK_FLAGS=

all: client

client: src/client.o src/regexm.o
	${CC} ${INCLUDE_FLAGS} ${LINK_FLAGS} $^ -o $@

src/regexm.o: src/regexm.c include/regexm.h
	${CC} -c ${INCLUDE_FLAGS} ${LINK_FLAGS} src/regexm.c -o $@

src/client.o: src/client.c include/regexm.h
	${CC} -c ${INCLUDE_FLAGS} ${LINK_FLAGS} src/client.c -o $@

clean:
	${RM} src/*.o client

.PHONY: clean all
