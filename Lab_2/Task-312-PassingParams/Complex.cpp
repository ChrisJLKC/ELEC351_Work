#include "mbed.h"
#include "Complex.h"

ComplexNumber_C complexAdd(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;
    y.real += b.real;
    y.imag += b.imag;
    return y;
}

ComplexNumber_C complexConjugate(const ComplexNumber_C a) {
    ComplexNumber_C y = a;

    y.real = (y.real + y.imag) * (y.real - y.imag);
    y.imag = 0;
    
    return y; 
}

ComplexNumber_C complexNegate(const ComplexNumber_C a) {
    ComplexNumber_C y = a;

    y.real = -y.real;
    y.imag = -y.imag;

    return y;
}

ComplexNumber_C complexSubract(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;

    y.real = y.real - b.real;
    y.imag = y.imag - b.imag;

    return y;
}

ComplexNumber_C complexMagnitude(const ComplexNumber_C a) {
    ComplexNumber_C y = a;

    y.real = 0;
    y.imag = sqrt((y.real * y.real) + (y.imag * y.imag));

    return y;
}

ComplexNumber_C complexMultiply(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;

    y.real = y.real * b.real;
    y.imag = y.imag * b.imag;

    return y;
}

ComplexNumber_C complexDivide(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;

    y.real = y.real / b.real;
    y.imag = y.imag / b.imag;

    return y;
}

void complexDisplay(const char *strName, const ComplexNumber_C u) {
    printf("%s = %f + j%f\n", strName, u.real, u.imag);
}