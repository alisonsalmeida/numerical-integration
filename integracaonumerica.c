#include <stdio.h>
#include <math.h>

double funcao(double x){
    return sin(x);
}

double Trapezio(double lsuperior, double linferior, int iteracoes){
    double passo;
    double resultado[iteracoes], somatorio, sum;
    int _iteracoes;
    double x;
    int i;

    somatorio = 0;
    _iteracoes = 0;
    passo = (lsuperior - linferior) / iteracoes;
    printf("passo: %f\n", passo);
    x = linferior;
    
    //Calcula todos os pequenos intervalos da funcao
    for(i = 0; i <= iteracoes; i++){
        resultado[_iteracoes] = funcao(x);
        printf("resultado:  %f, x: %f, i: x %d\n", funcao(x), x, i);
        _iteracoes++;
        x = x + passo;
    }
    
    //soma os extremos
    sum = resultado[0] + resultado[iteracoes];

    for(i = 1; i < iteracoes; i++){
        somatorio = somatorio + resultado[i];
    }

    return (passo / 2) * (sum + (2 * somatorio));
}

double Simpson1Regra(double lsuperior, double linferior, int iteracoes){
    double passo;
    double resultado[iteracoes], somatorio, sum, sumpar, sumimpar;
    int _iteracoes;
    double x;
    int i;

    somatorio = 0;
    sumpar = 0;
    sumimpar = 0;
    
    _iteracoes = 0;
    passo = (lsuperior - linferior) / iteracoes;
    printf("passo: %f\n", passo);
    x = linferior;
    
    //Calcula todos os pequenos intervalos da funcao
    for(i = 0; i <= iteracoes; i++){
        resultado[_iteracoes] = funcao(x);
        printf("resultado:  %f, x: %f, i: x %d\n", funcao(x), x, i);
        _iteracoes++;
        x = x + passo;
    }
    
    //soma os extremos
    sum = resultado[0] + resultado[iteracoes];

    for(i = 1; i < iteracoes; i++){
        if(i%2 == 0){
            sumpar = sumpar + (resultado[i] * 2);
        }
        else{
            sumimpar = sumimpar + (resultado[i] * 4);
        }
    }
    return (passo/3) * (sum + sumpar+ sumimpar);
}

double Simpson2Regra(double lsuperior, double linferior, int iteracoes){
    double passo;
    double resultado[iteracoes], somatorio, sum, sumpar, sumimpar;
    int _iteracoes;
    double x;
    int i;

    somatorio = 0;
    sumpar = 0;
    sumimpar = 0;
    
    _iteracoes = 0;
    passo = (lsuperior - linferior) / iteracoes;
    printf("passo: %f\n", passo);
    x = linferior;
    
    //Calcula todos os pequenos intervalos da funcao
    for(i = 0; i <= iteracoes; i++){
        resultado[_iteracoes] = funcao(x);
        printf("resultado:  %f, x: %f, i: x %d\n", funcao(x), x, i);
        _iteracoes++;
        x = x + passo;
    }
    
    //soma os extremos
    sum = resultado[0] + resultado[iteracoes];

    for(i = 1; i < iteracoes; i++){
        if(i%3 == 0){
            sumpar = sumpar + (resultado[i] * 2);
        }
        else{
            sumimpar = sumimpar + (resultado[i] * 3);
        }
    }
    return ((passo * 3 ) /8) * (sum + sumpar + sumimpar);
}

int main(){
    printf("%f\n", Simpson2Regra(3.14, 0, 20));
}