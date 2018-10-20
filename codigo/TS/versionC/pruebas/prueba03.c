// Prueba 03: " Muchas tablas"
// ---------------------------------

// El objetivo de esta prueba es comprobar
// el rendimiento cuando se tienen 
// cargadas un gran número de tablas
// en memoria.

// Primero se crearán muchas tablas en un
// bucle y luego se destruirán todas 
// en otro bucle. Se ha observado que
// el rendimiento es aceptable, 
// La ejecución se produce de forma
// prácticamente instantanea (<0,01s)

// Sin embargo, con 5000 tablas
// en memoria a la vez,
// el manejo interno de las
// listas enlazadas se notará en la
// velocidad de ejecución (0,22s)

// Nota: Los tiempos se han
// medido con un sencillo batch de msdos
// llamado medir03.bat
// en un portatil con 2Ghz,2Gb RAM

#include "ts2006.h" //necesario para 
// usar la tabla de símbolos

#define NUMTABLAS 5000 // tablas que 
// se van a crear seguidas y 
// luego se destruiran

int main()
{
	int i;
	int devuelto;
	char* desc;
	// Se crearán NUMTABLAS tablas
	printf("Creando %d tablas de símbolos... ",
	NUMTABLAS);
	for( i = 1; i <= NUMTABLAS; i++ )
	{
		devuelto = crear_tabla(); // se crea una tabla
		if (devuelto<0)
		{
			desc=consultar_descripcion_ultimo_error();
			printf("Se produjo un error " 
			"al crear una tabla. "
			"Iteracion %d : %s\n",i,desc);
			exit(-1);
		}
	}
	// Se destruyen NUMTABLAS tablas
	printf("Operación completada con éxito\n");
	printf("Destruyendo esas %d tablas " 
	"de símbolos... ",NUMTABLAS);
	for( i = 1; i <= NUMTABLAS; i++ )
	{
		// En realidad se tendría que 
		// haber guardado una lista
		// de los ids obtenidos, pero 
		// para simplificar, nos aprovecharemos
		// de que sabemos de antemano 
		// que los identificadores que
		// se habrán obtenido
		// serán del 1 a NUMTABLAS
		devuelto = destruir_tabla(i);
		if (devuelto<0)
		{
			desc=consultar_descripcion_ultimo_error();
			printf("Se produjo un error al "
			"destruir la tabla %d : %s\n",i,desc);
			exit(-1);
		}
	}
	printf("Operación completada con éxito\n");
}
