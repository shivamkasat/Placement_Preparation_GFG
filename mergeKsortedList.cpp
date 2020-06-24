bool comp(ListNode *a, ListNode *b) {
  return a->val < b->val;
}
ListNode* mergeLists(vector < listNode * > lists) {
  priority_queue < ListNode *, vector < ListNode * >, comp > pq;
  for (int i = 0; i < lists.size(); i++) {
    if (lists[i][0] != NULL)
      pq.push(lists[i][0]);
  }

  ListNode *head = NULL;
  ListNode *temp = NULL;
  ListNode *min = NULL;

  while (pq.empty() != true) {
    min = pq.top();
    pq.pop();
    if (head == NULL) {
      head = min;
      temp = min;
    } else {
      temp->next = min;
      temp = temp->next;
    }

    if (min->next != NULL) {
      pq.push(min->next);
    }
  }

  return head;
}
