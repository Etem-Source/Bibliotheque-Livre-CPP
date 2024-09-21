/*
    Sujet : Mini-Projet Librairie
    Auteur : Etem 
    Langage : C++
*/

// Bibliothèque

#include <iostream> 
#include <fstream>
#include <string>

// STD

using namespace std;

// Variables - Séparer pour chaque partie

int choix, choixBookManager;
int ajouterLivre;

string ajouterNomLivre, ajouterAuteurLivre;

int choixInfoBook;
int choixMAJBook;
int choixSUPBook;

int choixClientManager;
int ajouterClient;

string ajouterClientNom, ajouterClientPrenom, ajouterClientAge;
int choixClientInfo;
int choixMajClient;

int choixCommandsClient;
int CommandsManagerClient;
int CommandsManagerClientLivre;

// Variables - Tableaux

string book[100]; // L'emplacement d'un livre // if book[0] == "", alors on peut écrire dedans
string bookInfo[100]; // Les informations d'un livre
string bookClient[100]; // Les informations d'un livre appartenant a un client
string client[100]; // Les informations d'un client

        // BOOK MANAGER //

int BookAvailabeManagerChoix1() // Ajouter un nouveau livre
{
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!< Bienvenue dans la gestion : Ajouter un nouveau livre >!>" << endl;
    cout << "Dans quel emplacement souhaitez-vous ajouter le livre ? : ";
    cin >> ajouterLivre;

    if(book[ajouterLivre] == "")
    {
        cout << "Quel est le nom de ce livre ? : ";
        cin >> ajouterNomLivre;
        cout << "Quel est l'auteur de ce livre ? : ";
        cin >> ajouterAuteurLivre;

        book[ajouterLivre] = to_string(ajouterLivre);
        bookInfo[ajouterLivre] = "[] Livre : Nom : " + ajouterNomLivre + ", Auteur : " + ajouterAuteurLivre;
        cout << "Operation reussi avec succes. " << endl;
        cout << "L'emplacement est : " << book[ajouterLivre] << endl;
        cout << "Les informations sont : " << bookInfo[ajouterLivre] << endl;
    }
    else
    {
        cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
        cout << "L'emplacement contient deja un livre. " << endl;
        cout << bookInfo[ajouterLivre] << endl;
        BookAvailabeManagerChoix1();
    }

}

int BookAvailabeManagerChoix2() // Rechercher un livre et afficher ses informations
{
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!< Bienvenue dans la gestion : Rechercher un livre et afficher ses informations >!>" << endl;
    cout << "Veuillez saisir l'emplacement du livre : ";
    cin >> choixInfoBook;
    if(bookInfo[choixInfoBook] == "")
    {
        cout << "Cet emplacement ne contient pas de livre." << endl;
    }
    else
    {
        cout << "Les informations du livre de l'emplacement : " << choixInfoBook << endl;
        cout << bookInfo[choixInfoBook] << endl;
    }
    return 0;
}

int BookAvailabeManagerChoix3() // Mettre a jour les informations concernant un livre
{
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!< Bienvenue dans la gestion : Mettre a jour les informations concernant un livre >!>" << endl;  
    cout << "Veuillez saisir l'emplacement du livre a mettre a jour : "; 
    cin >> choixMAJBook;
    if(bookInfo[choixMAJBook] == "")
    {
        cout << "Cet emplacement ne contient pas de livre." << endl;
    }
    else
    {
        cout << "Vous voulez mettre a jour le livre suivant : " << endl;
        cout << bookInfo[choixMAJBook] << endl;
        cout << "[MaJ] Quel est le nom de ce livre ? : ";
        cin >> ajouterNomLivre;
        cout << "[MaJ] Quel est l'auteur de ce livre ? : ";
        cin >> ajouterAuteurLivre;
        book[ajouterLivre] = ajouterLivre;
        bookInfo[ajouterLivre] = "Nom : " + ajouterNomLivre + ", Auteur : " + ajouterAuteurLivre;
        cout << "Le livre est maintenant defini comme : " << endl;
        cout << bookInfo[choixMAJBook] << endl;
    }
}

