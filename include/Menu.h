#include <string>
#include <iostream>
#include <iomanip>

using std::string;
#ifndef DATE_H
#define DATE_H
class Date
{
private:
    int year, month, day, hour;

public:
    Date();
    Date(int y, int m, int d, int h);
    bool operator==(Date date2);
    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    void setHour(int);
};
#endif // !DATE_H

#ifndef MENU_H
#define MENU_H

class Menu
{
protected:
    string dishName, dishID;
    double price;

public:
    Menu();
    Menu(string disName, string disID, double price);
    void setDishName(string);
    void setDishID(string);
    void setPrice(double);
    string getDishName();
    string getDishId();
    double getPrice();
};

#endif

#ifndef ORDER_H
#define ORDER_H

class Order : public Menu
{
private:
    string customerName, adress, phone;
    int num;
    Date bookDate;
    bool modify;

public:
    Order();
    Order(string disName, string dishID, double price, string customerName,string adress, string phone, Date bookDate);
    Order(string dishName,string dishID,double price);
    Order(Menu, int);
    const bool operator==(Order order2);
    string getCustomerName();
    string getAdress();
    string getPhone();
    Date getBookDate();
    bool getModify();
    int getNum();
    bool setCustomerName(string curtomerName);
    bool setAdress(string adress);
    bool setPhone(string phone);
    bool setNum(int num);
    bool setBookData(Date bookDate);
    void setModify();
};

#endif // !ORDER_H
