#include <stdint.h>
void ADD(uint32_t *Rd,uint32_t *Rn){
*Rd=*Rn+*Rd;
}
void Xor(uint32_t *Rd,uint32_t *Rn){
*Rd = *Rd ^*Rn;

   }
uint32_t Or(uint32_t *Rd,uint32_t *Rn){
    if(*Rd|*Rn>2^32){
        printf("\nC: 1\n");
    }
    else
    {
        printf("\nC: 0\n");
    }


    return (*Rd | *Rn);
}

uint32_t And (uint32_t *Rd,uint32_t Y){
return (*Rd & *Rn);
}
uint32_t Movs (uint32_t *Rd,uint32_t *Rn){
    *Rd=*Rn;
}


uint32_t Subs (uint32_t X,uint32_t Y){
    if(*Rd|*Rn==0){
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

