// Prueba 02: "Un poco de todo"
// ---------------------------------

// El objetivo de esta prueba es comprobar
// que las funciones principales funcionan
// correctamente en la versión C++

#include "ts2006.h"

int main() {
	int devuelto;

	string strdevuelto; 
    ts2006* gestor;

	// creación del gestor
	gestor=new ts2006(); 

	// creación de tablas
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvió " << 
	 devuelto << endl;
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvió " << 
	 devuelto << endl;
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvió " << 
	 devuelto << endl;
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvió " << 
	 devuelto << endl;
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvió " << 
	 devuelto << endl;

	// creación de entradas
	devuelto=gestor->crear_entrada(1,"algo");
	cout << "crear_entrada(1,'algo') devolvió " 
	 << devuelto << endl;

	devuelto=gestor->crear_entrada(1,"goal");
	cout << "crear_entrada(1,'goal') devolvió " 
	 << devuelto << endl;

	devuelto=gestor->crear_entrada(1,"lago");
	cout << "crear_entrada(1,'lago') devolvió " 
	 << devuelto << endl;

	// asignar tipo de entrada
	devuelto=gestor->
	 asignar_tipo_entrada(1,"lago","variable");
	cout << "asignar_tipo_entrada(1,'lago',"
	 "'variable') devolvió " << devuelto << endl;

	// consultar tipo de entrada
	strdevuelto=gestor->consultar_tipo_entrada(
	 1,"lago");
	cout << "consultar_tipo_entrada(1,"
	 "'lago') devolvió " << 
	 strdevuelto.c_str() << endl;

	// creación de atributos
	devuelto=gestor->crear_atributo_cadena(1,
	 "lago","nombrecadena","algo");
	cout << "crear_atributo_cadena(1,'lago',"
	 "'nombrecadena','algo') devolvió " 
	 << devuelto << endl;

	devuelto=gestor->crear_atributo_cadena(1,
	 "lago","nombrecadena2","algo2");
	cout << "crear_atributo_cadena(1,'lago',"
	 "'nombrecadena2','algo2') devolvió " <<
	 devuelto << endl;

	// cambiar valor a los atributos
	devuelto=gestor->
	 asignar_valor_atributo_cadena(1,"lago",
	 "nombrecadena2","nuevo");
	cout << "asignar_valor_atributo_cadena(1,"
	 "'lago','nombrecadena2','nuevo') devolvió " 
	 << devuelto << endl;

	devuelto=gestor->crear_atributo_entero(1,
	 "lago","nombreentero",1);
	cout << "crear_atributo_entero(1,'lago',"
	 "'nombreentero',1) devolvió " 
	 << devuelto << endl;

	devuelto=gestor->crear_atributo_entero(1,
	 "lago","nombreentero2",2);
	cout << "crear_atributo_entero(1,'lago',"
	 "'nombreentero2',2) devolvió " 
	 << devuelto << endl;

	devuelto=gestor->
	 asignar_valor_atributo_entero(1,
	 "lago","nombreentero2",3);
	cout << "asignar_valor_atributo_entero(1,"
	 "'lago','nombreentero2',3) devolvió " 
	 << devuelto << endl;	

	// buscar posición de una entrada
	devuelto=gestor->buscar_posicion_entrada(
	 1,"lago");
	cout << "buscar_posicion_entrada(1,"
	 "'lago') devolvió " << devuelto << endl;

	// operaciones por posición
	devuelto=gestor->
	asignar_valor_atributo_entero2(devuelto,
	"nombreentero",123);
	cout << "asignar_valor_atributo_entero2("
	 "devuelto,'nombreentero',123) devolvió " 
	 << devuelto << endl;

	// escribir tabla en fichero
	devuelto=gestor->escribir_tabla(1,
	 "prueba.txt");
	cout << "escribir_tabla(1,"
	 "'prueba.txt') devolvió "
	 << devuelto << endl;

	// destruir tablas
	devuelto=gestor->destruir_tabla(5);
	cout << "destruir_tabla_tabla(5) devolvió " 
	 << devuelto << endl;
	devuelto=gestor->destruir_tabla(4);
	cout << "destruir_tabla_tabla(4) devolvió " 
	 << devuelto << endl;
	devuelto=gestor->destruir_tabla(3);
	cout << "destruir_tabla_tabla(3) devolvió " 
	 << devuelto << endl;
	devuelto=gestor->destruir_tabla(2);
	cout << "destruir_tabla_tabla(2) devolvió " 
	 << devuelto << endl;
	devuelto=gestor->destruir_tabla(1);
	cout << "destruir_tabla_tabla(1) devolvió " 
	 << devuelto << endl;

	// consultar último error
	strdevuelto=gestor->
	 consultar_descripcion_ultimo_error();
	cout << "consultar_descripcion_ultimo_error()"
	 " devolvió: \n   " 
	 << strdevuelto.c_str() << endl;

	delete gestor; // destrucción del gestor
   
	return 0;
}
