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
        } else if (input[pivot] < target) {
            left = pivot + 1;
        } else {
            right = pivot - 1;
        }
    }
    return -1;
}

void move_zeros() {
    int input[] = {0, 5, 7, 0, 3};
    int inputsize = sizeof(input) / sizeof(int);

    int wIdx = 0;
    for(int i = 0; i < inputsize -1; i++) {
        if(input[i] != 0) {
            input[wIdx] = input[i];
            wIdx++;
        }
    }

    for(;wIdx < inputsize; wIdx++) {
        input[wIdx] = 0;
    }

    for(int i = 0; i < inputsize; i++) {
        cout<<input[i]<<" ";
    }
}

int find_pivot_index() {
    int input[] = {1, 8, 2, 9, 2, 3, 6};
//    int input[] = {2, 5, 7};
    int inputsize = sizeof(input)/sizeof(input[0]);

    int sum = 0;
    int leftsum = 0;
    int rightsum = 0;
    for(int i = 0; i < inputsize; i++){
        rightsum += input[i];
    }

    int past_num = 0;
    for(int i =0; i < inputsize -1; i++){
        int crt_num = input[i];
        rightsum = rightsum - crt_num;
        leftsum = leftsum + past_num;
        if(leftsum == rightsum) {
            return i;
        }

        past_num = crt_num;
    }


    return -1;   
}

int main() {
    cout<<"Hello World"<<endl;
    
    // int rtn = binary_search();
    // cout<<"rtn = "<<rtn<<endl;
    
    // move_zeros();
    
    int rtn = find_pivot_index();
    cout<<"rtn = "<<rtn<<endl;

    return 0;
}