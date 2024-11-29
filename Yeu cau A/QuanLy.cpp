#ifndef QUANLY_CPP
#define QUANLY_CPP
#include <bits/stdc++.h>
#include <windows.h>
#include "Car.cpp"
using namespace std;

int cmp(Car car1, Car car2) {
        return car1.getPrice() < car2.getPrice();  
}

class QuanLy {
private:
    vector<Car> cars;
public:
    QuanLy() {}
    void input();
    void font();
    void output();
    void sortCar();
    void add();
    void erase1();
    void modify();
    void find();
    void findPrice();
    void findName();
    void findColor();
    void findAutomaker();
    void maxPrice();
    void minPrice();
};

void QuanLy::input() {
    int num;
    ifstream fi("input.inp");
    fi >> num; fi.ignore();
    bool check = false;
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
        check = false;
        if(i>0) {
            for(int j=0; j<cars.size(); j++) {
                if(cars[j] == b) {
                    cars[j].setSoluong(cars[j].getSoluong()+b.getSoluong());
                    check = true;
                }else {
                    continue;
                }
            }
            if(check == false) cars.push_back(b);
        } else {
            cars.push_back(b);
        }
    }
    fi.close();
}

void QuanLy::font() {
    cout << setfill('-');		
    cout << setw(100) << "-" << endl;
    cout << setfill(' ');                       
    cout << "|";
    cout << left << setw(5) << "STT";
    cout << "|";
    cout << left << setw(25) << "Ten";
    cout << "|";
    cout << left << setw(25) << "Hang xe";
    cout << "|";
    cout << left << setw(15) << "Mau sac";
    cout << "|";
    cout << left << setw(15) << "Gia ban";
    cout << "|";
    cout << left << setw(9) << "So luong";
    cout << "|" << endl;
    cout << setfill('-');		
    cout << setw(100) << "-" << endl;
    cout << setfill(' ');
}

void QuanLy::output() {
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

void QuanLy::sortCar() {
    sort(cars.begin(), cars.end(), cmp);
}

void QuanLy::add() {
    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    bool check = false;
    Car b; cin >> b;
    for(int i=0; i<cars.size(); i++) {
        if(cars[i] == b) {
            cars[i].setSoluong(cars[i].getSoluong()+b.getSoluong());
            check = true;
            break;
        }
    }
    if(!check){
        cars.push_back(b);
    }
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void QuanLy::erase1() {
    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\nNhap vao thu tu cua chiec xe muon xoa: " << endl;
    int pos; cin >> pos;
    cout << "Ban muon xoa bao nhieu chiec xe nay: ";
    int cnt;
    do {
        cin >> cnt;
        if(cnt > cars[pos-1].getSoluong() || cnt < 0) {
            cout << "Khong hop le, xin moi nhap lai: ";
            continue;
        }else {
            break;
        }
    }while(1);
    if(cnt == cars[pos-1].getSoluong()) {
        cars.erase(cars.begin() + pos-1);  
    } else {
        cars[pos-1].setSoluong(cars[pos-1].getSoluong()-cnt);
    }
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void QuanLy::modify() {
    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    if(cars.size() == 0) { 
        cout << "Khong co chiec xe nao trong garage!!";
        return;
    }
    int pos;
    do {
        cout << "Nhap vao so thu tu cua chiec xe muon sua: ";
        cin >> pos;
        if(pos < 1 && pos > cars.size()) {
            cout << "So thu tu khong dung, xin moi nhap lai: ";
            continue;
        }
        cout << "Xin moi sua thong tin (thong tin nao khong muon sua thi nhap -1)\n";
        int soLuong;
        cout << "Nhap vao so luong: ";
        cin >> soLuong;
        string name, autom, color;
        cin.ignore();
        cout << "Ten: ";
        getline(cin, name);
        cout << "Hang xe: ";
        getline(cin, autom);
        cout << "Mau sac: ";
        getline(cin, color);
        double price;
        cout << "Gia ban: ";
        cin >> price;
        if(soLuong != -1) cars[pos-1].setSoluong(soLuong);
        if(name != "-1") cars[pos-1].setName(name);
        if(autom != "-1") cars[pos-1].setAutomaker(autom);
        if(color != "-1") cars[pos-1].setcolor(color);
        if(price != -1) cars[pos-1].setPrice(price);
        for(int i=0; i<cars.size(); i++) {
            if(cars[i]==cars[pos-1] && i != pos-1) {
                cars[i].setSoluong(cars[i].getSoluong()+cars[pos-1].getSoluong());
                cars.erase(cars.begin() + pos-1);
                break;
            }
        }
        break;
    } while(1);
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void QuanLy::find() {
    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n" << "Nhap vao chiec xe ma ban muon tim kiem \n";
    string name, automaker, color;
    double price;
    cout << "Ten: ";
    cin.ignore();
    getline(cin, name);
    cout << "Hang xe: ";
    cin.ignore('\n'-1e9);
    getline(cin, automaker);
    cout << "Mau xe: ";
    cin.ignore('\n'-1e9);
    getline(cin, color);
    cout << "Gia: ";
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
    } else cout << "Khong tim thay!";
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void QuanLy::findPrice() {
    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n" << "Nhap vao gia muon tim kiem: \n";
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
    } else cout << "Khong tim thay!";
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void QuanLy::findName() {
    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n" << "Nhap vao ten chiec xe muon tim kiem: \n";
    cin.ignore();
    string name; getline(cin, name);
    bool check = false;
    for(int i=0; i<cars.size(); i++) {
        if(Lower(cars[i].getName()) == Lower(name)) {
            check = true; break;
        }
    }
    if(check == true) {
        font();
        for(int i=0; i<cars.size(); i++) {
            if(Lower(cars[i].getName()) == Lower(name)) {
                cout << "|";
                cout << left << setw(5) << i+1;
                cout << cars[i];
            }
        }
        cout << setfill('-');		
        cout << setw(100) << "-" << endl;
        cout << setfill(' ');
    } else cout << "Khong tim thay!";
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void QuanLy::findColor() {
    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n" << "Nhap vao mau sac muon tim kiem: \n";
    cin.ignore();
    string color; getline(cin, color);
    bool check = false;
    for(int i=0; i<cars.size(); i++) {
        if(Lower(cars[i].getColor()) == Lower(color)) {
            check = true; break;
        }
    }
    if(check == true) {
        font();
        for(int i=0; i<cars.size(); i++) {
            if(Lower(cars[i].getColor()) == Lower(color)) {
                cout << "|";
                cout << left << setw(5) << i+1;
                cout << cars[i];
            }
        }
        cout << setfill('-');		
        cout << setw(100) << "-" << endl;
        cout << setfill(' ');
    } else cout << "Khong tim thay!";
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void QuanLy::findAutomaker() {
    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n" << "Nhap vao hang xe muon tim kiem: \n";
    cin.ignore();
    string autom; getline(cin, autom);
    bool check = false;
    for(int i=0; i<cars.size(); i++) {
        if(Lower(cars[i].getAutomaker()) == Lower(autom)) {
            check = true; break;
        }
    }
    if(check == true) {
        font();
        for(int i=0; i<cars.size(); i++) {
            if(Lower(cars[i].getAutomaker()) == Lower(autom)) {
                cout << "|";
                cout << left << setw(5) << i+1;
                cout << cars[i];
            }
        }
        cout << setfill('-');		
        cout << setw(100) << "-" << endl;
        cout << setfill(' ');
    } else cout << "Khong tim thay!";
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void QuanLy::maxPrice() {
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

void QuanLy::minPrice() {
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

#endif