#include <string>
#include <iostream>
using namespace std;

struct Node{
    int prefix_count;
    bool isEnd;
    int index;
    struct Node *child[26];
}*head;

int mIdx = 0;

void init() {
    head = new Node();
    head->isEnd = false;
    head->index = mIdx;
    head->prefix_count = 0;
}

void insert(string word) {
    Node *current = head;
    current->prefix_count++;

    for(int i = 0; i < word.length(); ++i) {
        int letter = (int)word[i] - 'a';
        if(current->child[letter] == NULL) {
            current->child[letter] = new Node();
        }

        current->child[letter]->prefix_count++;
        current = current->child[letter];
    }
    current->isEnd = true;
    current->index = ++mIdx;
}

int search(string word) {
    Node *current = head;

	for(int i = 0 ; i < word.length(); ++i)
	{
		int letter = (int)word[i] - (int)'a';
		if(current->child[letter] == NULL) {
            return 0;
        }
		current = current->child[letter];
	}
	return current->index;
}

int main() {
    init();
    string input = "apple";
    insert(input);
    input = "samsung";
    insert(input);
    input = "victory";
    insert(input);

    int rtn = search("samsung");
    cout<<"rtn = "<<rtn<<endl;


    return 0;
}