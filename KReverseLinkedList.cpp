#include <bits/stdc++.h>
using namespace std;

typedef struct node {
  int val;
  struct node *next;
} ListNode;

ListNode * createNode(int val) {
  ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
  temp->val = val;
  temp->next = NULL;
  return temp;
}

ListNode *insertNode(ListNode *head, ListNode *newNode) {
  if (head == NULL) {
    head = newNode;
    return head;
  }

  ListNode *temp = NULL;
  temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

void printList(ListNode *head) {
  ListNode *temp = head;
  cout<<"printing list"<<endl;
  while (temp != NULL) {
    cout<<temp->val<<" ";
    temp = temp->next;
  }

}

// create your function of interest here.
ListNode* reverseList(ListNode *start, ListNode *end) {
  ListNode *prev = end->next;
  ListNode *current = start;
  ListNode *later = current->next;

  while (later != end->next) {
    current->next = prev;
    prev = current;
    current = later;
    later = later->next;
  }

  current->next = prev;
  start = current;

  return start;

}

ListNode* kReverse(ListNode *head, int k) {
  ListNode *start = head;
  ListNode *end = NULL;
  ListNode *prevStart = NULL;
  head = NULL;

  cout<<"outside loop"<<endl;
  while (start != NULL) {
    cout<<"entered loop"<<endl;
    end = start;
    for (int i = 1; i < k; i++) {
      end = end->next;
    }

    // cout<<"start = "<<start->val<<" end = "<<end->val<<endl;

    if (head == NULL) {
      head = reverseList(start, end);
    } else {
      prevStart->next = reverseList(start, end);
    }

    prevStart = start;
    start = start->next;

  }

  return head;

}


int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    int val;
    ListNode *head1 = NULL;
    for (int i = 0; i < n; i++) {
      cin>>val;
      ListNode *newNode = createNode(val);
      head1 = insertNode(head1, newNode);
    }

    int k;
    cin>>k;

    // call you intrested function here.
    head1 = kReverse(head1, k);
    printList(head1);

  }
  return 0;
}
