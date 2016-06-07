#include <iostream>
#include <stdlib.h>
#include "stos.hpp"
#include "calc.hpp"

int main (void) {
    try {
        char c = '1';
        Calculator calc;
        while ( c != 'q' ) {
            std::cout << "Enter operation" << std::endl;
            calc.enter();
            if ( calc.check() ) std::cout << "Result = " << calc.result() << std::endl;
            else std::cout << "Something gone wrong" << std::endl;
            std::cout << "Press 'q' to exit, or different button to continue" << std::endl;
            std::cin >> c;

            #ifdef WIN32
                std::cin.clear();
                std::cin.sync();
                system("cls");
            #else
                std::cin.clear();
                std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
                system("clear");
                //printf("\033[0;0f");
            #endif
        }
    }

    catch ( const char * error ) {
        std::cout << std::endl << "An Error has occurred, the program will be terminated." << std::endl << "Reason:" << std::endl << error;
        exit(EXIT_FAILURE);
    }

    catch(std::bad_alloc & error)
    {

        std::cout << error.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}
