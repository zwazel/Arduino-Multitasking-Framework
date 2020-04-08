void setup() {
  // setup-Funktionen der Tasks ausrufen, wenn nötig
  task1_setup();
  task2_setup();
  
  taskcount = 2;

  //tasks definieren
  tasks[0] = &task1;
  waitticks[0] = 0;     // nicht warten, sondern sofort ausführen
  states[0] =0;         // state setzen
  
  tasks[1] = &task2;
  waitticks[1] = 0;
  states[1] = 0;

}

void loop() {
  callTasks(); 
}
