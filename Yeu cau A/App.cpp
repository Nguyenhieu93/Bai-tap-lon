#include <bits/stdc++.h>
#include "QuanLy.cpp"
using namespace std;

class App {
public:
    int menu() {
        cout << endl;
        cout << right << setw(20) << "Xe hoi\n";

        cout << setfill('-');		
	    cout << setw(30) << "-" << endl;
        cout << setfill(' ');

        cout << "1. Enter the car list\n";
        cout << "2. My garage\n";
        cout << "3. Add a new car for my car list\n";
        cout << "4. Modify vehicle information\n";
        cout << "5. Search my car\n";
        cout << "6. Search cars's name at garage\n";
        cout << "7. Search automaker at garage\n";
        cout << "8. Search car's color at garage\n";
        cout << "9. Search car's price at garage\n";
        cout << "10. Delete\n"; 
        cout << "11. Exit\n";
        cout << "Choose: ";
        
        while(1){
            int t;
            cin>>t;
            if (t >= 1 && t <= 10) return t;
            cout << "Invalid!!";
            cout << " Choose again: ";
        }
    }
    void run() {
        QuanLy a;
        int tt;
        do{
            tt = menu();
            switch (tt)
            {
                case 1:
                    a.input();
                    break;
                case 2:
                    a.output();
                    break;
                case 3:
                    a.add();
                    break;
                case 4:
                    a.modify();
                    break;
                case 5:
                    a.find();
                    break;
                case 6:
                    a.findName();
                    break;
                case 7:
                    a.findAutomaker();
                    break;
                case 8:
                    a.findColor();
                    break;
                case 9:
                    a.findPrice();
                    break;
                case 10:
                    a.erase1();
                    break;
                case 11: 
                    cout << "Goodbye!!!";
                default:
                    break;
            }
        }while(tt != 11);
    }
};


main() {
    App a;
    a.run();
}