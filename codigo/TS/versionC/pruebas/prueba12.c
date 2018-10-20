// Prueba 12: "Error - ya existe entrada"
// ---------------------------------

// Se comprobará que se 
// produce un error si 
// se intenta crear dos veces la misma
// entrada (lexema) en 
// la misma tabla.


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
	printf("Creando tabla...\n");
	tabla = crear_tabla();
	printf("crear_entrada en esta"
	 " tabla: lexema abc...\n");
    devuelto = crear_entrada(tabla,"abc");
	printf("crear_entrada en esta"
	 " tabla: lexema abc...\n");
    devuelto = crear_entrada(tabla,"abc");
    if (devuelto<0)
	{
      printf("La función devolvió %d!\n"
	   "Último error: %s\n",devuelto,
	   consultar_descripcion_ultimo_error());
	  exit (0);
	}
	
    return 0;
}
