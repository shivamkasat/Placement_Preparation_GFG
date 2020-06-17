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
ListNode* removeNthElem(ListNode *head, int n) {
  ListNode *first = head;
  ListNode *second = head;
  ListNode *prev = NULL;
  for (int i = 0; i < n; i++) {
    if (second == NULL && i < n) {
        break;
    }
    second = second->next;
  }

  while (second != NULL) {
    prev = first;
    first = first->next;
    second = second->next;
  }

  if (prev != NULL) {
    prev->next = first->next;
  } else {
    head = head->next;
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

    int n1;
    cin>>n1;

    // call you intrested function here.
    head1 = removeNthElem(head1, n1);
    printList(head1);
    cout<<"end of printing"<<endl;

  }
  return 0;
}
