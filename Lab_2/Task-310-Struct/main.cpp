#include "mbed.h"

// Date Type ComplexNumber_C
typedef struct {
  double real;
  double imag;
} ComplexNumber_C;

int main() {

    //Create instance of a complex number
    ComplexNumber_C p;

    //Initialise each attribute 
    p.real = 2.0;
    p.imag = 3.0;
    
    //Create and Initialise 
    ComplexNumber_C q = {1.0, 1.0};

    // Creating instance of complex number and Initialise
    ComplexNumber_C y = {p.real + q.real, p.imag + q.imag};

    printf("%f %fi", y.real, y.imag);
    
    while (true) {
    }
}
