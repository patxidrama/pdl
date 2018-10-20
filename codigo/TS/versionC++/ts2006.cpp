//--------------------------------------------------------------
//
// Tabla de Símbolos 2006 - VERSION C++ orientada a objetos -
// Creada por Daniel Peña Vázquez
// Supervisada por José Luis Fuertes Castro

// Este código es C++ estándar.
// Gracias a ello, se puede compilar correctamente y sin warnings 
// al menos en los siguientes compiladores:
// - G++  ( GNU C++ compiler for Windows , version September 13, 2005 )
// - BCC32 ( probado en la versión Borland C++ 5.5.1 )
// - Microsoft Visual C++ ( probado en la versión 6.0 )

// Nota: las cadenas que maneja esta tabla de simbolos son case-sensitive
// (no es lo mismo mayusculas que minusculas)
//
//
// Implementaciones de las clases de las que consta nuestra
// version orientada a objetos de la Tabla de simbolos
//
// TS2006.CPP
//
#include "ts2006.h"

// Implementacion clase TS2006

// 1. GESTION DE TABLAS

ts2006::ts2006()
{
// Constructor del gestor
	tablas_de_simbolos = NULL;
    ultimo_id_error = 0; // ID del último error que se ha producido
    contador_tablas = 0; // Contador de las tablas creadas
}


ts2006::~ts2006()
{
// Destructor del gestor
	lista_de_tablas_de_simbolos* punterolista;
	lista_de_tablas_de_simbolos* punterolista2;
	punterolista=tablas_de_simbolos;
	// borramos toda la lista de tablas
	while (punterolista!=NULL)
	{
		punterolista2=punterolista;
		punterolista=punterolista->get_siguiente();
		delete punterolista2;
	}
}


// ************** Crear una tabla de símbolos ******************************************
// Proceso DFD  : 1.1
// ID Requisito : REQ04
// Entrada      : <nada>
//
// Salida       : - Identificador de la tabla creada (número positivo) si se creó.
//                - Devuelve -1 si se produce un error.
// Descripción  : Crea una nueva tabla de símbolos y
//                 devuelve el identificador que se le ha asignado.
// *************************************************************************************
int ts2006::crear_tabla()
{
	tabla_de_simbolos* tabla;
	lista_de_tablas_de_simbolos* punterolista;
	lista_de_tablas_de_simbolos* nodolista;
	if (contador_tablas == cte_max_tablas)
	{
		ultimo_id_error = cte_error_demasiadas_tablas; // Error: se han creado demasiadas tablas 
		return -1;
	}
	contador_tablas=contador_tablas+1;
	tabla=new tabla_de_simbolos(contador_tablas);
	if (!tabla)
	{
		ultimo_id_error = cte_error_sin_memoria; // Error: sin memoria para el new
		return -1;
	}

	nodolista=new lista_de_tablas_de_simbolos;
	if (!nodolista)
	{
		delete tabla;
		ultimo_id_error = cte_error_sin_memoria; // Error: sin memoria para el new
		return -1;
	}

	nodolista->set_tabla(tabla);
    nodolista->set_siguiente(NULL);

	punterolista=tablas_de_simbolos;
    if (punterolista==NULL)
	{
		tablas_de_simbolos=nodolista;
	}
    else
	{
		punterolista=tablas_de_simbolos;
		while (punterolista->get_siguiente() != NULL) // Buscamos el final de la lista
		{
			punterolista = punterolista->get_siguiente();
		}
        punterolista->set_siguiente(nodolista);
    }
	return contador_tablas; // devolvemos al usuario el ID de la tabla que acabamos de crear
}

// ************** Destruir una tabla de símbolos ***************************************
// Proceso DFD  : 1.2
// ID Requisito : REQ05
// Cabecera     : int destruir_tabla(int id_tabla);
// Entrada      : - Identificador de la tabla que se quiere destruir.
//
// Salida       : - Devuelve 0 si la operación se realizó correctamente.
//                - Devuelve -1 si se produce un error.
// Descripción  : Se destruye la tabla indicada.
// *************************************************************************************
int ts2006::destruir_tabla(int id_tabla)
{
	lista_de_tablas_de_simbolos* punterolista;
	lista_de_tablas_de_simbolos* siguiente;
	lista_de_tablas_de_simbolos* previo = NULL;

	int resultado=-1;
	punterolista=tablas_de_simbolos;
    while (punterolista != NULL)
	{
		siguiente=punterolista->get_siguiente();
		if (punterolista->get_tabla()->get_id() == id_tabla)
		{
			if (previo == NULL)
			{
				tablas_de_simbolos=siguiente;
			}
			else
			{
				previo->set_siguiente(siguiente);
			}
			delete punterolista;
			punterolista=siguiente;
			resultado=0;
		}
		else
		{
			previo=punterolista;
			punterolista=siguiente;
		}
	}	
	if (resultado==-1)
	{
		ultimo_id_error = cte_error_no_existe_tabla; // Error: no existe la tabla indicada
	}
	return resultado;
}


