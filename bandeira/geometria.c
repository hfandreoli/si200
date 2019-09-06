#include "geometria.h"
#include <stdlib.h>
#include <stdio.h>

#define quad(x) ((x)*(x))

	Circulo * newCirculo (double raio, int xc, int yc){
		Circulo * c = (Circulo*)malloc(sizeof(Circulo));
		c->xc = xc;
		c->yc = yc;
		c->raio = raio;
	
		return c;
	}

	int dentroCirculo(Circulo * c, int x, int y){
		return quad(x - c->xc) + quad(y - c->yc) <= quad(c->raio);
	}
