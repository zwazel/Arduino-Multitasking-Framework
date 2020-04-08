void task2_setup()
{
  pinMode(12, OUTPUT);
}

int task2(int tasknr, int state)
{
  if (state==0) 
  {
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    setState(tasknr,1);
  }
  else
  {
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    setState(tasknr,0);
    
  }

  return 100; //nach 50 ticks (= 50x 1/100s) erneut aufrufen
}
