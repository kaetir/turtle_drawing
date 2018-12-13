#ifndef TURTLE_H
#define TURTLE_H 

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <cmath>


using namespace std;

class  turtle 	{

		public:
		// taille de la map de dessin
		int taile_x= 1000, taile_y=1000;
	


		// position et orientation de la turtle
		float x = 10;
		float y = 10;
		float theta = 0;
		// nombre du trait
		int  trait = 1;

		// si on dessine des lignes ou des formes
		bool path = false;

		// savoir si on déssine ou pas
		// stylo posay
		bool penDown = true;

		// largeur
		size_t largeur = 4;
		
		string couleur= "\"#00FF00\"";




		turtle(){}
		~turtle(){}
	
		// permet de dire si on trace une ligne (comme avec un stylo sur une feuille)
		void baisser(){penDown = true;}
		void lever(){penDown = false;}
	
		// avance d'une distance entière
			void avancer(double x){
				this->x += cos(theta) * x; 
				this->y += sin(theta) * x; 
				trait++;
			}
		// tourne d'un angle en degré
			void tourner(double t){
				theta += (t/180*M_PI);
			}
	
		// se déplace instantanément a une position donnée sans tracer
			void gotoXY(int , int);
	
			void setSize(unsigned int );
	};















#endif /*TURTLE_H*/