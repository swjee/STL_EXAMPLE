PROGS	= test functest arithm
CC	= g++
#CFLAGS 	= -g  -save-temps
CFLAGS 	= -g  
LIBS 	= -lpthread

all:	${PROGS}

.c.o:
	$(CC) $(CFLAGS) -c $< 

.cpp.o:
	$(CC) $(CFLAGS) -c $<

test:	test.o
			${CC} ${CFLAGS} -o $@ test.o ${LIBS}

functest: 	functest.o
			${CC} ${CFLAGS} -o $@ functest.o ${LIBS}


arithm: 	arithm.o
			${CC} ${CFLAGS} -o $@ arithm.o ${LIBS}


clean:
	rm -rf *.o *.ii *.s test


