#include "Operaciones.h"
#include  <curses.h>
#include "io.h"
uint32_t c,s,o,n,Pc=0,LR=0;//Variables globales banderas
uint32_t *R,counter=0;
uint8_t *memoria;
char type;

void OBMEMOR(uint8_t *a){//Obtiene un puntero con la direccion de el arreglo de memoria
memoria=a;// se iguala  la variable memoria la cual es un puntero a la direccion de memoria
}
void OBR(uint32_t *m){//Obtiene un puntero con la direccion de el arreglo de Registros
R=m; //se iguala la Variable R a la direccion de los registros
}

void RPC(int *P)//Un puntero apuntado a la variable PC para obtener el valor de PC
{
    *P=Pc; //modifica el PC
}
void ADC(uint32_t *Rd,uint32_t Rn,uint32_t Rm)//Funcion que suma Dos registros y el carry(Rn,Rm,c) y los guarda en Rd es decir el registro de destino
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
void ADD(uint32_t *Rd,uint32_t Rn,uint32_t Rm)//Funcion que suma dos registros (Rn,Rm) y los guarda en el registro de destino Rd
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
void EOR(uint32_t *Rd,uint32_t Rn,uint32_t Rm){//Funcion que hace una Eor entre dos registros(Rn,Rm) y los guarda en el registro de destino Rd
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
uint32_t OR(uint32_t *Rd,uint32_t Rn,uint32_t Rm){//Funcion que hace una Or entre dos registros(Rn,Rm) y los guarda en el registro de destino Rde
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

uint32_t AND (uint32_t *Rd,uint32_t Rn,uint32_t Rm){//Funcion que hace una AND entre dos registros(Rn,Rm) y los guarda en el registro de destino Rd
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

}
uint32_t MOV (uint32_t *Rd,uint32_t Rn){//Funcion que mueve el valor de un registro Rn a otro Rd
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


uint32_t SUB (uint32_t *Rd,uint32_t Rn,uint32_t Rm){//Funcion que hace una Resta entre dos registros(Rn,Rm) y los guarda en el registro de destino Rd
Pc+=2;
Rm=~Rm+1;//se hace un complemento a dos de Rm es decir se vuelve negativo
*Rd=Rn+Rm;// se Modifica el registro de destino con el resultado de la suma de Rn y Rm




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
void CMP(uint32_t Rn,uint32_t Rm){////Funcion que hace una Resta entre dos registros(Rn,Rm) y no guarda el resultado solo modifica las banderas
    uint32_t Rd;
    Pc+=2;
    Rm=~Rm+1;//se hace complemento a dos de Rm es decir se vuelve negativo
Rd=Rn+Rm; //se guarda el resultado de la suma en una variable local
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
uint32_t CMN (uint32_t Rn,uint32_t Rm){////Funcion que hace una Suma entre dos registros(Rn,Rm) y no guarda el resultado solo modifica las banderas
    uint32_t Rd;
    Rd=Rn+Rm;//se guarda el valor de la suma en una variable local
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
void MUL (uint32_t *Rd,uint32_t Rn,uint32_t Rm){//Funcion que hace una Multiplicacion entre dos registros(Rn,Rm) y los guarda en el registro de destino Rd
Pc+=2;
*Rd=(Rn * Rm);//se guarda en el registro de destino Rd el resultado de la Multiplicacion
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
void TST (uint32_t Rn,uint32_t Rm){////Funcion que hace una And a nivel de bits entre dos registros(Rn,Rm) y solo modifica las banderas
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
void LSL(uint32_t *Rd,uint32_t Rn,uint32_t y){//Funcion que hace un Desplasamiento a la isquierda de un registro y los guarda en el registro de destino Rd
    Pc+=2;
*Rd=Rn<<y;//Hace un desplasamiento hacia la isquierda dependiendo del usuario
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
void LSR (uint32_t *Rd,uint32_t Rn,int y){//Funcion que hace un desplasamiento logico a la derecha de un registro y los guarda en el registro de destino Rd
    Pc+=2;
   *Rd=Rn>>y;//hace el desplasamiento a la derecha dependiendo del usuario
   Rn=Rn>>(y-1);//hace desplasamiento a la derecha de un bit menos del usuario para saber cual es el carry

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
void ROR (uint32_t *Rd,uint32_t Rn,int y){//Funcion que hace una Rotacion a la derecha  de un registro y los guarda en el registro de destino Rd
    Pc+=2;
uint32_t s;
    s=(Rn>>(32-y))&2147483647;//hace un desplasamiento a la derecha del tamaño de la variable menos el numero del usuario
*Rd=Rn<<y;//hace un desplasamiento a la isquierda del numero del usuario
*Rd=*Rd|s;//hace una Or entre las dos variables
*Rd=*Rd&4294967295;//hace una and para conservar solo los 32 bits






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


void ASR (uint32_t *Rd,uint32_t Rn,int y){//Funcion que hace un desplasamiento aritmetico  a la derecha  de un registro y los guarda en el registro de destino Rd
    Pc+=2;
uint32_t s;
s=~0<<(32-y);//desplasa a la isquierda un -1 el tamaño de la variable menos el numero del usuario
*Rd=Rn>>y;//desplasamiento a la derecha del numero del usuario
*Rd=*Rd|s;//hace una OR entre los dos variables
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


void REV (uint32_t *Rd,uint32_t Rn){//Funcion que hace cambia el orden  de un registro y los guarda en el registro de destino Rd
    Pc+=2;
uint32_t x=255,y;
*Rd=(Rn&x)<<24;//corre a la derecha el registro Rn 24 bits con el fin de conservar solo los primeros 8 bits
y= (Rn>>24)&x;//corre a la isquierda el registro Rn 24 bits con el fin de conservar solo los ultimos 8 bits
*Rd=*Rd|((Rn&(x<<8))<<8);//conserva los bit del 8 al 15, y los guarda en os del 16 al 23
*Rd=*Rd|((Rn&(x<<16))>>8);//conserva los bit del 16 al 23, y los guarda en los del 8 al 15

}





void BIC (uint32_t *Rd,uint32_t Rn,uint32_t Rm){//Funcion que hace una AND entre  un registro Rn  y el complemento de otro y los guarda en el registro de destino Rd
    Pc+=2;
   *Rd=Rn & ~Rm;//And entre Rn y el complemento de Rm
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

void MVN(uint32_t *Rd,uint32_t Rn){//Funcion que guarda el complemento de un registro Rn y lo guarda en el registro de destino Rd
    Pc+=2;

*Rd=~Rn;//guarda el complemento de Rn en Rd
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
void NOP(){ //Funcion que no hace nada y aumenta el pc
Pc+=2;
}
void RSB (uint32_t *Rd,uint32_t Rn){//Funcion que hace el complemento a dos   de un registro y los guarda en el registro de destino Rd
    Pc+=2;
*Rd=~Rn+1;//hace complemento a dos de Rn y lo guarda en Rd
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
void SBC (uint32_t *Rd,uint32_t Rn,uint32_t Rm){//Funcion que hace Resta con carry entre dos registros (Rn,Rm,c) y los guarda en el registro de destino Rd
    Pc+=2;
Rm=~Rm+1;//vuelve negativo a Rm
Rm=Rm-c;//suma el carry negativo
*Rd=Rn+Rm;//suma el Rn y Rm y lo gaurda en Rd




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

void BEQ(int Sal){//hace un salto definido por el usuario si a bandera de cero esta activada
    if(s==1){//un if si la bandera de cero esta activada
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }
}
void BNE(int Sal){//hace un salto definido por el usuario si a bandera de cero esta en 0
    if(s==0){//un if si la bandera de cero esta en 0
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }
}
void BCS(int Sal){//hace un salto definido por el usuario si a bandera de carry esta activada
    if(c==1){//un if si la bandera de carry esta en 1
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }
}
void BCC(int Sal){//hace un salto definido por el usuario si a bandera de carry esta en 0
    if(c==0){//un if si la bandera de carry esta en 0
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }
}
void BMI(int Sal){//hace un salto definido por el usuario si a bandera de negativo esta activada
    if(n==1){//un if si la bandera de negativo esta en 1
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }
}
void BPL(int Sal){//hace un salto definido por el usuario si a bandera de negativo esta en 0
    if(n==o){//un if si la bandera de negativo esta en 0
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }
}
void BVS(int Sal){//hace un salto definido por el usuario si a bandera de sobreflujo esta activada
    if(o==1){//un if si la bandera de sobreflujo esta en 1
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }
}
void BVL(int Sal){//hace un salto definido por el usuario si a bandera de sobreflujo esta en 0
    if(o==0){//un if si la bandera de sobreflujo esta en 0
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }
}
void BHI(int Sal){//hace un salto definido por el usuario si a bandera de carry esta activada y la bandera de cero esta en 0
    if(c==1&&s==0){//un if si la bandera de carry esta activada y la bandera de cero esta en 0
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }
}

void BLS(int Sal){//hace un salto definido por el usuario si a bandera de carry esta en 0 o la bandera de cero esta activada
    if(c==0||s==1){//un if si la bandera de carry esta en 0 o la bandera de cero esta activada
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }
}
void BGE(int Sal){//hace un salto definido por el usuario si a bandera de negativo es igual a la bandera de cero
    if(n==o){//un if si la bandera negativo es igual a la bandera de cero
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }
}
void BLT(int Sal){//hace un salto definido por el usuario si a bandera de negativo es diferente a la bandera de cero
    if(n!=o){//un if si la bandera de negativo es diferente a la bandera de cero
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }

}
void BGT(int Sal){//hace un salto definido por el usuario si a bandera de cero esta en 0 y la bandera de negativo esta en 0
    if(s==0&&n==0){//un if si la bandera de cero esta en 0 y la bandera de negativo esta en 0
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }
}
void BLE(int Sal){//hace un salto definido por el usuario si a bandera de cero esta activada y la bandera de negativo es diferente de la de sobreflujo
    if(s==1||n!=o){//un if si la bandera de cero esta activada y la bandera de negativo es diferente de la de sobreflujo
        Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
    }
    else{//si no
    Pc+=2;//aumente el pc para pasar a la siguiente instruccion
    }
}
void B(int Sal){//hace un salto definido por el usuario sin condicion
Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
}
void BL(int Sal){//hace un salto definido por el usuario sin condicion
LR=Pc+2;//vuelve LR a la siguiente instruccion
Pc+=Sal*2;//aumenta el pc el numero de saltos definido por el usuario

}
void BX(int Sal){//hace un salto definido por el usuario sin condicion
if(LR==Sal){
    Pc=LR;
}
else{
Pc=Sal*2;//aumenta el pc el numero de saltos definido por el usuario
}
}
void OBLR (int *P){//Funcion que obtiene en un puntero la direccion de LR
*P=LR;// el puntero P se iguala a la direccion de LR
}

void PBanderas (){//Funcion que imprime las banderas en pantalla
   move(7,50);
   attron(COLOR_PAIR(1));
    printw("C:");
    move(7,65);
    printw("Z:");
    move(8,50);
    printw("O:");
    move(8,65);
    printw("N:");
    move(15,50);
    printw("PC:");
    move(16,50);
    printw("LR:");
    refresh();
    attroff(COLOR_PAIR(1));
       move(7,50);

   attron(COLOR_PAIR(2));
   move(7,53);
    printw("%.8X",c);
    move(7,68);
    printw("%.8X",s);
    move(8,53);
    printw("%.8X",o);
    move(8,68);
    printw("%.8X",n);
    move(15,53);
    printw("%.8X",Pc-2);
    move(16,53);
    printw("%.8X",LR);
    refresh();
    attroff(COLOR_PAIR(2));

}

void LRegistros(uint32_t *ptra,uint8_t *memor){//Funcion que limpia los registros y la memoria
int i=0; //contador
for (i=0;i<16;i++){//for de 0 a 15 para limpiar los 16 registros
    ptra[i]=0;//hace cada registro igual a 0
}
Pc=0;//Pc igual a 0
LR=0;//LR igual a 0
c=0;//Carry igual a 0
o=0;//sobreflujo igual a 0
n=0;//negativo igual a 0
s=0;//cero iguala a 0

   for (i=255;0<=i;i--){//for de 255 hasta 0 para cada la memoria y se hace FF
    memor[i]=-1;//se hace cada memoria igual a FF
   }



}

void Mmemor(uint32_t *memor){//Funcion que muestra en pantalla la memoria por bloques con su respectivo valor e indicador

	border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);

	attron(COLOR_PAIR(3));	/* Activa el color verde para el
							   texto y negro para el fondo Pair 1*/
							   move(1,2);
    printw("Arm Cortex-M0-Emulator:");
    attroff(COLOR_PAIR(3));
    refresh();

int i=64;
int b=0;
attron(COLOR_PAIR(1));
move(1,28);
printw("             ");
refresh();
    printw("SRAM");
attroff(COLOR_PAIR(1));

for(i=255;195<=i;i-=4){
        move (5+b,6);
        attron(COLOR_PAIR(1));
        printw(" %.2X:",i);
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        printw(" %.2X %.2X %.2X %.2X",memoria[i],memoria[i-1],memoria[i-2],memoria[i-3]);
        attroff(COLOR_PAIR(2));
        attron(COLOR_PAIR(1));
        printw(" %.2X:",i-64);
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        printw(" %.2X %.2X %.2X %.2X",memoria[i-64],memoria[i-65],memoria[i-66],memoria[i-67]);
        attroff(COLOR_PAIR(2));
        attron(COLOR_PAIR(1));
        printw(" %.2X:",i-128);
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        printw(" %.2X %.2X %.2X %.2X",memoria[i-128],memoria[i-129],memoria[i-130],memoria[i-131]);
        attroff(COLOR_PAIR(2));
        attron(COLOR_PAIR(1));
        printw(" %.2X:",i-192);
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        printw(" %.2X %.2X %.2X %.2X",memoria[i-192],memoria[i-193],memoria[i-194],memoria[i-195]);
        attroff(COLOR_PAIR(2));
        refresh();

        b++;
}
}


void PUSH(uint8_t *Rd){//Funcion Push que guarda en la Ram los valores de los registros indicados
    int i=0;

    Pc+=2;
    for(i=0;i<16;i++){//For de 0 a 15 para cada registro
       if(Rd[i]==1){//se determina que registros se van a guardar
            if(i<8||i==15){//se garantisa que los registros a guardar sean del 0 a 7 o el pc

            memoria[255-counter]=((R[i]>>24)&255);//se guarda en el primer bloque o memoria los primeros 0 al 7 bits del registro
            counter++; //se aumenta el contador de bloques o memoria
            memoria[255-counter]=((R[i]>>16)&255);//se guarda en el segundo bloque o memoria los bits del 8 al 15  del registro
            counter++;//se aumenta el contador de bloques o memoria
            memoria[255-counter]=((R[i]>>8)&255);//se guarda en el tercer bloque o memoria los bits del 16 al 23 del registro
            counter++;//se aumenta el contador de bloques o memoria
            memoria[255-counter]=(R[i]&255);//se guarda en el cuarto bloque o memoria los bits del 24 al 31 del registro
             counter++;//se aumenta el contador de bloques o memoria


    }
       }




}
R[13]=255-counter; //se guarda el SP indicador de que posicion de memoria se encuentra
}
void POP(uint8_t *Rd){
    int i=0;


    Pc+=2;
for(i=15;0<i;i--){//For de 15 a 0 para cada registro


       if(Rd[i]==1){//se determina que registro se va a obtener
            if(i<8||i==15){//se garantisa que los registros a guardar sean del 0 a 7 o el pc
                    counter--;//se decrementa el contador de bloques o memoria
                        R[i]=memoria[255-counter];//se guarda en el registro el cuarto bloque o memoria los bits del 24 al 31 del registro
             memoria[255-counter]=-1;//se limpia el valor de la memoria
             counter--;//se decrementa el contador de bloques o memoria
                        R[i]|=(memoria[255-counter]<<8);//se guarda en el registro el tercer bloque o memoria los bits del 16 al 23 del registro
             memoria[255-counter]=-1;//se limpia el valor de la memoria
             counter--;//se decrementa el contador de bloques o memoria
                        R[i]|=memoria[255-counter]<<16;//se guarda en el registro el segundo bloque o memoria los bits del 8 al 15 del registro
             memoria[255-counter]=-1;//se limpia el valor de la memoria
             counter--;//se decrementa el contador de bloques o memoria
                        R[i]|=(memoria[255-counter]<<24);//se guarda en el registro el primer bloque o memoria los bits del 0 al 7 del registro
             memoria[255-counter]=-1;//se limpia el valor de la memoria
            }

    }

}
R[13]=255-counter;//se guarda el valor de Sp el indicador de posicion de memoria

}
void OPTYPE(char tipe){//funcion que Obtiene el tipo del tercer caracter para saber si es un inmediato o un registro

    type=tipe;//se guarda el tipo en la variable type.
}

void LDR (uint32_t *Rd,uint32_t Rn,uint32_t Rm){//load de cuatro bloques de memoria de 8 bits cada uno y se guarda en un registro de 32 bits
      Rn=Rn-536870912;
      Pc+=2;
if(type=='#'||Rm==R[15]){//se determina el tipo de la tercera variable para hacer la operacion correspondiente
    Rm=Rm*4;//se agrega a Rm "00" si es un inmediato

}

Rm=Rn+Rm; //suma las dos variables para la direccion
*Rd=memoria[Rm]; //guarda el primer bloque de bits de la memoria  en el registro
*Rd|=(memoria[Rm+1]<<8); //guarda el segundo bloque de bits de la memoria  en el registro
*Rd|=(memoria[Rm+2]<<16); //guarda el tercer bloque de bits de la memoria  en el registro
*Rd|=(memoria[Rm+3]<<24); //guarda el cuarto bloque de bits de la memoria  en el registro
}
void LDRB (uint32_t *Rd,uint32_t Rn,uint32_t Rm){//load de un entero sin signo de tamaño byte. Al escribirse el dato sobre el registro
Rn=Rn-536870912;                                              //destino se extiende con ceros hasta los 32 bits.
      Pc+=2;
Rm=Rm+Rn;//se suma las dos variables para la direccion
*Rd=memoria[Rm];//se guarda solo el bloque de la direccion
}


void LDRH (uint32_t *Rd,uint32_t Rn,uint32_t Rm){//load de un entero sin signo de 16 bits. Al escribirse el dato sobre el registro
        Rn=Rn-536870912;                                          //destino se extiende con ceros hasta los 32 bits.
      Pc+=2;
if(type=='#'){
    Rm=Rm*2;

}
Rm=Rm+Rn;//se suma las dos variables para la direccion
*Rd=memoria[Rm];// se guarda el primer bloque de la memoria en el registro
*Rd|=(memoria[Rm+1]<<8);//se guarda el segundo bloque de la memoria en el registro
}



void LDRSB(uint32_t *Rd,uint32_t Rn,uint32_t Rm){//load de un entero con signo de tamaño byte. Al escribirse el dato sobre el registro
   Rn=Rn-536870912;                                           //destino se extiende con el bit de signo hasta los 32 bits.
    Pc+=2;
Rm=Rm+Rn;//se suma las dos variables para la direccion
*Rd=memoria[Rm];// se guarda el primer bloque de la memoria en el registro
if(((memoria[Rm]>>7)&1)==1){//si el ultimo bit de la memoria es 1
    *Rd|=(255<<8);//agrega puros uno el los bits 8 a 15
    *Rd|=(255<<16);// agrega puron unos en los bits 16 a 23
    *Rd|=(255<<24);//agrega puros unos en los bits 24 a 31

}
}
void LDRSH(uint32_t *Rd,uint32_t Rn,uint32_t Rm){//load de un entero con signo de 16 bits. Al escribirse el dato sobre el registro
       Rn=Rn-536870912;
      Pc+=2;                                           //destino se extiende con el bit de signo hasta los 32 bits.
Rm=Rm+Rn;//se suma las dos variables para la direccion
*Rd=memoria[Rm];// se guarda el primer bloque de la memoria en el registro
*Rd|=(memoria[Rm+1]<<8);// se guarda el segundo bloque de la memoria en el registro
if(((memoria[Rm+1]>>7)&1)==1){//si el ultimo bit de la memoria es 1
    *Rd|=(255<<16);// agrega puron unos en los bits 16 a 23
    *Rd|=(255<<24);//agrega puros unos en los bits 24 a 31
}
}

void STR(uint32_t *Rd,uint32_t Rn,uint32_t Rm){
       Rn=Rn-536870912;
      Pc=+2;
if(type=='#'||Rm==R[15]){
    Rm=Rm*4;
}
Rm=Rn+Rm;//se suma las dos variables para la direccion
memoria[Rm]=*Rd;//guarda en la memoria el primer byte del registro
memoria[Rm+1]=(*Rd>>8);//guarda en la memoria el sugundo byte del registro
memoria[Rm+2]=(*Rd>>16);//guarda en la memoria el tercer byte del registro
memoria[Rm+3]=(*Rd>>24);//guarda en la memoria el cuarto byte del registro

}
void STRB(uint32_t *Rd,uint32_t Rn,uint32_t Rm){//se escribe en memoria un entero de tamaño byte obtenido de los 8 bits menos
        Rn=Rn-536870912;                                        //significativos del registro fuente.
    Pc=+2;
Rm=Rm+Rn;//se suma las dos variables para la direccion
memoria[Rm]=(*Rd&255);//guarda en la memoria el primer byte del registro
}



void STRH(uint32_t *Rd,uint32_t Rn,uint32_t Rm){//se escribe en memoria un entero de 16 bits obtenido de los 16 bits menos significativos
          Rn=Rn-536870912;                                      //del registro fuente.
    Pc=+2;
if(type=='#'){
    Rm=Rm*2;

}
Rm=Rm+Rn;//se suma las dos variables para la direccion
memoria[Rm]=(*Rd&255);//guarda en la memoria el primer byte del registro
memoria[Rm+1]=((*Rd>>8)&255);//guarda en la memoria el segundo byte del registro

}
void PUSH_INTERRUP(){
int i;
memoria[255-counter]=c;
counter++;
memoria[255-counter]=s;
counter++;
memoria[255-counter]=n;
counter++;
memoria[255-counter]=o;
counter++;
for(i=0;i<16;i++){
           memoria[255-counter]=((R[i]>>24)&255);//se guarda en el primer bloque o memoria los primeros 0 al 7 bits del registro
            counter++; //se aumenta el contador de bloques o memoria
            memoria[255-counter]=((R[i]>>16)&255);//se guarda en el segundo bloque o memoria los bits del 8 al 15  del registro
            counter++;//se aumenta el contador de bloques o memoria
            memoria[255-counter]=((R[i]>>8)&255);//se guarda en el tercer bloque o memoria los bits del 16 al 23 del registro
            counter++;//se aumenta el contador de bloques o memoria
            memoria[255-counter]=(R[i]&255);//se guarda en el cuarto bloque o memoria los bits del 24 al 31 del registro
             counter++;//
}
R[13]=255-counter;
}

void POP_INTERRUP(){
    int i=0;
for(i=15;0<=i;i--){
                    counter--;//se decrementa el contador de bloques o memoria
                        R[i]=memoria[255-counter];//se guarda en el registro el cuarto bloque o memoria los bits del 24 al 31 del registro
             memoria[255-counter]=-1;//se limpia el valor de la memoria
             counter--;//se decrementa el contador de bloques o memoria
                        R[i]|=(memoria[255-counter]<<8);//se guarda en el registro el tercer bloque o memoria los bits del 16 al 23 del registro
             memoria[255-counter]=-1;//se limpia el valor de la memoria
             counter--;//se decrementa el contador de bloques o memoria
                        R[i]|=memoria[255-counter]<<16;//se guarda en el registro el segundo bloque o memoria los bits del 8 al 15 del registro
             memoria[255-counter]=-1;//se limpia el valor de la memoria
             counter--;//se decrementa el contador de bloques o memoria
                        R[i]|=(memoria[255-counter]<<24);//se guarda en el registro el primer bloque o memoria los bits del 0 al 7 del registro
             memoria[255-counter]=-1;//se limpia el valor de la memoria
            }


    counter--;
c=memoria[255-counter];
memoria[255-counter]=-1;
counter--;
s=memoria[255-counter];
memoria[255-counter]=-1;
counter--;
n=memoria[255-counter];
memoria[255-counter]=-1;
counter--;
o=memoria[255-counter];
memoria[255-counter]=-1;
Pc=R[15];
LR=R[14];
R[13]=255-counter;

}


void callinte(int n){

if(n<16){
LR=Pc;
R[15]=LR;
Pc=n*2;

if(n<8){
    changePinPortA(n,1);
}
if(n>8){
        n=n-8;
    changePinPortB(n,1);
}
PUSH_INTERRUP();
}
else{
         move(26,2);
       attron(COLOR_PAIR(2));
printw("                                   ");
        attroff(COLOR_PAIR(2));
refresh();
    move(26,2);
       attron(COLOR_PAIR(3));
printw("ERROR VALOR NO VALIDO PARA LAS INTERRUPCIONES");
        attroff(COLOR_PAIR(3));
refresh();

}
}
void ESPC(int pc){
Pc=pc;

}


