#include <vector>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
// 릿코드 상에서 이미 정의돼 있다는 가정이 있으므로 제출 시에는 이 struct 지우고 제출!
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		vector<int> lists;
		ListNode* cur = head;

		// lists의 front에 연결 리스트의 값을 삽입한다.
		while (cur != nullptr) {
			vector<int>::iterator it;
			it = lists.begin();
			lists.insert(it, cur->val);
			cur = cur->next;
		}

		// 뒤에서부터 n번째의 값이 삭제된다.
		vector<int>::iterator it = (lists.begin() + (n - 1));
		lists.erase(it);

		// 다시 결과를 위해 뒤집는다.
		reverse(lists.begin(), lists.end());

		// 결과를 연결 리스트로 연결하는 작업을 진행한다.
		ListNode* ret = nullptr;

		// 원소가 하나라서 다 삭제가 된 경우를 방지한다.
		if (lists.size() >= 1) {
			// cur만 옮기며 삽입하기 때문에, ret는 첫 번째 head를 고정으로 가리키게 된다.
			ret = new ListNode();
			cur = ret;

			for (int i = 0; i < lists.size(); i++) {
				cur->val = lists[i];

				// 맨 마지막 원소에서는 다음 노드를 만들 필요가 없다.
				if (i < lists.size() - 1) {
					cur->next = new ListNode();
					cur = cur->next;
				}
			}
		}

		return ret;
	}
};