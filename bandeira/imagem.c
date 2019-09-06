#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

	RGB ** allocaMatriz(int LI, int CO){
		RGB **color;
		color = (RGB**)malloc(sizeof(RGB*)*LI);
		for(int i=0; i<LI; i++){
			color[i]=(RGB*)malloc(sizeof(RGB)*CO);
		}
		return color;
	}

	Imagem * newImagem(int LI, int CO){
		Imagem * x = (Imagem*)malloc(sizeof(Imagem));
		x->LI = LI;
		x->CO = CO;
		x->color= allocaMatriz(LI,CO);
		RGB branca = {255,255,255};
		for(int i=0; i<LI; i++){
			for(int col=0; col<CO;col++){
				x->color[i][col] = branca;
			}
		}
		return x;
	}

		void setColor(Imagem * img , int li, int col, RGB cor){
			if(li>=0 && li<img->LI && col>=0 && col<img->CO){
				img->color[li][col] = cor;
			}
		}

		void salvaImagem(Imagem * x, char * fname){
			FILE *f;
			f = fopen(fname , "w");
			int li, col;
			fprintf(f,"P3\n");
			fprintf(f,"%d %d\n",x->LI , x->CO);
			for(li=x->LI-1;li>=0;li--){
				for(col=0; col< x->CO; col++){
					if(col>0){
						fprintf(f," ");
					}
					fprintf(f, "%d %d %d", x->color[li][col].red, x->color[li][col].green, x->color[li][col].blue);
				}
			fprintf(f,"\n");
			}
			fclose(f);
		}
			
