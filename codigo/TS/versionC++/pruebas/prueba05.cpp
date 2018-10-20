// Prueba 05: "Captura de errores simplificada"
// ---------------------------------

// El objetivo de esta prueba es comprobar
// que se puede detectar donde se
// producen errores de forma
// sencilla si detras de cada llamada
// al gestor siempre comprobamos
// el último error y luego reseteamos
// el último error.
// Se pondrá para que ocurran
// algunos errores intenciondamente.

#include "ts2006.h"

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

	string strdevuelto; 
    

	// creación del gestor
	gestor=new ts2006(); 

	// creación de tablas
	devuelto=gestor->crear_tabla();
	comprobar_errores ("1");
	devuelto=gestor->crear_tabla();
	comprobar_errores ("2");
	devuelto=gestor->crear_tabla();
	comprobar_errores ("3");
	devuelto=gestor->crear_tabla();
	comprobar_errores ("4");
	devuelto=gestor->crear_tabla();
	comprobar_errores ("5");

	// creación de entradas
	devuelto=gestor->crear_entrada(1,"algo");
	comprobar_errores ("6");
	devuelto=gestor->crear_entrada(1,"goal");
	comprobar_errores ("7");
	devuelto=gestor->crear_entrada(1,"lago");
	comprobar_errores ("8");
	// se introduce un error aquí:
	// la entrada algo ya existe en tabla 1
	devuelto=gestor->crear_entrada(1,"algo");
	comprobar_errores ("9");

	// asignar tipo de entrada
	devuelto=gestor->
	 asignar_tipo_entrada(1,"lago","variable");
	comprobar_errores ("10");

	// consultar tipo de entrada
	strdevuelto=gestor->consultar_tipo_entrada(
	 1,"lago");
	comprobar_errores ("11");

	// creación de atributos
	devuelto=gestor->crear_atributo_cadena(1,
	 "lago","nombrecadena","algo");
	comprobar_errores ("12");

	devuelto=gestor->crear_atributo_cadena(1,
	 "lago","nombrecadena2","algo2");
	comprobar_errores ("13");

	// se introduce otro error aquí:
	// el atributo algo2 ya existe
	// en esa entrada
	devuelto=gestor->crear_atributo_cadena(1,
	 "lago","nombrecadena2","algo2");
	comprobar_errores ("14");

	// cambiar valor a los atributos
	devuelto=gestor->
	 asignar_valor_atributo_cadena(1,"lago",
	 "nombrecadena2","nuevo");
	comprobar_errores ("15");

	devuelto=gestor->crear_atributo_entero(1,
	 "lago","nombreentero",1);
	comprobar_errores ("16");

	devuelto=gestor->crear_atributo_entero(1,
	 "lago","nombreentero2",2);
	comprobar_errores ("17");

	devuelto=gestor->
	 asignar_valor_atributo_entero(1,
	 "lago","nombreentero2",3);
	comprobar_errores ("18");

	// buscar posición de una entrada
	devuelto=gestor->buscar_posicion_entrada(
	 1,"lago");
	comprobar_errores ("19");

	// operaciones por posición
	devuelto=gestor->
	asignar_valor_atributo_entero2(devuelto,
	"nombreentero",123);
	comprobar_errores ("20");


	// escribir tabla en fichero
	devuelto=gestor->escribir_tabla(1,
	 "prueba.txt");
	comprobar_errores ("21");

	// destruir tablas
	devuelto=gestor->destruir_tabla(5);
	comprobar_errores ("22");

	devuelto=gestor->destruir_tabla(4);
	comprobar_errores ("23");

	devuelto=gestor->destruir_tabla(3);
	comprobar_errores ("24");

	devuelto=gestor->destruir_tabla(2);
	comprobar_errores ("25");

	devuelto=gestor->destruir_tabla(1);
	comprobar_errores ("26");

	// se introduce otro error aquí:
	// se intentará destruir una
	// tabla ya destruida
	devuelto=gestor->destruir_tabla(4);
	comprobar_errores ("27");

	delete gestor; // destrucción del gestor
   
	return 0;
}
