/*
  4x4x4 LED Cube
  Connection Setup: 
  Columns
  [(x,y)-Pin]
  (1,1)-13
  (1,2)-12
  (1,3)-11
  (1,4)-10
  (2,1)-9
  (2,2)-8
  (2,3)-7
  (2,4)-6
  (3,1)-5
  (3-2)-4
  (3-3)-3
  (3,4)-2
  (4,1)-1
  (4,2)-0
  (4,3)-A5
  (4,4)-A4
  Layers
  [layer-Pin]
  a-A0
  b-A1
  c-A2
  d-A3
*/
//initializing and declaring led rows
  int column[16]={14,15,16,17,18,19,20,21,35,37,39,41,43,45,47,49};
//initializing and declaring led layers
  int layer[4]={4,5,6,7};

  int time = 250;
 
void setup()
{
  //setting rows to ouput
  for(int i = 0; i<16; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  //setting layers to output
  for(int i = 0; i<4; i++)
  {
    pinMode(layer[i], OUTPUT);
  }
  }

void loop()
{
  //turnEverythingOn();//turn all off
  //delay(1000);
  //turnEverythingOff();//turn all on
  //delay(5000);
  set1(); delay(1200);
  set2(); delay(1150);
  
  inside();
  inside();
  outside();
  turnEverythingOff(); delay(150);  

  inside();
  inside();
  outside();
  turnEverythingOff();  delay(150);  
  
  inside();
  corners();
  turnEverythingOff(); delay(150);
  turnEverythingOn(); delay(300);

  turnEverythingOff(); delay(1000);
  
}


//xxxxxxxxxxxxxxxxxxxxFUNCTIONSxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void set1(){
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 1);
  }
  
  digitalWrite(layer[0], 0); digitalWrite(layer[1], 0); delay(200);
  digitalWrite(layer[0], 1); digitalWrite(layer[1], 1); delay(100);
  
  digitalWrite(layer[1], 0); digitalWrite(layer[2], 0); delay(200);
  digitalWrite(layer[1], 1); digitalWrite(layer[2], 1); delay(100);
  
  digitalWrite(layer[2], 0); digitalWrite(layer[3], 0); delay(200);
  digitalWrite(layer[2], 1); digitalWrite(layer[3], 1); delay(100);
}

void set2(){
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 1);
  }

  digitalWrite(layer[2], 0); digitalWrite(layer[3], 0); delay(200);
  digitalWrite(layer[2], 1); digitalWrite(layer[3], 1); delay(100);
 
  
  digitalWrite(layer[1], 0); digitalWrite(layer[2], 0); delay(200);
  digitalWrite(layer[1], 1); digitalWrite(layer[2], 1); delay(100);
  
  digitalWrite(layer[0], 0); digitalWrite(layer[1], 0); delay(200);
  digitalWrite(layer[0], 1); digitalWrite(layer[1], 1); delay(100);
}

void inside(){
  turnEverythingOff();
  digitalWrite(column[5], 1); digitalWrite(column[6], 1);
  digitalWrite(column[9], 1); digitalWrite(column[10], 1);

  digitalWrite(layer[1], 0); digitalWrite(layer[2], 0); delay(150);
  digitalWrite(layer[1], 1); digitalWrite(layer[2], 1); delay(150);  
}

void outside(){
  turnEverythingOn();
  digitalWrite(column[5], 0); digitalWrite(column[6], 0);
  digitalWrite(column[9], 0); digitalWrite(column[10], 0);

  digitalWrite(layer[0], 0); digitalWrite(layer[1], 0); digitalWrite(layer[2], 0); digitalWrite(layer[3], 0); delay(300);
}

void corners(){
  turnEverythingOff();
  digitalWrite(column[0], 1); digitalWrite(column[3], 1); digitalWrite(column[12], 1); digitalWrite(column[15], 1); 
  digitalWrite(layer[0], 0); digitalWrite(layer[3], 0); 
  delay(250);
}

///////////////////////////////////////////////////////////turn all off
void turnEverythingOff()
 {
   for(int i = 0; i<16; i++)
   {
     digitalWrite(column[i], 0);
   }
   for(int i = 0; i<4; i++)
   {
     digitalWrite(layer[i], 1);
   }
 }
 
////////////////////////////////////////////////////////////turn all on
void turnEverythingOn()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 1);
  }
  //turning on layers
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 0);
  }
}

