// suma dos numeros devuelve el resultado
float sumaDosNumeros(float a, float b){
    float resultado;
    resultado=a+b;
    return (resultado);
}
// resta de dos numeros
float restaDosNumeros(float a,float b){
    float resultado;
    resultado=a-b;
    return (resultado);
}
// division de dos numeros
float divideDosNumeros(float a,float b){
    float resultado;
    if (b==0)
        return 0;
    resultado=a/b;
    return (resultado);
}
//mulplicacion de dos nuemos
float multiplicaDosNumeros(float a,float b){
    float resultado;
    resultado=a*b;
    return (resultado);
}
//calcular factorial
int calculaFactorial(float a){
    int resultado;
    float textFactorial;

    if(a<0)
        return 0;
    textFactorial=(int)a-a;
    if (textFactorial<0)
        return 0;
    else if(a==0||a==1)
        return 1;
    resultado=a*calculaFactorial(a-1);
    return (resultado);
}
//muestra el menu
int mostrarMenu(float numeroA,float numeroB){
        #include <stdio.h>
        int respuesta;
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
        if (scanf("%d",&respuesta)!=1)
            mostrarMenu(numeroA,numeroB);
        return(respuesta);
}
