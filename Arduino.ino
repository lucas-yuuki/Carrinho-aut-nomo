//=====================================
// Sensores Ultrassônicos
//=====================================

const int TRIGGER = 13;

const int ECHO_DIREITA  = 2;
const int ECHO_MEIO     = 4;
const int ECHO_ESQUERDA = 7;


const int DISTANCIA_PARADA = 30;      // cm
const int DISTANCIA_LIVRE = 80;       // cm

const int PWM_MIN = 140;              // Velocidade mínima
const int PWM_MAX = 200;              // Aproximadamente 80%
//=====================================
// Ponte H - Lado Direito
//=====================================

// Motor traseiro direito
const int IN1_D = 8;   // Ré
const int IN2_D = 6;   // Frente (PWM)

// Motor dianteiro direito
const int IN3_D = 5;   // Frente (PWM)
const int IN4_D = 3;   // Ré

//=====================================
// Ponte H - Lado Esquerdo
//=====================================

// Motor dianteiro esquerdo
const int IN1_E = 9;    // Ré
const int IN2_E = 10;   // Frente (PWM)

// Motor traseiro esquerdo
const int IN3_E = 11;   // Frente (PWM)
const int IN4_E = 12;   // Ré

//=====================================

void setup() {

  Serial.begin(9600);

  // Sensores
  pinMode(TRIGGER, OUTPUT);

  pinMode(ECHO_DIREITA, INPUT);
  pinMode(ECHO_MEIO, INPUT);
  pinMode(ECHO_ESQUERDA, INPUT);

  // Motores lado direito
  pinMode(IN1_D, OUTPUT);
  pinMode(IN2_D, OUTPUT);
  pinMode(IN3_D, OUTPUT);
  pinMode(IN4_D, OUTPUT);

  // Motores lado esquerdo
  pinMode(IN1_E, OUTPUT);
  pinMode(IN2_E, OUTPUT);
  pinMode(IN3_E, OUTPUT);
  pinMode(IN4_E, OUTPUT);

  pararMotores();
}

void loop() {
  long direita   = lerSensor(ECHO_DIREITA);
  delay(30);
  long meio      = lerSensor(ECHO_MEIO);
  delay(30);
  long esquerda  = lerSensor(ECHO_ESQUERDA);

  // Lógica de decisão
  if (meio <= DISTANCIA_PARADA) {
    // Obstáculo à frente: Parar e decidir lado
    pararMotores();
    delay(500); // Pequena pausa para estabilizar

    if (esquerda > direita) {
      girarEsquerda(200); // Gira para o lado com mais espaço
      delay(800);         // Ajuste este tempo para o giro de 90 graus
    } else {
      girarDireita(200);
      delay(800);
    }
  } else {
    // Caminho livre: Segue em frente com velocidade baseada na distância
    int velocidade = map(constrain(meio, DISTANCIA_PARADA, DISTANCIA_LIVRE), 
                         DISTANCIA_PARADA, DISTANCIA_LIVRE, 
                         PWM_MIN, PWM_MAX);
    frente(velocidade);
  }
}

//=====================================
// Leitura do sensor
//=====================================

long lerSensor(int echo) {

  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIGGER, LOW);

  long tempo = pulseIn(echo, HIGH, 30000);

  if (tempo == 0)
    return 999;

  return tempo * 0.0343 / 2;
}

//=====================================
// Movimento
//=====================================

void frente(int velocidade) {

  velocidade = 255;

  // Direita
  digitalWrite(IN1_D, LOW);
  analogWrite(IN2_D, velocidade);

  analogWrite(IN3_D, velocidade);
  digitalWrite(IN4_D, LOW);

  // Esquerda
  digitalWrite(IN1_E, LOW);
  analogWrite(IN2_E, velocidade);

  analogWrite(IN3_E, velocidade);
  digitalWrite(IN4_E, LOW);
}

void tras(int velocidade) {

  velocidade = constrain(velocidade, 0, 255);

  // -------- Lado Direito --------

  analogWrite(IN1_D, velocidade);
  digitalWrite(IN2_D, LOW);

  digitalWrite(IN3_D, LOW);
  analogWrite(IN4_D, velocidade);

  // -------- Lado Esquerdo --------

  analogWrite(IN1_E, velocidade);
  digitalWrite(IN2_E, LOW);

  digitalWrite(IN3_E, LOW);
  analogWrite(IN4_E, velocidade);
}

void pararMotores() {

  digitalWrite(IN1_D, LOW);
  digitalWrite(IN2_D, LOW);
  digitalWrite(IN3_D, LOW);
  digitalWrite(IN4_D, LOW);

  digitalWrite(IN1_E, LOW);
  digitalWrite(IN2_E, LOW);
  digitalWrite(IN3_E, LOW);
  digitalWrite(IN4_E, LOW);
}

void girarEsquerda(int velocidade) {
  // Motor esquerdo para trás, direito para frente
  digitalWrite(IN1_E, HIGH);
  analogWrite(IN2_E, 0);
  analogWrite(IN3_E, 0);
  digitalWrite(IN4_E, HIGH);

  digitalWrite(IN1_D, LOW);
  analogWrite(IN2_D, velocidade);
  analogWrite(IN3_D, velocidade);
  digitalWrite(IN4_D, LOW);
}

void girarDireita(int velocidade) {
  // Motor direito para trás, esquerdo para frente
  digitalWrite(IN1_D, HIGH);
  analogWrite(IN2_D, 0);
  analogWrite(IN3_D, 0);
  digitalWrite(IN4_D, HIGH);

  digitalWrite(IN1_E, LOW);
  analogWrite(IN2_E, velocidade);
  analogWrite(IN3_E, velocidade);
  digitalWrite(IN4_E, LOW);
}