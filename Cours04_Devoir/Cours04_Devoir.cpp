// Cours04_Devoir.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
/*
    Auteur: Charles-Olivier Sabourin
    Date: 2026-08-28
    Descriptions: Devoir04
*/

#include <iostream>
#include <string>
#include <format>

using namespace std;




int main()
{
    setlocale(LC_ALL, "fr_CA.UTF-8");

    std::cout << "Hello World!\n";


    // *** Exercice ## (ex. 01) **** 
// Description de l’exercice 
    int a = 10.0 + 12 / 8;                        // 11.5 
    double b = 27 + 3 / 14;                      // 27.21 
    double c = (10 + 20 + 30 + 40 + 50) / 11;    // 13.6363... 
    int d = (int)c;                               // 13 
    int e = (180 / 7) + c / 2;                   // 32.5321... 
    double f = d / 15;                           // 0.8666... 

    cout << format("a: {:.2f} \n", a ); // Ex. ne donne pas la valeur attendue 11.5 


}




