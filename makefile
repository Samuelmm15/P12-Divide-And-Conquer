text0 =
text1 = Compilación del proyecto...
text2 = Modo de empleo:
text3 = ./largeIntegerMultiplication
text4 = Se han eliminado el fichero ejecutable y los ficheros objetos.
text5 = clear; make clean; make; clear; ./largeIntegerMultiplication

CC=g++
CXXFLAGS=-g -std=c++14

OBJS = src/mainDivideAndConquer.o

all: ${OBJS}
		@echo $(text0)
		@echo $(text1)
		$(CC) $(CXXFLAGS) -o largeIntegerMultiplication ${OBJS}
		@echo $(text0)
		@echo $(text2)
		@echo $(text3)

clean:
	rm -rf src/*.o largeIntegerMultiplication
	@echo $(text4)