#include <bits/stdc++.h>
using namespace std;

void setMatrixZeros(vector < vector < int > > &mat) {
	int rows = mat.size();
	int cols = mat[0].size();
	vector < int > colMask(rows, 1);
	vector < int > rowMask(cols, 1);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			rowMask[j] *= mat[i][j];
		}
	}

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			colMask[j] *= mat[j][i];
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			mat[i][j] *= rowMask[j];
		}
	}

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			 mat[j][i] *= colMask[j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	while (test--) {
		int rows;
		int cols;
		cin>>rows>>cols;
		vector < vector < int > >mat(rows, vector < int >(cols, 0));
		for (int i = 0; i < rows; i++) { 
			for (int j = 0; j < cols; j++) {
				cin>>mat[i][j];
			}
		}
		setMatrixZeros(mat);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}