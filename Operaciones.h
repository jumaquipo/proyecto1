#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//PROFE SE TUVO UN PROBLEMA CON EL MSYS DEBIDO A ESO NO PUDIMOS TERMINAR CON LA INTERFAS COMO HUBIESEMOS QUERIDO

/**
 *  \brief     Esta función permite que el puntero operador 1 apute a la variable PC DEL MAIN, la modifica con el valor del PC. 
 *  \param     P operador 1 puntero tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para modificar el valor del contador PC. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
*/
void RPC(int *P);

/**
 *  \brief     Esta función realiza la respectiva suma con carry entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para realizar la ADD con carry. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void ADC(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función realiza la respectiva suma entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para realizar la ADD. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void ADD(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función realiza la OR exclusiva bit a bit entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para realizar la EOR. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void EOR(uint32_t *Rd,uint32_t Rn,uint32_t Rm);


/**
 *  \brief     Esta función realiza la OR logica bit a bit entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    Retorna un valor tipo entero de 32 bits.
 *  \details   Esta función se utiliza para realizar la OR. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
uint32_t OR(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función realiza la AND bit a bit entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    Retorna un valor tipo entero de 32 bits.
 *  \details   Esta función se utiliza para realizar la AND. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
uint32_t AND (uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función escribe un valor en un registro entre el operador 1 y el operador 2, el resultdo lo guarda en el operador 1. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    Retorna un valor tipo entero de 32 bits.
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
uint32_t MOV (uint32_t *Rd,uint32_t Rn);

/**
 *  \brief     Esta función la realiza una resta entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    Retorna un valor entero de 32 bits.
 *  \details   Esta función se utiliza para hacer una resta  logica 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
uint32_t SUB (uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función hace la resta entre el operador 1 y el operador 2, pero no guarda el resultado solo modifica banderas. 
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para realizar una resta pero no guarda resultado. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void CMP(uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función hace la suma entre el operador 1 y el operador 2, pero no guarda el resultado solo modifica banderas. 
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    Retorna un valor tipo entero de 32 bits.
 *  \details   Esta función se utiliza para realizar una suma pero no guarda resultado. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
uint32_t CMN (uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función hace la multiplicacion entre los registros del operador 2 y el operador 3, ademas guarda los 32 bits menos significativos en el operador 1. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para realizar multiplicacion con número sih signo. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void MUL (uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función realiza la AND bit a bit entre el operador 1 y el operador 2, pero no guarda el resultado, solo modifica banderas. 
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función cumple la misma función que la instrucción AND, solo que en este caso se modifican las banderas. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void TST (uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función hace el desplazamiento logico a la izquierda entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void LSL(uint32_t *Rd,uint32_t Rn,uint32_t y);

/**
 *  \brief     Esta función hace el desplazamiento logico a la derecha entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void LSR (uint32_t *Rd,uint32_t Rn,int y);

/**
 *  \brief     Esta función hace la rotación a la derecha entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     y operador 3 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para realizar la rotación a la derecha. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void ROR (uint32_t *Rd,uint32_t Rn,int y);

/**
 *  \brief     Esta función hace el desplazamieento aritmetico a la derecha entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     y operador 3 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para realizar el desplazamiento aritmetico a la derecha. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void ASR (uint32_t *Rd,uint32_t Rn,int y);

/**
 *  \brief     Esta función cambia el orden de los bytes entre el operador 1 y el operador 2.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para cambiar el orden de los bytes. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void REV (uint32_t *Rd,uint32_t Rn);

 /**
 *  \brief     Esta función realiza la AND entre el operador 2 y el complemento del operador 3, el resultdo lo guarda en el operador 1.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para realizar la AND. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BIC (uint32_t *Rd,uint32_t Rn,uint32_t Rm);

 /**
 *  \brief     Esta función guarda el complemento del registro del operador 2 en operador 1.
 *  \param     Rd operador 1 tipo puntero de 32 bits
 *  \param     Rn operador 2 tipo entero de 32 bits
 *  \return    no retorna valor
 *  \details   Esta función se utiliza para guardar el complemento del registro. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void MVN(uint32_t *Rd,uint32_t Rn);

/**
 *  \brief     Esta función no realiza niguna operación.
 *  \param     No recive ningún parametros (variables)
 *  \return    Por esta razón no retorna ningun valor.
 *  \details   Esta función no hace nada. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void NOP();

 /**
 *  \brief     Esta función obtiene el complemento a dos de un numero, entre el operador 1 y el operador 2.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener el complemento a dos de un número. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void RSB (uint32_t *Rd,uint32_t Rn);

 /**
 *  \brief     Esta función obtiene la resta con carry, entre el operador 2 y el operador 3, almacena el resultado en el operador 1.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener la resta con carry. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void SBC (uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función realiza un salto cuando la bandera de Zero sea igual a 1.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando se active la bandera de Zero. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BEQ(int Sal);

/**
 *  \brief     Esta función realiza un salto cuando la bandera de Zero sea igual a 0.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 0 la bandera de Zero. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BNE(int Sal);


v/**
 *  \brief     Esta función realiza un salto cuando haya un carry (sea igual a 1).
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando se active la bandera de carry. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BCS(int Sal);

/**
 *  \brief     Esta función realiza un salto cuando la bandera de carry sea igual a 0.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 0 la bandera de carry. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BCC(int Sal);

/**
 *  \brief     Esta función realiza un salto cuando la bandera de negativo sea igual a 1.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando se active la bandera de negativo. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BMI(int Sal);

/**
 *  \brief     Esta función realiza un salto cuando la bandera de negativo sea igual a 0.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 0 la bandera de negativo. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BPL(int Sal);


/**
 *  \brief     Esta función realiza un salto cuando la bandera de overflow sea igual a 1.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando se active la bandera de overflow. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BVS(int Sal)

/**
 *  \brief     Esta función realiza un salto cuando la bandera de overflow sea igual a 0.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 0 la bandera de overflow. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
 void BVL(int Sal)

/**
 *  \brief     Esta función realiza un salto cuando la bandera de carry sea igual a 1 y la bandera de Zero sea igual a 0.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 1 el carry y en 0 el zero. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BHI(int Sal)

/**
 *  \brief     Esta función realiza un salto cuando la bandera de carry sea igual a 0 ó la bandera de Zero sea igual a 1.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 0 el carry ó en 1 el zero. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BLS(int Sal);


v/**
 *  \brief     Esta función realiza un salto cuando la bandera de negativo sea igual a la bandera de overflow.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando sean iguales las banderas de negativo y overflow.
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BGE(int Sal)

/**
 *  \brief     Esta función realiza un salto cuando la bandera de negativo sea diferente a la bandera de overflow.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando las banderas de negativo y overflow sean diferentes. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BLT(int Sal)

/**
 *  \brief     Esta función realiza un salto cuando la bandera de negativo sea igual a overflow y la bandera de Zero sea igual a 0.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando esten igualeslas banderas negativo y overflow y en 0 el zero. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BGT(int Sal)

/**
 *  \brief     Esta función realiza un salto cuando la bandera de Zero sea igual a 1 o la bandera de negativo sea diferente al overflow. 
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 1 el zero o sean diferentes las banderas de negativo y de overflow en 0 el zero.
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BLE(int Sal)

/**
 *  \brief     Esta función realiza un salto de lo que haya acumulado en pc hasta un número. 
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando desde el valor de pc hasta otro número especifico.
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void B(int Sal)

/**
 *  \brief     Esta función realiza un salto de lo que haya acumulado en pc hasta un número. 
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando desde el valor de pc hasta otro número especifico.
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BL(int Sal)

/**
 *  \brief     Esta función realiza un salto de lo que haya acumulado en pc. 
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando desde el valor de pc.
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BX(int Sal);

/**
 *  \brief     Esta función imprime las banderas en el menu. 
 *  \param     No recive parametros.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando desde el valor de pc.
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void PBanderas ();

 /**
 *  \brief     Esta función limpia los registros.
 *  \param     ptra operador 1 tipo puntero de 32 bits.
 *  \param     memor operador 2 tipo puntero de 32 bits.
 *  \return    no retorna valor
 *  \details   Esta función se utiliza para borrar todo el historial de los registros. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void LRegistros(uint32_t *ptra,uint32_t *memor);

/**
 *  \brief     Esta función muestra los registros en memoria.
 *  \param     memor operador 1 tipo puntero de 32 bits.
 *  \return    no retorna valor
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void Mmemor(uint32_t *memor);

/**
 *  \brief     Esta función crea una variable global en operador 1 para guardadr los registros en el operador 1.
 *  \param     m operador 1 tipo puntero de 32 bits.
 *  \return    no retorna valor
 *  \details   Esta función se utiliza para guardar los registro en memoria. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void OBMEMOR(uint32_t *m);

/**
 *  \brief     Esta función pone los datos en la pila.
 *  \param     Rd operador 1 tipo entero de 32 bits.
 *  \param     Rn operador 2 tipo enetero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    no retorna valor
 *  \details   Esta función para guardar los datos en la memoria de la pila, solomanete resive 8 registros del 0-7. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void PUSH (uint32_t Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función obtiene registros.
 *  \param     m operador 1 puntero tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
*/
void OBR(uint32_t *m);

