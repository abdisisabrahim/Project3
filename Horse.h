//
// Created by Abdul Aziz Ibrahim on 2/28/21.
//

#ifndef HORSE_H
#define HORSE_H
#include <string>
using namespace std;

class Horse{
private:
   string name,     // A string holding the horses name.
          rider;    // A string holding the rider’s name.
   int maxRunningDistPerSecond, // An int that holds the maximum distance the horse could run in one second.
       distanceTraveled, //How far the horse has gone already.
       racesWon; //An int that determines how much races this horse and rider have won
public:

    Horse(string,string);
    void setName(string);
    void setRider(string);
    void setMaxRunningDistPerSecond(int);
    void setDistanceTraveled(int);
    void setRacesWon(int);
    string getName() const;
    string getRider() const;
    int getMaxRunningDistPerSecond() const;
    int getDistanceTraveled() const;
    int getRacesWon() const;
    void runASecond();
    void sendToGate();
    void displayHorse(int);
    void addRacesWon();

};


#endif //UNTITLED3_HORSE_H
