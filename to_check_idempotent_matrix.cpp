// Program to check given matrix 
// is idempotent matrix or not.
#include<bits/stdc++.h>
#define N 3
using namespace std;

// Function for matrix multiplication.
void multiply(int mat[][N], int res[][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < N; k++)
				res[i][j] += mat[i][k] * mat[k][j];
		}
	}
}

// Function to check idempotent
// property of matrix.
bool checkIdempotent(int mat[][N])
{ 
	// Calculate multiplication of matrix
	// with itself and store it into res.
	int res[N][N];
	multiply(mat, res);

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)	 
			if (mat[i][j] != res[i][j])
				return false;
	return true;
}

// Driver function.
int main()
{
	int mat[N][N] = {{2, -2, -4},
					{-1, 3, 4},
					{1, -2, -3}};
	
	// checkIdempotent function call.
	if (checkIdempotent(mat))
		cout << "Idempotent Matrix";
	else
		cout << "Not Idempotent Matrix.";
	return 0;
}
