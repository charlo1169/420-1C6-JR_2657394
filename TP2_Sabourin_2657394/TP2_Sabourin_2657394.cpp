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
#include <cmath>
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
                {
                    bool nombreValide = true;
                    do
                    {
                        nombreValide = true;
                        cout << "Entrer l'exposant : ";

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

                            if (nombre != (int)nombre)
                            {
                                throw exception();
                            }

                            int exposant = (int)nombre;

                            if (resultat == 0 && exposant < 0)
                            {
                                message = "Operation annulee : impossible pour 0 d'avoir un exposant negatif !\n";
                            }
                            else
                            {
                                double base = resultat;
                                double nouveauResultat;
                                string calculs = "";

                                if (exposant == 0)
                                {
                                    nouveauResultat = 1;
                                }
                                else if (exposant == 1)
                                {
                                    nouveauResultat = base;
                                }
                                else if (exposant == -1)
                                {
                                    nouveauResultat = 1 / base;
                                }
                                else if (exposant > 1)
                                {
                                    calculs = "Calculs :\n";
                                    double acc = base;
                                    for (int i = 2; i <= exposant; i++)
                                    {
                                        double ancien = acc;
                                        acc = ancien * base;
                                        calculs += format("{} * {} = {}\n", ancien, base, acc);
                                    }
                                    nouveauResultat = acc;
                                }
                                else
                                {
                                    calculs = "Calculs :\n";
                                    double accDenom = base;
                                    int exposantPositif = -exposant;
                                    for (int i = 2; i <= exposantPositif; i++)
                                    {
                                        double ancienDenom = accDenom;
                                        accDenom = ancienDenom * base;
                                        calculs += format("1 / {} * 1 / {} = 1 / {}\n", ancienDenom, base, accDenom);
                                    }
                                    nouveauResultat = 1 / accDenom;
                                }

                                message = format("Operation : {} ^ {} = {}\n", base, exposant, nouveauResultat) + calculs;
                                resultat = nouveauResultat;
                            }
                        }
                        catch (...)
                        {
                            cout << "Erreur : exposant invalide, doit etre un entier !\n";
                            nombreValide = false;
                        }
                    } while (!nombreValide);
                    break;
                }
                case '!':
                {
                    bool nombreValide = true;
                    do
                    {
                        nombreValide = true;
                        cout << "Entrer la factorielle : ";

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

                            if (nombre < 0 || nombre != (int)nombre)
                            {
                                cout << "Erreur : factorielle invalide, doit etre un entier positif !\n";
                                nombreValide = false;
                            }
                            else
                            {
                                int n = (int)nombre;
                                double nouveauResultat = 1;
                                string calculs = "";

                                if (n >= 2)
                                {
                                    calculs = "Calculs :\n";
                                    for (int i = n; i >= 1; i--)
                                    {
                                        double ancien = nouveauResultat;
                                        nouveauResultat = ancien * i;
                                        calculs += format("{} * {} = {}\n", ancien, i, nouveauResultat);
                                    }
                                }

                                resultat = nouveauResultat;
                                message = format("Operation : {}! = {}\n", n, nouveauResultat) + calculs;
                            }
                        }
                        catch (...)
                        {
                            cout << "Erreur : factorielle invalide, doit etre un entier positif !\n";
                            nombreValide = false;
                        }
                    } while (!nombreValide);
                    break;
                }
                case 's':
                {
                    double x = 0;
                    bool xValide = true;
                    do
                    {
                        xValide = true;
                        cout << "Entrer le x de la serie de Taylor : ";

                        string chaineX;
                        cin >> chaineX;

                        try
                        {
                            size_t nombreCaracteresConvertis;
                            x = stod(chaineX, &nombreCaracteresConvertis);

                            if (nombreCaracteresConvertis < chaineX.length())
                            {
                                throw exception();
                            }
                        }
                        catch (...)
                        {
                            cout << "Erreur : x invalide doit etre un nombre a virgule !\n";
                            xValide = false;
                        }
                    } while (!xValide);

                    int n = 0;
                    bool nValide = true;
                    do
                    {
                        nValide = true;
                        cout << "Entrer le n de la serie de Taylor : ";

                        string chaineN;
                        cin >> chaineN;

                        try
                        {
                            size_t nombreCaracteresConvertis;
                            double nombre = stod(chaineN, &nombreCaracteresConvertis);

                            if (nombreCaracteresConvertis < chaineN.length())
                            {
                                throw exception();
                            }

                            if (nombre < 0 || nombre != (int)nombre)
                            {
                                cout << "Erreur : n invalide, doit etre un nombre entier positif !\n";
                                nValide = false;
                            }
                            else
                            {
                                n = (int)nombre;
                            }
                        }
                        catch (...)
                        {
                            cout << "Erreur : n invalide, doit etre un nombre entier positif !\n";
                            nValide = false;
                        }
                    } while (!nValide);

                    string formule = "Serie de Taylor : 1";
                    string calculs = "Calculs : 1";
                    string valeurs = "Valeurs : 1";
                    double somme = 1;
                    double puissance = 1;
                    double factorielle = 1;

                    for (int k = 1; k <= n; k++)
                    {
                        puissance = puissance * x;
                        factorielle = factorielle * k;
                        double terme = puissance / factorielle;
                        somme = somme + terme;

                        formule += format(" + ({}^{} / {}!)", x, k, k);
                        calculs += format(" + {} / {}", puissance, factorielle);
                        valeurs += format(" + {}", terme);
                    }

                    resultat = somme;
                    message = formule + "\n" + calculs + "\n" + valeurs + "\n";
                    break;
                }
                case 'r':
                {
                    double hauteur = 0;
                    bool hauteurValide = true;
                    do
                    {
                        hauteurValide = true;
                        cout << "Entrer une hauteur : ";

                        string chaineHauteur;
                        cin >> chaineHauteur;

                        try
                        {
                            size_t nombreCaracteresConvertis;
                            hauteur = stod(chaineHauteur, &nombreCaracteresConvertis);

                            if (nombreCaracteresConvertis < chaineHauteur.length())
                            {
                                throw exception();
                            }

                            if (hauteur <= 0)
                            {
                                cout << "Erreur : hauteur doit etre plus grand que 0 !\n";
                                hauteurValide = false;
                            }
                        }
                        catch (...)
                        {
                            cout << "Erreur : hauteur doit etre un nombre a virgule !\n";
                            hauteurValide = false;
                        }
                    } while (!hauteurValide);

                    double largeur = 0;
                    bool largeurValide = true;
                    do
                    {
                        largeurValide = true;
                        cout << "Entrer une largeur : ";

                        string chaineLargeur;
                        cin >> chaineLargeur;

                        try
                        {
                            size_t nombreCaracteresConvertis;
                            largeur = stod(chaineLargeur, &nombreCaracteresConvertis);

                            if (nombreCaracteresConvertis < chaineLargeur.length())
                            {
                                throw exception();
                            }

                            if (largeur <= 0)
                            {
                                cout << "Erreur : largeur doit etre plus grand que 0 !\n";
                                largeurValide = false;
                            }
                        }
                        catch (...)
                        {
                            cout << "Erreur : largeur doit etre un nombre a virgule !\n";
                            largeurValide = false;
                        }
                    } while (!largeurValide);

                    int hauteurEntier = (int)hauteur;
                    if (hauteurEntier < hauteur)
                    {
                        hauteurEntier++;
                    }

                    int largeurEntier = (int)largeur;
                    if (largeurEntier < largeur)
                    {
                        largeurEntier++;
                    }

                    for (int ligne = 1; ligne <= hauteurEntier; ligne++)
                    {
                        for (int colonne = 1; colonne <= largeurEntier; colonne++)
                        {
                            if (colonne > 1)
                            {
                                cout << " ";
                            }
                            cout << "*";
                        }
                        cout << "\n";
                    }

                    double aire = hauteur * largeur;
                    double perimetre = 2 * (hauteur + largeur);
                    cout << format("Aire      : {:.3f}\n", aire);
                    cout << format("Perimetre : {:.3f}\n", perimetre);

                    cout << "Appuyer sur une touche pour continuer.\n";
                    cin.ignore();
                    cin.get();
                    break;
                }
                case 't':
                {
                    double hauteur = 0;
                    bool hauteurValide = true;
                    do
                    {
                        hauteurValide = true;
                        cout << "Entrer une hauteur : ";

                        string chaineHauteur;
                        cin >> chaineHauteur;

                        try
                        {
                            size_t nombreCaracteresConvertis;
                            hauteur = stod(chaineHauteur, &nombreCaracteresConvertis);

                            if (nombreCaracteresConvertis < chaineHauteur.length())
                            {
                                throw exception();
                            }

                            if (hauteur <= 0)
                            {
                                cout << "Erreur : hauteur doit etre plus grand que 0 !\n";
                                hauteurValide = false;
                            }
                        }
                        catch (...)
                        {
                            cout << "Erreur : hauteur doit etre un nombre a virgule !\n";
                            hauteurValide = false;
                        }
                    } while (!hauteurValide);

                    int hauteurEntier = (int)hauteur;
                    if (hauteurEntier < hauteur)
                    {
                        hauteurEntier++;
                    }

                    for (int ligne = 1; ligne <= hauteurEntier; ligne++)
                    {
                        for (int colonne = 1; colonne <= ligne; colonne++)
                        {
                            if (colonne > 1)
                            {
                                cout << " ";
                            }
                            cout << "*";
                        }
                        cout << "\n";
                    }

                    double aire = (hauteur * hauteur) / 2;
                    double hypotenuse = sqrt(hauteur * hauteur + hauteur * hauteur);
                    double perimetre = hauteur + hauteur + hypotenuse;
                    cout << format("Aire       : {:.3f}\n", aire);
                    cout << format("Hypotenuse : {:.3f}\n", hypotenuse);
                    cout << format("Perimetre  : {:.3f}\n", perimetre);

                    cout << "Appuyer sur une touche pour continuer.\n";
                    cin.ignore();
                    cin.get();
                    break;
                }
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
