// Prueba 27: "Consultar tipo de entrada no definido - por posición"
// ---------------------------------

// Se trata de comprobar que 
// también se obtendrá un error
// al intentar consultar 
// por posición el tipo de
// entrada si no se ha definido


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
	 "entradas el tipo 'variable'"
	 " (por posición)...\n");
	devuelto=asignar_tipo_entrada2(
	 pos1,"variable");
	devuelto=asignar_tipo_entrada2(
	 pos2,"variable");
	devuelto=asignar_tipo_entrada2(
	 pos3,"variable");
	;
    printf("Tipo entrada pos1: %s\n",
	 consultar_tipo_entrada2(pos1));
    printf("Tipo entrada pos2: %s\n",
	 consultar_tipo_entrada2(pos2));
	printf("Tipo entrada pos3: %s\n",
	 consultar_tipo_entrada2(pos3));
	// dara un error aqui:
	printf("Tipo entrada pos4: %s\n",
	 consultar_tipo_entrada2(pos4));

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
