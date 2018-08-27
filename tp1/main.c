#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
/*Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
2
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
*/

int main()
{
    float numeroA;
    float numeroB;
    float resultado;

    printf("Ingrese el primer numero:");
    scanf("%f",&numeroA);
    printf("Ingrese el segundo numero:");
    scanf("%f",&numeroB);
    resultado=sumaDosNumeros(numeroA, numeroB);
    printf("El resultado de la suma es: %.2f\n",resultado);
    resultado=restaDosNumeros(numeroA,numeroB);
    printf("El resultado de la resta es: %.2f\n",resultado);
    resultado=divideDosNumeros(numeroA,numeroB);
    if (resultado==0){
        printf("No se puede dividir por cero\n");
    }else {
        printf("El resultado de la division es: %.2f\n",resultado);
    }
    resultado=calculaFactorial(numeroA);
    printf("El factorial de %.2f es : %.2f\n",numeroA,resultado);
    resultado=calculaFactorial(numeroB);
    printf("El factorial de %.2f es : %.2f\n",numeroB,resultado);
    return 0;
}
