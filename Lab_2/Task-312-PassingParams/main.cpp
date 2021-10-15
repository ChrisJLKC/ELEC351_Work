#include "mbed.h"
#include "Complex.h"

int main() {
    printf("\n\nTASK312\n");

    //Create instance of a complex number
    ComplexNumber_C p = {2.0, 3.0};
    ComplexNumber_C q = {1.0, 1.0};
    complexDisplay("p", p);
    complexDisplay("q", q);
 
    ComplexNumber_C sum = complexAdd(p, q);
    complexDisplay("p+q", sum);

    ComplexNumber_C Con_p = complexConjugate(p);
    complexDisplay("p_Con", Con_p);

    ComplexNumber_C Con_q = complexConjugate(q);
    complexDisplay("q_Con", Con_q);

    ComplexNumber_C Neg_p = complexNegate(p);
    complexDisplay("p_Neg", Neg_p);

    ComplexNumber_C Neg_q = complexNegate(q);
    complexDisplay("q_Neg", Neg_q);

    ComplexNumber_C Sub_p_q = complexSubract(p, q);
    complexDisplay("Sub_p_q", Sub_p_q);

    ComplexNumber_C Mag_p = complexMagnitude(p);
    complexDisplay("Mag_p", Mag_p);

    ComplexNumber_C Mag_q = complexMagnitude(q);
    complexDisplay("Mag_q", Mag_q);

    ComplexNumber_C Multi_p_q = complexMultiply(p, q);
    complexDisplay("Multi_p_q", Multi_p_q);

    ComplexNumber_C Divide_p_q = complexDivide(p, q);
    complexDisplay("Divide_p_q", Divide_p_q);

    
    while (true) {
    }
}
