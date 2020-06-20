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
ListNode* partitionList(ListNode *head, int x) {

  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode *p = NULL;
  ListNode *q = head;
  ListNode *r = head->next;
  ListNode *end = head;
  ListNode *mark = NULL;

  while (end->next != NULL) {
    end = end->next;
  }

  mark = end;

  while (q != mark) {
    if (q->val >= x) {
      if (p == NULL) {
        head = r;
      } else {
        p->next = r;
      }

      end->next = q;
      q->next = NULL;
      q = r;
      r = q->next;
      end = end->next;

    } else {
      p = q;
      q = r;
      r = q->next;
    }
  }

  if (q->val >= x && q != end) {
    if (p == NULL) {
      head = r;
    } else {
      p->next = r;
    }
    end->next = q;
    q->next = NULL;
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

    int x;
    cin>>x;

    // call you intrested function here.
    head1 = partitionList(head1, x);
    printList(head1);

  }
  return 0;
}
