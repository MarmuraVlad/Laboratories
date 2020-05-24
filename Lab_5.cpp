#include <iostream>
#include <String>

using namespace std;

void clear() {
    cout << "____________________________________________________________" << endl;
}

class Ship {
public:
    void setShipName(string Name) {
        sName = Name;
    }
    void setShipPass(int passengers) {
        sPass = passengers;
    }
    void setShipFuel(int fuel) {
        sFuel = fuel;
    }
    void setShipValue(int value) {
        sValue = value;
    }
    void setShipMilesValue(int cost) {
        sMileValue = cost;
    }
    void setShipFuelPerMile(int fuel) {
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
    bool Move(int miles) {
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
        cout << "Ship Name - " << this->sName << endl;
        cout << "Ship Passengers - " << this->sPass << endl;
        cout << "Ship Fuel - " << this->sFuel << endl;
        cout << "Ship Value - " << this->sValue << endl;
        cout << "Ship Miles - " << this->sMiles << endl;
        clear();
    }
    Ship(string name, int passengers, int fuel, int value, int valuepermile, int fuelpermile) {
        sName = name;
        sPass = passengers;
        sFuel = fuel;
        sValue = value;
        sMileValue = valuepermile;
        sMiles = 0;
        sFuelPerMile = fuelpermile;
    }
    friend bool operator+= (Ship ship1, Ship ship2) {
        ship1.sFuel += ship2.getShipFuel();
        cout << "Ship 1 fuel = " << ship1.sFuel << endl;
        cout << "Ship 2 fuel = " << ship2.getShipFuel() << endl;
        return true;
    }
    friend bool operator-= (Ship ship1, Ship ship2) {
        ship1.sFuel -= ship2.getShipFuel();
        cout << "Ship 1 fuel = " << ship1.sFuel << endl;
        cout << "Ship 2 fuel = " << ship2.getShipFuel() << endl;
        return false;
    }
    Ship& operator= (const Ship& ship2) {
        if (this == &ship2) {
            return *this;
        }
        sFuel = ship2.sFuel;
        sPass = ship2.sPass;
        return *this;
    }
private:
    string sName;
    int sPass, sFuel, sValue, sMileValue, sMiles, sFuelPerMile;
};

bool operator == (Ship ship1, Ship ship2) {
    if (ship1.getShipFuel() == ship2.getShipFuel() && ship1.getShipName() == ship2.getShipName() && ship1.getShipMilesValue() == ship2.getShipMilesValue()) {
        return true;
    }
    else return false;
}
bool operator != (Ship ship1, Ship ship2) {
    if (ship1.getShipFuel() == ship2.getShipFuel() && ship1.getShipName() == ship2.getShipName() && ship1.getShipMilesValue() == ship2.getShipMilesValue()) {
        return false;
    }
    else return true;
}
bool operator > (Ship ship1, Ship ship2) {
    if (ship1.getShipFuel() > ship2.getShipFuel() && ship1.getShipPass() > ship2.getShipPass()) {
        return true;
    }
    else return false;
}

bool operator < (Ship ship1, Ship ship2) {
    if (ship1.getShipFuel() < ship2.getShipFuel() && ship1.getShipName() < ship2.getShipName() && ship1.getShipMilesValue() < ship2.getShipMilesValue()) {
        return true;
    }
    else return false;
}

int main() {
    string sName, sName1;
    int sPassengers, sFuel, sValue, sMileValue, sFuelPerMile;
    int sPassengers1, sFuel1, sValue1, sMileValue1, sFuelPerMile1;
    cout << "Enter a  first ship's name - ";
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
    Ship myShip1(sName, sPassengers, sFuel, sValue, sMileValue, sFuelPerMile);
    cout << endl << endl;
    cout << endl << "First ship state - " << endl;
    myShip1.State();
    cout << "Enter a second ship's name - ";
    cin >> sName1;
    cout << endl << "Enter a ship's passengers on board - ";
    cin >> sPassengers1;
    cout << endl << "Enter a ship's fuel on board - ";
    cin >> sFuel1;
    cout << endl << "Enter a ship's value - ";
    cin >> sValue1;
    cout << endl << "Enter a ship's usage value per 1 mile - ";
    cin >> sMileValue1;
    cout << endl << "Enter a ship's fuel usage per 1 mile - ";
    cin >> sFuelPerMile1;
    Ship myShip2(sName1, sPassengers1, sFuel1, sValue1, sMileValue1, sFuelPerMile1);
    cout << endl << "Second ship state - " << endl;
    myShip2.State();
    if (myShip1==myShip2) {
        cout << "Ships are same" << endl;
    }
    if (myShip1>myShip2) {
        cout << "First ship is more loaded than second" << endl;
    }
    myShip1 += myShip2;
    myShip1 = myShip2;
    myShip1.State();
    myShip2.State();
}
