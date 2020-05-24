#include <iostream>

using namespace std;

class Car {
public:
	int getSpeed() {
		return Speed;
	}
	int getmaxPax() {
		return maxPax;
	}
	int getmaxSpeed() {
		return maxSpeed;
	}
	void setSpeed(int speed) {
		Speed = speed;
	}
	void setmaxPax(int pax) {
		maxPax = pax;
	}
	void setmaxSpeed(int speed) {
		maxSpeed = speed;
	}
	virtual void Move () = 0;
	virtual void offPass() = 0;
	virtual ~Car() {
		cout << "Deleted" << endl;
	}
protected:
	int Speed, maxPax, maxSpeed;
};

class Armored_Car :public Car {
public:
	int getArmor() {
		return Armor;
	}
	bool getisSwim() {
		return isSwim;
	}
	bool getisWeapon() {
		return isWeapon;
	}
	void setArmor(int pow) {
		Armor = pow;
	}
	void setisSwim(bool is) {
		isSwim = is;
	}
	void setisWeapon(bool is) {
		isWeapon = is;
	}
	void Shooted(int damage) {
		if (Armor < damage) {
			cout << "Vehicle is destroyed." << endl;
		}
		else Armor -= damage;
	}
	virtual void Move() override{
		cout << "Armored Car is moving." << endl;
	}
	virtual void offPass() override {
		cout << "Armored Car has its pax off." << endl;
	}
	Armored_Car operator= (const Armored_Car &armcar) {
		this->Armor = armcar.Armor;
		this->isSwim = armcar.isSwim;
		this->isWeapon = armcar.isWeapon;
		this->maxPax = armcar.maxPax;
		this->maxSpeed = armcar.maxSpeed;
		this->Speed = 0;
	}
	void Swim(int dist) {
		//swim
		if (isSwim == true) {
			cout << "Vehicle is swimming." << endl;
		}
		else cout << "Vehicle cannot swim and destroyed." << endl;
	}
	Armored_Car() {
		Armor = 0;
		isSwim = false;
		isWeapon = false;
		Speed = 0;
		maxPax = 2;
		maxSpeed = 1;
	}
	Armored_Car(const Armored_Car &armcar) {
		this->Armor = armcar.Armor;
		this->isSwim = armcar.isSwim;
		this->isWeapon = armcar.isWeapon;
		this->maxPax = armcar.maxPax;
		this->maxSpeed = armcar.maxSpeed;
		this->Speed = 0;
	}
	Armored_Car(int speed, int armor, int max_pax, bool swim, bool weap ) {
		Speed = speed;
		Armor = armor;
		maxPax = max_pax;
		isSwim = swim;
		isWeapon = weap;
	}
	
private:
	int Armor;
	bool isSwim, isWeapon;
};

int main() 
{
	cout << "Enter a speed of vehicle - " << endl;
	int speed;
	cin >> speed;
	cout << "Enter an armour of vehicle - " << endl;
	int arm;
	cin >> arm;
	Armored_Car armcar(speed, arm, 15, true, true);
	armcar.Swim(1);
	armcar.Move();
	return 0;
}
