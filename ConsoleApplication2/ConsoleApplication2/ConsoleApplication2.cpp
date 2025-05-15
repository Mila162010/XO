#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

// x (1(X) или 2(O)) чей ход
void input(int x, int mass[]) {
	int a;
	cout << "В какую из девяти клеток вы хотите поставить знак: ";
	cin >> a;
	mass[a - 1] = x;
}

char F23(int x) {
	if (x == 1)
		return 'X';
	else if (x == 2)
		return 'O';
	else
		return ' ';
}

void draw(int mass[]) {
	cout << ' ';
	for (int k = 0; k < 27; k++)
		cout << '_';
	cout << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << '|';
			if (j != 1) {
				for (int m = 0; m < 3; m++)
					cout << "        |";
			}
			else {
				for (int p = 0; p < 3; p++) {
					cout << "    ";
					cout << F23(mass[i * 3 + p]);
					cout << "   |";
				}
			}
			cout << endl;
		}
		cout << '|';
		for (int k1 = 0; k1 < 3; k1++) {
			for (int k = 0; k < 8; k++)
				cout << '_';
			cout << "|";
		}
		cout << endl;
	}
}

int flagF(int mass[], int s) {
	if (mass[0] == mass[1] and mass[1] == mass[2] and mass[2] != 0)
		s = 1;
	else if (mass[3] == mass[4] and mass[4] == mass[5] and mass[5] != 0)
		s = 1;
	else if (mass[6] == mass[7] and mass[7] == mass[8] and mass[8] != 0)
		s = 1;
	else if (mass[0] == mass[3] and mass[3] == mass[6] and mass[6] != 0)
		s = 1;
	else if (mass[1] == mass[4] and mass[4] == mass[7] and mass[7] != 0)
		s = 1;
	else if (mass[2] == mass[5] and mass[5] == mass[8] and mass[8] != 0)
		s = 1;
	else if (mass[0] == mass[4] and mass[4] == mass[8] and mass[8] != 0)
		s = 1;
	else if (mass[2] == mass[4] and mass[4] == mass[6] and mass[6] != 0)
		s = 1;
	return s;
}

int main() {
	setlocale(LC_ALL, "RU");
	while (true) {
		system("cls");
		int mass[9] = {
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
		int s = 0;
		int x = 1, p = 0;
		while (s == 0) {
			system("cls");
			draw(mass);
			input(x, mass);
			s = flagF(mass, s);
			if (s != 0) {
				system("cls");
				draw(mass);
				if (x == 1)
					cout << "Победил первый игрок!";
				else if (x == 2)
					cout << "Победил второй игрок!";
				char h;
				cin >> h;
				break;
			}
			int p = 1;
			for (int i = 0; i < 9; i++)
				p *= mass[i];
			if (p != 0) {
				system("cls");
				draw(mass);
				cout << "Ничья!";
				int h;
				cin >> h;
			}
			if (x == 1)
				x = 2;
			else
				x = 1;
		}
	}
}

