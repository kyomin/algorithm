/* 이는 릿코드 내부적으로 따로 정의되어 있는 구조체이므로 제출 시에 주석 처리한다. */
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ret = new ListNode();		// 답 노드의 처음을 가리키고 있다.
		ListNode* target = ret;				// 얘는 포인터가 계속 이동할 것이므로
		int carry = 0;

		// 2개의 연결 리스트가 모두 nullptr을 가리키지 않을 때까지
		while (l1 != nullptr || l2 != nullptr) {
			int val1 = 0;
			int val2 = 0;

			if (l1 != nullptr)
				val1 = l1->val;

			if (l2 != nullptr)
				val2 = l2->val;

			int sum = val1 + val2 + carry;
			target->val = sum % 10;

			if (sum >= 10)
				carry = 1;
			else
				carry = 0;

			// 노드가 유효하다면, 다음으로 이동
			if (l1 != nullptr)
				l1 = l1->next;
			if (l2 != nullptr)
				l2 = l2->next;

			// 둘 중 하나라도 유효하면, 다음 답 노드를 생성해야 한다.
			if (l1 != nullptr || l2 != nullptr) {
				target->next = new ListNode();	// 다음 노드를 생성하고
				target = target->next;			// 그 노드를 포인터가 가리키게 한다.
			}
		}

		// l1, l2를 끝까지 순회해 연산했는데, 캐리가 1인 경우 처리
		if (carry == 1) 
			target->next = new ListNode(1);
		
		return ret;
	}
};