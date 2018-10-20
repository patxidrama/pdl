// Prueba 16: "Error - atributo no entero"
// ---------------------------------

// Se comprobará que se produce
// un error si se intenta 
// escribir una cadena en 
// el valor de un atributo entero.

#include "ts2006.h" //necesario para 
// usar la tabla de símbolos

int main()
{
    // Pruebas de error. 
	// Verificaremos que se dan
	// los errores oportunos
	// en los casos de error
	// más típicos:
	int devuelto;
	int tabla;
	printf("Creando tabla...\n");
	tabla = crear_tabla();
	printf("crear entrada en esta tabla"
	 ": lexema abc...\n");
    devuelto = crear_entrada(tabla,"abc");
	printf("Creando un atributo ENTERO "
	 "'algo' en la tabla creada, "
	 "en lexema 'abc'...\n");
	devuelto=crear_atributo_entero(
	 tabla, "abc", "algo", 0);
	printf("Asignar valor 'abcd' (CADENA)"
	 " al atributo 'algo' del lexema "
	 "'abc' de esta tabla...\n");
	devuelto=asignar_valor_atributo_cadena(
	 tabla, "abc", "algo", "abcd");
    if (devuelto<0)
	{
      printf("La función devolvió %d!\n"
	   "Último error: %s\n",devuelto,
	   consultar_descripcion_ultimo_error());
	  exit (0);
	}
	
    return 0;
}
