// Prueba 11: "Error - no existe tabla"
// ---------------------------------

// Se comprobará que se produce 
// un error si se intenta manejar 
// una tabla que no
// se ha creado.


#include "ts2006.h" //necesario para 
// usar la tabla de símbolos


int main()
{
	// Pruebas de error. 
	// Verificaremos que se 
	// dan los errores oportunos
	// en los casos de error más típicos:
	int devuelto;
	printf("crear_entrada en tabla 1:"
	 " lexema abc...\n");
	devuelto = crear_entrada(1,"abc");
	if (devuelto<0)
	{
	  printf("La función devolvió %d!\n"
	   " Último error: %s\n",devuelto,
	   consultar_descripcion_ultimo_error());
	  exit (0);
	}
	return 0;
}
