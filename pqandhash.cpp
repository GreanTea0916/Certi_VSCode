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

    bool operator()(PACKAGE t, PACKAGE u) {
        return t.pid > u.pid;
    }

};

struct cmp {
    bool operator()(PACKAGE t, PACKAGE u) {
        return t.pid < u.pid;
    }
};

int main() {
    unordered_map<string, int> hashmap;

    priority_queue<PACKAGE, vector<PACKAGE>, cmp> pq[10];

    hashmap["apple"] = 31;
    hashmap["banana"] = 21;
    hashmap["orange"] = 11;

    cout<<"count = "<<hashmap.count("apple")<<endl;

    pq[0].push(PACKAGE(1, "apple", 100, 1));
    pq[0].push(PACKAGE(2, "banana", 200, 1));
    pq[0].push(PACKAGE(3, "orange", 300, 1));

    cout<<"size of hashmap = "<<hashmap.size()<<endl;

    while(!pq[0].empty()) {
        PACKAGE item = pq[0].top();
        cout<<"item index = "<<item.pid<<", name = "<<item.name<<", price = "<<item.price<<", hash idx = "<<hashmap[item.name]<<endl;
        pq[0].pop();
    }


    return 0;
}