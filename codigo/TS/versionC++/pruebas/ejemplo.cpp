#include "ts2006.h"

int main() {
	int devuelto;

	string strdevuelto; 
    ts2006* gestor;

	gestor=new ts2006(); // creacion del gestor

	// creacion de tablas
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvio " << devuelto << endl;
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvio " << devuelto << endl;
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvio " << devuelto << endl;
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvio " << devuelto << endl;
	devuelto=gestor->crear_tabla();
	cout << "crear_tabla() devolvio " << devuelto << endl;

	// creacion de entradas
	devuelto=gestor->crear_entrada(1,"algo");
	cout << "crear_entrada(1,'algo') devolvio " << devuelto << endl;

	devuelto=gestor->crear_entrada(1,"goal");
	cout << "crear_entrada(1,'goal') devolvio " << devuelto << endl;

	devuelto=gestor->crear_entrada(1,"lago");
	cout << "crear_entrada(1,'lago') devolvio " << devuelto << endl;

	// asignar tipo de entrada
	devuelto=gestor->asignar_tipo_entrada(1,"lago","variable");
	cout << "asignar_tipo_entrada(1,'lago','variable') devolvio " << devuelto << endl;

	// consultar tipo de entrada
	strdevuelto=gestor->consultar_tipo_entrada(1,"lago");
	cout << "consultar_tipo_entrada(1,'lago') devolvio " << strdevuelto.c_str() << endl;

	// creacion de atributos
	devuelto=gestor->crear_atributo_cadena(1,"lago","nombrecadena","algo");
	cout << "crear_atributo_cadena(1,'lago','nombrecadena','algo') devolvio " << devuelto << endl;

	devuelto=gestor->crear_atributo_cadena(1,"lago","nombrecadena2","algo2");
	cout << "crear_atributo_cadena(1,'lago','nombrecadena2','algo2') devolvio " << devuelto << endl;

	// cambiar valor a los atributos
	devuelto=gestor->asignar_valor_atributo_cadena(1,"lago","nombrecadena2","nuevo");
	cout << "asignar_valor_atributo_cadena(1,'lago','nombrecadena2','nuevo') devolvio " << devuelto << endl;

	devuelto=gestor->crear_atributo_entero(1,"lago","nombreentero",1);
	cout << "crear_atributo_entero(1,'lago','nombreentero',1) devolvio " << devuelto << endl;

	devuelto=gestor->crear_atributo_entero(1,"lago","nombreentero2",2);
	cout << "crear_atributo_entero(1,'lago','nombreentero2',2) devolvio " << devuelto << endl;

	devuelto=gestor->asignar_valor_atributo_entero(1,"lago","nombreentero2",3);
	cout << "asignar_valor_atributo_entero(1,'lago','nombreentero2',3) devolvio " << devuelto << endl;	

	// buscar posicion de una entrada
	devuelto=gestor->buscar_posicion_entrada(1,"lago");
	cout << "buscar_posicion_entrada(1,'lago') devolvio " << devuelto << endl;

	// operaciones por posicion
	devuelto=gestor->asignar_valor_atributo_entero2(devuelto,"nombreentero",123);
	cout << "asignar_valor_atributo_entero2(devuelto,'nombreentero',123) devolvio " << devuelto << endl;

	// escribir tabla en fichero
	devuelto=gestor->escribir_tabla(1,"prueba.txt");
	cout << "escribir_tabla(1,'prueba.txt') devolvio " << devuelto << endl;

	// destruir tablas
	devuelto=gestor->destruir_tabla(5);
	cout << "destruir_tabla_tabla(5) devolvio " << devuelto << endl;
	devuelto=gestor->destruir_tabla(4);
	cout << "destruir_tabla_tabla(4) devolvio " << devuelto << endl;
	devuelto=gestor->destruir_tabla(3);
	cout << "destruir_tabla_tabla(3) devolvio " << devuelto << endl;
	devuelto=gestor->destruir_tabla(2);
	cout << "destruir_tabla_tabla(2) devolvio " << devuelto << endl;
	devuelto=gestor->destruir_tabla(1);
	cout << "destruir_tabla_tabla(1) devolvio " << devuelto << endl;

	// consultar ultimo error
	strdevuelto=gestor->consultar_descripcion_ultimo_error();
	cout << "consultar_descripcion_ultimo_error() devolvio : \n   " << strdevuelto.c_str() << endl;

	delete gestor; // destruccion del gestor
   
	return 0;
}
