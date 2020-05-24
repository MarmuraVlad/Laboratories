#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int counter = 0;

void ClearLine() {
	cout << "________________________________________________________________________________" << endl;
}

void Menu() {
	ClearLine();
	cout << "What do u want to do?" << endl << "To write a data about new train, enter 1. " << endl;
	cout << "To read all saved data and summary, enter 2." << endl;
	int choose1 = 0;
	cin >> choose1;
	ClearLine();
	if (choose1 == 1) {
		cout << "Enter this required information -" << endl;
		cout << "Train Number - Train Direction - Sold Tickets - Ticket cost per unit." << endl;
		string tDirection, tNumber, tTickets, tTicketCost;
		ClearLine();
		cin >> tNumber >> tDirection >> tTickets >> tTicketCost;
		ofstream fOut;
		fOut.open("summary.txt", ios::app);
		tNumber.resize(3,' ');
		tDirection.resize(23, ' ');
		tTickets.resize(4, ' ');
		tTicketCost.resize(4, ' ');
		fOut << "|" << tNumber << "|" << tDirection << "|" << tTickets << "|" << tTicketCost << "|" << endl;
		fOut.close();
		cout << "Would u like to continue ? (1 - yes / 0 - no)" << endl;
		int choose2;
		cin >> choose2;
		ClearLine();
		if (choose2 == 1) {
			Menu();
		}
	}
	else if (choose1 == 2) {
		cout << "_______________________________________" << endl;
		cout << "|No.| Train Direction       |Tckt|Cost|";
		ifstream fIn;
		fIn.open("summary.txt");
		while (fIn) {
			string line;
			getline(fIn,line);
			cout << endl << line;
			counter++;
		}
		fIn.close();
		cout << "_______________________________________" << endl;
		int ticketTotal = 0 , profitTotal = 0;
		ifstream fIn2;
		fIn2.open("summary.txt");
		int i = 0;
		while (i<counter-1) {
			string line1;
			getline(fIn2,line1);
			int size1 = line1.size();
			line1.resize(size1-1);
			int pos1 = line1.rfind('|');
			string ln1 = line1.substr(pos1+1);
			int size2 = line1.size();
			line1.resize(size2-5);
			int pos2 = line1.rfind('|');
			string ln2 = line1.substr(pos2+1);
			for (int z = 0; z < 3; z++) {
				int pos3 = 0;
				pos3 = ln1.rfind(' ');
				if (pos3 != -1) {
					int size3 = ln1.size();
					ln1.resize(size3 - 1);
				}
			}
			for (int x = 0; x < 3; x++) {
				int pos3 = 0;
				pos3 = ln2.rfind(' ');
				if (pos3 != -1) {
					int size3 = ln2.size();
					ln2.resize(size3 - 1);
				}
			}
			ticketTotal += stoi(ln2);
			profitTotal += (stoi(ln2) * stoi(ln1));
			i++;
		}
		cout << "Total tickets sold - " << ticketTotal << endl;
		cout << "Total profit - " << profitTotal <<endl;
		fIn2.close();
		ClearLine();
		cout << "Would u like to continue ? (1 - yes / 0 - no)" << endl;
		int choose2;
		cin >> choose2;
		ClearLine();
		if (choose2 == 1) {
			counter = 0;
			Menu();
		}
	}
	else {
		cout << "Error! - wrong usage. Make sure u have entered a right number to make the action." << endl;
	}
}

int main ()
{
	Menu();
	return 0;
}
