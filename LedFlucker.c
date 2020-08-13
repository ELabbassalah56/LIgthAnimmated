/*
 * LedFlucker.c
 *
 *  Created on:12/08/2020
 *      Author:elabbas salah hatata
 */

#include<avr/io.h>
#define F_CPU   8000000UL
#include<util/delay.h>
#define   UNSETPORTA()     (PORTA=0x00)
void FLashingEvrey500ms(void);
void ShiftLeft250ms(void);
void ShiftRight250ms(void);
void LedConverging300ms(void);
void LedDiverging300ms(void);
void PingPong250ms();
void SnakeEffect300ms();
void ConverDiver300ms();

int main(){



while(1){


FLashingEvrey500ms();
UNSETPORTA();
_delay_ms(1000);
ShiftLeft250ms();
UNSETPORTA();
_delay_ms(1000);
ShiftRight250ms();
UNSETPORTA();
_delay_ms(1000);
LedConverging300ms();
UNSETPORTA();
_delay_ms(1000);
LedDiverging300ms();
UNSETPORTA();
_delay_ms(1000);
SnakeEffect300ms();
UNSETPORTA();
_delay_ms(1000);
PingPong250ms();
UNSETPORTA();
_delay_ms(1000);
ConverDiver300ms();
UNSETPORTA();
_delay_ms(1000);

}


return 0 ;
}


void FLashingEvrey500ms(void){

DDRA =0xff;
PORTA = 0xff;
_delay_ms(500);
PORTA=0x00;
_delay_ms(500);

}

void ShiftLeft250ms(void){
DDRA=0xff;
int i=0;
for(i=0;i<8;i++)
{
	PORTA |=(1<<i);
	_delay_ms(250);
    PORTA &= (1<<i);
   _delay_ms(250);
}
}

void ShiftRight250ms(void){
DDRA=0xff;
int i;
for(i=7;i>=0;--i)
{
	PORTA |=(1<<i);
	_delay_ms(250);
    PORTA &= (1<<i);
   _delay_ms(250);
}
}
void LedConverging300ms(){

	DDRA=0xff;
	int i,j;
	for(i=7,j=0 ;j<4 && i>=4;--i,++j)
	{


		   PORTA |=(1<<i);
		   PORTA |=(1<<j);
	   	   _delay_ms(300);
	   	  PORTA &= (1<<i);
	   	   PORTA &= (1<<j);
	   	   _delay_ms(300);



	}



}

void LedDiverging300ms(){
	DDRA=0xff;
	int i,j;
	for(i=4,j=3 ;i<8 && j>=0;++i,--j)
	{


		   PORTA |=(1<<i);
		   PORTA |=(1<<j);
	   	   _delay_ms(300);
	   	  PORTA &= (1<<i);
	   	   PORTA &= (1<<j);
	   	   _delay_ms(300);




	}
}

void PingPong250ms(){

	ShiftLeft250ms();
	_delay_ms(250);
	ShiftRight250ms();
	_delay_ms(250);



}

void SnakeEffect300ms(){
    DDRA=0xff;
	int i;
	for(i=7;i>=0;--i)
	{
		PORTA |=(1<<i);
		_delay_ms(300);

	}
}
void ConverDiver300ms(){

	LedConverging300ms();
    LedDiverging300ms();


}