int BookAvailabeManagerChoix4() // Supprimer un livre de la liste.
{
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!< Bienvenue dans la gestion : Supprimer un livre de la liste >!>" << endl;   
    cout << "Veuillez saisir l'emplacement du livre a supprimer : "; 
    cin >> choixSUPBook;
    if(bookInfo[choixSUPBook] == "")
    {
        cout << "Cet emplacement est deja vide." << endl;
    }
    else
    {
        cout << "Les informations suivantes vont etre supprimees : " << endl;
        cout << bookInfo[choixSUPBook] << endl;
        bookInfo[choixSUPBook] = "";
        cout << "Operation reussi avec succes." << endl;
    }
}

int BookAvailabeManager()
{
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!< Bienvenue dans la gestion de la liste des livres disponibles. >!>" << endl;
    cout << "Que souhaitez-vous faire ? " << endl;
    cout << "1. Ajouter un nouveau livre." << endl;
    cout << "2. Rechercher un livre et afficher ses informations." << endl;
    cout << "3. Mettre a jour les informations concernant un livre."  << endl;
    cout << "4. Supprimer un livre de la liste." << endl;
    cin >> choixBookManager;
    switch (choixBookManager)
    {
    case 1:
        BookAvailabeManagerChoix1(); // Ajouter un nouveau livre
        break;
    case 2:
        BookAvailabeManagerChoix2(); // Rechercher un livre et afficher ses informations
        break;
    case 3:
        BookAvailabeManagerChoix3(); // Mettre a jour les informations concernant un livre
        break;
    case 4:
        BookAvailabeManagerChoix4(); // Supprimer un livre de la liste.
        break;
    default:
        cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
        cout << "Vous n'avez pas choisis un nombre entre 1 et 4..." << endl;
        BookAvailabeManager();
        break;
    }
}

        // BOOK MANAGER //

        // CLIENT MANAGER // 

int ClientManagerChoix1() // Ajouter un nouveau client
{
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!< Bienvenue dans la gestion : Ajouter un nouveau client >!>" << endl;
    cout << "Dans quel emplacement souhaitez-vous ajouter le client ? : ";
    cin >> ajouterClient;

    if(client[ajouterClient] == "")
    {
        cout << "Quel est le nom de ce client ? : ";
        cin >> ajouterClientNom;
        cout << "Quel est le prenom de ce client ? : ";
        cin >> ajouterClientPrenom;
        cout << "Quel est son age ? : ";
        cin >> ajouterClientAge;
        client[ajouterClient] = "Nom : " + ajouterClientNom + ", Prenom : " + ajouterClientPrenom + ", Age : " + ajouterClientAge;
        cout << "Operation reussi avec succes. " << endl;
        cout << "Les informations sont : " << client[ajouterClient] << endl;
    }
    else
    {
        cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
        cout << "L'emplacement contient deja un client. " << endl;
        cout << client[ajouterClient] << endl;
        ClientManagerChoix1();
    }
}

int ClientManagerChoix2() // Rechercher un client et afficher ses informations
{
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!< Bienvenue dans la gestion : Rechercher un client et afficher ses informations >!>" << endl;
    cout << "Veuillez saisir l'emplacement du client : ";
    cin >> choixClientInfo;
    if(client[choixClientInfo] == "")
    {
        cout << "Cet emplacement ne contient pas de client." << endl;
    }
    else
    {
        cout << "Les informations du client de l'emplacement : " << choixClientInfo << endl;
        cout << client[choixClientInfo] << endl;
    }
}

