// Prueba 06: "Tabla rellena simple"
// ---------------------------------

// En este caso se desea mostrar un
// ejemplo de lo que podría ser rellenar 
// simplemente una única tabla con 
// 4 variables de un programa muy sencillo.

// Se puede observar cómo se escribe
// correctamente el contenido de la tabla
// en el fichero tabla.txt


#include "ts2006.h" //necesario para 
// usar la tabla de símbolos

int main()
{
	int devuelto;
	int id;
	printf("Creando una tabla...\n");
	id = crear_tabla();
	printf("Introducimos lexema"
	 " 'nombre'...\n");
    devuelto = crear_entrada(id,"nombre");

	printf("Introducimos lexema"
	 " 'apellidos'...\n");
    devuelto = crear_entrada(id,
	 "apellidos");

	printf("Introducimos lexema"
	 " 'dni'...\n");
    devuelto = crear_entrada(id,"dni");

	printf("Introducimos lexema"
	 " 'valido'...\n");
    devuelto = crear_entrada(id,
	 "valido");


	printf("Asignaremos a estas entradas"
	 " el tipo 'variable'...\n");
	devuelto=asignar_tipo_entrada(id,
	 "nombre","variable");
	devuelto=asignar_tipo_entrada(id,
	 "apellidos","variable");
	devuelto=asignar_tipo_entrada(id,
	 "dni","variable");
	devuelto=asignar_tipo_entrada(id,
	 "valido","variable");

	printf("Introducimos algunos"
	 " atributos típicos a "
	 "las entradas...\n");
    devuelto = crear_atributo_cadena(id,
	 "nombre", "tipo", "string");
    devuelto = crear_atributo_cadena(id,
	 "apellidos", "tipo", "string");
	devuelto = crear_atributo_cadena(id,
	 "dni", "tipo", "int");
    devuelto = crear_atributo_cadena(id,
	 "valido", "tipo", "bool");
    devuelto = crear_atributo_entero(id,
	 "nombre", "desplazamiento", 0);
	devuelto = crear_atributo_entero(id,
	 "apellidos", "desplazamiento", 16);
	devuelto = crear_atributo_entero(id,
	 "dni", "desplazamiento", 32);
	devuelto = crear_atributo_entero(id,
	 "valido", "desplazamiento", 48);

	printf("Escribiendo tabla en"
	 " 'tabla.txt'...\n");
    devuelto = escribir_tabla(id,
	 "tabla.txt");

	printf("Destruyendo tabla...\n");
	devuelto = destruir_tabla(id);

    if (consultar_id_ultimo_error() != 0)
	{
	  printf("--Se han producido"
	   " errores--\n");
      printf("Último error: %s\n",
	   consultar_descripcion_ultimo_error());
	}
	else
	{
      printf("No se produjeron errores.\n");
	}
    return 0;
}
