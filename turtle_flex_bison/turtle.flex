%option noyywrap

%{
#include <string>
#include "projet.bison.hpp" 
using namespace std;
%}

%%
[0-9]+(\.[0-9]*)?([Ee][0-9]+)?  { yylval.valeur = atof(yytext); return NUMBER;  }
#.*$							{ return COMMENT;								}
pour|Réitérer                   { return REPEAT;                                }
taille							{ 			}
couleur		                    {                                 				}
aller		                    {                                 				}
tourner		                    {                                 				}
avancer		                    {                                 				}
[A-Za-z_][0-9A-Za-z_]*          { strcpy(yylval.nom,yytext); return IDENTIFIER; }
:								{ return ENSEMBLE ;								}
\n                              { return '\n';                                  }
\r                              { return '\n';                                  }
[\t]                            {                                               }
.                               { return yytext[0];                             }	
%%
