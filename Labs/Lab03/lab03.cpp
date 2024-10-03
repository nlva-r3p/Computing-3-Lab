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


}

void mass:: setMassMetricGrams(int grams)
{
	drams = grams * 1.7718451953125;

}

double mass:: getMassMetricGrams() const
{
	return drams;
}