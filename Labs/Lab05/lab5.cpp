#include <iostream>

using namespace std;

class ComplexNumber
{
	
public:
	ComplexNumber() : real(0), imagine(0) {}

	ComplexNumber(int r, int i)
	{
		setNumbers(r, i);
	}

	void setNumbers(int r, int i);
	void outputNumbers();

private:
	int real;
	int imagine;

};

void ComplexNumber::setNumbers(int r, int i)
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


}