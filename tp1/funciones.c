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
float calculaFactorial(float a){
    float resultado;
    int factorial;
    factorial=(int)a;
    if (factorial==1)
        return 1;
    else if(factorial==0)
        return 0;
    resultado=a*calculaFactorial(a-1);
    return (resultado);
}
