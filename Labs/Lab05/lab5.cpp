#include <iostream>

class ComplexNumber {	
public:

	// constructors
	ComplexNumber() : real(0), imaginary(0) {}
	ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

	// mutators
	void setReal(double r); 
	void setImaginary(double i);
	void setNumbers(double r, double i);

	// accessors
	double getReal() const;
	double getImaginary() const;
	void outputNumbers() const;

	friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& number);

	ComplexNumber operator+(const ComplexNumber& other) const;
	ComplexNumber operator-(const ComplexNumber& other) const;
	ComplexNumber operator*(const ComplexNumber& other) const;
	ComplexNumber operator/(const ComplexNumber& other) const;
	ComplexNumber operator!() const;

private:
	double real;
	double imaginary;
};

void ComplexNumber::setReal(double r) {
	real = r;
}

void ComplexNumber::setImaginary(double i) {
	imaginary = i;
}

void ComplexNumber::setNumbers(double r, double i) {
	real = r;
	imaginary = i;
}

double ComplexNumber::getReal() {
	return real;
}

double ComplexNumber::getImaginary() {
	return imaginary;
}

void ComplexNumber::outputNumbers() {
	cout << "c1.Re() == " << real << ", c1.Im() == " << imaginary;
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& number) {

}

ComplexNumber operator+(const ComplexNumber& other) const {

}

ComplexNumber operator-(const ComplexNumber& other) const {

}

ComplexNumber operator*(const ComplexNumber& other) const {

}

ComplexNumber operator/(const ComplexNumber& other) const {

}

ComplexNumber operator!() const {
	
}

int main(int argc, int* argv[]) 
{
	ComplexNumber c1;
	ComplexNumber c2(1, 2);
	ComplexNumber c3(3, 4);

	cout << "Value of c1 (default constructor):" << endl;
	cout << "c1.Re() == " << c1.getReal() << ", c1.Im() == " << c1.getImaginary() << endl;

	cout << "Value of c2 (default constructor):" << endl;
	cout << "c2.Re() == " << c2.getReal() << ", c2.Im() == " << c2.getImaginary() << endl;
	cout << endl;

    	cout << "c2 + c3 (" << c2 << " + " << c3 << ") == " << (c2 + c3) << endl;
    	cout << "c2 - c3 (" << c2 << " - " << c3 << ") == " << (c2 - c3) << endl;
    	cout << "c2 * c3 (" << c2 << " * " << c3 << ") == " << (c2 * c3) << endl;
   	cout << "c2 / c3 (" << c2 << " / " << c3 << ") == " << (c2 / c3) << endl;

	cout << "Conjugate of c2 (" << c2 << ") == " << !c2 << endl; 
	cout << endl;

	vector<ComplexNumber> vec;
	for (int n = 0; n < 10; ++n) {
		vec.push_back(ComplexNumber(n, 2 * n));
	}


	cout << "Vector output using indexed for-loop:" << endl;
	for (int i = 0; i < 10; ++i) {
		cout << vec[i] << endl;
	}
	cout << endl;

	
	cout << "Vector output using iterator for-loop:" << endl;
	for ( auto it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << endl;
	}

}
