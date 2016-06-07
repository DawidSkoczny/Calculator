#include "stos.hpp"

using namespace std;

    Stack::Stack (int size) {                       //konstruktor
        this->digit = 0;
        if(size < 1) {
            this->size = 0;
            stack = NULL;
        }
        stack = new double [size];
        if(stack == NULL) {
            this->size = 0;
            throw "\nBlad konstruktora stosu\n";
        } else {
            this->size = size;
        }
    }


    Stack::Stack (const Stack &B) {                  //konstruktor kopiujacy
        delete [] stack;
        if(B.size < 1 || B.stack == NULL ) {
            this->size = 0;
            this->digit = 0;
            stack = NULL;
        } else {
            stack = new double [B.size];
            if ( stack == NULL ) {
                this->size = 0;
                this->digit = 0;
                throw "\nBlad konstruktora kopiujacego stosu\n";
            } else {
                size = B.size;
                digit = B.digit;
                for ( int i = 0; i < size; i++ )
                    stack[i] = B.stack[i];
            }
        }
    }

    Stack::~Stack () {                              //destruktor
        delete [] stack;
        this->size = 0;
        this->digit = 0;
    }

    int Stack::getSize() const {                    //zwraca size
        return size;
    }

    int Stack::getDigit() const {                   //zwraca digit
        return digit;
    }

    double* Stack::getStack() const {               //zwraca stos
        return stack;
    }

    void Stack::show() const {                      //wyswietla zawartosc stosu
        for ( int i = 0; i < digit -1; i++ ) {
            cout << stack[i] << " ";
        }
        cout << stack[digit];
    }

    void Stack::reset() {                           //usuwa liczby ze stosu i przywraca size 5
        delete [] stack;
        stack = new double [5];
        size = 5;
        digit = 0;
    }

    void Stack::resize( int a ) {                   //zmienia rozmiar stosu
        double * temporary = new double [a];
        size = a;
        for ( int i = 0; i < a; i++ )
            temporary[i] = stack[i];
        delete [] stack;
        stack = temporary;
    }

    void Stack::push(double element) {              //wkladanie elementu na szczyt stosu
        if ( digit == size )
            (*this).resize( size+5 );
        *(stack + digit) = element;
        ++digit;
    }

    void Stack::pop() {                             //usuwanie elementu na szczycie ze stosu
        digit--;
    }

    double Stack::top() const {                     //zwraca element na wierzcholku stosu bez usuwania go
        return stack[digit-1];
    }

    int Stack::isempty() const {                    //zwraca 1 gdy stos jest pusty
        if ( digit != 0 ) return 0;
        else return 1;
    }

    Stack & Stack::operator=(const Stack & B) {     //operator przypisania
        if ( this == & B )
            return *this;
        if( B.size < 1 || B.stack == NULL ) {
            size = 0;
            stack = NULL;
            throw "\nBlad operatora = stosu (zly wymiar)\n";
        }
        delete[] stack;
        size = 0;
        stack = new double [B.size];
        if ( stack == NULL ) {
            size = 0;
            throw "\nBlad operatora = macierzy (nie udalo sie utowrzyc macierzy)\n";
        }
        size = B.size;
        for ( int i = 0; i < size; i++) {
            *(stack + i) = *(B.stack + i);
        }
        return *this;
    }
