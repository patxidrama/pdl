// Prueba 30: "Crash II"
// ---------------------------------

// Se observar� que el programa se
// interrumpe de forma an�mala si en
// vez de una posici�n se pone
// un n�mero cualquiera que no
// se corresponda con una posici�n


#include "ts2006.h" //necesario para 
// usar la tabla de s�mbolos

int main()
{
	int devuelto;
	int id;
	int pos1,pos2,pos3,pos4;
	printf("Creando una tabla...\n");
	id = crear_tabla();
	printf("Introducimos lexema "
	 "'nombre'...\n");
    devuelto = crear_entrada(id,
	 "nombre");

	printf("Introducimos lexema "
	 "'apellidos' ...\n");
    devuelto = crear_entrada(
	 id,"apellidos");

	printf("Introducimos lexema "
	 "'dni' ...\n");
    devuelto = crear_entrada(
	 id,"dni");

	printf("Introducimos lexema "
	 "'valido' ...\n");
    devuelto = crear_entrada(
	 id,"valido");

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
	 "(por posici�n)...\n");
	// si por error se pone un numero 
	// cualquiera que no se 
	// corresponda con una posici�n
	// tambien se interrumpir�. 
	// Hay que poner especial cuidado en
	// evitar estos errores:
	devuelto=asignar_tipo_entrada2(
	 1234,"variable"); // CRASH!
	printf("asignar_tipo_entrada2("
	 "1234,'variable') devolvio %d\n",
	 devuelto);
	devuelto=asignar_tipo_entrada2(
	 pos2,"variable");
	devuelto=asignar_tipo_entrada2(
	 pos3,"variable");
	devuelto=asignar_tipo_entrada2(
	 pos4,"variable");

	printf("Introducimos algunos "
	 "atributos t�picos a las "
	 "entradas (por posici�n) ...\n");
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

	printf("Consultamos el valor "
	 "de los atributos (por posici�n)\n");
	printf("valor atributo 'tipo' en "
	 "pos1 = %s\n",
	 consultar_valor_atributo_cadena2(
	 pos1, "tipo"));
	printf("valor atributo 'tipo' en "
	 "pos2 = %s\n",
	 consultar_valor_atributo_cadena2(
	 pos2, "tipo"));
	printf("valor atributo 'tipo' en "
	 "pos3 = %s\n",
	 consultar_valor_atributo_cadena2(
	 pos3, "tipo"));
	printf("valor atributo 'tipo' en "
	 "pos4 = %s\n",
	 consultar_valor_atributo_cadena2(
	 pos4, "tipo"));;
	printf("valor atributo 'desplazamiento'"
	 " en pos1 = %d\n",
	 consultar_valor_atributo_entero2(
	 pos1, "desplazamiento"));
	printf("valor atributo 'desplazamiento'"
	 " en pos2 = %d\n",
	 consultar_valor_atributo_entero2(
	 pos2, "desplazamiento"));
	printf("valor atributo 'desplazamiento'"
	 " en pos3 = %d\n",
	 consultar_valor_atributo_entero2(
	 pos3, "desplazamiento"));
	printf("valor atributo 'desplazamiento'"
	 " en pos4 = %d\n",
	 consultar_valor_atributo_entero2(
	 pos4, "desplazamiento"));

	printf("Consultamos existencia"
	 " de algunos atributos "
	 "(por posici�n)\n");
	printf("existe 'tipo' en pos1 = %d\n",
	 existe_atributo2(pos1, "tipo"));
	printf("existe 'tipo' en pos2 = %d\n",
	 existe_atributo2(pos2, "tipo"));
	printf("existe 'tipo' en pos3 = %d\n",
	 existe_atributo2(pos3, "tipo"));
	printf("existe 'tipo' en pos4 = %d\n",
	 existe_atributo2(pos4, "tipo"));
	printf("existe 'desplazamiento' "
	 "en pos1 = %d\n",existe_atributo2(
	 pos1, "desplazamiento"));
	printf("existe 'desplazamiento' "
	 "en pos2 = %d\n",existe_atributo2(
	 pos2, "desplazamiento"));
	printf("existe 'desplazamiento' "
	 "en pos3 = %d\n",existe_atributo2(
	 pos3, "desplazamiento"));
	printf("existe 'desplazamiento' "
	 "en pos4 = %d\n",existe_atributo2(
	 pos4, "desplazamiento"));

	printf("existe 'otro' en pos1 = %d\n",
	 existe_atributo2(pos1, "otro"));
	printf("existe 'otro' en pos2 = %d\n",
	 existe_atributo2(pos2, "otro"));
	printf("existe 'otro' en pos3 = %d\n",
	 existe_atributo2(pos3, "otro"));
	printf("existe 'otro' en pos4 = %d\n",
	 existe_atributo2(pos4, "otro"));


	printf("Escribiendo tabla en "
	 "'tabla.txt' ...\n");
    devuelto = escribir_tabla(
	 id, "tabla.txt");
    // destrucci�n de la tabla ...
	printf("Destruyendo tabla ...\n");
	devuelto = destruir_tabla(id);
  
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
