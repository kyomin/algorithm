/* �̴� ���ڵ� ���������� ���� ���ǵǾ� �ִ� ����ü�̹Ƿ� ���� �ÿ� �ּ� ó���Ѵ�. */
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
		ListNode* ret = new ListNode();		// �� ����� ó���� ����Ű�� �ִ�.
		ListNode* target = ret;				// ��� �����Ͱ� ��� �̵��� ���̹Ƿ�
		int carry = 0;

		// 2���� ���� ����Ʈ�� ��� nullptr�� ����Ű�� ���� ������
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

			// ��尡 ��ȿ�ϴٸ�, �������� �̵�
			if (l1 != nullptr)
				l1 = l1->next;
			if (l2 != nullptr)
				l2 = l2->next;

			// �� �� �ϳ��� ��ȿ�ϸ�, ���� �� ��带 �����ؾ� �Ѵ�.
			if (l1 != nullptr || l2 != nullptr) {
				target->next = new ListNode();	// ���� ��带 �����ϰ�
				target = target->next;			// �� ��带 �����Ͱ� ����Ű�� �Ѵ�.
			}
		}

		// l1, l2�� ������ ��ȸ�� �����ߴµ�, ĳ���� 1�� ��� ó��
		if (carry == 1) 
			target->next = new ListNode(1);
		
		return ret;
	}
};