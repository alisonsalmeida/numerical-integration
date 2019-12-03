#include <stdio.h>
#include <math.h>

double funcao(double _passo, int _i){
    return 1 / (1 + pow((_passo * _i), 2));
}

double Trapezio(double lsuperior, double linferior, int iteracoes){
    double passo;
    double resultado[iteracoes], integration, somatorio;
    int i;

    passo = (lsuperior - linferior) / iteracoes;

    for(i = 0; i <= iteracoes; i++){
        resultado[i] = funcao(passo, i);
    }
    
    somatorio = resultado[0] + resultado[iteracoes];

    for(i = 1; i < iteracoes; i++){
        somatorio = somatorio + (resultado[i] * 2);
    }
    
    integration = (passo / 2) * somatorio;
    return integration;
}

double Simpson1Regra(double lsuperior, double linferior, int iteracoes){
    double passo;
    double resultado[iteracoes], integration, somatorio;
    int i;

    passo = (lsuperior - linferior) / iteracoes;

    for(i = 0; i <= iteracoes; i++){
        resultado[i] = funcao(passo, i);
    }
    
    somatorio = resultado[0] + resultado[iteracoes];

    for(i = 1; i < iteracoes; i++){
        if(i%2 == 0){
            somatorio = somatorio + (resultado[i] * 2);
        }
        else{
            somatorio = somatorio + (resultado[i] * 4);
        }
    }
    
    integration = (passo / 3) * somatorio;
    return integration;
}

double Simpson2Regra(double lsuperior, double linferior, int iteracoes){
    double passo;
    double resultado[iteracoes], integration, somatorio;
    int i;

    passo = (lsuperior - linferior) / iteracoes;

    for(i = 0; i <= iteracoes; i++){
        resultado[i] = funcao(passo, i);
    }
    
    somatorio = resultado[0] + resultado[iteracoes];

    for(i = 1; i < iteracoes; i++){
        if(i%3 == 0){
            somatorio = somatorio + (resultado[i] * 2);
        }
        else{
            somatorio = somatorio + (resultado[i] * 3);
        }
    }

    integration = ((passo * 3) / 8) * somatorio;
    return integration;
}

int main(){
    printf("%f\n", Trapezio(1, 0, 4));
}