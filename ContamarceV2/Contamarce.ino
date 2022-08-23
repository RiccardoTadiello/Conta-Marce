int ledPins[] = {12,11,10,9,8,7,6};
int button1 = 4;
int button2 = 3;
int folle = 5;
boolean sw_read1;
boolean sw_read2;
boolean sw_read3;
int k =0;
int knew=9;
//int contat=0;
int combinazioni[10][7]= {{0,1,1,0,0,0,0},
                          {1,1,0,1,1,0,1},
                          {1,1,1,1,0,0,1},
                          {0,1,1,0,0,1,1},
                          {1,0,1,1,0,1,1},
                          {1,0,1,1,1,1,1},
                          {1,1,1,0,0,0,0},
                          {1,1,1,1,1,1,1},
                          {1,1,1,1,0,1,1},
                          {1,0,0,0,1,1,1}};
//variabili Manfredi pelato                       
unsigned int currentGear = 0; //Inizialmente dovrebbe assumere la marcia lasciata dall'ultimo utilizzo(come si fa? Eh signor magi?)
bool BlockIncrement = false;
bool BlockDecrement = false;

void setup() {

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(folle, INPUT);

  for(int i=0; i<10; i++){
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i],LOW); 
  }
}

void loop() {

  if(digitalRead(button1) && !BlockDecrement)//Decrementa Marcia Premuto (Bottone1)
  {
    // BlockDecrement = true;
    // BlockIncrement = false;
    
    //verifico che la marcia sia > 0 per decrementarla
    if(currentGear > 0)
      currentGear--;
      
    for(int i=0; i<7; i++)
    {
      if(combinazioni[currentGear][i] == 1){
        digitalWrite(ledPins[i], HIGH);
      }
      else{
        digitalWrite(ledPins[i], LOW);
      }
    }
    delay(300);
  }
  else if(digitalRead(button2) && !BlockIncrement)//Incrementa Marcia Premuto (Bottone2)
  {
    // BlockIncrement = true;
    // BlockDecrement = false;
    
    //verifico che la marcia sia < 5 per incrementarla
    if(currentGear < 5)
      currentGear++;
    
    for(int i=0; i<7; i++){
      if(combinazioni[currentGear][i] == 1){
        
        digitalWrite(ledPins[i], HIGH);
     }
     else{
      digitalWrite(ledPins[i], LOW);
      }
    }
    delay(300);
  }
  else if(digitalRead(folle))//bottone folle pazzo in culo premuto (folle)
  {
    k=0; 
    for(int j=0; j<7; j++){
      if(combinazioni[knew][j] == 1){
        
        digitalWrite(ledPins[j], HIGH);
      }
     else{
      digitalWrite(ledPins[j], LOW);
      }
    }
    delay(300);
  }
  
  //Quando il bottone "marcia giù" non è premuto, riabilito la lettura del bottone
  if(!digitalRead(button1)){
    BlockDecrement = false;
  }
  //Quando il bottone "marcia su" non è premuto, riabilito la lettura del bottone
  if(!digitalRead(button2)){
    BlockIncrement = false;
  }
  
  
  
  







  sw_read1 = digitalRead(button1);
  sw_read2 = digitalRead(button2);
  sw_read3 = digitalRead(folle);
  if(sw_read1)
  {
    k--;
    if(k<0){
    k=0;
    }
    for(int j=0; j<7; j++){
      if(combinazioni[k][j] == 1){
        
       digitalWrite(ledPins[j], HIGH);
      }
      else{
       digitalWrite(ledPins[j], LOW);
      }
   }
    delay(300);
  }

  if(sw_read2)
  {
    k++;
    if(k>5){
    k=5;
    }
    for(int j=0; j<7; j++){
      if(combinazioni[k][j] == 1){
        
        digitalWrite(ledPins[j], HIGH);
     }
     else{
      digitalWrite(ledPins[j], LOW);
      }
    }
    delay(300);
  }

  if(sw_read3){

    k=0; 
    for(int j=0; j<7; j++){
      if(combinazioni[knew][j] == 1){
        
        digitalWrite(ledPins[j], HIGH);
      }
     else{
      digitalWrite(ledPins[j], LOW);
      }
    }
    delay(300);

  }


 /* for(int j=0; j<7; j++){
      if(combinazioni[k][j] == 1){
        
        digitalWrite(ledPins[j], HIGH);
     }
     else{
      digitalWrite(ledPins[j], LOW);
     }
   }
    delay(150);*/


}