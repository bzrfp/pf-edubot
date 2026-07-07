#include <Sparki.h> 

void setup() {
}

void loop() {
  int lim = 500;

  int lineLeft   = sparki.lineLeft();   
  int lineCenter = sparki.lineCenter(); 
  int lineRight  = sparki.lineRight();  

  if ( lineLeft < lim ) 
  {  
    sparki.moveLeft(); 
  }

  else if ( lineCenter < lim ) 
  {  
    sparki.moveForward();
    delay(100)
  }

  else if ( lineRight < lim )
  {
    sparki.moveRight(); 
  }  
  
  else
  {
    sparki.moveStop();
    delay(1000);
    sparki.moveRight(180);
  }

}
