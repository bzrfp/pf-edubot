#include <Sparki.h>

bool achouObjeto = false; 
bool temObjeto = false;

void setup() {

  sparki.clearLCD();
  sparki.servo(SERVO_CENTER);
  sparki.gripperOpen();
  delay(5000);
  sparki.gripperStop();

}

void loop() {

  int lim = 500;
  int lineLeft   = sparki.lineLeft();
  int lineCenter = sparki.lineCenter();
  int lineRight  = sparki.lineRight();
  int cm = sparki.ping();

  if (cm < 10 && cm > -1) // verifica se tem um objeto ao fim do caminho que o sparki entrou 
  {
    temObjeto = true;
    sparki.clearLCD();
    sparki.print("achou");
    sparki.updateLCD();
  }
  
  if (!achouObjeto) // caminho de ida (antes da captura do objeto)
  
  {

    if ( lineLeft < lim )
    {
      sparki.moveLeft();
    }
    else if ( lineCenter < lim )
    {
      sparki.moveForward();
    }
    else if ( lineRight < lim )
    {
      sparki.moveRight();
    }
    else // ponto sem saida
    {
      if (temObjeto)
        {
        sparki.moveStop();
        delay(1000);
        sparki.gripperClose();
        delay(5000);
        sparki.gripperStop();
        achouObjeto = true;
        }
        
        sparki.moveRight(180);
    }

    delay(100);
  }
