// Prueba 19: "Error - lexema es null"
// ---------------------------------

// Se comprobará que se produce
// un error si se intenta
// introducir como lexema 
// una cadena NULL.

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
	printf("Crear entrada en esta"
	 " tabla: lexema NULL...\n");
    devuelto = crear_entrada(tabla,NULL);
    if (devuelto<0)
	{
      printf("La función devolvió %d!\n"
	   "Último error: %s\n",devuelto,
	   consultar_descripcion_ultimo_error());
	  exit (0);
	}
	
    return 0;
}
