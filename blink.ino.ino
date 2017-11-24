/*
© Janis Reinberger
This program translates text to morsecode, which will be displayed with the built-in LED of the Arduino Genuino Uno
*/
char morsetext[]= "abba";
int txtlen = sizeof(morsetext); // sizeof(morsetext[0]);
bool morsing = false;
int chardelay = 4000;
int worddelay = 2000;
int inchardelay = 2000;
int sblink = 100;
int lblink = 4000;
//---------------------------------------------------Program start---------------------------------------------------//
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void exec_morse(int dec) {
    digitalWrite(LED_BUILTIN, HIGH);
    switch (dec) {
      case 0: delay(sblink); break;
      case 1: delay(lblink); break;
      case 2: break;
    }
    digitalWrite(LED_BUILTIN, LOW);
    switch (dec) {
      case 0:morsing = false; break;
      case 1: morsing = false; break;
      case 2: delay(chardelay); morsing = false; break;
      default: morsing = false; break;
    }
}

void init_morse(int i) {
    switch(morsetext[i]){
      case 'a': exec_morse(0);
                exec_morse(1);
                exec_morse(2);
                break;
      case 'b': exec_morse(1);
                exec_morse(0);
                exec_morse(0);
                exec_morse(0);
                exec_morse(2);
                break;
      case 'c': exec_morse(1);
                exec_morse(0);
                exec_morse(1);
                exec_morse(0);
                exec_morse(2);
                break;
      case 'd': exec_morse(1);
                exec_morse(0);
                exec_morse(0);
                exec_morse(2);
                break;
      case 'e': exec_morse(0);
                exec_morse(2);
                break;
      case 'f': exec_morse(0);
                exec_morse(0);
                exec_morse(1);
                exec_morse(0);
                exec_morse(2);
                break;   
      case 'g': exec_morse(1);
                exec_morse(1);
                exec_morse(0);
                exec_morse(2);
                break;  
      case 'h': exec_morse(0);
                exec_morse(0);
                exec_morse(0);
                exec_morse(0);
                exec_morse(2);
                break;    
      case 'i': exec_morse(0);
                exec_morse(0);
                exec_morse(2);
                break;             
    }
}


void loop() {
  for (int i=0; i < 4; i++) {
    while (!morsing) {       //otherwise it will go through all calculations at once and overlap the executions
      morsing = true;
      init_morse(i);
    }
  }
}




