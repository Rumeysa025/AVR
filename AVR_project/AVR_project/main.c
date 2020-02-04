#include <avr/io.h>
#include <util/delay.h>


/******************************************************************/
void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
Version :    	DMK, Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

/******************************************************************/

void ButtonC0Pressed()
{
	DDRD = 0b11111111;			// All pins PORTD are set to output
	while (1)
	{
		if (PINC & 0x01)
		{
			PORTD = 0x80;
			wait(250);
		}
		
		PORTD = 0x00;
		wait(250);
	}
}

int main(void)
{
	/* Part B3 */
	ButtonC0Pressed();
	
	/* Part B2 */
	DDRD = 0b11111111;			// All pins PORTD are set to output
	DDRC = 0xff;
	while (1)
	{
		//PORTD = 0xAA;			// Write 10101010b PORTD
		PORTC = 0b10000000;
		
		wait( 500 );
		//PORTD = 0x55;			// Write 01010101b PORTD
		PORTC = 0b01000000;
		wait( 500 );
	}

	/* Part A
	
	DDRD = 0b11111111;
	while (1)
	{
		PORTD = 0xAA;
		wait( 250 );
		PORTD = 0x55;			// Write 01010101b PORTD
		wait( 250 );
	}
	
	return 1;
	
	*/
}








