#include "queue.h"

Queue::Queue()
{
    first = NULL;
    sizeOf = 0;
}

Queue::Queue(const Queue &a)
{
    first = NULL;
    sizeOf = 0;
    Node* temp = a.first;
    while(temp)
    {
        push(temp->data);
        temp = temp->next;
    }
}

int Queue::size()
{
    return sizeOf;
}

bool Queue::isEmpty()
{
    if(sizeOf==0) return true;
    else return false;
}

void Queue::push(Buy _data)
{
    if(!first)
    {
        first = new Node;
        first->data = _data;
        last = first;
    }
    else
    {
        Node *temp = new Node;
        temp->data = _data;
        last->next = temp;
        last = temp;
    }
    sizeOf+=1;
}

Buy Queue::pop()
{
    if(first)
    {
        Buy ret = first->data;
        Node *temp = first;
        first = first->next;
        delete temp;
        sizeOf-=1;
        return ret;
    }
}

void Queue::show()
{
    Node *temp = first;
    while(temp) temp->data.show(), temp = temp->next;
}

void Queue::save(QString f_name)
{
    QFile file;
    file.setFileName(f_name);
    file.open(QIODevice::WriteOnly);
    QDataStream stream(&file);
    for(Node* temp = first; temp; temp=temp->next)
    {
        stream<<QString::number(temp->data.getDate().day)+"/"+QString::number(temp->data.getDate().month)+"/"+QString::number(temp->data.getDate().year)
        <<QString::number(temp->data.getTime().hours)+":"+QString::number(temp->data.getTime().minutes)+":"+QString::number(temp->data.getTime().seconds)
        <<QString::number(temp->data.getPrice());
    }
    file.close();
}

void Queue::load(QString f_name)
{
    QFile file;
    file.setFileName(f_name);
    file.open(QIODevice::ReadOnly);
    QDataStream stream(&file);
    while(!file.atEnd())
    {
        QString _date;
        QString _time;
        QString _price;
        stream>>_date>>_time>>_price;
        QStringList _d = _date.split("/");
        QStringList _t = _time.split(":");
        push(Buy(Time(_t.at(0).toInt(),_t.at(1).toInt(),_t.at(2).toInt()),Date(_d.at(0).toInt(),_d.at(1).toInt(),_d.at(2).toInt()), _price.toInt()));
    }
    file.close();
}

Buy* Queue::front()
{
    return &(first->data);
}

int Queue::countMoney(Date date1, Time time1, Date date2, Time time2)
{
    Node *temp = first;
    int result = 0;

    //С помощью коэффициентов дата представляется в виде одного числа, чтобы не делать много сравнений
    int date_low_bound = date1.year*10000+date1.month*100+date1.day;
    int date_high_bound = date2.year*10000+date2.month*100+date2.day;
    int time_low_bound = time1.hours*10000+time1.minutes*100+time1.seconds;
    int time_high_bound = time2.hours*10000+time2.minutes*100+time2.seconds;
    while(temp)
    {
        int date_curr = temp->data.getDate().year*10000+temp->data.getDate().month*100+temp->data.getDate().day;
        int time_curr = temp->data.getTime().hours*10000+temp->data.getTime().minutes*100+temp->data.getTime().seconds;
        if(date_curr>date_low_bound&&date_curr<date_high_bound) result+=temp->data.getPrice();
          else if(date_curr==date_low_bound && time_curr >= time_low_bound) result+=temp->data.getPrice();
            else if(date_curr==date_high_bound && time_curr <= time_high_bound) result+=temp->data.getPrice();
        temp = temp->next;
    }
    return result;
}

Queue::~Queue()
{
    Node *del = first, *temp = first->next;
    while (temp->next)
    {
        temp=del->next;
        delete del;
        del = temp;
    }
    delete del;
}
