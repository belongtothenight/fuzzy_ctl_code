CC=g++
CFLAG=-Wno-implicit-function-declaration -Wextra -Wall -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum -Wconversion -Wunreachable-code -Wformat=2 -O3
CPPFLAG=-Wextra -Wall -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum -Wconversion -Wunreachable-code -Wformat=2 -O3
FLAG=$(CPPFLAG)
# https://stackoverflow.com/questions/3375697/what-are-the-useful-gcc-flags-for-c

flc_sim: main.o error.o
	$(CC) $(FLAG) -o $@ -lm $^

clean:
	rm *.o flc_sim

clean_win:
	del *.o *.exe

# Dependencies
main.o: main.c
	$(CC) $(FLAG) -c $^

error.o: error.c
	$(CC) $(FLAG) -c $^
