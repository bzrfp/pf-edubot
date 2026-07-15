#include <Sparki.h>

int  pontoSemSaida = 0;
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

  bool achouLinha = true;

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
    else // ponto sem saída
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
      achouLinha = false;
      sparki.moveRight(180);
    }

    //contador (para que idenfiquemos em que saída o sparki encontrou o objeto)
    if ( !achouLinha )
    {
      pontoSemSaida++;
      sparki.clearLCD();
      sparki.print(pontoSemSaida);
      sparki.updateLCD();
    }
  
    delay(100);
    
  }
  
  else // caminho de volta 
  {

    if ( pontoSemSaida == 1 ) 
    {
      if ( lineLeft < lim)
      {
        sparki.moveLeft();
      }
      else if ( lineRight < lim )
      {
        sparki.moveRight();
      }
      else if ( lineCenter < lim )
      {
        sparki.moveForward();
      }
      else //voltou pro ponto de origem
      { 
        sparki.moveStop();
        sparki.gripperOpen();
        delay(5000);
        sparki.gripperStop();
      }
    }
    
    else if (pontoSemSaida == 2)
    {
      if (lineRight < lim && lineLeft < lim) // logo apos capturar o objeto, evita o loop
      {
         sparki.moveForward(5); // medimos experimentalmente para que o sparki fique centralizado apos a curva
         sparki.moveRight(90);
         sparki.moveForward(10);
      }
      else if ( lineLeft < lim )
      {
        sparki.moveForward(5); // tambem para ajudar na centralizacao
        sparki.moveLeft(90);     
      }
      else if ( lineCenter < lim )
      {
        sparki.moveForward();
      }    
      else if (lineRight < lim)
      {
        sparki.moveRight();
      }
      else //voltou pro ponto de origem
      { 
        sparki.moveStop();
        sparki.gripperOpen();
        delay(5000);
        sparki.gripperStop();
      }
    }
    
    else if (pontoSemSaida == 3)
    {
      if ( lineLeft < lim )
      {
        sparki.moveLeft();
      }
      else if ( lineCenter < lim )
      {
        sparki.moveForward();
      }
      else if (lineRight < lim)
      {
        sparki.moveRight();
      }
      else //voltou pro ponto de origem
      { 
        sparki.moveStop();
        sparki.gripperOpen();
        delay(5000);
        sparki.gripperStop();
      } 
    }
    
  }  
  
 }
