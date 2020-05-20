#include<bits/stdc++.h>

using namespace std;

void flood_fill(int x, int y, int k, int old,int rows, int cols, vector < vector < int > > &mat) 
{
	if ((x >= rows || y >= cols || x < 0 || y < 0 || mat[x][y] != old)) return;

	mat[x][y] = k;

	//if (y + 1 < cols && mat[x][y + 1] == old) {
		flood_fill(x, y + 1, k, old, rows, cols, mat);
	//}

	//if (x + 1 < rows && mat[x + 1][y] == old) {
		flood_fill(x + 1, y, k, old, rows, cols, mat);
	//}

	//if (y - 1 > -1 && mat[x][y - 1] == old) {
		flood_fill(x, y - 1, k , old, rows, cols, mat);
	//}

	//if (x - 1 > -1 && mat[x - 1][y] == old) {
	       flood_fill(x - 1, y, k, old, rows, cols, mat);
	//}	       
		
}

int main() 
{
	int test;
	cin>>test;
	while (test > 0) {
		int rows;
		int cols;
		cin>>rows>>cols;
		vector < vector < int > >mat(rows, vector < int >(cols, 0));
		
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cin>>mat[i][j];
			}
		}

		/*
		for (auto x : mat) {
			for (auto y : x) {
				printf("%3d", y);
			}
			printf("\n");
		}
		*/

		int x, y, k;
		cin>>x>>y>>k;
		
		flood_fill(x, y, k, mat[x][y], rows, cols, mat);

		for (auto x : mat) {
			for (auto y : x) {
				printf("%3d", y);
			}
			//printf("\n");
		}
	
		test--;
	}
}
