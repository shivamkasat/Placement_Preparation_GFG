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
ListNode* rotateList(ListNode *head, int k) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  int count = 1;
  ListNode *end = head;
  while (end->next != NULL) {
    count++;
    end = end->next;
  }

  k = k % count;
  if (k == 0) {
    return head;
  }

  k = count - k;

  ListNode *tempHead = NULL;
  ListNode *temp = head;

  for (int i = 1; i < k; i++) {
    temp = temp->next;
  }
  tempHead = temp->next;
  end->next = head;
  temp->next = NULL;
  head = tempHead;

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
    head1 = rotateList(head1, k);
    printList(head1);
  }
  return 0;
}
