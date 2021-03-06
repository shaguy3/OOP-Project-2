#include <iostream>
#include <fstream>

#define rcastcc reinterpret_cast<const char*>
#define rcastc reinterpret_cast<char*>
using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(int _day, int _month, int _year);
    int getDay();
    int getMonth();
    int getYear();
    bool setDay(int _day);
    bool setMonth(int _month);
    bool setYear(int _year);
    friend ostream& operator<<(ostream& os, const Date& date);
    ~Date();
    
    /*Serialization*/

    void save(ostream& out) const;
    void load(istream& in);
};