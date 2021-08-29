void setup() {
  // put your setup code here, to run once:
   pinMode(5, 0);
  pinMode(4, 0);
  pinMode(3, 1);
  pinMode(2, 1);
  pinMode(8,1);
  pinMode(13, 1);
  pinMode(12, 1);
  pinMode(11, 1);
  pinMode(10, 1);
  pinMode(6,0);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  Serial.begin(9600);

}

void loop() {
  int a;
  int b;
  int c;
  a = digitalRead(4);
  b = digitalRead(5);
  c = digitalRead(6);
  int c1 = 0;
  int c2 = 0;
  if (a == 1 && b==0) // line follower starts
  {
    Serial.print("RIGHT DETECTION");
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,1);
  }
  else if (b == 1 && a==0)
  {
    Serial.print("LEFT DETECTION");
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
  }
  else if (a == 1 && b == 1)
  {
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,1);
   
    
  }
  else
  {
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0); 
  }
 //line follower ends

  if (a == 0 && b == 0 && c1 ==0) // edge follower starts
  {
    Serial.print("NO DETECTION");
    digitalWrite(13,0);
    digitalWrite(12,1);
    digitalWrite(11,1);
    digitalWrite(10,0);
    delay(3500);
    c1++;
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,1);
    delay(3500);
    //turn right 90 deg
  }
    else if (a == 0 && b == 0 && c1 ==1) // edge follower starts
  {
    Serial.print("NO DETECTION");
    digitalWrite(13,0);
    digitalWrite(12,1);
    digitalWrite(11,1);
    digitalWrite(10,0);
    delay(1000);
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,1);
    delay(7000);
    // turn right 180 deg
    
  }
  delay(100); // edge followwr ends
  if (c == 1) //obstacle deetec
  {
        digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,1);
    delay(3500);
    //turn left 90 deg
    c2 = c2 +1;;
  }
  if (a == 0 && b == 0 && c2 != 2)
  {
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
    delay(3500);
    //turn left with delay
  }
  
}
