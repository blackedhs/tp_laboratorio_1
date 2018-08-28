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
    char salida='n';
    int respuesta;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    float factorialA;
    float factorialB;

    numeroA=0;
    numeroB=0;
    while (salida=='n'){
        printf("1. Ingresar 1er operando (A=%.2f)\n",numeroA);
        printf("2. Ingresar 2do operando (B=%.2f)\n",numeroB);
        printf("3. Calcular todas las operaciones siguentes:\n");
        printf("\t a). Calcular la suma\n");
        printf("\t b) Calcular la resta (A-B)\n");
        printf("\t c) Calcular la division (A/B)\n");
        printf("\t d) Calcular la multiplicacion (A*B)\n");
        printf("\t e) Calcular el factorial (A!)\n");
        printf("4. Informar los resultados\n");
        printf("5. Salir\n");
        printf("INGRESE UNA OPCION :\n");
        scanf("%d",&respuesta);
        switch (respuesta){
            case 1:
                printf("Ingrese el primer operando:");
                scanf("%f",&numeroA);
                break;
            case 2:
                printf("Ingrese el segundo operando:");
                scanf("%f",&numeroB);
                break;
            case 3:
                suma=sumaDosNumeros(numeroA, numeroB);
                resta=restaDosNumeros(numeroA,numeroB);
                division=divideDosNumeros(numeroA,numeroB);
                multiplicacion=multiplicaDosNumeros(numeroA,numeroB);
                factorialA=calculaFactorial(numeroA);
                factorialB=calculaFactorial(numeroB);
                break;
            case 4:
                printf("El resultado de la suma es: %.2f\n",suma);
                printf("El resultado de la resta es: %.2f\n",resta);
                if (division==0){
                    printf("No se puede dividir por cero\n");
                }else {
                    printf("El resultado de la division es: %.2f\n",division);
                }
                printf("El resultado de la multiplicacion es: %.2f\n",multiplicacion);
                printf("El factorial de %.2f es : %.2f y el factorial de %.2f es :%.2f\n",numeroA,factorialA,numeroB,factorialB);
                break;
            case 5:
                salida='s';
                break;
            default:
                printf("La opcion ingresada es invalida por favor intente nuevamente\n");
        }
    }
    return 0;
}
