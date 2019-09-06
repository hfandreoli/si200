#ifndef IMAGEM_H
#define IMAGEM_H
#include "geometria.h"

	
	typedef struct RGB{
		int red;
		int green;
		int blue;
	}RGB;

	

	typedef struct Imagem{
		int LI,CO;
		RGB **color;
	}Imagem;


	Imagem * newImagem (int LI, int CO);
	void setColor (Imagem * img, int li, int col, RGB cor);
	void salvaImagem (Imagem * x, char * fname);
	void desenhoCirculo (Imagem * img, Circulo * c, RGB cor);
	void Invere (Imagem * img);
	void espelhaHorizontal ( Imagem * img);
	Imagem * clona (Imagem * img);

#endif
