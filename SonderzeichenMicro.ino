#include <Keyboard.h>

int ms;
int i=0;

void setup() {
  Serial.begin(9600);

  Keyboard.begin();

  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);

  delay(3000);
  Serial.println("Started...");

  if(digitalRead(2)==HIGH){
    Keyboard.end(); 
  }else{
    start();
  }
}
//---------------------!GETS STARTED WHEN PIN2 IS NOT PULLED TO HIGH!-----------------
void start(){
  
}
//------------------------------------------------------------------------------------

void test(int Start, int Stop){
  for(int k = Start;k<(Stop+1);k++){
    Keyboard.press(k);
    Keyboard.print(" ");
    
    Keyboard.print(k);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(250);
  }
}

void enter(){
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void windows(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
}

void tap(String a, int mod){
  /* --------------MOD--------------
   * Nothing [0]
   * Shift[1]
   * Controll[2]
   * Alt[3]
   * 
   * Controll,Shift[4]
   * Controll,Alt[5]
   * -------------------------------
   * to use MOD u have to send only
   *       one Keystroke!!!
   * -------------------------------
   */
  for(int j=0; j<(a.length()+1); j++){
    if(mod==1){
      Keyboard.press(KEY_LEFT_SHIFT);
      
    }else if(mod==2){
      Keyboard.press(KEY_LEFT_CTRL);
      
    }else if(mod==3){
      Keyboard.press(KEY_LEFT_ALT);
      
    }else if(mod==4){
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
    }else if(mod==5){
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
    }else{
      //when 0 or wrong => !do nothing!  
    }
    specialCaracters(a[j]);
    Keyboard.releaseAll();
  }  
}


void specialCaracters(char s){
  Serial.println("Used byte:");
  Serial.println((byte)s);
  Serial.println(" ");
  /*
   * 
   * If you find new special caracters feel free to add them here:
   * 
   * }else if(((byte)s)==[ASKII number of your key you want to press]){
   *   ms = [the number of the char, where the arduino keys are lying on];  //changes /
   *   
   *   to find the arduino keys run test() in start() or read the list.txt
   * 
   */
  if(((byte)s)==35){
    ms = 92;  //changes # um
  }else if(((byte)s)==47){
    ms = 38;  //changes / um
  }else if(((byte)s)==45){
    ms = 47;  //changes - um
  }else if(((byte)s)==61){
    ms = 41;  //changes = um
  }else if(((byte)s)==37){
    ms = 37;  //changes % um
  }else if(((byte)s)==60){
    ms = 236;//changes < um
  }else if(((byte)s)==94){
    ms = 96;//changes ^ um
  }else if(((byte)s)==58){
    ms = 62;//changes : um
  }else if(((byte)s)==36){
    ms = 36;//changes $ um
  }else if(((byte)s)==43){
    ms = 223;//changes + um
  }else if(((byte)s)==225){
    ms = 45;//changes ß um
  }else{
    ms = s;  
  }
  Serial.println("Printed byte:");
  Serial.println(ms);
  Serial.println(" ");
  Serial.println(" ");
  if(! ms==0){
    Keyboard.press(ms);
    Keyboard.releaseAll();
  }
}

void loop() {
  //for some people that feel special :)
}
