#include "../lib/WaterManager.h"

void WaterManager::FillUpWater(WaterLevel level){
    while (iwaterPtr->GetWaterLevel()<level){
        if(!iwaterPtr->Drain()){
            iwaterPtr->SetDrain(true);
        }
        if(iwaterPtr->Sink()){
            iwaterPtr->SetSink(false);
        }
    }
}

void WaterManager::EmptyWaterTank(){
    while (iwaterPtr->GetWaterLevel()>EMPTY){
        if(iwaterPtr->Drain()){
            iwaterPtr->SetDrain(false);
        }
        if(!iwaterPtr->Sink()){
            iwaterPtr->SetSink(true);
        }
    } 
}