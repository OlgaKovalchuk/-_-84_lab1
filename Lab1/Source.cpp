#include <iostream>
#include <string>
#include <ctime>
#include <time.h>

using namespace std;

const string HEX_DIGITS = "0123456789ABCDEF";

int* AnswerAdd5;
string Ostacha_str;

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
			if (temp > 15 || (Answer[i] + temp) > 15)
			{
				Answer[i - 1] = Answer[i - 1] + ((Answer[i] + temp) / 16);
				Answer[i] = Answer[i] + temp - ((Answer[i] + temp) / 16) * 16;
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
	}
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
				A[a_length - j] = A[a_length - j] + 16;
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
							A[a_length - j - k] = A[a_length - j - k] + 16;
						}
						else {
							A[a_length - j - k] = A[a_length - j - k] + 16;
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
				A[a_length - i] = A[a_length - i] + 16;
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
	}
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
		}
	}
	else if(temp1[c+1] == 17){
		for (int i = 1; i < c + 2; i++)
		{
			Answer1[2 * c - i] = Answer1[2 * c - i] + temp1[c - i + 1];
		}
	}
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
			Answer3 = LongAdd(Answer1, Answer2, 2 * c, 2 * c);
			for (int k = 0; k < 2 * c; k++)
			{
				Answer2[k] = 0;
				Answer1[k] = Answer3[k];
			}
		}
	}
	else if (b_length == 1)
	{
		for (int k = 0; k < 2 * c; k++)
		{
			Answer3[k] = Answer1[k];
		}
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
		answer += HEX_DIGITS.at(A[i]);
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
				answer = 2;   //Число А равно числу В
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
	/*for (int k = 0; k < b_length + number_of_cells_shift; k++)
	{
		NewB[k] = 0;
	}*/
	for (int i = 0; i < b_length; i++)
	{
		NewB[i] = B[i];
	}
	for (int k = b_length; k < b_length + number_of_cells_shift; k++)
	{
		NewB[k] = 0;
	}
	return NewB;
}

int SizeOfArray(int A[])
{
	int size_limit = 1000;
	int size_of_array = 0;
	int i = 0;
	while (A[i] >= 0 && A[i] < 16 && i < size_limit + 1)
	{
		size_of_array++;
		i++;
	}
	return size_of_array;
}

