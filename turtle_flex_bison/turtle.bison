%{
	#include <iostream>
	#include <vector>
	#include <fstream>
	#include <map>
	#include <string>
	#include <cmath>

	using namespace std;

	// FLEX
	extern FILE *yyin;
	extern int yylex ();
	int yyerror(const char *s) { printf("%s\n", s); return 0;}

	// map des variables
	map<string, double> variables;
	
	// fichier dans lequel on affiche
	fstream file("bite.html", ios_base::out);
	
	// Stockage des instructions
	vector<pair<int,double>> instructions;

	// Stockage des couleurs
	map<int, string> zoli ;

	// Stockage des labels pour les goto
	map<string, int> labels ;
	string labelTosearch;

	size_t ic = 0;   // compteur instruction 
	inline void ins(int c, double d) { instructions.push_back(make_pair(c, d)); ic++;};

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


	// structure pour stocker les adresses pour les sauts condistionnels et autres...
	typedef struct adr {
		int ic_goto; 
		int ic_false;
	} t_adresse; 

%}

%union
{
	double valeur;
	char nom[100];
	t_adresse adresse;
	char chaine[100];
}

// decalation de terminaux
%type <valeur> expression


// Test
%token <adresse> SI
%token ALORS
%token SINON
%token FINSI

// JUMP
%token JMP 
%token JNZ
%token OUT
%token LABEL
%token GOTO

// Token utilisables par l'user
%token <chaine> STRING
%token <valeur> NUMBER
%token <nom> IDENTIFIER

// repete une instruction x fois
%token <adresse> POUR 
%token FINPOUR

// COMMANDES 
%token TAILLE
%token COULEUR
%token FORWARD
%token ROTATE
%token PENDOWN
%token PENUP
%token GOTOXY


%left '+' '-'     /* associativité à gauche */
%left '*' '/'     /* associativité à gauche */

%%

bloc : bloc instruction '\n' 
	 |    /* Epsilon */
	 ;

instruction : expression                { ins(OUT,0); 	                                                              }
| PENDOWN 								{ ins(PENDOWN, 0);                                                            }
| PENUP 								{ ins(PENUP  , 0);                                                            }
| LABEL STRING							{ labels[$2] = ic; ins(LABEL  , 0);			                                  }
| GOTO STRING							{ labelTosearch=$2; ins(GOTO  , 0);			                                  }
| GOTOXY expression expression			{ ins(GOTOXY  , 0);                                                           }
| TAILLE expression expression 			{ ins(TAILLE , 0); /*cout << "taille " << $2 << ' ' << $3 << endl;    */      }
| FORWARD expression 					{ ins(FORWARD, 0); /*cout << "avance " << $2 << endl;     */                  }
| ROTATE expression  					{ ins(ROTATE , 0); /*cout << "tourne " << $2 << endl;     */                  }
| COULEUR STRING  						{ ins(COULEUR, 0); /*cout << "Couleur " << $2 << endl; */zoli[ic-1] = $2;     }
| IDENTIFIER '=' expression             { variables[$1] = $3; cout << "Affectation de " << $3 << " à " << $1 << endl; }
| SI expression '\n' { $1.ic_goto = ic;  
					   ins (JNZ,0);
					   }
  ALORS '\n' bloc    { $1.ic_false = ic;
					   ins (JMP,0);
					   instructions[$1.ic_goto].second = ic;  
					   }
  SINON '\n' bloc    { instructions[$1.ic_false].second = ic; }
  FINSI              {   }
| POUR '(' expression ')' bloc  { ins(POUR  , 0); for (int i =0; i<$3; i++) cout << "pour" << endl;   }
  FINPOUR 						{   }
| /* Ligne vide*/
;

expression:   expression '+' expression     	{ ins('+', 0);}
| expression '-' expression     { ins('-', 0);}
| expression '*' expression     { ins('*', 0);}
| expression '/' expression     { ins('/', 0);}
| '(' expression ')'            { }
| NUMBER                        { ins(NUMBER, $1);}
| IDENTIFIER                    { ins(IDENTIFIER, variables[$1]);}
;



%%




// Pour imprimer le code généré de manière plus lisible 
string nom(int instruction){
switch (instruction){
	case '+'     	: return "ADD";
	case '*'     	: return "MUL";
	case NUMBER  	: return "NUM";
	case LABEL  	: return "LBL";
	case GOTO   	: return "GOT";
	case GOTOXY  	: return "GXY";
	case TAILLE  	: return "TAL";
	case IDENTIFIER : return "IDE";
	case COULEUR  	: return "CLR";
	case FORWARD  	: return "FWD";
	case PENDOWN	: return "PDN";
	case PENUP	  	: return "PUP";
	case ROTATE		: return "ROT";
	case POUR     	: return "FOR";	
	case OUT     	: return "OUT";	
	case JNZ     	: return "JNZ";   // Jump if not zero
	case JMP     	: return "JMP";   // Unconditional Jump
	default  		: return to_string (instruction);
}
}

