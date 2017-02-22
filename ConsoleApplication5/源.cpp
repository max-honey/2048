#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>

#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<vector>

#include<iostream>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<stdlib.h>


using namespace std;
int a[4][4];
void left();
void right();
void up();
void down();
void judge(int m, int n);
int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			scanf("%d", &a[i][j]);
	}
	char  str[100];
	memset(str, '\0', 100);
	int t = 0, m, n;
	cin.get();
	cin.getline(str, 100);
	char b;
	while (str[t] != '\0')
	{
		b = str[t]; t += 2;
		if (str[t + 1] != ' ') 
		{ 
			m = 10 + str[t + 1] -48; n =str[t+3]- 48; t += 5;
			
		}
		else if (str[t + 1] == ' ') 
		{ 
			m = str[t] - 48; n =str[t + 2] - 48; t += 4; 
		}
		if (b== 'a') 
		{ 
			left();
			judge(m, n);
		}
		if (b == 's') 
		{ 
			down();
			judge(m, n);
		}
		if (b == 'w')
		{ 
			up();
			judge(m, n);
		}
		if (b == 'd')
		{ 
			right(); 
			judge(m, n);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			cout<<a[i][j]<<" ";
	}

	cout << a[3][0] << " " << a[3][1] << " " << a[3][2] << " "<<a[3][3] << endl;
	system("pause");
	return 0;

}
void left()
{
		for (int i = 0; i < 4; i++)
		{
			int j = 0, k = 0; k = j;
			while (j <= 3)
			{
				if (a[i][j] != 0) {
					a[i][k] = a[i][j]; k++; j++;
				}
				else j++;
			}
			for (k; k < 4; k++)a[i][k] = 0;
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (a[i][j] == a[i][j + 1]) { a[i][j] += a[i][j+ 1]; a[i][j + 1] = 0; }
				else;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int j = 0, k = 0; k = j;
			while (j <= 3)
			{
				if (a[i][j] != 0) {
					a[i][k] = a[i][j]; k++; j++;
				}
				else j++;
			}
			for (k; k < 4; k++)a[i][k] = 0;
		}
}
void right()
{
	for (int i =0; i<4; i++)
	{
		int j = 3, k = 3; k = j;
		while (j >=0)
		{
			if (a[i][j] != 0) {
				a[i][k] = a[i][j]; k--; j--;
			}
			else j--;
		}
		for (k; k >=0; k--)a[i][k] = 0;
	}
	for (int i = 0; i<4; i++)
	{
		for (int j =3; j >=1; j--)
		{
			if (a[i][j] == a[i][j - 1]) { a[i][j] += a[i][j -1]; a[i][j -1] = 0; }
			else;
		}
	}
	for (int i = 0; i<4; i++)
	{
		int j = 3, k = 3; k = j;
		while (j >= 0)
		{
			if (a[i][j] != 0) {
				a[i][k] = a[i][j]; k--; j--;
			}
			else j--;
		}
		for (k; k >= 0; k--)a[i][k] = 0;
	}
}
void up()
{
	for (int j = 0; j<4; j++)
	{
		int i = 0, k = 0; k = i;
		while (i <=3)
		{
			if (a[i][j] != 0) {
				a[k][j] = a[i][j]; k++; i++;
			}
			else i++;
		}
		for (k; k <4; k++)a[k][j] = 0;
	}
	for (int j = 0; j<4; j++)
	{
		for (int i = 0; i<4; i++)
		{
			if (a[i][j] == a[i+1][j]) { a[i][j] += a[i+1][j]; a[i+1][j] = 0; }
			else;
		}
	}
	for (int j = 0; j<4; j++)
	{
		int i = 0, k = 0; k = i;
		while (i <= 3)
		{
			if (a[i][j] != 0) {
				a[k][j] = a[i][j]; k++; i++;
			}
			else i++;
		}
		for (k; k <4; k++)a[k][j] = 0;
	}
}
void down()
{
	for (int j = 0; j<4; j++)
	{
		int i = 3, k = 3; k = i;
		while (i >=0)
		{
			if (a[i][j] != 0) {
				a[k][j] = a[i][j]; k--; i--;
			}
			else i--;
		}
		for (k; k >=0; k--)a[k][j] = 0;
	}
	for (int j = 0; j<4; j++)
	{
		for (int i = 3; i>0; i--)
		{
			if (a[i][j] == a[i -1][j]) { a[i][j] += a[i - 1][j]; a[i - 1][j] = 0; }
			else;
		}
	}
	for (int j = 0; j<4; j++)
	{
		int i = 3, k = 3; k = i;
		while (i >= 0)
		{
			if (a[i][j] != 0) {
				a[k][j] = a[i][j]; k--; i--;
			}
			else i--;
		}
		for (k; k >= 0; k--)a[k][j] = 0;
	}
}
void judge(int m,int n)
{
	int i = 0, j = 0;
	while (1)
	{
		if (m == 4 || m == 8 || m == 12 || m == 16)
		{
			i = (m - 1) / 4;
			j = 3;
		}
		else
		{   
			i = m / 4;
			j = m % 4 - 1;
		}
		if (a[i][j] != 0) { m = m % 16 + 1; }
		if (a[i][j] == 0)break;
	}
	a[i][j] = n;
	//fdfdfd
}