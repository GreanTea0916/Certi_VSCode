#include <queue>
#include <iostream>

using namespace std;


void printQueue() {

}

int main() {
    queue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout<<"queue size = "<<queue.size()<<endl;
    for(auto i = queue.front(); i != queue.back(); i++){

    }
    queue.push(4);
    if(queue.size() > 3) {
        queue.pop();
    }
    cout<<"queue2 size = "<<queue.size()<<endl;

    return 0;
}