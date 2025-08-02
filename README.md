🔐 Keypad Password-Based Door Lock System  
**Short Description:** A 4x4 keypad and LCD-based password system with password reset option.

### Description:
This project implements a secure password-protected system using a 4x4 matrix keypad, LCD, and an Arduino. It allows the user to enter a password, verify access, and even reset the password with a two-step confirmation process.

### Components:
- Arduino UNO
- 4x4 Matrix Keypad
- I2C 16x2 LCD
- Jumper Wires

### Pin Configuration:
| Component | Arduino Pin |
|----------|-------------|
| Keypad Row Pins | 13, 12, 11, 10 |
| Keypad Column Pins | 9, 8, 7, 6 |
| LCD SDA | A4 |
| LCD SCL | A5 |

### Features:
- LCD prompts for input
- Validates password and grants/denies access
- `*` initiates password reset
- `#` confirms password or reset

---
