#include <iostream>
#include <String>

using namespace std;

void clear() {
    cout << "____________________________________________________________" << endl;
}

class Ship {
    public:
        bool setShipName(string Name) {
            sName = Name;
        }
        bool setShipPass(int passengers) {
            sPass = passengers;
        }
        bool setShipFuel(int fuel) {
            sFuel = fuel;
        }
        bool setShipValue(int value) {
            sValue = value;
        }
        bool setShipMilesValue (int cost) {
            sMileValue = cost;
        }
        bool setShipFuelPerMile(int fuel) {
            sFuelPerMile = fuel;
        }
        string getShipName() {
            return sName;
        }
        int getShipPass() {
            return sPass;
        }
        int getShipFuel() {
            return sFuel;
        }
        int getShipValue() {
            return sValue;
        }
        int getShipMilesValue() {
            return sMileValue;
        }
        int getShipFuelPerMile() {
            return sFuelPerMile;
        }
        bool Move(int miles){
            sValue -= sMileValue * miles;
            sMiles += miles;
            sFuel -= sFuelPerMile * miles;
            if (sFuel > 0) {
                return true;
            }
            else if (sFuel <= 0) {
                cout << "Fuel tank empty, ship had stucked in ocean..." << endl;
                return false;
            }
        }
        void PortOut(int passengers) {
            sPass -= passengers;
        }
        void PortIn(int passengers) {
            sPass += passengers;
        }
        void State() {
            clear();
            cout << "Ship Name - " << sName << endl;
            cout << "Ship Passengers - " << sPass << endl;
            cout << "Ship Fuel - " << sFuel << endl;
            cout << "Ship Value - " << sValue << endl;
            cout << "Ship Miles - " << sMiles << endl;
            clear();
        }
        Ship(string name, int passengers, int fuel, int value, int valuepermile , int fuelpermile) {
            sName = name;
            sPass = passengers;
            sFuel = fuel;
            sValue = value;
            sMileValue = valuepermile;
            sMiles = 0;
            sFuelPerMile = fuelpermile;
        }
    private:
        string sName;
        int sPass, sFuel, sValue, sMileValue, sMiles, sFuelPerMile;

};

int main() {
    string sName;
    int sPassengers, sFuel, sValue, sMileValue, sFuelPerMile, sMilesSw, sPassIn, sPassOut;
    cout << "Enter a ship's name - ";
    cin >> sName;
    cout << endl << "Enter a ship's passengers on board - ";
    cin >> sPassengers;
    cout << endl << "Enter a ship's fuel on board - ";
    cin >> sFuel;
    cout << endl << "Enter a ship's value - ";
    cin >> sValue;
    cout << endl << "Enter a ship's usage value per 1 mile - ";
    cin >> sMileValue;
    cout << endl << "Enter a ship's fuel usage per 1 mile - ";
    cin >> sFuelPerMile;
    Ship myShip(sName, sPassengers, sFuel, sValue, sMileValue, sFuelPerMile);
    myShip.State();
    cout << endl << "Enter a distance to the next stop - " << endl;
    cin >> sMilesSw;
    bool isSuccess1 = myShip.Move(sMilesSw);
    if (isSuccess1==false) {
        return 0;
    }
    cout << "OK, ship has arrived. Enter a number of passengers that are going off the board - " << endl;
    cin >> sPassOut;
    myShip.PortOut(sPassOut);
    cout << "OK, enter a number of passengers that are going on the board - " << endl;
    cin >> sPassIn;
    myShip.PortIn(sPassIn);
    myShip.State();
}
