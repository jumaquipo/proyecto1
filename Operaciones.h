#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//PROFE SE TUVO UN PROBLEMA CON EL MSYS DEBIDO A ESO NO PUDIMOS TERMINAR CON LA INTERFAS COMO HUBIESEMOS QUERIDO
void RPC(int *P);
void ADC(uint32_t *Rd,uint32_t Rn,uint32_t Rm);
void ADD(uint32_t *Rd,uint32_t Rn,uint32_t Rm);
void EOR(uint32_t *Rd,uint32_t Rn,uint32_t Rm);
uint32_t OR(uint32_t *Rd,uint32_t Rn,uint32_t Rm);
uint32_t AND (uint32_t *Rd,uint32_t Rn,uint32_t Rm);
uint32_t MOV (uint32_t *Rd,uint32_t Rn);
uint32_t SUB (uint32_t *Rd,uint32_t Rn,uint32_t Rm);
void CMP(uint32_t Rn,uint32_t Rm);
uint32_t CMN (uint32_t Rn,uint32_t Rm);
void MUL (uint32_t *Rd,uint32_t Rn,uint32_t Rm);
void TST (uint32_t Rn,uint32_t Rm);
void LSL(uint32_t *Rd,uint32_t Rn,uint32_t y);
void LSR (uint32_t *Rd,uint32_t Rn,int y);
void ROR (uint32_t *Rd,uint32_t Rn,int y);
void ASR (uint32_t *Rd,uint32_t Rn,int y);
void REV (uint32_t *Rd,uint32_t Rn);
void BIC (uint32_t *Rd,uint32_t Rn,uint32_t Rm);
void MVN(uint32_t *Rd,uint32_t Rn);
void NOP();
void RSB (uint32_t *Rd,uint32_t Rn);
void SBC (uint32_t *Rd,uint32_t Rn,uint32_t Rm);
void BEQ(int Sal);
void BNE(int Sal);
void BCS(int Sal);
void BCC(int Sal);
void BMI(int Sal);
void BPL(int Sal);
void BVS(int Sal);
void BVL(int Sal);
void BHI(int Sal);
void BLS(int Sal);
void BGE(int Sal);
void BLT(int Sal);
void BGT(int Sal);
void BLE(int Sal);
void B(int Sal);
void BL(int Sal);
void BX(int Sal);
void PBanderas ();


