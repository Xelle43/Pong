#include <raylib.h>
#include <iostream>
#include "Player.h"
#include "Ball.h"
#include "Punktestand.h"

int main(){
    InitWindow(1200,600,"PingPong");
    SetTargetFPS(60);

    Player player1(10,10);
    Player player2(1170,10);
    Punktestand player1Punkte(0);
    Punktestand player2Punkte(0);

    Ball ball(600,300);
    int speed =6;
    int Ballspeed = 4;
    srand(time(0));
    int Player=0;
    bool start = true;
    


    while(WindowShouldClose() == false){

        while(start == true){
            if(WindowShouldClose()== true){
                CloseWindow();
                return 0;
            }

        BeginDrawing();
        ClearBackground(BLUE);

        DrawText(TextFormat("%02i", player1Punkte.Punkte), 200, 120, 70, GREEN);
        DrawText(TextFormat("%02i", player2Punkte.Punkte), 1000, 120, 70, GREEN);
        DrawRectangle(player1.x,player1.y,player1.width,player1.height,WHITE);
        DrawRectangle(player2.x,player2.y,player1.width,player1.height,WHITE);
        DrawCircle(ball.x,ball.y,20,WHITE);
       
        
        
        EndDrawing();

            if(IsKeyDown(KEY_W) ||IsKeyDown(KEY_S) ||IsKeyDown(KEY_I) ||IsKeyDown(KEY_K)){
                start = false;
                ball.ResetBall();


            }


        }

        

        //Inputs
            if (IsKeyDown(KEY_W) && player1.y >0) {
                player1.move(false,speed);
            }    
            if (IsKeyDown(KEY_S) && player1.y <450){
                player1.move(true,speed);
            }  
            
            if (IsKeyDown(KEY_I) && player2.y >0) {
                player2.move(false,speed);
            }    
            if (IsKeyDown(KEY_K) && player2.y <450){
                player2.move(true,speed);
            } 
            //Top-Left Top-Right Bottom-Right Bottom-Left
            int player1Rect[] ={
                player1.x,
                player1.y,
                player1.width,
                player1.height
                
            };
            int player2Rect[] ={
                player2.x,
                player2.y,
                player2.width,
                player2.height
                
            };

           

           Player = ball.move(Ballspeed,player1Rect,player2Rect);
           if(Player == 1){
            player2Punkte.AddPunkte();
            ball.ResetBall();

           }
           if(Player ==2 ){
            player1Punkte.AddPunkte();
            ball.ResetBall();
           }
            


          
        
        

        


        BeginDrawing();
        ClearBackground(BLUE);

        DrawText(TextFormat("%02i", player1Punkte.Punkte), 200, 120, 70, GREEN);
        DrawText(TextFormat("%02i", player2Punkte.Punkte), 1000, 120, 70, GREEN);
        DrawRectangle(player1.x,player1.y,player1.width,player1.height,WHITE);
        DrawRectangle(player2.x,player2.y,player1.width,player1.height,WHITE);
        DrawCircle(ball.x,ball.y,20,WHITE);
       
        
        
        EndDrawing();




    }


    CloseWindow();
    return 0;
}
