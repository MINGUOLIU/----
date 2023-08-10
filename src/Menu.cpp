#include "Menu.h"
#include <cstring>
Date::Date() : year(2012), month(12), day(12), hour(12){};

Date::Date(int y, int m, int d, int h)
{
    year = y;
    month = m;
    day = d;
    hour = h;
}

bool Date::operator==(Date date2)
{
    if(this->day == date2.day&&this->year==date2.year
        &&this->month==date2.month&&this->hour==date2.hour)
        return true;
    return false;
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

int Date::getHour()
{
    return hour;
}

void Date::setYear(int y)
{
    year = y;
}

void Date::setMonth(int m)
{
    month = m;
}

void Date::setDay(int d)
{
    day = d;
}

void Date::setHour(int h)
{
    hour = h;
}

Menu::Menu()
{
}

Menu::Menu(string disName, string disID, double price)
{
    this->dishName = disName;
    this->dishID = disID;
    this->price = price;
}

void Menu::setDishName(string name)
{
    this->dishName = name;
}

void Menu::setDishID(string ID)
{
    this->dishID = ID;
}

void Menu::setPrice(double price)
{
    this->price = price;
}

string Menu::getDishName()
{
    return dishName;
}

string Menu::getDishId()
{
    return dishID;
}

double Menu::getPrice()
{
    return price;
}

Order::Order()
{
    modify = 1;
}

Order::Order(string disName, string dishID, double price, string customerName, string adress, string phone, Date bookDate)
{
    this->customerName = customerName;
    this->adress = adress;
    this->phone = phone;
    modify = 1;
}

Order::Order(string dishName, string dishID, double price):Menu(dishName,dishID,price)
{
    modify = 1;
}

Order::Order(Menu m, int n) : Menu(m), num(n)
{
    modify = 1;
};

const bool Order::operator==(Order order2)
{   
    if(order2.dishID!=dishID)
        return false;
    if(order2.dishName!=dishName)
        return false;
    if(order2.customerName!=customerName)
        return false;
    if(order2.phone!=phone)
        return false;
    if(order2.adress!=adress)
        return false;
    if(!(order2.bookDate==bookDate))
        return false;
    return true;
}

string Order::getCustomerName()
{
    return customerName;
}

string Order::getAdress()
{
    return adress;
}

string Order::getPhone()
{
    return string(this->phone);
}

Date Order::getBookDate()
{
    return Date(bookDate);
}

bool Order::getModify()
{
    return modify;
}

int Order::getNum()
{
    return num;
}

bool Order::setCustomerName(string curtomerName)
{
    if(!modify)
        return false;
    this->customerName = curtomerName;
    return true;
}

bool Order::setAdress(string adress)
{   
    if(!modify)
        return false;
    this->adress = adress;
    return true;
}

bool Order::setPhone(string phone)
{
    if(!modify)
        return false;
    this->phone = phone;
    return true;
}

bool Order::setNum(int num)
{   
    if(!modify)
        return false;
    this->num = num;
    return true;
}

bool Order::setBookData(Date bookDate)
{
    if(!modify)
        return false;
    this->bookDate = bookDate;
    return true;
}

void Order::setModify()
{
    modify = 0;
}
