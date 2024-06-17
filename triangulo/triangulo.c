#include "triangulo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void getLados(double* array_lados) {
    printf("Digite o primeiro lado: ");
    scanf("%lf", &array_lados[0]);

    printf("Digite o segundo lado: ");
    scanf("%lf", &array_lados[1]);

    printf("Digite o terceiro lado: ");
    scanf("%lf", &array_lados[2]);
}

double getAngulo(double a, double b, double c) {
    double rad = acos((pow(a, 2) - pow(b, 2) - pow(c, 2)) / (-2*b*c));
    double result = rad * (180/PI);
    return result;
}

void getAngulos(double* array_lados, double* array_angulos) {
    double 
    l1 = array_lados[0], 
    l2 = array_lados[1],
    l3 = array_lados[2];
    
    array_angulos[0] = getAngulo(l1, l2, l3);
    array_angulos[1] = getAngulo(l2, l1, l3);
    array_angulos[2] = getAngulo(l3, l2, l1);
}

int validarTriangulo(double* array_lados) {
    double 
    l1 = array_lados[0], 
    l2 = array_lados[1],
    l3 = array_lados[2];

    if(l1 == 0 || l2 == 0 || l3 == 0)
        return 0;

    // somando os lados
    if((l1 + l2) < l3 || (l1 + l3) < l2 || (l2 + l3) < l1)
        return 0;

    return 1;
}

void getNomenclatura(double* array_lados, double* array_angulos, char* nomenclatura) {
    // em relacao aos lados
    double 
    l1 = array_lados[0], 
    l2 = array_lados[1],
    l3 = array_lados[2],
    a1 = array_angulos[0],
    a2 = array_angulos[1],
    a3 = array_angulos[2];

    char* tipo_lado;
    char* tipo_angulo;

    // TIPO DE LADO
    if(l1!=l2 && l1!=l3 && l2!=l3)
        tipo_lado = "escaleno";

    else if(l1==l2 || l1==l3 || l2==l3)
        tipo_lado = "isosceles";

    else if(l1==l2 && l1==l3 && l2==l3)
        tipo_lado = "equilatero";
    
    else 
        tipo_lado = "";
    
    // TIPO DE ANGULO
    if(a1 == 90 || a2 == 90 || a3 == 90)
        tipo_angulo = "retangulo";
    
    else if(a1 < 90 && a2 < 90 && a3 < 90)
        tipo_angulo = "acutangulo";
    
    else if(a1 > 90 || a2 > 90 || a3 > 90)
        tipo_angulo = "obtusangulo";
    
    else
        tipo_angulo = "";
    
    strcat(nomenclatura, "triangulo ");
    strcat(nomenclatura, tipo_angulo);
    strcat(nomenclatura, " ");
    strcat(nomenclatura, tipo_lado);

}