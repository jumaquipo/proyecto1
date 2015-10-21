#include "Minstruccion.h"




void Minstruccion(instruction_t instruction){

int i;

     move(3,10);
    attron(COLOR_PAIR(1));
    printw("Instruccion:");
    attroff(COLOR_PAIR(1));
    refresh();
if(strcmp(instruction.mnemonic,"NOP")==0){

         move(3,26);
    attron(COLOR_PAIR(2));
        printw("                                                   ");
        refresh();
        move(3,26);
    printw("%s ()",instruction.mnemonic);
    attroff(COLOR_PAIR(2));
    refresh();
    }

 if(strncmp(instruction.mnemonic,"B",1)!=0){
    if(instruction.op3_type!='N'){

         move(3,26);
    attron(COLOR_PAIR(2));
        printw("                                                   ");
        refresh();
        move(3,26);
    printw("%s <%c%d %c%d %c%d>",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
    attroff(COLOR_PAIR(2));
    refresh();
    }
    if(instruction.op3_type=='N'){
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

     if(strncmp(instruction.mnemonic,"B",1)==0){
             move(3,26);
    attron(COLOR_PAIR(2));
        printw("                                      ");
        refresh();
         move(3,26);
        printw("%s<%c%d>",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
         attroff(COLOR_PAIR(2));
         refresh();

     }


    if(strncmp(instruction.mnemonic,"P",1)==0){//cambie
             move(3,26);
    attron(COLOR_PAIR(2));
        printw("                                      ");
        refresh();
        move(3,26);
         printw("%s {",instruction.mnemonic);
        for(i=0;i<8;i++){
         if(instruction.registers_list[i]==1){
        printw(" R%d",i);
         }
        }
         printw(" }");
         attroff(COLOR_PAIR(2));
         refresh();
     }



}


