#include <iostream>
#include <Windows.h>
#include <conio.h>

#define ENDNUM	0
#define P_SIZE 5



enum CHECKLIST {
	STATE,
	VALUE
};

enum COMPUTER_LEVEL
{
	EASY = 1,
	HARD
};
using std::cout;
using std::endl;
using std::cin;

int main()
{
	//����: ���� ���� ���� �����

	//1 ~ 25���� ���ڰ� �ְ� �� ���ڸ� ���� ��� 5 * 5�� ����Ѵ�.
	system("mode con: cols=100 lines=100");

	int iBingo[P_SIZE * P_SIZE]{ 0 };
	bool iCheck[2][P_SIZE * P_SIZE]{ 0 };  // 0 = STATE, 1 =VALUE

	int iComputer[P_SIZE * P_SIZE]{ 0 };
	bool iComputerCheck[2][P_SIZE * P_SIZE]{ 0 };  // 0 = STATE, 1 =VALUE

	bool  C_Length{ 0 }, C_Height{ 0 }, C_Depth[2]{ 0 }, C_cDepth[2]{ 0 };
	int input{ 0 }, Cinput{ 0 }, C_Bingo{ 0 }, C_Computer{ 0 }, Level{ 0 };

	srand(time(NULL));

	for (int i = 0; i < P_SIZE * P_SIZE; i++)
	{
		iBingo[i] = i + 1;
		iComputer[i] = i + 1;
	}
	cout << "CHOOSE LEVEL (1, 2) : " << endl;
	cin >> Level;


	//������!
	system("cls");
	for (int i = P_SIZE * P_SIZE - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);

		if (i == j)
			continue;

		int iTemp = iBingo[i];
		iBingo[i] = iBingo[j];
		iBingo[j] = iTemp;

		//���°� ��� �̻ڰ�. 

		cout << endl << endl;
		cout << "\t    __________________ BINGO ________________" << endl << endl;
		for (int k = 0; k < P_SIZE; k++)
		{
			cout << "\t\t";
			for (int e = 0; e < P_SIZE; e++)
			{
				if (i == (k * 5 + e) || j == (k * 5 + e))
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //����
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				cout << iBingo[k * 5 + e] << "\t";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			cout << endl << endl << endl;
		}
		cout << "\t    __________________________________________" << endl << endl;

		cout << endl << endl;

		//��ǻ�� ���� 

		j = rand() % (i + 1);

		if (i == j)
			continue;

		iTemp = iComputer[i];
		iComputer[i] = iComputer[j];
		iComputer[j] = iTemp;

		cout << endl << endl;
		cout << "\t    __________________ COMPU ________________" << endl << endl;
		for (int k = 0; k < P_SIZE; k++)
		{
			cout << "\t\t";
			for (int e = 0; e < P_SIZE; e++)
			{
				if (i == (k * 5 + e) || j == (k * 5 + e))
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //����
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				cout << iComputer[k * 5 + e] << "\t";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			cout << endl << endl << endl;
		}
		cout << "\t    __________________________________________" << endl << endl;
		cout << endl << endl;
		Sleep(100);
		system("cls");

	}

	cout << endl << endl;
	cout << " ���Ⱑ �Ϸ�Ǿ����ϴ�! " << endl;
	system("pause>null");



	while (true)
	{
		//���� ���! 
		system("cls");

		//���� ���� ���� �� ������ üũ�ؼ� ȭ�鿡 �����ش�.
		cout << "���� ���� �� : " << C_Bingo << endl;


		cout << endl << endl;
		cout << "\t    __________________ BINGO ________________" << endl << endl;
		for (int i = 0; i < P_SIZE; i++)
		{
			cout << "\t\t";
			for (int j = 0; j < P_SIZE; j++)
			{
				if (iCheck[STATE][i * 5 + j])
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << "* \t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				else
					cout << iBingo[i * 5 + j] << "\t";
			}
			cout << endl << endl << endl;
		}
		cout << "\t    __________________________________________" << endl;


		//��ǻ�� ���� ��� 
		cout << "\t    __________________________________________" << endl;
		cout << endl << endl;
		cout << "��ǻ�� ���� ���� �� : " << C_Computer << endl;
		cout << "��ǻ�Ͱ� �Է��ߴ� ��  : " << Cinput + 1 << endl;


		cout << endl << endl;
		cout << "\t    __________________ COMPU ________________" << endl << endl;
		for (int i = 0; i < P_SIZE; i++)
		{
			cout << "\t\t";
			for (int j = 0; j < P_SIZE; j++)
			{
				if (iComputerCheck[STATE][i * 5 + j])
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << "* \t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				else
					cout << iComputer[i * 5 + j] << "\t";
			}
			cout << endl << endl << endl;
		}
		cout << "\t    __________________________________________" << endl << endl;

		//5�� �̻��� ��� ������ �����Ѵ�.
		if (C_Bingo >= 5 || C_Computer >= 5)
		{
			cout << endl << endl;
			cout << "-------------------------------------------" << endl;
			cout << "|       O!O  5 BINGO!" << (C_Bingo >= C_Computer ? "Player " : "Computer ") << "Win  O!O       | " << endl;
			cout << "-------------------------------------------" << endl;
			cout << endl << endl;

			break;
		}


		//�÷��̾�� ���ڸ� �Է��Ѵ�. 1 ~ 25 ������ ���ڸ� �Է¹޾ƾ� �Ѵ�.
			//�Է��� ���ڿ��� -1 �ؼ� �Ǵ��Ѵ�. 

		cout << "���ڸ� �������ּ���!( 1 ~ " << P_SIZE * P_SIZE << " ����) : " << endl;
		cin >> input;
		input--;

		if (cin.fail() || input < -1 || input >(P_SIZE * P_SIZE - 1))
		{
			cout << "�ùٸ� ���ڰ� �ƴմϴ�. �ٽ� �Է����ּ���." << endl;

			cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			system("pause>null");
			continue;
		}
		if ((input + 1) == ENDNUM)
		{
			//0�� �Է��ϸ� ������ �����Ѵ�.
			cout << " ���Ḧ ����̽��ϴ�. ";
			break;
		}


		//���� ��� �� ���ڸ� ã�Ƽ� *�� ������ش�.
		if (iCheck[VALUE][input])
		{
			cout << " �� ���ڴ� �̹� ���õǾ����ϴ�! : " << input + 1 << endl;
			system("pause>null");
			continue;
		}

		//��ǻ�� �� ���� 

		while (true) {
			Cinput = rand() % (P_SIZE * P_SIZE);

			if (iComputerCheck[VALUE][Cinput] || input == Cinput)
				continue;
			else
				break;
		}
		//�ΰ� �� * ǥ���ϱ�.  Player
		iCheck[VALUE][input] = true; //�� ���ڴ� ������Դϴ�! 
		iCheck[VALUE][Cinput] = true;

		iComputerCheck[VALUE][input] = true;
		iComputerCheck[VALUE][Cinput] = true;

		// ���� ��ġ ã�� 
		for (int i = 0; i < P_SIZE * P_SIZE; i++)
		{
			if (iBingo[i] == (input + 1))
				iCheck[STATE][i] = true; // �� ��ġ�� * �����Դϴ�!

			if (iBingo[i] == (Cinput + 1))
				iCheck[STATE][i] = true;

			if (iComputer[i] == (input + 1))
				iComputerCheck[STATE][i] = true; // �� ��ġ�� * �����Դϴ�!

			if (iComputer[i] == (Cinput + 1))
				iComputerCheck[STATE][i] = true;
		}






		//���ڸ� *�� ���� �Ŀ� ���� �� ���� üũ�Ѵ�.
		//5 * 5�̱� ������ ���� 5�� ���� 5�� �밢�� 2���� ���� �� �ִ�.


		C_Depth[0] = C_Depth[1] = C_cDepth[0] = C_cDepth[1] = true;
		C_Bingo = C_Computer = 0;

		for (int i = 0; i < P_SIZE; i++)
		{
			C_Length = C_Height = true;
			for (int j = 0; j < P_SIZE; j++)
			{
				// ������
				if (!iCheck[STATE][i * P_SIZE + j]) C_Length = false;
				// ������ 
				if (!iCheck[STATE][i + j * P_SIZE]) C_Height = false;
			}
			if (C_Length) C_Bingo++;
			if (C_Height) C_Bingo++;

			//��ǻ�� 
			C_Length = C_Height = true;
			for (int j = 0; j < P_SIZE; j++)
			{
				// ������
				if (!iComputerCheck[STATE][i * P_SIZE + j]) C_Length = false;
				// ������ 
				if (!iComputerCheck[STATE][i + j * P_SIZE]) C_Height = false;
			}
			if (C_Length) C_Computer++;
			if (C_Height) C_Computer++;


			// �밢�� 
			if (!iCheck[STATE][(P_SIZE * i) + i]) C_Depth[0] = false;
			if (!iCheck[STATE][(P_SIZE * i) + (P_SIZE - i - 1)]) C_Depth[1] = false;

			//��ǻ�� �밢�� 
			if (!iComputerCheck[STATE][(P_SIZE * i) + i]) C_cDepth[0] = false;
			if (!iComputerCheck[STATE][(P_SIZE * i) + (P_SIZE - i - 1)]) C_cDepth[1] = false;

		}
		if (C_Depth[0]) C_Bingo++;
		if (C_Depth[1]) C_Bingo++;
		if (C_cDepth[0]) C_Computer++;
		if (C_cDepth[1]) C_Computer++;

	}
	return 0;
}
