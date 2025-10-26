#include <iostream>
#include <Windows.h>

#define RANGE	3
#define SIZE	9

using std::cout;
using std::endl;



int main()
{
	//String, STL, 알고리즘 없이 배열만으로 구현하세요. 
	/*
	숫자 야구 게임

	1 ~ 9 사이의 랜덤한 숫자 3개를 얻어온다. 단 숫자는 중복되어서는 안된다.
	3개의 숫자는 최종적으로 * * * 의 형태로 출력이 되야 하고,
	이 3개의 숫자를 사용자가 맞추는 게임이다.

	사용자는 이 3개의 숫자를 맞출 때 까지 게임이 종료되면 안되고 계속해서 숫자를 입력해야 한다.

	최종적으로 3개의 숫자를 자리까지 모두 맞출 때 까지 입력하면 게임이 종료된다.
	만약 입력받은 숫자 중 하나라도 0이 있을 경우 게임을 종료한다.



	만약 맞춰야할 숫자가 7 3 8 일 경우

	입력 : 1 2 4를 입력했을 경우 1 2 4는 맞춰야 할 숫자 중 아무것도 없으므로 OUT을 출력한다.
	출력 : Out

	입력 : 7 5 9를 입력했을 경우 7은 맞춰야 할 숫자 중 있고, 위치도 같으므로 Strike판정.
	5, 9는 없으므로 처리하지 않음.
	출력 : 1Strike 0Ball

	입력 : 7 8 6을 입력했을 경우 7은 맞춰야 할 숫자 중 있고, 위치도 같으므로 Strike판정.
	8은 맞춰야 할 숫자 중 있지만 위치가 다르므로 Ball 판정.
	출력 : 1Strike 1Ball
*/


	srand(time(NULL));

	int  Playinput[RANGE]{ 0 }, Randint[SIZE]{ 0 };
	int Strike{ 0 }, Ball{ 0 };

	/*
	for (int i = 0; i < RANGE; i++)
		Randint[i] = rand() % SIZE + 1;
	*/

	//숫자 3개 얻어오기 (중복 불가) 
	for (int i = 0; i < SIZE; i++)
		Randint[i] = i;

	for (int i = SIZE - 1; i > 0; i--) //재활용할거면 Strike와 ball로 쓰기 
	{
		int j = rand() % (i + 1);
		int num = Randint[i];
		Randint[i] = Randint[j];
		Randint[j] = num;

	}


	//Randint 로 어차피 몇개 섞어놀거고 그중 맨 앞 3개만 쓸거니까 배열 하나에 같이씀. 

	cout << endl << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "   컴퓨터가 숫자를 골랐습니다. " << endl;
	cout << "   필요한 범위 수 : " << "1~ 9 사이의 숫자. " << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << endl << endl;
	cout << "Press Enter To Start" << endl;

	system("pause>null");


	//비교해서 출력하기 
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		Strike = Ball = 0;

		//값 입력
		cout << endl << endl;
		cout << "      키를 " << RANGE << "개 입력하세요. " << endl;
		std::cin >> Playinput[0] >> Playinput[1] >> Playinput[2];


		cout << endl << endl;
		cout << "---------------------------------------------------------------------------------" << endl;

		//확인용 
		cout << "컴퓨터가 입력한 숫자 : " << Randint[0] << " " << Randint[1] << " " << Randint[2] << endl;
		cout << "---------------------------------------------------------------------------------" << endl;
		//확인용

		cout << "사용자가 입력한 숫자 : " << Playinput[0] << " " << Playinput[1] << " " << Playinput[2] << endl;
		cout << "---------------------------------------------------------------------------------" << endl;
		cout << endl << endl;

		//입력값 범위 체크 
		if (Playinput[0] / SIZE || Playinput[1] / SIZE || Playinput[2] / SIZE || Playinput[0] <= 0 || Playinput[1] <= 0 || Playinput[2] <= 0)
		{
			cout << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "입력키 범위 초과 하였습니다. 다시 부탁드립니다. " << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << " 필요한 범위 수 : " << "1~ 9 사이의 숫자. " << endl;
			cout << "Press Enter To Restart" << endl;

			system("pause>null");
			continue;
		}


		//Strike Ball 판정 
		for (int i = 0; i < 3; i++)
		{
			if (Playinput[i] == Randint[i])
				Strike++;
			else if (Playinput[i] == Randint[0] || Playinput[i] == Randint[1] || Playinput[i] == Randint[2] && !(Playinput[i] == Randint[i]))
				Ball++;

		}


		//판정 출력 

		cout << "결과값 : ";

		if (Strike == 3)
		{
			//예 쁘 게 
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
			//예 쁘 게 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << " 3Strike! 당신의 성공입니다!" << endl << endl;
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

	//마지막에 결과 출력하기 



	return 0;
}
