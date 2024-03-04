CC=g++
CFLAG=-Wno-implicit-function-declaration -Wextra -Wall -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum -Wconversion -Wunreachable-code -Wformat=2 -O3
CPPFLAG=-Wextra -Wall -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum -Wconversion -Wunreachable-code -Wformat=2 -O3
FLAG=$(CPPFLAG)
# https://stackoverflow.com/questions/3375697/what-are-the-useful-gcc-flags-for-c

eFLL_PATH=../../../eFLL
eFLL_LIB=$(eFLL_PATH)/Fuzzy.o $(eFLL_PATH)/FuzzyComposition.o $(eFLL_PATH)/FuzzyIO.o $(eFLL_PATH)/FuzzyInput.o $(eFLL_PATH)/FuzzyOutput.o $(eFLL_PATH)/FuzzyRule.o $(eFLL_PATH)/FuzzyRuleAntecedent.o $(eFLL_PATH)/FuzzyRuleConsequent.o $(eFLL_PATH)/FuzzySet.o

flc_sim: main.o error.o
	$(CC) $(FLAG) -o $@ -lm $(eFLL_LIB) $^

clean:
	rm *.o flc_sim

clean_win:
	del *.o *.exe

# Dependencies
main.o: main.cpp
	$(CC) $(FLAG) -c $^

error.o: error.c
	$(CC) $(FLAG) -c $^

eFLL:
	cd $(eFLL_PATH) && make