/**
 *  \brief     Esta función guarda carga dos registros consecutivos con dos palabras (32 bits) consecutivas de memoria..
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    no retorna valor
 *  \details   Esta función para guardar los datos en la memoria de la pila, solomanete resive 8 registros del 0-7. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void LDR(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función guarda un entero sin signo de tamaño byte. al escribirse el dato sobre el registro destino se extiende con ceros hasta los 32 bits.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    no retorna valor
 *  \details   Esta función para guardar los datos en la memoria de la pila, solomanete resive 8 registros del 0-7. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void LDRB(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función carga en los byte 0,1 del operador 1  Mem(Rn+Rm). 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    no retorna valor
 *  \details   Esta función para guardar los datos en la memoria de la pila, solomanete resive 8 registros del 0-7. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void LDRH(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función carga un entero con signo de tamaño byte. Al escribirse el dato sobre el registro destino se extiende con el bit de signo hasta los 32 bits.. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    no retorna valor
 *  \details   Esta función para guardar los datos en la memoria de la pila, solomanete resive 8 registros del 0-7. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void LDRSB(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función carga un entero con signo de 16 bits. Al escribirse el dato sobre el registro destino se extiende con el bit de signo hasta los 32 bits.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    no retorna valor
 *  \details   Esta función para guardar los datos en la memoria de la pila, solomanete resive 8 registros del 0-7. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void LDRSH(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función guarda 32 bits en el operador 1.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    no retorna valor
 *  \details   Esta función para guardar los datos en la memoria de la pila, solomanete resive 8 registros del 0-7. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void STR(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función escribe en memoria un entero de tamaño byte obtenido de los 8 bits menos significativos del registro fuente..
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    no retorna valor
 *  \details   Esta función para guardar los datos en la memoria de la pila, solomanete resive 8 registros del 0-7. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void STRB(uint32_t *Rd,uint32_t Rn,uint32_t Rm);

/**
 *  \brief     Esta función escribe en memoria un entero de 16 bits obtenido de los 16 bits menos significativos del registro fuente..
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    no retorna valor
 *  \details   Esta función para guardar los datos en la memoria de la pila, solomanete resive 8 registros del 0-7. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void STRH(uint32_t *Rd,uint32_t Rn,uint32_t Rm);