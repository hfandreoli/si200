#ifndef GEOMETRIA_H
#define GEMETRIA_H
#define PI 3.14159265359

	typedef struct Circulo{
	double raio;
	int xc, yc;
	}Circulo;

	Circulo * newCirculo(double raio, int xc, int yc);
	int dentroCirculo(Circulo *c, int x , int y);

#endif
