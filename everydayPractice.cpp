
//add delete find swap
#include <iostream>
#include <string>
#include <cstring>
#include <vector> //vector
#include <queue> //queue, pq
#include <unordered_map> //hash

using namespace std;

struct Package {
    int id;
    int price;
    int area;
    Package(int _id, int _price, int _area) {
        id = _id, price = _price, area = _area;
    }
};

void runVector() {
    vector<Package> vt;
    vt.push_back(Package(1,1,1));
    vt.push_back(Package(2,2,2));
    vt.push_back(Package(3,3,3));
    vt.push_back(Package(4,4,4));
    vt.push_back(Package(5,5,5));

    for(vector<Package>::iterator i = vt.begin(); i < vt.end(); i++) {
        cout<<(*i).id<<", price = "<<(*i).price<<", area = "<<(*i).area<<endl;
    }
    cout<<endl;
    vt.erase(vt.begin() + 1);
    for(vector<Package>::iterator i = vt.begin(); i < vt.end(); i++) {
        if((*i).id == 3) {
            vt.erase(i);
        }
    }

    cout<<endl;
    for(vector<Package>::iterator i = vt.begin(); i < vt.end(); i++) {
        cout<<(*i).id<<", price = "<<(*i).price<<", area = "<<(*i).area<<endl;
    }

}

struct cmp {
    bool operator()(Package u, Package t) {
        if(u.price == t.price) {
            return u.id > t.id;
        }
        return u.price > t.price;
    }

};

void runQueue() {
    cout<<"runQueue"<<endl;
    queue<Package> q;
    q.push(Package(1,1,1));
    q.push(Package(2,1,1));
    q.push(Package(3,1,1));
    q.push(Package(4,1,1));
    q.push(Package(5,1,1));
    cout<<q.front().id<<endl;
    cout<<q.back().id<<endl;
    q.pop();
    int size = q.size();
    for(int i =0; i < size; i++){
        Package item = q.front();
        cout<<"id = "<<item.id<<", "<<item.price<<", "<<item.area<<endl;
        q.pop();
    }
}

void runPQ() {
    cout<<"runPQ"<<endl;
    priority_queue<Package, vector<Package>, cmp> pq;
    pq.push(Package(1,1,1));
    pq.push(Package(2,1,1));
    pq.push(Package(3,2,1));
    pq.push(Package(4,3,1));
    pq.push(Package(5,2,1));
    int size = pq.size();
    for(int i = 0; i < size; i++){
        Package item = pq.top();
        cout<<"id = "<<item.id<<", "<<item.price<<", "<<item.area<<endl;
        pq.pop();
    }

}

void runHash(){
    vector<Package> vec;
    string strList[5] = {"apple", "banana", "cocoa", "diamond", "elephant"};
    unordered_map<string, int> hash;
    for(int i = 0; i < 5; i++){
        // string str = strList[i];
        hash[strList[i]] = i;
    }

    cout<<"value = "<<hash["apple"]<<endl;
}

int main() {

    runVector();
    runQueue();
    runPQ();
    runHash();

    return 0;
}
