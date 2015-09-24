#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Operaciones.h"
int c,s,o,n,Pc=0,LR=0;//Variables globales banderas

void RPC(int *P)//Un puntero apuntado a la variable PC DEL MAIN la modifica con el valor del PC
{
    *P=Pc; //modifica el PC del (Main)
}
void ADC(uint32_t *Rd,uint32_t Rn,uint32_t Rm)
{
    Rm=Rm+c; //le suma la bandera de carry
    *Rd=Rn + Rm;//Este puntero Modifica elregistro de destino con el resultado de la suma de Rn y Rm
    Pc+=2;//Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
if(((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)==0)&&((*Rd>>31)==0))||((((Rn>>31))==0) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)&1==1))){
       c=1; //Bandera de carry se activa si el ultimo bit de los dos numeros es uno y el de el Rd da 0 o 1
    }
else
    {
       c=0;//No se activa el carry
    }
if((Rn>>31==0 && Rm>>31==0 && (*Rd>>31)&1==1 )||(((Rn>>31)&1==1)&&((Rm>>31)&1==1)&&(*Rd>>31==0))){
    o=1; //Se activa si el ultimo bit de los dos registros son iguales y cambia  esto quiere decir que de la suma de dos nuemros de mismo signo da uno de diferente signo
}
else{
    o=0;//No se activa Bandera sobreflujo
}
if((*Rd>>31)&1==1){
    n=1; //si el ultimo bit es 1 es negativo
}
else{
    n=0;// Si no es positivo
}
if (*Rd==0)
        {

    s=1;//Si el registro de destino da 0 se activa
        }
else{
    s=0;//De lo contrario no se activa la bandera
}



}
void ADD(uint32_t *Rd,uint32_t Rn,uint32_t Rm)
      {
      *Rd=Rn + Rm;// modifica en el destino por el resultado de la suma
      Pc+=2;
if(((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)==0)&&((*Rd>>31)==0))||((((Rn>>31))==0) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)&1==1))){
       c=1;
    }
else
    {
       c=0;
    }
if((Rn>>31==0 && Rm>>31==0 && (*Rd>>31)&1==1 )||(((Rn>>31)&1==1)&&((Rm>>31)&1==1)&&(*Rd>>31==0))){
    o=1;
}
else{
    o=0;
}
if((*Rd>>31)&1==1){
    n=1;
}
else{
    n=0;
}
if (*Rd==0){
    s=1;
}
else{
    s=0;
}


}
void EOR(uint32_t *Rd,uint32_t Rn,uint32_t Rm){
*Rd = Rn ^Rm; //modifica en el Destino el resultado de la EOR
Pc+=2;
if (*Rd==0){
    s=1;
}
else{
    s=0;
}
if((*Rd>>31)&1==1 ){
    n=1;
}
else{
    n=0;
}


   }
uint32_t OR(uint32_t *Rd,uint32_t Rn,uint32_t Rm){
   *Rd=Rn|Rm; //Modifica en el registro de destino el resultado de la OR
   Pc+=2;
   if (*Rd==0){
    s=1;
}
else{
    s=0;
}
if((*Rd>>31)&1==1 ){
    n=1;
}
else{
    n=0;
}

}

uint32_t AND (uint32_t *Rd,uint32_t Rn,uint32_t Rm){
*Rd=Rn & Rm; //Modifica en el registro el resultado de la AND
Pc+=2;
   if (*Rd==0){
    s=1;
}
else{
    s=0;
}
if((*Rd>>31)&1==1 ){
    n=1;
}
else{
    n=0;
}
printf("\nCARRY: %d\n",c);
    printf("ZERO: %d\n",s);
    printf("OVERFLOW: %d\n",o);
    printf("NEGATIVO: %d",n);
}
uint32_t MOV (uint32_t *Rd,uint32_t Rn){
    *Rd=Rn;//Mueve el valor del registro que se desea copiar al registro de destino
    Pc+=2;
if (*Rd==0){
    s=1;
}
else{
    s=0;
}
if((*Rd>>31)&1==1 ){
    n=1;
}
else{
    n=0;
}

}


