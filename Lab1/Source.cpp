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
	int* Answer = new int[c + 2];
	int i = c - 1;
	for (int k = 0; k < c + 2; k++)
	{
		Answer[k] = 0;
	}
	while (i != Max(a_length, b_length) - Min(a_length, b_length) - 1 && a_length != b_length)
	{
		for (int j = 1; j < Min(a_length, b_length) + 1; j++)
		{
			int temp = A[a_length - j] + B[b_length - j];
			if (temp > 15)
			{
				Answer[i] = Answer[i] + temp - (temp / 16) * 16;
				Answer[i - 1] = Answer[i - 1] + (temp / 16);
			}
			else {
				Answer[i] = Answer[i] + temp;
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
			}
			if (Max(a_length, b_length) == b_length) {
				Answer[c - i - 1] = Answer[c - i - 1] + B[b_length - i - 1];
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
			}
			else if (Answer[c - i] + temp > 15)
			{
				Answer[c - i - 1] = ((Answer[c - i] + temp) / 16);
				Answer[c - i] = (Answer[c - i] + temp) - ((Answer[c - i] + temp) / 16) * 16;
			}
			else {
				Answer[c - i] = Answer[c - i] + temp;
			}
		}
		Answer[0] = Answer[0] + A[0] + B[0];
	}
	if (Answer[0] > 15)
	{
		for (i = c; i > 0; i--)
		{
			Answer[i] = Answer[i - 1];
		}
		Answer[1] = Answer[1] - ((Answer[1]) / 16) * 16;
		Answer[0] = Answer[0] / 16;
		Answer[c + 1] = 100;
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

int* LongSub(int A[], int B[], int a_length, int b_length)
{
	int c = Max(a_length, b_length);
	int borrow = 0;
	int* Answer = new int[c + 1];
	int i = c - 1;
	for (int k = 0; k < c + 1; k++)
	{
		Answer[k] = 0;
	}
	while (i != Max(a_length, b_length) - Min(a_length, b_length) - 1 && a_length != b_length)
	{
		for (int j = 1; j < Min(a_length, b_length) + 1; j++)
		{
			int temp = A[a_length - j] - B[b_length - j];
			if (temp < 0)
			{
				borrow++;
				A[a_length - j] = A[a_length - j] + 15;
				if (A[a_length - j - 1] == 0)
				{
					int k = 1;
					while (A[a_length - j - 1 - k] == 0)
					{
						A[a_length - j - 1 - k] = A[a_length - j - 1 - k] - 1;
						if (A[a_length - j - 1 - k] < 0)
						{
							k++;
							A[a_length - j - 1 - k] = A[a_length - j - 1 - k] - 1;
							A[a_length - j - k] = A[a_length - j - k] + 15;
						}
						else {
							A[a_length - j - k] = A[a_length - j - k] + 15;
							break;
						}
					}
				}
				A[a_length - j - 1] = A[a_length - j - 1] - 1;
				temp = A[a_length - j] - B[b_length - j];
				Answer[i] = Answer[i] + temp;
				borrow--;
			}
			else {
				Answer[i] = Answer[i] + temp;
			}
			i--;
		}
	}
	if (a_length != b_length)
	{
		for (i = Min(a_length, b_length); i < Max(a_length, b_length); i++)
		{
			Answer[c - i - 1] = Answer[c - i - 1] + A[a_length - i - 1];
		}

	}
	else if (a_length = b_length)
	{
		for (i = 1; i < a_length; i++)
		{
			int temp = A[a_length - i] - B[b_length - i];
			if (temp < 0)
			{
				borrow++;
				A[a_length - i] = A[a_length - i] + 15;
				A[a_length - i - 1] = A[a_length - i - 1] - 1;
				temp = A[a_length - i] - B[b_length - i];
				Answer[c - i] = Answer[c - i] + temp;
				borrow--;
			}
			else {
				Answer[c - i] = Answer[c - i] + temp;
			}
		}
		Answer[0] = Answer[0] + A[0] - B[0];
	}
	if (Answer[0] < 0)
	{
		borrow++;
		Answer[c] = borrow;
	}
	else {
		cout << "Ответ:" << endl;
		for (int i = 0; i < c; i++)
		{
			cout << Answer[i] << "  ";
		}
	}
	cout << endl;
	return Answer;
}

int* LongMulOneDigit(int A[], int digit_from_str, int a_length)
{
	int c = a_length;
	int* Answer = new int[c + 1];
	for (int k = 0; k < c + 1; k++)
	{
		Answer[k] = 0;
	}
	for (int j = c - 1; j > 0; j--)
	{
		int temp = A[j] * digit_from_str;
		if (temp > 15)
		{
			Answer[j] = Answer[j] + temp - (temp / 16) * 16;
			Answer[j - 1] = Answer[j - 1] + (temp / 16);
		}
		else {
			Answer[j] = Answer[j] + temp;
			if (Answer[j] > 15)
			{
				Answer[j] = Answer[j] - (Answer[j] / 16) * 16;
				Answer[j - 1] = Answer[j - 1] + (Answer[j] / 16);
			}
		}
	}
	Answer[0] = Answer[0] + A[0] * digit_from_str;
	if(Answer[0] > 15)
	{
		for (int i = c; i > 0; i--)
		{
			Answer[i] = Answer[i - 1];
		}
		Answer[1] = Answer[1] - ((Answer[1]) / 16) * 16;
		Answer[0] = Answer[0] / 16;
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

/*int* LongMul(int A[], int B[], int a_length, int b_length)
{
	int c = Max(a_length, b_length);
	int* Answer = new int[2*c];
	int i = 2*c - 1;
	int* temp1;
	int* temp2;
	for (int k = 0; k < 2*c + 1; k++)
	{
		Answer[k] = 0;
	}
	for (int i = 1; i < c + 1; i++)
	{
		temp1 = LongMulOneDigit(A, B[b_length - i], a_length);
		Answer[2 * c - i] = Answer[2*c - i] + temp1[i - 1];
		temp2 = LongMulOneDigit(A, B[b_length - i -1], a_length);
		Answer[2 * c - i - 1] = Answer[2 * c - i - 1] + temp2[i - 1];
	}
	return Answer;
}*/

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
	int* AnswerAdd;
	int* AnswerSub;
	int* AnswerMulOneDigit;
	int* integ_A = A;
	int* integ_B = B;
	cout << "Число а:" << endl;
	cin >> a;
	cout << "Число b:" << endl;
	cin >> b;
	a_length = a.length();
	b_length = b.length();
	for (i = 0; i < a_length; i++)
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
	AnswerAdd = LongAdd(integ_A, integ_B, a_length, b_length);
	string Answer1;
	if (AnswerAdd[Max(a_length, b_length) + 1] == 100)
	{
		for (i = 0; i < Max(a_length, b_length) + 1; i++)
		{
			if (AnswerAdd[i] == 10)
			{
				Answer1 = Answer1 + "A";
			}
			else if (AnswerAdd[i] == 11)
			{
				Answer1 = Answer1 + "B";
			}
			else if (AnswerAdd[i] == 12)
			{
				Answer1 = Answer1 + "C";
			}
			else if (AnswerAdd[i] == 13)
			{
				Answer1 = Answer1 + "D";
			}
			else if (AnswerAdd[i] == 14)
			{
				Answer1 = Answer1 + "E";
			}
			else if (AnswerAdd[i] == 15)
			{
				Answer1 = Answer1 + "F";
			}
			else if (AnswerAdd[i] < 10) {
				Answer1 += to_string(AnswerAdd[i]);
			}
		}
	}
	else if (AnswerAdd[Max(a_length, b_length) + 1] == 0)
	{
		for (i = 0; i < Max(a_length, b_length); i++)
		{
			if (AnswerAdd[i] == 10)
			{
				Answer1 = Answer1 + "A";
			}
			else if (AnswerAdd[i] == 11)
			{
				Answer1 = Answer1 + "B";
			}
			else if (AnswerAdd[i] == 12)
			{
				Answer1 = Answer1 + "C";
			}
			else if (AnswerAdd[i] == 13)
			{
				Answer1 = Answer1 + "D";
			}
			else if (AnswerAdd[i] == 14)
			{
				Answer1 = Answer1 + "E";
			}
			else if (AnswerAdd[i] == 15)
			{
				Answer1 = Answer1 + "F";
			}
			else if (AnswerAdd[i] < 10) {
				Answer1 += to_string(AnswerAdd[i]);
			}
		}
	}
	cout << "Результат А + В в 16-чной системе исчисления:" << endl;
	cout << Answer1;
	cout << endl;
	delete[] AnswerAdd;
	cout << endl;
	string digit;
	cout << "Умножение числа А на константу" << endl;
	cout << "Введите значение константы:" << endl;
	cin >> digit;
	int digit_from_str;
	if (isdigit(digit.at(0)) == 0)
	{
		digit_from_str = digit.at(0) - '0' - 7;
	}
	else {
		digit_from_str = digit.at(0) - '0';
	}
	cout << "Наша константа в 16-чной системе исчисления:" << endl;
	cout << digit_from_str << endl;
	AnswerMulOneDigit = LongMulOneDigit(integ_A, digit_from_str, a_length);
	string Answer3;
	for (i = 0; i < a_length + 1; i++)
	{
		if (AnswerMulOneDigit[i] == 10)
		{
			Answer3 = Answer3 + "A";
		}
		else if (AnswerMulOneDigit[i] == 11)
		{
			Answer3 = Answer3 + "B";
		}
		else if (AnswerMulOneDigit[i] == 12)
		{
			Answer3 = Answer3 + "C";
		}
		else if (AnswerMulOneDigit[i] == 13)
		{
			Answer3 = Answer3 + "D";
		}
		else if (AnswerMulOneDigit[i] == 14)
		{
			Answer3 = Answer3 + "E";
		}
		else if (AnswerMulOneDigit[i] == 15)
		{
			Answer3 = Answer3 + "F";
		}
		else if (AnswerMulOneDigit[i] < 10) {
			Answer3 += to_string(AnswerMulOneDigit[i]);
		}
	}
	cout << "Результат (число) А * (константа) " <<digit<<" в 16-чной системе исчисления:" << endl;
	cout << Answer3 <<endl;
	delete[]AnswerMulOneDigit;
	cout << endl;
	//int* AnswerLongMul;
	//AnswerLongMul = LongMul(integ_A, integ_B, a_length, b_length);
	cout << "Отнимаем число В от числа А" << endl;
	string Answer2;
	if (a_length < b_length)
	{
		Answer2 = "Ошибка!!! От числа меньшей длины отнимаем число большей длины!";
		cout << Answer2 << endl;
	}
	else {
		AnswerSub = LongSub(integ_A, integ_B, a_length, b_length);
		if (AnswerSub[Max(a_length, b_length)] == 1)
		{
			Answer2 = "Отрицательное значение!!! ";
		}
		else {
			for (i = 0; i < Max(a_length, b_length); i++)
			{
				if (AnswerSub[i] == 10)
				{
					Answer2 = Answer2 + "A";
				}
				else if (AnswerSub[i] == 11)
				{
					Answer2 = Answer2 + "B";
				}
				else if (AnswerSub[i] == 12)
				{
					Answer2 = Answer2 + "C";
				}
				else if (AnswerSub[i] == 13)
				{
					Answer2 = Answer2 + "D";
				}
				else if (AnswerSub[i] == 14)
				{
					Answer2 = Answer2 + "E";
				}
				else if (AnswerSub[i] == 15)
				{
					Answer2 = Answer2 + "F";
				}
				else if (AnswerSub[i] < 10) {
					Answer2 += to_string(AnswerSub[i]);
				}
			}
		}
		cout << "Результат А - В в 16-чной системе исчисления:" << endl;
		cout << Answer2 << endl;
		delete[] AnswerSub;
	}
	return 0;
}
