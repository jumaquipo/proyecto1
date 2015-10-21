#include <dos.h>
#include "Mregistros.h"
#include "Operaciones.h"
#include "decoder.h"
#include "io.h"
int main()
{
    char on=0;
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
    extern uint8_t irq[16];

    uint8_t data;

    int PC=0,key,ind=0,LR,h=0,co=0,inter=0,coninter=0;
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

ind=0;
initIO();
while(ind!=4){
        if(kbhit()==TRUE){
        key=getch();
        }
        if(PC==LR&&co!=0){
           POP_INTERRUP();

if(ind==3){
    showPorts();
	endwin();
	getch();
}
        }
switch(key){
         case 274:
RPC(&PC);
         instruction = getInstruction(instructions[PC]); // Instrucción en la posición 0
		Minstruccion(instruction);
		decodeInstruction(instruction);

		if(ind==0){
		 PBanderas();
		 Mregistro(R,16);
       		}
       		if(ind==1){
                    Mmemor(memor);
                }
    R[15]=PC;
    OBLR(&LR);
    R[14]=LR;
    key=getch();
    break;

   case 273:
     instruction = getInstruction(instructions[PC]); // Instrucción en la posición 0
   Minstruccion(instruction);
    decodeInstruction(instruction);
    RPC(&PC);
     if(ind==0){
		 PBanderas();
		 Mregistro(R,16);

       		}
       		if(ind==1){
                    Mmemor(memor);
                }
		 Mregistro(R,16);
		 R[15]=PC;
    OBLR(&LR);
    R[14]=LR;
    sleep(1);
    break;

   case 272:
    key=getch();
    break;

   case 271:
       clear();
       ind=3;

      showPorts();
	endwin();
	getch();

   key=getch();			// Muestra en pantalla el estado del puerto
    break;

   case 270:
    LRegistros(R,memor);
    initIO();
    if(ind==0){
    PBanderas();
    Mregistro(R,16);
    }
    if(ind==1){
        Mmemor(memor);
    }
    if(ind==1){
        showPorts();
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
    Minstruccion(instruction);
    move(22,2);
       attron(COLOR_PAIR(3));
              printw("F10:Step    F9:Run   F8:Pause   F7:Puertos   F6:Reset    F5:SRam     Esc:Quit");
        attroff(COLOR_PAIR(3));
              refresh();
              key=getch();
                  break;

   case 27:
    clear();
    if(ind==0){
            exit(0);
    }
    if(ind==1||ind==3){
    ind=0;
    PBanderas();
    Mregistro(R,16);
    PBanderas();
    Minstruccion(instruction);
    key=getch();

    }

    break;
   case 105:
        move(26,2);
       attron(COLOR_PAIR(3));
printw("INGRESE LA INTERRUPCION");
        attroff(COLOR_PAIR(3));
refresh();
    scanw("%d",&inter);
     move(26,2);
       attron(COLOR_PAIR(2));
printw("                                   ");
        attroff(COLOR_PAIR(2));
refresh();
    co++;

    callinte(inter);
    key=274;
    R[15]=PC;
    break;


}
 if((strncmp(instruction.mnemonic,"L",1)==0)||(strncmp(instruction.mnemonic,"S",1)==0)){
if(ind==3){
    showPorts();
	endwin();
	getch();
}
}
Obpc(PC);
}


	getch();	/* Espera entrada del usuario */
	endwin();	/* Finaliza el modo curses */

	return 0;

}

