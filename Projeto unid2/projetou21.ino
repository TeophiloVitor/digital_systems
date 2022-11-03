// C++ code
//
bool luz = false;
bool e = true;
bool d = true;
void setup()
{
  DDRB = 0b00000000;
  PORTB = 0b00000000;
  Serial.begin(9600);
  ADMUX |= (1<<REFS0);
  ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}

void loop()
{
  ADMUX &= 0b11110000;
  ADMUX |= 0b00000000;
  ADCSRA |= (1<<ADSC);
  while(ADCSRA & (1<<ADSC));
  int A0 = ADC;

  if(A0 == 341){
    if(PINB & (1<<4) && luz == false){ //Pino para os faróis (branco)
      PORTD |= (1<<7);
      luz = true;
      delay(50);
    }
    else if(PINB & (1<<4) && luz == true){ //Pino para os faróis (branco)
      PORTD &= ~(1<<7);
      luz = false;
      delay(50);
    }

    if(PINB & 1<<3){ //Pino da seta-esquerda (laranja)
      if(e){
      	PORTD |= (1<<5);
      }
      else {
      	PORTD &= ~(1<<5);
      }
      e = !e;
    }
    else {
		PORTD &= ~(1<<5);
    }

    if(PINB & 1<<2){ //Pino da seta-direita (amarelo)
      if(d){
      	PORTD |= (1<<4);
      }
      else {
      	PORTD &= ~(1<<4);
      }
      d = !d;
    }
    else {
		PORTD &= ~(1<<4);
    }
    ADMUX &= 0b11110000;
    ADMUX |= 0b00000010;
    ADCSRA |= (1<<ADSC);

    while(ADCSRA & (1<<ADSC)); 
    long convert = (ADCH << 8) | ADCL;
    long fuel = (1023 - convert)/10.2; 
    Serial.print("Combustivel: ");
    Serial.print(fuel);
    Serial.println(" %");
  }
  else if(A0 == 682){
    PORTD |= (1<<6); //Pino da injeção eletrônica (vermelho)
    
    if(PINB & (1<<4) && luz == false){ //Pino para os faróis (branco)
      PORTD |= (1<<7);
      luz = true;
      delay(50);
    }
    else if(PINB & (1<<4) && luz == true){ //Pino para os faróis (branco)
      PORTD &= ~(1<<7);
      luz = false;
      delay(50);
    }

    if(PINB & 1<<3){ //Pino da seta-esquerda (laranja)
      if(e){
      	PORTD |= (1<<5);
      }
      else {
      	PORTD &= ~(1<<5);
      }
      e = !e;
    }
    else {
		PORTD &= ~(1<<5);
    }

    if(PINB & 1<<2){ //Pino da seta-direita (amarelo)
      if(d){
      	PORTD |= (1<<4);
      }
      else {
      	PORTD &= ~(1<<4);
      }
      d = !d;
    }
    else {
		PORTD &= ~(1<<4);
    }
    
    ADMUX &= 0b11110000;
    ADMUX |= 0b00000010;
    ADCSRA |= (1<<ADSC);

    while(ADCSRA & (1<<ADSC)); 
    long convert = ADCL | (ADCH << 8);
    long fuel = (1023 - convert)/10.2; 
    Serial.print("Combustivel: ");
    Serial.print(fuel);
    Serial.print(" %");

    ADMUX &= 0b11110000;
    ADMUX |= 0b00000001;
    ADCSRA |= (1<<ADSC);


    while(ADCSRA & (1<<ADSC));
    convert = ADCL | (ADCH << 8);
    long speed = (1023 - convert)/3.3;
    Serial.print(" | Velocidade: ");
    Serial.print(speed);
    Serial.println(" Km/h");
}      
  if(PINB & 1<<5){ //Pino do servo motor
  }
  delay(500);//Espera 500 millisegundos
}