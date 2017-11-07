#include <iostream>
#include "queue.h"
#include <cassert>

using namespace std;

int main()
{
    Queue queue;
    assert(queue.isEmpty()&&queue.size()==0);
    queue.push(Buy(Time(22, 11, 13), Date(11,10,2017), 32));
    assert(!queue.isEmpty()&&queue.size()==1);
    queue.push(Buy(Time(2, 1, 3), Date(17,9,2015), 332));
    queue.push(Buy(Time(11, 21, 23), Date(25,9,2014), 104));
    queue.push(Buy(Time(12, 9, 11), Date(8,2,2001), 97));
    queue.push(Buy(Time(21, 21, 0), Date(1,8,2002), 621));
    assert(queue.front()->getPrice() == 32);
    assert(queue.countMoney(Date(24,9,2014), Time(0,0,0), Date(18,9,2015), Time(0,0,1))==332+104);
    assert(queue.pop().getPrice()==32);
    assert(queue.size()==4&&queue.front()->getPrice()==332);
    Queue copy = queue;
    assert(queue.size()==copy.size()&&queue.front()->getPrice()==copy.front()->getPrice());
    return 0;
}

