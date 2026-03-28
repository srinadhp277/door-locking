#include  <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(A4,A5 ,A3 ,A2 ,A1 ,A0);

Servo lockServo;
#define SERVO_PIN 9

const byte ROWS =4;
const byte COLS =3;

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS]={0 , 1 , 2 , 3};
byte colPins[COLS]={4 , 5 , 6 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String storedPassword = "1234";
String enteredPassword = "";
int attemptCount = 0;



void setup() {

  lcd.begin(16,2);
  lockServo.attach(SERVO_PIN);
  lockServo.write(0);
  lcd.print("Enter Password: ");

}

void loop() {
  char key = keypad.getKey();
  if (key){
    handleKey(key);
  }
}

void handleKey(char key){
  if(key =='*'){
    enteredPassword="";
    lcd.clear();
    lcd.print("Enter Password: ");
  }else if (key == '#'){
    checkPassword();
  }else{
    enteredPassword += key;
    lcd.setCursor(enteredPassword.length()-1,1);
    lcd.print("*"); 
  }
}
void checkPassword() {

  if (enteredPassword == storedPassword) {
    unlockDoor();
    attemptCount = 0;

  } else {
    wrongAttempt();
    attemptCount++;
    if (attemptCount >= 3) {
      lockSystem();
    }
  }

  enteredPassword = "";
}


void unlockDoor() {
  lockServo.write(90);          // unlock
  lcd.clear();
  lcd.print("Access Granted!");
  delay(3000);
  lockServo.write(0);           // lock again
  lcd.clear();
  lcd.print("Enter Password:");
}

void wrongAttempt() {
  lcd.clear();
  lcd.print("Wrong Password!");
  lcd.setCursor(0, 1);
  lcd.print("Attempts: ");
  lcd.print(attemptCount + 1);
  delay(2000);
  lcd.clear();
  lcd.print("Enter Password:");
}

void lockSystem() {
  lcd.clear();
  lcd.print("System Locked!");
  lcd.setCursor(0, 1);
  lcd.print("Wait 30 sec...");
  delay(30000);
  attemptCount = 0;
  lcd.clear();
  lcd.print("Enter Password:");
}


