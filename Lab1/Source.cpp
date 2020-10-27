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
		/*cout << "Ответ (Результат суммирования двух чисел):" << endl;
		for (int i = 0; i < c + 1; i++)
		{
			cout << Answer[i] << "  ";
		}*/
	}
	/*else if (Answer[0] < 16)
	{
		cout << "Ответ (Результат сумирования двух чисел):" << endl;
		for (int i = 0; i < c; i++)
		{
			cout << Answer[i] << "  ";
		}
	}
	cout << endl;*/
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
		/*cout << "Ответ (Результат разницы двух чисел):" << endl;
		for (int i = 0; i < c; i++)
		{
			cout << Answer[i] << "  ";
		}*/
	}
	cout << endl;
	return Answer;
}

int* LongMulOneDigit(int A[], int digit_from_str, int a_length)
{
	int c = a_length;
	int* Answer = new int[c + 2];
	for (int k = 0; k < c + 2; k++)
	{
		Answer[k] = 0;
	}
	for (int j = c - 1; j > 0; j--)
	{
		int temp = A[j] * digit_from_str;
		if (temp > 15)
		{
			Answer[j - 1] = Answer[j - 1] + ((Answer[j] + temp) / 16);
			Answer[j] = Answer[j] + temp - ((Answer[j] + temp) / 16) * 16;
		}
		else {
			Answer[j] = Answer[j] + temp;
			if (Answer[j] > 15)
			{
				Answer[j - 1] = Answer[j - 1] + (Answer[j] / 16);
				Answer[j] = Answer[j] - (Answer[j] / 16) * 16;
			}
		}
	}
	Answer[0] = Answer[0] + A[0] * digit_from_str;
	if(Answer[0] > 15)
	{
		Answer[c + 1] = 17;
		for (int i = c; i > 0; i--)
		{
			Answer[i] = Answer[i - 1];
		}
		Answer[1] = Answer[1] - ((Answer[1]) / 16) * 16;
		Answer[0] = Answer[0] / 16;
		/*cout << "Ответ (Результат умножения числа А на " <<digit_from_str<<" ):"<< endl;
		for (int i = 0; i < c + 1; i++)
		{
			cout << Answer[i] << "  ";
		}*/
	}
	else if (Answer[0] < 16)
	{
		/*cout << "Ответ (Результат умножения числа А на " << digit_from_str << " ):" << endl;
		for (int i = 0; i < c; i++)
		{
			cout << Answer[i] << "  ";
		}*/
	}
	cout << endl;
	return Answer;
}

