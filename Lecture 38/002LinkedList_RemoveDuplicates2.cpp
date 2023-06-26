#include<iostream>

using namespace std;

class ListNode {
public:

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

void insertAtHead(ListNode*& head, int val) {
	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;
}

void printLinkedList(ListNode* head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

// time : O(n) space : O(n) due to function call stack

ListNode* removeDuplicates(ListNode* head) {

	// base case

	if (head == NULL || head->next == NULL) {
		return head;
	}

	// recursive case

	if (head->val != head->next->val) {

		// head of the original LL will be the head of the final LL

		ListNode* headFromMyFriend = removeDuplicates(head->next);
		head->next = headFromMyFriend;
		return head;

	} else {

		// head of the original LL is duplicate therefore it will not be the head of the final LL

		while (head->next != NULL and head->val == head->next->val) {
			head = head->next;
		}

		ListNode* headFromMyFriend = removeDuplicates(head->next);
		return headFromMyFriend;

	}

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);
	insertAtHead(head, 0);
	insertAtHead(head, 0);
	insertAtHead(head, 0);
	insertAtHead(head, 0);

	printLinkedList(head);

	head = removeDuplicates(head);

	printLinkedList(head);

	return 0;
}