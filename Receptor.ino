int signalPin =  4;   
String recibe="";
String temp="";
int van=0;
int van1=0;
int van0=0;
int recibiendo=0;

void setup()   {                
  pinMode(signalPin, INPUT); // initialize the digital pin as an output:  
  Serial.begin(9600);  // initialize serial communications at 9600 bps:
}

int estoy=0;
bool h1000=0;

void loop()                     
{

  delay(50);

  if(LOW == digitalRead(signalPin)){
    if(recibiendo==1){
      temp=temp+"1";
    }
    van1++;
    van0=0;
  }else{
    if(recibiendo==1){
      temp=temp+"0";
    }
    van0++;
    van1=0;
  }
  //Serial.println(van1);

  if(van1>35){
    van1=0;
    if(recibiendo==0){
      recibiendo=1;
      Serial.println("inicia transmision");
      temp="";
    }else{
      recibiendo=0;
      Serial.println(temp);
      int pini=0;
      int pfin=temp.length()-1;
      while(temp.charAt(pini)=='1')
        pini++;
      while(temp.charAt(pfin)=='1')
        pfin--;
      while(temp.charAt(pfin)=='0')
        pfin--;
      while(((pfin-pini)/4)%8!=0)
        pfin++;      
      temp=temp.substring(pini, pfin);
      
      Serial.println(temp);
      int cont=0;
      int suma=0;
      int bits[8];
      int posbit=0;
      int val=0;
      String cadfin="";
      for(int i=0; i<temp.length(); i++){
        suma=temp.substring(i,i+1).toInt()+suma;
        cont++;
        if(cont==4){
          cont=0;
          bits[posbit]=round(suma/4.0);
          suma=0;
          posbit++;
        }
        if(posbit==8){
          if(bits[0]==1){
            for(int j=7; j>0; j--){
              bits[j]=bits[j-1];
            }
            bits[0]=0;
          }
          Serial.println("En bits");
          for(int j=0; j<7; j++)
            Serial.print(bits[j]);
          Serial.println(bits[7]);
            val=bits[0]*128+bits[1]*64+bits[2]*32+bits[3]*16+bits[4]*8+bits[5]*4+bits[6]*2+bits[7]*1;
            if((char)val == '@')
               cadfin=cadfin+" ";
            else
               cadfin=cadfin+(char)val;
            val=0;
            posbit=0;
          }
      }
      Serial.println(cadfin);
      Serial.println("fin transmision");
      temp="";
    }
  }
  
  
}