int* LongMul(int A[], int B[], int a_length, int b_length)
{
	int c = Max(a_length, b_length);
	int* Answer1 = new int[2*c];
	int* Answer2 = new int[2 * c];
	int* Answer3 = new int[2 * c];
	int i = 2*c - 1;
	int* temp1;
	int* temp2;
	for (int k = 0; k < 2*c; k++)
	{
		Answer1[k] = 0;
		Answer2[k] = 0;
		Answer3[k] = 0;
	}
	temp1 = LongMulOneDigit(A, B[b_length - 1], a_length);
	if (temp1[c+1] == 0) {
		for (int i = 1; i < c+1; i++)
		{
			Answer1[2 * c - i] = Answer1[2 * c - i] + temp1[c - i];
			//cout << "Answer1 [" << 2 * c - i << "] = " << Answer1[2 * c - i] << endl;
		}
	}
	else if(temp1[c+1] == 17){
		for (int i = 1; i < c + 2; i++)
		{
			Answer1[2 * c - i] = Answer1[2 * c - i] + temp1[c - i + 1];
			//cout << "Answer1 [" << 2 * c - i << "] = " << Answer1[2 * c - i] << endl;
		}
	}
	/*for (int i = 1; i < c + 2; i++)
	{
		Answer1[2 * c - i] = Answer1[2 * c - i] + temp1[c - i + 1];
		cout << "Answer1 [" << 2 * c - i << "] = " << Answer1[2 * c - i] << endl;
	}*/
	if (b_length > 1)
	{
		for (int j = 1; j < b_length; j++)
		{
			temp2 = LongMulOneDigit(A, B[b_length - j - 1], a_length);
			if (temp2[c + 1] == 0)
			{
				for (int i = 1; i < c + 1; i++)
				{
					Answer2[2 * c - i - j] = Answer2[2 * c - i - j] + temp2[c - i];
				}
			}
			else if (temp2[c + 1] == 17) {
				for (int i = 1; i < c + 2; i++)
				{
					Answer2[2 * c - i - j] = Answer2[2 * c - i - j] + temp2[c - i + 1];
				}
			}
			/*cout << "Answer1:" << endl;
			for (int i = 0; i < 2 * c; i++)
			{
				cout << "Answer1[" <<i<<"] = " <<Answer1[i]<< endl;
			}
			cout << "Answer2:" << endl;
			for (int i = 0; i < 2 * c; i++)
			{
				cout << "Answer2[" << i << "] = " << Answer2[i] << endl;
			}*/
			Answer3 = LongAdd(Answer1, Answer2, 2 * c, 2 * c);
			for (int k = 0; k < 2 * c; k++)
			{
				Answer2[k] = 0;
				Answer1[k] = Answer3[k];
			}
			/*for (int k = 0; k < 2 * c; k++)
			{
				cout << "Answer1 [" << k << "] = " << Answer1[k] << "   " << "Answer3 [" << k << "] = " << Answer3[k] << endl;
			}*/
		}
	}
	else if (b_length == 1)
	{
		for (int k = 0; k < 2 * c; k++)
		{
			Answer3[k] = Answer1[k];
		}
		/*for (int k = 0; k < 2 * c; k++)
		{
			cout << "Answer1 [" << k << "] = " << Answer1[k] << "   " << "Answer3 [" << k << "] = " << Answer3[k] << endl;
		}*/
	}
	return Answer3;
}

int* PowerToSquare(int A[], int a_length)
{
	int c = a_length;
	int* Answer = new int[2 * c];
	for (int i = 0; i < 2 * c; i++)
	{
		Answer[i] = 0;
	}
	Answer = LongMul(A, A, a_length, a_length);
	/*cout << "Ответ (Вознесение числа в квадрат):" << endl;
	for (int i = 0; i < 2 * c; i++)
	{
		cout << Answer[i] << "  ";
	}*/
	return Answer;
}

int* ConvertStrToNumber(string a, int a_length)
{
	int* Answer = new int[a_length];
	for (int k = 0; k < a_length; k++)
	{
		Answer[k] = 0;
	}
	for (int i = 0; i < a_length; i++)
	{
		if (isdigit(a.at(i)) == 0)
		{
			Answer[i] = a.at(i) - '0' - 7;
		}
		else {
			Answer[i] = a.at(i) - '0';
		}
	}
	return Answer;
}

string ConvertNumberToStr(int A[], int size)
{
	string answer;
	for (int i = 0; i < size; i++)
	{
		if (A[i] == 10)
		{
			answer = answer + "A";
		}
		else if (A[i] == 11)
		{
			answer = answer + "B";
		}
		else if (A[i] == 12)
		{
			answer = answer + "C";
		}
		else if (A[i] == 13)
		{
			answer = answer + "D";
		}
		else if (A[i] == 14)
		{
			answer = answer + "E";
		}
		else if (A[i] == 15)
		{
			answer = answer + "F";
		}
		else if (A[i] < 10) {
			answer += to_string(A[i]);
		}
	}
	return answer;
}

int CompareNum(int A[], int B[], int a_length, int b_length)
{
	int answer;
	if (a_length > b_length)
	{
		answer = 1;
	}
	else if (a_length < b_length)
	{
		answer = 0;
	}
	else if (a_length == b_length)
	{
		if (A[0] < B[0])
		{
			answer = 0;  //Число А меньше числа В
		}
		else if (A[0] > B[0])
		{
			answer = 1;  //Число А больше числа В
		}
		else if (A[0] == B[0])
		{
			int i = 1;
			while ((A[i] == B[i]) && i != Max(a_length, b_length))
			{
				answer = 2;
				i++;
			}
			if (i == Max(a_length, b_length) && A[i] == B[i])
			{
				answer = 2;
			}
			else if (i != Max(a_length, b_length) && A[i] < B[i])
			{
				answer = 0;
			}
			else if (i != Max(a_length, b_length) && A[i] > B[i])
			{
				answer = 0;
			}
		}
	}
	return answer;
}

