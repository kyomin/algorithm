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

// y ���� �������� ����, y�� ������ x ���� �������� ����
bool comp(Node& node1, Node& node2) {
	if (node1.y == node2.y)
		return node1.x < node2.x;

	return node1.y > node2.y;
}

/*
	Node ����ü ���� ������ left, right ���� ä��� �Լ�

	@param parent		�θ� ���
	@param child		������ �Ǵ� parent �θ� ����� left �Ǵ� right�� ���� �ڽ� ���
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
	���� ��ȸ

	��Ʈ -> ���� ���� Ʈ�� -> ������ ���� Ʈ��
*/
void preorder(vector<int>& ans, Node* node) {
	if (node == NULL)
		return;

	ans.push_back(node->id);
	preorder(ans, node->left);
	preorder(ans, node->right);
}

/*
	���� ��ȸ

	���� ���� Ʈ�� -> ������ ���� Ʈ�� -> ��Ʈ
*/
void postorder(vector<int>& ans, Node* node) {
	if (node == NULL)
		return;

	postorder(ans, node->left);
	postorder(ans, node->right);
	ans.push_back(node->id);
}

/*
	@param nodeinfo		����Ʈ���� �����ϴ� ������ ��ǥ�� ��� �迭

	@return				����� ������ ����Ʈ���� ���� ��ȸ, ���� ��ȸ�� ���
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

	// ��Ʈ ���κ��� �� ���� ������ �� ��ġ�� �߰��Ͽ� ���� Ʈ�� �����
	Node* root = &nodes[0];
	for (int i = 1; i < size; i++)
		addNode(root, &nodes[i]);

	// ���� ��ȸ, ���� ��ȸ ����
	vector<vector<int>> answer{ {}, {} };

	preorder(answer[0], root);
	postorder(answer[1], root);

	return answer;
}