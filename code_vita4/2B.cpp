/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 27 August 2015 (Thursday) 17:01
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ld long double
ld inverse[100][100];
ld determinant(ld [][100], ld);
void cofactor(ld [][100], ld);
void transpose(ld [][100], ld [][100], ld);
int main()
{
	ld a[100][100], d , s[100];
	int k;
	cin>>k;
	for(int i = 0 ; i < k ; i++){
		for(int j = 0 ; j < k ; j++){
			cin>>a[i][j];
		}
		cin>>s[i];
	}
	d = determinant(a, k);
	if (d == 0.0){
		printf("Unsolvable\n");
		return 0;
	}
	else{
		cofactor(a, k);
		for(int i = 0 ; i < k ; i++){
			ld ans = 0;
			for(int j = 0 ; j < k ; j++){
				ans += inverse[i][j]*s[j];
			}
			printf("%.2LF\n" , ans);
		}
	}
	return 0;
}
 
/*For calculating Determinant of the Matrix */
ld determinant(ld a[100][100], ld k)
{
	ld s = 1, det = 0, b[100][100];
	int i, j, m, n, c;
	if (k == 1)
	{
		return (a[0][0]);
	}
	else
	{
		det = 0;
		for (c = 0; c < k; c++)
		{
			m = 0;
			n = 0;
			for (i = 0;i < k; i++)
			{
				for (j = 0 ;j < k; j++)
				{
					b[i][j] = 0;
					if (i != 0 && j != c)
					{
						b[m][n] = a[i][j];
						if (n < (k - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			det = det + s * (a[0][c] * determinant(b, k - 1));
			s = -1 * s;
		}
	}
	return (det);
}
 
void cofactor(ld num[100][100], ld f)
{
	ld b[100][100], fac[100][100];
	int p, q, m, n, i, j;
	for (q = 0;q < f; q++)
	{
		for (p = 0;p < f; p++)
		{
			m = 0;
			n = 0;
			for (i = 0;i < f; i++)
			{
				for (j = 0;j < f; j++)
				{
					if (i != q && j != p)
					{
						b[m][n] = num[i][j];
						if (n < (f - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
		}
	}
	transpose(num, fac, f);
}
/*Finding transpose of matrix*/ 
void transpose(ld num[100][100], ld fac[100][100], ld r)
{
	int i, j;
	ld b[100][100], d;
 
	for (i = 0;i < r; i++)
	{
		for (j = 0;j < r; j++)
		{
			b[i][j] = fac[j][i];
		}
	}
	d = determinant(num, r);
	for (i = 0;i < r; i++)
	{
		for (j = 0;j < r; j++)
		{
			inverse[i][j] = b[i][j] / d;
		}
	}
	// printf("\n\n\nThe inverse of matrix is : \n");
 
	// for (i = 0;i < r; i++)
	// {
	// 	for (j = 0;j < r; j++)
	// 	{
	// 		printf("\t%f", inverse[i][j]);
	// 	}
	// 	printf("\n");
	// }
}