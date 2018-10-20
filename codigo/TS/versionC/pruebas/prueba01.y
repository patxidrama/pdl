%{
// Prueba 01: "Flex-Bison"
// ---------------------------------

// El objetivo de esta prueba es comprobar
// que se puede manejar la tabla de
// s�mbolos correctamente desde el
// c�digo generado por Flex-Bison.

// Se ha creado un analizador muy
// sencillo que cuenta parejas diferentes
// de identificadores-n�mero entero
// positivo. Las identificadores se van
// insertando en una tabla
// de s�mbolos (a no ser que ya existieran) 
// y se les a�ade un atributo entero 
// valor. Al terminar se genera un
// fichero con el contenido final de
// la tabla usada.

#include "ts2006.h"
#define YYERROR_VERBOSE
extern FILE *yyin;
extern int micontador;
extern int mitabla;
extern int yyparse();
%}

%union
{
struct{
	char *ristra;
	int numero;
	}p; /* informaci�n de un lexema */
}

%token <ristra> CADENA
%token <numero> ENTERO

%start S

%%
S: S CADENA {  }
     ENTERO { 
  int res;
  if (existe_entrada(mitabla,$<p.ristra>2)!=0) 
  {
    res = crear_entrada(mitabla,$<p.ristra>2);
    res = asignar_tipo_entrada(mitabla, $<p.ristra>2, "prueba");
    res = crear_atributo_entero(mitabla, $<p.ristra>2, "valor", $<p.numero>4);
    fprintf(stdout,
    "Se asign� el valor %d al atributo valor del lexema %s\n",
    $<p.numero>4,$<p.ristra>2);
    micontador++;
  }
  else
  {
    fprintf(stdout,
     "Ya se ley� antes la cadena %s\n",
     $<p.ristra>2);
  } 
}
  | { /*  fin */ }

%%

int micontador=0;
int mitabla=0;

int main(int argc, char **argv) 
{
  int res;
  yyin = stdin; /* entrada del analizador = entrada por defecto */
  fprintf(stdout,
   "Leyendo parejas de cadena - n�mero. Terminar con CONTROL+Z\n");
  mitabla = crear_tabla();
  yyparse();
  res=escribir_tabla(mitabla,"tabla.txt");
  res=destruir_tabla(mitabla);
  fprintf(stdout,
   "Se han leido %d cadenas diferentes\n",micontador);
}


yyerror (char *s)
{
  printf ("ERROR SINT�CTICO: %s\n",s);
}

int yywrap()
{
  return 1;
}
