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

// time : O(sum of no. of digits in the two numbers)
// space : O(sum of no. of digits in the two numbers + 1)

ListNode* sumOfLinkedList(ListNode* head1, ListNode* head2) {

	ListNode* head = NULL;
	int carry = 0;

	while (head1 != NULL and head2 != NULL) {

		int sum = head1->val + head2->val + carry;

		ListNode* n = new ListNode(sum % 10);
		n->next = head;
		head = n;

		carry = sum / 10;

		head1 = head1->next;
		head2 = head2->next;

	}

	while (head1 != NULL) {

		int sum = head1->val + carry;

		ListNode* n = new ListNode(sum % 10);
		n->next = head;
		head = n;

		carry = sum / 10;

		head1 = head1->next;

	}

	while (head2 != NULL) {

		int sum = head2->val + carry;

		ListNode* n = new ListNode(sum % 10);
		n->next = head;
		head = n;

		carry = sum / 10;

		head2 = head2->next;

	}

	if (carry == 1) {
		ListNode* n = new ListNode(1);
		n->next = head;
		head = n;
	}

	return head;

}

// time : O(sum of no. of digits in the two numbers)
// space : O(sum of no. of digits in the two numbers + 1)

ListNode* sumOfLinkedListRefactored(ListNode* head1, ListNode* head2) {

	ListNode* head = NULL;
	int carry = 0;

	while (head1 != NULL || head2 != NULL || carry == 1) {

		int d1 = head1 != NULL ? head1->val : 0;
		int d2 = head2 != NULL ? head2->val : 0;

		int sum = d1 + d2 + carry;

		ListNode* n = new ListNode(sum % 10);
		n->next = head;
		head = n;

		carry = sum / 10;

		head1 = head1 != NULL ? head1->next : NULL;
		head2 = head2 != NULL ? head2->next : NULL;

	}

	return head;

}

int main() {

	ListNode* head1 = NULL;

	insertAtHead(head1, 9);
	insertAtHead(head1, 9);
	insertAtHead(head1, 9);
	insertAtHead(head1, 9);
	insertAtHead(head1, 9);

	printLinkedList(head1);

	ListNode* head2 = NULL;

	insertAtHead(head2, 9);
	insertAtHead(head2, 9);
	insertAtHead(head2, 9);

	printLinkedList(head2);

	// ListNode* head = sumOfLinkedList(head1, head2);
	ListNode* head = sumOfLinkedListRefactored(head1, head2);

	printLinkedList(head);



	return 0;
}