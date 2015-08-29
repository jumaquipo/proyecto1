#include <stdint.h>
void LSLS(uint32_t *Rd,uint32_t *Rn,uint32_t y){
*Rd=*Rn<<y;
}
void LSRS (uint32_t *Rd,uint32_t *Rn,int y){
   *Rd=*Rn>>y;
}

void ROR (uint32_t *Rd,uint32_t *Rn,int y){
uint32_t s;
s=*Rn>>(32−y);
*Rd=*Rn<<y;
*Rd=*Rd|s;
}




void ASR (uint32_t *Rd,uint32_t *Rn,int y){
uint32_t s;
s=~0<<(32−y);
*Rd=*Rn>>y;
*Rd=*Rd|s;

}
void Bic(uint32_t *Rd,uint32_t *Rn){
*Rd&=~*Rn;

}
void Mvn (uint32_t *Rd,uint32_t *Rn){
*Rd=~*Rn;
}
void REV (uint32_t *Rd,uint32_t *Rn){
uint32_t x=255;
*Rd=*Rm<<24;
*Rd= *Rd|(Rn>>24);
*Rd=*Rd|((*Rn&(x<<8))<<8);
*Rd=*Rd|((*Rn&(x<<16))>>8);
}


