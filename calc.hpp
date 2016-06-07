#ifndef CALCULATOR
 #define CALCULATOR

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <new>
#include <cstdlib>

#include "stos.hpp"

class Calculator {

private:

    Stack stack;
    std::string operation;

public:

	void enter() { getline( std::cin, operation ); };
    void add();
    void subtract();
    void multiply();
    double result();
    bool check();

};

#endif // CALCULATOR
