// Prueba 09: "S�mbolos extra�os en el nombre"
// ---------------------------------

// Se analizar� que ocurre al intentar escribir
// atributos con s�mbolos extra�os en el
// nombre de atributo. Se usar� un bucle que
// generar� 255 cadenas de una sola letra con
// diferentes valores ASCII. 
// Se escribir� la tabla al final.

// Se comprueba que se graban correctamente
// en memoria y se ha podido comprobar uno a
// uno que se han creado correctamente.
// No obstante algunos valores ASCII hacen que
// la salida en fichero de texto sea menos
// legible por lo que se recomienda evitarlos
// en los nombres de los atributos.

#include "ts2006.h"

ts2006* gestor;


void comprobar_errores(string strReferencia)
{
	int idult;
	// consultar id �ltimo error
	idult=gestor->
	 consultar_id_ultimo_error();
	if (idult!=0)
	{
		// si hay error, informar
		cout << "-DETECTADO ERROR-" <<
		 endl;
		cout << "Punto de debug: " << 
		 strReferencia << endl;
		cout << "Descripci�n del error: "
		 << gestor->
		 consultar_descripcion_ultimo_error()
		 << endl;
		gestor->
		resetear_ultimo_error();
	}
}

int main() {
	int devuelto;
	int id;
	int i;
    int veces;
	int diferentes;
	int idchar;
    char nombre_atributo[2];
	string nombre;
	

	// Aqui indicamos cuantas veces
	// queremos repetir el bucle
	// de la prueba
	veces=3000;

	// creaci�n del gestor
	gestor=new ts2006(); 


	// creaci�n de una tabla
	id=gestor->crear_tabla();
	comprobar_errores ("1");

	// creaci�n de entradas
	devuelto=gestor->crear_entrada(id,"prueba");
	comprobar_errores ("2");

	// asignar tipo de entrada
	devuelto=gestor->
	 asignar_tipo_entrada(id,"prueba","tipopruebas");
	comprobar_errores ("3");

	cout << "Inicio del bucle..." << endl;
	diferentes=0;
    for(i = 1; i <= 255; i++)
    {
		idchar=i;
		nombre_atributo[0]=idchar;
		nombre_atributo[1]=0;

        nombre=nombre_atributo;

	  // creaci�n de atributo

	    devuelto=gestor->crear_atributo_cadena(id,
	     "prueba",nombre,"algo");
	    comprobar_errores ("4");
		if (gestor->existe_atributo(id,"prueba",nombre)==1)
		{
		  cout << "No se escribio bien la cadena "
		   << idchar << endl;
		}

	}
	cout << "Fin del bucle..." << endl;
	cout << "Escribiendo tabla..." << endl;
    devuelto=gestor->escribir_tabla(id,"prueba.txt");
    comprobar_errores ("6");
	delete gestor; // destrucci�n del gestor


	return 0;
}
