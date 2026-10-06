// ============================================================
// TP2 - Calculatrice
// Charles-Olivier Sabourin (2657394)
// Description : Calculatrice qui effectue des operations sur
// des nombres a virgule et conserve le resultat entre les
// operations.
// ============================================================

#include <iostream>
#include <string>
#include <format>
using namespace std;

int main()
{
    setlocale(LC_ALL, "en_US");

    double resultat = 0;
    string message = "";

    bool programmeActif = true;
    while (programmeActif)
    {
        // Afficher l'en-tete et le menu
        cout << "************************************************************\n";
        cout << "* Calculatrice *\n";
        cout << "* Par Charles-Olivier Sabourin (2657394) *\n";
        cout << "************************************************************\n";
        cout << message;
        message = "";
        cout << format("Resultat : {}\n", resultat);
        cout << "+) Addition\n";
        cout << "-) Soustraction\n";
        cout << "*) Multiplication\n";
        cout << "/) Division\n";
        cout << "^) Exposant\n";
        cout << "!) Factorielle\n";
        cout << "s) Serie de Taylor\n";
        cout << "r) Rectangle\n";
        cout << "t) Triangle\n";
        cout << "q) Quitter\n";

        bool choixValide = true;
        do
        {
            choixValide = true;
            cout << "Choisir une operation ou entrer un nouveau resultat : ";

            string chaine;
            cin >> chaine;

            char choixMenu = chaine.length() == 1 ? chaine[0] : '\0';

            switch (choixMenu)
            {
                case '+':
                {
                    bool nombreValide = true;
                    do
                    {
                        nombreValide = true;
                        cout << "Entrer un nombre : ";

                        string chaineNombre;
                        cin >> chaineNombre;

                        try
                        {
                            size_t nombreCaracteresConvertis;
                            double nombre = stod(chaineNombre, &nombreCaracteresConvertis);

                            if (nombreCaracteresConvertis < chaineNombre.length())
                            {
                                throw exception();
                            }

                            double ancienResultat = resultat;
                            resultat = ancienResultat + nombre;
                            message = format("Operation : {} + {} = {}\n", ancienResultat, nombre, resultat);
                        }
                        catch (...)
                        {
                            cout << "Erreur : nombre invalide, doit etre un nombre a virgule !\n";
                            nombreValide = false;
                        }
                    } while (!nombreValide);
                    break;
                }
                case '-':
                {
                    bool nombreValide = true;
                    do
                    {
                        nombreValide = true;
                        cout << "Entrer un nombre : ";

                        string chaineNombre;
                        cin >> chaineNombre;

                        try
                        {
                            size_t nombreCaracteresConvertis;
                            double nombre = stod(chaineNombre, &nombreCaracteresConvertis);

                            if (nombreCaracteresConvertis < chaineNombre.length())
                            {
                                throw exception();
                            }

                            double ancienResultat = resultat;
                            resultat = ancienResultat - nombre;
                            message = format("Operation : {} - {} = {}\n", ancienResultat, nombre, resultat);
                        }
                        catch (...)
                        {
                            cout << "Erreur : nombre invalide, doit etre un nombre a virgule !\n";
                            nombreValide = false;
                        }
                    } while (!nombreValide);
                    break;
                }
                case '*':
                {
                    bool nombreValide = true;
                    do
                    {
                        nombreValide = true;
                        cout << "Entrer un nombre : ";

                        string chaineNombre;
                        cin >> chaineNombre;

                        try
                        {
                            size_t nombreCaracteresConvertis;
                            double nombre = stod(chaineNombre, &nombreCaracteresConvertis);

                            if (nombreCaracteresConvertis < chaineNombre.length())
                            {
                                throw exception();
                            }

                            double ancienResultat = resultat;
                            resultat = ancienResultat * nombre;
                            message = format("Operation : {} * {} = {}\n", ancienResultat, nombre, resultat);
                        }
                        catch (...)
                        {
                            cout << "Erreur : nombre invalide, doit etre un nombre a virgule !\n";
                            nombreValide = false;
                        }
                    } while (!nombreValide);
                    break;
                }
                case '/':
                {
                    bool nombreValide = true;
                    do
                    {
                        nombreValide = true;
                        cout << "Entrer un nombre : ";

                        string chaineNombre;
                        cin >> chaineNombre;

                        try
                        {
                            size_t nombreCaracteresConvertis;
                            double nombre = stod(chaineNombre, &nombreCaracteresConvertis);

                            if (nombreCaracteresConvertis < chaineNombre.length())
                            {
                                throw exception();
                            }

                            if (nombre == 0)
                            {
                                message = "Operation annulee : impossible de diviser par 0 !\n";
                            }
                            else
                            {
                                double ancienResultat = resultat;
                                resultat = ancienResultat / nombre;
                                message = format("Operation : {} / {} = {}\n", ancienResultat, nombre, resultat);
                            }
                        }
                        catch (...)
                        {
                            cout << "Erreur : nombre invalide, doit etre un nombre a virgule !\n";
                            nombreValide = false;
                        }
                    } while (!nombreValide);
                    break;
                }
                case '^':
                    // TODO : exposant
                    break;
                case '!':
                    // TODO : factorielle
                    break;
                case 's':
                    // TODO : serie de Taylor
                    break;
                case 'r':
                    // TODO : rectangle
                    break;
                case 't':
                    // TODO : triangle
                    break;
                case 'q':
                    cout << "Appuyer sur une touche pour continuer.\n";
                    programmeActif = false;
                    break;
                default:
                    try
                    {
                        size_t nombreCaracteresConvertis;
                        double nombreVirgule = stod(chaine, &nombreCaracteresConvertis);

                        if (nombreCaracteresConvertis < chaine.length())
                        {
                            throw exception();
                        }

                        resultat = nombreVirgule;
                    }
                    catch (...)
                    {
                        cout << "Erreur : l'operation ou le nombre est invalide.\n";
                        choixValide = false;
                    }
                    break;
            }
        } while (!choixValide);
    }
}
