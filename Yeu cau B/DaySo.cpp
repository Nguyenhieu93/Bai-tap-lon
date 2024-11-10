#include <bits/stdc++.h>
#include "List.cpp"
using namespace std;

class NumberList {
private:
    List<double> numbers;
public:
    void creatNumberList() {
        ifstream fi("Input.INP");
        cout << "Enter the numbers (enter # to stop): ";
        string s;
        while(1) {
            fi >> s;
            if(s == "#") break;
            double n = stod(s);
            numbers.push_back(n);
        }
    }

    void output() {
        cout << "Day so: ( ";
        for(auto it = numbers.begin(); it != numbers.end(); it++) {
            cout << *it << " ";
        }
        cout << ")" << endl;
    }

    void addNumber() {
        int pos;
        double val;
        cout << "Nhap vao vi tri muon add trong day so: ";
        cin >> pos;
        cout << "Nhap vao gia tri muon add: ";
        cin >> val;
        numbers.insert(pos, val);
    }

    void hasK() {
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
    
    void hasChanDuong() {
        int pos = 0, cnt = 1;
        auto it1 = numbers.begin();
        auto tmp = it1;
        auto it2 = ++tmp;
        auto tmp1 = it2;
        auto it3 = ++tmp1;
        cout << "3 so chan duong dung canh nhau o cac vi tri: " << endl;
        while(it3 != numbers.end()) {
            if(fmod(*it1, 2) == 0 && *it1 > 0 &&
               fmod(*it2, 2) == 0 && *it2 > 0 &&
               fmod(*it3, 2) == 0 && *it3 > 0) {
                cout << cnt << ". "; cnt++;
                cout << "(" << pos+1 << ", " << pos+2 << ", " << pos+3 << ")" << endl;
            }
            ++it1; ++it2; ++it3; ++pos;
        }
    }

    void sapXep() {
        numbers.sort();
    }

    bool checkInt(double a) {
        return a - (int)a == 0;
    }
    bool isNguyenTo(double a) {
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
    
    void xoaNguyenTo() {
        int pos = 1;
        for(auto it = numbers.begin(); it != numbers.end(); it++) {
            if(isNguyenTo(*it)) {
                numbers.erase(pos);
                continue;
            }
            pos++;
        }
    }

    void xoaTrungNhau() {
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

};

int main() {
    NumberList a;
    a.creatNumberList();
    a.output();
    a.sapXep();
    a.output();
    // a.xoaNguyenTo();
    a.output();
    a.xoaTrungNhau();
    a.output();
}