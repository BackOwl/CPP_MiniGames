#include <iostream>

using std::cout;
using std::endl;


#define Pay 5
#define TrumpCount 52


enum CardShape
{
	Spade, Heart, Diamond, Clover
};


enum CardNum
{
	A = 1, J = 11, Q, K,
};

enum SeedName
{
	Player, Banker
};


struct Test
{
	int		a;
	float	b;
};


int main()
{
	// Trump Card를 각각 5개씩 분배하기. 
	// 알고리즘, STL , String 없이 배열만 이용해 구현하기 . 

// 52장의 트럼프 카드 중 
// Player에게 5장, Banker에게 5장씩 랜덤하게 겹치지 않고 분배하여 출력하는 프로그램을 만들어주세요.
// 스페이드, 하트, 다이아, 클럽. 각 13개씩. 
	//srand(time(NULL));


	int Trump[TrumpCount] = {};
	int Card[2][Pay] = {}; //0 = P, 1 = B

	int CheckNum(0), randint = 0, randint2{ 0 }, num{ 0 };


	srand(time(NULL));


	for (int i = 0; i < TrumpCount; i++)
		Trump[i] = i;

	//shuffle
	for (int i = 0; i < TrumpCount; i++)
	{
		randint = rand() % TrumpCount;
		randint2 = rand() % TrumpCount;

		num = Trump[randint2];
		Trump[randint2] = Trump[randint];
		Trump[randint] = num;

	}

	while (true) {



		if (CheckNum * Pay * 2 > (TrumpCount - (Pay * 2)))
		{
			cout << " -----카드가 소진되었습니다.---- " << endl;
			break;
		}
		else {
			system("cls");
		}


		// 나눠주는 부분

		for (int i = 0; i < 2; i++)
		{
			for (int t = 0; t < Pay; t++)
			{

				Card[i][t] = Trump[(CheckNum * Pay * 2) + i * Pay + t];

			}
		}



		// 표기하기
		cout << endl << endl;
		cout << " ----------- 카드를 모두 나눠주었습니다. ----------" << endl << endl << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << " 플레이어 : " << (i == 0 ? "Player" : "Banker") << "  의 트럼프카드. " << endl;
			cout << " --------------------------------------------------" << endl;
			for (int t = 0; t < Pay; t++)
			{
				switch (Card[i][t] / 13)
				{
				case Spade:
					cout << "Spade ";
					break;
				case Heart:
					cout << "Heart ";
					break;
				case Diamond:
					cout << "Diamond ";
					break;
				case Clover:
					cout << "Clover ";
					break;
				default: break;
				}

				switch (Card[i][t] % 13 + 1)
				{
				case J:
					cout << "J ";
					break;
				case Q:
					cout << "Q ";
					break;
				case K:
					cout << "K ";
					break;
				case A:
					cout << "A ";
					break;
				default:
					cout << Card[i][t] % 13 + 1;
				}

				cout << endl;
			}

			cout << endl << endl;
		}

		//크기 확인하기. 
		CheckNum += 1;

		cout << "각자 소지한 카드 갯수: " << CheckNum * Pay << endl;
		system("pause>null");
	}
	return 0;
}

/*#include <iostream>

using std::cout;
using std::endl;


#define Pay 5


enum CardShape {
	Spade, Heart, Diamond, Clover
};


enum CardNum{
	A =1, J =11, Q, K,
};

enum SeedName{
	Player, Banker
};




int main()
{
	// Trump Card 분배

// 52장의 트럼프 카드 중
// Player에게 5장, Banker에게 5장씩 랜덤하게 겹치지 않고 분배하여 출력하는 프로그램을 만들어주세요.
// 스페이드, 하트, 다이아, 클럽. 각 13개씩.
	//srand(time(NULL));


	bool Trump[52]{ 0 };
	int Card[2][Pay]{ 0 }; //0 = P, 1 = B

	int CheckNum{ 0 };
	int randint{ 0 };
	srand(time(NULL));


	while (true) {

		////다시 초기화 구문 *(반복문 사용시 넣을 애들)
		//for (int i = 0; i < (sizeof(Trump) / sizeof(bool)); i++)
		//	Trump[i] = false;


		//for (int i = 0; i < Pay; i++)
		//{
		//	Card[Player][i] = 0;
		//	Card[Banker][i] = 0;
		//}

		//크기 확인하기.
		CheckNum += 1;

		if( CheckNum *Pay*2 > (52-(Pay*2)))
		{
			cout << " -----카드가 소진되었습니다.---- " << endl;
			break;
		}
		else {
			system("cls");
		}
		// 나눠주는 부분


		for (int i = 0; i < 2; i++)
		{
			for (int t = 0; t < Pay; t++)
			{
				randint = rand() % 52;

				while (Trump[randint]) { // Trump에서 꺼내온게 나눠주지 않은 애라면
					randint = rand() % 52;
				}

				Trump[randint] = true;
				Card[i][t] = randint;
			}
		}

		// 표기하기
		cout << endl << endl;
		cout << " ----------- 카드를 모두 나눠주었습니다. ----------" << endl << endl << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << " 플레이어 : " << (i == 0 ? "Player" : "Banker") << "  의 트럼프카드. " << endl;
			cout << " --------------------------------------------------" << endl;
			for (int t = 0; t < Pay; t++)
			{
				switch (Card[i][t] /13)
				{
				case Spade:
					cout << "Spade ";
					break;
				case Heart:
					cout << "Heart ";
					break;
				case Diamond:
					cout << "Diamond ";
					break;
				case Clover:
					cout << "Clover ";
					break;
				default: break;
				}

				switch (Card[i][t] % 13 + 1)
				{
				case J:
					cout << "J ";
					break;
				case Q:
					cout << "Q ";
					break;
				case K:
					cout << "K ";
					break;
				case A:
					cout << "A ";
					break;
				default:
					cout << Card[i][t] % 13 + 1;
				}

				cout << endl;
			}

			cout << endl << endl;
		}

		cout << "각자 소지한 카드 갯수: " << CheckNum << endl;
		system("pause>null");
	}
	return 0;
}

*/