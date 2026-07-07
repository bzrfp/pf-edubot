//é bom printar essa variavel no LCD pra ver se a contagem tá certa

#include <Sparki.h>

int  pontoSemSaida = 0;  

void setup() {
}

void loop() {
  int lim = 500;
  int lineLeft   = sparki.lineLeft();
  int lineCenter = sparki.lineCenter();
  int lineRight  = sparki.lineRight();

  bool achouLinha = true; 

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

  sparki.clearLCD();
  sparki.println(pontoSemSaida);
  sparki.updateLCD();
  
  delay(100);
}
