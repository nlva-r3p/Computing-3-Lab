#include <iostream>

using namespace std;

class ComplexNumber
{
	
public:
	ComplexNumber() : real(0), imagine(0) {}

	ComplexNumber(double r, double i) :`
	{
		setNumbers(r, i);
	}

	void setNumbers(double r, double i);
	void outputNumbers();

private:
	double real;
	double imagine;

};

void ComplexNumber::setNumbers(double r, double i)
{
	real = r;
	imagine = i;
}

void ComplexNumber::outputNumbers()
{
	cout << "c1.Re() == " << real << ", c1.Im() == " << imagine;

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
