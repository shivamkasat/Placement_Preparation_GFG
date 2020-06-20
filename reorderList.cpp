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

ListNode* reverseList(ListNode *head) {
  ListNode *prev = NULL;
  ListNode *current = head;
  ListNode *later = head->next;

  while (later != NULL) {
    current->next = prev;
    prev = current;
    current = later;
    later = later->next;
  }

  current->next = prev;
  head = current;

  return head;

}


// create your function of interest here.
ListNode* reorderList(ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode *slow = head;
  ListNode *fast = head;
  ListNode *prevSlow = NULL;

  while (fast != NULL && fast->next != NULL) {
    prevSlow = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  bool isOdd = true;

  if (fast == NULL) {
    isOdd = false;
    prevSlow->next = reverseList(slow);
  } else {
    slow->next = reverseList(slow->next);
    prevSlow = slow;
  }



  ListNode *t1 = head;;
  ListNode *t2 = prevSlow->next;
  ListNode *t3 = t1->next;
  ListNode *t4 = t2->next;

  while (t4 != NULL) {
    t1->next = t2;
    t2->next = t3;
    t1 = t3;
    t2 = t4;
    t3 = t3->next;
    t4 = t4->next;
  }

  if (isOdd == false) {
    t1->next = t2;
    t2->next = NULL;
  } else {
    t1->next = t2;
    t2->next = slow;
    slow->next = NULL;
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
    head1 = reorderList(head1);
    printList(head1);
  }
  return 0;
}
