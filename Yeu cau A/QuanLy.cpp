#ifndef QUANLY_CPP
#define QUANLY_CPP
#include <bits/stdc++.h>
#include <windows.h>
#include "Car.cpp"
using namespace std;

int cmp(Car car1, Car car2) {
        return car1.getName() < car2.getName();  
}

class QuanLy {
private:
    int num;
    vector<Car> cars;
public:
    QuanLy() : num(0) {}
    void input() {
        ifstream fi("input.inp");
        fi >> num; fi.ignore();
        for(int i=0; i<num; i++) {
            int soLuong;
            string name, automaker, color;
            double price;
            fi >> soLuong;
            fi.ignore();
            getline(fi, name);
            getline(fi, automaker);
            getline(fi, color);
            fi >> price; fi.ignore();
            Car b(soLuong, name, automaker, color, price);
            if(i > 0) {
                bool check = false;
                int l=0, r=i, mid;
                while(l < r) {
                    mid = (l+r)/2;
                    if(cars[mid] == b) {
                        cars[mid].setSoluong(cars[mid].getSoluong()+b.getSoluong());
                        check = true;
                        break;
                    } else if(cars[mid].getPrice() < b.getPrice()) {
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                }
                if(!check){
                    cars.push_back(b);
                }
            } else {
                cars.push_back(b);
            }
        }
    }

    void font() {
        cout << setfill('-');		
        cout << setw(100) << "-" << endl;
        cout << setfill(' ');                       
        cout << "|";
        cout << left << setw(5) << "ID";
        cout << "|";
        cout << left << setw(25) << "Name";
        cout << "|";
        cout << left << setw(25) << "Automaker";
        cout << "|";
        cout << left << setw(15) << "Color";
        cout << "|";
        cout << left << setw(15) << "Price";
        cout << "|";
        cout << left << setw(9) << "So luong";
        cout << "|" << endl;
        cout << setfill('-');		
        cout << setw(100) << "-" << endl;
        cout << setfill(' ');
    }

    void output() {
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        font();
        for(int i=0; i<cars.size(); i++) {
            cout << "|";
            cout << left << setw(5) << i+1;
            cout << cars[i];

            cout << setfill('-');		
	        cout << setw(100) << "-" << endl;
            cout << setfill(' ');
        }
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    void sortCar() {
        sort(cars.begin(), cars.end(), cmp);
    }

    void add() {
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        bool check = false;
        Car b; cin >> b;
        int l=0, r=num-1, mid;
        while(l < r) {
            mid = (l+r)/2;
            if(cars[mid] == b) {
                cars[mid].setSoluong(cars[mid].getSoluong()+b.getSoluong());
                check = true;
                break;
            } else if(cars[mid].getPrice() < b.getPrice()) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        if(!check){
            cars.push_back(b);
        }
        sortCar();
        num++;
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    void erase1() {
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\nNhap vao thu tu cua chiec xe muon xoa: ";
        int pos; cin >> pos;
        cars.erase(cars.begin() + pos-1);
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    void modify() {
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        if(num == 0) { 
            cout << "Khong co chiec xe nao trong garage!!";
            return;
        }
        int pos;
        do {
            cout << "Nhap vao so thu tu cua chiec xe muon sua: ";
            cin >> pos;
            if(pos < 1 && pos > num) {
                cout << "So thu tu khong dung, xin moi nhap lai: ";
                continue;
            }
            cout << "Xin moi sua thong tin (thong tin nao khong muon sua thi nhap -1)\n";
            int soLuong;
            cout << "Nhap vao so luong: ";
            cin >> soLuong;
            string name, autom, color;
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "Automaker: ";
            getline(cin, autom);
            cout << "Color: ";
            getline(cin, color);
            double price;
            cout << "Price: ";
            cin >> price;
            if(soLuong != -1) cars[pos-1].setSoluong(soLuong);
            if(name != "-1") cars[pos-1].setName(name);
            if(autom != "-1") cars[pos-1].setAutomaker(autom);
            if(color != "-1") cars[pos-1].setcolor(color);
            if(price != -1) cars[pos-1].setPrice(price);
            break;
        } while(1);
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    void find() {
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n" << "Enter the car you want search for: \n";
        string name, automaker, color;
        double price;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Automaker: ";
        cin.ignore('\n'-1e9);
        getline(cin, automaker);
        cout << "Color: ";
        cin.ignore('\n'-1e9);
        getline(cin, color);
        cout << "Price: ";
        cin >> price;
        Car a(0, name, automaker, color, price);

        bool check = false;
        for(int i=0; i<cars.size(); i++) {
            if(cars[i] == a) {
                check = true; break;
            }
        }
        if(check == true) {
            font();
            for(int i=0; i<cars.size(); i++) {
                if(cars[i] == a) {
                    cout << "|";
                    cout << left << setw(5) << i+1;
                    cout << cars[i];
                }
            }
            cout << setfill('-');		
            cout << setw(100) << "-" << endl;
            cout << setfill(' ');
        } else cout << "Not found!";
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    void findPrice() {
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n" << "Enter the price: \n";
        double price; cin >> price;
        bool check = false;
        for(int i=0; i<cars.size(); i++) {
            if(cars[i].getPrice() == price) {
                check = true; break;
            }
        }
        if(check == true) {
            font();
            for(int i=0; i<cars.size(); i++) {
                if(cars[i].getPrice() == price) {
                    cout << "|";
                    cout << left << setw(5) << i+1;
                    cout << cars[i];
                }
            }
            cout << setfill('-');		
            cout << setw(100) << "-" << endl;
            cout << setfill(' ');
        } else cout << "Not found!";
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    void findName() {
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n" << "Enter the name: \n";
        string name; cin >> name;
        bool check = false;
        for(int i=0; i<cars.size(); i++) {
            if(cars[i].getName() == name) {
                check = true; break;
            }
        }
        if(check == true) {
            font();
            for(int i=0; i<cars.size(); i++) {
                if(cars[i].getName() == name) {
                    cout << "|";
                    cout << left << setw(5) << i+1;
                    cout << cars[i];
                }
            }
            cout << setfill('-');		
            cout << setw(100) << "-" << endl;
            cout << setfill(' ');
        } else cout << "Not found!";
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    void findColor() {
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n" << "Enter the color: \n";
        string color; cin >> color;
        bool check = false;
        for(int i=0; i<cars.size(); i++) {
            if(cars[i].getColor() == color) {
                check = true; break;
            }
        }
        if(check == true) {
            font();
            for(int i=0; i<cars.size(); i++) {
                if(cars[i].getColor() == color) {
                    cout << "|";
                    cout << left << setw(5) << i+1;
                    cout << cars[i];
                }
            }
            cout << setfill('-');		
            cout << setw(100) << "-" << endl;
            cout << setfill(' ');
        } else cout << "Not found!";
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    void findAutomaker() {
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n" << "Enter the automaker: \n";
        string autom; cin >> autom;
        bool check = false;
        for(int i=0; i<cars.size(); i++) {
            if(cars[i].getAutomaker() == autom) {
                check = true; break;
            }
        }
        if(check == true) {
            font();
            for(int i=0; i<cars.size(); i++) {
                if(cars[i].getAutomaker() == autom) {
                    cout << "|";
                    cout << left << setw(5) << i+1;
                    cout << cars[i];
                }
            }
            cout << setfill('-');		
            cout << setw(100) << "-" << endl;
            cout << setfill(' ');
        } else cout << "Not found!";
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    void maxPrice() {
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        double max = -1e9;
        for(int i=0; i<cars.size(); i++) {
            if(cars[i].getPrice() > max) max = cars[i].getPrice();
        }
        font();
        for(int i=0; i<cars.size(); i++) {
            if(cars[i].getPrice() == max) {
                cout << "|";
                cout << left << setw(5) << i+1;
                cout << cars[i];
            }
        }
        cout << setfill('-');		
	    cout << setw(100) << "-" << endl;
        cout << setfill(' ');
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    void minPrice() {
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        double min = 1e9;
        for(int i=0; i<cars.size(); i++) {
            if(cars[i].getPrice() < min) min = cars[i].getPrice();
        }
        font();
        for(int i=0; i<cars.size(); i++) {
            if(cars[i].getPrice() == min) {
                cout << "|";
                cout << left << setw(5) << i+1;
                cout << cars[i];
            }
        }
        cout << setfill('-');		
	    cout << setw(100) << "-" << endl;
        cout << setfill(' ');
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
};

#endif