#include <Servo.h>

int score;

// Displays de Pontuação
// display esquerdo
int esqPinoA = 46;
int esqPinoB = 47;
int esqPinoC = 48;
int esqPinoD = 49;
int esqPinoE = 50;
int esqPinoF = 51;
int esqPinoG = 52;

byte displayEsquerdo[12][7] = {

    {0, 0, 0, 0, 0, 0, 1}, // DIGITO 0
    {1, 0, 0, 1, 1, 1, 1}, // DIGITO 1
    {0, 0, 1, 0, 0, 1, 0}, // DIGITO 2
    {0, 0, 0, 0, 1, 1, 0}, // DIGITO 3
    {1, 0, 0, 1, 1, 0, 0}, // DIGITO 4
    {0, 1, 0, 0, 1, 0, 0}, // DIGITO 5
    {0, 1, 0, 0, 0, 0, 0}, // DIGITO 6
    {0, 0, 0, 1, 1, 1, 1}, // DIGITO 7
    {0, 0, 0, 0, 0, 0, 0}, // DIGITO 8
    {0, 0, 0, 0, 1, 0, 0},  // DIGITO 9
    {1, 1, 1, 1, 1, 1, 1}, // DESLIGADO
    {0, 1, 1, 1, 0, 0, 0} // F

};

void ligaDisplayEsquerdo(byte digito)
{                 // função para acionar o display com o digito correspondente
  byte pino = 46; // pino inicial do display
  // Liga os segmentos de acordo com o digito correspondente
  for (byte contadorSegmentos = 0; contadorSegmentos < 7; ++contadorSegmentos)
  {
    digitalWrite(pino, displayEsquerdo[digito][contadorSegmentos]);
    ++pino;
  }
}

// display central
int cenPinoA = 38;
int cenPinoB = 39;
int cenPinoC = 40;
int cenPinoD = 41;
int cenPinoE = 42;
int cenPinoF = 43;
int cenPinoG = 44;

byte displayCentral[12][7] = {

    {0, 0, 0, 0, 0, 0, 1}, // DIGITO 0
    {1, 0, 0, 1, 1, 1, 1}, // DIGITO 1
    {0, 0, 1, 0, 0, 1, 0}, // DIGITO 2
    {0, 0, 0, 0, 1, 1, 0}, // DIGITO 3
    {1, 0, 0, 1, 1, 0, 0}, // DIGITO 4
    {0, 1, 0, 0, 1, 0, 0}, // DIGITO 5
    {0, 1, 0, 0, 0, 0, 0}, // DIGITO 6
    {0, 0, 0, 1, 1, 1, 1}, // DIGITO 7
    {0, 0, 0, 0, 0, 0, 0}, // DIGITO 8
    {0, 0, 0, 0, 1, 0, 0}, // DIGITO 9
    {1, 1, 1, 1, 1, 1, 1}, // DESLIGADO
    {1, 1, 1, 1, 0, 0, 1} // I

};

void ligaDisplayCentral(byte digito)
{                 // função para acionar o display com o digito correspondente
  byte pino = 38; // pino inicial do display
  // Liga os segmentos de acordo com o digito correspondente
  for (byte contadorSegmentos = 0; contadorSegmentos < 7; ++contadorSegmentos)
  {
    digitalWrite(pino, displayCentral[digito][contadorSegmentos]);
    ++pino;
  }
}

// display direito
int dirPinoA = 28;
int dirPinoB = 29;
int dirPinoC = 30;
int dirPinoD = 31;
int dirPinoE = 32;
int dirPinoF = 33;
int dirPinoG = 34;

byte displayDireito[12][7] = {

    {0, 0, 0, 0, 0, 0, 1}, // DIGITO 0
    {1, 0, 0, 1, 1, 1, 1}, // DIGITO 1
    {0, 0, 1, 0, 0, 1, 0}, // DIGITO 2
    {0, 0, 0, 0, 1, 1, 0}, // DIGITO 3
    {1, 0, 0, 1, 1, 0, 0}, // DIGITO 4
    {0, 1, 0, 0, 1, 0, 0}, // DIGITO 5
    {0, 1, 0, 0, 0, 0, 0}, // DIGITO 6
    {0, 0, 0, 1, 1, 1, 1}, // DIGITO 7
    {0, 0, 0, 0, 0, 0, 0}, // DIGITO 8
    {0, 0, 0, 0, 1, 0, 0}, // DIGITO 9
    {1, 1, 1, 1, 1, 1, 1}, // DESLIGADO
    {0, 0, 0, 1, 0, 0, 1} // M
};

void ligaDisplayDireito(byte digito)
{                 // função para acionar o display com o digito correspondente
  byte pino = 28; // pino inicial do display
  // Liga os segmentos de acordo com o digito correspondente
  for (byte contadorSegmentos = 0; contadorSegmentos < 7; ++contadorSegmentos)
  {
    digitalWrite(pino, displayDireito[digito][contadorSegmentos]);
    ++pino;
  }
}

Servo servo;
void setup()
{
  // Inicialização do Serial.
  Serial1.begin(9600);
  Serial.begin(9600);

  // servo motor
  servo.attach(8);
  
  // displays
  pinMode(dirPinoA, OUTPUT);
  pinMode(dirPinoB, OUTPUT);
  pinMode(dirPinoC, OUTPUT);
  pinMode(dirPinoD, OUTPUT);
  pinMode(dirPinoE, OUTPUT);
  pinMode(dirPinoF, OUTPUT);
  pinMode(dirPinoG, OUTPUT);

  pinMode(cenPinoA, OUTPUT);
  pinMode(cenPinoB, OUTPUT);
  pinMode(cenPinoC, OUTPUT);
  pinMode(cenPinoD, OUTPUT);
  pinMode(cenPinoE, OUTPUT);
  pinMode(cenPinoF, OUTPUT);
  pinMode(cenPinoG, OUTPUT);

  pinMode(esqPinoA, OUTPUT);
  pinMode(esqPinoB, OUTPUT);
  pinMode(esqPinoC, OUTPUT);
  pinMode(esqPinoD, OUTPUT);
  pinMode(esqPinoE, OUTPUT);
  pinMode(esqPinoF, OUTPUT);
  pinMode(esqPinoG, OUTPUT);

  // inicia displays desligados
  ligaDisplayEsquerdo(10);
  ligaDisplayDireito(10);
  ligaDisplayCentral(10);
  
  servo.write(0);
}

void loop()
{  
// função para somar pontos de sensores
  if (Serial1.available() > 0)
  {
    char recebePonto = Serial1.read();
    if (recebePonto == 'u')
    {
      score += 1;
      delay(100);
      servo.write(random(180));
    }
    if (recebePonto == 'd') {
      score += 2;
      delay(100);
      servo.write(random(180));
    }
    if (recebePonto == 't') {
      score += 3;
      delay(100);
      servo.write(random(180));
    } 
    if (recebePonto == 'f') {
      score += 999;
    }
  }

  // mantem o score atual do jogaror nos displays
  if(score < 999) {
  0int scoreEsquerdo = score / 100;
  int scoreCentral = (score % 100) / 10;
  int scoreDireito = score % 10;

  ligaDisplayEsquerdo(scoreEsquerdo);
  ligaDisplayCentral(scoreCentral);
  ligaDisplayDireito(scoreDireito);
  }else{
  ligaDisplayEsquerdo(11);
  ligaDisplayCentral(11);
  ligaDisplayDireito(11);
}
  
}
