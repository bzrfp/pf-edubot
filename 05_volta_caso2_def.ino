#include <Sparki.h>
void setup (){
}

void loop (){
  
int lim = 500;
int lineLeft   = sparki.lineLeft();
int lineCenter = sparki.lineCenter();
int lineRight  = sparki.lineRight();

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

else if ( lineRight > lim && lineLeft > lim && lineCenter > lim)//voltou pro ponto de origem
  { 
    sparki.moveStop();
    sparki.gripperOpen();
    delay(5000);
    sparki.gripperStop();
  }

}
