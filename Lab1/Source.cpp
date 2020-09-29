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
	int* Answer = new int[c+1];
	int i = c-1;
	for (int k = 0; k < c; k++)
	{
		Answer[k] = 0;
	}
	while (i != Max(a_length, b_length) - Min(a_length, b_length) - 1 && a_length != b_length)
	{
		for (int j = 1; j < Min(a_length, b_length)+1; j++)
		{
			int temp = A[a_length - j] + B[b_length - j];
			if (temp > 15)
			{
				Answer[i] = Answer[i] + temp - (temp / 16) * 16;
				Answer[i - 1] = Answer[i - 1] + (temp / 16);
				//cout << "Это из цикла while, if" << endl;
				//cout << "Answer[" << i << "] = " << Answer[i] << endl;
				//cout << "Answer[" << i - 1 << "] = " << Answer[i - 1] << endl;
				//cout << endl;
			}
			/*else if (Answer[c - i] + temp > 15)
			{
				Answer[c - i - 1] = ((Answer[c - i] + temp) / 16);
				Answer[c - i] = (Answer[c - i] + temp) - ((Answer[c - i] + temp) / 16) * 16;
			}*/
			else {
				Answer[i] =Answer[i] + temp;
				//cout << "Это из цикла while, else" << endl;
				//cout << "Answer[" << i << "] = " << Answer[i] << endl;
				//cout << endl;
			}
			i--;
		}
	}
	if (a_length != b_length)
	{
		for (i = Min(a_length, b_length); i < Max(a_length, b_length); i++)
		{
			if (Max(a_length, b_length) == a_length)
			{
				Answer[c - i - 1] = Answer[c - i - 1] + A[a_length - i - 1];
				//cout << "Это из if, когда разной длины числа, А>В:" << endl;
				//cout << "Answer[" << c - i - 1 << "] = " << Answer[c - i - 1] << endl;
				//cout << endl;
			}
			if (Max(a_length, b_length) == b_length) {
				Answer[c - i - 1] = Answer[c - i - 1] + B[b_length - i - 1];
				//cout << "Это из if, когда разной длины числа, А<В:" << endl;
				//cout << "Answer[" << c - i - 1 << "] = " << Answer[c - i - 1] << endl;
				//cout << endl;
			}
		}

	}
	else if (a_length = b_length)
	{
		for (i = 1; i < a_length; i++)
		{
			int temp = A[a_length - i] + B[b_length - i];
			if (temp > 15)
			{
				Answer[c - i] = Answer[c - i] + (temp - (temp / 16) * 16);
				Answer[c - i - 1] = Answer[c - i - 1] + (temp / 16);
				//cout << "Это из else if, когда одинаковой длины числа, if:" << endl;
				//cout << "Answer[" << c - i << "] = " << Answer[c - i] << endl;
				//cout << "Answer[" << c - i - 1 << "] = " << Answer[c - i - 1] << endl;
				//cout << endl;
			}
			else if (Answer[c - i] + temp > 15)
			{
				Answer[c - i - 1] = ((Answer[c - i] + temp) / 16);
				Answer[c - i] = (Answer[c-i] +temp) - ((Answer[c-i] + temp) / 16) * 16;
				//cout << "Это из else if, когда одинаковой длины числа, else if:" << endl;
				//cout << "Answer[" << c - i - 1 << "] = " << Answer[c - i - 1] << endl;
				//cout << "Answer[" << c - i << "] = " << Answer[c - i] << endl;
				//cout << endl;
			}
			else {
				Answer[c-i] = Answer[c-i] + temp;
				//cout << "Это из else if, когда одинаковой длины числа, else:" << endl;
				//cout << "Answer[" << c - i << "] = " << Answer[c - i] << endl;
				//cout << endl;
			}
		}
		Answer[0] = Answer[0] + A[0] + B[0];
		//cout << "Это из else if, когда одинаковой длины числа:" << endl;
		//cout << "Answer[" << 0 << "] = " << Answer[0] << endl;
		//cout << endl;
	}
	if (Answer[0] > 15)
	{
		for (i = c; i >0; i--)
		{
			Answer[i] = Answer[i - 1];
		}
		Answer[1] = Answer[1]- ((Answer[1]) / 16) * 16;
		Answer[0] = Answer[0]/16;
		cout << "Ответ:" << endl;
		for (int i = 0; i < c + 1; i++)
		{
			cout << Answer[i] << "  ";
		}
	}
	else if (Answer[0] < 16)
	{
		cout << "Ответ:" << endl;
		for (int i = 0; i < c; i++)
		{
			cout << Answer[i] << "  ";
		}
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
	int A[1000];
	int B[1000];
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
			Answer1 = Answer1 + "A";
		}
		else if (Answer[i] == 11)
		{
			Answer1 = Answer1 + "B";
		}
		else if (Answer[i] == 12)
		{
			Answer1 = Answer1 + "C";
		}
		else if (Answer[i] == 13)
		{
			Answer1 = Answer1 + "D";
		}
		else if (Answer[i] == 14)
		{
			Answer1 = Answer1 + "E";
		}
		else if (Answer[i] == 15)
		{
			Answer1 = Answer1 + "F";
		}
		else if (Answer[i]<10){
			Answer1 += to_string(Answer[i]);
		}
	}
	cout << "Ответ в 16-чной системе исчисления:" << endl;
	cout << Answer1;
	cout << endl;
	delete [] Answer;
	//int A[1000] = {0};
	//int B[1000] = {0};
	return 0;
}
