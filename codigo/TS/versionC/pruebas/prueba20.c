// Prueba 20: "Último error en múltiples errores"
// ---------------------------------

// Se comprobará que cuando 
// se producen varios errores
// a lo largo de la 
// ejecución, la función para 
// consultar el último error 
// realmente sólo informa 
// del último error cometido.

#include "ts2006.h" //necesario para 
// usar la tabla de símbolos

int main()
{
    // Pruebas de error. 
	// Verificaremos que se dan
	// los errores oportunos
	// en los casos de error más típicos:
	int devuelto;
	int tabla;
	char* tipoe;
	printf("Creando tabla...\n");
	tabla = crear_tabla();
	printf("Crear entrada en esta tabla:"
	 " lexema NULL...\n");
    devuelto = crear_entrada(tabla,NULL);
    if (devuelto<0)
	{
      printf("La función devolvió "
	   "%d!\n",devuelto);
	}
	printf("Crear entrada en tabla"
	 " 1234: lexema abc...\n");
    devuelto = crear_entrada(1234,"abc");
    if (devuelto<0)
	{
      printf("La funcion devolvió"
	   " %d!\n",devuelto);
	}
	printf("Último error: %s\n",
	 consultar_descripcion_ultimo_error());

    return 0;
}
