#include "Punktestand.h"

Punktestand::Punktestand(int StartPunkte){

    Punkte = StartPunkte;





};

bool Punktestand::AddPunkte() {
    Punkte++;
    if (Punkte >= PointsToWin) {   
        return true;
    }
    return false;
}

void Punktestand::SetPoints(int points){
    PointsToWin = points;
    


}