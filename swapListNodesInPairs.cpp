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
ListNode* swapNodes(ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode *p = NULL;
  ListNode *q = head;
  ListNode *r = head->next;
  ListNode *tempr = NULL;

  while (1) {
    if (p == NULL) {
      head = r;
    } else {
      p->next = r;
    }

    tempr = r->next;
    r->next = q;

    if (tempr == NULL || tempr->next == NULL) {
      break;
    }

    p = q;
    q = tempr;
    r = q->next;

  }

  if (tempr == NULL) {
    q->next = NULL;
  } else {
    q->next = tempr;
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

    // call you intrested function here.
    head1 = swapNodes(head1);
    printList(head1);
  }
  return 0;
}
