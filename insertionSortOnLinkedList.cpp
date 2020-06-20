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
ListNode* insertionSort(ListNode *head) {

  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode *pt1 = NULL;
  ListNode *t1 = NULL;
  ListNode *t2 = NULL;
  ListNode *nt2 = NULL;
  ListNode *pt2 = NULL;

  t2 = head->next;
  pt2 = head;

  while (t2 != NULL) {
    t1 = head;
    pt1 = NULL;
    nt2 = t2->next;

    while (t1 != t2 && t1->val <= t2->val) {
      pt1 = t1;
      t1 = t1->next;
    }

    if (t1->val > t2->val) {
      pt2->next = t2->next;
      t2->next = t1;
      if (pt1 == NULL) {
        head = t2;
      } else {
        pt1->next = t2;
      }
    } else {
      pt2 = t2;
    }

    t2 = nt2;

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
    head1 = insertionSort(head1);
    printList(head1);

  }
  return 0;
}
