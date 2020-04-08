void task1_setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

int task1(int tasknr, int state)
{
  if (state==0) 
  {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    setState(tasknr,1);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    setState(tasknr,0);
    
  }

  return 33; //nach 50 ticks (= 50x 1/100s) erneut aufrufen
}
