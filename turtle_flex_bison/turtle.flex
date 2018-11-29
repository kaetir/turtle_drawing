%option noyywrap

%{
#include <string>
#include <iostream>
#include "projet.bison.hpp" 
using namespace std;
%}

%%
#.*$							{ cout << "Comment " << yytext  << endl;		}
[0-9]+(\.[0-9]*)?([Ee][0-9]+)?  { yylval.valeur = atof(yytext); return NUMBER;  }
pour|Réitérer                   { return REPEAT;                                }
taille							{ return TAILLE;								}
couleur		                    { return COULEUR;                  				}
aller		                    {                                 				}
tourner		                    {                                 				}
avancer		                    {                                 				}
[A-Za-z_][0-9A-Za-z_]*          { strcpy(yylval.nom,yytext); return IDENTIFIER; }
:								{ return ENSEMBLE ;								}
\r\n 							{ return '\n';		   							}
\n                              { return '\n';         							}
\r                              { return '\n';         							}
[ \t]                           {                                               }
.                               { cout << yytext[0]  << endl; return yytext[0]; }	
%%
