/*
  Free open Arduino Course

  Github:
  https://github.com/ZGZMakerSpace/ArduinoCourse
  Documentation:
  https://zaragozamakerspace.com/index.php/courses/curso-basico-arduino/
  
  by Zaragoza Maker Space
*/
int full_array[] ={ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int sum;
int length;

void setup() {
  Serial.begin(9600);
  length = sizeof(full_array)/sizeof(full_array[ 0 ]);
  Serial.print("Length: ");
  Serial.println( length );
  
  for(int i = 0; i < 10; i++ ){
    sum = sum + full_array[ i ];
    Serial.print("Value: ");
    Serial.print( full_array[ i ] );
    Serial.print(" Sum: ");
    Serial.println(sum);
  }
  
  Serial.print(" Mean: ");
  Serial.println( sum/length );
  
}

void loop() {
  
}