// ************** Determinar la existencia de una tabla de símbolos ********************
// Proceso DFD  : 1.3
// ID Requisito : REQ15
// Entrada      : - Identificador de la tabla que se quiere consultar.
//
// Salida       : - Devuelve 0 si existe.
//                - Devuelve 1 si no existe. 
//                - Devuelve -1 si se produce un error.
// Descripción  : Determina si una tabla existe 
//                 (ya fue creada y aun no ha sido destruida)
// *************************************************************************************
int ts2006::existe_tabla(int id_tabla)
{
	if (tablas_de_simbolos->buscar_tabla(id_tabla) == NULL )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// 2. GESTION DE ENTRADAS

// ************** Crear una nueva entrada **********************************************
// Proceso DFD  : 2.1
// ID Requisito : REQ06
// Entrada      : - Identificador de la tabla donde se quiere crear la entrada.
//                - Lexema que se quiere insertar en la nueva entrada.
//
// Salida       : - Devuelve 0 si la operación se realizó correctamente.
//                - Devuelve -1 si se produce un error.
// Descripción  : Crea una nueva entrada en la tabla indicada
//                 con el lexema indicado. 
// *************************************************************************************
int ts2006::crear_entrada(int id_tabla, string lexema)
{
	tabla_de_simbolos* tabla;
	int resultado;
	tabla=tablas_de_simbolos->buscar_tabla(id_tabla);
	if (tabla==NULL)
	{
		ultimo_id_error = cte_error_no_existe_tabla; // Error: no existe la tabla indicada
		return -1;
	}
	else
	{
		resultado=tabla->crear_entrada(lexema);
		if (resultado == -1)
		{
			ultimo_id_error = cte_error_ya_existe_entrada; // Ya existe una entrada con ese lexema en esa tabla
		}
		if (resultado == -2)
		{
			ultimo_id_error = cte_error_sin_memoria; // Error: sin memoria para la nueva entrada
			resultado = -1;
		}
		return resultado;
	}
}

// ************** Asignar el tipo de entrada a una entrada *****************************
// Proceso DFD  : 2.2
// ID Requisito : REQ07
// Entrada      : - Identificador de la tabla de símbolos de la entrada.
//                - Lexema de la entrada.
//                - Tipo que se le quiere dar a la entrada.
//
// Salida       : - Devuelve 0 si la operación se realizó correctamente.
//                - Devuelve -1 si se produce un error.
// Descripción  : Asigna un tipo a una entrada existente.
// *************************************************************************************
int ts2006::asignar_tipo_entrada(int id_tabla, string lexema, string tipo)
{
	tabla_de_simbolos* tabla;
	entrada* la_entrada;
	tabla=tablas_de_simbolos->buscar_tabla(id_tabla);
	if (tabla==NULL)
	{
		ultimo_id_error = cte_error_no_existe_tabla; // Error: no existe la tabla indicada
		return -1;
	}
	else
	{
		la_entrada=tabla->buscar_entrada(lexema);
		if (la_entrada==NULL)
		{
			ultimo_id_error = cte_error_no_existe_entrada; // No existe una entrada con ese lexema en esa tabla
			return -1;
		}
		else
		{
			la_entrada->set_tipo_entrada(tipo);
			return 0;
		}
	}
}

// ************** Consultar el tipo de entrada de una entrada **************************
// Proceso DFD  : 2.3
// ID Requisito : REQ08
// Entrada      : - Identificador de la tabla de símbolos de la entrada.
//                - Lexema de la entrada.
//
// Salida       : - Devuelve tipo de la entrada si se ha definido uno y no hay errores.
//                - Devuelve "" si se produce un error.
// Descripción  : Consulta el tipo de una entrada.
// *************************************************************************************
string ts2006::consultar_tipo_entrada(int id_tabla, string lexema)
{
	tabla_de_simbolos* tabla;
	entrada* la_entrada;
	tabla=tablas_de_simbolos->buscar_tabla(id_tabla);
	if (tabla==NULL)
	{
		ultimo_id_error = cte_error_no_existe_tabla; // Error: no existe la tabla indicada
		return "";
	}
	else
	{
		la_entrada=tabla->buscar_entrada(lexema);
		if (la_entrada==NULL)
		{
			ultimo_id_error = cte_error_no_existe_entrada; // No existe una entrada con ese lexema en esa tabla
			return "";
		}
		else
		{
			return la_entrada->get_tipo_entrada();
		}
	}
}

// ************** Determinar la existencia de una entrada ******************************
// Proceso DFD  : 2.4
// ID Requisito : REQ16
// Entrada      : - Identificador de la tabla de símbolos de la entrada.
//                - Lexema de la entrada.
//
// Salida       : - Devuelve 0 si existe.
//                - Devuelve 1 si no existe.
//                - Devuelve -1 si se produce un error.
// Descripción  : Determina si una entrada existe 
//                 ( fue ya creada y aun no se ha destruido su tabla )
// *************************************************************************************
int ts2006::existe_entrada(int id_tabla, string lexema)
{
	tabla_de_simbolos* tabla;
	entrada* la_entrada;
	tabla=tablas_de_simbolos->buscar_tabla(id_tabla);
	if (tabla==NULL)
	{
		return 1;
	}
	else
	{
		la_entrada=tabla->buscar_entrada(lexema);
		if (la_entrada==NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}


// 3. GESTION DE ATRIBUTOS

// ************** Crear un atributo entero en una entrada ******************************
// Proceso DFD  : 3.1
// ID Requisito : REQ09
// Entrada      : - Identificador de la tabla de símbolos de la entrada.
//                - Lexema de la entrada.
//                - Alias del atributo (ejemplos: "desplazamiento", "ancho","tabla")
//                - Valor inicial para el atributo que estamos 
//                   creando (ejemplos: 16, 48, 3)
//
// Salida       : - Devuelve 0 si la operación se realizó correctamente.
//                - Devuelve -1 si se produce un error.
// Descripción  : Crea un nuevo atributo en la entrada, con el alias indicado. 
//                 Este atributo solo podrá almacenar valores enteros (tipo int de C++)
// *************************************************************************************
int ts2006::crear_atributo_entero(int id_tabla, string lexema, string alias_at, int valor)
{
	tabla_de_simbolos* tabla;
	entrada* la_entrada;
	int resultado;

	tabla=tablas_de_simbolos->buscar_tabla(id_tabla);
	if (tabla==NULL)
	{
		ultimo_id_error = cte_error_no_existe_tabla; // Error: no existe la tabla indicada
		return -1;
	}
	else
	{
		la_entrada=tabla->buscar_entrada(lexema);
		if (la_entrada==NULL)
		{
			ultimo_id_error = cte_error_no_existe_entrada; // No existe una entrada con ese lexema en esa tabla
			return -1;
		}
		else
		{
			resultado=la_entrada->crear_atributo_entero(alias_at,valor);
			if (resultado==-1)
			{
				// ya existia
				ultimo_id_error = cte_error_ya_existe_atributo; // Ya existia el atributo. No se ha modificado.
			}
			if (resultado==-2)
			{
				// sin memoria
				ultimo_id_error = cte_error_sin_memoria; // Error: memoria agotada 
				resultado=-1;
			}
			return resultado;
		}
	}
}

// ************** Crear un atributo cadena en una entrada ******************************
// Proceso DFD  : 3.2
// ID Requisito : REQ10
// Entrada      : - Identificador de la tabla de símbolos de la entrada.
//                - Lexema de la entrada.
//                - Alias del atributo (ejemplos: "cadena", "real","cosa")
//                - Valor inicial para el atributo que estamos 
//                  creando (ejemplos: "algo", "12.345", "123abcd")
//
// Salida       : - Devuelve 0 si la operación se realizó correctamente.
//                - Devuelve -1 si se produce un error.
// Descripción  : Crea un nuevo atributo en la entrada, con el alias indicado. 
//                 Este atributo solo podrá almacenar cadenas (tipo string de C++)
// *************************************************************************************
int ts2006::crear_atributo_cadena(int id_tabla, string lexema, string alias_at, string valor)
{
	tabla_de_simbolos* tabla;
	entrada* la_entrada;
	int resultado;

	tabla=tablas_de_simbolos->buscar_tabla(id_tabla);
	if (tabla==NULL)
	{
		ultimo_id_error = cte_error_no_existe_tabla; // Error: no existe la tabla indicada
		return -1;
	}
	else
	{
		la_entrada=tabla->buscar_entrada(lexema);
		if (la_entrada==NULL)
		{
			ultimo_id_error = cte_error_no_existe_entrada; // No existe una entrada con ese lexema en esa tabla
			return -1;
		}
		else
		{
			resultado=la_entrada->crear_atributo_cadena(alias_at,valor);
			if (resultado==-1)
			{
				// ya existia
				ultimo_id_error = cte_error_ya_existe_atributo; // Ya existia el atributo. No se ha modificado.
			}
			if (resultado==-2)
			{
				// sin memoria
				ultimo_id_error = cte_error_sin_memoria; // Error: memoria agotada 
				resultado=-1;
			}
			return resultado;
		}
	}
}

// ************** Asignar el valor de un atributo entero *******************************
// Proceso DFD  : 3.3
// ID Requisito : REQ11
// Entrada      : - Identificador de la tabla de símbolos de la entrada.
//                - Lexema de la entrada.
//                - Alias del atributo.
//                - Nuevo valor que se quiere escribir en ese atributo (un entero)
//
// Salida       : - Devuelve 0 si la operación se realizó correctamente.
//                - Devuelve -1 si se produce un error.
// Descripción  : Da un valor al atributo (entero) de alias indicado en la 
//                 entrada indicada (sobrescribe el valor antiguo)
// *************************************************************************************
int ts2006::asignar_valor_atributo_entero(int id_tabla, string lexema, string alias_at, int valor)
{
	tabla_de_simbolos* tabla;
	entrada* la_entrada;
	atributo* el_atributo;
	int resultado;

	tabla=tablas_de_simbolos->buscar_tabla(id_tabla);
	if (tabla==NULL)
	{
		ultimo_id_error = cte_error_no_existe_tabla; // Error: no existe la tabla indicada
		return -1;
	}
	else
	{
		la_entrada=tabla->buscar_entrada(lexema);
		if (la_entrada==NULL)
		{
			ultimo_id_error = cte_error_no_existe_entrada; // No existe una entrada con ese lexema en esa tabla
			return -1;
		}
		else
		{
			el_atributo=la_entrada->buscar_atributo(alias_at);
			if (el_atributo == NULL)
			{
				ultimo_id_error = cte_error_no_existe_atributo; // No existia el atributo.
				return -1;
			}

			if (el_atributo->get_tipo_atributo() != tipo_entero)
			{
				ultimo_id_error = cte_error_atributo_no_entero; // El atributo existe pero no es del tipo entero
				return -1;
			}

			resultado=el_atributo->set_valor_entero(valor);
			if (resultado<0)
			{
				ultimo_id_error = cte_error_sin_memoria; // Error: memoria agotada 
				resultado=-1;
			}
			return resultado;
		}
	}
}

// ************** Asignar el valor de un atributo cadena *******************************
// Proceso DFD  : 3.4
// ID Requisito : REQ12
// Entrada      : - Identificador de la tabla de símbolos de la entrada.
//                - Lexema de la entrada.
//                - Alias del atributo.
//                - Nuevo valor que se quiere escribir en ese atributo (una cadena)

// Salida       : - Devuelve 0 si la operación se realizó correctamente.
//                - Devuelve -1 si se produce un error.
// Descripción  : Da un valor al atributo (cadena) de alias indicado en la entrada 
//                 indicada (sobrescribe el valor antiguo)
// *************************************************************************************
int ts2006::asignar_valor_atributo_cadena(int id_tabla, string lexema, string alias_at, string valor)
{
	tabla_de_simbolos* tabla;
	entrada* la_entrada;
	atributo* el_atributo;
	int resultado;

	tabla=tablas_de_simbolos->buscar_tabla(id_tabla);
	if (tabla==NULL)
	{
		ultimo_id_error = cte_error_no_existe_tabla; // Error: no existe la tabla indicada
		return -1;
	}
	else
	{
		la_entrada=tabla->buscar_entrada(lexema);
		if (la_entrada==NULL)
		{
			ultimo_id_error = cte_error_no_existe_entrada; // No existe una entrada con ese lexema en esa tabla
			return -1;
		}
		else
		{
			el_atributo=la_entrada->buscar_atributo(alias_at);
			if (el_atributo == NULL)
			{
				ultimo_id_error = cte_error_no_existe_atributo; // No existia el atributo.
				return -1;
			}

			if (el_atributo->get_tipo_atributo() != tipo_cadena)
			{
				ultimo_id_error = cte_error_atributo_no_cadena; // El atributo existe pero no es del tipo cadena
				return -1;
			}

			resultado=el_atributo->set_valor_cadena(valor);
			if (resultado<0)
			{
				ultimo_id_error = cte_error_sin_memoria; // Error: memoria agotada 
				resultado=-1;
			}
			return resultado;
		}
	}
}

// ************** Consultar el valor de un atributo entero *****************************
// Proceso DFD  : 3.5
// ID Requisito : REQ13
// Entrada      : - Identificador de la tabla de símbolos de la entrada.
//                - Lexema de la entrada.
//                - Alias del atributo.
//
// Salida       : - Valor del atributo entero.
//                - Devuelve 0 y genera un error si se produce error.
// Descripción  : Consulta el valor de un atributo entero.
// *************************************************************************************
int ts2006::consultar_valor_atributo_entero(int id_tabla, string lexema, string alias_at)
{
	tabla_de_simbolos* tabla;
	entrada* la_entrada;
	atributo* el_atributo;

	tabla=tablas_de_simbolos->buscar_tabla(id_tabla);
	if (tabla==NULL)
	{
		ultimo_id_error = cte_error_no_existe_tabla; // Error: no existe la tabla indicada
		return 0;
	}
	else
	{
		la_entrada=tabla->buscar_entrada(lexema);
		if (la_entrada==NULL)
		{
			ultimo_id_error = cte_error_no_existe_entrada; // No existe una entrada con ese lexema en esa tabla
			return 0;
		}
		else
		{
			el_atributo=la_entrada->buscar_atributo(alias_at);
			if (el_atributo == NULL)
			{
				ultimo_id_error = cte_error_no_existe_atributo; // No existia el atributo.
				return 0;
			}

			if (el_atributo->get_tipo_atributo() != tipo_entero)
			{
				ultimo_id_error = cte_error_atributo_no_entero; // El atributo existe pero no es del tipo entero
				return -1;
			}

			return el_atributo->get_valor_entero();
		}
	}
}

// ************** Consultar el valor de un atributo cadena *****************************
// Proceso DFD  : 3.6
// ID Requisito : REQ14
// Entrada      : - Identificador de la tabla de símbolos de la entrada.
//                - Lexema de la entrada.
//                - Alias del atributo.
//
// Salida       : - Valor del atributo cadena.
//                - Devuelve "" y genera un error si se produce error.
// Descripción  : Consulta el valor de un atributo cadena.
// *************************************************************************************
string ts2006::consultar_valor_atributo_cadena(int id_tabla, string lexema, string alias_at)
{
	tabla_de_simbolos* tabla;
	entrada* la_entrada;
	atributo* el_atributo;

	tabla=tablas_de_simbolos->buscar_tabla(id_tabla);
	if (tabla==NULL)
	{
		ultimo_id_error = cte_error_no_existe_tabla; // Error: no existe la tabla indicada
		return "";
	}
	else
	{
		la_entrada=tabla->buscar_entrada(lexema);
		if (la_entrada==NULL)
		{
			ultimo_id_error = cte_error_no_existe_entrada; // No existe una entrada con ese lexema en esa tabla
			return "";
		}
		else
		{
			el_atributo=la_entrada->buscar_atributo(alias_at);
			if (el_atributo == NULL)
			{
				ultimo_id_error = cte_error_no_existe_atributo; // No existia el atributo.
				return "";
			}

			if (el_atributo->get_tipo_atributo() != tipo_cadena)
			{
				ultimo_id_error = cte_error_atributo_no_cadena; // El atributo existe pero no es del tipo cadena
				return "";
			}

			return el_atributo->get_valor_cadena();
		}
	}
}


// ************** Determinar la existencia de un atributo ******************************
// Proceso DFD  : 3.7
// ID Requisito : REQ17
// Entrada      : - Identificador de la tabla de símbolos de la entrada.
//                - Lexema de la entrada.
//                - Alias del atributo.
//
// Salida       : - Devuelve 0 si existe.
//                - Devuelve 1 si no existe.
//                - Devuelve -1 si se produce un error.
// Descripción  : Determina si un atributo (con el alias indicado) existe en una 
//                 determinada entrada (si existe la entrada y 
//                 aun su tabla no se ha destruido)
// *************************************************************************************
int ts2006::existe_atributo(int id_tabla, string lexema, string alias_at)
{
	tabla_de_simbolos* tabla;
	entrada* la_entrada;
	atributo* el_atributo;

	tabla=tablas_de_simbolos->buscar_tabla(id_tabla);
	if (tabla==NULL)
	{
		return 1;
	}
	else
	{
		la_entrada=tabla->buscar_entrada(lexema);
		if (la_entrada==NULL)
		{
			return 1;
		}
		else
		{
			el_atributo=la_entrada->buscar_atributo(alias_at);
			if (el_atributo == NULL)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}

// 4. GESTION DE FICHEROS

// ************** Escribir el contenido actual de una tabla en un fichero **************
// Proceso DFD  : 4.1
// ID Requisito : REQ18
// Entrada      : - Identificador de la tabla de símbolos.
//                - Nombre del fichero donde se quiere escribir su contenido.

//
// Salida       : - Da una salida por fichero representando textualmente el 
//                   contenido de la tabla indicada en el momento de la llamada.
//                - Devuelve 0 si la operación se realizó correctamente.
//                - Devuelve -1 si se produce un error.
// Descripción  : Refleja el contenido actual de una tabla de símbolos 
//                 en un fichero, de forma textual.
// *************************************************************************************
int ts2006::escribir_tabla(int id_tabla, string nombre_fichero)
{
	int resultado;
	tabla_de_simbolos* la_tabla;
	la_tabla=tablas_de_simbolos->buscar_tabla(id_tabla);
	if (la_tabla == NULL)
	{
		ultimo_id_error = cte_error_no_existe_tabla; // Error: no existe la tabla indicada
		return -1;
	}
	// existe: delegar en ella la tarea de escribir su contenido.
	resultado=la_tabla->escribir_tabla(nombre_fichero);
	if (resultado<0)
	{
		ultimo_id_error = cte_error_creacion_fichero; // Error: El sistema no permitio crear el fichero.
		return -1;
	}
	return 0;
}

// 5. GESTION DE ERRORES

// ************** Consultar el ID del último error que se ha producido *****************
// Proceso DFD  : 5.1
// ID Requisito : REQ19
// Entrada      : <nada>
//
// Salida       : - Devuelve un entero positivo que representa el 
//                   último error que se ha producido.
//                - Devuelve 0 si de momento no han ocurrido errores.
// Descripción  : Devuelve un valor numérico que identifica el
//                 último error que se ha producido.
// *************************************************************************************
int ts2006::consultar_id_ultimo_error()
{
	return ultimo_id_error;
}

// ************** Consultar la descripción del último error que se ha producido ********
// Proceso DFD  : 5.2
// ID Requisito : REQ20
// Entrada      : <nada>
//
// Salida       : - Devuelve una cadena indicando la descripción del 
//                   último error que se ha producido.
//                - Devuelve la cadena vacía ("") si de momento no han ocurrido errores.
// Descripción  : Devuelve una descripción textual en lenguaje natural 
//                 del último error que se ha producido.
// *************************************************************************************
string ts2006::consultar_descripcion_ultimo_error()
{
	switch( ultimo_id_error )
	{
	case 0 : 
		return "";
	case cte_error_no_existe_tabla :
		return "No existe la tabla indicada";
	case cte_error_ya_existe_entrada :
		return "Ya existe una entrada con ese lexema en esa tabla";
	case cte_error_no_existe_entrada :
		return "No existe una entrada con ese lexema en esa tabla";
	case cte_error_ya_existe_atributo :
		return "Ya existía el atributo. No se ha modificado";	
	case cte_error_no_existe_atributo :
		return "No existe una atributo con ese nombre en la entrada indicada";
	case cte_error_lexema_es_null :
		return "NULL no es una cadena válida para denominar un lexema";
	case cte_error_alias_es_null :
		return "NULL no es una cadena válida para denominar un atributo";		 
	case cte_error_fichero_es_null :
		return "NULL no es una cadena válida para denominar un fichero";
	case cte_error_tipo_es_null :
		return "NULL no es una cadena válida para denominar un tipo de entrada";
	case cte_error_creacion_fichero :
		return "El sistema no permitió crear el fichero";
	case cte_error_tipo_no_definido :
		return "Tipo de entrada no definido";
	case cte_error_atributo_no_entero :
		return "El atributo existe pero no almacena enteros";
	case cte_error_atributo_no_cadena :
		return "El atributo existe pero no almacena cadenas";
	case cte_error_tipo_entrada_no_definido :
		return "El tipo de entrada aún no se ha definido";
	case cte_error_demasiadas_tablas :
		return "Se han creado demasiadas tablas";
	case cte_error_sin_memoria :
		return "Memoria agotada";
	case cte_error_atributo_cadena_es_null :
		return "El atributo cadena almacena un NULL";
	case cte_error_valor_es_null :
		return "No se permite almacenar cadenas NULL";
	case cte_error_posicion_es_null : 
		return "La posicion indicada apunta a NULL";
	case cte_error_posicion_ilegal : 
		return "Ocurrió un error al intentar acceder a la posicion indicada";
	default : 
		return "Ocurrió un error por causas desconocidas";
	}
}

// ************** Resetear la variable que almacena el último error producido  *********
// Proceso DFD  : 5.3
// ID Requisito : REQ32
// Entrada      : <nada>
//
// Salida       : <nada>
// Descripción  : Resetea la variable interna que indica el
//                 último error que se ha producido.
// *************************************************************************************
void ts2006::resetear_ultimo_error()
{
	ultimo_id_error=0;

}

// 6. FUNCIONES ALTERNATIVAS

// ************** Asignar el tipo de entrada a una entrada (por posicion) **************
// Proceso DFD  : 2,2
// ID Requisito : REQ07 + REQ30
// Entrada      : - Posicion de la entrada
//                - Tipo que se le quiere dar a la entrada.
//
// Salida       : - Devuelve 0 si la operación se realizó correctamente.
//                - Devuelve -1 si se produce un error.
// Descripción  : Asigna un tipo a una entrada existente.
// *************************************************************************************
int ts2006::asignar_tipo_entrada2(int posicion, string tipo)
{
	entrada* la_entrada;
	try
	{
		la_entrada=(entrada *) posicion;
		la_entrada->set_tipo_entrada(tipo);
		return 0;
	}
	catch(...) // capturaremos cualquier excepcion 
	{
		this->ultimo_id_error=cte_error_posicion_ilegal;
		return -1;
	}
}

// ************** Consultar el tipo de entrada de una entrada (por posicion) ***********
// Proceso DFD  : 2.3
// ID Requisito : REQ08 + REQ30
// Entrada      : - Posicion de la entrada
//
// Salida       : - Devuelve tipo de la entrada si se ha definido uno y no hay errores.
//                - Devuelve "" si se produce un error.
// Descripción  : Consulta el tipo de una entrada.
// *************************************************************************************
string ts2006::consultar_tipo_entrada2(int posicion)
{
// Entrada:
// - Posición de la entrada.
// Salida:
// - Devuelve tipo de la entrada si se ha definido uno y no hay errores.
// - Devuelve "" y genera error si se produce un error.
// Descripción:	Consulta el tipo de una entrada.
	entrada* la_entrada;
	try
	{
		la_entrada=(entrada *) posicion;
		return la_entrada->get_tipo_entrada();
	}
	catch(...) // capturaremos cualquier excepcion 
	{
		this->ultimo_id_error=cte_error_posicion_ilegal;
		return "";
	}
}

// ************** Crear un atributo entero en una entrada (por posicion) ***************
// Proceso DFD  : 3.1 
// ID Requisito : REQ09 + REQ30
// Entrada      : - Posicion de la entrada
//                - Alias del atributo (ejemplos: "desplazamiento", "ancho","tabla")
//                - Valor inicial para el atributo que estamos 
//                   creando (ejemplos: 16, 48, 3)
//
// Salida       : - Devuelve 0 si la operación se realizó correctamente.
//                - Devuelve -1 si se produce un error.
// Descripción  : Crea un nuevo atributo en la entrada, con el alias indicado. 
//                 Este atributo solo podrá almacenar valores enteros (tipo int de C++)
// *************************************************************************************
int ts2006::crear_atributo_entero2(int posicion, string alias_at, int valor)
{
	entrada* la_entrada;
	int resultado;
	try
	{
		la_entrada=(entrada *) posicion;
		resultado=la_entrada->crear_atributo_entero(alias_at,valor);
		if (resultado==-1)
		{
			// ya existia
			ultimo_id_error = cte_error_ya_existe_atributo; // Ya existia el atributo. No se ha modificado.
		}
		if (resultado==-2)
		{
			// sin memoria
			ultimo_id_error = cte_error_sin_memoria; // Error: memoria agotada 
			resultado=-1;
		}
		return resultado;
	}
	catch(...) // capturaremos cualquier excepcion 
	{
		this->ultimo_id_error=cte_error_posicion_ilegal;
		return -1;
	}
}

// ************** Crear un atributo cadena en una entrada (por posicion) ***************
// Proceso DFD  : 3.2 
// ID Requisito : REQ10 + REQ30
// Entrada      : - Posicion de la entrada
//                - Alias del atributo (ejemplos: "cadena", "real","cosa")
//                - Valor inicial para el atributo que estamos 
//                  creando (ejemplos: "algo", "12.345", "123abcd")
//
// Salida       : - Devuelve 0 si la operación se realizó correctamente.
//                - Devuelve -1 si se produce un error.
// Descripción  : Crea un nuevo atributo en la entrada, con el alias indicado. 
//                 Este atributo solo podrá almacenar cadenas (tipo string de C++)
// *************************************************************************************
int ts2006::crear_atributo_cadena2(int posicion, string alias_at, string valor)
{
	entrada* la_entrada;
	int resultado;
	try
	{
		la_entrada=(entrada *) posicion;
		resultado=la_entrada->crear_atributo_cadena(alias_at,valor);
		if (resultado==-1)
		{
			// ya existia
			ultimo_id_error = cte_error_ya_existe_atributo; // Ya existia el atributo. No se ha modificado.
		}
		if (resultado==-2)
		{
			// sin memoria
			ultimo_id_error = cte_error_sin_memoria; // Error: memoria agotada 
			resultado=-1;
		}
		return resultado;
	}
	catch(...) // capturaremos cualquier excepcion 
	{
		this->ultimo_id_error=cte_error_posicion_ilegal;
		return -1;
	}
}

// ************** Asignar el valor de un atributo entero (por posicion) ****************
// Proceso DFD  : 3.3
// ID Requisito : REQ11 + REQ30
// Entrada      : - Posicion de la entrada
//                - Alias del atributo.
//                - Nuevo valor que se quiere escribir en ese atributo (un entero)
//
// Salida       : - Devuelve 0 si la operación se realizó correctamente.
//                - Devuelve -1 si se produce un error.
// Descripción  : Da un valor al atributo (entero) de alias indicado en la 
//                 entrada indicada (sobrescribe el valor antiguo)
// *************************************************************************************
int ts2006::asignar_valor_atributo_entero2(int posicion, string alias_at, int valor)
{
	entrada* la_entrada;
	atributo* el_atributo;
	int resultado;
	try
	{
		la_entrada=(entrada *) posicion;
		el_atributo=la_entrada->buscar_atributo(alias_at);
		if (el_atributo == NULL)
		{
			ultimo_id_error = cte_error_no_existe_atributo; // No existia el atributo.
			return -1;
		}
		if (el_atributo->get_tipo_atributo() != tipo_entero)
		{
			ultimo_id_error = cte_error_atributo_no_entero; // El atributo existe pero no es del tipo entero
			return -1;
		}

		resultado=el_atributo->set_valor_entero(valor);
		if (resultado<0)
		{
			ultimo_id_error = cte_error_sin_memoria; // Error: memoria agotada 
			resultado=-1;
		}
		return resultado;
	}
	catch(...) // capturaremos cualquier excepcion 
	{
		this->ultimo_id_error=cte_error_posicion_ilegal;
		return -1;
	}
}

// ************** Asignar el valor de un atributo cadena (por posicion) ****************
// Proceso DFD  : 3.4
// ID Requisito : REQ12 + REQ30
// Entrada      : - Posicion de la entrada
//                - Alias del atributo.
//                - Nuevo valor que se quiere escribir en ese atributo (una cadena)

// Salida       : - Devuelve 0 si la operación se realizó correctamente.
//                - Devuelve -1 si se produce un error.
// Descripción  : Da un valor al atributo (cadena) de alias indicado en la entrada 
//                 indicada (sobrescribe el valor antiguo)
// *************************************************************************************
int ts2006::asignar_valor_atributo_cadena2(int posicion, string alias_at, string valor)
{
	entrada* la_entrada;
	atributo* el_atributo;
	int resultado;
	try
	{
		la_entrada=(entrada *) posicion;
		el_atributo=la_entrada->buscar_atributo(alias_at);
		if (el_atributo == NULL)
		{
			ultimo_id_error = cte_error_no_existe_atributo; // No existia el atributo.
			return -1;
		}
		if (el_atributo->get_tipo_atributo() != tipo_cadena)
		{
			ultimo_id_error = cte_error_atributo_no_cadena; // El atributo existe pero no es del tipo cadena
			return -1;
		}

		resultado=el_atributo->set_valor_cadena(valor);
		if (resultado<0)
		{
			ultimo_id_error = cte_error_sin_memoria; // Error: memoria agotada 
			resultado=-1;
		}
		return resultado;
	}
	catch(...) // capturaremos cualquier excepcion 
	{
		this->ultimo_id_error=cte_error_posicion_ilegal;
		return -1;
	}
}

// ************** Consultar el valor de un atributo entero (por posicion) **************
// Proceso DFD  : 3.5 
// ID Requisito : REQ13 + REQ30
// Entrada      : - Posicion de la entrada
//                - Alias del atributo.
//
// Salida       : - Valor del atributo entero.
//                - Devuelve 0 y genera un error si se produce error.
// Descripción  : Consulta el valor de un atributo entero.
// *************************************************************************************
int ts2006::consultar_valor_atributo_entero2(int posicion, string alias_at)
{
	entrada* la_entrada;
	atributo* el_atributo;
	try
	{
		la_entrada=(entrada *) posicion;
		el_atributo=la_entrada->buscar_atributo(alias_at);
		if (el_atributo == NULL)
		{
			ultimo_id_error = cte_error_no_existe_atributo; // No existia el atributo.
			return -1;
		}

		if (el_atributo->get_tipo_atributo() != tipo_entero)
		{
			ultimo_id_error = cte_error_atributo_no_entero; // El atributo existe pero no es del tipo entero
			return -1;
		}

		return el_atributo->get_valor_entero();
	}
	catch(...) // capturaremos cualquier excepcion 
	{
		this->ultimo_id_error=cte_error_posicion_ilegal;
		return -1;
	}
}

// ************** Consultar el valor de un atributo cadena (por posicion) **************
// Proceso DFD  : 3.6
// ID Requisito : REQ14 + REQ30
// Entrada      : - Posicion de la entrada
//                - Alias del atributo.
//
// Salida       : - Valor del atributo cadena.
//                - Devuelve "" y genera un error si se produce error.
// Descripción  : Consulta el valor de un atributo cadena.
// *************************************************************************************
string ts2006::consultar_valor_atributo_cadena2(int posicion, string alias_at)
{
	entrada* la_entrada;
	atributo* el_atributo;
	try
	{
		la_entrada=(entrada *) posicion;
		el_atributo=la_entrada->buscar_atributo(alias_at);
		if (el_atributo == NULL)
		{
			ultimo_id_error = cte_error_no_existe_atributo; // No existia el atributo.
			return "";
		}

		if (el_atributo->get_tipo_atributo() != tipo_cadena)
		{
			ultimo_id_error = cte_error_atributo_no_cadena; // El atributo existe pero no es del tipo cadena
			return "";
		}

		return el_atributo->get_valor_cadena();
	}
	catch(...) // capturaremos cualquier excepcion 
	{
		this->ultimo_id_error=cte_error_posicion_ilegal;
		return "";
	}
}

// ************** Determinar la existencia de un atributo (por posicion) ***************
// Proceso DFD  : 3.7
// ID Requisito : REQ17 + REQ30
// Entrada      : - Posicion de la entrada
//                - Alias del atributo.
//
// Salida       : - Devuelve 0 si existe.
//                - Devuelve 1 si no existe.
//                - Devuelve -1 si se produce un error.
// Descripción  : Determina si un atributo (con el alias indicado) existe en una 
//                 determinada entrada (si existe la entrada y 
//                 aun su tabla no se ha destruido)
// *************************************************************************************
int ts2006::existe_atributo2(int posicion, string alias_at)
{
	entrada* la_entrada;
	atributo* el_atributo;
	try
	{
		la_entrada=(entrada *) posicion;
		el_atributo=la_entrada->buscar_atributo(alias_at);
		if (el_atributo == NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	catch(...) // capturaremos cualquier excepcion 
	{
		this->ultimo_id_error=cte_error_posicion_ilegal;
		return -1;
	}
}

// ************** Buscar la posicion de una entrada ************************************
// Proceso DFD  : 2.4
// ID Requisito : REQ29
// Entrada      : - Identificador de la tabla de símbolos de la entrada.
//                - Lexema de la entrada.
//
// Salida       : - Devuelve la posicion de la entrada (si existe)
//                - Devuelve 0 si no existe una entrada con ese id_tabla y lexema
// Descripción  : Busca la posicion de una entrada 
//                 ( si ya fue ya creada y aun no se ha destruido su tabla )
// *************************************************************************************
int ts2006::buscar_posicion_entrada(int id_tabla, string lexema)
{
	tabla_de_simbolos* tabla;
	entrada* la_entrada;
	tabla=tablas_de_simbolos->buscar_tabla(id_tabla);
	if (tabla==NULL)
	{
		ultimo_id_error = cte_error_no_existe_tabla; // Error: no existe la tabla indicada
		return 0;
	}
	else
	{
		la_entrada=tabla->buscar_entrada(lexema);
		if (la_entrada==NULL)
		{
			ultimo_id_error = cte_error_no_existe_entrada; // No existe una entrada con ese lexema en esa tabla
			return 0;
		}
		else
		{
			return (int) la_entrada;
		}
	}
}



// IMPLEMENTACION DE LAS CLASES AUXILIARES

// Implementacion clase lista_de_tablas_de_simbolos


lista_de_tablas_de_simbolos::lista_de_tablas_de_simbolos()
{
	nodo_tabla=NULL;
	siguiente=NULL;
}

lista_de_tablas_de_simbolos::~lista_de_tablas_de_simbolos()
{
	if (nodo_tabla != NULL)
	{
		delete nodo_tabla;
	}
}

lista_de_tablas_de_simbolos* lista_de_tablas_de_simbolos::get_siguiente()
{
	return siguiente;
}

tabla_de_simbolos* lista_de_tablas_de_simbolos::get_tabla()
{
	return nodo_tabla;
}

tabla_de_simbolos* lista_de_tablas_de_simbolos::buscar_tabla(int par_id)
{
	if (nodo_tabla->get_id() == par_id)
	{
		return nodo_tabla;
	}
	else
	{
		if (siguiente == NULL)
		{
			return NULL;
		}
		else
		{
			return siguiente->buscar_tabla(par_id);
		}
	}
}

void lista_de_tablas_de_simbolos::set_siguiente(lista_de_tablas_de_simbolos *par_siguiente)
{
	siguiente=par_siguiente;
}

void lista_de_tablas_de_simbolos::set_tabla(tabla_de_simbolos *par_tabla)
{
	nodo_tabla=par_tabla;
}

// Implementacion clase tabla_de_simbolos

tabla_de_simbolos::tabla_de_simbolos(int par_id)
{
	int i;
	for (i=0; i<cte_espacio_hash; i++ ) // todas sus entradas estaran vacias
	{
		almacen_entradas[i] = NULL;
	}
	id=par_id;
}

tabla_de_simbolos::~tabla_de_simbolos()
{
	int i;
	lista_de_entradas* punterolista;
	lista_de_entradas* punterolista2;
	for (i=0; i<cte_espacio_hash; i++ ) // liberar memoria de todas las listas de entradas
	{
		punterolista=almacen_entradas[i];
		// borramos todas los nodos
		while (punterolista!=NULL)
		{
			punterolista2=punterolista;
			punterolista=punterolista->get_siguiente();
			delete punterolista2;
		}
	}
}

int tabla_de_simbolos::funcion_hash(string cadena)
{
	// Función que devuelve un número entre 
	// 0 y cte_espacio_hash - 1
	// calculado a partir de la cadena indicada.
	int suma_ascii = 0;
	int lon;
	int i;
	int resultado;
	char letra;
	int ascii_letra;
	lon = cadena.length();
	for (i=0; i<lon; i++ )
	{
		letra = cadena[i];
		// Se convierte cada letra a su valor entero ascii.
		ascii_letra = (int) letra;
		// Se sumarán todos esos valores.
		suma_ascii = suma_ascii+ascii_letra;
	}
	// Se hace módulo con cte_espacio_hash.
	resultado = suma_ascii % cte_espacio_hash;
	return resultado;
}

int tabla_de_simbolos::get_id()
{
	return id;
}

int tabla_de_simbolos::crear_entrada(string lexema)
{
	int posicion;
	entrada* entrada_nueva;
	lista_de_entradas* punterolista;
	lista_de_entradas* nodolista;

	posicion=funcion_hash(lexema); // calculamos hash para este lexema

	// existe ya?
	if (almacen_entradas[posicion] !=NULL)
	{
		if (this->almacen_entradas[posicion]->buscar_entrada(lexema) != NULL)
		{
			return -1; // ya existe
		}
	}

	entrada_nueva=new entrada(lexema);
	if (!entrada_nueva)
	{
		// Error: sin memoria para el new
		return -2;
	}

	nodolista=new lista_de_entradas;
	if (!nodolista)
	{
		// Error: sin memoria para el new
		delete entrada_nueva;
		return -2;
	}
	nodolista->set_entrada(entrada_nueva);
    nodolista->set_siguiente(NULL);

    if (almacen_entradas[posicion] ==NULL)
	{
		almacen_entradas[posicion]=nodolista;
	}
    else
	{
		punterolista=almacen_entradas[posicion];
		while (punterolista->get_siguiente() != NULL) // Buscamos el final de la lista
		{
			punterolista = punterolista->get_siguiente();
		}
        punterolista->set_siguiente(nodolista);
    }
	return 0;
}

entrada* tabla_de_simbolos::buscar_entrada(string lexema)
{
	int posicion;
	posicion=funcion_hash(lexema); // calculamos hash para este lexema
	// existe ya?
	if (almacen_entradas[posicion] !=NULL)
	{
		return almacen_entradas[posicion]->buscar_entrada(lexema);
	}
	else
	{
		return NULL; // no existe
	}
}

int tabla_de_simbolos::escribir_tabla(string nombre_fichero)
{
	// Crea un fichero con el contenido de la tabla indicada
	// 0 = operacion ok  ; -1 = error

	ofstream controlador;

	lista_de_entradas* punterolista;
	entrada* una_entrada;
	int i;
	int escrito_algo = -1 ; // hemos encontrado alguna entrada?

    controlador.open(nombre_fichero.c_str()); // (intentamos) abrir el fichero para escritura
	if (!controlador) // si falla , no podemos seguir
	{
		// Error: El sistema no permitio crear el fichero.
		return -1;
	}
	// todo ok: podemos empezar a escribir
	controlador << "CONTENIDO ACTUAL DE LA TABLA # " << id << " :" << endl;

	for (i=0; i<cte_espacio_hash; i++ ) 
	{
		punterolista=almacen_entradas[i];
		while (punterolista!=NULL)
		{
			una_entrada=punterolista->get_entrada();
			punterolista=punterolista->get_siguiente();
			controlador << "---------------------------------------------------" << endl;
			una_entrada->escribir_entrada(controlador);
			escrito_algo=0;	
		}
	}
	controlador << "---------------------------------------------------" << endl;
	if (escrito_algo == -1)
	{
		controlador << "  <la tabla esta vacía>" << endl;
	}
	controlador.close(); // liberamos el controlador del fichero
	return 0;
}

// Implementacion clase lista de entradas
lista_de_entradas::lista_de_entradas()
{
	nodo_entrada=NULL;
	siguiente=NULL;
}

lista_de_entradas::~lista_de_entradas()
{
	if (nodo_entrada != NULL)
	{
		delete nodo_entrada;
	}
}

lista_de_entradas* lista_de_entradas::get_siguiente()
{
	return siguiente;
}

entrada* lista_de_entradas::get_entrada()
{
	return nodo_entrada;
}

void lista_de_entradas::set_siguiente(lista_de_entradas *par_siguiente)
{
	siguiente=par_siguiente;
}

void lista_de_entradas::set_entrada(entrada *par_entrada)
{
	nodo_entrada=par_entrada;
}

entrada* lista_de_entradas::buscar_entrada(string lexema)
{
	if (nodo_entrada->get_lexema() == lexema)
	{
		return nodo_entrada;
	}
	else
	{
		if (siguiente == NULL)
		{
			return NULL;
		}
		else
		{
			return siguiente->buscar_entrada(lexema);
		}
	}
}

// Implementacion clase entrada

entrada::entrada(string par_lexema)
{
	lexema=par_lexema;
	tipo_entrada="";
	atributos=NULL;
}

entrada::~entrada()
{
	lista_de_atributos* puntero;
	lista_de_atributos* puntero2;
	puntero=atributos;
	while (puntero!=NULL)
	{
		puntero2=puntero;
		puntero=puntero->get_siguiente();
		delete puntero2;
	}
}

string entrada::get_lexema()
{
	return lexema;
}

string entrada::get_tipo_entrada()
{
	return tipo_entrada;
}

void entrada::set_tipo_entrada(string par_tipo_entrada)
{
	tipo_entrada=par_tipo_entrada;
}

int entrada::crear_atributo_entero(string alias_at, int valor_entero)
{
	atributo* un_atributo;
	lista_de_atributos* punterolista;
	lista_de_atributos* nodolista;
	int resultado;

	if (buscar_atributo(alias_at) != NULL)
	{
		return -1; // el atributo ya existia
	}

	un_atributo=new atributo(alias_at,tipo_entero);
	if (!un_atributo)
	{
		// Error: sin memoria para este new
		return -2;
	}

	nodolista=new lista_de_atributos;
	if (!nodolista)
	{
		delete un_atributo;
		// Error: sin memoria para este new
		return -2;
	}
	resultado=un_atributo->set_valor_entero(valor_entero);
	if (resultado<0)
	{
		delete un_atributo;
		delete nodolista;
		// Error: sin memoria para inicializacion valor
		return -2;
	}

	nodolista->set_atributo(un_atributo);
    nodolista->set_siguiente(NULL);

	punterolista=atributos;
    if (punterolista==NULL)
	{
		atributos=nodolista;
	}
    else
	{
		while (punterolista->get_siguiente() != NULL) // Buscamos el final de la lista
		{
			punterolista = punterolista->get_siguiente();
		}
        punterolista->set_siguiente(nodolista);
    }
	return 0; // todo ok
}

int entrada::crear_atributo_cadena(string alias_at, string valor_cadena)
{
	atributo* un_atributo;
	lista_de_atributos* punterolista;
	lista_de_atributos* nodolista;
	int resultado;

	if (buscar_atributo(alias_at) != NULL)
	{
		return -1; // el atributo ya existia
	}

	un_atributo=new atributo(alias_at,tipo_cadena);
	if (!un_atributo)
	{
		// Error: sin memoria para este new
		return -2;
	}

	nodolista=new lista_de_atributos;
	if (!nodolista)
	{
		delete un_atributo;
		// Error: sin memoria para este new
		return -2;
	}
	resultado=un_atributo->set_valor_cadena(valor_cadena);
	if (resultado<0)
	{
		delete un_atributo;
		delete nodolista;
		// Error: sin memoria para inicializacion valor
		return -2;
	}

	nodolista->set_atributo(un_atributo);
    nodolista->set_siguiente(NULL);

	punterolista=atributos;
    if (punterolista==NULL)
	{
		atributos=nodolista;
	}
    else
	{
		while (punterolista->get_siguiente() != NULL) // Buscamos el final de la lista
		{
			punterolista = punterolista->get_siguiente();
		}
        punterolista->set_siguiente(nodolista);
    }
	return 0; // todo ok
}

atributo* entrada::buscar_atributo(string alias_at)
{
	if (atributos==NULL)
	{
		return NULL;
	}
	else
	{
		return atributos->buscar_atributo(alias_at);
	}
}


void entrada::escribir_entrada(ofstream &controlador)
{
	lista_de_atributos* puntero;
	atributo* un_atributo;
    controlador << "* LEXEMA : '" << lexema.c_str() << "' "; 
	if (tipo_entrada == "")
	{
		controlador << "(tipo de entrada no definido)" << endl;  // No definido
	}
	else
	{
		controlador << "(tipo de entrada '" << tipo_entrada.c_str() << "')" << endl;
	}
	controlador << "  ATRIBUTOS :" << endl;
	if (atributos==NULL)
	{
		controlador << "   <no se han definido atributos para este lexema>" << endl;
	}
	else
	{
		puntero=atributos;
		while (puntero!=NULL)
		{
			un_atributo=puntero->get_atributo();
			puntero=puntero->get_siguiente();
			un_atributo->escribir_atributo(controlador);
		}
	}
}

// Implementacion clase lista de atributos
lista_de_atributos::lista_de_atributos()
{
	nodo_atributo=NULL;
	siguiente=NULL;
}

lista_de_atributos::~lista_de_atributos()
{
	if (nodo_atributo != NULL)
	{
		delete nodo_atributo;
	}
}

lista_de_atributos* lista_de_atributos::get_siguiente()
{
	return siguiente;
}

atributo* lista_de_atributos::get_atributo()
{
	return nodo_atributo;
}

void lista_de_atributos::set_siguiente(lista_de_atributos *par_siguiente)
{
	siguiente=par_siguiente;
}

void lista_de_atributos::set_atributo(atributo *par_atributo)
{
	nodo_atributo=par_atributo;
}

atributo* lista_de_atributos::buscar_atributo(string nombre)
{
	if (nodo_atributo->get_nombre() == nombre)
	{
		return nodo_atributo;
	}
	else
	{
		if (siguiente == NULL)
		{
			return NULL;
		}
		else
		{
			return siguiente->buscar_atributo(nombre);
		}
	}
}





// Implementacion clase atributo

atributo::atributo(string nombre, enum conj_tipo_atributo par_tipo)
{
	tipo_atributo=par_tipo;
	nombre_atributo=nombre;
	if (par_tipo == tipo_entero)
	{
		valor.entero=0;
	}
	else
	{
		valor.cadena=NULL;
	}
}

atributo::~atributo()
{
	if (tipo_atributo == tipo_cadena)
	{
		if (valor.cadena != NULL)
		{
			delete valor.cadena;
		}
	}
}

string atributo::get_nombre()
{
	return nombre_atributo;
}

int atributo::set_valor_cadena(string valor_cadena)
{
	if (tipo_atributo == tipo_cadena)
	{
		delete valor.cadena;
		valor.cadena=new string(valor_cadena);
		if (valor.cadena==NULL)
		{
			return -2; // sin memoria
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return -1; // atributo no almacena cadena
	}
}

int atributo::set_valor_entero(int valor_entero)
{
	if (tipo_atributo == tipo_entero)
	{
		valor.entero=valor_entero;
		return 0;
	}
	else
	{
		return -1; // atributo no almacena entero
	}
}

string atributo::get_valor_cadena()
{
	if (tipo_atributo == tipo_cadena)
	{
		return *valor.cadena;
	}
	else
	{
		return ""; // no deberia ocurrir: El gestor debe consultar el tipo previamente
	}
}

int atributo::get_valor_entero()
{
	if (tipo_atributo == tipo_entero)
	{
		return valor.entero;
	}
	else
	{
		return 0; // no deberia ocurrir: El gestor debe consultar el tipo previamente
	}
}

enum conj_tipo_atributo atributo::get_tipo_atributo()
{
	return tipo_atributo;
}

void atributo::escribir_atributo(ofstream &controlador)
{
	controlador << "   + " << nombre_atributo.c_str() << " : "; // escribimos nombre_atributo
	if (tipo_atributo==tipo_cadena)
	{
		if (valor.cadena == NULL) // <- no deberia ocurrir si usamos el gestor ...
		{
			controlador << "<NULL>" << endl;  // ... pero por si acaso.
		}
		else
		{
			controlador << "'" << valor.cadena->c_str() <<  "'" << endl; // ... escribimos la cadena
		}
	}
	else
	{
		controlador << valor.entero << endl; // ... escribimos el entero
	}
}
