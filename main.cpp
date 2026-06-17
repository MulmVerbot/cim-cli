#include <iostream>
#include <string>

// wenn man das so macht statt direkt namespace std, kommt man viel schwieriger in schwulitäten. (also hab ich gehört)
using std::cout;
using std::cin;
using std::string;
using std::getline;

void uebergang(){
    cout << "\n\n";
    cout << "#######################################\n";
}

void cls(){
    cout << "\033[2J\033[H"; // das hier ist die Escape suequenz (oder wie auch immer das heißt) um den Bildschirm zu clearen, und den Cursor oben links zu platzieren
};

void Eingabe_Modus_an(){
    cls();
    string Kunde;
    string Problem;
    string Info;

    cout << "Kunde: ";
    getline(cin, Kunde);
    cout << "\nProblem: ";
    getline(cin, Problem);
    cout << "\nInfo: ";
    getline(cin, Info);

    cout << "\nEingegebene Daten:\n=> " << Kunde << "\n=> " << Problem << "\n=> " << Info << "\n";
    getline(cin, Info);

    
}

void Menu(string Programm_Name, string Version){
    string Menu_auswahl_e;
    int Menu_auswahl;


// erste cli-gui(? nennt man das so?)
    cout << "#######################################\n";
    cout << "#          -" << Programm_Name << "                       #\n";
    cout << "#          -Version: " << Version << "              #\n";
    cout << "#######################################";
    
    cout << "\n\n";
    cout << "Auswahl treffen:\n";
    cout << "1: Eingabe-Modus starten\n2: Wiki\n3: Schnelles Tutorial\n4: Cheat Sheet\n"; 


    getline(cin, Menu_auswahl_e);


    try {
        Menu_auswahl = std::stoi(Menu_auswahl_e);
    } catch (...) {
        Menu_auswahl = 0;
    }

    switch (Menu_auswahl){
        case 0:
            cls();
            cout << "Das war keine gültige Eingabe.\n";
            Menu(Programm_Name, Version);
            break;

        case 1:
            uebergang();
            Eingabe_Modus_an();
        break;    

        case 2:
            uebergang();

        break;

        case 3:
            uebergang();
        break;

        case 4:
            uebergang();
        break;
    }
}

int main(){

// hier unten sollen nur ein paar Variablen etc definiert werden, ähnlich wie in der Python Version.
    static string Programm_Name = "CiM";
    static string Version = "0.0";
    Menu(Programm_Name, Version);

    


    return 0;
}