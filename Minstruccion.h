#include  <curses.h>
#include "decoder.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 *  \brief     Esta función muestra las instruciones en el operador 1.
 *  \param     P operador 1 estructuta tipo instruction.
 *  \return    No retorna valor.
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
*/
void Minstruccion(instruction_t instruction);

/**
 *  \brief     Esta función obtiene los registros, los almacena en el operador 1.
 *  \param     a operador 1 puntero tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
*/
void ORL(uint8_t *a);

