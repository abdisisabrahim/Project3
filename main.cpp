#include <iostream>
#include "Horse.h"
#include <iomanip>
using namespace std;
int main() {

    int numhorse;
    int racedis;
    int totalrace = 1;
    int winning_dist = 0;
    int compare = 0;
    int winninghorse = 0;
    srand(time(0));
    do {
        cout << "How many horses are in the race: ";
        cin >> numhorse;
        if (numhorse < 2) {
            cout << "Error. Numhorse isn't correct\n";
        }
    } while (numhorse < 2);

    cin.ignore();
    Horse *horse[numhorse];
    for (int i = 0; i < numhorse; ++i) {
        string nameOfHorse;
        string nameOfRider;
        cout << "Please give me the name of horse " << i + 1 << ": ";
        getline(cin, nameOfHorse);
        cout << "Please give me the name of the rider " << i + 1 << ": ";
        getline(cin, nameOfRider);
        horse[i] = new Horse(nameOfHorse, nameOfRider);
    }
    do {
        cout << "Please enter the distance of the race: ";
        cin >> racedis;
        if (racedis < 100) {
            cout << "Error. Race distance isn't correct\n";
        }
    } while (racedis < 100);
    bool gameover = false;
    bool winner = false;
    char choice;
    cin.ignore();
    cout << "The start!" << endl;
    for (int i = 0; i < numhorse; ++i) {

        horse[i]->displayHorse(racedis);
    }

    while (gameover == false) {
        do {
            cout << "Are you ready for the next second(y/n)?: ";
            cin >> choice;

            if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
                cout << "Error\n";
            }
        } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');

        if (choice == 'y' || choice == 'Y') {
            for (int i = 0; i < numhorse; ++i) {
                horse[i]->runASecond();
                horse[i]->displayHorse(racedis);

                if (horse[i]->getDistanceTraveled() >= racedis) {
                    winner = true;

                }
            }
            for (int i = 0; i < numhorse; ++i) {
                compare = horse[i]->getDistanceTraveled();
                if (compare > winning_dist) {
                    winninghorse = i;
                    winning_dist = compare;
                } else if (compare == winning_dist) {
                    int z = rand() % 10;
                    if (z < 5) {
                        winninghorse = i;
                    }
                }
            }

            if (winner == true) {

                horse[winninghorse]->addRacesWon();
                for (int i = 0; i < numhorse; ++i) {
                    cout << horse[i]->getName() << " has won " << horse[i]->getRacesWon() << "/" << totalrace
                         << " races." << endl;
                }
                totalrace++;
                do {
                    cout << "Do you wish to continue(y/n)?: ";
                    cin >> choice;

                    if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
                        cout << "Error\n";
                    }
                } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');
                if (choice == 'n' || choice == 'N') {
                    gameover = true;
                    cout << "Game Over!" << endl;
                } else if (choice == 'y' || choice == 'Y') {
                    winner = false;
                    cout << endl;
                    for (int i = 0; i < numhorse; ++i) {
                        horse[i]->sendToGate();
                        horse[i]->displayHorse(racedis);
                    }
                }
            }

        } else if (choice == 'n' || choice == 'N') {
            gameover = true;
            cout << "Game Over!" << endl;
            for (int i = 0; i < numhorse; ++i) {
                cout << horse[i]->getName() << " has won " << horse[i]->getRacesWon() << "/" << totalrace << " races."
                     << endl;
            }
        }


    }

    return 0;
}
