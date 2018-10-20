// Prueba 10: "Contenido muy grande"
// ---------------------------------

// Se analizará que ocurre al intentar 
// escribir una cadena extremadamente larga
// como valor de un atributo.
// En concreto la longitud será de 50000 bytes.

#include "ts2006.h"

// Aqui indicamos la longitud
// de la cadena que escribiremos
// como valor en el atributo
// de esta prueba
const int longatr=50000;

ts2006* gestor;


void comprobar_errores(string strReferencia)
{
	int idult;
	// consultar id último error
	idult=gestor->
	 consultar_id_ultimo_error();
	if (idult!=0)
	{
		// si hay error, informar
		cout << "-DETECTADO ERROR-" <<
		 endl;
		cout << "Punto de debug: " << 
		 strReferencia << endl;
		cout << "Descripción del error: "
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
	int idchar;
    char valor_atributo[longatr+1];
	string elvalor;
	
	// creación del gestor
	gestor=new ts2006(); 


	// creación de una tabla
	id=gestor->crear_tabla();
	comprobar_errores ("1");

	// creación de entradas
	devuelto=gestor->crear_entrada(id,"prueba");
	comprobar_errores ("2");

	// asignar tipo de entrada
	devuelto=gestor->
	 asignar_tipo_entrada(id,"prueba","tipopruebas");
	comprobar_errores ("3");

    cout << "Creando atributo..." << endl;

	// el valor del atributo
    // sera una cadena con muchas letras A
    for(i = 0; i <= longatr-1; i++)
    {
		valor_atributo[i]=97; // letra A
	}
	valor_atributo[longatr]=0;
    elvalor=valor_atributo;

	// creación de atributo
	devuelto=gestor->crear_atributo_cadena(id,
	     "prueba","algo",elvalor);
	comprobar_errores ("4");
	cout << "Escribiendo tabla..." << endl;
    devuelto=gestor->escribir_tabla(id,"prueba.txt");
    comprobar_errores ("5");
	delete gestor; // destrucción del gestor


	return 0;
}
