
vector<int> Solution::subUnsort(vector<int> &A) {
  vector < int > result;
  int n = A.size();
  int i = 1;
  while (i < n && A[i] < A[i - 1]) {
    i++;
  }

  if (i == n) {
    result.push_back(-1);
    return result;
  }

  int j = n - 2;
  while (j > -1 && A[j] > A[j + 1]) {
    j--;
  }

  result = {i - 1, j + 1};
  return result;
}
