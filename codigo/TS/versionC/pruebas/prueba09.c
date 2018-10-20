// Prueba 09: "Procedimiento"
// ---------------------------------

// Un ejemplo explica cómo 
// se podría introducir un 
// procedimiento "helloworld" en las
// tablas de símbolos. 
// Este procedimiento no tiene 
// parámetros y no tiene ningún 
// valor de retorno.

// Se puede observar cómo
// se escribe correctamente 
// el contenido de las tablas 
// del programa principal y 
// el de la tabla de la función.

#include "ts2006.h" //necesario para 
// usar la tabla de símbolos

int main()
{
	int devuelto;
	int id;
	int idprocedimiento;
	printf("Creando una tabla "
	 "para el programa principal...\n");
	id = crear_tabla();

	// procedimiento
	printf("Creando una tabla para"
	 " el procedimiento 'helloworld'...\n");
	idprocedimiento = crear_tabla();
	printf("Supongamos que el "
	 "procedimiento usa tres "
	 "variables locales "
	 "'a','b','c':... \n");
	printf("Introducimos lexema"
	 " 'a'...\n");
    devuelto = crear_entrada(
	 idprocedimiento,"a");

	printf("Introducimos lexema"
	 " 'b'... \n");
    devuelto = crear_entrada(
	 idprocedimiento,"b");

	printf("Introducimos lexema "
	 "'c'... \n");
    devuelto = crear_entrada(
	 idprocedimiento,"c");

	printf("Asignaremos a estas "
	 "entradas el tipo 'variable'...\n");
	devuelto=asignar_tipo_entrada(
	 idprocedimiento,"a","variable");
	devuelto=asignar_tipo_entrada(
	 idprocedimiento,"b","variable");
	devuelto=asignar_tipo_entrada(
	 idprocedimiento,"c","variable");

	printf("Introducimos algunos "
	 "atributos típicos "
	 "a las entradas... \n");
    devuelto = crear_atributo_cadena(
	 idprocedimiento, "a", "tipo", "int");
    devuelto = crear_atributo_cadena(
	 idprocedimiento, "b", "tipo", "int");
	devuelto = crear_atributo_cadena(
	 idprocedimiento, "c", "tipo", "int");
    devuelto = crear_atributo_entero(
	 idprocedimiento, "a", 
	 "desplazamiento", 0);
	devuelto = crear_atributo_entero(
	 idprocedimiento, "b", 
	 "desplazamiento", 16);
	devuelto = crear_atributo_entero(
	 idprocedimiento, "c", 
	 "desplazamiento", 32);
  
    // tras procesar el procedimiento,
	// un compilador podría 
	// destruir su tabla:

	// primero lo escribimos en
	// fichero (no podriamos
	// tras destruirlo)

	printf("Escribiendo tabla "
	 "procedimiento en "
	 "'tablaproc.txt'...\n");
    devuelto = escribir_tabla(
	 idprocedimiento, "tablaproc.txt");

	printf("Destruyendo tabla"
	 " procedimiento... \n");
	devuelto = destruir_tabla(
	 idprocedimiento);

	printf("Creamos el enlace al "
     "procedimiento en el "
	 "programa principal...\n");
	printf("Introducimos lexema "
	 "'helloworld'...\n");
    devuelto = crear_entrada(id,
	 "helloworld");

	printf("Asignaremos a esta entrada "
	 "el tipo 'procedimiento'...\n");
	devuelto=asignar_tipo_entrada(
	 id,"helloworld","procedimiento");
	printf("Creamos los atributos "
	 "tipo, ancho e idtabla...\n");
	devuelto = crear_atributo_entero(
	 id, "helloworld", "ancho", 48);   
	devuelto = crear_atributo_entero(
	 id, "helloworld",
	 "idtabla", idprocedimiento);
	printf("En un atributo indicaremos"
	 " que no tiene parámetros"
	 " (numpar=0)... \n");
	devuelto = crear_atributo_entero(
	 id, "helloworld", "numpar", 0);   

    // variables del programa principal
    printf("Creamos una variable "
	 "'algo' en el p. principal... \n");
	printf("Introducimos lexema 'algo'...\n");
    devuelto = crear_entrada(id,"algo");
	printf("Asignaremos a esta entrada"
	 " el tipo 'variable'...\n");
	devuelto=asignar_tipo_entrada(
	 id,"algo","variable");

	printf("Ponemos algunos atributos"
	 " a esta entrada 'algo'...\n");
    devuelto = crear_atributo_cadena(
	 id, "algo", "tipo", "int");
    devuelto = crear_atributo_entero(
	 id, "algo", "desplazamiento", 0);

	printf("Escribiendo tabla programa"
	 " principal en 'tabla.txt'...\n");
    devuelto = escribir_tabla(id,
	 "tabla.txt");

	printf("Destruyendo tabla p. pal...\n");
	devuelto = destruir_tabla(id);

	// por comodidad, valdrá con
	// consultar el último error 
	// al final para asegurarnos
	// de que nada ha fallado.
    if (consultar_id_ultimo_error() != 0)
	{
	  printf("--Se han producido"
	   " errores--\n");
      printf("Último error:"
	   " %s\n",
	   consultar_descripcion_ultimo_error());
	}
	else
	{
      printf("No se produjeron errores.\n");
	}
    return 0;
}
