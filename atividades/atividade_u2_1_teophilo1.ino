// C code
//
#define n0 0b11111010
#define n1 0b01100000
#define n2 0b11011100
#define n3 0b11110100
#define n4 0b01100110
#define n5 0b10110110
#define n6 0b10111110
#define n7 0b11100000
#define n8 0b11111110
#define n9 0b11110110

int main()
{
  DDRB = 0xff;
  PORTB = 0b00000000;   // Puts High in all B port
  //PORTD = n9;
  int cont = 9;
  while(true){
      switch (cont)
      {
        case 0:
        if(PINB & 1<<4)
        {
          PORTD = n0 ; 
          cont--;
         _delay_ms(1000);
        }
         break;
        case 1:
         if(PINB & 1<<4){
          PORTD = n1;
          cont--;
          _delay_ms(1000);
         }
         break;
        case 2:
         if(PINB & 1<<4){
          PORTD = n2;
          cont--;
          _delay_ms(1000);
         }
         break;
        case 3:
         if(PINB & 1<<4){
          PORTD = n3;
          cont--;
          _delay_ms(1000);
         }
         break;
        case 4:
         if(PINB & 1<<4){
          PORTD = n4;
          cont--;
          _delay_ms(1000);
         }
         break;
        case 5:
         if(PINB & 1<<4){
          PORTD = n5;
          cont--;
          _delay_ms(1000);
         }
         break;
        case 6:
         if(PINB & 1<<4){
          PORTD = n6;
          cont--;
          _delay_ms(1000);
         }
         break;
        case 7:
         if(PINB & 1<<4){
          PORTD = n7;
          cont--;
          _delay_ms(1000);
         }
         break;
        case 8:
         if(PINB & 1<<4){
          PORTD = n8;
          cont--;
          _delay_ms(1000);
         }
         break;
        case 9:
        if(PINB & 1<<4){
          PORTD = n9;
          cont--;
          _delay_ms(1000);
        }
         break;

         default:
             break;
       }
    if(cont == -1 ){
      cont = 9;
    }
  }
  return 0;
}