int ClientManagerChoix3() // Mettre a jour les informations concernant un client
{
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!< Bienvenue dans la gestion : Mettre a jour les informations concernant un client >!>" << endl;  
    cout << "Veuillez saisir l'emplacement du client a mettre a jour : "; 
    cin >> choixMajClient;
    if(client[choixMajClient] == "")
    {
        cout << "Cet emplacement ne contient pas de client." << endl;
    }
    else
    {
        cout << "Vous voulez mettre a jour le client suivant : " << endl;
        cout << client[choixMajClient] << endl;
        cout << "[MaJ] Quel est le nom de ce client ? : ";
        cin >> ajouterClientNom;
        cout << "[MaJ] Quel est le prenom de ce client ? : ";
        cin >> ajouterClientPrenom;
        cout << "[MaJ] Quel est l'age de ce client ? : ";
        cin >> ajouterClientAge;
        client[ajouterClient] = "Nom : " + ajouterClientNom + ", Prenom : " + ajouterClientPrenom + ", Age : " + ajouterClientAge;
        cout << "Operation reussi avec succes. " << endl;
        cout << "Le client est maintenant defini comme : " << endl;
        cout << client[choixMajClient] << endl;
    }
}

int ClientManager()
{
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!< Bienvenue dans la gestion de la liste des clients. >!>" << endl;
    cout << "Que souhaitez-vous faire ? " << endl;
    cout << "1. Ajouter un nouveau client." << endl;
    cout << "2. Rechercher un client et afficher ses informations." << endl;
    cout << "3. Mettre a jour les informations concernant un client."  << endl;
    cin >> choixClientManager;
    switch (choixClientManager)
    {
    case 1:
        ClientManagerChoix1(); // Ajouter un nouveau client
        break;
    case 2:
        ClientManagerChoix2(); // Rechercher un client et afficher ses informations
        break;
    case 3:
        ClientManagerChoix3(); // Mettre a jour les informations concernant un client
        break;
    default:
        cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
        cout << "Vous n'avez pas choisis un nombre entre 1 et 3..." << endl;
        ClientManager();
        break;
    }
}

        // CLIENT MANAGER // 
        
        // COMMANDS MANAGER //

int CommandsManagerChoix1() // Ajouter un livre d'un client
{
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!< Bienvenue dans la gestion : Ajouter un livre d'un client >!>" << endl;
    cout << "Quel est l'emplacement du client ? : ";
    cin >> CommandsManagerClient;
    if(client[CommandsManagerClient] == "")
    {
        cout << "Cet emplacement ne contient aucun client." << endl;
    }
    else
    {
        cout << "Ajouter un livre pour le client suivant : " << endl;
        cout << client[CommandsManagerClient] << endl;
        cout << "Quel est l'emplacement du livre a ajouter ? : ";
        cin >> CommandsManagerClientLivre;
        if(bookInfo[CommandsManagerClientLivre] == "")
        {
            cout << "Cet emplacement ne contient aucun livre." << endl;
        }
        else
        {
            cout << "Le livre que vous voulez ajouter est celui-ci : " << endl;
            cout << bookInfo[CommandsManagerClientLivre] << endl;
            bookClient[CommandsManagerClient] =  bookInfo[CommandsManagerClientLivre] + ", [] Client : " + client[CommandsManagerClient];
            cout << "Operation reussi avec succes." << endl;
            cout << bookClient[CommandsManagerClient] << endl;
        }
    } 
}

