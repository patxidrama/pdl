// Prueba 07: "Registro"
// ---------------------------------

// Este ejemplo muestra cómo
// se podría 
// introducir un registro de
// tipo "fecha" (con los campos 
// día, mes, año) y  un par de
// variables de ese tipo.

// Se puede observar cómo se
// escribe correctamente el 
// contenido de las tablas 
// del programa principal y 
// el de la tabla del registro.

#include "ts2006.h" //necesario para 
// usar la tabla de símbolos

int main()
{
	int devuelto;
	int id;
	int idreg;
	printf("Creando una tabla para"
	 " el programa principal... \n");
	id = crear_tabla();

	// registro
	printf("Creando una tabla para"
	 " el registro... \n");
	idreg = crear_tabla();
	printf("Introducimos la "
	 "estructura del "
	 "registro...\n");
	printf("Introducimos "
	 "lexema 'día'...\n");
    devuelto = crear_entrada(idreg,
	 "día");
	printf("Introducimos "
	 "lexema 'mes'... \n");
    devuelto = crear_entrada(idreg,
	 "mes");
	printf("Introducimos "
	 "lexema 'año'... \n");
    devuelto = crear_entrada(idreg,
	 "año");

	printf("Asignaremos a "
	 "estas entradas el "
	 "tipo 'variable'...\n");
	devuelto=asignar_tipo_entrada(
	 idreg,"día","variable");
	devuelto=asignar_tipo_entrada(
	 idreg,"mes","variable");
	devuelto=asignar_tipo_entrada(
	 idreg,"año","variable");

	printf("Introducimos algunos"
	 " atributos tipicos a "
	 "las entradas... \n");
    devuelto = crear_atributo_cadena(
	 idreg, "día", "tipo", "int");
    devuelto = crear_atributo_cadena(
	 idreg, "mes", "tipo", "int");
	devuelto = crear_atributo_cadena(
	 idreg, "año", "tipo", "int");
    devuelto = crear_atributo_entero(
	 idreg, "día", "desplazamiento", 0);
	devuelto = crear_atributo_entero(
	 idreg, "mes", "desplazamiento", 16);
	devuelto = crear_atributo_entero(
	 idreg, "año", "desplazamiento", 32);
  
	printf("Creamos el tipo registro "
	 "'fecha' en el programa "
	 "principal... \n");
	printf("Introducimos lexema "
	 "'fecha'...\n");
    devuelto = crear_entrada(id,"fecha");
	printf("Asignaremos a esta "
	 "entrada el tipo 'registro'...\n");
	devuelto=asignar_tipo_entrada(id,
	 "fecha","registro");
	printf("Creamos un atributo "
	 "ancho y otro idtabla... \n");
	devuelto = crear_atributo_entero(
	 id, "fecha", "ancho", 48);   
	devuelto = crear_atributo_entero(
	 id, "fecha", "idtabla", idreg); 

    // variables del programa principal
    printf("Creamos las variables "
	 "'día1' y 'día2' de tipo "
	 "'fecha' en el "
	 "p. principal... \n");
	printf("Introducimos lexema "
	 "'día1'...\n");
    devuelto = crear_entrada(
	 id,"día1");

	printf("Introducimos lexema "
	 "'día2'...\n");
    devuelto = crear_entrada(id,"día2");

	printf("Asignaremos a estas "
	 "entradas el tipo 'variable'...\n");
	devuelto=asignar_tipo_entrada(
	 id,"día1","variable");
	devuelto=asignar_tipo_entrada(
	 id,"día2","variable");

	printf("'día1' y 'día2' son "
	 "variables, pero su atributo"
	 " tipo será 'fecha'... \n");
    devuelto = crear_atributo_cadena(
	 id, "día1", "tipo", "fecha");

    devuelto = crear_atributo_cadena(
	 id, "día2", "tipo", "fecha");
    devuelto = crear_atributo_entero(
	 id, "día1", "desplazamiento", 0);
	devuelto = crear_atributo_entero(
	 id, "día2", "desplazamiento", 48);


	printf("Escribiendo tabla "
	 "registro en 'tablareg.txt'...\n");
    devuelto = escribir_tabla(
	 idreg, "tablareg.txt");

	printf("Escribiendo tabla "
	 "programa principal en"
	 " 'tabla.txt'...\n");
    devuelto = escribir_tabla(id,
	 "tabla.txt");

	printf("Destruyendo tabla"
	 " registro...\n");
	devuelto = destruir_tabla(idreg);

	printf("Destruyendo tabla"
	 " ppal... \n");
	devuelto = destruir_tabla(id);

	// por comodidad, valdrá con
	// consultar el último error 
	// al final para asegurarnos 
	// de que nada ha fallado 
    if (consultar_id_ultimo_error() != 0)
	{
	  printf("--Se han producido"
	   " errores--\n");
      printf("Último error: "
	   "%s\n",
	   consultar_descripcion_ultimo_error());
	}
	else
	{
      printf("No se produjeron "
	   "errores.\n");
	}
    return 0;
}
