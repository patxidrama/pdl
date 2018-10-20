//****************************************************************
//   CPLUS2\PARSER_C.FRM
//   Coco/R C++ Support Frames.
//   Author: Frankie Arzu <farzu@uvg.edu.gt>
//
//   Jun 12, 1996  Version 1.06
//      Many fixes and suggestions thanks to
//      Pat Terry <p.terry@.ru.ac.za>
//   Oct 11, 1997  Version 1.07
//      Eliminated redundant ";" in some places
//****************************************************************

#include "pruebac.hpp"

#include <stdlib.h>
  #include <iostream.h>
  #include "ts2006.h"



#include "pruebap.hpp"
#include "pruebas.hpp"

unsigned short int pruebaParser::SymSet[][MAXSYM] = {
  /*EOF_Sym */
  {0x1},
  
  {0x0}
};

void pruebaParser::Get()
{ do {
    Sym = Scanner->Get();
    Scanner->NextSym.SetSym(Sym);
    if (Sym <= MAXT) Error->ErrorDist ++;
    else {
      /* Empty Stmt */ ;
      Scanner->NextSym = Scanner->CurrSym;
    }
  } while (Sym > MAXT);
}

void pruebaParser::ExpectWeak(int n, int follow)
{ if (Sym == n) Get();
  else {
    GenError(n);
    while (!(In(SymSet[follow], Sym) || In(SymSet[0], Sym))) Get();
  }
}

int pruebaParser::WeakSeparator(int n, int syFol, int repFol)
{ unsigned short int s[MAXSYM];
  int i;

  if (Sym == n) { Get(); return 1; }
  if (In(SymSet[repFol], Sym)) return 0;

  for (i = 0; i < MAXSYM; i++)
    s[i] = SymSet[0][i] | SymSet[syFol][i] | SymSet[repFol][i];
  GenError(n);
  while (!In(s, Sym)) Get();
  return In(SymSet[syFol], Sym);
}

void pruebaParser::prueba01()
{
	
	char Tipe[100];
	int devuelto;
	ts2006* gestor;
	cout << "--INICIO DE LA COMPILACIÓN--\n"; 
	// creación del gestor
	gestor=new ts2006(); 
	// creación de una tabla
	devuelto=gestor->crear_tabla(); 
	// creación de una entrada
	devuelto=gestor->crear_entrada(1,"eprueba"); 
	// asignar tipo de entrada
	devuelto=gestor->asignar_tipo_entrada(
	1,"eprueba","tprueba");
	devuelto=gestor->crear_atributo_cadena(
	1,"eprueba","contenido","");
	while (Sym == palabraSym) {
		Get();
		
		LexString(Tipe, sizeof(Tipe) - 1);
		cout << "Palabra detectada = " << Tipe << " ...\n"; 
		// Anotaremos la última palabra
		// en la tabla 1, 
		// en la entrada eprueba
		// en el atributo contenido
		devuelto=gestor->asignar_valor_atributo_cadena(
		1,"eprueba","contenido",Tipe);
	}
	
	cout << "--FIN DE LA COMPILACIÓN--\n"; 
	// escribiremos el contenido de la tabla 1 al final
	// (se verá la última palabra detectada)
	devuelto=gestor->escribir_tabla(1,"prueba01.txt");
	delete gestor; // destruccion del gestor
	;
}



void pruebaParser::Parse()
{ Scanner->Reset(); Get();
  prueba01();
}

