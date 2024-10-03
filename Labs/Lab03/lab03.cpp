#include <iostream>
using namespace std;

class mass
{
public:
    void setMassAvoirdupoisPounds(int Apounds);
    void setMassTroyPounds(int Tpounds);
	void setMassMetricGrams(int grams);
	double getMassMetricGrams() const;
    double getMassAvoirdupoisPounds() const;
    double getMassTroyPounds() const;


private:
	double drams;
};


int main(int argc, char* argv[])
{
	Mass mass;
	int choice;
	int input_Mass;

	do {
		
		cout << "Enter 1 for Avoirdupois pounds, 2 for Troy pounds, 3 for grams, or 0 to exit: ";
		cin >> choice;

		switch (choice) {

			// case 1: need to do for Avoirdupois pounds. 
           // cout << "Enter mass in Avoirdupois pounds: ";
            // cin >> input_Mass;
		// .......

		
	Case 2:
		cout << "Enter mass in Troy pounds: ";
		cin >> input_Mass;
		mass.setMassTroyPounds(input_Mass);
		cout << fixed << setprecision(6);
		cout << " Mass in Avoirdupois pounds: " << mass.getMassAvoirdupoisPounds() << endl;
		cout << " Mass in Troy pounds: " << mass.getMassTroyPounds() <<endl;
		cout << " Mass in grams: " << mass.getMassMetricGrams() << endl;
		break;

	// case 3: need to mass in grams. 
	// cout << "Enter mass in grams: ";
           // cin >> input_Mass;
	   // .......


 case 0:
            cout << "Exiting program. Thanks for using the converter!" << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}




void mass:: setMassMetricGrams(int grams)
{
	drams = grams * 1.7718451953125;

}

double mass:: getMassMetricGrams() const
{
	return drams;
}

void mass:: setMassTroyPounds(int Tpounds) {
    drams = Tpounds * 96; // 1 Troy pound = 96 drams
}

double mass:: getMassTroyPounds() const {
    return drams / 96; //  drams to Troy pounds
}
//.....
