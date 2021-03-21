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

    Horse(string,string);   // Default constructor
    void setName(string);   // Holds name of the horse.
    void setRider(string);  // Holds name of the rider.
    void setMaxRunningDistPerSecond(int);   // Holds the distance
    void setDistanceTraveled(int);
    void setRacesWon(int);      // Holds the races won.
    string getName() const;     // Displays the name of the horse.
    string getRider() const;    // Displays the name of the rider
    int getMaxRunningDistPerSecond() const; // Displays the distance
    int getDistanceTraveled() const;
    int getRacesWon() const;
    void runASecond();      // Rescales the distance to what the programmer input
    void sendToGate();      // Sets the distance travelled to zero
    void displayHorse(int);  // Displays the race.
    void addRacesWon();     // Adds when there's a new race.

};


#endif //UNTITLED3_HORSE_H
