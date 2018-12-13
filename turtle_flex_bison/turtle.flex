%option noyywrap

%{
#include <iostream>

typedef struct adr {
	int ic_goto; 
	int ic_false;
} t_adresse; 

#include "projet.bison.hpp" 
using namespace std;


%}

%option nounput

%%
#.*$								{ /*cout << "Comment " << yytext  << endl;*/	} // regex 							{ instruction avec return de token pour bison   }
-?[0-9]+(\.[0-9]*)?([Ee][0-9]+)?  	{ yylval.valeur = atof(yytext); return NUMBER;  }
si|Si|SI 							{ return SI; 									}
Alors|alors|ALORS 					{ return ALORS; 								}
Sinon|sinon|SINON					{ return SINON; 								}
FinSi|finsi|FINSI					{ return FINSI; 								}
pour|for     		             	{ return POUR;	                                }
faire|do     		             	{ return FAIRE;	                                }
finpour|endfor                  	{ return FINPOUR;                               }
chemin|path							{ return PATH;									}
finchemin|endpath					{ return ENDPATH;								}
taille								{ return TAILLE;								}
taillec								{ return LARGEUR;								}
label 		                    	{ return LABEL;                  				}
goto 		                    	{ return GOTO;                  				}
couleur		                    	{ return COULEUR;                  				}
poser								{ return PENDOWN;								}
lever								{ return PENUP;									}
position	                    	{ return GOTOXY;                   				}
tourner		                    	{ return ROTATE ;                 				}
angle		                    	{ return SETANGLE ;                				}
avancer		                    	{ return FORWARD;                  				}
[A-Za-z_][0-9A-Za-z_]*          	{ strcpy(yylval.nom,yytext); return IDENTIFIER; }
\r\n 								{ return '\n';		   							}
\n                              	{ return '\n';         							}
\r                              	{ return '\n';         							}
[ \t]                           	{                                               }
.                               	{ cout << yytext[0]  << endl; return yytext[0]; }	
\".*\" 		                    	{ strcpy(yylval.chaine,yytext); return STRING;  }
%%
