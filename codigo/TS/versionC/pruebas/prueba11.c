// Prueba 11: "Error - no existe tabla"
// ---------------------------------

// Se comprobar� que se produce 
// un error si se intenta manejar 
// una tabla que no
// se ha creado.


#include "ts2006.h" //necesario para 
// usar la tabla de s�mbolos


int main()
{
	// Pruebas de error. 
	// Verificaremos que se 
	// dan los errores oportunos
	// en los casos de error m�s t�picos:
	int devuelto;
	printf("crear_entrada en tabla 1:"
	 " lexema abc...\n");
	devuelto = crear_entrada(1,"abc");
	if (devuelto<0)
	{
	  printf("La funci�n devolvi� %d!\n"
	   " �ltimo error: %s\n",devuelto,
	   consultar_descripcion_ultimo_error());
	  exit (0);
	}
	return 0;
}
