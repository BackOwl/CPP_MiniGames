#include <iostream>
#include <Windows.h>
#include <conio.h>

#define ENDNUM	0
#define P_SIZE 5



enum CHECKLIST {
	STATE,
	VALUE
};

using std::cout;
using std::endl;
using std::cin;

int main()
{
	// 숫자 빙고 게임 만들기
	//오직 배열만 사용해서 만들기. 
	//1 ~ 25까지 숫자가 있고 이 숫자를 골고루 섞어서 5 * 5로 출력한다.

	int iBingo[P_SIZE * P_SIZE]{ 0 };
	bool iCheck[2][P_SIZE * P_SIZE]{ 0 };  // 0 = STATE, 1 =VALUE
	bool  C_Length{ 0 }, C_Height{ 0 }, C_Depth[2]{ 0 };
	int input{ 0 }, C_Bingo{ 0 };

	srand(time(NULL));

	for (int i = 0; i < P_SIZE * P_SIZE; i++)
		iBingo[i] = i + 1;

	//무작위!
	for (int i = P_SIZE * P_SIZE - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);

		if (i == j)
			continue;

		int iTemp = iBingo[i];
		iBingo[i] = iBingo[j];
		iBingo[j] = iTemp;

		//섞는거 출력 이쁘게. 
		system("cls");
		cout << endl << endl;
		cout << "\t    __________________ BINGO ________________" << endl << endl;
		for (int k = 0; k < P_SIZE; k++)
		{
			cout << "\t\t";
			for (int e = 0; e < P_SIZE; e++)
			{
				if (i == (k * 5 + e) || j == (k * 5 + e))
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //빨강
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				cout << iBingo[k * 5 + e] << "\t";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			cout << endl;
		}
		cout << "\t    __________________________________________" << endl << endl;
		Sleep(50);

	}

	cout << endl << endl;
	cout << " 섞기가 완료되었습니다! " << endl;
	system("pause>null");

	while (true)
	{
		//빙고 출력! 
		system("cls");

		//빙고 줄이 현재 몇 줄인지 체크해서 화면에 보여준다.
		cout << "현재 빙고 수 : " << C_Bingo << endl;


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
			cout << endl;
		}
		cout << "\t    __________________________________________" << endl << endl;

		//5줄 이상일 경우 게임을 종료한다.
		if (C_Bingo >= 5)
		{
			cout << endl << endl;
			cout << "-----------------------------------" << endl;
			cout << "|       O!O  5 BINGO!  O!O       | " << endl;
			cout << "-----------------------------------" << endl;
			cout << endl << endl;

			break;
		}


		//플레이어는 숫자를 입력한다. 1 ~ 25 사이의 숫자를 입력받아야 한다.
			//입력한 숫자에서 -1 해서 판단한다. 

		cout << "숫자를 선택해주세요!( 1 ~ " << P_SIZE * P_SIZE << " 까지) : " << endl;
		cin >> input;
		input--;

		if (cin.fail() || input < -1 || input >(P_SIZE * P_SIZE - 1))
		{
			cout << "올바른 숫자가 아닙니다. 다시 입력해주세요." << endl;

			cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			system("pause>null");
			continue;
		}
		if ((input + 1) == ENDNUM)
		{
			//0을 입력하면 게임을 종료한다.
			cout << " 종료를 누루셨습니다. ";
			break;
		}


		//숫자 목록 중 숫자를 찾아서 *로 만들어준다.
		if (iCheck[VALUE][input])
		{
			cout << " 이 숫자는 이미 선택되었습니다! : " << input + 1 << endl;
			system("pause>null");
			continue;
		}
		else
		{
			iCheck[VALUE][input] = true; //이 숫자는 사용중입니다! 

			// 숫자 위치 찾기 

			for (int i = 0; i < P_SIZE * P_SIZE; i++)
			{
				if (iBingo[i] == (input + 1))
					iCheck[STATE][i] = true; // 이 위치는 * 상태입니다!
			}

		}

		//숫자를 *로 만든 후에 빙고 줄 수를 체크한다.
		//5 * 5이기 때문에 가로 5줄 세로 5줄 대각선 2줄이 나올 수 있다.


		C_Depth[0] = C_Depth[1] = true;
		C_Bingo = 0;

		for (int i = 0; i < P_SIZE; i++)
		{
			C_Length = C_Height = true;
			for (int j = 0; j < P_SIZE; j++)
			{
				// 가로줄
				if (!iCheck[STATE][i * P_SIZE + j]) C_Length = false;
				// 세로줄 
				if (!iCheck[STATE][i + j * P_SIZE]) C_Height = false;
			}
			if (C_Length) C_Bingo++;
			if (C_Height) C_Bingo++;

			// 대각선 
			if (!iCheck[STATE][(P_SIZE * i) + i]) C_Depth[0] = false;
			if (!iCheck[STATE][(P_SIZE * i) + (P_SIZE - i - 1)]) C_Depth[1] = false;

		}
		if (C_Depth[0]) C_Bingo++;
		if (C_Depth[1]) C_Bingo++;





	}
	return 0;
}
