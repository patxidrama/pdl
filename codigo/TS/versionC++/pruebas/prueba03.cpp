// Prueba 03: "Diccionario interactivo"
// ---------------------------------

// Un ejemplo sencillo
// usando la tabla de símbolos
// a modo de diccionario.


#include "ts2006.h"

int idTabla;
ts2006* gestor;

void modificar()
{
	// se crea/modifica
	// segun si ya existe
	// una entrada para ese
	// lexema.
	// el valor se escribirá
	// en un atributo "valor"
	string strEntrada;
	string strValor;
	int existe;
	int devuelto;
	gestor->resetear_ultimo_error();
	cout << "¿Entrada?" 
		 << endl;
	strEntrada="";
	while (strEntrada == "")
	{
		cin >> strEntrada;
	}
	cout << "¿Valor?" 
		 << endl;
	strValor="";
	while (strValor == "")
	{
		cin >> strValor;
	}
	existe=gestor->existe_entrada(idTabla,
	 strEntrada);
	if (existe==1)
	{
		cout << "Añadiendo..." << endl;
		devuelto=gestor->
		 crear_entrada(idTabla,strEntrada);
		if (devuelto != 0)
		{
		  cout << "ERROR: " <<
		   gestor->
		   consultar_descripcion_ultimo_error()
		   << endl;
		   gestor->resetear_ultimo_error();
		}
		else
		{
		   devuelto=
			gestor->asignar_tipo_entrada(
			idTabla, strEntrada, 
			"entrada de diccionario");
			if (devuelto != 0)
			{
			  cout << "ERROR: " <<
			   gestor->
			   consultar_descripcion_ultimo_error()
			   << endl;
			   gestor->resetear_ultimo_error();
			}
		   cout << strEntrada <<
		    "=" << strValor << endl;
		   gestor->crear_atributo_cadena(
		    idTabla, strEntrada, "valor", strValor);
	   		if (devuelto != 0)
			{
			  cout << "ERROR: " <<
			   gestor->
			   consultar_descripcion_ultimo_error()
			   << endl;
			   gestor->resetear_ultimo_error();
			}
		}

	}
	else if (existe==0)
	{	
		cout << "Modificando..." << endl;
		cout << strEntrada <<
		    "=" << strValor << endl;
		devuelto=gestor->
		 asignar_valor_atributo_cadena(
		 idTabla, strEntrada, "valor", strValor);
		if (devuelto != 0)
		{
		  cout << "ERROR: " <<
		   gestor->
		   consultar_descripcion_ultimo_error()
		   << endl;
		   gestor->resetear_ultimo_error();
		}
	}
	else
	{
		cout << "ERROR: " <<
		 gestor->
		 consultar_descripcion_ultimo_error()
		 << endl;
		 gestor->resetear_ultimo_error();
	}

}

void consultar()
{
	// Se consulta si
	// la entrada existe.
	// Si existe se
	// consulta su atributo
	// "valor" y se muestra
	// por pantalla
	string strEntrada;
	string strValor;
	int existe;
	gestor->resetear_ultimo_error();
	cout << "¿Entrada a consultar?" 
		 << endl;
	strEntrada="";
	while (strEntrada == "")
	{
		cin >> strEntrada;
	}
	existe=gestor->existe_entrada(idTabla,
	 strEntrada);
	if (existe==0)
	{
		strValor=gestor->
		 consultar_valor_atributo_cadena(
		 idTabla, strEntrada, "valor");
		if (gestor->
		 consultar_id_ultimo_error() !=0)
		{
		cout << "ERROR: " <<
		 gestor->
		 consultar_descripcion_ultimo_error()
		 << endl;
		 gestor->resetear_ultimo_error();
		}
		cout << "Entrada encontrada. Valor = " << 
		 strValor << endl; 
	}
	else if (existe==1)
	{
		cout << "No existe esa entrada" 
		 << endl;
	}
	else
	{
		cout << "ERROR: " <<
		 gestor->
		 consultar_descripcion_ultimo_error()
		 << endl;
		 gestor->resetear_ultimo_error();
	}
}

void grabar()
{
	// graba el contenido
	// actual de la tabla
	// en el fichero "dicc.txt"
	int devuelto;
	gestor->resetear_ultimo_error();
	cout << "Grabando..."
	 << endl;
	devuelto=
	 gestor->escribir_tabla(idTabla,
	 "dicc.txt");
	if (devuelto == 0)
	{
		cout << 
		 "El contenido del diccionario"
		 " se ha grabado en dicc.txt";
	}
	else
	{
		cout << "ERROR: " <<
		 gestor->
		 consultar_descripcion_ultimo_error()
		 << endl;
		gestor->resetear_ultimo_error();
	}

}

int main() {
	int devuelto;

	string strdevuelto; 
	string stropcion;
    

	// creación del gestor
	gestor=new ts2006(); 

	// creación de la tabla
	idTabla=gestor->crear_tabla();

	// menu interactivo en consola,
	// (muy básico)
	stropcion="";
	while ((stropcion != "S") && 
		(stropcion != "s"))
	{
		cout << "Seleccione una opción:" 
		 << endl;
		cout << "A: Añadir/modificar" 
		 << endl;	
		cout << "C: Consultar" 
		 << endl;	
		cout << "S: Grabar y salir" 
		 << endl;	
		cin >> stropcion;
		if (( stropcion == "A" ) || 
		 (stropcion == "a"))
		{
		  modificar();
		}
		else if (( stropcion == "C" ) || 
		 (stropcion == "c"))
		{
		  consultar();
		}
		else if (( stropcion == "S" ) || 
		 (stropcion == "s"))
		{
		  grabar();
		}
		else
		{
		  cout << "Opción no válida."
		   << endl;
		}

	}
	

	delete gestor; // destrucción del gestor
   
	return 0;
}
