#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <ctime>

using namespace std;
int speed = 0;
int carGears = 0;
int tachometer = 1500;
float dist = 0;
void instrukcja() {
	cout << "=====INSTRUKCJA=====" << endl;
	cout << "W - do przodu \n S - hamulec \n 1,2,3,4,5,6,R - biegi \n E - wlaczenie silnika \n P - wylaczenie silnika"<< endl;
	Sleep(5000);
	system("cls");
}
void deskaRozdzielcza() {
	cout << "=====DESKA ROZDZIELCZA=====" << endl;
	cout << "predkosc " << speed << endl;
	cout << "bieg " << carGears << endl;
	cout << "obrotomierz " << tachometer << " /8000" << endl;
	cout << "dystans " << dist << " km"<< endl;
}


int main() {
	//instrukcja();
	
start:
	cout << "Aby uruchomic auto wcisnij klawisz e" << endl;

	if (_getch() == 'e') {
		while (true)
		{
			if (_kbhit()) {
				switch (_getch()) {
				case 'w':

					if (carGears >= 1) {
						speed++;
					}

					else if (carGears == 0) {
						tachometer *= 1.1;
					}
					if (tachometer < 7000) {
						tachometer *= 1.03;
					}
					else if (tachometer > 7000) {
						tachometer == 7000;
					}
					if (tachometer < 1000) {
						tachometer == 1000;
					}
					if (speed > 220) {
						speed = 220;
					}
					if (carGears == 1 && speed > 50) {
						speed = 50;
					}
					if (carGears == 2 && speed > 70) {
						speed = 70;
					}
					if (carGears == 3 && speed > 90) {
						speed = 90;
					}
					if (carGears == 4 && speed > 120) {
						speed = 120;
					}
					if (carGears == 5 && speed > 150) {
						speed = 150;
					}
					if (carGears == 7 && speed == 0){
						speed = speed - 1;
					}
					if (carGears == 0 && tachometer > 7500) {
						tachometer = 7500;
					}
					if (speed > 0) {
						dist += (speed * 1.1) / 5000;
					}
					if (carGears == 7 && speed >= 20) {
						speed = 20;
					}
					if (tachometer > 5000) {
						cout << "zmien bieg na wyzszy!";
					}
					
					break;
				case 's':
					if (speed > 0) {
						speed--;
						tachometer *= 0.987;
					}
					else if (tachometer < 1500) {
						tachometer == 1500;
					}
					break;
				/*
				case 'r':
					if (biegi == 7 && predkosc <= 0) {
						predkosc--;
					}
					if (predkosc <= -20) {
						predkosc = -20;
					}
					
					break;
					*/
				case '1':
					carGears =1;
					break;
				case '2':
					carGears = 2;
					tachometer = 2000;
					break;
				case '3':
					carGears = 3;
					tachometer = 2000;
					break;
				case '4':
					carGears = 4;
					tachometer = 2000;
					break;
				case '5':
					carGears = 5;
					tachometer = 2400;
					break;
				case '6':
					carGears = 6;
					tachometer = 2500;
					break;
				case '7':
					if (carGears == 0) {
						carGears = 7;
					}
					break;
				case '0':
					carGears = 0;
					break;
				case 'p':
					if (speed == 0 & carGears == 0) {
						cout << "Wylaczyles silnik " << endl;
						goto start;
					}
					break;
				default:
					break;
				}
			} 
			if (tachometer < 1500) {
				cout << "zmien bieg na nizszy!";
			}
			if (_kbhit() == NULL) {
				if (tachometer > 1500) {
					tachometer *= 0.987;
				}
				else if (speed > 0) {
					speed--;
				}
			}
			Sleep(25);
			system("cls");
			deskaRozdzielcza();
		}

	}
	else {
		cout << "Ups chyba wziales nie te kluczki" << endl;
	}
	goto start;
	return 0;
}