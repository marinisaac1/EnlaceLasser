void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
int i, temp;
// the loop function runs over and over again forever
void loop() {

  char texto[]="pao";
  int valores[sizeof(texto)-1];
  bool binarios[(sizeof(texto)-1)*8];
  for(i=0; i < sizeof(texto)-1 ; i++){
    valores[i]=int(texto[i]);
    temp = valores[i];
    for(int j=8; j>0; j--){
      binarios[i*8+8-j] = bitRead(temp,j-1);
    }
  }
  
  digitalWrite(13, HIGH);   
  delay(1800);
//  digitalWrite(13, HIGH);  
//  delay(1);
  int cars=0;
  for(i=0; i< (sizeof(texto)-1)*8; i++){
    digitalWrite(13, binarios[i]);    // turn the LED off by making the voltage LOW
    delay(200);
  }

  digitalWrite(13, LOW);
  delay(1800);
}
