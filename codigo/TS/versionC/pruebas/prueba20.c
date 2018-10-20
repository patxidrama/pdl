// Prueba 20: "�ltimo error en m�ltiples errores"
// ---------------------------------

// Se comprobar� que cuando 
// se producen varios errores
// a lo largo de la 
// ejecuci�n, la funci�n para 
// consultar el �ltimo error 
// realmente s�lo informa 
// del �ltimo error cometido.

#include "ts2006.h" //necesario para 
// usar la tabla de s�mbolos

int main()
{
    // Pruebas de error. 
	// Verificaremos que se dan
	// los errores oportunos
	// en los casos de error m�s t�picos:
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
      printf("La funci�n devolvi� "
	   "%d!\n",devuelto);
	}
	printf("Crear entrada en tabla"
	 " 1234: lexema abc...\n");
    devuelto = crear_entrada(1234,"abc");
    if (devuelto<0)
	{
      printf("La funcion devolvi�"
	   " %d!\n",devuelto);
	}
	printf("�ltimo error: %s\n",
	 consultar_descripcion_ultimo_error());

    return 0;
}
