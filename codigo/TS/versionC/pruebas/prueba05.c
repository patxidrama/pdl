// Prueba 05: "Con colisiones"
// ---------------------------------

// Se crean muchas entradas de forma
// que se garantize que
// ocurrirán colisiones en la
// tabla hash.

// El hecho de que se produzcan o no
// colisiones internas es totalmente 
// invisible para el usuario, que no
// tiene que preocuparse por 
// estos problemas. 
// Externamente debería funcionar
// igual de bien (o quizás unos 
// nanosegundos más lentos 
// si hay colisiones).

#include "ts2006.h" //necesario para 
// usar la tabla de símbolos

#define NUMENTRADAS 2500 // entradas
// que vamos a crear para la prueba

int main()
{
	int devuelto;
	int id;
	int i;
	int v;
	int num[3];
	int mult;
	char nombre_entrada[13];
	// se crea una tabla
	printf("Creando tabla...\n");
	id = crear_tabla();
    if (id<0) 
	{ 
		printf("Se produjo un error: %s\n",
		 consultar_descripcion_ultimo_error()); 
		exit(-1); 
	}
	// se crean muchas entradas
	// de formas que se
	// produzcan eventualmente
	// colisiones en la funcion hash
	printf("Creando muchas entradas...\n");
    // devuelto = crear_entrada(id,"baaaaaaaaaa");
	nombre_entrada[11]=0;
	for ( i = 0; i <= NUMENTRADAS-1 ; i++ )
	{
		v=i;
		nombre_entrada[0]=97;
		nombre_entrada[1]=97;
		nombre_entrada[2]=97;
		nombre_entrada[3]=97;
		nombre_entrada[4]=97;
		nombre_entrada[5]=97;
		nombre_entrada[6]=97;
		nombre_entrada[7]=97;
		num[0]=v%26;
		v=v/26;
		num[1]=v%26;
		v=v/26;
		num[2]=v%26;
		nombre_entrada[8]=97+num[2];
		nombre_entrada[9]=97+num[1];
		nombre_entrada[10]=97+num[0];
		// printf("Creando entrada... %s\n",
		// nombre_entrada);
		devuelto = crear_entrada(id,
		 nombre_entrada);
		if (devuelto != 0)
		{
			printf("(!) En la anterior llamada"
			 " se produjo el error %d\n",
			 devuelto);
		}
	}
	// se escribe la tabla en fichero
	devuelto = escribir_tabla(id,"tabla.txt");

	// se destuye la tabla
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
