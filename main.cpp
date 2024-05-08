#include "Menu.h"
#include "Simulation.h"

int main() {
    int mode;
    cout << "Chcesz przeprowadzić:\n";
    cout << "1. Otworzenie programu w menu:\n";
    cout << "2. Symulacja:\n";
    cin >> mode;
    if(mode == 1) {
        int type;
        while(true) {
            cout << "Wybierz typ, na którym chcesz operować:\n";
            cout << "1. Int\n";
            cout << "2. Float\n";
            cout << "3. Double\n";
            cout << "4. Char\n";
            cout << "5. Zakończ program\n";
            cin >> type;
            if(type == 1) {
                Menu::displayMenuInt();
            } else if (type == 2) {
                Menu::displayMenuFloat();
            } else if(type == 3) {
                Menu::displayMenuDouble();
            } else if(type == 4) {
                Menu::displayMenuChar();
            } else if(type==5){
                break;
            } else {
                cout << "Nie ma takiej opcji!\n";
            }
        }
    } else if(mode == 2) {
        Simulation::simulate();
    } else {
        cout << "Nie ma takiej opcji!\n";
    }

    return 0;
}
