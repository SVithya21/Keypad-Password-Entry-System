🔐 Arduino Keypad Password Lock System
✅ Features:
Password: Initially set to "A36B"

Correct entry → Shows "Access Granted"

Wrong entry → Shows "Access Denied"

Press * → Start password change process

Enter new password → Re-enter to confirm

If confirmed, new password takes effect for this session (not saved after reset)

🔌 Pin Configuration
Component	Pin Type	Arduino Pin	Purpose
Keypad Row 1	Digital Input	13	Row R1
Keypad Row 2	Digital Input	12	Row R2
Keypad Row 3	Digital Input	11	Row R3
Keypad Row 4	Digital Input	10	Row R4
Keypad Col 1	Digital Input	9	Col C1
Keypad Col 2	Digital Input	8	Col C2
Keypad Col 3	Digital Input	7	Col C3
Keypad Col 4	Digital Input	6	Col C4
LCD (I2C)	Analog (I2C)	A4 (SDA)	LCD SDA
LCD (I2C)	Analog (I2C)	A5 (SCL)	LCD SCL

🧠 Code Logic Breakdown
✅ Mode enum
enum Mode { NORMAL, CHECK, RESET, CONFIRM };
NORMAL: Default mode, user enters password

RESET: User is entering a new password

CONFIRM: User is re-entering the new password for confirmation

✅ Main Flow in loop()
Accepts digits (0–9) and letters (A–D) from the keypad

Displays typed characters on LCD

🔘 Special Keys:
Key	Action
#	Confirms input based on current mode
*	Starts or cancels password reset

🧩 Password Change Logic:
User presses * → Mode switches to RESET, asks for new password

After entering new password → Press # → Mode switches to CONFIRM

Re-enter new password → Press # again

If match → password updated

If mismatch → error shown

⚠️ Limitation
Password is stored in RAM only (in a String).
This means the password resets back to "A36B" every time the Arduino restarts or loses power.

