/*
Presenter: Nguyen Mai, clarified questions/answers to problems we ran into during the coding process.
Manager: Brandon Bui, I made sure we were working on separate parts of the lab and figuring it out coding wise before we put it all
together.
Reflector: Umit Nazar, made sure everyone was working on what they needed to be and that we all understood what we were brainstorming.
Recorder: Aayush Patel, typed down each of our ideas as well as general names for the variables and/or programs we planned to code.
*/

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	double interestRate;
	double loanAmount;
	int loanPeriod;
	double totalLoan;
	double monthlyPayment;

	cout << "Please enter the annual interest rate as a percentage(e.g., 15 for 15 %) (enter 0 to quit): ";
	cin >> interestRate;

	if (interestRate <= 0)
	{
		return 0;
	}

	cout << "Please enter the amount you would like to receive: ";
	cin >> loanAmount;

	cout << "Please enter the loan period in months: ";
	cin >> loanPeriod;

	totalLoan = loanAmount * (1 + (interestRate / 100) * (loanPeriod / 12.0));
	monthlyPayment = totalLoan / loanPeriod;

	cout << "The total amount of your loan (including interest at " << interestRate << "% per annum) is $" << totalLoan << endl;
	cout << "Your monthly payment for " << loanPeriod << " months will be $" << monthlyPayment << endl;


}