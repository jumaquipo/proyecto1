#include <stdint.h>
#include <stdlib.h>
#include "mregistros.h"
void Mregistro(uint32_t *ptro,int n){
    char i;
    system("cls");//esta funcion de la libreria <stdlib.h> Limpia el terminal
    system("COLOR 02");//esta funcion de la libreria <stdlib.h> cambia color el primer numero fondo y el segundo el texto
    int x;
    printf("##########################################################################\n");
    printf("##########################################################################\n");
    printf("                               REGISTROS:                                 \n");
    for(i=0;i<n;i++){//un for hasta la cantidad de registros

              printf("            REGISTRO #0%d : %d \n",i+1,ptro[i]);//imprime en la tarminal elvalor de cada registro

        }
        system("COLOR 02");
    printf("\n");
    printf("##########################################################################\n");
    printf("##########################################################################\n");
    printf("\n");

}