void print_program(){
	cout << "==== CODE GENERE ====" << endl;
	int i = 0;
	for (auto ins : instructions )
		cout << i++ << '\t' << nom(ins.first) << "\t" << ins.second << endl;
	cout << "=====================" << endl;  
}

double depiler(vector<double> &pile) {
	double t = pile[pile.size()-1];
  //cout << "Dépiler " << t << endl; 
	pile.pop_back();
	return t;
}


void run_program(turtle my_turtle){
	vector<double> pile; 
	double x,y;
	string c;

	cout << "===== EXECUTION =====" << endl;
	ic = 0;
	while ( ic < instructions.size() ){
		auto ins = instructions[ic];
		cout << ic << '\t' << nom(ins.first) << "\t" << ins.second << endl;

		switch(ins.first){

			case '+':
			x = depiler(pile);
			y = depiler(pile);
			pile.push_back(y+x);
			ic++;
			break;

			case '*':
			x = depiler(pile);
			y = depiler(pile);
			pile.push_back(y*x);
			ic++;
			break;

			case FORWARD:
			x = depiler(pile);
			if(my_turtle.penDown){
				::file << "<line x1='"<< my_turtle.x << "' y1='"<< my_turtle.y << "' x2='" << my_turtle.x+cos(my_turtle.theta)*x <<"' y2='"<< my_turtle.y+sin(my_turtle.theta)*x <<"' fill='#00FF00' stroke=" << my_turtle.couleur << " stroke-width=" << my_turtle.largeur << " stroke-miterlimit='10' stroke-dasharray='1000' stroke-dashoffset='0' > </line>" ;
				// file << "<line x1='"<< x << "' y1='"<< y << "' x2='" << x+cos(theta)*$2 <<"' y2='"<< y+sin(theta)*$2 <<"'  fill='#FFFFFF' stroke='#000000' stroke-width='4' stroke-miterlimit='10' stroke-dasharray='1000' stroke-dashoffset='0'><animate attributeName='x' from='0' to='200' dur='5s' /><animate attributeType='CSS' attributeName='stroke-dashoffset' from='1000' to='0' dur='5s' <!--begin='" << 2*trait <<"s;'--> /><!--animate id='op' attributeType='CSS' attributeName='opacity'from='1' to='0' dur='1s' begin='0s' /--> </line>" ;
			}
			my_turtle.avancer(x);

			ic++;
			break;

			case NUMBER :
			pile.push_back(ins.second);
			ic++;
			break;

			case LABEL :
			std::cout << "bite" << std::endl;
			ic++;
			break;

			case GOTO :
			for(auto it : labels ){
				std::cout << it.first << " " << it.second << '\n';
			}
			if(labels[labelTosearch])
				ic  = labels[labelTosearch]  ;
			ic++;
			break;

			case PENDOWN :
			my_turtle.baisser();
			ic++;
			break;

			case PENUP :
			my_turtle.lever();
			ic++;
			break;

			case GOTOXY :
			x = depiler(pile);
			y = depiler(pile);

			my_turtle.x = x;
			my_turtle.y = y; 
			ic++;
			break;

			case TAILLE :
			x = depiler(pile);
			y = depiler(pile);

			my_turtle.taile_x= x;
			my_turtle.taile_y= y; 
			ic++;
			break;

			case COULEUR :
			my_turtle.couleur= zoli[ic]; 
			ic++;
			break;


			case ROTATE :
			x = depiler(pile);
			my_turtle.tourner(x);
			ic++;
			break;
			
			case IDENTIFIER :
			pile.push_back(ins.second);
			ic++;
			break;

			case POUR : // TO DO

			ic++;
			break;			

			case JMP :
			ic = ins.second;
			break;

			case JNZ :
			x = depiler(pile);
			ic = ( x ? ic + 1 : ins.second);
			break;

			case OUT :
				cout << "Résultat : " << depiler(pile) << endl;
				ic++;
				break;
			
			default :
			std::cout << "oups :" << ic << "\t" << nom(ins.first) << std::endl;
		}
	}
	cout << "=====================" << endl;
	return;  
}



int main(int argc, char **argv) {

	
	file 	<< "<html><head><title>des seins</title><meta charset=\"utf-8\"></head>"
	<< "<body> <svg width='200mm' height='200mm' viewBox='0 0 1000 1000'id='svg1'>" ;

	turtle my_turtle;
	zoli[0] = "\"#000000\"";

	if ( argc > 1 )
		yyin = fopen( argv[1], "r" );
	else
		yyin = stdin;
	yyparse();

	print_program();

	run_program(my_turtle);

	file << "</svg></body></html>" ;

} 