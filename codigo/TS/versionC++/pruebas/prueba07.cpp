// Prueba 07: "Reescribiendo una tabla"
// ---------------------------------

// Se analizar� que ocurre al usar la funci�n 
// escribir_tabla 1000 veces seguidas
// dentro de un bucle.

// Se ha probado a dejarlo ejecut�ndose 
// hasta el final y no se observa ning�n 
// problema en el contenido del fichero. 
// La funci�n sobrescribe 
// correctamente el fichero.


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
	string strdevuelto; 
    
	// Aqui indicamos cuantas veces
	// queremos repetir el bucle
	// de la prueba
	veces=1000;

	// creaci�n del gestor
	gestor=new ts2006(); 


    {
	// creaci�n de una tabla
	id=gestor->crear_tabla();
	comprobar_errores ("1");

	// creaci�n de entradas
	devuelto=gestor->crear_entrada(id,"algo");
	comprobar_errores ("2");
	devuelto=gestor->crear_entrada(id,"goal");
	comprobar_errores ("3");
	devuelto=gestor->crear_entrada(id,"lago");
	comprobar_errores ("4");

	// asignar tipo de entrada
	devuelto=gestor->
	 asignar_tipo_entrada(id,"lago","variable");
	comprobar_errores ("5");

	// consultar tipo de entrada
	strdevuelto=gestor->consultar_tipo_entrada(
	 id,"lago");
	comprobar_errores ("6");

	// creaci�n de atributos
	devuelto=gestor->crear_atributo_cadena(id,
	 "lago","nombrecadena","algo");
	comprobar_errores ("7");

	devuelto=gestor->crear_atributo_cadena(id,
	 "lago","nombrecadena2","algo2");
	comprobar_errores ("8");


	// cambiar valor a los atributos
	devuelto=gestor->
	 asignar_valor_atributo_cadena(id,"lago",
	 "nombrecadena2","nuevo");
	comprobar_errores ("9");

	devuelto=gestor->crear_atributo_entero(id,
	 "lago","nombreentero",1);
	comprobar_errores ("10");

	devuelto=gestor->crear_atributo_entero(id,
	 "lago","nombreentero2",2);
	comprobar_errores ("11");

	devuelto=gestor->
	 asignar_valor_atributo_entero(id,
	 "lago","nombreentero2",3);
	comprobar_errores ("12");

	// buscar posici�n de una entrada
	devuelto=gestor->buscar_posicion_entrada(
	 id,"lago");
	comprobar_errores ("13");

	// operaciones por posici�n
	devuelto=gestor->
	asignar_valor_atributo_entero2(devuelto,
	"nombreentero",123);
	comprobar_errores ("14");


	cout << "Inicio del bucle..." << endl;
    for(i = 0; i < veces; i++)
	// escribir tabla en fichero
	// dentro de un bucle
	// 1000 veces, usando mismo
	// nombre
	devuelto=gestor->escribir_tabla(id,
	 "prueba.txt");
	comprobar_errores ("15");
    cout << "...Fin del bucle." << endl;
	// destruir tabla
	devuelto=gestor->destruir_tabla(id);
	comprobar_errores ("16");
    }
    
	delete gestor; // destrucci�n del gestor
   
	return 0;
}
