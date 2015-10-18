#include <dos.h>
#include "Mregistros.h"
#include "Operaciones.h"
#include "decoder.h"
int main()
{
    initscr();
    curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */

	start_color();	/* Permite manejar colores */
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_WHITE);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    char interrup[16]={0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0};

    int PC=0,key,ind=0,LR,h=0,co=0;
    uint32_t R[16];
    uint8_t memor[256];//cambie
registro(R);
OBMEMOR(memor);
OBR(R);
LRegistros(R,memor);

	//------- No modificar ------//
			int i, num_instructions;
		ins_t read;
		char** instructions;
		instruction_t instruction;

		num_instructions = readFile("code.txt", &read);
		if(num_instructions==-1)
			return 0;

		if(read.array==NULL)
			return 0;

		instructions = read.array; /* Arreglo con las instrucciones */
	//---------------------------//rreglo con las instrucciones */
	//---------------------------//


     Mregistro(R,16);
     PBanderas();

key=getch();
while(ind!=2){
        if(kbhit()==TRUE){
        key=getch();
        }
        if(interrup[h]==0 && interrup[h-1]==1){
                printf("entre hhwhw");
           POP_INTERRUP();
        }

switch(key){
         case 274:

         instruction = getInstruction(instructions[PC]); // Instrucción en la posición 0
		Minstruccion(instruction,interrup[h]);
		decodeInstruction(instruction);
		if(ind==0 && interrup[h]==0){
		 PBanderas();
		 Mregistro(R,16);
       		}
       		if(ind==1 && interrup[h]==0){
                    Mmemor(memor);
                }
            if(ind==0 && interrup[h]==1){
                    if(co==0){
                    PUSH_INTERRUP(h);
                    }
                    co++;
		 PBanderas();
		 Mregistro(R,16);
       		}
       		if(ind==1 && interrup[h]==1){
           if(co==0){
                    PUSH_INTERRUP(h);
                    }
                    Mmemor(memor);
                    co++;
                }
    RPC(&PC);
    R[15]=PC;
    OBLR(&LR);
    R[14]=LR;
    key=getch();
    break;

   case 273:

     instruction = getInstruction(instructions[PC]); // Instrucción en la posición 0
   Minstruccion(instruction,interrup[h]);
    decodeInstruction(instruction);
     RPC(&PC);
     if(ind==0 && interrup[h]==0){
		 PBanderas();
		 Mregistro(R,16);

       		}
       		if(ind==1 && interrup[h]==0){
                    Mmemor(memor);
                }
            if(ind==0 && interrup[h]==1){
                    if(co==0){
                    PUSH_INTERRUP(h);
                    }
		 PBanderas();
		 Mregistro(R,16);
		 co++;
       		}
       		if(ind==1 && interrup[h]==1){
            if(co==0){
                    PUSH_INTERRUP(h);
                    }
                    Mmemor(memor);
                    co++;
                }

    R[15]=PC;
    OBLR(&LR);
    R[14]=LR;
    sleep(1);
    break;

   case 272:
    key=getch();
    break;

   case 271:
    ind=2;
    break;

   case 270:
    LRegistros(R,memor);
    if(ind==0){
    PBanderas();
    Mregistro(R,16);
    }
    if(ind==1){
        Mmemor(memor);
    }
    RPC(&PC);
    R[15]=PC;
    OBLR(&LR);
    R[14]=LR;
    key=getch();
    break;

   case 269:
       ind=1;
       clear();
    Mmemor(memor);
    Minstruccion(instruction,interrup[h]);
    move(22,2);
       attron(COLOR_PAIR(3));
              printw("F10:Step    F9:Run   F8:Pause   F7:Stop   F6:Reset    F5:SRam     Esc:Quit");
        attroff(COLOR_PAIR(3));
              refresh();
              key=getch();
                  break;

   case 27:
    clear();
    if(ind==0){
            exit(0);
    }
    if(ind==1){
    ind=0;
    PBanderas();
    Mregistro(R,16);
    PBanderas();
    Minstruccion(instruction,interrup[h]);
    key=getch();
    }

    break;
}
printf("pc %d",PC);
if(15>h){
h++;
}
}


	getch();	/* Espera entrada del usuario */
	endwin();	/* Finaliza el modo curses */

	return 0;

}

