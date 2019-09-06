#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#define ESCALA 10


	int main (){
	Imagem * img;
	img = newImagem(200,140);
	salvaImagem(img, "bandeira.ppm");
	return 0;
	}
	
			
		
