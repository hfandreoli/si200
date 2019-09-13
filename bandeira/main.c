#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "imagem.h"
#define ESCALA 50

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

int losangoPrimeiraMetadeCima (int x) {
	float y = x * 5.3 / 8.3 + 5.9145*ESCALA;
	return (int)roundf(y);
}

int losangoPrimeiraMetadeBaixo (int x) {
	float y = x * -5.3 / 8.3 + 8.0855*ESCALA;
	return (int)roundf(y);
}

int losangoSegundaMetadeCima (int x) {
	float y = x * -5.3 / 8.3 + 18.6855*ESCALA;
	return (int)roundf(y);
}

int losangoSegundaMetadeBaixo (int x) {
	float y = x * 5.3 / 8.3 + -4.6855*ESCALA;
	return (int)roundf(y);
}

void pintalosango(Imagem* img) {
	int lin, col;
	int limiteEsq = (int)roundf(1.7*ESCALA);
	int limiteDir = 20 * ESCALA - limiteEsq;
	
	for (col=0; col < (img->CO-1)/2; col++) {
		for (lin=0; lin < img->LI; lin++) {
			if (col > (limiteEsq)) {
				if (lin > losangoPrimeiraMetadeBaixo(col) && lin < losangoPrimeiraMetadeCima(col)) {
					setColor(img, lin, col, amarelo);
				}	
			}
		}
	}

	for (col=(img->CO-1)/2; col < img->CO; col++) {
		for (lin=0; lin < img->LI; lin++) {
			if (col < (limiteDir)) {
				if (lin > losangoSegundaMetadeBaixo(col) && lin < losangoSegundaMetadeCima(col)) {
					setColor(img, lin, col, amarelo);
				}	
			}
		}
	}
}

void pintaCirculo (Imagem* img) {
	Circulo* circulo = newCirculo(3.5 * ESCALA, (img->LI-1)/2, (img->CO-1)/2);

	for (int col=0; col < img->CO; col++) {
		for (int lin=0; lin < img->LI; lin++) {
			if ( dentroCirculo(circulo, lin, col) )	{
				setColor(img, lin, col, azul);	
			}		
		}
	}
}

void pintaFaixa (Imagem* img) {
	Circulo* circuloAzul = newCirculo(3.5 * ESCALA, (img->LI-1)/2, (img->CO-1)/2);
	Circulo* circuloExter = newCirculo(8.5 * ESCALA, 0, (img->CO-1)/2 - (2 * ESCALA));
	Circulo* circuloInter = newCirculo(8 * ESCALA, 0, (img->CO-1)/2 - (2 * ESCALA));
	
	for (int col=0; col < img->CO; col++) {
		for (int lin=0; lin < img->LI; lin++) {
			if ( dentroCirculo(circuloAzul, lin, col) && 
			     dentroCirculo(circuloExter, lin, col) &&
			     !dentroCirculo(circuloInter, lin, col) ) {
				setColor(img, lin, col, branco);	
			}		
		}
	}
}

int main (){
	Imagem * img;
	img = newImagem(14 * ESCALA,20 * ESCALA);
	pintaVerde(img);
	pintalosango(img);
	pintaCirculo(img);
	pintaFaixa(img);
	salvaImagem(img, "bandeira.ppm");
	return 0;
}
	
			
		
