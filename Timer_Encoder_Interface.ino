
void setup() 
{
  // Datasheet page 392
  Serial.begin(115200);
  RCC_BASE->APB2ENR |= (1<<2); // Enable clock to Port A
  GPIOA_BASE->CRL |= ( (1<<3)|(1<<7) ); // PA0,PA1 as INPUT_PULLUP
  GPIOA_BASE->CRL &= ~( 1|(1<<1)|(1<<2)|(1<<4)|(1<<5)|(1<<6) );
  GPIOA_BASE->ODR |= 1|(1<<1);
  TIMER2_BASE->CR1 = TIMER_CR1_CEN; // Enable Timer
  TIMER2_BASE->CR2 = 0;
  TIMER2_BASE->SMCR |= 3; // Encoder Mode SMS = 011
  TIMER2_BASE->DIER = 0; // Disable Timer Interrupts
  TIMER2_BASE->EGR = 0;
  TIMER2_BASE->CCMR1 = 257; // Encoder Mode Enable
  TIMER2_BASE->CCMR2 = 0;   
  TIMER2_BASE->CCER = 0;
  TIMER2_BASE->PSC = 0;
  TIMER2_BASE->ARR = 3999; // 4000 Pulse Per revolution
  TIMER2_BASE->DCR = 0;
  TIMER2_BASE->CNT = 0;
}

void loop() 
{
  delay(50);
  Serial.println((TIMER2_BASE->CNT)*0.09);
}


