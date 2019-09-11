#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "imagem.h"
#define ESCALA 100

RGB verde = {0,156,59};
RGB amarelo = {255,223,0};
RGB azul = {0,39,118};
RGB branco = {255,255,255};

void pintaVerde (Imagem* img) {
	for (int i=0; i < img->LI; i++) {
		for (int j=0; j < img->CO; j++) {
			setColor(img,i,j,verde);
		}	
	}
}

int lozangoPrimeiraMetadeCima (int x) {
	float y = (float)x * 5.3 / 8.3 + 5.9145 * (float)ESCALA;
	return (int)roundf(y);
}

int lozangoPrimeiraMetadeBaixo (int x) {
	float y = (float)x * -5.3 / 8.3 + 8.0855 * (float)ESCALA;
	return (int)roundf(y);
}

int lozangoSegundaMetadeCima (int x) {
	float y = (float)x * -5.3 / 8.3 + 18.6855 * (float)ESCALA;
	return (int)roundf(y);
}

int lozangoSegundaMetadeBaixo (int x) {
	float y = (float)x * 5.3 / 8.3 + -4.6855 * (float)ESCALA;
	return (int)roundf(y);
}

void pintaLozango(Imagem* img) {
	int lin, col, limiteSup, limiteInf;
	int limiteEsq = (int)roundf(1.7*(float)ESCALA);
	int limiteDir = 20 * ESCALA - limiteEsq;
	
	for (col=0; col < img->CO/2; col++) {
		for (lin=0; lin < img->LI; lin++) {
			if (col > (limiteEsq)) {
				limiteInf = lozangoPrimeiraMetadeBaixo(col);
				limiteSup = lozangoPrimeiraMetadeCima(col);
				if (lin > limiteInf && lin < limiteSup) {
					setColor(img, lin, col, amarelo);
				}	
			}
		}
	}

	for (col=img->CO/2; col < img->CO; col++) {
		for (lin=0; lin < img->LI; lin++) {
			if (col < (limiteDir)) {
				if (lin > lozangoSegundaMetadeBaixo(col) && lin < lozangoSegundaMetadeCima(col)) {
					setColor(img, lin, col, amarelo);
				}	
			}
		}
	}
}

int main (){
	Imagem * img;
	img = newImagem(14 * ESCALA,20 * ESCALA);
	pintaVerde(img);
	pintaLozango(img);
	salvaImagem(img, "bandeira.ppm");
	return 0;
}
	
			
		
