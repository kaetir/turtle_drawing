%{
	#include <iostream>
	#include <map>
	#include <string>
	using namespace std;
	extern FILE *yyin;
	extern int yylex ();
	int yyerror(const char *s) { printf("%s\n", s); return 0;}

	map<string, double> variables;

%}

%union
{
	double valeur;
	char nom[50];
}

%token <valeur> NUMBER
%token <nom> IDENTIFIER
%type <valeur> expression
%token REPEAT
%token ENSEMBLE
%token TAILLE

%left '+' '-'     /* associativité à gauche */
%left '*' '/'     /* associativité à gauche */

%%
ligne : ligne instruction '\n' 
			|    /* Epsilon */
			;
instruction : expression                           	{ printf("Résultat : %g\n",$1); }
			| TAILLE '(' expression ')'				{ cout << "taille " /*<< $2 /*<< ' ' << $4*/ << endl;}
			| REPEAT '(' expression ')' expression  { for (int i =0; i<$3; i++) cout << $5 << endl;}
			| IDENTIFIER '=' expression             { variables[$1] = $3; cout << "Affectation de " << $3 << " à " << $1 << endl;}
			| ENSEMBLE expression                   { cout << "itération de " << $2 << endl; }
			|   /* Ligne vide*/
			;
expression: expression '+' expression     { $$ = $1 + $3; cout << $1 << '+' << $3 << '=' << $$ << endl; }
					| expression '-' expression     { $$ = $1 - $3; }
					| expression '*' expression     { $$ = $1 * $3; cout << $1 << '*' << $3 << '=' << $$ << endl;}
					| expression '/' expression     { $$ = $1 * $3; }
					| '(' expression ')'            { $$ = $2; }
					| NUMBER                        { $$ = $1; }
					| IDENTIFIER                    { $$ = variables[$1];}
					;
%%
int main(int argc, char **argv) {
	if ( argc > 1 )
		yyin = fopen( argv[1], "r" );
	else
		yyin = stdin;
	yyparse();
} 