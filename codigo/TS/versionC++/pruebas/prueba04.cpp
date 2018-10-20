// Prueba 04: "Número de entradas variable"
// ---------------------------------

// Un ejemplo sencillo
// en el que se crearan
// tantas entradas como
// indique el usuario.

// Ademas se medirá
// el tiempo

#include "ts2006.h"
#include <time.h>

int idTabla;
ts2006* gestor;


void grabar4()
{
	// graba el contenido
	// actual de la tabla
	// en el fichero "tabla4.txt"
	int devuelto;
	gestor->resetear_ultimo_error();
	cout << "Grabando..."
	 << endl;
	devuelto=
	 gestor->escribir_tabla(idTabla,
	 "tabla4.txt");
	if (devuelto == 0)
	{
		cout << 
		 "El contenido de la tabla"
		 " se ha grabado en tabla4.txt";
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
	int id;
	int i;
	int v;
	int num[3];
	int mult;
	int NUMENTRADAS;
	clock_t t_ini, t_fin;
	double secs;
	char nombre_entrada[13];
	string nombre;
    
	// creación del gestor
	gestor=new ts2006(); 

	// creación de la tabla
	idTabla=gestor->crear_tabla();

	// pregunta número de entradas
	// al usuario
	cout << "¿Cuantas entradas creamos? "
		" (max=17576 en este ejemplo)"
     << endl;
	cin >> NUMENTRADAS;

	// se crea una tabla
	cout << "Creando tabla..." << endl;
	idTabla = gestor->crear_tabla();
    if (idTabla<0) 
	{ 
		 cout << "Se produjo un error: " <<
		 gestor->consultar_descripcion_ultimo_error()
		 << endl;
		 exit(-1); 
	}

    // se crean tantas entradas
	// como el usuario halla indicado

	cout << "Creando " << NUMENTRADAS
	 << " entradas... " << endl;
	t_ini = clock();
	nombre_entrada[11]=0;
	for ( i = 0; i <= NUMENTRADAS-1 ; i++ )
	{
		v=i;
		nombre_entrada[0]=97;
		nombre_entrada[1]=97;
		nombre_entrada[2]=97;
		nombre_entrada[3]=97;
		nombre_entrada[4]=97;
		nombre_entrada[5]=97;
		nombre_entrada[6]=97;
		nombre_entrada[7]=97;
		num[0]=v%26;
		v=v/26;
		num[1]=v%26;
		v=v/26;
		num[2]=v%26;
		nombre_entrada[8]=97+num[2];
		nombre_entrada[9]=97+num[1];
		nombre_entrada[10]=97+num[0];

		nombre=nombre_entrada;
		// cout << "Creando entrada " << 
		// i+1 << "... "
		// << nombre << endl;
		devuelto = gestor->crear_entrada(
		 idTabla,nombre);
		if (devuelto != 0)
		{
			cout << 
			 "(!) En la anterior llamada"
			 " se produjo el error "
			 << devuelto << endl;
			cout << 
			 "Descripción del error: "
			<<
			gestor->
			consultar_descripcion_ultimo_error()
		    << endl;
			exit (-1);
		}
	}
	t_fin = clock();

	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;

	// printf("%.16g milisegundos\n", 
	// secs * 1000.0);

	cout << "Se ha tardado en total: " <<
		secs * 1000.0 << " ms" << endl;
	grabar4();

	delete gestor; // destrucción del gestor
   
	return 0;
}
