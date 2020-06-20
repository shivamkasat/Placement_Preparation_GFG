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

ListNode* reverseList(ListNode *head, ListNode *start, ListNode *end) {

  cout<<"val at start "<<start->val<<endl;
  cout<<"val at end "<<end->val<<endl;

  ListNode *prev = end->next;
  ListNode *current = start;
  ListNode *later = start->next;

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

ListNode* reverseLinkedList(ListNode *head, int n, int m) {
  if (head == NULL || head->next == NULL || n == m) {
    return head;
  }

  ListNode *start = head;
  ListNode *end = head;
  ListNode *beforeStart = NULL;

  for (int i = 1; i < n; i++) {
    beforeStart = start;
    start = start->next;
  }

  for (int i = 1; i < m; i++) {
    end = end->next;
  }

  if (beforeStart == NULL) {
    head = reverseList(head, start, end);
  } else {
    beforeStart->next = reverseList(head, start, end);
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

    int start, end;
    cin>>start>>end;

    // call you intrested function here.
    head1 = reverseLinkedList(head1, start, end);
    printList(head1);
  }
  return 0;
}
