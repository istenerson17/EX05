#ifndef Date_H_
#define Date_H_
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int elapsedtimeSec);
	int getYear();
	int getMonth();
	int getDay();
	int setDate(int elapsetime);
};
#endif