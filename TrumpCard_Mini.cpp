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
	// Trump Card�� ���� 5���� �й��ϱ�. 
	// �˰���, STL , String ���� �迭�� �̿��� �����ϱ� . 

// 52���� Ʈ���� ī�� �� 
// Player���� 5��, Banker���� 5�徿 �����ϰ� ��ġ�� �ʰ� �й��Ͽ� ����ϴ� ���α׷��� ������ּ���.
// �����̵�, ��Ʈ, ���̾�, Ŭ��. �� 13����. 
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
			cout << " -----ī�尡 �����Ǿ����ϴ�.---- " << endl;
			break;
		}
		else {
			system("cls");
		}


		// �����ִ� �κ�

		for (int i = 0; i < 2; i++)
		{
			for (int t = 0; t < Pay; t++)
			{

				Card[i][t] = Trump[(CheckNum * Pay * 2) + i * Pay + t];

			}
		}



		// ǥ���ϱ�
		cout << endl << endl;
		cout << " ----------- ī�带 ��� �����־����ϴ�. ----------" << endl << endl << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << " �÷��̾� : " << (i == 0 ? "Player" : "Banker") << "  �� Ʈ����ī��. " << endl;
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

		//ũ�� Ȯ���ϱ�. 
		CheckNum += 1;

		cout << "���� ������ ī�� ����: " << CheckNum * Pay << endl;
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
	// Trump Card �й�

// 52���� Ʈ���� ī�� ��
// Player���� 5��, Banker���� 5�徿 �����ϰ� ��ġ�� �ʰ� �й��Ͽ� ����ϴ� ���α׷��� ������ּ���.
// �����̵�, ��Ʈ, ���̾�, Ŭ��. �� 13����.
	//srand(time(NULL));


	bool Trump[52]{ 0 };
	int Card[2][Pay]{ 0 }; //0 = P, 1 = B

	int CheckNum{ 0 };
	int randint{ 0 };
	srand(time(NULL));


	while (true) {

		////�ٽ� �ʱ�ȭ ���� *(�ݺ��� ���� ���� �ֵ�)
		//for (int i = 0; i < (sizeof(Trump) / sizeof(bool)); i++)
		//	Trump[i] = false;


		//for (int i = 0; i < Pay; i++)
		//{
		//	Card[Player][i] = 0;
		//	Card[Banker][i] = 0;
		//}

		//ũ�� Ȯ���ϱ�.
		CheckNum += 1;

		if( CheckNum *Pay*2 > (52-(Pay*2)))
		{
			cout << " -----ī�尡 �����Ǿ����ϴ�.---- " << endl;
			break;
		}
		else {
			system("cls");
		}
		// �����ִ� �κ�


		for (int i = 0; i < 2; i++)
		{
			for (int t = 0; t < Pay; t++)
			{
				randint = rand() % 52;

				while (Trump[randint]) { // Trump���� �����°� �������� ���� �ֶ��
					randint = rand() % 52;
				}

				Trump[randint] = true;
				Card[i][t] = randint;
			}
		}

		// ǥ���ϱ�
		cout << endl << endl;
		cout << " ----------- ī�带 ��� �����־����ϴ�. ----------" << endl << endl << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << " �÷��̾� : " << (i == 0 ? "Player" : "Banker") << "  �� Ʈ����ī��. " << endl;
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

		cout << "���� ������ ī�� ����: " << CheckNum << endl;
		system("pause>null");
	}
	return 0;
}

*/