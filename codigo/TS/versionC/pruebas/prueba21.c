// Prueba 21: "Funci�n - por posici�n"
// ---------------------------------

// Un ejemplo de como se podr�a
// introducir una funci�n 
// "sumar" en las tablas de
// s�mbolos. Esta funci�n tiene 
// 2 par�metros enteros 
// y devuelve un entero.

// Se puede observar como se escribe
// correctamente el contenido
// de las tablas
// del programa principal y 
// el de la tabla de la funci�n.

#include "ts2006.h" //necesario para 
// usar la tabla de s�mbolos

int main()
{
	int devuelto;
	int id;
	int idfuncion;
	int pos;
	printf("Creando una tabla "
	 "para el programa principal...\n");
	id = crear_tabla();

	// funcion
	printf("Creando una tabla para"
	 " la funcion 'sumar'...\n");
	idfuncion = crear_tabla();
	printf("Supongamos que la "
	 "funcion usa tres variables "
	 "locales 'a','b','c': ...\n");

	printf("Introducimos lexema"
	 " 'a'...\n");
    devuelto = crear_entrada(idfuncion,"a");

	printf("Introducimos lexema"
	 " 'b'...\n");
    devuelto = crear_entrada(idfuncion,"b");

	printf("Introducimos lexema"
	 " 'c'...\n");
    devuelto = crear_entrada(idfuncion,"c");

	printf("Asignaremos a estas "
	 "entradas el tipo 'variable'...\n");
	devuelto=asignar_tipo_entrada(
	 idfuncion,"a","variable");
	devuelto=asignar_tipo_entrada(
	 idfuncion,"b","variable");
	devuelto=asignar_tipo_entrada(
	 idfuncion,"c","variable");

	printf("Consultamos la posici�n"
	 " de la entrada 'a' en la "
	 "tabla de la funci�n\n");
    pos=buscar_posicion_entrada(
	 idfuncion,"a");

  	printf("Cambiando tipo de entrada"
	 " 'a' a traves de la posici�n...\n");
    devuelto=asignar_tipo_entrada2(
	 pos,"cosarara"); 

	printf("Cambiado tipo de entrada "
	 "'a': %s\n",
	 consultar_tipo_entrada(idfuncion,"a"));
    


	printf("Introducimos algunos "
	 "atributos t�picos a las "
	 "entradas...\n");
    devuelto = crear_atributo_cadena(
	 idfuncion, "a", "tipo", "int");
    devuelto = crear_atributo_cadena(
	 idfuncion, "b", "tipo", "int");
	devuelto = crear_atributo_cadena(
	 idfuncion, "c", "tipo", "int");
    devuelto = crear_atributo_entero(
	 idfuncion, "a", "desplazamiento", 0);
	devuelto = crear_atributo_entero(
	 idfuncion, "b", "desplazamiento", 16);
	devuelto = crear_atributo_entero(
	 idfuncion, "c", "desplazamiento", 32);
  
    // tras procesar la funcion, 
	// un compilador podr�a 
	// destruir su tabla:

	// primero la escribimos en
	// fichero (no podr�amos
	// tras destruirla)

	printf("Escribiendo tabla "
	 "funci�n en 'tablaf.txt'...\n");
    devuelto = escribir_tabla(idfuncion,
     "tablaf.txt");

	printf("Destruyendo tabla "
	 "funcion...\n");
	devuelto = destruir_tabla(idfuncion);

	printf("Creamos el enlace a la funci�n"
	 " en el programa principal ..\n");
	printf("Introducimos lexema "
	 "'sumar'...\n");
    devuelto = crear_entrada(id,"sumar");

	printf("Asignaremos a esta entrada"
	 " el tipo 'funcion'...\n");
	devuelto=asignar_tipo_entrada(id,
	 "sumar","funcion");
	printf("Creamos los atributos tipo"
	 ", ancho e idtabla...\n");
	devuelto = crear_atributo_cadena(
	 id, "sumar", "tipo", "int");
	devuelto = crear_atributo_entero(
	 id, "sumar", "ancho", 48);   
	devuelto = crear_atributo_entero(
	 id, "sumar", "idtabla", idfuncion);
	printf("Creamos ademas atributos "
	 "para los par�metros ...\n");
	devuelto = crear_atributo_entero(
	 id, "sumar", "numpar", 2);   
	devuelto = crear_atributo_cadena(
	 id, "sumar", "tipopar1", "int");
	devuelto = crear_atributo_cadena(
	 id, "sumar", "modopar1", "pasoporvalor");
	devuelto = crear_atributo_cadena(
	 id, "sumar", "tipopar2", "int");
	devuelto = crear_atributo_cadena(
	 id, "sumar", "modopar2", "pasoporvalor");

    // variables del programa principal
    printf("Creamos una variable 'algo'"
	 " en el p. principal...\n");
	printf("Introducimos lexema "
	 "'algo'...\n");
    devuelto = crear_entrada(id,"algo");
	printf("Asignaremos a esta "
	 "entrada el tipo 'variable'...\n");
	devuelto=asignar_tipo_entrada(
	 id,"algo","variable");

	printf("ponemos algunos atributos"
	 " a esta entrada 'algo'...\n");
    devuelto = crear_atributo_cadena(
	 id, "algo", "tipo", "int");
    devuelto = crear_atributo_entero(
	 id, "algo", "desplazamiento", 0);

	printf("Escribiendo tabla "
	 "programa principal en "
	 "'tabla.txt'...\n");
    devuelto = escribir_tabla(id,
	 "tabla.txt");

	printf("Destruyendo tabla...\n");
	devuelto = destruir_tabla(id);

	// por comodidad, valdr� con
	// consultar el �ltimo error 
	// al final para asegurarnos
	// de que nada ha fallado 
    if (consultar_id_ultimo_error() != 0)
	{
	  printf("--Se han producido errores--\n");
      printf("�ltimo error: %s\n",
	   consultar_descripcion_ultimo_error());
	}
	else
	{
      printf("No se produjeron errores.\n");
	}
    return 0;
}
