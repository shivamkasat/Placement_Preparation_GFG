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

Node* mergeList(Node *head1, Node *head2) {
  Node *head = NULL;
  Node *temp1 = NULL;
  Node *temp2 = NULL;
  Node *temp3 = NULL;

  if (head2 == NULL) {
    return head1;
  } else if (head1 == NULL) {
    return head2;
  }

  temp1 = head1;
  temp2 = head2;

  while (temp1 != NULL && temp2 != NULL) {
    if (temp1->data < temp2->data) {
      if (head == NULL) {
        head = temp1;
        temp3 = head;
        temp1 = temp1->next;
        temp3->next = NULL;
      } else {
        temp3->next = temp1;
        temp1 = temp1->next;
        temp3 = temp3->next;
        temp3->next = NULL;
      }
    } else {
      if (head == NULL) {
        head = temp2;
        temp3 = head;
        temp2 = temp2->next;
        temp3->next = NULL;
      } else {
        temp3->next = temp2;
        temp2 = temp2->next;
        temp3 = temp3->next;
        temp3->next = NULL;
      }
    }
  }

  if (temp1 != NULL) {
    temp3->next = temp1;
  }

  if (temp2 != NULL) {
    temp3->next = temp2;
  }

  return head;

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

    int m;
    cin>>m;
    Node *head2 = NULL;
    for (int i = 0; i < m; i++) {
      cin>>data;
      Node *newNode = createNode(data);
      head2 = insertNode(head2, newNode);
    }

    Node *head3 = NULL;
    head3 = mergeList(head1, head2);
    printList(head3);

  }
  return 0;
}
