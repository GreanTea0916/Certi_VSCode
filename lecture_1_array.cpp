#include <iostream>

using namespace std;

int binary_search() {
    cout<<"run binary_search"<<endl;
    int target = 15;
    int input[] = {1, 3, 5, 6, 7, 15, 20};

    int left = 0;
    int right = sizeof(input) / sizeof(int) - 1;

    while(left <= right) {
        int pivot = (left + right) / 2;
        if(input[pivot] == target) {
            return pivot;
        } else if(input[pivot] < target) {
            left = pivot + 1;
        } else {
            right = pivot - 1;
        }
    }
    return -1;
}


int main() {
    cout<<"Hello World"<<endl;
    int rtn = binary_search();
    cout<<"rtn = "<<rtn<<endl;
    return 0;
}