#pragma once

class Ball{


    public:
    int y,x;
    int width =20;
    int height =20;
     bool right = true;
     int ySpeed =0;
     float speedIncrease =1.0f;
     
    Ball(int xPos,int yPos);
    int move(int speed,int player1Rect[], int player2Rect[]);
    void ResetBall();

    private:
    int GetNewRandom();
    int lastCollision =0;
    int frameCounter =0;




};