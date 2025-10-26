#include <iostream>
#include <Windows.h>

#define RANGE	3
#define SIZE	9

using std::cout;
using std::endl;



int main()
{
	//String, STL, �˰��� ���� �迭������ �����ϼ���. 
	/*
	���� �߱� ����

	1 ~ 9 ������ ������ ���� 3���� ���´�. �� ���ڴ� �ߺ��Ǿ�� �ȵȴ�.
	3���� ���ڴ� ���������� * * * �� ���·� ����� �Ǿ� �ϰ�,
	�� 3���� ���ڸ� ����ڰ� ���ߴ� �����̴�.

	����ڴ� �� 3���� ���ڸ� ���� �� ���� ������ ����Ǹ� �ȵǰ� ����ؼ� ���ڸ� �Է��ؾ� �Ѵ�.

	���������� 3���� ���ڸ� �ڸ����� ��� ���� �� ���� �Է��ϸ� ������ ����ȴ�.
	���� �Է¹��� ���� �� �ϳ��� 0�� ���� ��� ������ �����Ѵ�.



	���� ������� ���ڰ� 7 3 8 �� ���

	�Է� : 1 2 4�� �Է����� ��� 1 2 4�� ����� �� ���� �� �ƹ��͵� �����Ƿ� OUT�� ����Ѵ�.
	��� : Out

	�Է� : 7 5 9�� �Է����� ��� 7�� ����� �� ���� �� �ְ�, ��ġ�� �����Ƿ� Strike����.
	5, 9�� �����Ƿ� ó������ ����.
	��� : 1Strike 0Ball

	�Է� : 7 8 6�� �Է����� ��� 7�� ����� �� ���� �� �ְ�, ��ġ�� �����Ƿ� Strike����.
	8�� ����� �� ���� �� ������ ��ġ�� �ٸ��Ƿ� Ball ����.
	��� : 1Strike 1Ball
*/


	srand(time(NULL));

	int  Playinput[RANGE]{ 0 }, Randint[SIZE]{ 0 };
	int Strike{ 0 }, Ball{ 0 };

	/*
	for (int i = 0; i < RANGE; i++)
		Randint[i] = rand() % SIZE + 1;
	*/

	//���� 3�� ������ (�ߺ� �Ұ�) 
	for (int i = 0; i < SIZE; i++)
		Randint[i] = i;

	for (int i = SIZE - 1; i > 0; i--) //��Ȱ���ҰŸ� Strike�� ball�� ���� 
	{
		int j = rand() % (i + 1);
		int num = Randint[i];
		Randint[i] = Randint[j];
		Randint[j] = num;

	}


	//Randint �� ������ � �����Ű� ���� �� �� 3���� ���Ŵϱ� �迭 �ϳ��� ���̾�. 

	cout << endl << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "   ��ǻ�Ͱ� ���ڸ� ������ϴ�. " << endl;
	cout << "   �ʿ��� ���� �� : " << "1~ 9 ������ ����. " << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << endl << endl;
	cout << "Press Enter To Start" << endl;

	system("pause>null");


	//���ؼ� ����ϱ� 
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		Strike = Ball = 0;

		//�� �Է�
		cout << endl << endl;
		cout << "      Ű�� " << RANGE << "�� �Է��ϼ���. " << endl;
		std::cin >> Playinput[0] >> Playinput[1] >> Playinput[2];


		cout << endl << endl;
		cout << "---------------------------------------------------------------------------------" << endl;

		//Ȯ�ο� 
		cout << "��ǻ�Ͱ� �Է��� ���� : " << Randint[0] << " " << Randint[1] << " " << Randint[2] << endl;
		cout << "---------------------------------------------------------------------------------" << endl;
		//Ȯ�ο�

		cout << "����ڰ� �Է��� ���� : " << Playinput[0] << " " << Playinput[1] << " " << Playinput[2] << endl;
		cout << "---------------------------------------------------------------------------------" << endl;
		cout << endl << endl;

		//�Է°� ���� üũ 
		if (Playinput[0] / SIZE || Playinput[1] / SIZE || Playinput[2] / SIZE || Playinput[0] <= 0 || Playinput[1] <= 0 || Playinput[2] <= 0)
		{
			cout << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "�Է�Ű ���� �ʰ� �Ͽ����ϴ�. �ٽ� ��Ź�帳�ϴ�. " << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << " �ʿ��� ���� �� : " << "1~ 9 ������ ����. " << endl;
			cout << "Press Enter To Restart" << endl;

			system("pause>null");
			continue;
		}


		//Strike Ball ���� 
		for (int i = 0; i < 3; i++)
		{
			if (Playinput[i] == Randint[i])
				Strike++;
			else if (Playinput[i] == Randint[0] || Playinput[i] == Randint[1] || Playinput[i] == Randint[2] && !(Playinput[i] == Randint[i]))
				Ball++;

		}


		//���� ��� 

		cout << "����� : ";

		if (Strike == 3)
		{
			//�� �� �� 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "        C   ";
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "O   ";
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			cout << "N   ";
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "G   ";
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "R   ";
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			cout << "A   ";
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "T   ";
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "U   ";
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			cout << "L   ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "A   ";
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "T   ";
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			cout << "I  ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "O   ";
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "N   ";
			//�� �� �� 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << " 3Strike! ����� �����Դϴ�!" << endl << endl;
			break;
		}
		else if (Strike == 0 && Ball == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "OUT!" << endl;
		}

		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << Strike << " Strike, ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << Ball << " Ball" << endl;
		}




		system("pause>null");
	}

	//�������� ��� ����ϱ� 



	return 0;
}