int* LongShiftBitsToHigh(int B[], int number_of_cells_shift, int b_length)
{
	int* NewB = new int[b_length + number_of_cells_shift];
	for (int k = 0; k < b_length + number_of_cells_shift; k++)
	{
		NewB[k] = 0;
	}
	for (int i = 0; i < b_length; i++)
	{
		NewB[i] = B[i];
	}
	return NewB;
}

int SizeOfArray(int A[])
{
	int size_limit = 1000;
	int size_of_array = 0;
	int i = 0;
	while ((A[i] == 0 || A[i] == 1 || A[i] == 2 || A[i] == 3 || A[i] == 4 || A[i] == 5 || A[i] == 6 || A[i] == 7 || A[i] == 8 || A[i] == 9 || A[i] == 10 || A[i] == 11 || A[i] == 12 || A[i] == 13 || A[i] == 14 || A[i] == 15)
		&& i <size_limit+1)
	{
		size_of_array++;
		i++;
	}
	return size_of_array;
}

int** LongDivModul(int A[], int B[], int a_length)
{
	int b_length = SizeOfArray(B);
	int *Answer[2];
	int** AnswerPointer = Answer;
	int Q[1] = { 1 };
	int* Q_pointer = Q;
	int* Ostacha = new int [a_length];
	int* Chastka = new int[a_length];
	int* Answer1;
	int* NewB;
	for (int i = 0; i < a_length; i++)
	{
		Chastka[i] = 0;
	}
	for (int i = 0; i < a_length ; i++)
	{
		Ostacha[i] = A[i];
	}
	while (CompareNum(Ostacha, B, a_length, b_length) == 1 || CompareNum(Ostacha, B, a_length, b_length) == 2)
	{
		int length_Ostacha = SizeOfArray(Ostacha);
		NewB = LongShiftBitsToHigh(B, length_Ostacha - b_length, b_length);
		b_length = SizeOfArray(NewB);
		if (CompareNum(Ostacha, NewB, length_Ostacha, b_length) == 0)
		{
			length_Ostacha--;
			NewB = LongShiftBitsToHigh(B, length_Ostacha - b_length, b_length);
		}
		Answer1 = LongSub(Ostacha, NewB, length_Ostacha, b_length);
		Ostacha = Answer1;
		Chastka = LongAdd(Chastka, Q, a_length, 1);
		Ostacha = Answer1;
	}
	Answer[0] = Chastka;
	Answer[1] = Ostacha;
	return AnswerPointer;
}

int* DvoichnaForma(int A[], int a_length)
{
	int* Dvoich_A = new int[4 * a_length];
	int ostacha;
	for (int i = 0; i < a_length; i++)
	{
		ostacha = A[i];
		Dvoich_A[4 * i + 3] = ostacha % 2;
		ostacha = ostacha / 2;
		Dvoich_A[4 * i + 2] = ostacha % 2;
		ostacha = ostacha / 2;
		Dvoich_A[4 * i + 1] = ostacha % 2;
		ostacha = ostacha / 2;
		Dvoich_A[4 * i] = ostacha % 2;
		ostacha = ostacha / 2;
	}
	return Dvoich_A;
}

