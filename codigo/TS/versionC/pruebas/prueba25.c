// Prueba 25: "Uso combinado de funciones normales y por posición"
// ---------------------------------

// Se trata de observar de que 
// no se produzca ninguna clase de fallo
// por usar ambas formas de 
// acceso en el mismo programa.


#include "ts2006.h" //necesario para 
// usar la tabla de símbolos

int main()
{
	int devuelto;
	int id;
	int pos1,pos2;
	printf("Creando una tabla...\n");
	id = crear_tabla();
	printf("Introducimos lexema "
	 "'nombre'...\n");
    devuelto = crear_entrada(id,
	 "nombre");

	printf("Introducimos lexema "
	 "'apellidos'...\n");
    devuelto = crear_entrada(id,
	 "apellidos");

	printf("Introducimos lexema "
	 "'dni'...\n");
    devuelto = crear_entrada(id,"dni");

	printf("Introducimos lexema "
	 "'valido'...\n");
    devuelto = crear_entrada(id,
	 "valido");

    pos1=buscar_posicion_entrada(
	 id,"nombre");
	pos2=buscar_posicion_entrada(
	 id,"apellidos");


	printf("Asignaremos a estas entradas"
	 " el tipo 'variable' (por "
	 "posición)...\n");
	devuelto=asignar_tipo_entrada2(
	 pos1,"variable");
	devuelto=asignar_tipo_entrada2(
	 pos2,"variable");
	devuelto=asignar_tipo_entrada(
	 id,"dni","variable");
	devuelto=asignar_tipo_entrada(
	 id,"valido","variable");

	printf("Introducimos algunos "
	 "atributos típicos a las "
	 "entradas (por posición)...\n");
    devuelto = crear_atributo_cadena2(
	 pos1, "tipo", "string");
    devuelto = crear_atributo_cadena2(
	 pos2, "tipo", "string");
	devuelto = crear_atributo_cadena(
	 id,"dni", "tipo", "int");
    devuelto = crear_atributo_cadena(
	 id,"valido", "tipo", "bool");
    devuelto = crear_atributo_entero2(
	 pos1, "desplazamiento", 0);
	devuelto = crear_atributo_entero2(
	 pos2, "desplazamiento", 16);
	devuelto = crear_atributo_entero(
	 id,"dni", "desplazamiento", 32);
	devuelto = crear_atributo_entero(
	 id,"valido", "desplazamiento", 48);

	printf("Consultamos el valor de "
	 "los atributos (por posición)\n");
	printf("valor atributo 'tipo' en "
	 "pos1 = %s\n",
	 consultar_valor_atributo_cadena2(
	 pos1, "tipo"));
	printf("valor atributo 'tipo' en "
	 "pos2 = %s\n",
	 consultar_valor_atributo_cadena2(
	 pos2, "tipo"));
	printf("valor atributo 'tipo' en "
	 "id,'dni' = %s\n",
	 consultar_valor_atributo_cadena(
	 id,"dni", "tipo"));
	printf("valor atributo 'tipo' en "
	 "'valido' = %s\n",
	 consultar_valor_atributo_cadena(
	 id,"valido", "tipo"));;
	printf("valor atributo 'desplazamiento'"
	 " en pos1 = %d\n",
	 consultar_valor_atributo_entero2(
	 pos1, "desplazamiento"));
	printf("valor atributo 'desplazamiento'"
	 " en pos2 = %d\n",
	 consultar_valor_atributo_entero2(
	 pos2, "desplazamiento"));
	printf("valor atributo 'desplazamiento'"
	 " en id,'dni' = %d\n",
	 consultar_valor_atributo_entero(
	 id,"dni", "desplazamiento"));
	printf("valor atributo 'desplazamiento'"
	 " en id,'valido' = %d\n",
	 consultar_valor_atributo_entero(
	 id,"valido", "desplazamiento"));

	printf("Escribiendo tabla en "
	 "'tabla.txt'...\n");
    devuelto = escribir_tabla(
		id, "tabla.txt");

	printf("Destruyendo tabla...\n");
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
