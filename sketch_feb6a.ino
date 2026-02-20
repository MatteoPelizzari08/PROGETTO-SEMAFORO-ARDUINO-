const int PULSANTE = 3;
const int led_rosso = 9;
const int led_giallo = 10;
const int led_verde = 11;

int contatore = 0;
int numero_colore = 0;
bool ultimo_stato_pulsante = HIGH; 

void setup() {
  Serial.begin(9600);
  pinMode(PULSANTE, INPUT_PULLUP);
  pinMode(led_rosso, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_giallo, OUTPUT);
}

void loop() {
  bool stato_attuale = digitalRead(PULSANTE);
  
  if (stato_attuale == LOW && ultimo_stato_pulsante == HIGH) {
    digitalWrite(led_verde, LOW);
    digitalWrite(led_giallo, LOW); 
    digitalWrite(led_rosso, LOW);

    numero_colore = contatore % 3;
    contatore++; 
    Serial.println(numero_colore);

    delay(50); 
  }
  
  ultimo_stato_pulsante = stato_attuale;


  switch (numero_colore) {
    case 0: digitalWrite(led_rosso, HIGH); break;
    case 1: digitalWrite(led_giallo, HIGH); break;
    case 2: digitalWrite(led_verde, HIGH); break;
  }
}