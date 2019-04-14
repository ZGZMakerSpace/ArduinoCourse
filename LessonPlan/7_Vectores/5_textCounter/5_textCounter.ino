/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/
char text_array[] = "https://zaragozamakerspace.com/";
int counter[255];

void initCounter(){ 
  for(int i =0; i < sizeof(text_array)/sizeof(char); i++){
    text_array[i] = ' ';
  }
  for(int i =0; i < 255; i++){
    counter[i] = 0 ;
  }
};

void setup() {
  Serial.begin(9600);
  
  Serial.println(text_array);
  for(int i =0; i < sizeof(text_array)/sizeof(char); i++){
    counter[ (int)text_array[i] ]++;
  }
  
  for(int i =97; i < 122; i++){
    Serial.print( (char)i );
    Serial.print(" : ");
    Serial.println( counter[i] );
  }
  initCounter();
}

void loop() {
  if (Serial.available()){
   String text = Serial.readString();
   text.toCharArray( text_array,text.length() );
   Serial.println( text_array ); 

   for(int i =0; i < sizeof(text_array)/sizeof(char); i++){
    counter[ (int)text_array[i] ]++;
    }
  
   for(int i =97; i < 122; i++){
      Serial.print( (char)i );
      Serial.print(" : ");
      Serial.println( counter[i] );
    }
    initCounter();
  }
}
