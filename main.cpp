#include <iostream>
#include <string>
#include "cluedo.h"


using namespace std;


int main()
{
  std::vector<std::string> listeJoueurs;
  int nombreJoueurs = 0;
  cout << "Combien y a t-il de joueurs ?" << endl;
  cin >> nombreJoueurs;

  string myName = "";
  cout << "Mon nom : ";
  cin >> myName;
  listeJoueurs.push_back(myName);
  
  for(int i=2; i<=nombreJoueurs; i++)
    {
      string name = "";
      cout << "Nom du Joueur " << i << " : ";
      cin >> name;
      listeJoueurs.push_back(name);
    }
  
  Cluedo partie(listeJoueurs);
  
  char input('h');
  cout << "Bienvenue dans mon programme de Cluedo !!!" << endl;
  cout << "Tapez 'h' pour ouvrir l'aide !!!" << endl;

  do
    {
      cout << "@ ";
      input = 'h';
      cin >> input;
      
      if(input == 'h')
	{
	  cout << "Voici les différentes commandes : " << endl;
	  cout << "'q' pour quitter" << endl;
	  cout << "'a' pour afficher la partie" << endl;
	  cout << "'h' pour afficher l'aide" << endl;
	  cout << "'l' pour lister les cartes" << endl;
	  cout << "'r' pour réfléchir un peu" << endl;
	  cout << "'e' pour entrer un indice" << endl;
	  cout << "'n' pour creer une supposition" << endl;
	  cout << "'s' pour afficher les suppositions" << endl;
	  cout << "'d' pour entrer ses cartes de départ" << endl;
	}

      else if(input == 'a')
      	{partie.toutAfficher();}

      else if(input == 'q')
	{
	  cout << "Voulez-vous vraiement quitter ?  Les données non-enregistrées seront perdues !"<<endl;
	  cout << "Tapez 'q' pour quitter : ";
	  cin >> input;
	  if(input == 'q')
	    {cout << "Bye, Bye !!!" << endl;}
	}

      else if(input == 'l')
	{partie.liste();}

      else if(input == 'e')
	{
	  string Joueur;
	  string Indice;
	  cout << "Joueur : ";
	  cin >> Joueur;
	  cout << "Indice : ";
	  cin >> Indice;
	  partie.info(Joueur,Indice);
	  partie.reflechir();
	}

      else if(input == 'd')
	{
	  int n;
	  cout << "Combien de cartes avez vous ?  : " << endl;
	  cin >> n;
	  for(int i=0; i<n; i++)
	    {
	      string maCarte;
	      cout << i+1 << " : ";
	      cin >> maCarte;
	      partie.info(myName, maCarte);
	    }
	  partie.reflechir();
	}
	  
      else if(input == 'r')
	{partie.reflechir();}

      else if(input == 's')
	{partie.afficherSuppo();}

      else if(input == 'n')
	{
	  cout << "Hypothèse posée par : ";
	  string Joueur;
	  cin >> Joueur;

	  cout << "Lieu : ";
	  string Lieu;
	  cin >> Lieu;

	  cout << "Suspect : ";
	  string Suspect;
	  cin >> Suspect;
	  
	  cout << "Arme : ";
	  string Arme;
	  cin >> Arme;
	  
	  char Reponse = 'z';
	  do
	    {
	      string Personne;
	      cout << "Qui doit répondre ? ";
	      cin >> Personne;
	      
	      cout << "Cette personne a-t-elle répondu ? ";
	      cin >> Reponse;
	      
	      if(Reponse == 'o')
		{
		  if(Personne != myName)
		    {partie.suppo(Joueur, Lieu, Suspect, Arme, Personne);}
		}
	      else
		{partie.pas(Personne, Lieu, Suspect, Arme);
		  cout <<"Bingo ";}
	    }while(Reponse != 'o');
	}
      
      else
	{cout << "Tapez 'h' pour ouvrir l'aide !!!" << endl;}
      
    }while(input != 'q');
}
