#include "Player.h"

Player::Player(int xPos, int yPos){
    x=xPos;
    y=yPos;
   

    

}

void Player::move(bool Yup,int speed){


    




        if(Yup == true){

            y+=speed;
        }
        if(Yup == false){
            y-=speed;
        }

   



}