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
  ListNode *t1 = NULL;
  ListNode *t2 = NULL;
  ListNode *t3 = NULL;

  if (head == NULL || head->next == NULL) {
    return head;
  }

  t1 = head;
  t2 = head->next;
  head = NULL;

  while (t2 != NULL) {
    if (t1->val != t2->val) {
      if (t1->next == t2) {
        if (head == NULL) {
          head = t1;
          t3 = head;
        } else {
          t3->next = t1;
          t3 = t3->next;
        }
      }
      t1 = t2;
      t2 = t1->next;
    } else {
      t2 = t2->next;
    }
  }

  if (t1->next == NULL) {
    if (head == NULL) {
      head = t1;
    } else {
      t3->next = t1;
    }
  } else {
    if (t3 != NULL)
      t3->next = NULL;
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
    head1 = removeDuplicates(head1);
    printList(head1);

  }
  return 0;
}
