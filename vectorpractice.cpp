#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct Package {
    int id;
    int price;
    int area;

    Package(int _id, int _price, int _area) {
        id = _id, price = _price, area = _area;
    }
};
struct cmp {
    bool operator()(Package u, Package t) {
        if(u.price == t.price) {
            return u.id > t.id;
        }
        return u.price > t.price;
    }
};

priority_queue<Package, vector<Package>, cmp> pq;
vector<Package> input2;

Package findItem(int id) {
    Package rtn = Package(0,0,0);
    
    for(vector<Package>::iterator i = input2.begin(); i < input2.end(); i++){
        Package item = *i;
        cout<<item.id<<", price"<<item.price<<", area = "<<item.area<<endl;
        if( item.id == id) {
            return item;
        }
    }

    return rtn;
}
int main() {
    vector<int> input;
    pq.push(Package(1, 1, 1));
    pq.push(Package(2, 3, 2));
    pq.push(Package(3, 1, 2));
    pq.push(Package(4, 2, 1));
    pq.push(Package(5, 4, 3));

    input2.push_back(Package(1, 1, 1));
    input2.push_back(Package(2, 3, 2));
    input2.push_back(Package(3, 1, 2));
    input2.push_back(Package(4, 2, 1));
    input2.push_back(Package(5, 4, 3));
    for(vector<Package>::iterator i = input2.begin(); i < input2.end(); i++){
        Package item = *i;
        cout<<item.id<<", price"<<item.price<<", area = "<<item.area<<endl;
    }

    Package item = findItem(3);
    cout<<"item = "<<item.id<<", price = "<<item.price<<", area = "<<item.area<<endl;

    
    
    // for(int i =0 ; i < 5; i++){
    //     input.push_back(i);
    // }

    // vector<int>::iterator it = input.begin();
    // for(vector<int>::iterator i = input.begin(); i < input.end(); i++){
    //     cout<<"value = "<<*i<<endl;
    // }

    // for(int i =0; i < input.size(); i++){
    //     cout<<input[i]<<endl;
    // }

    // for(int i = 0; i < 5; i++){
    //     cout<<"id = "<<pq.top().id<<", price = "<<pq.top().price<<endl;
    //     pq.pop();
    // }

    return 0;
}