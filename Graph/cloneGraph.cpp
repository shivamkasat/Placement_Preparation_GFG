// submit on leetcode! IB has problem.
Node* cloneGraph(Node* root) {
  if (root == NULL) {
       return NULL;
   }
   map < int, Node * > nodeMap;
   set < pair < Node *, Node * > > edgeSet;
   Node *newRoot = new Node(root->val);
   queue < pair < Node *, Node * > > q;
   q.push({root, newRoot});
   nodeMap[newRoot->val] = newRoot;
   Node *oldNode;
   Node *newNode;
   Node *newNeigh;
   while (q.empty() != true) {
     oldNode = q.front().first;
     newNode = q.front().second;
     q.pop();
     for (auto neigh : oldNode->neighbors) {
       if (nodeMap.find(neigh->val) == nodeMap.end()) {
         newNeigh = new Node(neigh->val);
         newNeigh->neighbors.push_back(newNode);
         newNode->neighbors.push_back(newNeigh);
         nodeMap[newNeigh->val] = newNeigh;
         edgeSet.insert({newNeigh, newNode});
         edgeSet.insert({newNode, newNeigh});
         q.push({neigh, newNeigh});
       } else {
         newNeigh = nodeMap[neigh->val];
         if (edgeSet.find({newNeigh, newNode}) == edgeSet.end()) {
           newNeigh->neighbors.push_back(newNode);
           newNode->neighbors.push_back(newNeigh);
           edgeSet.insert({newNeigh, newNode});
           edgeSet.insert({newNode, newNeigh});
         }
       }
     }
   }

   return newRoot;
}
