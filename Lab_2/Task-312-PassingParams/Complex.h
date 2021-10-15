#ifndef COMPLEX_H_
#define COMPLEX_H_

typedef struct {
  double real;
  double imag;
} ComplexNumber_C;

ComplexNumber_C complexAdd(ComplexNumber_C a, ComplexNumber_C b);
ComplexNumber_C complexConjugate(ComplexNumber_C a);
ComplexNumber_C complexNegate(ComplexNumber_C a);
ComplexNumber_C complexSubract(ComplexNumber_C a, ComplexNumber_C b);
ComplexNumber_C complexMagnitude(ComplexNumber_C a);
ComplexNumber_C complexMultiply(const ComplexNumber_C a, const ComplexNumber_C b);
ComplexNumber_C complexDivide(const ComplexNumber_C a, const ComplexNumber_C b);
void complexDisplay(const char *strName, const ComplexNumber_C u); 


#endif