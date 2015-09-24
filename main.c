#include <stdio.h>
#include <stdlib.h>

#include "decoder.h"
#include "mregistros.h"


int main(void)
{
    uint32_t R[12];
     unsigned int PC=0,C;
    R[1]=-1;


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
	//---------------------------//



registro(&R[0]);
printf("\n");
	/* Ejemplo de uso
		Llama la función que separa el mnemonico y los operandos
		Llama la instrucción que decodifica y ejecuta la instrucción
	*/
	// Esto debe ser ciclico para la lectura de todas las instrucciones, de acuerdo
	// al valor del PC (Program Counter)
	Mregistro(R,12);
	while(C<200){

	instruction = getInstruction(instructions[PC]); // Instrucción en la posición 0

    decodeInstruction(instruction);
    Mregistro(R,12);
     if(strncmp(instruction.mnemonic,"B",1)!=0){

    printf("\nInstruccion: %d   es %s<%c %d %c %d>\n\n",PC,instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
    PBanderas();
    RPC(&PC);
    getchar();
    C+=2;
     }
     if(strncmp(instruction.mnemonic,"B",1)==0){
        printf("\nInstruccion: %d   es %s<%c %d>\n\n",PC,instruction.mnemonic,instruction.op1_type,instruction.op1_value);
    PBanderas();
    RPC(&PC);
    getchar();
    C+=2;
     }

	}



printf("\n");



	//------- No modificar ------//
	/* Libera la memoria reservada para las instrucciones */
	for(i=0; i<num_instructions; i++){
		free(read.array[i]);
	}
	free(read.array);
	//---------------------------//


	return 0;
}
