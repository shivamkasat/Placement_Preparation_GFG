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
ListNode* addList(ListNode *head1, ListNode *head2) {
  if (head1 == NULL) {
    return head2;
  } else if (head2 == NULL) {
    return head1;
  }

  int n1 = 1;
  int n2 = 1;
  ListNode *temp1 = head1;
  ListNode *temp2 = head2;

  while(temp1 != NULL) {
    n1++;
    temp1 = temp1->next;
  }

  while (temp2 != NULL) {
    n2++;
    temp2 = temp2->next;
  }

  if (n1 < n2) {
    temp1 = head1;
    head1 = head2;
    head2 = temp1;
  }

  // cout<<"head1 = "<<head1->val<<" head2 = "<<head2->val<<endl;
  int base = 0;
  int carry = 0;
  temp1 = head1;
  temp2 = head2;

  while (temp2 != NULL) {
    base = temp1->val + temp2->val + carry;
    carry = base / 10;
    temp1->val = base % 10;
    // cout<<"base = "<<temp1->val<<" carry = "<<carry<<endl;
    temp1 = temp1->next;
    temp2 = temp2->next;
  }

  while (temp1 != NULL) {
    base = temp1->val + carry;
    temp1->val = base % 10;
    carry = base / 10;
    temp1 = temp1->next;
  }

  if (carry == 0) {
    return head1;
  }

  temp1 = head1;
  while (temp1->next != NULL) {
    temp1 = temp1->next;
  }

  temp1->next = createNode(carry);
  return head1;



  return head1;

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

    int n2;
    cin>>n2;

    ListNode *head2 = NULL;
    for (int i = 0; i < n2; i++) {
      cin>>val;
      ListNode *newNode = createNode(val);
      head2 = insertNode(head2, newNode);
    }

    // call you intrested function here.
    head1 = addList(head1, head2);
    printList(head1);
  }
  return 0;
}
