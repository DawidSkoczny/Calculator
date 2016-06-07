#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include "calc.hpp"
#include "stos.hpp"

    void Calculator::add() {         //pobiera dwie ostatnie liczby ze stosu i w ich miejsce wpisuje wynik
        double a = stack.top();
        stack.pop();
        double b = stack.top();
        stack.pop();
        double c = a+b;
        stack.push( b+a );
    }

    void Calculator::subtract() {    //pobiera dwie ostatnie liczby ze stosu i w ich miejsce wpisuje wynik
        double a = stack.top();
        stack.pop();
        double b = stack.top();
        stack.pop();
        stack.push( b-a );
    }

    void Calculator::multiply() {    //pobiera dwie ostatnie liczby ze stosu i w ich miejsce wpisuje wynik
        double a = stack.top();
        stack.pop();
        double b = stack.top();
        stack.pop();
        stack.push( b*a );
    }

    double Calculator::result() {   //sprawdza ktore dzialanie nalezy wykonac, jezeli dojdzie do konca lini,zwraca wynik
        int i = 0;
        while ( operation[i] ) {
            std::string temp;
            if ( operation[i] == ' ' ) i++; {
                if ( operation[i] == '+' ) {
                    add();
                    i++;
                }
                else if ( operation[i] == '-' ) {
                    subtract();
                    i++;
                }
                else if ( operation[i] == '*' ) {
                    multiply();
                    i++;
                }
                else {
                    while ( operation[i] != ' ' ) {
                        temp += operation[i];
                        i++;
                    }
                    int number;
                    std::istringstream iss(temp);
                    iss >> number;
                    stack.push(number);
                }
            }
        }
        return stack.top();
    }

    bool Calculator::check() {      //sprawdza czy zadane dzialanie moze zostac obliczone
        int i = 0, operators = 0, operands = 0, length = operation.size();
        while( operation[i] ) {
            if (operation[i]==' ') i++;
            else if ( operation[i] == '+' || operation[i] == '-' || operation[i] == '*')
            {
                if ( operation[i+1] == ' ' || i == length-1 )
                {
                    operators++;
                    i++;
                }
                else return false;
            }
            else {
                while ( operation[i] != ' ' ) {
                    if ( operation[i] >= '0' && operation[i] <= '9' ) i++;
                    else return false;
                }
                operands++;
            }
            if ( operators >= operands ) return false;
        }
        if ( operators == operands-1 ) return true;
        else return false;
    }
