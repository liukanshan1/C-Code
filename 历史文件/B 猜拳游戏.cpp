#include <iostream>
using namespace std;
int main()
{
	int s, r, p, c;
	char a, b;
	while (cin >> a >> b)
	{
		c = a - b;
		if (c > 0)
		{
			if (c == 3)
			{
				cout << "player1 win" << endl;
				goto FLAG;
			}
			cout << "player2 win" << endl;

		}
		else if (c < 0)
		{
			if (c == -3)
			{
				cout << "player2 win" << endl;
				goto FLAG;
			}
			cout << "player1 win" << endl;

		}
		else
		{
			cout << "draw" << endl;
		}
	FLAG:;

	}
}									//by Palettone


/*
#include <iostream>
using namespace std;
int main()
{
	char a, b;
	while (cin>>a>>b)
	{
		if (a==b)
		{
			cout << "draw" << endl;
		}
		if (a=='s' && b == 'p')			//ע�ⵥ����
		{
			cout << "awin";
		}								//�������оٵİ취��δ���

	}
}						//by Aroc
*/