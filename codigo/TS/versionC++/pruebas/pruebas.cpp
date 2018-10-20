//****************************************************************
//   CPLUS2\SCAN_C.FRM
//   Coco/R C++ Support Frames.
//   Author: Frankie Arzu <farzu@uvg.edu.gt>
//
//   Jun 12, 1996  Version 1.06
//      Many fixes and suggestions thanks to
//      Pat Terry <p.terry@.ru.ac.za>
//   Oct 31, 1999  Version 1.14
//      LeftContext Support
//   Mar 24, 2000  Version 1.15
//      LeftContext Support no longer needed
//****************************************************************

#include "pruebac.hpp"
#include "pruebas.hpp"

#define Scan_Ch        Ch
#define Scan_NextCh    NextCh
#define Scan_ComEols   ComEols
#define Scan_CurrLine  CurrLine
#define Scan_CurrCol   CurrCol
#define Scan_LineStart LineStart
#define Scan_BuffPos   BuffPos
#define Scan_NextLen   NextSym.Len

int pruebaScanner::STATE0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                  1,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                  1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int pruebaScanner::CheckLiteral(int id)
{ char c;
  c =  CurrentCh(NextSym.Pos);
  if (IgnoreCase) c = Upcase(c);
  switch (c) {
  
  }
  return id;
}

int pruebaScanner::Comment()
{ int Level, StartLine, OldCol;
  long OldLineStart;

  Level = 1; StartLine = CurrLine;
  OldLineStart = LineStart; OldCol = CurrCol;
  
  return 0;
}

int pruebaScanner::Get()
{ int state, ctx;

  start:
    while (Scan_Ch == ' ') Scan_NextCh();
    

    CurrSym = NextSym;
    NextSym.Init(0, CurrLine, CurrCol - 1, BuffPos, 0);
    NextSym.Len  = 0; ctx = 0;

    if (Ch == EOF_CHAR) return EOF_Sym;
    state = STATE0[Ch];
    while(1) {
      Scan_NextCh(); NextSym.Len++;
      switch (state) {
       /* State 0; valid STATE0 Table
      case 0:
      	if (Scan_Ch >= 'A' && Scan_Ch <= 'Z' ||
          Scan_Ch == '_' ||
          Scan_Ch >= 'a' && Scan_Ch <= 'y') state = 1; else
      	return No_Sym;
      	break;
       --------- End State0 --------- */
      case 1:
      	if (Scan_Ch >= 'A' && Scan_Ch <= 'Z' ||
      	    Scan_Ch == '_' ||
      	    Scan_Ch >= 'a' && Scan_Ch <= 'y') /*same state*/; else
      	return palabraSym;
      	break;
      
      default: return No_Sym; /* Scan_NextCh already done */
      }
    }
}

