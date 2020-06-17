#include <bits/stdc++.h>
using namespace std;

typedef struct node {
  int data;
  struct node *next;
} Node;

Node * createNode(int data) {
  Node *temp = (Node *) malloc(sizeof(Node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

Node *insertNode(Node *head, Node *newNode) {
  if (head == NULL) {
    head = newNode;
    return head;
  }

  Node *temp = NULL;
  temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

void printList(Node *head) {
  Node *temp = head;
  cout<<"printing list"<<endl;
  while (temp != NULL) {
    cout<<temp->data<<" ";
    temp = temp->next;
  }

}

Node* reverseList(Node *head) {
  Node *prev = NULL;
  Node *current = head;
  Node *later = current->next;
  while (later != NULL) {
    current->next = prev;
    prev = current;
    current = later;
    later = later->next;
  }

  current->next = prev;
  head = current;
  prev = NULL;
  current = NULL;
  later = NULL;

  return head;

}


bool checkPalin(Node *head) {
  if (head == NULL) {
    return false;
  }else if (head->next == NULL) {
    return true;
  }

  Node *slow = head;
  Node *fast = head;
  Node *prevSlow = NULL;
  bool isOdd = true;
  while (fast != NULL && fast->next != NULL) {
    prevSlow = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  if (fast == NULL) {
    isOdd = false;
  }


  if (isOdd) {
    slow->next = reverseList(slow->next);
    prevSlow = slow;
  } else {
    prevSlow->next = reverseList(slow);
  }

  slow = head;
  fast = prevSlow->next;

  while (fast != NULL) {
    if (slow->data != fast->data) {
      return false;
    }
    slow = slow->next;
    fast = fast->next;
  }

  return true;

}


int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    int data;
    Node *head1 = NULL;
    for (int i = 0; i < n; i++) {
      cin>>data;
      Node *newNode = createNode(data);
      head1 = insertNode(head1, newNode);
    }

    // head1 = reverseList(head1);
    // printList(head1);

    cout<<checkPalin(head1)<<endl;

  }
  return 0;
}
