#include "User.h"
#include <cmath>
#include <cstring>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::left;
using std::setw;

fstream inout;

//input date
void printDate(Date Date)
{
    cout << left;
    cout << Date.getYear() << "/" << Date.getMonth() << '/' << Date.getDay() << "-" << Date.getHour() << "h";
}

//input menu
void printMenu(Menu m)
{
    cout << left;
    cout << setw(20) << m.getDishId() << setw(20) << m.getDishName() << setw(20) << m.getPrice() << endl;
}

//input order
void printOrder(Order myOrder)
{
    cout<<left;
	cout<<setw(7)<<myOrder.getDishId()<<setw(10)<<myOrder.getDishName()<<setw(6)<<myOrder.getPrice()<<setw(4)<<myOrder.getNum();
	cout<<setw(8)<<myOrder.getCustomerName()<<setw(8)<<myOrder.getPhone()<<setw(12)<<myOrder.getAdress();
	cout<<" ";printDate(myOrder.getBookDate());cout<<"  ";
	if(myOrder.getModify())
	{
		cout<<setw(10)<<"New"<<endl;
	}
	else cout<<setw(10)<<"Approved"<<endl;
}

//用于将menu write file
void outputMenu(Menu &iMenu)
{
    inout << iMenu.getDishId() << " " << iMenu.getDishName() << " " << iMenu.getPrice() << endl;
}

//用于将订单写入文件
void outputOrder(Order &iOrder)
{
    Date date = iOrder.getBookDate();
	int modify = iOrder.getModify()? 1:0;
	inout<<iOrder.getDishId()<<' '<<iOrder.getDishName()<<' '<<iOrder.getPrice()<<' '<<iOrder.getNum()<<endl;
	inout<<iOrder.getCustomerName()<<' '<<iOrder.getAdress()<<' '<<iOrder.getPhone()<<endl;
	inout<<date.getYear()<<' '<<date.getMonth()<<' '<<date.getDay()<<' '<<date.getHour()<<' '<<modify<<endl;
}

Seller::Seller()
{
    password = "888888";
}

void Seller::modifyOrder(vector<Order> &order)
{
    int *pos = new int[order.size() + 1], count = 0;
    memset(pos, 0, sizeof(pos));
    for (int i = 0;i<order.size()++i)
    {
        if(order[i].getModify())
        {
            count++;
            pos[i] = 1;
        }
    }

    if(count==0)
    {
        cout << endl
              << "All order hava been approved!" << endl;
        return;
    }
    cout << left;
    cout << endl
         << "Here is the  order you haven't approve:" << endl;
    cout<<endl<<setw(7)<<"DishID"<<setw(10)<<"DishName"<<setw(6)<<"price"<<setw(4)<<"num"<<setw(8)<<"Name";
	cout<<setw(8)<<"Phone"<<setw(12)<<"Address"<<setw(15)<<"Date"<<setw(10)<<"state"<<endl;
	count = 0;
    for (int i = 0; i < order.size();++i)
    {
        if(pos[i]&&order[i].getModify())
        {
            count++;
            cout << "count=" << count << endl;
            printOrder(order[i]);
        }
    }
    cout << std::right;
	cout<<endl<<setw(20)<<"1.Aprove all"<<setw(25)<<"2.Aprove one by one"<<setw(20)<<"3.return"<<endl;
    string n;
    while (cin>>n)
    {
        if(n=="1"||n=="2"||n=="3")
            break;
        else{
            cout<<endl<<"Invalid input!"<<endl;
	        cout<<endl<<setw(20)<<"1.Aprove all"<<setw(25)<<"2.Aprove one by one"<<setw(20)<<"3.return"<<endl;
		}
    } 
    if(n=="3")
        return;
    if(n=="1")
    {
        for (int i = 0; i < order.size();++i)
            if(pos[i])
                order[i].setModify();
    }
    else
    {
        cout << std::right;
		cout<<endl<<setw(30)<<"1.Continue"<<setw(20)<<"2.return"<<endl;
        int k, m;
        while(cin>>m)
        {
            if(m==2)
                return;
            if(m!=1)
            {
                cout << endl
                     << "Invalid input" << endl;
                return;
            }
            cout << "Please input the nuber if irder";
            cin >> m;
            if(m>count)
            {
                cout << endl
                     << "There is only" << count << "order" << endl;
                cout << endl
                     << "Plese input again!" << endl;
            }
            else if(m<=0)
            {
                cout << endl
                     << "There number must be positive !" << endl;
                cout << endl
                     << "Please input again!" << endl;
            }
            else
            {
                k = 0;
				for(int i=0;i<order.size();++i)
				{
					if(pos[i])
					{
						k++;
						if(k == m)
						{
							order[i].setModify();
							cout<<endl<<"The order have approved!"<<endl;
						}
					}
				}
            }
            cout << std::right;
			cout<<endl<<setw(30)<<"1.Continue"<<setw(20)<<"2.return"<<endl;
            
        }
    }
    inout.open("order.txt", std::ios::out);
    if (inout.fail())
    {
        cout << endl
             << "The system can't find the file !" << endl;
        return;
    }
    for (int i = 0; i < order.size(); ++i)
        outputOrder(order[i]);
    inout.close();
}

