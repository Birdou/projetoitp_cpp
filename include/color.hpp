
/*
* Essa biblioteca não deve ser usada com fins lucrativos ou
* comerciais.
* Propriedade intelectual de Felipe Sena de Medeiros - IMD/UFRN
* Última atualização: 14/06/2021
*/

#ifndef COLOURPLUS_H
#define COLOURPLUS_H

#include <iostream>
#include <cstdlib>
#include <sstream>

#ifndef NOCOLORED
#define aRESET "[0m"

#define eBOLD "[1m"
#define eDIM "[2m"
#define eUNDERLINED "[4m"
#define eBLINK "[5m"
#define eREVERSE "[7m"
#define eHIDDEN "[8m"

#define fRESET "[39m"
#define fBLACK "[30m"
#define fRED "[31m"
#define fGREEN "[32m"
#define fYELLOW "[33m"
#define fBLUE "[34m"
#define fMAGENTA "[35m"
#define fCYAN "[36m"
#define fLIGHT_GRAY "[37m"
#define fDARK_GRAY "[90m"
#define fLIGHT_RED "[91m"
#define fLIGHT_GREEN "[92m"
#define fLIGHT_YELLOW "[93m"
#define fLIGHT_BLUE "[94m"
#define fLIGHT_MAGENTA "[95m"
#define fLIGHT_CYAN "[96m"
#define fWHITE "[97m"

#define bRESET "[49m"
#define bBLACK "[40m"
#define bRED "[41m"
#define bGREEN "[42m"
#define bYELLOW "[43m"
#define bBLUE "[44m"
#define bMAGENTA "[45m"
#define bCYAN "[46m"
#define bLIGHT_GRAY "[47m"
#define bDARK_GRAY "[100m"
#define bLIGHT_RED "[101m"
#define bLIGHT_GREEN "[102m"
#define bLIGHT_YELLOW "[103m"
#define bLIGHT_BLUE "[104m"
#define bLIGHT_MAGENTA "[105m"
#define bLIGHT_CYAN "[106m"
#define bWHITE "[107m"
#else
#define eRESET
#define eBOLD
#define eDIM
#define eUNDERLINED
#define eBLINK
#define eREVERSE
#define eHIDDEN

#define fRESET
#define fBLACK
#define fRED
#define fGREEN
#define fYELLOW
#define fBLUE
#define fMAGENTA
#define fCYAN
#define fLIGHT_GRAY
#define fDARK_GRAY
#define fLIGHT_RED
#define fLIGHT_GREEN
#define fLIGHT_YELLOW
#define fLIGHT_BLUE
#define fLIGHT_MAGENTA
#define fLIGHT_CYAN
#define fWHITE

#define bRESET
#define bBLACK
#define bRED
#define bGREEN
#define bYELLOW
#define bBLUE
#define bMAGENTA
#define bCYAN
#define bLIGHT_GRAY
#define bDARK_GRAY
#define bLIGHT_RED
#define bLIGHT_GREEN
#define bLIGHT_YELLOW
#define bLIGHT_BLUE
#define bLIGHT_MAGENTA
#define bLIGHT_CYAN
#define bWHITE
#endif

#define colorspace(command, color) \
	std::cout << color;            \
	command;                       \
	std::cout << aRESET;

#define colorstream(stream, color) \
	color << stream << aRESET

#endif