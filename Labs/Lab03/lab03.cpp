#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

double getValidInputs();

class Mass
{
public:
	void setMassAvoirdupoisPounds(double Apounds);
	void setMassTroyPounds(double Tpounds);
	void setMassMetricGrams(double grams);
	double getMassAvoirdupoisPounds() const;
	double getMassTroyPounds() const;
	double getMassMetricGrams() const;

private:
	double drams;
};

int main(int argc, char *argv[])
{
	Mass mass;
	int choice;
	double input_Mass;

	do
	{

		cout << "Enter 1 for Avoirdupois pounds, 2 for Troy pounds, 3 for grams, or 0 to exit: ";
		cin >> choice;

		switch (choice)
		{

		case 1:
			cout << "Enter mass in Avoirdupois pounds: ";
			input_Mass = getValidInputs();
			mass.setMassAvoirdupoisPounds(input_Mass);
			cout << fixed << setprecision(6);
			cout << " Mass in Avoirdupois pounds: " << mass.getMassAvoirdupoisPounds() << endl;
			cout << " Mass in Troy pounds: " << mass.getMassTroyPounds() << endl;
			cout << " Mass in grams: " << mass.getMassMetricGrams() << endl;
			break;

		case 2:
			cout << "Enter mass in Troy pounds: ";
			input_Mass = getValidInputs();
			mass.setMassTroyPounds(input_Mass);
			cout << fixed << setprecision(6);
			cout << " Mass in Avoirdupois pounds: " << mass.getMassAvoirdupoisPounds() << endl;
			cout << " Mass in Troy pounds: " << mass.getMassTroyPounds() << endl;
			cout << " Mass in grams: " << mass.getMassMetricGrams() << endl;
			break;

		case 3:
			cout << "Enter mass in grams: ";
			cin >> input_Mass;
			mass.setMassMetricGrams(input_Mass);
			cout << fixed << setprecision(6);
			cout << " Mass in Avoirdupois pounds: " << mass.getMassAvoirdupoisPounds() << endl;
			cout << " Mass in Troy pounds: " << mass.getMassTroyPounds() << endl;
			cout << " Mass in grams: " << mass.getMassMetricGrams() << endl;
			break;

		case 0:
			cout << "Exiting program. Thanks for using the converter!" << endl;
			break;

		default:
			cout << "Invalid choice. Try again." << endl;
		}
	} while (choice != 0);

	return 0;
}

void Mass::setMassAvoirdupoisPounds(double Apounds)
{
	drams = Apounds * 256; // 1 avoirdupois pound = 256 drams
}

double Mass::getMassAvoirdupoisPounds() const
{
	return drams / 256; // drams to avoirdupois pounds
}

void Mass::setMassTroyPounds(double Tpounds)
{
	drams = Tpounds * 96; // 1 troy pound = 96 drams
}

double Mass::getMassTroyPounds() const
{
	return drams / 96; // drams to troy pounds
}

void Mass::setMassMetricGrams(double grams)
{
	drams = grams / 1.7718451953125; // 1 gram = 1/1.7718451953125 drams
}

double Mass::getMassMetricGrams() const
{
	return drams * 1.7718451953125; // drams to grams
}

double getValidInputs()
{
	double number;

	while(true)
	{
		cin >> number;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a valid number." << endl;
		}
		else if (number < 0)
		{
			cout << "Number must be greater or equal to 0." << endl;
		}
		else
		{
			return number;
		}
	}
}