int* LongDivModul(int A[], int B[], int a_length, int b_length)
{
	int new_b_length = a_length;
	int* Q  = new int [a_length];
	int* Answer = new int[a_length];
	int* Ostacha = new int [a_length];
	int* Chastka = new int[a_length];
	int* Answer1;
	int* NewB;
	int shift = 0;
	int shift1 = 0;
	for (int i = 0; i < a_length - 1; i++)
	{
		Q[i] = 0;
	}
	Q[a_length - 1] = 1;
	for (int i = 0; i < a_length; i++)
	{
		Chastka[i] = 0;
	}
	for (int i = 0; i < a_length ; i++)
	{
		Ostacha[i] = A[i];
		//cout <<"Ostacha["<<i<<"] = "<< Ostacha[i] << endl;
	}
	int length_Ostacha = SizeOfArray(Ostacha);
	int p = 0;
	while (CompareNum(Ostacha, B, a_length, b_length) == 1 || CompareNum(Ostacha, B, a_length, b_length) == 2)
	{
		//int length_Ostacha = SizeOfArray(Ostacha);
		if (Ostacha[0] == 0)
		{
			p++;
			for (int i = 0; i < length_Ostacha-1; i++)
			{
				Ostacha[i] = Ostacha[i + 1];
			}
			length_Ostacha--;
			/*if (new_b_length == length_Ostacha)
			{
				shift = shift;
			}*/
			if (new_b_length > length_Ostacha)
			{
				new_b_length--;
			}
			shift++;
		}
		NewB = LongShiftBitsToHigh(B,length_Ostacha - b_length, b_length);
		/*cout << "Сдвинутое число В:" << endl;
		for (int i = 0; i < length_Ostacha; i++)
		{
			cout << NewB[i] << "  ";
		}*/
		while (CompareNum(Ostacha, NewB, length_Ostacha, new_b_length) == 0)
		{
			new_b_length--;
			if (new_b_length < b_length)
			{
				break;
			}
			NewB = LongShiftBitsToHigh(B, length_Ostacha - b_length - 1, b_length);
			/*cout << "Сдвинутое число В:" << endl;
			for (int i = 0; i < new_b_length; i++)
			{
				cout << NewB[i] << "  ";
			}
			cout << endl;*/
			//b_length--;
		}
		if (new_b_length < b_length)
		{
			break;
		}
		cout << "Остаток сейчас:" << endl;
		for (int i = 0; i < length_Ostacha; i++)
		{
			cout << "Ostacha[" << i << "] = " << Ostacha[i] << endl;
		}
		cout << endl;
		Answer = LongSub(Ostacha, NewB, length_Ostacha, new_b_length);
		cout << "Разность А и В:" << endl;
		for (int i = 0; i < a_length; i++)
		{
			cout <<"Answer["<<i<<"] = "<< Answer[i] <<endl;
		}
		cout << endl;
		for (int i = 0; i < length_Ostacha; i++)
		{
			Ostacha[i] = Answer[i];
		}
		if (shift != 0 && length_Ostacha!=b_length )
		{
			Q[a_length - shift-1] = 1;
			for (int i = a_length - shift; i < a_length; i++)
			{
				Q[i] = 0;
			}
			Q[a_length - 1] = 0;
		}
		Chastka = LongAdd(Chastka, Q, a_length, a_length);
		cout << "Частка равна сейчас:" << endl;
		for (int i = 0; i < a_length; i++)
		{
			cout << Chastka[i] << "  ";
		}
		cout << endl;
		p++;
	}
	Ostacha_str = ConvertNumberToStr(Ostacha, length_Ostacha);
	return Chastka;
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
	int* Dvoich_B = DvoichnaForma(B, b_length);
	string Dvoich_B_str = ConvertNumberToStr(Dvoich_B, SizeOfArray(Dvoich_B));
	int first_1 = Dvoich_B_str.find('1');
	int* Answer = new int[500 * a_length];
	int* Answer1 = new int[500 * a_length];
	for (int i = 0; i < a_length; i++)
	{
		Answer1[500  * a_length - i - 1] = A[a_length - i - 1];
	}
	for (int j = 0; j < 500 * a_length - a_length; j++)
	{
		Answer1[j] = 0;
	}
	for (int j = 0; j < 500 * a_length; j++)
	{
		Answer[j] = 0;
	}
	for (int j = first_1+1; j < 4 * b_length; j++)
	{
		Answer = PowerToSquare(Answer1, 500 * a_length);
		for (int k = 0; k < 500 * a_length; k++)
		{
			Answer1[500 * a_length - k - 1] = Answer[2 * 500 * a_length - k - 1];
		}
		if (Dvoich_B[j] == 1)
		{
			Answer = LongMul(Answer1, A, 500 * a_length, a_length);
			for (int k = 0; k < 500  * a_length; k++)
			{
				Answer1[500 * a_length-k-1] = Answer[2*500 * a_length-k-1];
			}
		}
	}
	return Answer1;
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
	double d1;
	clock_t start1, finish1;
	srand(time(NULL));
	start1 = clock();
	AnswerAdd = LongAdd(integ_A, integ_B, a_length, b_length);
	string Answer1;
	if (AnswerAdd[Max(a_length, b_length) + 1] == 100)
	{
		Answer1 = ConvertNumberToStr(AnswerAdd, Max(a_length, b_length) + 1);
	}
	else if (AnswerAdd[Max(a_length, b_length) + 1] == 0)
	{
		Answer1 = ConvertNumberToStr(AnswerAdd, Max(a_length, b_length));
	}
	cout << "Результат А + В в 16-чной системе исчисления:" << endl;
	cout << Answer1 << endl;
	delete[] AnswerAdd;
	finish1 = clock();
	d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
	cout << "Время работы операции + : " << d1 << endl;
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
	double d2;
	clock_t start2, finish2;
	srand(time(NULL));
	start2 = clock();
	cout << "Умножаем число А на число В" << endl;
	int* AnswerLongMul;
	if (b_length > a_length)
	{
		AnswerLongMul = LongMul(integ_B, integ_A, b_length, a_length);
	}
	else {
		AnswerLongMul = LongMul(integ_A, integ_B, a_length, b_length);
	}
	//AnswerLongMul = LongMul(integ_A, integ_B, a_length, b_length);
	string Answer4;
	Answer4 = ConvertNumberToStr(AnswerLongMul, 2 * Max(a_length, b_length));
	if (b_length > 1)
	{
		while (Answer4.at(0) == '0')
		{
			Answer4.erase(0, 1);
		}
	}
	else if (b_length == 1)
	{
		//Answer4.erase(0, 1);
		while (Answer4.at(0) == '0')
		{
			Answer4.erase(0, 1);
		}
	}
	cout << "Результат умножения числа А на число В в 16-чной системе исчисления:" << endl;
	cout << Answer4 << endl;
	finish2 = clock();
	d2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
	cout << "Время работы операции * : " << d2 << endl;
	delete[]AnswerLongMul;
	double d3;
	clock_t start3, finish3;
	srand(time(NULL));
	start3 = clock();
	cout << "Отнимаем число В от числа А" << endl;
	string Answer2;
	if (a_length < b_length)
	{
		Answer2 = "Ошибка!!! От числа меньшей длины отнимаем число большей длины!";
		cout << Answer2 << endl;
		finish3 = clock();
		d3 = (double)(finish3 - start3) / CLOCKS_PER_SEC;
		cout << "Время работы операции * : " << d2 << endl;
	}
	else {
		AnswerSub = LongSub(integ_A, integ_B, a_length, b_length);
		if (AnswerSub[Max(a_length, b_length)] == 1)
		{
			Answer2 = "Отрицательное значение!!! ";
		}
		else {
			Answer2 = ConvertNumberToStr(AnswerSub, Max(a_length, b_length));
		}
		cout << "Результат А - В в 16-чной системе исчисления:" << endl;
		cout << Answer2 << endl;
		finish3 = clock();
		d3 = (double)(finish3 - start3) / CLOCKS_PER_SEC;
		cout << "Время работы операции - : " << d3 << endl;
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
	double d4;
	clock_t start4, finish4;
	srand(time(NULL));
	start4 = clock();
	cout << "Возводим число А в квадрат" << endl;
	int* AnswerPowerToSquare1;
	string Answer5;
	AnswerPowerToSquare1 = PowerToSquare(integ_A, a_length);
	Answer5 = ConvertNumberToStr(AnswerPowerToSquare1, 2 * a_length);
	while (Answer5.at(0) == '0')
	{
		Answer5.erase(0, 1);
	}
	cout << endl;
	cout << "Результат возведения числа А в квадрат в 16-чной системе исчисления:" << endl;
	cout << Answer5 << endl;
	finish4 = clock();
	d4 = (double)(finish4 - start4) / CLOCKS_PER_SEC;
	cout << "Время работы операции ^ : " << d4 << endl;
	delete[]AnswerPowerToSquare1;
	cout << endl;
/*cout << "Возводим число В в квадрат" << endl;
int* AnswerPowerToSquare2;
string Answer6;
AnswerPowerToSquare2 = PowerToSquare(integ_B, b_length);
Answer6 = ConvertNumberToStr(AnswerPowerToSquare2, 2 * b_length);
while (Answer6.at(0) == '0')
{
	Answer6.erase(0, 1);
}
cout << endl;
cout << "Результат вознесения числа В в квадрат в 16-чной системе исчисления:" << endl;
cout << Answer6 << endl;
delete[]AnswerPowerToSquare2;
cout << endl;*/
/*double d6;
clock_t start6, finish6;
srand(time(NULL));
start6 = clock();
cout << "Возводим число А в степень, которая равна числу В" << endl;
int* AnswerLongPower = LongPower(integ_A, integ_B, a_length, b_length);
string Answer7;
Answer7 = ConvertNumberToStr(AnswerLongPower, 500 * a_length);
while (Answer7.at(0) == '0')
{
	Answer7.erase(0, 1);
}
cout << endl;
cout << "Результат возведения числа А в степень, которая равна числу В:" << endl;
cout << Answer7 << endl;
delete[]AnswerLongPower;
cout << endl;
finish6 = clock();
d6 = (double)(finish6 - start6) / CLOCKS_PER_SEC;
cout << "Время работы операции ^ B : " << d6 << endl;*/
double d5;
clock_t start5, finish5;
srand(time(NULL));
start5 = clock();
cout << "Деление числа А на число В" << endl;
/*cout << "Число В сдвинули на 1 символ:" << endl;
int* NewB = LongShiftBitsToHigh(integ_B, a_length - b_length - 2, b_length);
for (int i = 0; i < 5; i++)
{
	cout << "NewB[" << i << "] = " << NewB[i] << endl;
}
cout << endl;*/
if (CompareNum(integ_A, integ_B, a_length, b_length) == 0)
{
	cout << "Мы не можем поделить меньшее число на большее!!!" << endl;
	finish5 = clock();
	d5 = (double)(finish5 - start5) / CLOCKS_PER_SEC;
	cout << "Время работы операции ^ : " << d5 << endl;
}
else if (CompareNum(integ_A, integ_B, a_length, b_length) == 1 || CompareNum(integ_A, integ_B, a_length, b_length) == 2)
{
	int* AnswerLongDivMod = LongDivModul(integ_A, integ_B, a_length, b_length);
	string Answer8;
	int compare = CompareNum(integ_A, integ_B, a_length, b_length);
	cout << "Число А больше числа В? Ответ: " << compare << endl;
	cout << "Результат деления числа А на число В:" << endl;
	Answer8 = ConvertNumberToStr(AnswerLongDivMod, a_length);
	while (Answer8.at(0) == '0')
	{
		Answer8.erase(0, 1);
	}
	//cout << Answer8.length() << endl;
	string Answer8_1;
	for (int i = 0; i < Answer8.length(); i++)
	{
		Answer8_1 = Answer8_1 + Answer8.at(Answer8.length() - i - 1);
	}
	cout << Answer8_1 << endl;
	cout << "Остаток от деления числа А на число В:" << Ostacha_str << endl;
	finish5 = clock();
	d5 = (double)(finish5 - start5) / CLOCKS_PER_SEC;
	cout << "Время работы операции / : " << d5 << endl;
	delete[] AnswerLongDivMod;
}
cout << "===========================================================================";
cout << endl;
cout << "Проверки правильности выполнения" << endl;
cout << "Пункт 1: (a+b)*c = c*(a+b) = a*c+ b*c" << endl;
string c;
int c_length;
int C[1000];
int* integ_C = C;
cout << "Число c:" << endl;
cin >> c;
c_length = c.length();
integ_C = ConvertStrToNumber(c, c_length);
cout << "Число C:" << endl;
for (i = 0; i < c_length; i++)
{
	cout << integ_C[i] << " ";
}
cout << endl;
cout << "Решаем выражение (a+b)*c" << endl;
int* AnswerAdd1 = LongAdd(integ_A, integ_B, a_length, b_length);
cout << "Результат суммирования чисел А и В:" << endl;
int AnswerAdd1_length;
if (AnswerAdd1[Max(a_length, b_length) + 1] == 100)
{
	AnswerAdd1_length = Max(a_length, b_length) + 1;
	for (int i = 0; i < Max(a_length, b_length) + 1; i++)
	{
		cout << AnswerAdd1[i] << "  ";
	}
	cout << endl;
}
else if (AnswerAdd1[Max(a_length, b_length) + 1] == 0)
{
	AnswerAdd1_length = Max(a_length, b_length);
	for (int i = 0; i < Max(a_length, b_length); i++)
	{
		cout << AnswerAdd1[i] << "  ";
	}
}
int* AnswerMul1 = LongMul(AnswerAdd1, integ_C, AnswerAdd1_length, c_length);
cout << "Результат выражения (а+b)*c :" << endl;
string equation1 = ConvertNumberToStr(AnswerMul1, 2 * Max(AnswerAdd1_length, c_length));
while (equation1.at(0) == '0')
{
	equation1.erase(0, 1);
}
cout << equation1 << endl;
cout << endl;
cout << "Решаем выражение c*(a+b)" << endl;
cout << "Длина ответа A+B = " << AnswerAdd1_length << endl;
int* AnswerAdd3 = LongAdd(integ_A, integ_B, a_length, b_length);
/*cout << "Число C:" << endl;
for (i = 0; i < c_length; i++)
{
	cout << integ_C[i] << " ";
}
cout << endl;*/
cout << "Результат суммирования чисел А и В:" << endl;
int AnswerAdd3_length;
if (AnswerAdd3[Max(a_length, b_length) + 1] == 100)
{
	AnswerAdd3_length = Max(a_length, b_length) + 1;
}
else if (AnswerAdd3[Max(a_length, b_length) + 1] == 0)
{
	AnswerAdd3_length = Max(a_length, b_length);
}
for (i = 0; i < AnswerAdd3_length; i++)
{
	cout << AnswerAdd3[i] << " ";
}
cout << endl;
int* AnswerMul2;
if (AnswerAdd3_length > c_length)
{
	AnswerMul2 = LongMul(AnswerAdd3, integ_C, AnswerAdd3_length, c_length);
}
else
{
	AnswerMul2 = LongMul(integ_C, AnswerAdd3, c_length, AnswerAdd3_length);
}
//AnswerMul2 = LongMul(integ_C, AnswerAdd3, c_length, AnswerAdd3_length);
for (int i = 0; i < 2 * Max(AnswerAdd3_length, c_length); i++)
{
	cout << AnswerMul2[i] << "  ";
}
cout << endl;
cout << "Результат выражения c*(а+b) :" << endl;
string equation2 = ConvertNumberToStr(AnswerMul2, 2 * Max(AnswerAdd1_length, c_length));
while (equation2.at(0) == '0')
{
	equation2.erase(0, 1);
}
cout << equation2 << endl;
cout << endl;
cout << "Решаем выражение a*c+b*c" << endl;
int* AnswerMul3 = LongMul(integ_A, integ_C, a_length, c_length);
int* AnswerMul4 = LongMul(integ_B, integ_C, b_length, c_length);
int* AnswerAdd2 = LongAdd(AnswerMul3, AnswerMul4, 2 * Max(a_length, c_length), 2 * Max(b_length, c_length));
int AnswerAdd2_length;
if (AnswerAdd2[Max(2 * Max(a_length, c_length), 2 * Max(b_length, c_length)) + 1] == 100)
{
	AnswerAdd2_length = Max(2 * Max(a_length, c_length), 2 * Max(b_length, c_length)) + 1;
}
else if (AnswerAdd2[Max(2 * Max(a_length, c_length), 2 * Max(b_length, c_length)) + 1] == 0)
{
	AnswerAdd2_length = Max(2 * Max(a_length, c_length), 2 * Max(b_length, c_length));
}
string equation3 = ConvertNumberToStr(AnswerAdd2, AnswerAdd2_length);
while (equation3.at(0) == '0')
{
	equation3.erase(0, 1);
}
cout << equation3 << endl;
cout << endl;
delete[]AnswerAdd1;
delete[]AnswerAdd2;
delete[]AnswerAdd3;
delete[]AnswerMul1;
delete[]AnswerMul2;
delete[]AnswerMul3;
delete[]AnswerMul4;
cout << "Пункт 2: B*Chastka+Ostacha=A" << endl;
int* Ostacha = ConvertStrToNumber(Ostacha_str, Ostacha_str.length());
int* Chastka = LongDivModul(integ_A, integ_B, a_length, b_length);
/*for (int i = 0; i < a_length; i++)
{
	cout << Chastka[i] << "  ";
}
cout << endl;
cout << "Остача = " << endl;
for (int i = 0; i < Ostacha_str.length(); i++)
{
	cout << Ostacha[i] << "  ";
}
cout << endl;*/
string Chastka_str = ConvertNumberToStr(Chastka, a_length);
while (Chastka_str.at(0) == '0')
{
	Chastka_str.erase(0, 1);
}
int chastka_length = Chastka_str.length();
/*cout << "Частка = " << Chastka_str << endl;
cout << "Число В:" << endl;
for (int i = 0; i < b_length; i++)
{
	cout << integ_B[i] << "  ";
}
cout << endl;
cout << "Частка:" << endl;
for (int i = 0; i < a_length; i++)
{
	cout << Chastka[i] << "  ";
}
cout << endl;*/
int* AnswerMul5 = LongMul(integ_B, Chastka, b_length, a_length);
string AnswerMul5_str = ConvertNumberToStr(AnswerMul5, 2*Max(b_length, a_length));
/*while (AnswerMul5_str.at(0) == '0')
{
	AnswerMul5_str.erase(0, 1);
}*/
int AnswerMul5_length = AnswerMul5_str.length();
//cout << "AnswerMul5_length = " << AnswerMul5_length << endl;
/*for (int i = 0; i < AnswerMul5_length; i++)
{
	cout << AnswerMul5[i] << "  ";
}
cout << endl;*/
int* AnswerAdd4 = LongAdd(AnswerMul5, Ostacha, AnswerMul5_length, Ostacha_str.length());
int AnswerAdd4_length;
if (AnswerAdd4[Max(AnswerMul5_length, Ostacha_str.length()) + 1] == 100)
{
	AnswerAdd4_length = Max(AnswerMul5_length, Ostacha_str.length()) + 1;
}
else if (AnswerAdd4[Max(AnswerMul5_length, Ostacha_str.length()) + 1] == 0)
{
	AnswerAdd4_length = Max(AnswerMul5_length, Ostacha_str.length());
}
string equation4 = ConvertNumberToStr(AnswerAdd4, AnswerAdd4_length);
while (equation4.at(0) == '0')
{
	equation4.erase(0, 1);
}
cout << equation4 << endl;
cout << "Число А:" << endl;
cout << a << endl;
cout << endl;
delete[]Ostacha;
delete[]Chastka;
delete[]AnswerAdd4;
delete[]AnswerMul5;
return 0;
}