uint32_t SUB (uint32_t *Rd,uint32_t Rn,uint32_t Rm){
Pc+=2;
Rm=~Rm+1;
*Rd=Rn+Rm;




 if(((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)==0)&&((*Rd>>31)==0))||((((Rn>>31))==0) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)&1==1))){
       c=1;
    }
else
    {
       c=0;
    }
if((Rn>>31==0 && Rm>>31==0 && (*Rd>>31)&1==1 )||(((Rn>>31)&1==1)&&((Rm>>31)&1==1)&&(*Rd>>31==0))){
    o=1;
}
else{
    o=0;
}
if((*Rd>>31)&1==1){
    n=1;
}
else{
    n=0;
}
if (*Rd==0){
    s=1;
}
else{
    s=0;
}

}
void CMP(uint32_t Rn,uint32_t Rm){
    uint32_t Rd;
    Pc+=2;
    Rm=~Rm+1;
Rd=Rn+Rm;
if(((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)==0)&&((Rd>>31)==0))||((((Rn>>31))==0) &&((Rm>>31)&1==1)&&((Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((Rd>>31)&1==1))){
        c=1;
    }
else
    {
       c=0;
    }
if((Rn>>31==0 && Rm>>31==0 && ((Rn+Rm)>>31)&1==1 )||(((Rn>>31)&1==1)&&((Rm>>31)&1==1)&&((Rn+Rm)>>31==0))){
    o=1;
}
else{
    o=0;
}
if((Rn+Rm>>31)&1==1){
    n=1;
}
else{
    n=0;
}
if (Rn+Rm==0){
    s=1;
}
else{
    s=0;
}
}
uint32_t CMN (uint32_t Rn,uint32_t Rm){
    uint32_t Rd;
    Rd=Rn+Rm;
    Pc+=2;

if(((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)==0)&&((Rd>>31)==0))||((((Rn>>31))==0) &&((Rm>>31)&1==1)&&((Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((Rd>>31)&1==1))){
       c=1;
    }
else
    {
       c=0;
    }
if((Rn>>31==0 && Rm>>31==0 && ((Rn+Rm)>>31)&1==1 )||(((Rn>>31)&1==1)&&((Rm>>31)&1==1)&&((Rn+Rm)>>31==0))){
    o=1;
}
else{
    o=0;
}
if((Rn+Rm>>31)&1==1){
    n=1;
}
else{
    n=0;
}
if (Rn+Rm==0){
    s=1;
}
else{
    s=0;
}


}
void MUL (uint32_t *Rd,uint32_t Rn,uint32_t Rm){
Pc+=2;
*Rd=(Rn * Rm);
if((*Rd>>31)&1==1){
    n=1;
}
else{
    n=0;
}
if (*Rd==0){
    s=1;
}
else{
    s=0;
}


}
void TST (uint32_t Rn,uint32_t Rm){
    Pc+=2;
 if (Rn&Rm==0){
    s=1;
}
else{
    s=0;
}
if(((Rn&Rm)>>31)&1==1 ){
    n=1;
}
else{
    n=0;
}
}
void LSL(uint32_t *Rd,uint32_t Rn,uint32_t y){
    Pc+=2;
*Rd=Rn<<y;//Hace un desplasamiento hacia la isquierda
Rn=Rn>>(32-y);

  if((Rn&1)==1){
        c=1;
}
else
{
    c=0;
}
if((*Rd>>31)&1==1){
    n=1;
}
else{
    n=0;
}
if (*Rd==0){
    s=1;
}
else{
   s=0;

}

}
void LSR (uint32_t *Rd,uint32_t Rn,int y){
    Pc+=2;
   * Rn=Rn>>(y-1);

  if((Rn&1)==1){
        c=1;
}
else
{
    c=0;
}
if((*Rd>>31)&1==1){
    n=1;
}
else{
    n=0;
}
if (*Rd==0){
    s=1;
}
else{
   s=0;

}

}
void ROR (uint32_t *Rd,uint32_t Rn,int y){
    Pc+=2;
uint32_t s;
    s=(Rn>>(32-y))&2147483647;
*Rd=Rn<<y;
*Rd=*Rd|s;
*Rd=*Rd&4294967295;
printf("%d",Rd);





if((*Rd>>31)&1==1){
    n=1;
}
else{
    n=0;
}
if (*Rd==0){
    s=1;
}
else{
   s=0;

}

}


void ASR (uint32_t *Rd,uint32_t Rn,int y){
    Pc+=2;
uint32_t s;
s=~0<<(32-y);
*Rd=Rn>>y;
*Rd=*Rd|s;
if((*Rd>>31)&1==1){
    n=1;
}
else{
    n=0;
}
if (*Rd==0){
    s=1;
}
else{
   s=0;

}
}


void REV (uint32_t *Rd,uint32_t Rn){
    Pc+=2;
uint32_t x=255,y,p,r;
*Rd=(Rn&x)<<24;
y= (Rn>>24)&x;
*Rd=*Rd|((Rn&(x<<8))<<8);
*Rd=*Rd|((Rn&(x<<16))>>8);

}





void BIC (uint32_t *Rd,uint32_t Rn,uint32_t Rm){
    Pc+=2;
   *Rd=Rn & ~Rm;
   if((*Rd>>31)&1==1){
    n=1;
}
else{
    n=0;
}
if (*Rd==0){
    s=1;
}
else{
   s=0;

}
}

void MVN(uint32_t *Rd,uint32_t Rn){
    Pc+=2;

*Rd=~Rn;
if((*Rd>>31)&1==1){
    n=1;
}
else{
    n=0;
}
if (*Rd==0){
    s=1;
}
else{
   s=0;

}

}
void NOP(){

}
void RSB (uint32_t *Rd,uint32_t Rn){
    Pc+=2;
*Rd=~Rn+1;
if((*Rd>>31)&1==1){
    n=1;
}
else{
    n=0;
}
if (*Rd==0){
    s=1;
}
else{
   s=0;

}
}
void SBC (uint32_t *Rd,uint32_t Rn,uint32_t Rm){
    Pc+=2;
Rm=~Rm+1;
Rm=Rm-c;
*Rd=Rn+Rm;




 if(((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)==0)&&((*Rd>>31)==0))||((((Rn>>31))==0) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)&1==1))){
       c=1;
    }
