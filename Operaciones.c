#include <stdint.h>
#include "Operaciones.h"
uint32_t Xor(uint32_t X,uint32_t Y){
    printf("HolA");
   return (X^Y);
   }
uint32_t Or(uint32_t X,uint32_t Y){
    if(X|Y<2^32){
        printf("\nC: 1");
    }
    else
    {
        printf("\nC: 1");
    }
    printf("HolA");
    return (X|Y);
}

uint32_t And (uint32_t X,uint32_t Y){
return (X&Y);
}
uint32_t CopReg (uint32_t X){
    uint32_t Y;
    Y=X;
    return (Y);
}
uint32_t Resta (uint32_t X,uint32_t Y){
      return (X-Y);
}

