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
	//숙제: 숫자 빙고 게임 만들기

	//1 ~ 25까지 숫자가 있고 이 숫자를 골고루 섞어서 5 * 5로 출력한다.
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


	//무작위!
	system("cls");
	for (int i = P_SIZE * P_SIZE - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);

		if (i == j)
			continue;
		int iTemp = iBingo[i];
		iBingo[i] = iBingo[j];
		iBingo[j] = iTemp;

		//컴퓨터 섞기 
		int a = rand() % (i + 1);
		if (i == a)
			continue;

		iTemp = iComputer[i];
		iComputer[i] = iComputer[a];
		iComputer[a] = iTemp;

		//섞는거 출력 이쁘게. 

		Sleep(100);
		system("cls");

		cout << endl << endl;
		cout << "\t    __________________ BINGO ________________" << "\t\t" << "    __________________ COMPU ________________" << endl << endl;
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


			cout << "\t\t";

			for (int c = 0; c < P_SIZE; c++)
			{
				if (i == (k * 5 + c) || a == (k * 5 + c))
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //빨강
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				cout << iComputer[k * 5 + c] << "\t";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			cout << endl << endl << endl;
		}
		cout << "\t    __________________________________________" << "\t\t" << "    __________________________________________" << endl;

	}

	cout << endl << endl;
	cout << " 섞기가 완료되었습니다! " << endl;
	system("pause>null");



	while (true)
	{
		//빙고 출력! 
		system("cls");

		//빙고 줄이 현재 몇 줄인지 체크해서 화면에 보여준다.
		cout << endl;
		cout << "\t현재 빙고 수 : " << C_Bingo << "\t\t" << "\t\t\t\t 컴퓨터 현재 빙고 수 : " << C_Computer << endl;
		cout << "\t\t\t\t\t\t\t\t\t 컴퓨터가 입력했던 수  : " << Cinput + 1 << endl;


		cout << endl;
		cout << "\t    __________________ BINGO ________________" << "\t\t" << "    __________________ COMPU ________________" << endl << endl;
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
		cout << "\t    __________________________________________" << "\t\t" << "    __________________________________________" << endl;


		//5줄 이상일 경우 게임을 종료한다.
		if (C_Bingo >= 5 || C_Computer >= 5)
		{
			cout << endl << endl;
			cout << "-------------------------------------------" << endl;
			cout << "|       O!O  5 BINGO!" << (C_Bingo >= C_Computer ? "Player " : "Computer ") << "Win  O!O       | " << endl;
			cout << "-------------------------------------------" << endl;
			cout << endl << endl;

			break;
		}


		//플레이어는 숫자를 입력한다. 1 ~ 25 사이의 숫자를 입력받아야 한다.
			//입력한 숫자에서 -1 해서 판단한다. 

		cout << endl;
		cout << "숫자를 선택해주세요!( 1 ~ " << P_SIZE * P_SIZE << " 까지) : " << endl;
		cin >> input;
		input--;


		////테스트 
		//for (int i = 0; i < P_SIZE * P_SIZE; i++)
		//	cout << "[" << i << "] " << iComputerCheck[STATE][i] << endl;


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


		iCheck[VALUE][input] = true; //이 숫자는 사용중입니다! 
		iComputerCheck[VALUE][input] = true;

		// 숫자 위치 찾기 
		for (int i = 0; i < P_SIZE * P_SIZE; i++)
		{
			if (iBingo[i] == (input + 1))
				iCheck[STATE][i] = true; // 이 위치는 * 상태입니다!

			if (iComputer[i] == (input + 1))
				iComputerCheck[STATE][i] = true; // 이 위치는 * 상태입니다!

		}


		//컴퓨터 턴 실행 
		if (Level == EASY)
		{
			while (true) {
				Cinput = rand() % (P_SIZE * P_SIZE);

				if (iComputerCheck[VALUE][Cinput] || input == Cinput)
					continue;
				else
					break;
			}
		}
		else if (Level == HARD) // ,HARd!!
		{
			//여기에 가장 적절한 부분을 찾는 로직을 넣어서 Cinput으로 만들어주기. 그러면 됌. 
			//별 갯수 확인하기. 

			int HardModeRogic[P_SIZE * 2 + 2]{ 0 };

			for (int i = 0; i < P_SIZE; i++)
			{
				for (int j = 0; j < P_SIZE; j++)
				{
					// 가로줄
					if (iComputerCheck[STATE][i * P_SIZE + j]) HardModeRogic[i]++;  // 0 1 2 3 4 에저장
					// 세로줄 
					if (iComputerCheck[STATE][i + j * P_SIZE])  HardModeRogic[P_SIZE + i]++; //  5 6 7 8 9 에 저장 

				}
				// 대각선 
				if (iComputerCheck[STATE][(P_SIZE * i) + i]) HardModeRogic[P_SIZE * 2]++; //10
				if (iComputerCheck[STATE][(P_SIZE * i) + (P_SIZE - i - 1)])  HardModeRogic[P_SIZE * 2 + 1]++; //11

			}

			//가장 큰 별 갯수줄의 위치 확인하기. (빙고는아닌.) 
			int Maxdax{ 0 };

			while (!(HardModeRogic[Maxdax] < P_SIZE)) {
				Maxdax = rand() % P_SIZE * 2 + 2;
			}

			for (int i = 1; i < P_SIZE * 2 + 2; i++) { //0부터 들어감
				if (HardModeRogic[i] > HardModeRogic[Maxdax] && HardModeRogic[i] < P_SIZE)
					Maxdax = i;
			}

			//거기서 하나 선택하기. cinput, 가장 유력한곳 은 HardModeRogic[Maxdax]가 가리키는 위치의 줄.
			switch (Maxdax / P_SIZE)
			{
			case 0:
				//가로줄임
				for (int i = 0; i < P_SIZE; i++)
				{
					if (!iComputerCheck[STATE][(Maxdax % P_SIZE) * P_SIZE + i]) //적절한 위치를 선정 후, 거기 값cinput으로 받아옴. 1~ 이므로 --; 
					{
						Cinput = iComputer[(Maxdax % P_SIZE) * P_SIZE + i];
						if ((Cinput - 1) != input)
							break;
					}
				}
				break;
			case 1:
				//새로줄임
				for (int i = 0; i < P_SIZE; i++)
				{
					if (!iComputerCheck[STATE][(Maxdax % P_SIZE) + i * P_SIZE])
					{
						Cinput = iComputer[(Maxdax % P_SIZE) + i * P_SIZE];

						if ((Cinput - 1) != input)
							break;
					}
				}
				break;
			case 2:
				//대각선임

				for (int i = 0; i < P_SIZE; i++)
				{
					if (Maxdax == P_SIZE * 2) //10
					{
						if (!iComputerCheck[STATE][(P_SIZE * i) + i])
						{
							Cinput = iComputer[(P_SIZE * i) + i];

							if ((Cinput - 1) != input)
								break;
						}
					}
					else if (Maxdax == P_SIZE * 2 + 1)//11
					{
						if (!iComputerCheck[STATE][(P_SIZE * i) + (P_SIZE - i - 1)])
						{
							Cinput = iComputer[(P_SIZE * i) + (P_SIZE - i - 1)];

							if ((Cinput - 1) != input)
								break;
						}
					}
				}
				break;
			}
			Cinput--;
		}


		//두개 다 * 표시하기.  Player

		iCheck[VALUE][Cinput] = true;
		iComputerCheck[VALUE][Cinput] = true;

		// 숫자 위치 찾기 
		for (int i = 0; i < P_SIZE * P_SIZE; i++)
		{
			if (iBingo[i] == (Cinput + 1))
				iCheck[STATE][i] = true;

			if (iComputer[i] == (Cinput + 1))
				iComputerCheck[STATE][i] = true;
		}


		//숫자를 *로 만든 후에 빙고 줄 수를 체크한다.
		//5 * 5이기 때문에 가로 5줄 세로 5줄 대각선 2줄이 나올 수 있다.

		C_Depth[0] = C_Depth[1] = C_cDepth[0] = C_cDepth[1] = true;
		C_Bingo = C_Computer = 0;

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

			//컴퓨터 
			C_Length = C_Height = true;
			for (int j = 0; j < P_SIZE; j++)
			{
				// 가로줄
				if (!iComputerCheck[STATE][i * P_SIZE + j]) C_Length = false;
				// 세로줄 
				if (!iComputerCheck[STATE][i + j * P_SIZE]) C_Height = false;
			}
			if (C_Length) C_Computer++;
			if (C_Height) C_Computer++;


			// 대각선 
			if (!iCheck[STATE][(P_SIZE * i) + i]) C_Depth[0] = false;
			if (!iCheck[STATE][(P_SIZE * i) + (P_SIZE - i - 1)]) C_Depth[1] = false;

			//컴퓨터 대각선 
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
