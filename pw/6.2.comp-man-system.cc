#include<bits/stdc++.h>
using namespace std;

struct addr{
    string area;
    int street;
    int house;
    addr(string a, int s, int h) : area(a), street(s), house(h) {}
};

struct empl{
    string name;
    int id;
    double salary;
    addr* address;
    empl(string n, int i, double s, addr* a) : name(n), id(i), salary(s), address(a) {}
};

string tolwr(string &s) {
    string k;
    for(char x : s) {
        if(x >= 'A' && x <= 'Z') k += x - ('A' - 'a');
        else k += x;
    }
    return k;
}

int main() {
    int n=0;
    cout << "Enter the number of employee: ";
    cin >> n;
    vector<empl*> r;
    while(n--) {
        string nm, ar;
        int id, sl, st, ho;
        cout << "\nEnter the name of employee: ";
        cin >> nm;
        cout << "Enter the employee id of employee: ";
        cin >> id;
        cout << "Enter the salary of employee: ";
        cin >> sl;
        cout << "Enter the area of employee: ";
        cin >> ar;
        cout << "Enter the street no of employee: ";
        cin >> st;
        cout << "Enter the house number of employee: ";
        cin >> ho;
        addr* ad = new addr(ar, st, ho);
        empl* x = new empl(nm, id, sl, ad);
        r.push_back(x);
    }
    string sar;
    cout << "\nEnter the area to find the employees belong to that area:\n";
    cin >> sar;
    sar = tolwr(sar);
    for(auto i : r) {
        if(i->address->area == sar) {
            cout << "\nName: " << i->name << endl;
            cout << "Empid: " << i->id << endl;
        }
    }
}