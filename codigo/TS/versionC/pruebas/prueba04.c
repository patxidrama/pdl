// Prueba 04: "Sin colisiones"
// ---------------------------------

// Aquí simplemente se observará el 
// funcionamiento correcto cuando se crean 
// algunas entradas vacías en una tabla.

// Los nombres elegidos para las entradas
// no provocarán colisiones en
// la tabla hash

#include "ts2006.h" //necesario para 
// usar la tabla de símbolos

int main()
{
	int devuelto;
	int id;
	// se crea una tabla
	printf("Creando tabla...\n");
	id = crear_tabla();
    if (id<0) 
	{ 
		printf("Se produjo un error: %s\n",
		 consultar_descripcion_ultimo_error()); 
		exit(-1); 
	}
	// se crean varias entradas
	printf("Creando varias entradas...\n");
    devuelto = crear_entrada(id,"aaaaaaaaaaa");
    devuelto = crear_entrada(id,"aaaaaaaaaab");
    devuelto = crear_entrada(id,"aaaaaaaaaac");
    devuelto = crear_entrada(id,"aaaaaaaaaad");
    devuelto = crear_entrada(id,"aaaaaaaaaae");
    devuelto = crear_entrada(id,"aaaaaaaaaaf");
    devuelto = crear_entrada(id,"aaaaaaaaaag");
    devuelto = crear_entrada(id,"aaaaaaaaaah");
    devuelto = crear_entrada(id,"aaaaaaaaaai");
    devuelto = crear_entrada(id,"aaaaaaaaaaj");
    devuelto = crear_entrada(id,"aaaaaaaaaak");
    devuelto = crear_entrada(id,"aaaaaaaaaal");
    devuelto = crear_entrada(id,"aaaaaaaaaam");
    devuelto = crear_entrada(id,"aaaaaaaaaan");
    devuelto = crear_entrada(id,"aaaaaaaaaañ");
    devuelto = crear_entrada(id,"aaaaaaaaaao");
    devuelto = crear_entrada(id,"aaaaaaaaaap");
	// se escribe tabla en fichero
	devuelto = escribir_tabla(id,"tabla.txt");

	// se destruye la tabla
	devuelto = destruir_tabla(id);
    if (consultar_id_ultimo_error() != 0)
	{
		printf("--Se han producido errores--\n");
		printf("Último error: %s\n",
		 consultar_descripcion_ultimo_error());
	}
	else
	{
		printf("No se produjeron errores.\n");
	}
    return 0;
}
