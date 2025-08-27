#pragma once

class Player{



    public:
        int y,x;
        int width =20;
        int height =150;
        bool IsOnWinningStreak = false;
       
       

        Player(int xPos, int yPos);
       void move(bool Yup, int speed);        
             
};




