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
ListNode* removeDuplicates(ListNode *head) {
  if (head->next == NULL) {
    return head;
  }
  ListNode *temp1 = head;
  ListNode *temp2 = head->next;

  while (temp2 != NULL) {
    if (temp1->val != temp2->val) {
      temp1->next = temp2;
      temp1 = temp2;
      temp2 = temp1->next;
    } else {
      temp2 = temp2->next;
    }
  }

  temp1->next = temp2;
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

    head1 = removeDuplicates(head1);
    printList(head1);

  }
  return 0;
}
