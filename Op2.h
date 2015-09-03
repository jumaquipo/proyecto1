#include <stdint.h>
/**
* \brief  funcion que hace el desplazamioento logico a la izquierda
* \param Rd operador 1
* \param Rn operador 2
* \param y operador 3
* \return no retorna valor
*/
void LSLS(uint32_t *Rd,uint32_t *Rn,uint32_t y)
{
	*Rd=*Rn<<y;
}
/**
* \brief  funcion que hace el desplazamioento logico a la derecha
* \param Rd operador 1
* \param Rn operador 2
* \param y operador 3
* \return no retorna valor
*/
void LSRS (uint32_t *Rd,uint32_t *Rn,int y)
{
	*Rd=*Rn>>y;
}

/**
* \brief  funcion que hace la rotacion a la derecha
* \param Rd operador 1
* \param Rn operador 2
* \param y operador 3
* \return no retorna valor
*/
void ROR (uint32_t *Rd,uint32_t *Rn,int y)
{
	uint32_t s;
	s=*Rn>>(32−y);
	*Rd=*Rn<<y;
	*Rd=*Rd|s;
}
/**
* \brief  funcion que hace el desplazamioento aritmetico a la derecha
* \param Rd operador 1
* \param Rn operador 2
* \param y operador 3
* \return no retorna valor
*/
void ASR (uint32_t *Rd,uint32_t *Rn,int y)
{
	uint32_t s;
	s=~0<<(32−y);
	*Rd=*Rn>>y;
	*Rd=*Rd|s;

}
/**
* \brief  funcion que hace la AND entre el operador 1 y el complemento del operador 2
* \param Rd operador 1
* \param Rn operador 2
* \return no retorna valor
*/
void Bic(uint32_t *Rd,uint32_t *Rn)
{
	*Rd&=~*Rn;

}
/**
* \brief  funcion que guarda el complemento del registro del operador 1 en operador 2
* \param Rd operador 1
* \param Rn operador 2
* \return no retorna valor
*/
void Mvn (uint32_t *Rd,uint32_t *Rn)
{
	*Rd=~*Rn;
}
/**
* \brief  funcion que cambia el orden de los bytes 
* \param Rd operador 1
* \param Rn operador 2
* \return no retorna valor
*/
void REV (uint32_t *Rd,uint32_t *Rn)
{
	uint32_t x=255;
	*Rd=*Rm<<24;
	*Rd= *Rd|(Rn>>24);
	*Rd=*Rd|((*Rn&(x<<8))<<8);
	*Rd=*Rd|((*Rn&(x<<16))>>8);
}


