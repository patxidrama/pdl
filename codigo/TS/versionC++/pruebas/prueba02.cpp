// Prueba 02: "Un poco de todo"
// ---------------------------------

// El objetivo de esta prueba es comprobar
// que las funciones principales funcionan
// correctamente en la versi�n C++

#include "ts2006.h"

int main() {
	int devuelto;

	string strdevuelto; 
    ts2006* gestor;

	// creaci�n del gestor
	gestor=new ts2006(); 

	// creaci�n de tablas
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvi� " << 
	 devuelto << endl;
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvi� " << 
	 devuelto << endl;
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvi� " << 
	 devuelto << endl;
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvi� " << 
	 devuelto << endl;
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvi� " << 
	 devuelto << endl;

	// creaci�n de entradas
	devuelto=gestor->crear_entrada(1,"algo");
	cout << "crear_entrada(1,'algo') devolvi� " 
	 << devuelto << endl;

	devuelto=gestor->crear_entrada(1,"goal");
	cout << "crear_entrada(1,'goal') devolvi� " 
	 << devuelto << endl;

	devuelto=gestor->crear_entrada(1,"lago");
	cout << "crear_entrada(1,'lago') devolvi� " 
	 << devuelto << endl;

	// asignar tipo de entrada
	devuelto=gestor->
	 asignar_tipo_entrada(1,"lago","variable");
	cout << "asignar_tipo_entrada(1,'lago',"
	 "'variable') devolvi� " << devuelto << endl;

	// consultar tipo de entrada
	strdevuelto=gestor->consultar_tipo_entrada(
	 1,"lago");
	cout << "consultar_tipo_entrada(1,"
	 "'lago') devolvi� " << 
	 strdevuelto.c_str() << endl;

	// creaci�n de atributos
	devuelto=gestor->crear_atributo_cadena(1,
	 "lago","nombrecadena","algo");
	cout << "crear_atributo_cadena(1,'lago',"
	 "'nombrecadena','algo') devolvi� " 
	 << devuelto << endl;

	devuelto=gestor->crear_atributo_cadena(1,
	 "lago","nombrecadena2","algo2");
	cout << "crear_atributo_cadena(1,'lago',"
	 "'nombrecadena2','algo2') devolvi� " <<
	 devuelto << endl;

	// cambiar valor a los atributos
	devuelto=gestor->
	 asignar_valor_atributo_cadena(1,"lago",
	 "nombrecadena2","nuevo");
	cout << "asignar_valor_atributo_cadena(1,"
	 "'lago','nombrecadena2','nuevo') devolvi� " 
	 << devuelto << endl;

	devuelto=gestor->crear_atributo_entero(1,
	 "lago","nombreentero",1);
	cout << "crear_atributo_entero(1,'lago',"
	 "'nombreentero',1) devolvi� " 
	 << devuelto << endl;

	devuelto=gestor->crear_atributo_entero(1,
	 "lago","nombreentero2",2);
	cout << "crear_atributo_entero(1,'lago',"
	 "'nombreentero2',2) devolvi� " 
	 << devuelto << endl;

	devuelto=gestor->
	 asignar_valor_atributo_entero(1,
	 "lago","nombreentero2",3);
	cout << "asignar_valor_atributo_entero(1,"
	 "'lago','nombreentero2',3) devolvi� " 
	 << devuelto << endl;	

	// buscar posici�n de una entrada
	devuelto=gestor->buscar_posicion_entrada(
	 1,"lago");
	cout << "buscar_posicion_entrada(1,"
	 "'lago') devolvi� " << devuelto << endl;

	// operaciones por posici�n
	devuelto=gestor->
	asignar_valor_atributo_entero2(devuelto,
	"nombreentero",123);
	cout << "asignar_valor_atributo_entero2("
	 "devuelto,'nombreentero',123) devolvi� " 
	 << devuelto << endl;

	// escribir tabla en fichero
	devuelto=gestor->escribir_tabla(1,
	 "prueba.txt");
	cout << "escribir_tabla(1,"
	 "'prueba.txt') devolvi� "
	 << devuelto << endl;

	// destruir tablas
	devuelto=gestor->destruir_tabla(5);
	cout << "destruir_tabla_tabla(5) devolvi� " 
	 << devuelto << endl;
	devuelto=gestor->destruir_tabla(4);
	cout << "destruir_tabla_tabla(4) devolvi� " 
	 << devuelto << endl;
	devuelto=gestor->destruir_tabla(3);
	cout << "destruir_tabla_tabla(3) devolvi� " 
	 << devuelto << endl;
	devuelto=gestor->destruir_tabla(2);
	cout << "destruir_tabla_tabla(2) devolvi� " 
	 << devuelto << endl;
	devuelto=gestor->destruir_tabla(1);
	cout << "destruir_tabla_tabla(1) devolvi� " 
	 << devuelto << endl;

	// consultar �ltimo error
	strdevuelto=gestor->
	 consultar_descripcion_ultimo_error();
	cout << "consultar_descripcion_ultimo_error()"
	 " devolvi�: \n   " 
	 << strdevuelto.c_str() << endl;

	delete gestor; // destrucci�n del gestor
   
	return 0;
}
