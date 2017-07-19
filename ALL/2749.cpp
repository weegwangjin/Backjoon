#include<iostream>
typedef unsigned long long ULONG; 
using namespace std;
typedef struct Matrix2
{
	ULONG f[2][2];
}Matrix2;

Matrix2 mulitply(Matrix2 A, Matrix2 B)
{
	Matrix2 C;
	C.f[0][0] = (A.f[0][0] * B.f[0][0] + A.f[0][1] * B.f[1][0])%1000000;
	C.f[0][1] = (A.f[0][0] * B.f[0][1] + A.f[0][1] * B.f[1][1])%1000000;
	C.f[1][0] = (A.f[1][0] * B.f[0][0] + A.f[1][1] * B.f[1][0])%1000000;
	C.f[1][1] = (A.f[1][0] * B.f[0][1] + A.f[1][1] * B.f[1][1])%1000000;

	return C;
}
Matrix2 Matrix_Power(Matrix2 A, ULONG n)
{
	if (n > 1)
	{
		A = Matrix_Power(A, n / 2);
		A = mulitply(A, A);

		if (n & 1)
		{
			Matrix2  F1 = { 1,1,1,0 };
			A = mulitply(A, F1);
		}
	}
	return A;
}

int main()
{
	ULONG n;
	cin >> n;
	Matrix2  F1 = { 1,1,1,0 };
	F1 = Matrix_Power(F1, n);
	cout << F1.f[0][1] << endl;

}
