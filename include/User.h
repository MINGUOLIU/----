#include <vector>
#include "Menu.h"

using std::vector;
#ifndef USER_H
#define USER_H
class User{
    private:

    public:
        virtual void modifyOrder(vector<Order> &) = 0;
        virtual void inquireOrder(vector<Order> &) = 0;

};
#endif

#ifndef SELLER_H
#define SELLER_H

class Seller:public User
{
    private:
        string password;
    public:
        Seller();
        void modifyOrder(vector<Order> &);
        void inquireOrder(vector<Order> &);
        void appendMenu(vector<Menu> &);
        void cancelMenu(vector<Menu> &);
        void setPassword(string);
        string getPassword();
};

#endif


#ifndef BUYER_H
#define BUYER_H

class Buyer:public User{
    private:
        vector<Order> myOrder;
        string name, adress, phone;
        Date bookDate;
        int num;
    public:
        Buyer();
        void bookOrder(vector<Menu> &, vector<Order> &);
        void modifyOrder(vector<Order> &);
        void inquirOrder(vector<Order> &);
        int getNum();
        string getName();
        void setNum(int);
};

#endif