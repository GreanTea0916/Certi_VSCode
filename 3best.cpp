#include <iostream>
#include <queue>

using namespace std;

const int MAX_CITY = 20;

struct Restaurant {
    int cityID;
    string name;
    int value;
    Restaurant(int _cityID, string _name, int _value) {
        cityID = _cityID;
        name = _name;
        value = _value;
    }
};

struct cmp {
    bool operator()(Restaurant u, Restaurant t) {
        return u.value > t.value;
    }
};

priority_queue<Restaurant, vector<Restaurant>, cmp> pq[MAX_CITY + 1];

int main() {

    pq[0].push(Restaurant(1, "apple", 10));
    pq[0].push(Restaurant(1, "aim", 20));
    pq[0].push(Restaurant(1, "air", 30));

    pq[1].push(Restaurant(1, "banana", 10));
    pq[1].push(Restaurant(1, "box", 20));
    pq[1].push(Restaurant(1, "boy", 30));

    for(register int i = 0; i < MAX_CITY; i++){
        for(register int j = 0; j < pq[i].size(); j++){
            Restaurant rest = pq[i].top();
            cout<<"pq["<<i<<"] = "<<rest.name<<", "<<rest.value<<endl;
            pq[i].pop();
        }
    }

    return 0;
}