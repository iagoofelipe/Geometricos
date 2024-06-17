#include <stdio.h>
#include <stdlib.h>

#include "triangulo.h"

int main() {

    // coletar os tres lados
    double array_lados[3];
    double array_angulos[3];
    char nomenclatura[50] = "";
    int triangulo_valido;

    printf("\nColetando lados do triangulo...\n");
    getLados(array_lados);

    // verificar se forma um triangulo valido
    printf("Validando condicoes de existencia...\n");
    triangulo_valido = validarTriangulo(array_lados);

    if(triangulo_valido) {
        printf("O triangulo atende as condicoes de existencia, prosseguindo\n");
    } else {
        printf("O triangulo nao atende as condicoes de existencia!\n");
        return 0;
    }

    printf("\nDados do triangulo\n");
    
    // calcular os tres angulos
    getAngulos(array_lados, array_angulos);
    printf("angulos:\t\t (%.1f, %.1f, %.1f)\n", array_angulos[0], array_angulos[1], array_angulos[2]);

    // verificar o tipo de triangulo formado
    getNomenclatura(array_lados, array_angulos, nomenclatura);
    printf("Tipo de triangulo:\t %s\n\n", nomenclatura);

    return 0;
}