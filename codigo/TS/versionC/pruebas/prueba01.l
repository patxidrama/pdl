/* prueba flex bison */

%{
#include "ts2006.h"
#include "prueba01.h"
%}


DIGITO  [0-9]
LETRA	[a-zA-Z]


%%

{DIGITO}+	{
  yylval.p.numero = atoi(yytext);
  return ENTERO;
}

{LETRA}+	{
  yylval.p.ristra = strdup(yytext);
  return CADENA;
}

[ \t\n]+	/* ignorar blancos, tabuladores y saltos de l�nea */

. { 
  fprintf(stdout,
   "ERROR L�XICO: Car�cter no v�lido: %s\n",yytext); 
}

%%

