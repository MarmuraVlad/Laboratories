#include <iostream>

using namespace std;

class CDevice 
{
public:
    virtual void state(bool whatState) {
        if (whatState) {
            cout << "Device is on." << endl;
        }
        else {
            cout << "Device is off" << endl;
        }
    }
    void setID(int myID) {
        id = myID;
    }
    int id;
};

class CFlashlight : public CDevice {
public:
    CFlashlight() {
        power = 1;
    }
    CFlashlight(int pow) {
        power = pow;
    }
    void operator = (CFlashlight torch) {
        this->power = torch.power;
    }
    void lightPower(int pow) {
        power = pow;
        cout << "Power is set." <<endl;
    }
protected:
    int power;
};

class CElectroShocker : public CDevice {
public:
    CElectroShocker() {
        timeUsed = 0;
    }
    ~CElectroShocker() {
        //null
    }
    void operator = (CElectroShocker shocker1) {
        this->timeUsed = shocker1.timeUsed;
    }
    void shock(int time) {
        cout << "Shocking for " << time << " seconds" << endl;
        timeUsed += time;
        cout << "Total usage time - " << timeUsed << endl;
    }
protected:
    int timeUsed;
};

class CShockingLighter : public CFlashlight, public CElectroShocker {
public:
    CShockingLighter() {
        timeUsed = 0;
        power = 0;
    }
    virtual void state(bool whatState) override {
        if (whatState) {
            cout << "ShockingLighter is on." << endl;
        }
        else {
            cout << "ShockingLighter is off" << endl;
        }
    }
};

int main()
{
    CShockingLighter my1;
    my1.state(true);
    my1.lightPower(10);
    my1.shock(5);
}

