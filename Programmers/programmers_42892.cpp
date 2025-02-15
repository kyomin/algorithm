#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int id;
	int x; 
	int y;
	Node* left;
	Node* right;
};

// y 기준 내림차순 정렬, y가 같으면 x 기준 오름차순 정렬
bool comp(Node& node1, Node& node2) {
	if (node1.y == node2.y)
		return node1.x < node2.x;

	return node1.y > node2.y;
}

/*
	Node 구조체 변수 노드들의 left, right 값을 채우는 함수

	@param parent		부모 노드
	@param child		기준이 되는 parent 부모 노드의 left 또는 right에 놓일 자식 노드
*/
void addNode(Node* parent, Node* child) {
	if (child->x < parent->x) {
		if (parent->left == NULL)
			parent->left = child;
		else
			addNode(parent->left, child);
	}
	else {
		if (parent->right == NULL)
			parent->right = child;
		else
			addNode(parent->right, child);
	}
}

/* 
	전위 순회

	루트 -> 왼쪽 서브 트리 -> 오른쪽 서브 트리
*/
void preorder(vector<int>& ans, Node* node) {
	if (node == NULL)
		return;

	ans.push_back(node->id);
	preorder(ans, node->left);
	preorder(ans, node->right);
}

/*
	후위 순회

	왼쪽 서브 트리 -> 오른쪽 서브 트리 -> 루트
*/
void postorder(vector<int>& ans, Node* node) {
	if (node == NULL)
		return;

	postorder(ans, node->left);
	postorder(ans, node->right);
	ans.push_back(node->id);
}

/*
	@param nodeinfo		이진트리를 구성하는 노드들의 좌표가 담긴 배열

	@return				노드들로 구성된 이진트리를 전위 순회, 후위 순회한 결과
*/
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {	
	vector<Node> nodes;

	int size = nodeinfo.size();

	for (int i = 0; i < size; i++) {
		nodes.push_back({
			i + 1,
			nodeinfo[i][0], 
			nodeinfo[i][1]
		});
	}

	sort(nodes.begin(), nodes.end(), comp);

	// 루트 노드로부터 그 하위 노드들을 각 위치에 추가하여 이진 트리 만들기
	Node* root = &nodes[0];
	for (int i = 1; i < size; i++)
		addNode(root, &nodes[i]);

	// 전위 순회, 후위 순회 수행
	vector<vector<int>> answer{ {}, {} };

	preorder(answer[0], root);
	postorder(answer[1], root);

	return answer;
}