// Prueba 08: "Muchos atributos"
// ---------------------------------

// Se analizará que ocurre al crear
// 3000 atributos diferentes para 
// una misma entrada. Se usará un generador
// de números aleatorios para construir 
// cadenas de texto aleatorias.

// Al principio se han observado errores 
// extraños. Tras analizar los valores que
// devolvían las funciones se ha visto que 
// estos errores eran debidos a que a veces 
// se generaban cadenas iguales. 
// Se añadió una comprobación previa al 
// insertado del atributo para evitar intentar
// volverlo a insertar en caso de que ya
// existiese uno con ese mismo nombre. 
// También se ha añadido un texto al final
// de la prueba que indicará, por curiosidad,
// cuantas cadenas diferentes se han insertado.



#include "ts2006.h"
#include <time.h>

ts2006* gestor;

int numero_aleatorio(int desde,int hasta)
{
  int resultado;
  resultado = rand() % (hasta+1) + desde;
  return(resultado);
}

void inicializar_generador_de_aleatorios()
{
	// inicializamos el generador
	// de numeros aleatorios.
	srand ( time(NULL) );
}

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
	int id;
	int i;
    int veces;
	int diferentes;
    char nombre_atributo[9];
	string nombre;
	
	inicializar_generador_de_aleatorios();
	// Aqui indicamos cuantas veces
	// queremos repetir el bucle
	// de la prueba
	veces=3000;

	// creación del gestor
	gestor=new ts2006(); 


	// creación de una tabla
	id=gestor->crear_tabla();
	comprobar_errores ("1");

	// creación de entradas
	devuelto=gestor->crear_entrada(id,"prueba");
	comprobar_errores ("2");

	// asignar tipo de entrada
	devuelto=gestor->
	 asignar_tipo_entrada(id,"prueba","tipopruebas");
	comprobar_errores ("3");

	cout << "Inicio del bucle..." << endl;
	diferentes=0;
    for(i = 0; i < veces; i++)
    {
		nombre_atributo[0]=97+numero_aleatorio(0,25);
		nombre_atributo[1]=97+numero_aleatorio(0,25);
		nombre_atributo[2]=97+numero_aleatorio(0,25);
		nombre_atributo[3]=97+numero_aleatorio(0,25);
		nombre_atributo[4]=97+numero_aleatorio(0,25);
		nombre_atributo[5]=97+numero_aleatorio(0,25);
		nombre_atributo[6]=97+numero_aleatorio(0,25);
		nombre_atributo[7]=97+numero_aleatorio(0,25);
		nombre_atributo[8]=0;
        nombre=nombre_atributo;

	  // creación de atributo
	  if (gestor->existe_atributo(id,"prueba",nombre)==1)
	  {
		// contamos cuantas cadenas diferentes
		// hemos creado con rand()
		// (por curiosidad)
		diferentes++;
	    devuelto=gestor->crear_atributo_cadena(id,
	     "prueba",nombre,"algo");
	    comprobar_errores ("4");
      }

	}
	cout << "Fin del bucle..." << endl;
    cout << "Se crearon " << diferentes <<
	 " atributos diferentes" << endl;
	cout << "Escribiendo tabla..." << endl;
    devuelto=gestor->escribir_tabla(id,"prueba.txt");
    comprobar_errores ("6");
	delete gestor; // destrucción del gestor


	return 0;
}
