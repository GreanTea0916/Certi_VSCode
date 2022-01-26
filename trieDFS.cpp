#include <iostream>
using namespace std;

const int MAX_N = 3;
const int MAX_M = 3;

int input[3][3][3] = {
    {{0,0,0},{0,0,0},{0,0,1}},
    {{0,0,0},{0,0,0},{1,0,1}},
    {{0,0,0},{0,0,0},{0,1,1}}    
};

int target[3][3] = {{0,0,0}, {0,0,0}, {1,1,1}};
int target2[3][3] = {{0,0,0},{0,0,0},{0,1,1}};

struct Node {
    struct Node *left;
    struct Node *right;
    int val;

    Node(){
        left = right = nullptr;
        val = 0;
    }

    void push_back(int idx) {
        if(val == 0) {
            val = idx;
        }
    }
}*root;


int n;
int m;
void init(int N, int M) {
    n = N;
    m = M;

    root = new Node();
    for(int i = 0; i < n; i++) {
        Node* it = root;
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                if(input[i][j][k] == 0) {
                    if(it->left == nullptr) {
                        it->left = new Node();
                    }
                    it = it->left;
                } else {
                    if(it->right == nullptr) {
                        it->right = new Node();
                    }
                    it = it->right;
                }
            }
        }
        it->push_back(i + 1);
    }
}

int arr[105];
int d[1000005];
int dfs(Node* cur, int pos, int diff) {
    if(cur == nullptr || diff >= 3) {
        return 0;
    }

    if(pos == m * m) {
        if(cur->val !=0) {
            d[cur->val] = diff;
            return cur->val;
        }
        return 0;
    }

    int left_node = 0;
    int right_node = 0;

    if(arr[pos] == 0) {
        left_node = dfs(cur->left, pos + 1, diff);
        right_node = dfs(cur->right, pos +1, diff + 1);
    } else {
        left_node = dfs(cur->left, pos + 1, diff + 1);
        right_node = dfs(cur->right, pos + 1, diff);
    }

    //return condition
    if(left_node == 0 || d[left_node] > d[right_node] || (d[left_node] == d[right_node] && left_node > right_node)) {
        return right_node;
    }
    return left_node;
}

int findImage(int mock[3][3]) {
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            arr[i * m + j] = mock[i][j];
        }
    }

    d[0] = m * m;

    int rtn = dfs(root, 0, 0);
    return rtn;
}

int main() {
    cout<<"Hello World"<<endl;

    init(3, 3);
    cout<<"init is done"<<endl;
    int rtn = findImage(target);
    cout<<"rtn = "<<rtn<<endl;
    rtn = findImage(target2);
    cout<<"rtn = "<<rtn<<endl;
    // findImage(target);

    return 0;
}