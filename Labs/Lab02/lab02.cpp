/*
Presenter: Nguyen Mai, clarified questions/answers to problems we ran into during the coding process.
Manager: Brandon Bui, I made sure we were working on separate parts of the lab and figuring it out coding wise before we put it all
together.
Reflector: Umit Nazar, made sure everyone was working on what they needed to be and that we all understood what we were brainstorming.
Recorder: Aayush Patel, typed down each of our ideas as well as general names for the variables and/or programs we planned to code.
*/

#include <iostream>
#include <cmath>

using namespace std;

void getWeight(int &lbs, double &oz);
void convertWeight(int lbs, double oz, int& kg, double& g);
void outputConvertedWeight(int lbs, double oz, int kg, double g);

int main(int argc, char* argv[])
{
	int lbs = -1;
	double oz = -1;
	int kg;
	double g;

	getWeight(lbs, oz);
	convertWeight(lbs, oz, kg, g);
	outputConvertedWeight(lbs, oz, kg, g);

	return 0;
}

void getWeight(int &lbs, double &oz) {
	const double OUNCES_IN_LBS = 16.0;
	cout << "Please enter the number of pounds: "; 
	while (!(cin >> lbs) || lbs < 0) // make sure valid input is checked first
	{
		cout << "Please enter a valid number of pounds (>= 0): " << flush;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Please enter the number of pounds: "; 
	}

    cout << "Please enter the number of ounces: ";
	while (!(cin >> oz) || oz < 0 || oz > OUNCES_IN_LBS) // make sure valid input is checked first
	{
		cout << "Please enter a valid number of ounces (>= 0 and <= " << OUNCES_IN_LBS << "): " << flush;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Please enter the number of ounces: "; 
	}
} 

void convertWeight(int lbs, double oz, int& kg, double& g)
{
	const double KG_IN_LBS = 0.45359237; // named constant
	const double OUNCES_IN_LBS = 16.0;
	const double GRAMS_IN_KG = 1000.0;

	double totalLbs = lbs + (oz / OUNCES_IN_LBS);
	double totalKg = totalLbs * KG_IN_LBS;

	kg = static_cast<int>(floor(totalKg));  // in C, we would do (int)floor(totalKg). However, even without explicily typecasting the variable, it would still be implicitly casted
	g = (totalKg - kg) * GRAMS_IN_KG;
}

void outputConvertedWeight(int lbs, double oz, int kg, double g)
{
	cout << lbs << " pounds and " << oz << " converts to\n";
	cout << kg << " kilograms and " << g << " grams.";
}