%{
// Prueba 01: "Flex-Bison"
// ---------------------------------

// El objetivo de esta prueba es comprobar
// que se puede manejar la tabla de
// símbolos correctamente desde el
// código generado por Flex-Bison.

// Se ha creado un analizador muy
// sencillo que cuenta parejas diferentes
// de identificadores-número entero
// positivo. Las identificadores se van
// insertando en una tabla
// de símbolos (a no ser que ya existieran) 
// y se les añade un atributo entero 
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
	}p; /* información de un lexema */
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
    "Se asignó el valor %d al atributo valor del lexema %s\n",
    $<p.numero>4,$<p.ristra>2);
    micontador++;
  }
  else
  {
    fprintf(stdout,
     "Ya se leyó antes la cadena %s\n",
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
   "Leyendo parejas de cadena - número. Terminar con CONTROL+Z\n");
  mitabla = crear_tabla();
  yyparse();
  res=escribir_tabla(mitabla,"tabla.txt");
  res=destruir_tabla(mitabla);
  fprintf(stdout,
   "Se han leido %d cadenas diferentes\n",micontador);
}


yyerror (char *s)
{
  printf ("ERROR SINTÁCTICO: %s\n",s);
}

int yywrap()
{
  return 1;
}
