#include <stdint.h>
/**
* \brief  funcion que hace la suma(AND) entre dos registros, suma Rd con Rn y almacena el valor en Rd
* \param Rd operador 1
* \param Rn operador 2
* \return no retorna valor
*/
void ADD(uint32_t *Rd,uint32_t *Rn)
{
	*Rd=*Rn+*Rd;
}
/**
* \brief  funcion que hace la OR logica bit a bit
* \param Rd operador 1
* \param Rn operador 2
* \return no retorna valor
*/
void Xor(uint32_t *Rd,uint32_t *Rn)
{
	*Rd = *Rd ^*Rn;

 }
/**
* \brief  funcion que hace la OR exclusiva bit a bit
* \param Rd operador 1
* \param Rn operador 2
* \return un entero de 32 bits positivos
*/
 uint32_t Or(uint32_t *Rd,uint32_t *Rn)
 {
	if(*Rd|*Rn>2^32)
	{
		printf("\nC: 1\n");
    }
    else
    {
		printf("\nC: 0\n");
	}

    return (*Rd | *Rn);
}
/**
* \brief  funcion que hace la AND exclusiva bit a bit
* \param Rd operador 1
* \param Rn operador 2
* \return un entero de 32 bits positivos
*/
uint32_t And (uint32_t *Rd,uint32_t Y)
{
	return (*Rd & *Rn);
}
/**
* \brief  funcion que hace la MOV, para esto el usuario debe escribir un valor en un registro
* \param Rd operador 1
* \param Rn operador 2
* \return un entero de 32 bits positivos
*/
uint32_t Movs (uint32_t *Rd,uint32_t *Rn)
{
	*Rd=*Rn;
}
/**
* \brief  funcion que hace la SUB (la resta entre los dos registros)
* \param Rd operador 1
* \param Rn operador 2
* \return un entero de 32 bits positivos
*/
uint32_t Subs (uint32_t X,uint32_t Y)
{
	if(*Rd|*Rn==0)
	{
		printf("\nZ: 1\n");
		printf("\nC: 1\n");
    }
    else
    {
		printf("\nZ: 0\n");
		printf("\nC: 0\n");
    }
	return (*Rd-*Rn);
}

