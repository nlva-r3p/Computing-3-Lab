#include <iostream>
#include <vector>

class ComplexNumber {
public:
    // Constructors
    ComplexNumber() : real(0), imaginary(0) {}
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    // Mutators
    void setReal(double r);
    void setImaginary(double i);
    void setNumbers(double r, double i);

    // Accessors
    double getReal() const;
    double getImaginary() const;
    void outputNumbers() const;

    // Operator overloads
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

// Mutator definitions
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

// Accessor definitions
double ComplexNumber::getReal() const {
    return real;
}

double ComplexNumber::getImaginary() const {
    return imaginary;
}

void ComplexNumber::outputNumbers() const {
    std::cout << "Re == " << real << ", Im == " << imaginary << std::endl;
}

// Operator overload definitions
std::ostream& operator<<(std::ostream& os, const ComplexNumber& number) {
    os << number.real;
    if (number.imaginary >= 0)
        os << '+';
    os << number.imaginary << 'i';
    return os;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    return ComplexNumber(real + other.real, imaginary + other.imaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
    return ComplexNumber(real - other.real, imaginary - other.imaginary);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    double newReal = real * other.real - imaginary * other.imaginary;
    double newImaginary = real * other.imaginary + imaginary * other.real;
    return ComplexNumber(newReal, newImaginary);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    double newReal = (real * other.real + imaginary * other.imaginary) / denominator;
    double newImaginary = (imaginary * other.real - real * other.imaginary) / denominator;
    return ComplexNumber(newReal, newImaginary);
}

ComplexNumber ComplexNumber::operator!() const {
    return ComplexNumber(real, -imaginary);
}

// Main function
int main() {
    ComplexNumber c1; // Default constructor
    ComplexNumber c2(1, 2); // Value constructor
    ComplexNumber c3(3, 4);

    std::cout << "Value of c1 (default constructor):" << std::endl;
    std::cout << "c1.Re() == " << c1.getReal() << ", c1.Im() == " << c1.getImaginary() << std::endl;

    std::cout << "Value of c2 (value constructor):" << std::endl;
    std::cout << "c2.Re() == " << c2.getReal() << ", c2.Im() == " << c2.getImaginary() << std::endl;

    // Test arithmetic operations
    std::cout << "c2 + c3 (" << c2 << " + " << c3 << ") == " << (c2 + c3) << std::endl;
    std::cout << "c2 - c3 (" << c2 << " - " << c3 << ") == " << (c2 - c3) << std::endl;
    std::cout << "c2 * c3 (" << c2 << " * " << c3 << ") == " << (c2 * c3) << std::endl;
    std::cout << "c2 / c3 (" << c2 << " / " << c3 << ") == " << (c2 / c3) << std::endl;

    // Test complex conjugate
    std::cout << "Conjugate of c2 (" << c2 << ") == " << !c2 << std::endl;

    // Vector of complex numbers
    std::vector<ComplexNumber> vec;
    for (int n = 0; n < 10; ++n) {
        vec.push_back(ComplexNumber(n, 2 * n));
    }

    std::cout << "Vector output using indexed for-loop:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << vec[i] << std::endl;
    }

    std::cout << "Vector output using iterator for-loop:" << std::endl;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}

