#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Node {
	bool removed;
	Node* prev;
	Node* next;
};

Node nodeArr[1000000];

string solution(int n, int k, vector<string> cmd) {
	for (int i = 1; i < n; i++) {
		nodeArr[i - 1].next = &nodeArr[i];
		nodeArr[i].prev = &nodeArr[i - 1];
	}

	Node* curr = &nodeArr[k];
	stack<Node*> removedList;
	for (string str : cmd) {
		if (str[0] == 'U') {
			int x = atoi(str.c_str() + 2);
			for (int i = 0; i < x; i++)
				curr = curr->prev;
		}
		else if (str[0] == 'D') {
			int x = atoi(str.c_str() + 2);
			for (int i = 0; i < x; i++)
				curr = curr->next;
		}
		else if (str[0] == 'C') {
			removedList.push(curr);
			curr->removed = true;	// mark remove status
			Node* up = curr->prev;
			Node* down = curr->next;

			if (up)
				up->next = down;

			if (down) {
				down->prev = up;
				curr = down;
			}
			else {
				curr = up;
			}
		}
		else {	// Z
			Node* node = removedList.top();
			removedList.pop();
			node->removed = false;
			Node* up = node->prev;
			Node* down = node->next;

			if (up)
				up->next = node;

			if (down)
				down->prev = node;
		}
	}

	string answer = "";
	for (int i = 0; i < n; i++) {
		if (nodeArr[i].removed)
			answer.push_back('X');
		else
			answer.push_back('O');
	}

	return answer;
}