#include "notas.h"

// Variaveis
int Buzzer1 = 7;

int ffvic[] = {
  NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3,
  NOTE_G4, NOTE_A4, NOTE_B3, NOTE_A4, NOTE_B3,
  NOTE_C4, NOTE_AS4, NOTE_C4, NOTE_AS4, NOTE_AS4,
  NOTE_DS4, NOTE_DS4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_D4,
  NOTE_C4, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_G4,
  NOTE_C4, NOTE_AS4, NOTE_C4, NOTE_AS4, NOTE_AS4,
  NOTE_DS4, NOTE_DS4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_D4,
  NOTE_C4, NOTE_AS4, NOTE_C4, NOTE_DS4, NOTE_F4
}; 

int zelda[] = {
  NOTE_E6, NOTE_G6, NOTE_D6, NOTE_C6, NOTE_E6, NOTE_G6, NOTE_D6,
  NOTE_E6, NOTE_G6, NOTE_D7, NOTE_C7, NOTE_G6, NOTE_F6, NOTE_E6, NOTE_G6,
  NOTE_G6, NOTE_D6, NOTE_E6, NOTE_G6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_G6, NOTE_D6,
  NOTE_E6, NOTE_G6, NOTE_D7, NOTE_C7, NOTE_G6, NOTE_F6, NOTE_E6, NOTE_D6
};

int pokemon[] = {
  
};

void tocaZelda() {
  for (int i = 0; i < 28; i++)
    {
      tone(Buzzer1, zelda[i], 550);
      delay(550);
    }
}

void setup()
{
  pinMode(Buzzer1, OUTPUT);
  Serial2.begin(9600);
  Serial.begin(9600);
}

void loop()
{  
  if(Serial2.available() > 0){
    char recebeSinal;
    recebeSinal = Serial2.read();

    if(recebeSinal == 'f') {
      tocaZelda();
    }
  }
}
