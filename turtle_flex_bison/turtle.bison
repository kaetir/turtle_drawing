%{


#include "turtle_class.h"


// FLEX
extern FILE *yyin;
extern int yylex ();
int yyerror(const char *s) { printf("%s\n", s); return 0;}


// map des variables
// map<string, double> variables;
vector<pair<string,double>> variables;

// fichier dans lequel on affiche

// fstream file("bite.html", ios_base::out);
fstream file("./turtle.svg", ios_base::out);

// Stockage des instructions
vector<pair<int,double>> instructions;

// Stockage des couleurs
map<int, vector<string>> zoli ;
map<int, int> colorcount;

// Stockage des labels pour les goto
map<string, int> labels ;
string labelTosearch;

// Stockage des FOR on stock l'ic et le nombre de rep
map<int, int> fors ;


size_t ic = 0;   // compteur instruction 

inline void ins(int c, double d) { instructions.push_back(make_pair(c, d)); ic++;};
inline void insvar(string c, double d) { variables.push_back(make_pair(c, d)); ic++;};

	



template< typename T >
std::string int_to_hex( T i )
{
	std::stringstream stream;
	  stream << std::setfill ('0') << std::setw(2) 
	<< std::hex << i;
	return stream.str();
}


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
%token VAR

// repete une instruction x fois
%token <adresse> POUR 
%token FAIRE
%token FINPOUR

// forme de dessin
%token PATH
%token ENDPATH

// COMMANDES 
%token TAILLE
%token LARGEUR
%token COULEUR
%token COULEURRGB
%token FORWARD
%token ROTATE
%token SETANGLE
%token PENDOWN
%token PENUP
%token GOTOXY


%left '+' '-'     /* associativité à gauche */
%left '*' '/'     /* associativité à gauche */

%%

bloc : bloc instruction '\n' 
	 |    /* Epsilon */
	 ;

instruction : expression                	{ ins(OUT,0); 	                                                            }
| PENDOWN 									{ ins(PENDOWN, 0);                                                          }
| PENUP 									{ ins(PENUP  , 0);                                                          }
| LABEL STRING								{ labels[$2] = ic; ins(LABEL  , 0);			                                }
| GOTO STRING								{ labelTosearch=$2; ins(GOTO  , 0);			                                }
| GOTOXY expression expression				{ ins(GOTOXY   , 0);                                                        }
| PATH						 				{ ins(PATH 	   , 0);                                                        }
| ENDPATH					 				{ ins(ENDPATH  , 0);                                                        }
| TAILLE expression expression 				{ ins(TAILLE , 0); /*cout << "taille " << $2 << ' ' << $3 << endl;    */    }
| LARGEUR expression 						{ ins(LARGEUR, 0); /*cout << "avance " << $2 << endl;     */                }
| FORWARD expression 						{ ins(FORWARD, 0); /*cout << "avance " << $2 << endl;     */                }
| ROTATE expression  						{ ins(ROTATE , 0); /*cout << "tourne " << $2 << endl;     */                }
| SETANGLE expression  						{ ins(SETANGLE , 0); /*cout << "tourne " << $2 << endl;     */                }
| COULEUR STRING  							{ ins(COULEUR, 0); zoli[ic-1].push_back($2);  								}
| COULEUR expression expression expression  { ins(COULEURRGB, 0);														}
| IDENTIFIER '=' expression             	{ variables[$1] = $3; 														}

| SI expression '\n' { $1.ic_goto = ic;  
					   ins (JNZ,0);
					   }
  ALORS '\n' bloc    { $1.ic_false = ic;
					   ins (JMP,0);
					   instructions[$1.ic_goto].second = ic;  
					   }
  SINON '\n' bloc    { instructions[$1.ic_false].second = ic; }
  FINSI              {   }

| POUR '(' expression ')'   	{ fors[ic]=$3; ins(POUR  , 0); }
  FAIRE bloc					{   }
  FINPOUR 						{ ins(FINPOUR  , 0);  }
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
	case '-'     	: return "SUB";
	case '*'     	: return "MUL";
	case '/'     	: return "DIV";
	case NUMBER  	: return "NUM";
	case LABEL  	: return "LBL";
	case GOTO   	: return "GOT";
	case GOTOXY  	: return "GXY";
	case PATH	  	: return "PTH";
	case ENDPATH  	: return "EPH";
	case TAILLE  	: return "TAL";
	case LARGEUR  	: return "LRG";
	case IDENTIFIER : return "IDE";
	case VAR 		: return "VAR";
	case COULEUR  	: return "CLR";
	case COULEURRGB : return "RGB";
	case FORWARD  	: return "FWD";
	case PENDOWN	: return "PDN";
	case PENUP	  	: return "PUP";
	case ROTATE		: return "ROT";
	case SETANGLE	: return "SAG";
	case POUR     	: return "FOR";	
	case FINPOUR  	: return "FFR";	
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
	double r,g,b;
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
			
			case '-':
			x = depiler(pile);
			y = depiler(pile);
			pile.push_back(y-x);
			ic++;
			break;

			case '*':
			x = depiler(pile);
			y = depiler(pile);
			pile.push_back(y*x);
			ic++;
			break;

			case '/':
			x = depiler(pile);
			y = depiler(pile);
			pile.push_back(y/x);
			ic++;
			break;

			case FORWARD:
			x = depiler(pile);
			if(my_turtle.penDown){
				if(!my_turtle.path){
					::file << "<line x1='"<< my_turtle.x << "' y1='"<< my_turtle.y << "' x2='" << my_turtle.x+cos(my_turtle.theta)*x <<"' y2='"<< my_turtle.y+sin(my_turtle.theta)*x <<"' fill='#00FF00' stroke=" << my_turtle.couleur << " stroke-width=\"" << my_turtle.largeur << "\" stroke-miterlimit='10' stroke-dasharray='1000' stroke-dashoffset='0' > </line>  \n" ;
					// file << "<line x1='"<< x << "' y1='"<< y << "' x2='" << x+cos(theta)*$2 <<"' y2='"<< y+sin(theta)*$2 <<"'  fill='#FFFFFF' stroke='#000000' stroke-width='4' stroke-miterlimit='10' stroke-dasharray='1000' stroke-dashoffset='0'><animate attributeName='x' from='0' to='200' dur='5s' /><animate attributeType='CSS' attributeName='stroke-dashoffset' from='1000' to='0' dur='5s' <!--begin='" << 2*trait <<"s;'--> /><!--animate id='op' attributeType='CSS' attributeName='opacity'from='1' to='0' dur='1s' begin='0s' /--> </line>" ;
				}
				else{
					::file << my_turtle.x+cos(my_turtle.theta)*x << " " << my_turtle.y+sin(my_turtle.theta)*x << " " ;
				}

			}
			my_turtle.avancer(x);

			ic++;
			break;

			case NUMBER :
			pile.push_back(ins.second);
			ic++;
			break;
			
			case LARGEUR :
			x = depiler(pile);
			my_turtle.largeur = x;
			ic++;
			break;

			case LABEL :
			ic++;
			break;

			case GOTO :
			
			if(labels[labelTosearch]){
				std::cout << labelTosearch  << " " << labels[labelTosearch]  << '\n';
				ic  = labels[labelTosearch]  ;
			}
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

			case PATH	  :
			my_turtle.path = true ;
			::file << "<path d=\"M" << my_turtle.x << " " << my_turtle.y << " "   ;							
			break;

			case ENDPATH  :
			my_turtle.path = false ;
			::file << "stroke=\"" << my_turtle.couleur <<"\" stroke-width=\"" << my_turtle.largeur << "\" fill=\"" << my_turtle.couleur << "\" />"    ;		
			break;


			case TAILLE :
			x = depiler(pile);
			y = depiler(pile);

			my_turtle.taile_x= x;
			my_turtle.taile_y= y; 
			ic++;
			break;

			case COULEUR :
			
			my_turtle.couleur= zoli[ic][colorcount[ic]++]; 
			ic++;
			break;


			case COULEURRGB :
			r = depiler(pile);
			g = depiler(pile);
			b = depiler(pile);
			std::cout << r << " " << g << " " << b  << std::endl;
			zoli[ic].push_back("\"#"+int_to_hex((int)r%255)+
									 int_to_hex((int)g%255)+
				   				     int_to_hex((int)b%255)+ "\"");
			my_turtle.couleur= zoli[ic][colorcount[ic]++]; 
			ic++;
			break;





			case ROTATE :
			x = depiler(pile);
			my_turtle.tourner(x);
			ic++;
			break;

			case SETANGLE :
			x = depiler(pile);
			my_turtle.theta = x ;
			ic++;
			break;
			
			case IDENTIFIER :
			pile.push_back(ins.second);
			ic++;
			break;

			case VAR :

			// x = depiler(pile);
			// variables[ins.first] = x;
			// pile.push_back(x);

			ic++;
			break;

			case POUR : // TO DO
			ic++;
			break;

			case FINPOUR : {
				auto it = fors.rbegin();
				if(it->second >= 0){
					ic = it->first;
					it->second--;
				}
				else{
					ic++;
				}
				break;			
			}

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

	
	// on ajoute l'entête du fichier
	file << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n<svg width='200mm' height='200mm' viewBox='0 0 1000 1000' id='svg1'>\n" ;
	
	// on crée la turtle
	turtle my_turtle;
	
	// initialisation de la couleur sur Noir
	zoli[0].push_back("\"#000000\"");
	colorcount[0] = 0;


	if ( argc > 1 )
		yyin = fopen( argv[1], "r" );
	else
		yyin = stdin;

	yyparse();

	print_program();

	run_program(my_turtle);

	file << "</svg>\n";

} 