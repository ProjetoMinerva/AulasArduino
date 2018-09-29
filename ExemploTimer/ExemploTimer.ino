void setup() {
  cli(); // Desabilitar todas interrupções
  TCCR2B |= _BV(0) | _BV(1) | _BV(2); // Prescaler 1024
  TIMSK2 |= _BV(0); // Aciona interrupção overflow
  sei(); // Habilita interrupções
  
  DDRB |= _BV(5); // Pino 5 como saída
  Serial.begin(9600);
}

void loop() {
  Serial.println("Victoria compra cartolina");
  delay(1000);
}

ISR(TIMER2_OVF_vect) {
  PORTB ^= _BV(5);
  volatile long long i = 999999;
  while(i--);
}

