# define RED_LED 11
# define GREEN_LED 12
# define YELLOW_LED 13
# define WHITELED_BUZZER 3
# define BUTTON 2
bool walkRequest = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(WHITELED_BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void waitWithButtonCheck(int duration) {
  unsigned long start = millis();
  while (millis() - start < duration) {
    if (digitalRead(BUTTON) == LOW) {       
      digitalWrite(WHITELED_BUZZER, HIGH);   
      walkRequest = true;
     } else {
      digitalWrite(WHITELED_BUZZER, LOW);   
    }
  }
}

void cycle(int blink){
  for (int i = 0; i < blink; i++) {

    digitalWrite(GREEN_LED, LOW);
    waitWithButtonCheck(4000);
    digitalWrite(GREEN_LED, HIGH);
    waitWithButtonCheck(0);

    digitalWrite(YELLOW_LED, LOW);
    waitWithButtonCheck(1200);
    digitalWrite(YELLOW_LED, HIGH);
    waitWithButtonCheck(0);

    digitalWrite(RED_LED, LOW);
    waitWithButtonCheck(4000);
    digitalWrite(RED_LED, HIGH);
    waitWithButtonCheck(0);

    if (walkRequest) {
    digitalWrite(WHITELED_BUZZER, HIGH);
    for(int i = 5; i > 0; i--) {
      waitWithButtonCheck(500);
    }
    digitalWrite(WHITELED_BUZZER, LOW);
    walkRequest = false;
   } 
  } 
}

void loop() {
  cycle(1);
}

