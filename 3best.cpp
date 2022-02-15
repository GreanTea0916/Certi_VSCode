//
//  main.cpp
//  best3
//
//  Created by Youngdae Lee on 2022. 2. 15..
//  Copyright © 2022년 Youngdae Lee. All rights reserved.
//
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

const int MAX_CITY = 20;
const int MAX_RESTAURANT = 10;
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
        if( u.value == t.value) {
            return u.cityID < t.cityID;
        } else {
            return u.value < t.value;
        }
    }
};


priority_queue<Restaurant, vector<Restaurant>, cmp> pq[MAX_CITY + 1];
vector<int> mArea;
unordered_map<string, int> restaurantList;

int main(int argc, const char * argv[]) {
    
    int area = 0;
    mArea.push_back(area);
    pq[area].push(Restaurant(1, "apple", 10));
    restaurantList["apple"] = 1;
    pq[area].push(Restaurant(2, "aim", 20));
    restaurantList["aim"] = 2;
    pq[area].push(Restaurant(3, "air", 30));
    restaurantList["air"] = 3;

    area = 1;
    mArea.push_back(area);
    pq[area].push(Restaurant(4, "banana", 10));
    restaurantList["banana"] = 4;
    pq[area].push(Restaurant(5, "box", 20));
    restaurantList["box"] = 5;
    pq[area].push(Restaurant(6, "boy", 30));
    restaurantList["boy"] = 6;

    area = 2;
    mArea.push_back(area);
    pq[area].push(Restaurant(7, "camera", 10));
    restaurantList["camera"] = 7;
    pq[area].push(Restaurant(8, "coconut", 20));
    restaurantList["coconut"] = 8;
    pq[area].push(Restaurant(9, "covariance", 30));
    restaurantList["covariance"] = 9;

    priority_queue<Restaurant, vector<Restaurant>, cmp> best3;

    for(int i = 0; i < 3; i++){
        int cnt = 0;
        while(cnt < 3) {
            Restaurant rest = pq[i].top();
            best3.push(rest);
            pq[i].pop();
            cnt++;
        }
    }
    
    int sum = 0;
    int cnt = 0;
    while(cnt < 3) {
        Restaurant rest = best3.top();
        cout<<"rest = "<<rest.cityID<<", from hash = "<<restaurantList[rest.name]<<", "<<rest.name<<", "<<rest.value<<endl;
        sum += rest.value;
        best3.pop();
        cnt++;
    }
    
    cout<<"sum of best3 = "<<sum<<endl;
    return 0;
}
