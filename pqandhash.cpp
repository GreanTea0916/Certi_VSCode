#include <queue>
#include <unordered_map>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

struct PACKAGE {
    int pid;
    string name;
    int price;
    int reserved;
    PACKAGE(int _pid, string _name, int _price, int _reserved) {
        pid = _pid;
        name = _name;
        price = _price;
        reserved = _reserved;
    }

};

struct cmp {
    bool operator()(PACKAGE t, PACKAGE u) {
        return t.pid > u.pid;
    }
};

int main() {
    unordered_map<string, int> hashmap;
    priority_queue<PACKAGE, vector<PACKAGE>, cmp> pq;

    hashmap["apple"] = 31;
    hashmap["banana"] = 21;
    hashmap["orange"] = 11;

    pq.push(PACKAGE(1, "apple", 100, 1));
    pq.push(PACKAGE(2, "banana", 200, 1));
    pq.push(PACKAGE(3, "orange", 300, 1));

    cout<<"size of hashmap = "<<hashmap.size()<<endl;

    while(!pq.empty()) {
        PACKAGE item = pq.top();
        cout<<"item index = "<<item.pid<<", name = "<<item.name<<", price = "<<item.price<<", hash idx = "<<hashmap[item.name]<<endl;
        pq.pop();
    }

    return 0;
}