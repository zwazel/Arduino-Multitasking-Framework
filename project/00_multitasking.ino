/* Framework, um Multitasking zu simulieren 
 *  Prinzip:
 *  Jeder Task besteht aus zwei Funktionen: task1_setup() und task1(int tasknr)
 *  Das Framework ruft in regelmässigen Abständen alle registrierten Task auf. Ein Aufruf wird im Folgenden "tick" genannt. Wir oft die ticks ausgelöst werden kann definiert werden.
 *  Standardmässig werden sie alle 1/100s aufgerufen
 *  
 *  Jeder Task besitzt einen state. Der state ist eine Zahl. Der stat kann genutzt werden, um dem Task mitzuteilen, wo er sich befinden. Z.B. kann state benutzt werden, um zu speichern,
 *  ob eine LED an ist oder nicht.
 *  Die Task-Funktion gibt einen int zurück. Dieser teilt dem Framework mit, nach wie vielen Ticks der Task erneut aufgerufen wurde. 0 - Aufruf beim nöcshten Tick. -1 kein Aufruf mehr
 *  
 *  
 *  Tasks können den state eines anderen Task ändern (dadurch ist eine Fremdsteuerung möglich)
 *  
 *     
 */

#define maxTasks 100

 

typedef int (*FunctionCallback)(int,int);
FunctionCallback tasks[maxTasks];

int taskcount;
int tickdelay = 10;                             // 10 ms delay zum nächsten Tick -> 100x pro Sekunde
unsigned long lasttick = millis();              // marker für die Erzeugung des Ticks

int waitticks[maxTasks];                        // speichert die zu wartenden ticks, bis ein Task erneut aufgerufen wird
int states[maxTasks];                           // speichert die aktuellen states der Tasks 


void setState(int tasknr,int state)
{
  states[tasknr]=state;
}


void callTasks()
{
    //schon wieder Zeit für Tick?
    if (millis()-lasttick>tickdelay)
    {
      lasttick = millis();
      for (int i=0; i<taskcount; i++)
      {
        if (waitticks[i]!=-1) //bei -1 Task nicht starten
        {
          waitticks[i]--;
          if (waitticks[i]<0)
          {
            waitticks[i] = tasks[i](i,states[i]);
          }
        }
      }
      
    }


}
