#include "Mregistros.h"

void Mregistro(uint32_t *ptro,int n){


    int a;
        int i=0;
			/* Inicia modo curses */



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
    attron(COLOR_PAIR(1));
    move(1,28);
    printw("PROCESSOR");

attroff(COLOR_PAIR(1));
a=0;
for(i=0;i<n;i+=2){
        if(i<10){
        attron(COLOR_PAIR(1));
	move(10+a,5);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("R%d :",i);
	move(10+a,25);
	printw("R%d :",i+1);
attroff(COLOR_PAIR(1));
        }

        if(i>9){
        attron(COLOR_PAIR(1));
	move(10+a,5);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("R%.2d:",i);
	move(10+a,25);
	printw("R%.2d:",i+1);
attroff(COLOR_PAIR(1));

}
refresh();
a++;
}
a=0;
for(i=0;i<n;i+=2){
   attron(COLOR_PAIR(2));
	move(10+a,10);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("%.8X",ptro[i]);
	move(10+a,30);
	printw("%.8X",ptro[i+1]);
attroff(COLOR_PAIR(2));
refresh();
a++;
}
move(22,2);
       attron(COLOR_PAIR(3));
printw("F10:Step    F9:Run   F8:Pause   F7:Stop   F6:Reset    F5:SRam     Esc:Quit");
        attroff(COLOR_PAIR(3));
refresh();

		/* Imprime en la pantalla
					Sin esto el printw no es mostrado */

		/* DEshabilita los colores Pair 1 */


}
