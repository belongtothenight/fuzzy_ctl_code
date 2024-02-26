CFLAG=-Wno-implicit-function-declaration -Wextra -Wall -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum -Wconversion -Wunreachable-code -Wformat=2 -O3
# https://stackoverflow.com/questions/3375697/what-are-the-useful-gcc-flags-for-c

all: main_c error_c
	gcc -o flc_sim -lm main.o error.o

clean:
	rm *.o flc_sim

clean_win:
	del *.o *.exe

# Dependencies
main_c: main.c
	gcc $(CFLAG) -c main.c

error_c: error.c
	gcc $(CFLAG) -c error.c