void Seller::inquireOrder(vector<Order> &order)
{
    if(order.size()==0)
    {
        cout << endl
             << "There is no any order !" << endl;
        return;
    }
    cout << left;
    cout << endl
         << "Here is the order :" << endl;
    cout<<endl<<setw(7)<<"DishID"<<setw(10)<<"DishName"<<
        setw(6)<<"price"<<setw(4)<<"num"<<setw(8)<<"Name";
	cout<<setw(8)<<"Phone"<<setw(12)<<"Address"<<setw(15)<<"Date"<<setw(10)<<"state"<<endl;
    for (int i = 0; i < order.size();++i)
    {
        printOrder(order[i]);
    }
    return;
}

void Seller::appendMenu(vector<Menu> &myMenu)
{
    cout << endl
         << "Do you want to append Menu?  Y/N" << endl;
    string ch;
    int k = myMenu.size();
    while(cin>>ch)
    {
        if(ch!="Y"&&ch!="y")
            break;
        cout << endl
             << "please input the dish name:";
        string str;
        Menu iMenu;
        double d;
        cin >> str;
        iMenu.setDishName(str);
        cout << endl
             << "Please input the dish ID :";
        cin >> str;
        iMenu.setDishID(str);
        cout << endl
             << "Please input the price of the dish:";
        cin >> d;
        iMenu.setPrice(d);
        myMenu.push_back(iMenu);
        cout << endl
             << "The dish hava been added to the menu!" << endl;
        cout << endl
             << "Do you want to contine to append Menu ? Y/N" << endl;
    }
    inout.open("menu.txt",std::ios::app);
    if(inout.fail())
    {
        cout << endl
             << "The system can't find the file !" << endl;
        return;
    }
    for (int i = k; i < myMenu.size();++i)
        outputMenu(myMenu[i]);
    inout.close();
    return;
}

void Seller::cancelMenu(vector<Menu> &myMenu)
{
    cout << endl
         << "Do you want to cancel Menu? Y/N" << endl;
    string str;
    string ch;
    Menu iMenu;
    vector<Menu>::iterator it = myMenu.begin();
    while (cin>>ch)
    {
        it = myMenu.begin();
        if(ch =="N"||ch=="n")
            break;
        if(ch!="Y"||ch!="y")
        {
            cout << endl
                 << "Invalid input Please input again!" << endl;
            cout << endl
                 << "D0 you want to cancel Menu? Y/N" << endl;
            continue;
        }
        cout << left;
        cout << endl
             << "Here is the Menu;" << endl;
        cout << endl
             << "       " << setw(20) << "DishID" << setw(20) << setw(20) << "Price" << endl;
        for (int i = 0; i < myMenu.size();++i)
        {
            cout << "        ";
            printMenu(myMenu[i]);
        }
        cout << endl
             << "Please input the dish ID you want cancel :";
        cin >> str;
        for (int i = 0; i < myMenu.size();++i)
        {
            if(myMenu[i].getDishId()==str)
            {
                myMenu.erase(it + i);
                cout << endl
                     << "The dish hava been canceled!" << endl;
                break;
            }
            if(i==myMenu.size()-1)
                cout << endl
                     << "There is no such dish! Please input again!" << endl;
        }
        cout << endl
             << "Do youo want to contineue to cnacel Menu? Y/N" << endl;
            
    }
    inout.open("menu.txt", std::ios::out);
    if(inout.fail())
    {
        cout << endl
             << "The system can't find the file !" << endl;
        return;
    }
    for (int i = 0; i < myMenu.size();++i)
        outputMenu(myMenu[i]);
    inout.close();
}

void Seller::setPassword(string p)
{
    password = p;
}

string Seller::getPassword()
{
    return string(password);
}

Buyer::Buyer()
{
}

void Buyer::bookOrder(vector<Menu> &, vector<Order> &)
{
}

void Buyer::modifyOrder(vector<Order> &)
{
}

void Buyer::inquirOrder(vector<Order> &)
{
}

int Buyer::getNum()
{
    return 0;
}

string Buyer::getName()
{
    return string();
}

void Buyer::setNum(int)
{
}
