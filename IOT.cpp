// Temperature sensor
void setup()
{
  pinMode(12, OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A2,INPUT);
}
void loop()
{  temp= analogRead(A2);
  if(temp>=200){
  digitalWrite(13,HIGH);
    tone(12,500,500);
  }
  digitalWrite(13,LOW);
}


// Obstacle Avoiding 
int pirsensor=0;
void setup()
{
pinMode(2,INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
}void loop()
{
  pirsensor=digitalRead(2);
  if(pirsensor==HIGH)
  {
  digitalWrite(12,HIGH);
    tone(13,500,500);
     }
digitalWrite(12,LOW);
}
