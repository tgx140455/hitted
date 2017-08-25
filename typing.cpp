#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

int hitted(int n, int delay)
{
	int i, m = 0, w;
	char ch, key;
	clock_t t;            //1
	cout << endl;
	for (i = 0; i < n; i++)
	{

		ch = 'A' + rand() % 26;
		if (rand() % 2) ch += 'a' - 'A';  //2
		w = rand() & 40 + 20;

		cout << setw(w) << ch << '\r';   //3

		t = clock() + delay;
		while (clock() <= t)
		{

			if (kbhit())
			{

				key = getch();
				if (key == ch)
					m++;
				else
					cout << "\a\r";  //4
				break;
			}
		}
		cout << setw(w) << ' ' << '\r';
	}
	return m;
}

int main()
{
	int n = 10, delay = 20000, m;
	time_t t;
	srand(time(&t));

	m = hitted(n, delay);

	cout << "\n" << m << "/" << n << " = "
		<< 100.0*m / n << "%" << endl;

	cout << "Press <ESC> ..." << endl;
	while (getch() != 27);   //5
	return 0;
}