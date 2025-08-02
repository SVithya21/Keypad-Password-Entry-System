#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte numRows = 4;
const byte numCols = 4;

char keymap[numRows][numCols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {13, 12, 11, 10};
byte colPins[numCols] = {9, 8, 7, 6};

Keypad keypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

String input = "";
String password = "A36B";
String newPassword = "";
String confirmPassword = "";

enum Mode { NORMAL, CHECK, RESET, CONFIRM };
Mode mode = NORMAL;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Keypad Lock");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}

void loop() {
  char key = keypad.getKey();

   if (key) {
    if ((key >= '0' && key <= '9') || (key >= 'A' && key <= 'D')) {
      input += key;
      lcd.setCursor(0, 1);
      lcd.print(input);
    }

    else if (key == '#') {
      if (mode == NORMAL) {
        if (input == password) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Access Granted");
        } else {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Access Denied");
        }
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Enter Password:");
        input = "";
      }

      else if (mode == RESET) {
        newPassword = input;
        input = "";
        mode = CONFIRM;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Re-enter New Pwd:");
      }

      else if (mode == CONFIRM) {
        confirmPassword = input;
        if (newPassword == confirmPassword) {
          password = newPassword;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Password Changed");
        } else {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Mismatch!");
        }
        delay(2000);
        input = "";
        newPassword = "";
        confirmPassword = "";
        mode = NORMAL;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Enter Password:");
      }
    }

    else if (key == '*') {
      input = "";
      if (mode == NORMAL) {
        mode = RESET;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("New Password:");
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Cancelled");
        delay(1000);
        mode = NORMAL;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Enter Password:");
      }
    }
  }
}
