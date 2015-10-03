#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Operaciones.h"
#include "decoder.h"

uint32_t *R;
uint32_t LR;
void registro(uint32_t *A){
R=A;
}

void decodeInstruction(instruction_t instruction)
{

    if((instruction.op1_type=='R')&&(instruction.op2_type=='#')){
	  if( strcmp(instruction.mnemonic,"ADC") == 0 ){

    ADC(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);

	}
	if( strcmp(instruction.mnemonic,"ADD") == 0 ){
   ADD(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"AND") == 0 ){
   AND(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"ASR") == 0 ){
    ASR(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"BIC") == 0 ){
    BIC(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"CMN") == 0 ){
    CMN(R[instruction.op1_value],instruction.op2_value);
	}
	if( strcmp(instruction.mnemonic,"CMP") == 0 ){
    CMP(R[instruction.op1_value],instruction.op2_value);
	}
	if( strcmp(instruction.mnemonic,"EOR") == 0 ){
    EOR(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"LSL") == 0 ){
    LSL(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"LSR") == 0 ){
    LSR(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"MOV") == 0 ){
    MOV(&R[instruction.op1_value],instruction.op2_value);
	}

	if( strcmp(instruction.mnemonic,"MUL") == 0 ){
    MUL(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"MVN") == 0 ){
    MVN(&R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"NOP") == 0 ){

	}
	if( strcmp(instruction.mnemonic,"EOR") == 0 ){
    EOR(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"REV") == 0 ){
    REV(&R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"ROR") == 0 ){
   ROR(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"RSB") == 0 ){
   RSB(&R[instruction.op1_value],instruction.op2_value);
	}
	if( strcmp(instruction.mnemonic,"SBC") == 0 ){
    SBC(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"SUB") == 0 ){
    SUB(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"TST") == 0 ){
    TST(R[instruction.op1_value],instruction.op2_value);
}
    }
     if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&((instruction.op3_type!='R'))){
	if( strcmp(instruction.mnemonic,"ADC") == 0 ){

    ADC(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);

	}
	if( strcmp(instruction.mnemonic,"ADD") == 0 ){
   ADD(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"AND") == 0 ){
   AND(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"ASR") == 0 ){
    ASR(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"BIC") == 0 ){
    BIC(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"CMN") == 0 ){
    CMN(R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"CMP") == 0 ){
    CMP(R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"EOR") == 0 ){
    EOR(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"LSL") == 0 ){
    LSL(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"LSR") == 0 ){
    LSR(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"MOV") == 0 ){
    MOV(&R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"MUL") == 0 ){
    MUL(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"MVN") == 0 ){
    MVN(&R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"NOP") == 0 ){

	}
	if( strcmp(instruction.mnemonic,"EOR") == 0 ){
    EOR(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"REV") == 0 ){
    REV(&R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"ROR") == 0 ){
   ROR(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"RSB") == 0 ){
   RSB(&R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"SBC") == 0 ){
    SBC(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"SUB") == 0 ){
    SUB(&R[instruction.op1_value],R[instruction.op2_value],instruction.op3_value);
	}
	if( strcmp(instruction.mnemonic,"TST") == 0 ){
    TST(R[instruction.op1_value],R[instruction.op2_value]);
}
    }
      if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&((instruction.op3_type=='R'))){
	if( strcmp(instruction.mnemonic,"ADC") == 0 ){

    ADC(&R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);

	}
	if( strcmp(instruction.mnemonic,"ADD") == 0 ){
   ADD(&R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);
	}
	if( strcmp(instruction.mnemonic,"AND") == 0 ){
   AND(&R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);
	}
	if( strcmp(instruction.mnemonic,"ASR") == 0 ){
    ASR(&R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);
	}
	if( strcmp(instruction.mnemonic,"BIC") == 0 ){
    BIC(&R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);
	}
	if( strcmp(instruction.mnemonic,"CMN") == 0 ){
    CMN(R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"CMP") == 0 ){
    CMP(R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"EOR") == 0 ){
    EOR(&R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);
	}
	if( strcmp(instruction.mnemonic,"LSL") == 0 ){
    LSL(&R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);
	}
	if( strcmp(instruction.mnemonic,"LSR") == 0 ){
    LSR(&R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);
	}
	if( strcmp(instruction.mnemonic,"MOV") == 0 ){
    MOV(&R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"MUL") == 0 ){
    MUL(&R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);
	}
	if( strcmp(instruction.mnemonic,"MVN") == 0 ){
    MVN(&R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"NOP") == 0 ){

	}
	if( strcmp(instruction.mnemonic,"EOR") == 0 ){
    EOR(&R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);
	}
	if( strcmp(instruction.mnemonic,"REV") == 0 ){
    REV(&R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"ROR") == 0 ){
   ROR(&R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);
	}
	if( strcmp(instruction.mnemonic,"RSB") == 0 ){
   RSB(&R[instruction.op1_value],R[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"SBC") == 0 ){
    SBC(&R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);
	}
	if( strcmp(instruction.mnemonic,"SUB") == 0 ){
    SUB(&R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);
	}
	if( strcmp(instruction.mnemonic,"TST") == 0 ){
    TST(R[instruction.op1_value],R[instruction.op2_value]);
}
    }
    if(strncmp(instruction.mnemonic,"B",1)==0){
        if(instruction.op1_type!='R'){
                if(strcmp(instruction.mnemonic,"BCC") == 0){
                       BCC(instruction.op1_value);
                }
            if(strcmp(instruction.mnemonic,"BEQ") == 0){
                BEQ(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BNE") == 0){
                BNE(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BCS") == 0){
                BCS(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BCC") == 0){
                BCC(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BMI") == 0){
                BMI(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BPL") == 0){
                BPL(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BVS") == 0){
                BVS(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BVL") == 0){
                BVL(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BHI") == 0){
                BHI(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BLS") == 0){
                BLS(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BGE") == 0){
                BGE(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BLT") == 0){
                BLT(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BGT") == 0){
                BGT(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BLE") == 0){
                BLE(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"B") == 0){
                B(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BL") == 0){
                BL(instruction.op1_value);
            }
            if(strcmp(instruction.mnemonic,"BX") == 0){
                          BX(instruction.op1_value);
            }
             if(strcmp(instruction.mnemonic,"PUSH") == 0){
                          PUSH(R[instruction.op1_value],R[instruction.op2_value],R[instruction.op3_value]);
            }


        }
        if(strcmp(instruction.mnemonic,"BX") == 0){
        if(instruction.op1_type=='L'||instruction.op1_type=='R'){
                    OBLR(&LR);
                    BX(LR);
                 }
        }



    }

}


instruction_t getInstruction(char* instStr)
{
	instruction_t instruction=
	{
		.registers_list = {0},
		.op3_type  = 'N',
		.op3_value = 0
	};
	char* split = (char*)malloc(strlen(instStr)+1);
	int num=0;

	strcpy(split, instStr);
	/* Obtiene el mnemonico de la instrucción */
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);

	/* Separa los operandos */
	while (split != NULL)
	{
		switch(num){
			case 1:
				if(split[0] == '{'){
					instruction.op1_type  = split[0];
					split++;
					do{
						if(split[0]=='L')
							instruction.registers_list[14] = 1;
						else if(split[0]=='P')
							instruction.registers_list[15] = 1;
						else
							instruction.registers_list[(uint8_t)strtoll(split+1, NULL, 0)] = 1;

						split = strtok(NULL, ",");
					}while(split != NULL);
				}else{
					instruction.op1_type  = split[0];
					instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				}
				break;

			case 2:
				if(split[0] == '[')
					split++;

				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
		}
		if(split != NULL){
			split = strtok(NULL, " ,.");
			num++;
		}
	}

	if(instruction.op1_type == 'L'){
		instruction.op1_value = 14;
		instruction.op1_type = 'R';
	}

	if(instruction.op1_type == '{'){
		instruction.op1_type = 'P';
	}

	free(split);

	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	/* Puntero a un archivo  */
	int lines;	/* Cantidad de líneas del archivo */
	int line=0;	/* Línea leida */
	char buffer[50]; /* Almacena la cadena leida */

	fp = fopen(filename, "r");	/* Abrir el archivo como solo lectura */
	if( fp==NULL )
		return -1;	/* Error al abrir el archivo */

	lines = countLines(fp);	/* Cantidad de líneas*/

	/* Asignación dinámica de memoria para cada instrucción */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}

	fclose(fp);	/* Cierra el archivo */

	return lines;
}


int countLines(FILE* fp)
{
	int lines=0;
	char buffer[50];

	while( fgets(buffer, 50, fp) != NULL )
		lines++;

	rewind(fp);

	return lines;
}
