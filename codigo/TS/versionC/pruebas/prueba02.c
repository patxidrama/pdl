// Prueba 02: "Crear y destruir tablas"
// ---------------------------------

// El objetivo de esta prueba es comprobar
// que no se producen errores de 
// memoria al crear y destruir tablas 
// repetitivamente.

// Simplemente se crean y destruyen
// muchas tablas en un bucle.

#include "ts2006.h" //  necesario para 
// usar la tabla de símbolos

#define NUMTABLAS 500 // tablas que se
// van a crear y destruir
int main()
{
	int i;
	int id;
	int devuelto;
	char* desc;
	printf("Creando y destruyendo %d "
	 "tablas de símbolos...\n",NUMTABLAS);
	for( i = 0; i < NUMTABLAS; i++ )
	{
	id = crear_tabla(); // crea una tabla
	if (id>0)
	{
		// se destruye la tabla recién creada
		devuelto = destruir_tabla(id);
		if (devuelto!=0)
		{
			desc=consultar_descripcion_ultimo_error();
			printf("Se produjo un error al"
			 " destruir la tabla %d: %s\n",id,desc);
			exit(-1);
		}
	}
	else
	{
		desc=consultar_descripcion_ultimo_error();
		printf("Se produjo un error al crear "
		 "una tabla. Iteración %d: %s\n",i,desc);
		exit(-1);
	}
	}
	printf("Operación completada con éxito");
}
