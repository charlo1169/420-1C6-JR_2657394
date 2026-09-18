// TODO: Ajouter un en-tête
/*
	Auteur : Charles-Olivier Sabourin
	Date : 2026-09-18
	Description : Instructions de boucles (while et do/while)
*/

// Inclusion des librairies
#include <format>
#include <iostream>
#include <string>

// Utilisation du namespace Standard (std::) pour les librairies
using namespace std;

int main()
{
	// Configuration de la console en Unicode pour les accents
	setlocale(LC_ALL, "fr_CA.UTF-8");

	// Affichage de l'en-tête
	cout << "--- Cours 13 - While ---\n\n";

	// *** While ***
	// - Instruction de boucle qui permet de faire plusieurs fois un même travail
	// - Permet de 'remonter' dans le code afin de rexécuter une partie de code
	// 
	// while ( condition )
	// {
	//		// Travail à exécuter
	//		// Attention : Travail doit changer la condition du while(), sinon boucle infinie
	// }

	// TODO: Dessin avec if() et while() avec conditions true/false

	// TODO: Programmer une boucle infinie qui affiche Hello world!
	if (false)
	{
		cout << "--- Hello world sans fin ---\n\n";

		// cout << "Hello world!";
		// cout << "Hello world!";
		// cout << "Hello world!";
		// ...




		cout << "Fin de la boucle infinie Hello world !\n\n";
	}

	// Boucle pour la lecture au clavier
	// - Déclarer une variable avant la boucle while() afin de pouvoir l'utiliser dans la condition

	// TODO: Programmer une boucle qui arrête lorsque l'utilisateur entre "stop" à la Console
	if (false)
	{
		cout << "--- Hello world avec fin ---\n\n";

		// cout << "Entrer \"stop\" afin de quitter : ";

		cout << "Fin de la boucle avec fin Hello world !\n\n";
	}

	// *** Scope ***
	// - Scope de la boucle while est détruit à la fin de chaque boucle
	//		- Début du Scope : Espace mémoire est réservé à chaque définition de variable (int, double, etc.)
	//		- Fin du Scope : Variables du Scope while sont détruites en mémoire
	// 
	// - Pour conserver une valeur à travers plusieurs itérations de la boucle while()
	//		- Déclarer la variable à l'extérieur du while() avant le while()
	//		- Ne pas redéfinir de nouvelle valeur avant le while
	if (false)
	{
		cout << "--- Addition ---\n\n";

		double addition = 0;
		cout << format("Valeur addition avant le while() : {}\n\n", addition);

		while (addition < 100)
		{
			cout << format("Valeur addition au debut du while() : {}\n", addition);
			addition += 20;
			cout << format("Valeur addition a la fin du while() : {}\n\n", addition);
		}

		cout << format("Valeur addition apres le while() : {}\n\n", addition);
	}

	// *** Erreur ***
	// - Attention, C++ est un peu traitre, il vous laisse vous tirer dans le pied
	// - Possible de déclarer une variable avec le même nom en C++ qui cache l'autre variable
	if (false)
	{
		cout << "--- Addition avec boucle infinie ---\n\n";

		double addition = 0;
		cout << format("Valeur addition avant le while() : {}\n\n", addition);

		while (addition < 100)
		{
			// Erreur, définition d'une 2ème variable qui est supprimée à la fin de chaque boucle
			double addition = 0;

			cout << format("Valeur addition au debut du while() : {}\n", addition);
			addition += 20;
			cout << format("Valeur addition a la fin du while() : {}\n\n", addition);
		}

		cout << format("Valeur addition apres le while() : {}\n\n", addition);
	}


	// TODO: Exemple de boucle avec condition complexe sur 2 éléments distinct
	if (false)
	{
		cout << "--- 10 nombres ---\n";

		// Initialiser les variables afin d'entrer dans la boucle
		int compteurNombresValides = 0;

		// Lire un nombre à la Console
		int nombre;
		cout << format("Entrer le nombre {} : ", compteurNombresValides + 1);
		cin >> nombre;

		// TODO: Vérifier si le nombre doit être comptabilisé ou écrire une erreur à l'écran
		cout << format("Erreur : Nombre {} est trop grand, maximum 1000.\n", nombre);

		// TODO: Incrémenter le compte de nombres valides

		// TODO: Lire et comptabiliser jusqu'à 10 nombres à la Console tant que l'utilisateur n'entre pas un nombre négatif	

		cout << "Fin du programme qui lit 10 nombres !\n";
	}

	// *** do {} while(); ***
	// - Différence entre les 2 types de boucles
	//		- while() {} : exécuté 0 fois ou plus
	//		- do {} while(); : exécuté 1 fois ou plus
	// - while()
	//		- Généralement plus utilisé (disponible dans tous les langages)
	//		- Simplement initialiser la condition afin de rentrer au moins 1 fois dans la boucle
	//
	// do
	// {
	//		// Travail à effectuer au moins une fois
	//		// Attention : Travail doit changer la condition du while(), sinon boucle infinie
	// } while ( condition ) ;

	// *** Erreur ***
	// - Point-virgule manquant à la fin du while(); pour indiquer qu'il n'y aura pas d'accolades {}
	//do
	//{
	//	cout << "Erreur de point-virgule manquant\n";
	//} while (true) // Erreur

	// TODO: Programmer Hello world avec une boucle do ... while (false)
	if (false)
	{
		cout << "--- Hello world au moins une fois ---\n";

		do
		{
			cout << "Hello world!\n";
		} while (false);

		cout << "Fin du Hello world au moins une fois !\n";
	}

	// TODO: Ajouter une condition de fin au Hello World lorsque l'utilisateur entre la valeur 10
	if (true)
	{
		cout << "--- Hello world avec do ... while() ---\n";

		int nombre;

		do
		{
			cout << "Hello world \n";

			cout << "Entrer 10 pour arreter : ";

		}


		// cout << "Hello world!";



	// *** Valider les entrées au clavier ***
	// 
	// cin.fail()
	// - Retourne 'true' ou 'false' qui indique si la dernière lecture cin >> ... a échouée ou réussie
	// - Lors de la lecture d'un entier avec cin >> ...
	//		- Utilisateur entre '12345'
	//				- cin.fail() => retourne 'false'
	//		- Utilisateur entre 'abcde' 
	//				- cin.fail() => retourne 'true'
	//				- variable après le cin vaut 0
	// 
	// cin.clear()
	// cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	// - Vider le contenu entier du contenu des lectures de cin (buffer) qui n'a pas encore été utilisé
	// - Lors de la lecture d'un entier avec cin >> ...
	//		- Utilisateur entre 'abc def ghi'
	//		- cin >> ...
	//				- Essaie de transformer la partie jusqu'à l'espace en entier 'abc'
	//				- cin.fail() est 'true' car 'abc' ne peut pas être transformé en entier
	//				- Reste 'def ghi' à traiter dans le prochain cin >> ... sans que l'utilisateur appuie sur une touche
	//		- cin.clear()
	//				- Enlève l'erreur de cin.fail() pour qu'il retourne false (pas d'erreur de lecture)
	// 		- cin.ignore(..., '\n')
	//				- Supprime 'def ghi' restant dans le buffer
	//				- Prochain cin >> ... attend que l'utilisateur entre des nouveaux caractères et 'Entrée' (\n)

	// TODO: Lire un nombre entier et arrêter lorsque le nombre entré est un entier valide
		if (false)
		{
			cout << "--- Lire un nombre ---\n\n";

			cout << "Entrer un nombre entier : ";
			int nombre;
			cin >> nombre;

			while (cin.fail())
			{ 
				cin.clear();
				cin.ignore(std::numeri)
			}


		// cout << format("Le nombre valide est : {}\n", ...);

			cout << format("Le nombre valide est : {}")

		cout << "Fin de lecture du nombre !\n";
	}
}
