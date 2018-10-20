//--------------------------------------------------------------
//
//////////////////////////////////////
// Interfaz de la tabla de s�mbolos //
//////////////////////////////////////
// (Definiciones de las clases de las que consta la
// versi�n orientada a objetos de la Tabla de s�mbolos)
//
// TS2006.H
//
#ifndef _TS2006H
#define _TS2006H

#include "ts2006int.h"

class ts2006 // Gestor de tablas de s�mbolos
{
	private:
		lista_de_tablas_de_simbolos* tablas_de_simbolos; // Lista de tablas de s�mbolos
		int ultimo_id_error; // ID del �ltimo error que se ha producido
		int contador_tablas; // Contador de las tablas creadas
	public:
		// Constructor
   		ts2006();

		// Destructor
		~ts2006();

		// 1. GESTI�N DE TABLAS

		// Crear una tabla. Obtendremos un id
		int crear_tabla();

		// Destruir una tabla
		int destruir_tabla(int id_tabla);

		// Determinar la existencia de una tabla
		int existe_tabla(int id_tabla);

		// 2. GESTI�N DE ENTRADAS

		// Crear una entrada en una tabla
		int crear_entrada(int id_tabla, string lexema);

		// Asignar el tipo de entrada a una entrada
		int asignar_tipo_entrada(int id_tabla, string lexema, string tipo);

		// Consultar el tipo de entrada de una entrada
		string consultar_tipo_entrada(int id_tabla, string lexema);

		// Determinar si existe una entrada
		int existe_entrada(int id_tabla, string lexema);

		// 3. GESTI�N DE ATRIBUTOS

		// Crear un atributo para almacenar enteros
		int crear_atributo_entero(int id_tabla, string lexema, string alias_at, int valor);

		// Crear un atributo para almacenar cadenas
		int crear_atributo_cadena(int id_tabla, string lexema, string alias_at, string valor);

		// Asignar un nuevo valor a un atributo entero
		int asignar_valor_atributo_entero(int id_tabla, string lexema, string alias_at, int valor);

		// Asignar un nuevo valor a un atributo cadena
		int asignar_valor_atributo_cadena(int id_tabla, string lexema, string alias_at, string valor);

		// Consultar el valor de un atributo entero
		int consultar_valor_atributo_entero(int id_tabla, string lexema, string alias_at);

		// Consultar el valor de un atributo cadena
		string consultar_valor_atributo_cadena(int id_tabla, string lexema, string alias_at);

		// Determinar si existe un atributo
		int existe_atributo(int id_tabla, string lexema, string alias_at);

		// 4. GESTI�N DE FICHEROS

		// Escribir el contenido de una tabla en fichero
		int escribir_tabla(int id_tabla, string nombre_fichero);

		// 5. GESTI�N DE ERRORES

		// Obtener el ID del �ltimo error que ha ocurrido
		int consultar_id_ultimo_error();

		// Obtener la descripci�n del �ltimo error que ha ocurrido
		string consultar_descripcion_ultimo_error();

		// Resetear la variable interna que almacena el
		// �ltimo error que ha ocurrido
		void resetear_ultimo_error();

		// 6. FUNCIONES ALTERNATIVAS
		// Basicamente tienen la misma funcionalidad
		// pero manejan "posici�n"
		// en lugar de "id tabla" + "lexema"
		// Son mas eficientes, pero solo para usuarios avanzados.
		// El usuario solo introduce y recibe enteros, pero a�n as�,
		// ahora habr� que tener mucho m�s cuidado de no consultar
		// posiciones de memoria incorrectas
		// Adem�s, ser�a extremadamente peligroso intentar liberar 
		// o destruir la memoria
		// de estas posiciones de forma directa.

		// Asignar el tipo de entrada a una entrada (por posici�n)
		int asignar_tipo_entrada2(int posicion, string tipo);

		// Consultar el tipo de entrada de una entrada (por posici�n)
		string consultar_tipo_entrada2(int posicion);

		// Crear un atributo para almacenar enteros (por posici�n)
		int crear_atributo_entero2(int posicion, string alias_at, int valor);

		// Crear un atributo para almacenar cadenas (por posici�n)
		int crear_atributo_cadena2(int posicion, string alias_at, string valor);

		// Asignar un nuevo valor a un atributo entero (por posici�n)
		int asignar_valor_atributo_entero2(int posicion, string alias_at, int valor);

		// Asignar un nuevo valor a un atributo cadena (por posici�n)
		int asignar_valor_atributo_cadena2(int posicion, string alias_at, string valor);

		// Consultar el valor de un atributo entero (por posici�n)
		int consultar_valor_atributo_entero2(int posicion, string alias_at);

		// Consultar el valor de un atributo cadena (por posici�n)
		string consultar_valor_atributo_cadena2(int posicion, string alias_at);

		// Determinar si existe un atributo (por posici�n)
		int existe_atributo2(int posicion, string alias_at);

		// Buscar la posici�n de una entrada
		// (devuelve la posici�n si existe,y sino 0)
		int buscar_posicion_entrada(int id_tabla, string lexema);
};

#endif
