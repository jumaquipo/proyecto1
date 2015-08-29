#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mregistros.h"
#include "Operaciones.h"
int main()
{
int h;

   int a,b,c;
   uint32_t rd[13];
   Mregistro(rd,13);
switch(a){
     case 1:
         Xor(rd[b],rd[c]);
         break;
     case 2:
         Or(rd[b],rd);
         break;
     case 3:
        And(rd[b],rd[c]);
         break;
     case 4:
          Movs(rd,b,c);
          break;
     case 5:
          Subs (rd[b],rd[c]);
          break;

}

printf("\n%d\n",rd[a]);


}
