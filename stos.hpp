#ifndef WEKTOR
 #define WEKTOR

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Stack {

private:

    double* stack;		                   	//stos
    int size;				               	//wielkosc stosu
    int digit;				            	//ile jest cyfr

public:

    Stack (int size = 5);		           	//konstruktor
    Stack (const Stack &B);		        	//konstruktor kopiujacy
    ~Stack ();				            	//destruktor

    int getSize() const;		        	//zwraca size
    int getDigit() const;			        //zwraca digit
    double* getStack() const;		    	//zwraca stos

    void show() const;                      //wyswietla zawartosc stosu
    void reset();                           //usuwa liczby ze stosu i przywraca size 5
    void resize( int a );                   //zmienia rozmiar stosu

    void push(double element);		    	//wkladanie elementu na szczyt stosu
    void pop();                             //usuwanie elementu na szczycie ze stosu
    double top() const;                     //zwraca element na wierzcholku stosu bez usuwania go
    int isempty() const;                    //zwraca 1 gdy stos jest pusty

    Stack & operator = (const Stack &B);	//operator przypisania

};

#endif
