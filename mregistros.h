#include <stdint.h>
/**
* \brief  funcion que imprime el registro del operador 1
* \param ptro operador 1
* \param n operador 2
* \return no retorna valor
*/
void Mregistro(uint32_t *ptro,int n)
{
    char i;
    int x;
	printf("                            REGISTROS:                                    \n");
    for(i=0;i<n;i++)
	{
		printf(" registro #%d  : %d \n",i+1,ptro[i]);
	}
}
