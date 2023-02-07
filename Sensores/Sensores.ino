//#include <Ultrasonic.h>

int opticoUm = 5;
int opticoDois = 6; 
int opticoTres = 7;

int boolOptUm;
int boolOptDois;
int boolOptTres;

int microSwitch1 = 9;
int microSwitch2 = 10;
int microSwitch3 = 11;

//int trigger = A0;
//int echo = A1;

//long duracao;
//long cm = 0;

//Ultrasonic ultrasonic(trigger, echo);

void setup() {
  // Inicialização do Serial.
  pinMode(opticoUm, INPUT);
  pinMode(microSwitch1, INPUT_PULLUP);
  pinMode(microSwitch2, INPUT_PULLUP);
  pinMode(microSwitch3, INPUT_PULLUP);
  //pinMode(echo, INPUT);
  //pinMode(trigger, OUTPUT);
  Serial1.begin(9600);
}


void loop() {
  boolOptUm = digitalRead(opticoUm); // lê o estado do sensor (alto = inativo, baixo = ativo)
  boolOptDois = digitalRead(opticoDois);
  boolOptTres = digitalRead(opticoTres);
  
  if (boolOptUm == HIGH || boolOptTres == HIGH)
    {
        Serial1.write('u');
    }
    if (boolOptDois == HIGH)
    {
        Serial1.write('d');
    }

  if(digitalRead(microSwitch1) == HIGH || digitalRead(microSwitch2) == HIGH || digitalRead(microSwitch3) == HIGH) {
    Serial1.write('t');
  }
  /*
   digitalWrite(trigger, LOW); //não envia som
   delayMicroseconds(2);
   digitalWrite(trigger,HIGH); //envia som 
   delayMicroseconds(10);
   digitalWrite(trigger,LOW); // não envia o som e espera o retorno do som enviado
   duracao = pulseIn(echo,HIGH); // Captura a duração em tempo do retorno do som.
   cm = duracao/58; // Calcula a distância

    if (cm <= 8) {
      Serial2.write('m');
    }
     */
   delay(10);  
}
