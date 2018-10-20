// Prueba 18: "Error - tipo de entrada no definido"
// ---------------------------------

// Se comprobará que se produce
// un error si se intenta 
// consultar el tipo de 
// entrada para una entrada
// donde no se ha definido esto.


#include "ts2006.h" //necesario para 
// usar la tabla de símbolos

int main()
{
    // Pruebas de error.
	// Verificaremos que se
	// dan los errores oportunos
	// en los casos de error más típicos:
	int devuelto;
	int tabla;
	char* tipoe;
	printf("Creando tabla...\n");
	tabla = crear_tabla();
	printf("Crear entrada en esta tabla"
	 ": lexema abc...\n");
    devuelto = crear_entrada(tabla,"abc");
	printf("Consultando tipo de entrada"
	 " del lexema abc de esta tabla...\n");
	tipoe=consultar_tipo_entrada(tabla, "abc");
    if (tipoe==NULL)
	{
      printf("La función devolvió NULL!\n"
	   "Último error: %s\n",
	   consultar_descripcion_ultimo_error());
	  exit (0);
	}
	
    return 0;
}
