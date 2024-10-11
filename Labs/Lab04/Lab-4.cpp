#include <iostream>
#include <string>

using namespace std;


// ***** Add your Date class definition and driver program at the end of this file
// (at about line 107). *****

// The Month class provided below is a "helper" class for your Date class.
// Note that although both classes are defined in this single compilation unit (file),
// we are not nesting the Month class in the Date class or vice versa.

class Date;

class Month {
	friend class Date;
    friend ostream& operator<<(ostream& out, const Date& date);
	friend ostream& operator<< (ostream& out, const Month& m);

private:
	enum EMonth { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

	Month() : _month(Jan) {} // default constructor
	Month(int im) {
        if (im < 1 || im > 12) {
            throw invalid_argument("Month must be between 1 and 12.");
        }
        _month = (static_cast<EMonth>(im));
    }

	void setMonth(const string& m) { _month = StringToEMonth(m); } // mutator functions
	void setMonth(int im) {
        if (im < 1 || im > 12) {
            throw invalid_argument("Month must be between 1 and 12.");
        }
        _month = static_cast<EMonth>(im); 
    }

	/* Private helper member functions */
	static EMonth StringToEMonth(const string& m);
	int MonthToInt() const { return static_cast<int>(_month); }
	string MonthToString() const;
	string MonthToString2() const;

	EMonth _month;
};

/* Definitions of helper member functions for class Month */

Month::EMonth Month::StringToEMonth(const string& m) {
	if (m == "Jan") return Jan;
	else if (m == "Feb") return Feb;
	else if (m == "Mar") return Mar;
	else if (m == "Apr") return Apr;
	else if (m == "May") return May;
	else if (m == "Jun") return Jun;
	else if (m == "Jul") return Jul;
	else if (m == "Aug") return Aug;
	else if (m == "Sep") return Sep;
	else if (m == "Oct") return Oct;
	else if (m == "Nov") return Nov;
	else if (m == "Dec") return Dec;
	else {
        throw invalid_argument("Invalid month string: " + m);
		/*cerr << "Month::StringToMonth: Invalid input month \"" << m << "\"\n";
		exit(1);*/
	}
}

string Month::MonthToString() const {
	switch (_month) {
	case Jan: return "Jan";
	case Feb: return "Feb";
	case Mar: return "Mar";
	case Apr: return "Apr";
	case May: return "May";
	case Jun: return "Jun";
	case Jul: return "Jul";
	case Aug: return "Aug";
	case Sep: return "Sep";
	case Oct: return "Oct";
	case Nov: return "Nov";
	case Dec: return "Dec";
	default:
		cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
		exit(1);
	}
}

string Month::MonthToString2() const {
	switch (_month) {
	case Jan: return "January";
	case Feb: return "February";
	case Mar: return "March";
	case Apr: return "April";
	case May: return "May";
	case Jun: return "June";
	case Jul: return "July";
	case Aug: return "August";
	case Sep: return "September";
	case Oct: return "October";
	case Nov: return "November";
	case Dec: return "December";
	default:
		cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
		exit(1);
	}
}

/* Definition of friend function operator<< */

ostream& operator<< (ostream& out, const Month& m) {
	out << m.MonthToString2();
	return out;
}


// ***** Add your Date class definition and driver program below. *****

class Date {
    friend class Month;

public:
    Date() : month(1), dayOfMonth(1), year(2018) {}

    Date(int m, int day = 1, int y = 2018) : month(m), dayOfMonth(day), year(y) {
        validateDate();
    }

    Date(string m, int day = 1, int y = 2018) : month(), dayOfMonth(day), year(y) {
        month.setMonth(m);
        validateDate();
    }

    void setMonth(int m) {
        month.setMonth(m);
    }

	void outputDateAsInt(ostream& out);
	void outputDateAsString(ostream& out);

    // returns the address of the ostream that prints the date
	friend ostream& operator<<(ostream& out, const Date& date); // friend function; overloaded cout

    // returns the address of the date object that has been modified, so it can be called again w/ the changes
    Date& operator++();

private:
	Month month;
	int dayOfMonth;
	int year;

    void validateDate();
};

void Date::outputDateAsInt(ostream& out) {
    out << month.MonthToInt() << '/' << dayOfMonth << '/' << year;
}

void Date::outputDateAsString(ostream& out) {
    out << month.MonthToString() << ' ' << dayOfMonth << ", " << year;
}

ostream& operator<<(ostream& out, const Date& date) {
    out << date.month.MonthToString2() << ' ' << date.dayOfMonth << ", " << date.year;
    return out;
}

// "this" is the pointer of the object that the member function was called on. Thus, we have to dereference it, and return it since "this" is type Date*
// we return to Date& because it returns a reference to the original object we called on
// A function with a datatype w/ & means a function that operates on an existing object, so it returns the reference of the existing object
Date& Date::operator++() {
    ++year;
    return *this;
}



void Date::validateDate() {
    int monthInt = month.MonthToInt();
    if (dayOfMonth > 31 || dayOfMonth < 1) {
        throw std::invalid_argument("Invalid day for the given month.");
    }
    if (year < 0) {
        throw std::invalid_argument("Invalid year.");
    }
    if (monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) {
        if (dayOfMonth > 30) {
            throw std::invalid_argument("Invalid day for the given month.");
        }
    } 
    else if (monthInt == 2) {
        if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) {
            if (dayOfMonth > 29) {
                throw std::invalid_argument("Invalid day for the given month.");
            }
        } else {
            if (dayOfMonth > 28) {
                throw std::invalid_argument("Invalid day for the given month.");
            }
        }
    } 
    else {
        if (dayOfMonth > 31) {
            throw std::invalid_argument("Invalid day for the given month.");
        }
    }
}

// ..... 


int main(int argc, char* argv[]) {
    try {
	    Date d1, d2(2, 1, 2018), d3("Mar", 1, 2018);

	    cout << "With the following declarations using operator<<\n";
    
	    cout << "d1 == " << d1 << endl;
	    cout << "d2 == " << d2 << endl;
	    cout << "d3 == " << d3 << endl;

	    d3.setMonth(4);
	    cout << "\nAfter d3.setMonth(4):\n";
	    cout << "d3 == " << d3 << endl;


	    Date d4(12, 31, 2018);
	    cout << "\nd4.outputDateAsInt(cout) outputs ";
	    d4.outputDateAsInt(cout);
	    cout << endl;

	    cout << "d4.outputDateAsString(cout) outputs ";
	    d4.outputDateAsString(cout);
	    cout << endl;

	    ++d4;
	    cout << "\n++d4 == " << d4 << endl;
    } catch (const invalid_argument& error) {
        cout << "\nError: " << error.what() << endl;
    }

	return 0;


}
