#include <Sparki.h> 

void setup() {
}

void loop() {
  int threshold = 500;

  int lineLeft   = sparki.lineLeft();   // measure the left IR sensor
  int lineCenter = sparki.lineCenter(); // measure the center IR sensor
  int lineRight  = sparki.lineRight();  // measure the right IR sens
  int dis = sparki.ping()

  if (dis == 5) {
   sparki.gripperClose();
   delay(1000);
   sparki.gipperStop();
   }

  sparki.moveLeft(180);
  sparki.moveFoward();
  delay(1000);
  spaki.moveLeft(90);
  sparki.moveFoward();
  delay(9000);
  sparki.moveRight(90);


  sparki.moveFoward();
  delay(2000);
  sparki.moveLeft(90);

  if (lineCenter > lim)  {
    sparki.moveFoward();
  }
  else  {
  sparki.stop();
  sparki.gripperOpen();
  delay(1300);
  }
