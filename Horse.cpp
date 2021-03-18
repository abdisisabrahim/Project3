//
// Created by Abdul Aziz Ibrahim on 2/28/21.
//
#include <string>
#include "Horse.h"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

Horse::Horse(string n, string r) {
    srand(time(0));
    name = n;
    rider = r;
    distanceTraveled = 0;
    maxRunningDistPerSecond = rand() % 100 + 1;
    racesWon = 0;
}

void Horse::setName(string n){
    name = n;
}
void Horse::setRider(string r){
    rider = r;
}
void Horse::setMaxRunningDistPerSecond(int max){
    maxRunningDistPerSecond = max;
}
void Horse::setDistanceTraveled(int dis){
    distanceTraveled = dis;
}
void Horse::setRacesWon(int won){
    racesWon = won;
}
string Horse::getName() const{
    return name;
}
string Horse::getRider() const{
    return rider;
}
int Horse::getMaxRunningDistPerSecond() const{
    return maxRunningDistPerSecond;
}
int Horse::getDistanceTraveled() const{
    return distanceTraveled;
}
int Horse::getRacesWon() const{
    return racesWon;
}

// This method adds distanceTraveled to an amount from 0-maxRunningDistPerSecond. This is the method that moves this horse along.
void Horse::runASecond(){
    int r;
    int d;
    r = rand() % getMaxRunningDistPerSecond();

    d = getDistanceTraveled() + r;

    setDistanceTraveled(d);
}

//This method reset the horse to the start of a race by setting distanceTraveled to 0.
void Horse::sendToGate() {
    setDistanceTraveled(0);
}
// Hello world
// This method will draw where the horse is along its race and graphically display in ascii how far the horse has
// gone on its way to goalLength. This will be scaled so it doesn’t overrun the screen.
void Horse::displayHorse(int goalLength) {
    const double x = 50;
    double y = x / goalLength;
    if (getDistanceTraveled() < goalLength){

        cout << "|";
        for (int i = 0; i < x; ++i) {

            if (i == floor(getDistanceTraveled() * y)){
                cout << ">";
            }
            else{
                cout << " ";
            }
        }
        cout <<  "| "  << getName() << ", ridden by " << getRider() << endl;
    }
    else{
        cout << "|";
        for (int i = 0; i < x; ++i) {

                cout << " ";

        }
        cout <<  "|> "  << getName() << ", ridden by " << getRider() << endl;

    }


}

void Horse::addRacesWon() {
    setRacesWon(getRacesWon() + 1);
}




/*string track = "|                   |";
   track[0] = '>';
   string winner_track = "|                |>";*/
