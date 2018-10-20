//--------------------------------------------------------------
//
//////////////////////////////////////
// Interfaz de las clases internas  //
//////////////////////////////////////
//
// TS2006int.H
//
#ifndef _TS2006INTH
#define _TS2006INTH

// Includes necesarios, dependientes del sistema operativo:
#if defined(_WIN32)    // en Windows Visual C++

#include <iostream>
#include <fstream>
using namespace std;

#else                  // en Unix C++

#include <iostream.h>
#include <fstream.h>

#endif
// Include necesario, comun a Windows y Unix:
#include <string>

// definiciones de constantes
#define cte_espacio_hash                    53
#define cte_max_tablas              2147483647
#define cte_error_no_existe_tabla           -1
#define cte_error_ya_existe_entrada         -2
#define cte_error_no_existe_entrada         -3
#define cte_error_ya_existe_atributo        -4
#define cte_error_no_existe_atributo        -5
#define cte_error_lexema_es_null            -6
#define cte_error_alias_es_null             -7
#define cte_error_fichero_es_null           -8
#define cte_error_tipo_es_null              -9
#define cte_error_creacion_fichero         -10
#define cte_error_tipo_no_definido         -11
#define cte_error_atributo_no_entero       -12
#define cte_error_atributo_no_cadena       -13
#define cte_error_tipo_entrada_no_definido -14
#define cte_error_demasiadas_tablas        -15
#define cte_error_sin_memoria              -16
#define cte_error_atributo_cadena_es_null  -17
#define cte_error_valor_es_null            -18
#define cte_error_posicion_es_null         -19
#define cte_error_posicion_ilegal          -20

// definiciones de conjuntos
enum conj_tipo_atributo {tipo_entero,tipo_cadena};

// definiciones de uniones
union enteroocadena {
	int entero; 
	string *cadena;
} ; // almacena [entero o cadena]

class atributo // un atributo
{
	private:
		string nombre_atributo; // nombre del atributo
		enteroocadena valor; // valor
		enum conj_tipo_atributo tipo_atributo; // tipo que almacena de cara al usuario
	public:
		// Constructor
		atributo(string nombre, enum conj_tipo_atributo par_tipo);

		// Destructor
		~atributo();

		// Obtener el nombre del atributo
		string get_nombre();

		// Dar un valor a un atributo cadena
		int set_valor_cadena(string valor_cadena);

		// Dar un valor a un atributo entero
		int set_valor_entero(int valor_entero);

		// Obtener el valor de un atributo cadena
		string get_valor_cadena();

		// Obtener el valor de un atributo entero
		int get_valor_entero();

		// Obtener el tipo del atributo
		enum conj_tipo_atributo get_tipo_atributo();

		// Escribir los datos del atributo en un fichero (previamente abierto)
		void escribir_atributo(ofstream &controlador);
};

class lista_de_atributos // clase auxiliar: una lista de tablas de atributos
{
	private:
		atributo *nodo_atributo; // un puntero al atributo actual
		lista_de_atributos *siguiente; // un puntero al siguiente nodo de la lista
	public:
		// Constructor
		lista_de_atributos();

		// Destructor
		~lista_de_atributos();

		// Obtener el nodo del siguiente atributo de la lista
		lista_de_atributos* get_siguiente();

		// Obtener el puntero al atributo actual
		atributo* get_atributo();

		// Poner a que nodo debe apuntar como siguiente
		void set_siguiente(lista_de_atributos *par_siguiente);

		// Poner a que atributo debe apuntar como actual
		void set_atributo(atributo *par_atributo);

		// Buscar un atributo recursivamente, por nombre
		atributo* buscar_atributo(string nombre);
};


class entrada // una entrada
{
	private:
		string lexema; // lexema que determina la entrada
		string tipo_entrada; // tipo de entrada
		lista_de_atributos *atributos; // lista de atributos
	public:
        // Constructor
		entrada(string par_lexema);

		// Destructor
		~entrada();

		// Obtener el lexema de la entrada
		string get_lexema();

		// Obtener el tipo de la entrada
		string get_tipo_entrada();

		// Poner el tipo de la entrada
		void set_tipo_entrada(string par_tipo_entrada);

		// Añadir un atributo entero a la entrada
		int crear_atributo_entero(string alias_at, int valor_entero);

		// Añadir un atributo cadena a la entrada
		int crear_atributo_cadena(string alias_at, string valor_cadena);

		// Buscarun atributo en la entrada
		atributo* buscar_atributo(string alias_at);

		// Escribir los datos de la entrada en un fichero (previamente abierto)
		void escribir_entrada(ofstream &controlador);
};


class lista_de_entradas // clase auxiliar: una lista de tablas de entradas
{
	private:
		entrada *nodo_entrada; // un puntero a la entrada actual
		lista_de_entradas *siguiente; // un puntero al siguiente nodo de la lista
	public:
        // Constructor
		lista_de_entradas();

		// Destructor
		~lista_de_entradas();

		// Obtener el nodo de la siguiente entrada de la lista
		lista_de_entradas* get_siguiente();

		// Obtener la entrada actual
		entrada* get_entrada();

		// Poner a que nodo debe apuntar como siguiente
		void set_siguiente(lista_de_entradas *par_siguiente);

		// Poner a que entrada debe apuntar como actual
		void set_entrada(entrada *par_entrada);

		// Buscar una entrada recursivamente, por lexema
		entrada* buscar_entrada(string lexema);
};

class tabla_de_simbolos // una tabla
{
	private:
		int id; // id de la tabla
		lista_de_entradas *almacen_entradas[cte_espacio_hash]; // almacen de entradas 

		// Funcion hash, (funcion privada)
		int funcion_hash(string cadena);
	public:

		// Constructor
		tabla_de_simbolos(int par_id);

		// Destructor
		~tabla_de_simbolos();

		// Obtener el ID de la tabla
		int get_id();

		// Crear una entrada
		int crear_entrada(string lexema);

		// Buscar una entrada
		entrada* buscar_entrada(string lexema);

		// Escribir el contenido de la tabla en un fichero, dando el nombre deseado para el fichero
		int escribir_tabla(string nombre_fichero);
};

class lista_de_tablas_de_simbolos // clase auxiliar: una lista de tablas de simbolos
{
	private:
		tabla_de_simbolos *nodo_tabla; // un puntero a la tabla actual
		lista_de_tablas_de_simbolos *siguiente; // un puntero al siguiente nodo de la lista
	public:
        // Constructor
		lista_de_tablas_de_simbolos();

		// Destructor
		~lista_de_tablas_de_simbolos();

		// Obtener el nodo de la siguiente entrada de esta lista
		lista_de_tablas_de_simbolos* get_siguiente();

		// Obtener la tabla actual
		tabla_de_simbolos* get_tabla();

		// Poner a que nodo debe apuntar como siguiente
		void set_siguiente(lista_de_tablas_de_simbolos *par_siguiente);

		// Poner a que tabla debe apuntar como actual
		void set_tabla(tabla_de_simbolos *par_tabla);

		// Buscar una tabla recursivamente, por ID
		tabla_de_simbolos* buscar_tabla(int par_id);
};

#endif
