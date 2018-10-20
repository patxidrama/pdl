// Prueba 03: " Muchas tablas"
// ---------------------------------

// El objetivo de esta prueba es comprobar
// el rendimiento cuando se tienen 
// cargadas un gran n�mero de tablas
// en memoria.

// Primero se crear�n muchas tablas en un
// bucle y luego se destruir�n todas 
// en otro bucle. Se ha observado que
// el rendimiento es aceptable, 
// La ejecuci�n se produce de forma
// pr�cticamente instantanea (<0,01s)

// Sin embargo, con 5000 tablas
// en memoria a la vez,
// el manejo interno de las
// listas enlazadas se notar� en la
// velocidad de ejecuci�n (0,22s)

// Nota: Los tiempos se han
// medido con un sencillo batch de msdos
// llamado medir03.bat
// en un portatil con 2Ghz,2Gb RAM

#include "ts2006.h" //necesario para 
// usar la tabla de s�mbolos

#define NUMTABLAS 5000 // tablas que 
// se van a crear seguidas y 
// luego se destruiran

int main()
{
	int i;
	int devuelto;
	char* desc;
	// Se crear�n NUMTABLAS tablas
	printf("Creando %d tablas de s�mbolos... ",
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
	printf("Operaci�n completada con �xito\n");
	printf("Destruyendo esas %d tablas " 
	"de s�mbolos... ",NUMTABLAS);
	for( i = 1; i <= NUMTABLAS; i++ )
	{
		// En realidad se tendr�a que 
		// haber guardado una lista
		// de los ids obtenidos, pero 
		// para simplificar, nos aprovecharemos
		// de que sabemos de antemano 
		// que los identificadores que
		// se habr�n obtenido
		// ser�n del 1 a NUMTABLAS
		devuelto = destruir_tabla(i);
		if (devuelto<0)
		{
			desc=consultar_descripcion_ultimo_error();
			printf("Se produjo un error al "
			"destruir la tabla %d : %s\n",i,desc);
			exit(-1);
		}
	}
	printf("Operaci�n completada con �xito\n");
}
