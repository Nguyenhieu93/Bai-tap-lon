#ifndef CAR_CPP
#define CAR_CPP
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void setColor(int color) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, color);
}

string Lower(string s) {
    transform(s.begin(), s.end(), s.begin(), :: tolower);
    return s;
}

class Car {
private:
    string name;
    string automaker;
    string color;
    double price;
    int soLuong;
public:
    Car() {}
    Car(int soLuong, string name, string automaker, string color, double price) {
        this->soLuong=soLuong;
        this->name=name;
        this->automaker=automaker;
        this->color=color;
        this->price=price;
    }
    string getName() {return name;}
    string getAutomaker() {return automaker;}
    string getColor() {return color;}
    double getPrice() {return price;}
    int getSoluong() {return soLuong;}
    void setName(string name) {this->name = name;}
    void setAutomaker(string automaker) {this->automaker = automaker;}
    void setcolor(string color) {this->color = color;}
    void setPrice(double price) {this->price = price;}
    void setSoluong(int n) {this->soLuong=n;}

    friend istream& operator>>(istream& is, Car& car) {
        cout << "Enter the car information: " << endl;
        cout << "Nhap vao so luong: ";
        is >> car.soLuong;
        cout << "Name: ";
        is.ignore();
        getline(is, car.name);
        cout << "Automaker: ";
        is.ignore('\n'-1e9);
        getline(is, car.automaker);
        cout << "Color: ";
        is.ignore('\n'-1e9);
        getline(is, car.color);
        cout << "Price: ";
        is >> car.price;
        return is;
    }
    friend ostream& operator<<(ostream& os, Car& car) {
        cout << "|";
        os << left << setw(25) << car.name;
        cout << "|";
        os << left << setw(25) << car.automaker;
        cout << "|";
        os << left << setw(15) << car.color;
        cout << "|";
        os << left << setw(15) << fixed << setprecision(1) << car.price;
        cout << "|";
        os << right << setw(9) << car.soLuong;
        os <<  "|" << endl;
        return os;
    }

    bool operator==(const Car& other) const {
        return (Lower(name) == Lower(other.name) && Lower(automaker) == Lower(other.automaker) 
                    && Lower(color) == Lower(other.color) && price == other.price);
    }
};

#endif
