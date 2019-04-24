#include "../lib/Program.h"

WashingProgram Program::PreProgram(){
    // to be implemented
    return progA;
}

void Program::ExecProgram(WashingProgram program){
    // to be implemented
    PreWash(program.preWashTemp);
    MainWash(program.mainWashWaterLevel, program.mainWashTemp, program.mainWashRotations);
    Centrifuge(program.centrifugeRotations);
}

void Program::PreWash(int temperature){
    // to be implemented

    // fill water at least 50%

    // add soap1

    // heatup until temp >= temperature

    // rotate clockwise, lowspeed, 60s

    // rotate anticlockwise, lowspeed, 60s

    // sink
}

void Program::MainWash(WaterLevel waterLevel, Temp temperature, int numberOfRotations){
    // to be implemented

    // fill water until >= waterLevel

    // add soap2

    // heatup until >= temperature

    // REPEAT the following *numberOfRotations
    // rotate clockwise, medspeed, 60s
    // rotate anticlockwise, medspeed, 60s

    // no heating

    // sink water until empty

    ///////////////////////////////////////////////

    // fill water until >= 50%

    // no heating

    // REPEAT the following *numberOfRotations
    // rotate clockwise, medspeed, 60s
    // rotate anticlockwise, medspeed, 60s

    // sink water until empty

}

void Program::Centrifuge(int numberOfRotations){
    // to be implemented

    // sink

    // REPEAT the following *numberOfRotations
    // rotate clockwise, highspeed, 30s
    // rotate anticlockwise, highspeed, 30s
}