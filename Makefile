output: main.cpp stos.o
 calc.o
	g++ main.cpp stos.o calc.o -o output


stos.o: stos.cpp stos.hpp

	g++ -c stos.cpp


calc.o: calc.cpp calc.hpp
	g++ -c calc.cpp

clean:

	rm *.o output