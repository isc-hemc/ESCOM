%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
extern int yylex(void);
void yyerror(char *s);
int contarDigitos();
char *potenciarCadena(char *cadena, int num, int digitos);
char *concatenarCadenas(char *texto1, char *texto2);
double potency(double base, double exponent);
char *convertToString(int number);
char *falsoOVerdadero(unsigned int numero);
%}
             
/* Declaraciones de BISON */
%union{
	int   entero;
	float flotante;
	char* cadena;
	unsigned int boolean;
}

%token <entero> ENTERO
%token <flotante> DECIMAL
%token <cadena> CAD
%token POW 
%token IF

%type <entero> exp
%type <flotante> expFloat
%type <cadena> texto
%type <boolean> condition

          
%left '+'  '-' 
%left '^'
%left '*' '/'
%left '('  %left ')'

             
/* Gramática */
%%
             
input:   /* cadena vacía */
        | input line 
;

line:   '\n'
		| exp '\n'  { printf ("\tresultado: %d\n\n", $1); }
		| expFloat '\n' { printf("\tflotante: %f\n", $1);}
        | texto '\n' { printf ("\tresultado: %s\n\n", $1); } 
        | condition '\n'{printf("\t%s\n", falsoOVerdadero($1));}
;
            
exp: 	ENTERO { $$ = $1;}
		| exp '+' exp        { $$ = $1 + $3;    }
		| exp '*' exp        { $$ = $1 * $3;	}
		| exp '/' exp        { $$ = $1 / $3;	}
		| exp '-' exp		 { $$ = $1 - $3;	}	
		| '-' exp			 { $$ = -$2;		}
		| '(' exp ')'		 { $$ = $2;			}
		| POW '(' exp ',' exp ')'	{ $$ = potency($3, $5);}
		| POW '(' exp ',' expFloat ')'	{ 
			int exponente  = $5;
			$$ = potency($3, exponente);
		}
;

expFloat:	DECIMAL { $$ = $1;}
			| expFloat '-' exp		 		{ $$ = $1 - $3;	}
			| exp '-' expFloat		 		{ $$ = $1 - $3;	}
			| expFloat '-' expFloat			{ $$ = $1 - $3;	}
			| expFloat '+' exp		 		{ $$ = $1 + $3;	}
			| exp '+' expFloat		 		{ $$ = $1 + $3;	}
			| expFloat '+' expFloat			{ $$ = $1 + $3;	}
			| expFloat '*' exp		 		{ $$ = $1 * $3;	}
			| exp '*' expFloat		 		{ $$ = $1 * $3;	}
			| expFloat '*' expFloat			{ $$ = $1 * $3;	}
			| expFloat '/' exp		 		{ $$ = $1 / $3;	}
			| exp '/' expFloat		 		{ $$ = $1 / $3;	}
			| expFloat '/' expFloat			{ $$ = $1 / $3;	}
			| '-' expFloat					{ $$ = -$2;	   	}
			| '(' expFloat ')'		 		{ $$ = $2;	   	}
			| POW '(' expFloat ',' exp ')'	{ $$ = potency($3, $5);}
			| POW '(' expFloat ',' expFloat ')'	{ 
				int exponente  = $5;
				$$ = potency($3, exponente);
			}
;
			
texto: 	CAD {printf("cadena\n");}
		| texto '+' texto  {
			$$ = concatenarCadenas($1,$3);
		}
		| texto '+' exp {
			char *str = convertToString($3);
			$$ = concatenarCadenas($1, str);
		}
		| '(' texto ')'		{ $$ = $2; }
		| texto '^' exp {
					int nDigitos = contarDigitos($1);
					char *potencia = potenciarCadena($1, $3, nDigitos);
					$$ = potencia;
				}
;

condition: IF '(' exp '>' exp ')' ';' { 
				unsigned int num = ($3 > $5)? 1:0; 
				$$ = num;
			}
			| IF '(' exp '<' exp ')' ';' { 
				unsigned int num = ($3 < $5)? 1:0; 
				$$ = num;
			}
			| IF '(' expFloat '>' expFloat ')' ';' { 
				unsigned int num = ($3 > $5)? 1:0; 
				$$ = num;
			}
			| IF '(' expFloat '<' expFloat ')' ';' { 
				unsigned int num = ($3 < $5)? 1:0; 
				$$ = num;
			}
			| IF '(' expFloat '>' exp ')' ';' { 
				unsigned int num = ($3 > $5)? 1:0; 
				$$ = num;
			}
			| IF '(' expFloat '<' exp ')' ';' { 
				unsigned int num = ($3 < $5)? 1:0; 
				$$ = num;
			}
			| IF '(' exp '>' expFloat ')' ';' { 
				unsigned int num = ($3 > $5)? 1:0; 
				$$ = num;
			}
			| IF '(' exp '<' expFloat ')' ';' { 
				unsigned int num = ($3 < $5)? 1:0; 
				$$ = num;
			}
			| IF '('condition ')' ';' { 
				unsigned int num = ($3 == 1)? 1:0; 
				$$ = num;
			}

			

 
%%

int main() {
  yyparse();
}
             
void yyerror (char *s)
{
  printf("--%s--\n", s);
}
            
int yywrap()  
{  
  return 1;  
}  

int contarDigitos(char *cad){
	int contador = 0;
	while(*cad != 0){
		contador++;
		cad++;
	}
	return contador;
}

char *potenciarCadena(char *cadena, int num, int digitos){
	int i = 0;
	int j = 0;
	int asignacion = 0;
	int size = (digitos*num) + 1;
	char *str = malloc(sizeof(char)*(size));
	for(i; i < num; i++){
		for(j=0; j < digitos; j++){
			*(str+asignacion) = *(cadena+j);
			asignacion++;
		}
	}
	str[size-1] = 0;
	return str;
}

double potency(double base, double exponent){
	double result = 1;	
	while (exponent != 0) {
        result *= base;
        --exponent;
    }
    return result;
}

char *convertToString(int number){
	char buffer[50];
	int i = 0;

	bool isNeg = number < 0;

	unsigned int n1 = isNeg ? -number : number;

	while(n1!=0)
	{
	    buffer[i++] = n1%10+'0';
	    n1=n1/10;
	}

	if(isNeg)
	    buffer[i++] = '-';

	buffer[i] = '\0';

	for(int t = 0; t < i/2; t++)
	{
	    buffer[t] ^= buffer[i-t-1];
	    buffer[i-t-1] ^= buffer[t];
	    buffer[t] ^= buffer[i-t-1];
	}

	if(number == 0)
	{
	    buffer[0] = '0';
	    buffer[1] = '\0';
	}  

	int size = contarDigitos(buffer) +1;
	char *s = malloc(sizeof(char)*(size));
	for (i=0; buffer[i] != 0; i++){
		*(s+i) = buffer[i];
	}
	*(s+i) = '\0';
	return s;

}

char *concatenarCadenas(char *cad1, char *cad2) {
	int texto1 = contarDigitos(cad1);
	int texto2 = contarDigitos(cad2);
	char *s = malloc(sizeof(char)*(texto1 + texto2 + 1));
	int i=0;
	for(i;i < texto1; i++){
		*(s+i) = *cad1++;
	}
	for(i;i < (texto1 + texto2); i++){
		*(s+i) = *cad2++;
	}
	return s;
}

char *falsoOVerdadero(unsigned int numero){
	char *boolean = (numero == 0)? "false" : "true";
	return boolean;
}