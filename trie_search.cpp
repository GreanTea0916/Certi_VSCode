#include <string>
#include <iostream>
using namespace std;

struct Node{
    int prefix_count;
    bool isEnd;
    struct Node *child[26];
}*head;

void init() {
    head = new Node();
    head->isEnd = false;
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
}

bool search(string word) {
    Node *current = head;

	for(int i = 0 ; i < word.length(); ++i)
	{
		int letter = (int)word[i] - (int)'a';
		if(current->child[letter] == NULL) {
            return false;
        }
		current = current->child[letter];
	}
	return current->isEnd;
}

int main() {
    init();
    string input = "apple";
    insert(input);

	if(search("apple"))
		printf("found apple\n");
	if(search("help"))
		printf("found help\n");


    return 0;
}