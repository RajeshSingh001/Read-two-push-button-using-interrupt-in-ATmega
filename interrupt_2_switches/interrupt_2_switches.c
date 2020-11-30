#include <inttypes.h>           //short forms for various integer types
#include <avr/io.h>
#include <avr/interrupt.h>      //file to be included if using interrupts

ISR(INT0_vect)
{
PORTB=0x0F;
}

ISR(INT1_vect)
{
PORTB=0xF0;
}

void init_interrupt()
{
	MCUCR=(1<<ISC01)|(1<<ISC11);
	GICR=(1<<INT0)|(1<<INT1);
}
int main()
{
DDRB=0xff;
init_interrupt();
sei();
while(1);
return 1;
}