else
    {
       c=0;
    }
if((Rn>>31==0 && Rm>>31==0 && (*Rd>>31)&1==1 )||(((Rn>>31)&1==1)&&((Rm>>31)&1==1)&&(*Rd>>31==0))){
    o=1;
}
else{
    o=0;
}
if((*Rd>>31)&1==1){
    n=1;
}
else{
    n=0;
}
if (*Rd==0){
    s=1;
}
else{
    s=0;
}
}

void BEQ(int Sal){
    if(s==1){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }
}
void BNE(int Sal){
    if(s==0){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }
}
void BCS(int Sal){
    if(c==1){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }
}
void BCC(int Sal){
    if(c==0){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }
}
void BMI(int Sal){
    if(n==1){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }
}
void BPL(int Sal){
    if(n==o){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }
}
void BVS(int Sal){
    if(o==1){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }
}
void BVL(int Sal){
    if(o==0){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }
}
void BHI(int Sal){
    if(c==1&&s==0){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }
}

void BLS(int Sal){
    if(c==0||s==1){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }
}
void BGE(int Sal){
    if(n==o){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }
}
void BLT(int Sal){
    if(n!=o){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }

}
void BGT(int Sal){
    if(s==0&&n==o){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }
}
void BLE(int Sal){
    if(s==1||n!=o){
        Pc+=Sal*2;
    }
    else{
    Pc+=2;
    }
}
void B(int Sal){

Pc+=Sal*2;
}
void BL(int Sal){
LR=Pc+2;
Pc+=Sal*2;
}
void BX(int Sal){
Pc=Sal;
}
void OBLR (int *P){
*P=LR;
}
void PBanderas (){
    printf("CARRY:----- %d\n",c);
    printf("ZERO:------ %d\n",s);
    printf("OVERFLOW:-- %d\n",o);
    printf("NEGATIVO:-- %d\n",n);
}





