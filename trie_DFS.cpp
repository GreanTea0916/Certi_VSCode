
struct Node {
    Node* left;
    Node* right;
    int value;

    void init(){
        // left = right = nullptr;
        value = 0;
    }

    void push_back(int index){
        if(value == 0){
            value = index;
        }
    }
};

Node* root;


void init() {

}

int DFS() {

}

int main() {
    init();

    DFS();
    return 0;
}