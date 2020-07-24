int maxHappiness (int a[], int b[], int chocs, int money)
{
    int mod = 998244353;
    vector < int > k(chocs, 1);
    priority_queue <  pair < int, int >, vector < pair < int, int > > > pq;
  for (int i = 0; i < chocs; i++) {
    //   cout<<"pushing "<<a[i]<<" "<<i<<endl;
    pq.push({a[i], i});
  }

  int happiness = 0;
  pair < int , int > currentPair;

  while (money > 0 && pq.empty() != true) {
    currentPair = pq.top();
    pq.pop();
    // cout<<"added ="<<currentPair.first<<endl;
    happiness = (happiness % mod + currentPair.first % mod) % mod;
    k[currentPair.second]++;
    if (a[currentPair.second] - (k[currentPair.second] - 1) * b[currentPair.second] > 0) {
      pq.push({a[currentPair.second] - (k[currentPair.second] - 1) * b[currentPair.second], currentPair.second});
    }
    money--;
  }

  return happiness;

}