int* LongPower(int A[], int B[], int a_length, int b_length)
{
	int* Answer = new int[a_length];
	Answer[0] = 1;
	for (int i = 1; i < a_length; i++)
	{
		Answer[i] = 0;
	}
	int* Dvoich_B = DvoichnaForma(B, b_length);
	for (int j = 0; j < 4 * b_length; j++)
	{
		Answer = PowerToSquare(Answer, a_length);
		if (Dvoich_B[j] == 1)
		{
			Answer = LongMul(Answer, A, a_length, a_length);
		}
		//Answer = PowerToSquare(Answer, a_length);
	}
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
	integ_A = ConvertStrToNumber(a, a_length);
	integ_B = ConvertStrToNumber(b, b_length);
	/*for (i = 0; i < a_length; i++)
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
	}*/
	cout << "Число А:" << endl;
	for (i = 0; i < a_length; i++)
	{
		cout << integ_A[i] << " ";
	}
	cout << endl;
	cout << "Число В:" << endl;
	for (i = 0; i < b_length; i++)
	{
		cout << integ_B[i] << " ";
	}
	cout << endl;
	/*int* AnswerDvoichFormA = DvoichnaForma(integ_A, a_length);
	int* AnswerDvoichFormB = DvoichnaForma(integ_B, b_length);
	cout << "Число А в двоичной форме: " << endl;
	for (int i = 0; i < 4 * a_length; i++)
	{
		cout << AnswerDvoichFormA[i] << "  ";
	}
	cout << endl;
	cout << "Число B в двоичной форме: " << endl;
	for (int i = 0; i < 4 * b_length; i++)
	{
		cout << AnswerDvoichFormB[i] << "  ";
	}
	cout << endl;*/
	AnswerAdd = LongAdd(integ_A, integ_B, a_length, b_length);
	string Answer1;
	if (AnswerAdd[Max(a_length, b_length) + 1] == 100)
	{
		Answer1 = ConvertNumberToStr(AnswerAdd, Max(a_length, b_length) + 1);
		/*for (i = 0; i < Max(a_length, b_length) + 1; i++)
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
		}*/
	}
	else if (AnswerAdd[Max(a_length, b_length) + 1] == 0)
	{
		Answer1 = ConvertNumberToStr(AnswerAdd, Max(a_length, b_length));
		/*for (i = 0; i < Max(a_length, b_length); i++)
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
		}*/
	}
	cout << "Результат А + В в 16-чной системе исчисления:" << endl;
	cout << Answer1;
	cout << endl;
	delete[] AnswerAdd;
	cout << endl;
	/*string digit;
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
	delete[]AnswerMulOneDigit;*/
	cout << endl;
	cout << "Умножаем число А на число В" << endl;
	int* AnswerLongMul;
	AnswerLongMul = LongMul(integ_A, integ_B, a_length, b_length);
	string Answer4;
	Answer4 = ConvertNumberToStr(AnswerLongMul, 2 * Max(a_length, b_length));
	/*for (i = 0; i < 2*Max(a_length, b_length); i++)
	{
		if (AnswerLongMul[i] == 10)
		{
			Answer4 = Answer4 + "A";
		}
		else if (AnswerLongMul[i] == 11)
		{
			Answer4 = Answer4 + "B";
		}
		else if (AnswerLongMul[i] == 12)
		{
			Answer4 = Answer4 + "C";
		}
		else if (AnswerLongMul[i] == 13)
		{
			Answer4 = Answer4 + "D";
		}
		else if (AnswerLongMul[i] == 14)
		{
			Answer4 = Answer4 + "E";
		}
		else if (AnswerLongMul[i] == 15)
		{
			Answer4 = Answer4 + "F";
		}
		else if (AnswerLongMul[i] < 10) {
			Answer4 += to_string(AnswerLongMul[i]);
		}
	}*/
	if (b_length > 1)
	{
		while (Answer4.at(0) == '0')
		{
			Answer4.erase(0, 1);
		}
	}
	else if (b_length == 1)
	{
		Answer4.erase(0, 1);
		while (Answer4.at(0) == '0')
		{
			Answer4.erase(0, 1);
		}
	}
	cout << endl;
	cout << "Результат умножения числа А на число В в 16-чной системе исчисления:" << endl;
	cout << Answer4 << endl;
	delete[]AnswerLongMul;
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
			Answer2 = ConvertNumberToStr(AnswerSub, Max(a_length, b_length));
			/*for (i = 0; i < Max(a_length, b_length); i++)
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
			}*/
		}
		cout << "Результат А - В в 16-чной системе исчисления:" << endl;
		cout << Answer2 << endl;
		delete[] AnswerSub;
		for (i = 0; i < a_length; i++) //Заполняем по новой масив А, потому что при операции "-" мы изменяли его запись
		{
			if (isdigit(a.at(i)) == 0)
			{
				integ_A[i] = a.at(i) - '0' - 7;
			}
			else {
				integ_A[i] = a.at(i) - '0';
			}
		}
	}
	cout << endl;
	cout << "Возводим число А в квадрат" << endl;
	int* AnswerPowerToSquare1;
	string Answer5;
	AnswerPowerToSquare1 = PowerToSquare(integ_A, a_length);
	Answer5 = ConvertNumberToStr(AnswerPowerToSquare1, 2 * a_length);
	/*for (i = 0; i < 2 * a_length; i++)
	{
		if (AnswerPowerToSquare1[i] == 10)
		{
			Answer5 = Answer5 + "A";
		}
		else if (AnswerPowerToSquare1[i] == 11)
		{
			Answer5 = Answer5 + "B";
		}
		else if (AnswerPowerToSquare1[i] == 12)
		{
			Answer5 = Answer5 + "C";
		}
		else if (AnswerPowerToSquare1[i] == 13)
		{
			Answer5 = Answer5 + "D";
		}
		else if (AnswerPowerToSquare1[i] == 14)
		{
			Answer5 = Answer5 + "E";
		}
		else if (AnswerPowerToSquare1[i] == 15)
		{
			Answer5 = Answer5 + "F";
		}
		else if (AnswerPowerToSquare1[i] < 10) {
			Answer5 += to_string(AnswerPowerToSquare1[i]);
		}
	}*/
	while (Answer5.at(0) == '0')
	{
		Answer5.erase(0, 1);
	}
	cout << endl;
	cout << "Результат вознесения числа А в квадрат в 16-чной системе исчисления:" << endl;
	cout << Answer5 << endl;
	delete[]AnswerPowerToSquare1;
	cout << endl;
	cout << "Возводим число В в квадрат" << endl;
	int* AnswerPowerToSquare2;
	string Answer6;
	AnswerPowerToSquare2 = PowerToSquare(integ_B, b_length);
	Answer6 = ConvertNumberToStr(AnswerPowerToSquare2, 2 * b_length);
	/*for (i = 0; i < 2 * b_length; i++)
	{
		if (AnswerPowerToSquare2[i] == 10)
		{
			Answer6 = Answer6 + "A";
		}
		else if (AnswerPowerToSquare2[i] == 11)
		{
			Answer6 = Answer6 + "B";
		}
		else if (AnswerPowerToSquare2[i] == 12)
		{
			Answer6 = Answer6 + "C";
		}
		else if (AnswerPowerToSquare2[i] == 13)
		{
			Answer6 = Answer6 + "D";
		}
		else if (AnswerPowerToSquare2[i] == 14)
		{
			Answer6 = Answer6 + "E";
		}
		else if (AnswerPowerToSquare2[i] == 15)
		{
			Answer6 = Answer6 + "F";
		}
		else if (AnswerPowerToSquare2[i] < 10) {
			Answer6 += to_string(AnswerPowerToSquare2[i]);
		}
	}*/
	while (Answer6.at(0) == '0')
	{
		Answer6.erase(0, 1);
	}
	cout << endl;
	cout << "Результат вознесения числа В в квадрат в 16-чной системе исчисления:" << endl;
	cout << Answer6 << endl;
	delete[]AnswerPowerToSquare2;
	/*cout << "Деление числа А на число В" << endl;
	int** AnswerLongDivMod = LongDivModul(A, B, a_length);
	int* Chastka = AnswerLongDivMod[0];
	int* Ostacha = AnswerLongDivMod[1];
	cout << "Результат деления числа А на число В:"<<Chastka << endl;
	cout << "Остаток от деления числа А на число В:" << Ostacha << endl;
	delete[] AnswerLongDivMod;*/
	return 0;
}
