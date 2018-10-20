// Prueba 13: "Error - no existe entrada"
// ---------------------------------

// Se comprobará que se produce
// un error si se intenta
// manejar una entrada que 
// no se ha creado.


#include "ts2006.h" //necesario para 
// usar la tabla de símbolos


int main()
{
    // Pruebas de error. 
	// Verificaremos que se
	// dan los errores oportunos
	// en los casos de error
	// más típicos:
	int devuelto;
	int tabla;
	printf("Creando tabla...\n");
	tabla = crear_tabla();
	printf("Creando un atributo en"
	 " la tabla creada, en "
	 "lexema 'abc'...\n");
	devuelto=crear_atributo_entero(tabla,
	 "abc", "algo", 0);
    if (devuelto<0)
	{
      printf("La función devolvió %d!\n"
	   "Último error: %s\n",devuelto,
	   consultar_descripcion_ultimo_error());
	  exit (0);
	}
	
    return 0;
}
