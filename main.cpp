#include <raylib.h>
#include <iostream>
#include "Player.h"
#include "Ball.h"
#include "Punktestand.h"
#include <string>

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
    bool Player1Won =false;
    bool Player2Won =false;
    Rectangle button = {500, 250, 240, 80};
    Rectangle circle = {475,390,50,50};
    bool ChangeScore = false;
    std::string input = "3";  
    int maxChars = 3; 
    int firstTime =true;
    bool OnlyNumbers = false;
    int NumberTimer = 150;
    


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


        
        int key = GetCharPressed();
        

        if (key >= 32 && key <= 125 && input.size() < maxChars && ChangeScore ){
             if (key >= '0' && key <= '9'){
                if(firstTime && !IsKeyPressed(KEY_BACKSPACE))
            {
                input ="";
                firstTime = false;
            }


            input.push_back((char)key);


             }
             else{
                if(OnlyNumbers == true){
                    NumberTimer =150;
                }
                else{
                    OnlyNumbers = true;
                }


             }
                   
            
        }
        if(IsKeyPressed(KEY_BACKSPACE) && !input.empty() && ChangeScore)
            {
                input.pop_back();
            }
        
         Vector2 mouse = GetMousePosition();
         bool hovered = CheckCollisionPointRec(mouse,circle);
         bool clicked = hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
         if(clicked){
            ChangeScore = !ChangeScore;
         }

        
        DrawCircle(500,415,25,ChangeScore ? GREEN:RED);
        int scoreToWin = 0; 
        if (!input.empty()) {
         scoreToWin = std::stoi(input);
        }
        DrawText(TextFormat("Score to win: %03i", scoreToWin), 550, 400, 30, GREEN);

        DrawText(TextFormat("PONG"),500,80,100,GREEN);
        DrawText(TextFormat("(click the red circle to change(and input a Number))"),360,550,20,GREEN);
        DrawText(TextFormat("if the button is red press an input key"),400,580,20,GREEN);
        if(OnlyNumbers){
            DrawText(TextFormat("Only Numbers Accepted"), 300, 450, 50, RED);
            NumberTimer --;
            if(NumberTimer <=0){
                OnlyNumbers =false;
                NumberTimer = 150;
            }

        }
        
        
       
        
        
        EndDrawing();

            if((IsKeyDown(KEY_W) ||IsKeyDown(KEY_S) ||IsKeyDown(KEY_I) ||IsKeyDown(KEY_K)) && !ChangeScore ){
                start = false;
                ball.ResetBall();
                player1Punkte.SetPoints(scoreToWin);
                player2Punkte.SetPoints(scoreToWin);


            }


        }
        

        

        //Inputs
        if(Player2Won ==false && Player1Won ==false)
        {
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

           

           Player = ball.move(player1Rect,player2Rect);
           if(Player == 1){
           bool HasWon = player2Punkte.AddPunkte();
           if(HasWon == true){
            ball.GameReset();
            Player2Won = true;
                
            }
            else{
                ball.ResetBall();


            }
            

           }

           if(Player == 2 ){
            bool HasWon = player1Punkte.AddPunkte();    
            if(HasWon == true){
                ball.GameReset();
                Player1Won =true;

            }
            else{
                ball.ResetBall();
                
                

            }
            

           }
            

           Vector2 mouse = GetMousePosition();
           bool hovered = CheckCollisionPointRec(mouse, button);
           bool clicked = hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);



           

        
        

        


        BeginDrawing();
        ClearBackground(BLUE);

        if(Player1Won || Player2Won){

            
            if(Player1Won)
            {
                DrawText(TextFormat(" Player 1 won (Player 2 kinda sucks)"), 260, 200, 40, GREEN);
                DrawRectangleRec(button, hovered ? LIGHTGRAY : GRAY);
                DrawText(TextFormat(" Play Again"), 500, 270, 40, DARKGRAY);
                

            }
            else{
                 DrawText(TextFormat(" Player 2 won (Player 1 kinda sucks)"), 260, 200, 40, GREEN);
                 DrawRectangleRec(button, hovered ? LIGHTGRAY : GRAY);
                 DrawText(TextFormat(" Play Again"), 500, 270, 40, DARKGRAY);
            }


            if(clicked){

            player1Punkte.Punkte =0;
            player2Punkte.Punkte =0;
            Player1Won =false;
            Player2Won =false;
            ball.Xspeed = 4;
            ball.ResetBall();


           }


           if(player1.y >=251)
           {
            player1.y -=2;
           }
           if(player1.y <=249)
           {
            player1.y+=2;
           }
           if(player2.y >=251)
           {
            player2.y -=2;
           }
           if(player2.y <=249)
           {
            player2.y+=2;
           }


            


        }
        
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
