/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/
int input_array[] ={ 2, 3, 4, 11, 13};
int output_array[] ={ 5, 6, 7, 8, 9, 10, 12};

int lengthof( int int_array[] ){
  return sizeof( int_array )/sizeof( int_array[0] );
}

void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < lengthof(input_array) ; i++ ){
    pinMode( input_array[ i ], INPUT );
  }
  
  for(int i = 0; i < lengthof(output_array) ; i++ ){
    pinMode( output_array[ i ], OUTPUT );
  }
}

void loop() {
  
}
