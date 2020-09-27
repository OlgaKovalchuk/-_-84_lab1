#include <iostream>
#include <string>

using namespace std;


int Max(int a, int b)
{
	int c;
	if (a > b)
	{
		c = a;
	}
	else {
		c = b;
	}
	return c;
}

int Min(int a, int b)
{
	int c;
	if (a > b)
	{
		c = b;
	}
	else {
		c = a;
	}
	return c;
}

int* LongAdd(int A[], int B[], int a_length, int b_length)
{
	int c = Max(a_length, b_length);
	int* Answer = new int[c];
	int i = c-1;
	for (int k = 0; k < c; k++)
	{
		Answer[k] = 0;
	}
	while (i != -1)
	{
		for (int j = 1; j < Min(a_length, b_length)+1; j++)
		{
			int temp = A[a_length - j] + B[b_length - j];
			if (temp > 15)
			{
				Answer[i + 1] = temp - (temp / 16) * 16;
				Answer[i] = (temp / 16);
			}
			else {
				Answer[i + 1] =Answer[i+1] + temp;
			}
			i--;
		}
	}
	if (a_length != b_length)
	{
		for (i == Min(a_length, b_length) + 1; i < Max(a_length, b_length) + 1; i++)
		{
			if (Max(a_length, b_length) == a_length)
			{
				Answer[i] = A[a_length - i];
			}
			if (Max(a_length, b_length) == b_length) {
				Answer[i] = B[b_length - i];
			}
		}
	}
	if (Answer[1] > 15)
	{
		if (Max(a_length, b_length) == a_length)
		{
			Answer[0] = A[0]/16;
		}
		if (Max(a_length, b_length) == b_length)
		{
			Answer[0] = B[0] / 16;
		}
		else {
			Answer[0] = (A[0]+B[0])/16;
		}
	}
	for (int i = 0; i < c+1; i++)
	{
		std::cout << Answer[i] << "  ";
	}
	cout << endl;
	return Answer;
}


int main()
{
	setlocale(LC_ALL, "ru_RU");
	string a;
	string b;
	int i;
	int a_length;
	int b_length;
	int A[30];
	int B[30];
	int *Answer;
	int* integ_A = A;
	int* integ_B = B;
	cout << "Число а:" << endl;
	cin >> a;
	cout << "Число b:" << endl;
	cin >> b;
	a_length = a.length();
	b_length = b.length();
	for (i = 0; i<a_length; i++)
	{
		if (isdigit(a.at(i)) == 0)
		{
			A[i] = a.at(i) - '0' - 7;
		}
		else {
			A[i] = a.at(i) - '0';
		}
	}
	for (i = 0; i < b_length; i++)
	{
		if (isdigit(b.at(i)) == 0)
		{
			B[i] = b.at(i) - '0' - 7;
		}
		else {
			B[i] = b.at(i) - '0';
		}
	}
	for (i = 0; i < a_length; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	for (i = 0; i < b_length; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;
	Answer = LongAdd(integ_A, integ_B, a_length, b_length);
	string Answer1;
	for (i = 0; i < Max(a_length, b_length) + 1; i++)
	{
		if (Answer[i] == 10)
		{
			Answer1 += "A";
		}
		if (Answer[i] == 11)
		{
			Answer1 += "B";
		}
		if (Answer[i] == 12)
		{
			Answer1 += "C";
		}
		if (Answer[i] == 13)
		{
			Answer1 += "D";
		}
		if (Answer[i] == 14)
		{
			Answer1 += "E";
		}
		if (Answer[i] == 15)
		{
			Answer1 += "F";
		}
		else {
			Answer1 += Answer[i];
		}
	}
	cout << Answer1[i];
	/*string Answer1;
	for (i = 0; i < Max(a_length, b_length)+1; i++)
	{
		Answer1.at(i) = Answer[i] + '0';
	}
	std::cout << Answer1;*/
	return 0;
}