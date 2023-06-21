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

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}


// void removeCycle(ListNode* head) {

// 	ListNode* slow = head;
// 	ListNode* fast = head;

// 	while (true) {
// 		slow = slow->next;
// 		fast = fast->next->next;

// 		if (slow == fast) {
// 			break;
// 		}
// 	}

// 	ListNode* prev = head;
// 	while (prev->next != slow) { // prev->next != fast
// 		prev = prev->next;
// 	}

// 	slow = head;

// 	while (slow->next != fast->next) {
// 		prev = prev->next;
// 		slow = slow->next;
// 		fast = fast->next;
// 	}

// 	prev->next = NULL; // prev is pointing the tail node of the LL

// }

void removeCycle(ListNode* head) {

	ListNode* slow = head;
	ListNode* fast = head;

	while (true) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			break;
		}
	}

	slow = head;

	while (slow->next != fast->next) {
		slow = slow->next;
		fast = fast->next;
	}

	// slow->next and fast->next are pointers to the start of the cycle
	// i.e. fast is present at the tail of the LL

	fast->next = NULL;

}


int main() {

	ListNode* head = new ListNode(10);
	head->next = new ListNode(20);
	head->next->next = new ListNode(30);
	head->next->next->next = new ListNode(40);
	head->next->next->next->next = new ListNode(50);
	head->next->next->next->next->next = new ListNode(60);
	head->next->next->next->next->next->next = head->next->next;

	removeCycle(head);

	printLinkedList(head);

	return 0;
}