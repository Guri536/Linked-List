#include<bits/stdc++.h>
#include "linked_list.hpp"
using namespace std;

struct mydt {
    vector<int> i;
    string a;
    mydt(vector<int> j, string k) : i(j), a(k) {}
};

ostream& operator<<(ostream& out, mydt& obj) {
    out << obj.a << ": { ";
    for (int k : obj.i) {
        out << k << " ";
    }
    out << "}";
    return out;
}

int main() {
    linked_list<mydt> list;
    list.appends(mydt(vector<int>{1, 2, 3}, "Wow"), mydt(vector<int>{3, 2, 1}, "Hmm"));
    list.println();
    return 0;
}