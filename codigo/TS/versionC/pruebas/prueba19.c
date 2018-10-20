// Prueba 19: "Error - lexema es null"
// ---------------------------------

// Se comprobar� que se produce
// un error si se intenta
// introducir como lexema 
// una cadena NULL.

#include "ts2006.h" //necesario para 
// usar la tabla de s�mbolos

int main()
{
    // Pruebas de error.
	// Verificaremos que se
	// dan los errores oportunos
	// en los casos de error m�s t�picos:
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
      printf("La funci�n devolvi� %d!\n"
	   "�ltimo error: %s\n",devuelto,
	   consultar_descripcion_ultimo_error());
	  exit (0);
	}
	
    return 0;
}
