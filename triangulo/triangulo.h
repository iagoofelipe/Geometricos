#define PI 3.1415

// coletando os valores dos lados do triangulo
void getLados(double* array_lados);

// calcula grau do angulo Â
double getAngulo(double a, double b, double c);

void getAngulos(double* array_lados, double* array_angulos);

// verificando relacao de coexistencia do triangulo
int validarTriangulo(double* array_lados);

void getNomenclatura(double* array_lados, double* array_angulos, char* nomenclatura);