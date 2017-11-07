#ifndef BUY_H
#define BUY_H
#include <QString>
#include <iostream>

using namespace std;

struct Date
{
    Date (int _day, int _month, int _year) : day(_day), month(_month), year(_year){}
    Date() {}
    int day;
    int month;
    int year;
};

struct Time
{
    Time (int _hours, int _minutes, int _seconds) : hours(_hours), minutes(_minutes), seconds(_seconds){}
    Time () {}
    int hours;
    int minutes;
    int seconds;
};

class Buy
{
public:
    Buy();
    Buy(Time _time, Date _date, int _price);
    Buy(const Buy& a);
    ~Buy();
    Time getTime();
    Date getDate();
    int getPrice();
    void setDate(Date _date);
    void setTime(Time _time);
    void setPrice(int price);
    void show();
private:
    Time time;
    Date date;
    int price;
};

#endif // BUY_H
