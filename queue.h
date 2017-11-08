#ifndef QUEUE_H
#define QUEUE_H

#include "buy.h"
#include <QFile>
#include <QStringList>

struct Node
{
    Node() : next(NULL){}
    Node* next;
    Buy data;
};

class Queue
{
public:
    Queue();
    Queue(const Queue &a);
    ~Queue();
    void push(Buy _data);
    Buy pop();
    Buy* front();
    bool isEmpty();
    int size();
    void save(QString f_name);
    void load(QString f_name);
    void show();
    int countMoney(Date date1, Time time1, Date date2, Time time2);
private:
    Node *first, *last;
    int sizeOf;
};

#endif // QUEUE_H
