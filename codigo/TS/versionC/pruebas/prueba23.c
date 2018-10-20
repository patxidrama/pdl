// Prueba 23: "Cambio valor atributos - por posición"
// ---------------------------------

// Se comprobará que no ocurre ningún
// error tampoco al cambiar el
// valor de algunos atributos 
// por posición.
// Se puede observar como se escribe
// correctamente el contenido
// de la tabla en 
// tabla.txt



#include "ts2006.h" //necesario para 
// usar la tabla de símbolos

int main()
{
	int devuelto;
	int id;
	int pos1,pos2,pos3,pos4;
	printf("Creando una tabla...\n");
	id = crear_tabla();
	printf("Introducimos lexema"
	 " 'nombre'...\n");
    devuelto = crear_entrada(
	 id,"nombre");

	printf("Introducimos lexema"
	 " 'apellidos'...\n");
    devuelto = crear_entrada(
		id,"apellidos");

	printf("Introducimos lexema"
	 " 'dni'...\n");
    devuelto = crear_entrada(
	 id,"dni");

	printf("Introducimos lexema"
	 " 'valido'...\n");
    devuelto = crear_entrada(id,
	 "valido");

    pos1=buscar_posicion_entrada(
	 id,"nombre");
	pos2=buscar_posicion_entrada(
	 id,"apellidos");
	pos3=buscar_posicion_entrada(
	 id,"dni");
	pos4=buscar_posicion_entrada(
	 id,"valido");


	printf("Asignaremos a estas "
	 "entradas el tipo 'variable' "
	 "(por posición)...\n");
	devuelto=asignar_tipo_entrada2(
	 pos1,"variable");
	devuelto=asignar_tipo_entrada2(
	 pos2,"variable");
	devuelto=asignar_tipo_entrada2(
	 pos3,"variable");
	devuelto=asignar_tipo_entrada2(
	 pos4,"variable");

	printf("Introducimos algunos "
	 "atributos típicos a las "
	 "entradas (por posición)...\n");
    devuelto = crear_atributo_cadena2(
	 pos1, "tipo", "string");
    devuelto = crear_atributo_cadena2(
	 pos2, "tipo", "string");
	devuelto = crear_atributo_cadena2(
	 pos3, "tipo", "int");
    devuelto = crear_atributo_cadena2(
	 pos4, "tipo", "bool");
    devuelto = crear_atributo_entero2(
	 pos1, "desplazamiento", 0);
	devuelto = crear_atributo_entero2(
	 pos2, "desplazamiento", 16);
	devuelto = crear_atributo_entero2(
	 pos3, "desplazamiento", 32);
	devuelto = crear_atributo_entero2(
	 pos4, "desplazamiento", 48);

	printf("Cambiamos el valor de "
	 "los atributos (por posición)...\n");
	devuelto = asignar_valor_atributo_cadena2(
	 pos1, "tipo", "string*");
	devuelto = asignar_valor_atributo_cadena2(
	 pos2, "tipo", "string*");
	devuelto = asignar_valor_atributo_cadena2(
	 pos3, "tipo", "int*");
	devuelto = asignar_valor_atributo_cadena2(
	 pos4, "tipo", "bool*");

	devuelto = asignar_valor_atributo_entero2(
	 pos1, "desplazamiento", 1);
	devuelto = asignar_valor_atributo_entero2(
	 pos2, "desplazamiento", 2);
	devuelto = asignar_valor_atributo_entero2(
	 pos3, "desplazamiento", 3);
	devuelto = asignar_valor_atributo_entero2(
	 pos4, "desplazamiento", 4);

	printf("Escribiendo tabla en"
	 " 'tabla.txt'...\n");
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
