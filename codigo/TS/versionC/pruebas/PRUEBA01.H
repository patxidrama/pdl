typedef union
{
struct{
	char *ristra;
	int numero;
	}p; /* informacion de un lexema */
} YYSTYPE;
#define	CADENA	258
#define	ENTERO	259


extern YYSTYPE yylval;
