// Prueba 10: "Un poco de todo"
// ---------------------------------

// El objetivo de esta prueba
// es ver el correcto funcionamiento
// de todas las 
// funciones cuando son usadas
// todas ellas en un mismo programa.

// Se puede observar cómo se escribe
// correctamente el contenido
// de la tabla en 
// el fichero tabla.txt


#include "ts2006.h" //necesario para 
// usar la tabla de símbolos

int crear_cadena_y_pasarla_fuera_del_main()
{   // Esto es posible gracias
	// a que la tabla de símbolos
	// hace una copia de la cadena.
	// Aunque al finalizar esta
	// función este destruida, 
	// su copia permanece 
	// inalterada en la 
	// tabla de símbolos.
	int devuelto;
	char* test;
	test= (char*) malloc(5*sizeof(char*));
	test[0]='a';
	test[1]='l';
	test[2]='g';
	test[3]='o';
	test[4]='\0';
	printf("asignar_tipo_entrada "
	 "en tabla 3: lexema 'bac' "
	 "será de tipo 'algo'...\n");
	devuelto=asignar_tipo_entrada(
	 3,"bac",test);
    printf("Ultimo error: %s\n",
	 consultar_descripcion_ultimo_error());
	free(test);
	return 0;
}
int main()
{
	int devuelto;

	printf("Creando tabla...\n");
	devuelto = crear_tabla();
    printf("Se creo la tabla con"
	 " ID %d\n",devuelto);
	printf("Creando tabla...\n");
	devuelto = crear_tabla();
    printf("Se creo la tabla con"
	 " ID %d\n",devuelto);
	printf("Creando tabla...\n");
	devuelto = crear_tabla();
    printf("Se creo la tabla con"
	 " ID %d\n",devuelto);
	printf("Creando tabla...\n");
	devuelto = crear_tabla();
    printf("Se creo la tabla con"
	 " ID %d\n",devuelto);
	printf("Creando tabla...\n");
	devuelto = crear_tabla();
    printf("Se creo la tabla con"
	 " ID %d\n",devuelto);
	printf("crear_entrada en tabla 3:"
	 " lexema abc...\n");
    devuelto = crear_entrada(3,"abc");
	printf("crear_entrada en tabla 3:"
	 " lexema bca...\n");
    devuelto = crear_entrada(3,"bca");
	printf("crear_entrada en tabla 3:"
	 " lexema bac...\n");
    devuelto = crear_entrada(3,"bac");
    devuelto=
	 crear_cadena_y_pasarla_fuera_del_main();
    printf("tipo entrada = %s\n",
	 consultar_tipo_entrada(3,"bac"));
	printf("Creando atributo entero "
	 "'desplazamiento', valor 16 ,"
	 " en tabla 3, entrada 'bac'\n");
    devuelto = crear_atributo_entero(
	 3, "bac", "desplazamiento", 16);
	printf("Creando atributo cadena "
	 "'string', valor 'texto' , en "
	 "tabla 3, entrada 'bac'\n");
    devuelto = crear_atributo_cadena(
	 3, "bac", "string", "texto");
	printf("Creando atributo cadena "
	 "'prueba', valor 'probando' ,"
	 " en tabla 3, entrada 'bac'\n");
    devuelto = crear_atributo_cadena(
	 3, "bac", "prueba", "probando");
	printf("Creando atributo entero "
	 "'ancho', valor 64 , en "
	 "tabla 3, entrada 'bac'\n");
    devuelto = crear_atributo_entero(
	 3, "bac", "ancho", 64);
	printf("Creando atributo entero "
	 "'otro', valor 128 , en "
	 "tabla 3, entrada 'bca'\n");
    devuelto = crear_atributo_entero(
	 3, "bca", "otro", 128);
    printf("Actualizando atributo "
	 "entero 'otro' a valor 256 , "
	 "en tabla 3, entrada 'bca'\n");
    devuelto = asignar_valor_atributo_entero(
	 3, "bca", "otro",256);
	printf("Actualizando atributo "
	 "cadena 'string' a valor 'X' "
	 ", en tabla 3, entrada 'bac'\n");
    devuelto = asignar_valor_atributo_cadena(
	 3, "bac", "string","X");
	printf("Consultando atributo"
	 " desplazamiento:\n");
    devuelto=consultar_valor_atributo_entero(
	 3, "bac", "desplazamiento");
	printf("desplazamiento = %d\n",devuelto);
	printf("Consultando atributo ancho:\n");
    devuelto=consultar_valor_atributo_entero(
	 3, "bac", "ancho");
	printf("ancho = %d\n",devuelto);
	printf("Consultando atributo string:\n");
    printf("string = %s\n",
	 consultar_valor_atributo_cadena(
	 3, "bac", "string"));
	printf("Escribiendo tabla 3...\n");
    devuelto = escribir_tabla(3, 
	 "tabla3.txt");
	printf("Escribiendo tabla 4...\n");
    devuelto = escribir_tabla(4,
	 "tabla4.txt");
	printf("Destruyendo tabla 3...\n");
	devuelto = destruir_tabla(3);
	printf("Destruyendo tabla 4...\n");
	devuelto = destruir_tabla(4);
	printf("Destruyendo tabla 1...\n");
	devuelto = destruir_tabla(1);
	printf("Destruyendo tabla 5...\n");
	devuelto = destruir_tabla(5);
	printf("Destruyendo tabla 2...\n");
	devuelto = destruir_tabla(2);
	printf("Consultamos ID último error: "
	 "%d\n",consultar_id_ultimo_error()); 
    printf("Consultamos descripcion último "
	 "error: %s\n",
	 consultar_descripcion_ultimo_error()); 

    return 0;
}
