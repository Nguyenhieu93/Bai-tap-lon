#include <bits/stdc++.h>
#include "List.cpp"
using namespace std;

class NumberList {
private:
    List<double> numbers;
public:
    void creatNumberList();
    void output();
    void addNumber();
    void hasK();
    void hasChanDuong();
    void sapXep();
    bool checkInt(double a);
    bool isNguyenTo(double a);
    void xoaNguyenTo();
    void xoaTrungNhau();

};

void NumberList::creatNumberList() {
    cout << "Enter the numbers (enter # to stop): \n";
    string s;
    while(1) {
        cin >> s;
        if(s == "#") break;
        double n = stod(s);
        numbers.push_back(n);
    }
}

void NumberList::output() {
    cout << "|";
    cout << left << setw(7) << "Vi tri";
    cout << "|";
    cout << left << setw(15) << "Gia tri";
    cout << "|" << endl;

    cout << setfill('-');		
    cout << setw(25) << "-" << endl;
    cout << setfill(' ');  

    int i=0;
    for(auto it = numbers.begin(); it != numbers.end(); it++) {
        cout << "|";
        cout << left << setw(7) << i+1;
        cout << "|";
        cout << left << setw(15) << *it;
        cout << "|" << endl;
        i++;
    }
    cout << "\n\n";
}

void NumberList::addNumber() {
    int pos;
    double val;
    cout << "Nhap vao vi tri muon add trong day so: ";
    cin >> pos;
    cout << "Nhap vao gia tri muon add: ";
    cin >> val;
    numbers.insert(pos, val);
}

void NumberList::hasK() {
    double k;
    int cnt = 0;
    cout << "Nhap vao so k muon kiem tra (k != 0): ";
    do{
        cin >> k;
        if(k == 0) {
            cout << "k khong thoa man, xin moi nhap lai: ";
            continue;
        }else {
            break;
        }
    }while(1);
    for(auto it = numbers.begin(); it != numbers.end(); it++) {
        if(*it == k) cnt++;
    }
    cout << "Co " << cnt << " chu so trong day co gia tri bang " << k << endl;
}

void NumberList::hasChanDuong() {
    int pos = 0, cnt = 1;
    auto it1 = numbers.begin();
    auto tmp = it1;
    auto it2 = ++tmp;
    auto tmp1 = it2;
    auto it3 = ++tmp1;
    bool check = false;
    cout << "3 so chan duong dung canh nhau o cac vi tri: " << endl;
    while(it3 != numbers.end()) {
        if(fmod(*it1, 2) == 0 && *it1 > 0 &&
            fmod(*it2, 2) == 0 && *it2 > 0 &&
            fmod(*it3, 2) == 0 && *it3 > 0) {
            cout << cnt << ". "; cnt++;
            cout << "(" << pos+1 << ", " << pos+2 << ", " << pos+3 << ")" << endl;
            check = true;
        }
        ++it1; ++it2; ++it3; ++pos;
    }
    if(!check) cout << "\nKhong co 3 so chan duong dung canh nhau!!";
}

void NumberList::sapXep() {
    numbers.sort();
}

bool NumberList::checkInt(double a) {
    return a - (int)a == 0;
}
bool NumberList::isNguyenTo(double a) {
    if(a - (int)a == 0) {
        int b = (int)a;
        for(int i=2; i<=sqrt(b); i++) {
            if(b % i == 0) return false;
        }
        return b > 1;
    } else {
        return false;
    }
}

void NumberList::xoaNguyenTo() {
    int pos = 1;
    for(auto it = numbers.begin(); it != numbers.end(); it++) {
        if(isNguyenTo(*it)) {
            numbers.erase(pos);
            continue;
        }
        pos++;
    }
}

void NumberList::xoaTrungNhau() {
    set<double> f;
    int pos = 1;
    for(auto it = numbers.begin(); it != numbers.end(); it++) {
        if(f.find(*it) != f.end()) {
            numbers.erase(pos);
            continue;
        } else {
            f.insert(*it);
        }
        pos++;
    }
}

int main() {
    NumberList a;
    a.creatNumberList();
    a.output();
    a.addNumber();
    a.hasK();
    a.hasChanDuong();
    a.sapXep();
    cout << "Danh sach so sau khi sap xep:" << endl;
    a.output();
    a.xoaNguyenTo();
    cout << "Danh sach so sau khi xoa chu so nguyen to:" << endl;
    a.output();
    a.xoaTrungNhau();
    cout << "Danh sach so sau khi xoa chu so trung nhau:" << endl;
    a.output();
}