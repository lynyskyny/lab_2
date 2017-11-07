#include "buy.h"

Buy::Buy() : price(100)
{
    date.day = 12;
    date.month = 11;
    date.year = 2000;

    time.hours = 22;
    time.minutes = 11;
    time.seconds = 34;
}

Buy::Buy(Time _time, Date _date, int _price)
{
    date.day = _date.day>0 && _date.day<32 ? _date.day : Buy().date.day;
    date.month = _date.month>0 && _date.month<13 ? _date.month : Buy().date.month;
    date.year =_date.year>1990 && _date.year<2018 ? _date.year : Buy().date.year;

    time.hours = _time.hours>=0 && _time.hours<24 ? _time.hours : Buy().time.hours;
    time.minutes = _time.minutes>=0 && _time.hours<60 ? _time.minutes : Buy().time.minutes;
    time.seconds = _time.seconds>=0 && _time.seconds<60 ? _time.seconds : Buy().time.seconds;

    price = _price>0 ? _price : Buy().price;
}

Buy::Buy(const Buy &a) : date(a.date), time(a.time), price(a.price) { }

Buy::~Buy() { }

Date Buy::getDate()
{
    return date;
}

Time Buy::getTime()
{
    return time;
}

int Buy::getPrice()
{
    return price;
}

void Buy::setDate(Date _date)
{
    date.day = _date.day>0 && _date.day<32 ? _date.day : date.day;
    date.month = _date.month>0 && _date.month<13 ? _date.month : date.month;
    date.year =_date.year>1990 && _date.year<2018 ? _date.year : date.year;
}

void Buy::setTime(Time _time)
{
    time.hours = _time.hours>=0 && _time.hours<24 ? _time.hours : time.hours;
    time.minutes = _time.minutes>=0 && _time.hours<60 ? _time.minutes : time.minutes;
    time.seconds = _time.seconds>=0 && _time.seconds<60 ? _time.seconds : time.seconds;
}

void Buy::show()
{
    cout<<"Date: "<<date.day<<"/"<<date.month<<"/"<<date.year<<endl;
    cout<<"Time: "<<time.hours<<":"<<time.minutes<<":"<<time.seconds<<endl;
    cout<<"Price: "<<getPrice()<<endl<<endl;
}
