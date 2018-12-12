%option noyywrap

%{
#include <string>
#include <iostream>


// structure pour stocker les adresses pour les sauts condistionnels et autres...
typedef struct adr {
    int ic_goto; 
    int ic_false;
} t_adresse;

#include "projet.bison.hpp" 
using namespace std;


%}

%%
#.*$								{ /*cout << "Comment " << yytext  << endl;*/	} // regex 							{ instruction avec return de token pour bison   }
-?[0-9]+(\.[0-9]*)?([Ee][0-9]+)?  	{ yylval.valeur = atof(yytext); return NUMBER;  }
si|Si|SI 							{ return SI; 									}
Alors|alors|ALORS 					{ return ALORS; 								}
Sinon|sinon|SINON					{ return SINON; 								}
FinSi|finsi|FINSI					{ return FINSI; 								}
pour|for     		             	{ return POUR;	                                }
finpour|endfor                  	{ return FINPOUR;                               }
taille								{ return TAILLE;								}
label 		                    	{ return LABEL;                  				}
goto 		                    	{ return GOTO;                  				}
couleur		                    	{ return COULEUR;                  				}
poser								{ return PENDOWN;								}
lever								{ return PENUP;									}
position	                    	{ return GOTOXY;                   				}
tourner		                    	{ return ROTATE ;                 				}
avancer		                    	{ return FORWARD;                  				}
[A-Za-z_][0-9A-Za-z_]*          	{ strcpy(yylval.nom,yytext); return IDENTIFIER; }
\r\n 								{ return '\n';		   							}
\n                              	{ return '\n';         							}
\r                              	{ return '\n';         							}
[ \t]                           	{                                               }
.                               	{ cout << yytext[0]  << endl; return yytext[0]; }	
\".*\" 		                    	{ strcpy(yylval.chaine,yytext); return STRING;  }
%%
