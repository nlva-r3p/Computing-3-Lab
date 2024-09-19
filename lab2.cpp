/*
Presenter: Nguyen Mai, clarified questions/answers to problems we ran into during the coding process.
Manager: Brandon Bui, I made sure we were working on separate parts of the lab and figuring it out coding wise before we put it all
together.
Reflector: Umit Nazar, made sure everyone was working on what they needed to be and that we all understood what we were brainstorming.
Recorder: Aayush Patel, typed down each of our ideas as well as general names for the variables and/or programs we planned to code.
*/

#include <iostream>
using namespace std;
void enter_values(int &lbs, double &oz);
void conversion(int lbs, double oz, int& kg, double& g);



int main(int argc, char* argv[])
{
	int pounds;
	double ounces;
	int kilograms;
	double grams;

    cout << kilograms << endl;;
}

void enter_values(int &lbs, double &oz) {
    cout << "Please enter the number of pounds: " << endl; 
    cin >> lbs; 
    cout << "Please enter the number of ounces: " << endl;
    cin >> oz; 
} 

void conversion(int lbs, double oz, int& kg, double& g)
{
	double total;
	total = lbs + (oz / 16);
	total = total / 0.45359237;
	kg = floor(total);
	g = (total - floor(total)) * 1000;
}
