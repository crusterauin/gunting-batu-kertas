#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void delay(int seconds) {
    time_t start_time = time(NULL);
    while (time(NULL) < start_time + seconds);
}

void countdown() {
    for (int i = 3; i > 0; --i) {
        cout << i << "...\n";
        delay(1);
    }
}

string nilaiKeString(int nilai) {
    switch (nilai) {
        case 1:
            return "Kertas";
        case 2:
            return "Batu";
        case 3:
            return "Gunting";
        default:
            return "Nilai tidak valid";
    }
}

void kbg(int p, int k) {
    string senjataPlayer = nilaiKeString(p);
    string senjataKomputer = nilaiKeString(k);

    if (p == 1 && k == 2 || k == 1 && p == 3 || k == 3 && p == 2) {
        countdown();
        cout << senjataPlayer << " melawan " << senjataKomputer << "\n";
        cout << ">>>Kamu menang!!!<<<\n";
    } else if (p == 1 && k == 3 || k == 1 && p == 2 || p == 3 && k == 2 ) {
        countdown();
        cout << senjataPlayer << " melawan " << senjataKomputer << "\n";
        cout << ">>>Kamu kalah!!!<<<\n";
    } else if (p == k) {
        countdown();
        cout << senjataPlayer << " melawan " << senjataKomputer << "\n";
        cout << ">>>Kalian seri!!!<<<\n";
    }
}

int main(){
	int senjataPlayer;
	int senjataKomputer;
	srand(static_cast<unsigned int>(time(0)));
	char ulangiProgram;
	
	do {
	system("cls");
	cout << "Selamat datang di game Kertas Batu Gunting!!!\n";
	cout << "Pilih senjatamu!\n";
	cout << "1. Kertas\n";
	cout << "2. Batu\n";
	cout << "3. Gunting\n";
	cin >> senjataPlayer;
	senjataKomputer = rand() % 3 + 1;
	kbg(senjataPlayer, senjataKomputer);
	
	cout << "Mau ulangi program? (Y/N)\n";
	cin >> ulangiProgram;
	} while (ulangiProgram == 'y' || ulangiProgram == 'Y');
	
	return 0;
}