int CommandsManagerChoix2() // Mettre a jour les informations d'un livre d'un client
{
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!< Bienvenue dans la gestion : Mettre a jour les informations d'un livre d'un client >!>" << endl;
    cout << "Quel est l'emplacement du client ? : ";
    cin >> CommandsManagerClient;
    if(client[CommandsManagerClient] == "")
    {
        cout << "Cet emplacement ne contient aucun client." << endl;
    }
    else
    {
        cout << "Modifier un livre pour le client suivant : " << endl;
        cout << client[CommandsManagerClient] << endl;
        cout << "Quel est l'emplacement du livre a ajouter ? (Ceci ecrasera le livre que contient le client) : ";
        cin >> CommandsManagerClientLivre;
        if(bookInfo[CommandsManagerClientLivre] == "")
        {
            cout << "Cet emplacement ne contient aucun livre." << endl;
        }
        else
        {
            cout << "Le livre que vous voulez ajouter est celui-ci : " << endl;
            cout << bookInfo[CommandsManagerClientLivre] << endl;
            bookClient[CommandsManagerClient] =  bookInfo[CommandsManagerClient] + ", client : " + client[CommandsManagerClient];
            cout << "Operation reussi avec succes." << endl;
        }
    }
}

int CommandsManagerChoix3() // Supprimer un livre d'un client
{
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!< Bienvenue dans la gestion : Supprimer un livre d'un client >!>" << endl;
    cout << "Quel est l'emplacement du client ? : ";
    cin >> CommandsManagerClient;
    if(client[CommandsManagerClient] == "")
    {
        cout << "Cet emplacement ne contient aucun client." << endl;
    }
    else
    {
        cout << "Modifier un livre pour le client suivant : " << endl;
        cout << client[CommandsManagerClient] << endl;
        cout << "Quel est l'emplacement du livre a supprimer du client ? : ";
        cin >> CommandsManagerClientLivre;
        if(bookInfo[CommandsManagerClientLivre] == "")
        {
            cout << "Cet emplacement ne contient aucun livre." << endl;
        }
        else
        {
            cout << "Le livre que vous voulez supprimer est celui-ci : " << endl;
            cout << bookInfo[CommandsManagerClientLivre] << endl;
            bookClient[CommandsManagerClient] =  bookInfo[CommandsManagerClient];
            cout << "Operation reussi avec succes." << endl;
        }
    }
}

int CommandsManager()
{
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!< Bienvenue dans la gestion de la liste des commandes. >!>" << endl;
    cout << "Que souhaitez-vous faire ? " << endl;
    cout << "1. Ajouter un livre d'un client." << endl;
    cout << "2. Mettre a jour les informations d'un livre d'un client." << endl;
    cout << "3. Supprimer un livre d'un client."  << endl;
    cin >> choixCommandsClient;
    switch (choixCommandsClient)
    {
    case 1:
        CommandsManagerChoix1(); // Ajouter un livre d'un client
        break;
    case 2:
        CommandsManagerChoix2(); // Mettre a jour les informations d'un livre d'un client
        break;
    case 3:
        CommandsManagerChoix3(); // Supprimer un livre d'un client
        break;
    default:
        cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
        cout << "Vous n'avez pas choisis un nombre entre 1 et 3..." << endl;
        CommandsManager();
        break;
    }
    
}

        // COMMANDS MANAGER //

int main()
{
    while(1)
    {
    cout << "= = = = = = = = = = = = = = = = = = = = =" << endl;
    cout << "<!<  Bienvenue dans la gestion principale de la librairie. >!>" << endl;
    cout << "Que souhaitez-vous faire ? " << endl;
    cout << "1. Gerer la liste des livres disponibles." << endl;
    cout << "2. Gerer la liste des clients." << endl;
    cout << "3. Gerer la liste des commandes."  << endl;
    cout << "4. Quitter le programme." << endl;
    cin >> choix;
    switch (choix)
    {
    case 1:
        BookAvailabeManager(); // Gérer la liste des livres disponibles.
        break;
    case 2:
        ClientManager(); // Gérer la liste des clients
        break;
    case 3:
        CommandsManager(); // Gérer la liste des commandes
        break;
    case 4:
        cout << "Vous avez choisi de quitter le programme ! " << endl;
        return 0;
        break;
    default:
        cout << "Vous n'avez pas choisis un nombre entre 1 et 3..." << endl;
        main();
        break;
    }
    }
    return 0;
}
