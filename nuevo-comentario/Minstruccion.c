#include "Minstruccion.h"

void Minstruccion(instruction_t instruction) //Esta función muestra las instruciones en la estructura tipo instruction.
{
	move(3,10); 
    attron(COLOR_PAIR(1)); //pone color a la interfaz
    printw("Instruccion:");

    attroff(COLOR_PAIR(1));
    refresh();


	if(strncmp(instruction.mnemonic,"B",1)!=0)
	{
		if(instruction.op3_type!='N')
		{

        move(3,26);
		attron(COLOR_PAIR(2));
        printw("                                                   ");
        refresh();
        move(3,26);
		printw("%s <%c%d %c%d %c%d>",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
		attroff(COLOR_PAIR(2));
		refresh();
		}
	
		if(instruction.op3_type=='N')
		{
			move(3,26);
			attron(COLOR_PAIR(2));
			printw("                                             ");
			refresh();
			move(3,26);
			printw("%s <%c%d %c%d>",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
			attroff(COLOR_PAIR(2));
			refresh();
		}

    }

    if(strncmp(instruction.mnemonic,"B",1)==0)
	{
        move(3,26);
		attron(COLOR_PAIR(2));
        printw("                                      ");
        refresh();
        move(3,26);
        printw("%s<%c%d>",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
        attroff(COLOR_PAIR(2));
        refresh();

     }
    if(strncmp(instruction.mnemonic,"P",1)==0)}
	{
        move(3,26);
		attron(COLOR_PAIR(2));
        printw("                                      ");
        refresh();
        move(3,26);
        printw("%s<%c%d %c%d %c%d>",instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        attroff(COLOR_PAIR(2));
        refresh();
	}
}

