//falta fazer o caso pro segundo ponto sem saída (acho que só com as prioridades ele entra no loop)
//falta abrir as garras quando achar o objeto 

#include <Sparki.h>

int  pontoSemSaida = 0;
bool achouObjeto = false; 

void setup() {
  
  sparki.gripperOpen();
  delay(5000);
}

void loop() {
  int lim = 500;
  int lineLeft   = sparki.lineLeft();
  int lineCenter = sparki.lineCenter();
  int lineRight  = sparki.lineRight();
  int cm = sparki.ping();

  bool achouLinha = true;
  
  if (!achouObjeto)
  
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
    else
    {
      // ponto sem saída
      achouLinha = false;
      sparki.moveRight(180);
    }

    //contador
    if ( !achouLinha )
    {
      pontoSemSaida++;
    }
  
    delay(100);
    
  }
  
  else
  {
    if ( pontoSemSaida == 1 ) 
    {
      if ( lineRight < lim )
      {
        sparki.moveRight();
      }
      else if ( lineCenter < lim )
      {
        sparki.moveForward();
      }
      
    }
    else if (pontoSemSaida == 3);
    {
      if ( lineCenter < lim )
      {
        sparki.moveForward();
      }
      else if ( lineLeft < lim )
      {
        sparki.moveLeft();
      }
      
    }
    
  }  
  
 }
