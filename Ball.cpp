#include "Ball.h"
#include <iostream>
#include <cstdlib>
#include <cmath>


Ball::Ball(int xPos, int yPos){
x=xPos;
y=yPos;









}
int Ball::move(int speed,int player1Rect[], int player2Rect[]){

frameCounter++;

    if (
    (x - width < player2Rect[0] + player2Rect[2] &&
     x + width > player2Rect[0] &&
     y - height < player2Rect[1] + player2Rect[3] &&
     y + height > player2Rect[1]) ||

    (x - width < player1Rect[0] + player1Rect[2] &&
     x + width > player1Rect[0] &&
     y - height < player1Rect[1] + player1Rect[3] &&
     y + height > player1Rect[1])
        )
         {
   //speed =0;
   //ySpeed =0;

    if (frameCounter - lastCollision > 5)
    {
     
      right =! right;  
      ySpeed = GetNewRandom();
      speedIncrease *= 1.1;
      lastCollision = frameCounter;
     
    }
    
 }
      if(y <=0 || y >= 580){


    ySpeed =ySpeed *-1;


     }




    x += right ? speed * speedIncrease: -speed * speedIncrease;
    y +=ySpeed * speedIncrease;





if (x <= 0) {
    return 1;   // links
} 
else if (x >= 1200) {
    return 2;   // rechts
} 
else {
    return 0;   // noch im Feld
}



}



     /*
xy width height
if(player1.x < player2.x + player2.width &&
    player1.x + player1.width > player2.x &&
    player1.y < player2.y + player2.height &&
    player1.y + player1.height > player2.y)



*/
   
  


int Ball::GetNewRandom() {
    return (rand() % 11) - 5;
}

void Ball::ResetBall(){
  int random = rand() % 2;

  if(random == 1)
  {
    right = false;
  }
  else{
    right = true;
  }
  ySpeed =0;


  y=300;
  x=600;
  speedIncrease =1;

};