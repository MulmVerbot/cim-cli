#include <iostream>
#include <string>
#include <fstream>
#include <format>

// wenn man das so macht statt direkt namespace std, kommt man viel schwieriger in schwulitäten. (also hab ich gehört)
using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::ofstream;
using std::format;

void Eingabe_Modus_an();

void uebergang(){
    cout << "\n\n";
    cout << "#######################################\n";
}



void cls(){
    cout << "\033[2J\033[H"; // das hier ist die Escape suequenz (oder wie auch immer das heißt) um den Bildschirm zu clearen, und den Cursor oben links zu platzieren
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

void eintrag_speichern(string eintrag_zu_speichern){
    ofstream datei("Eintrag.txt"); // datei ufmachen
    if (!datei.is_open()){
        std::cerr << "Fehler, kriege die Datei nicht auf.\n";
        cout << "abgeschissen\n";
    }

    datei << eintrag_zu_speichern; // reinschreiben
    cout << "Eintrag gespeichert."; // fertsch
    uebergang();
    Eingabe_Modus_an();

}

void Eingabe_Modus_an(){
    cls();
    string Kunde;
    string Problem;
    string Info;

    cout << "#######################################\n";
    cout << "Kunde: ";
    getline(cin, Kunde);
    cout << "#######################################\n";
    cout << "\nProblem: ";
    getline(cin, Problem);
    cout << "#######################################\n";
    cout << "\nInfo: ";
    getline(cin, Info);

    cout << "\nEingegebene Daten:\n=> " << Kunde << "\n=> " << Problem << "\n=> " << Info << "\n";
    string Eintrag = format("#######################################\nKunde: {}\n------\nProblem: {}\n------\nInfo: {}\n#######################################", Kunde, Problem, Info);
    eintrag_speichern(Eintrag);

    
}
int main(){

// hier unten sollen nur ein paar Variablen etc definiert werden, ähnlich wie in der Python Version.
    static string Programm_Name = "CiM";
    static string Version = "0.0";
    Menu(Programm_Name, Version);

    


    return 0;
}


// um mit c++ 20 zu kompilieren und die format funktion nutzen zu können das hier bei g++ nutzen:
// g++ -std=c++20 -O2 main.cpp -o cim-cli.exe