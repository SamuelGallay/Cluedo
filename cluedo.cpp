#include "cluedo.h"

using namespace std;

Cluedo::Cluedo(std::vector<std::string> liste)
{
  listeJoueurs = liste;
  listeLieux.push_back("Hall");
  listeLieux.push_back("Manger");
  listeLieux.push_back("Cuisine");
  listeLieux.push_back("Patio");
  listeLieux.push_back("Observatoire");
  listeLieux.push_back("Projection");
  listeLieux.push_back("Salon");
  listeLieux.push_back("Spa");
  listeLieux.push_back("Amis");

  listeSuspects.push_back("Moutarde");
  listeSuspects.push_back("Violet");
  listeSuspects.push_back("Olive");
  listeSuspects.push_back("Pervenche");
  listeSuspects.push_back("Rose");
  listeSuspects.push_back("Leblanc");

  listeArmes.push_back("Poignard");
  listeArmes.push_back("Chandelier");
  listeArmes.push_back("Revolver");
  listeArmes.push_back("Poison");
  listeArmes.push_back("Trophee");
  listeArmes.push_back("Corde");
  listeArmes.push_back("Batte");
  listeArmes.push_back("Hache");
  listeArmes.push_back("Halteres");

  tailleMax = 0;

  for(int i=0; i<listeJoueurs.size(); i++)
    {if(listeJoueurs[i].size() > tailleMax)
	{tailleMax = listeJoueurs[i].size();}}
 
  for(int i=0; i<listeSuspects.size(); i++)
    {possibSuspect.push_back(vector<int>(listeSuspects.size(),-1));}

  for(int i=0; i<listeLieux.size(); i++)
    {possibLieu.push_back(vector<int>(listeLieux.size(),-1));}

  for(int i=0; i<listeArmes.size(); i++)
    {possibArme.push_back(vector<int>(listeArmes.size(),-1));}
}

void Cluedo::liste()
{
  for(int i=0; i<listeJoueurs.size(); i++)
    {cout << i << " : " << listeJoueurs[i] << endl;}
  cout << endl;
  for(int i=0; i<listeLieux.size(); i++)
    {cout << i << " : " << listeLieux[i] << endl;}
  cout << endl;
  for(int i=0;i<listeSuspects.size(); i++)
    {cout << i << " : " << listeSuspects[i] << endl;}
  cout << endl;
  for(int i=0; i<listeArmes.size(); i++)
    {cout << i << " : " << listeArmes[i] << endl;}
  cout << endl;
}


void Cluedo::afficher(std::vector<std::string> liste, std::vector<std::vector<int> > possib)
{
  cout << endl << "---------| ";
  
  for(int i=0; i<liste.size(); i++)
    {cout << liste[i] <<" | ";}
  cout << endl;

  for(int i = 0; i < listeJoueurs.size(); i++)
    {
      cout << listeJoueurs[i];

      for(int j = listeJoueurs[i].size(); j<tailleMax+0; j++)
	{cout << " ";}

      cout << " | ";

      for(int j = 0; j < liste.size(); j++)
	{
	  char statIndice('z');
	  
	  if(possib[j][i]==0)
	    {statIndice = '-';}
	  else if(possib[j][i]==1)
	    {statIndice = 'O';}
	  else
	    {statIndice = ' ';}

	  cout << statIndice;
	  for(int k = 0; k<liste[j].size(); k++)
                {cout << " ";}
              cout << "| ";
	}
      cout << endl;
    }
  cout << endl;
}

void Cluedo::toutAfficher()
{
  afficher(listeLieux, possibLieu);
  afficher(listeSuspects, possibSuspect);
  afficher(listeArmes, possibArme);
}


void Cluedo::info(string joueur, string indice)
{
  int posJoueur;
  for(int j = 0; j<listeJoueurs.size(); j++)
    {if(listeJoueurs[j] == joueur)
	{posJoueur = j;}}
  for(int i = 0; i<listeLieux.size(); i++)
    {if(listeLieux[i] == indice)
	{possibLieu[i][posJoueur] = 1;}}
  for(int i = 0; i<listeSuspects.size(); i++)
    {if(listeSuspects[i] == indice)
        {possibSuspect[i][posJoueur] = 1;}}
  for(int i = 0; i<listeArmes.size(); i++)
    {if(listeArmes[i] == indice)
        {possibArme[i][posJoueur] = 1;}}
}



int Cluedo::qLieu(std::string indice)
{
  for(int i = 0; i<listeLieux.size(); i++)
    {if(listeLieux[i] == indice){return i;}}
  return -1;
}

int Cluedo::qSuspect(std::string indice)
{
  for(int i = 0; i<listeSuspects.size(); i++)
    {if(listeSuspects[i] == indice){return i;}}
  return -1;
}

int Cluedo::qArme(std::string indice)
{
  for(int i = 0; i<listeArmes.size(); i++)
    {if(listeArmes[i] == indice){return i;}}
  return -1;
}

int Cluedo::qJoueur(std::string indice)
{
  for(int i = 0; i<listeJoueurs.size(); i++)
    {if(listeJoueurs[i] == indice){return i;}}
  return -1;
}


void Cluedo::reduire(std::vector<std::string> liste, std::vector<std::vector<int> > &possib)
{
  for(int i=0; i<liste.size(); i++)
    {
      for(int j = 0; j<listeJoueurs.size(); j++)
	{
	  if(possib[i][j] == 1)
	    {
	      for(int k=0; k<listeJoueurs.size(); k++)
		{
		  if(k != j)
		    {
		      possib[i][k] = 0;
		    }
		}
	    }
	}
    }
}



void Cluedo::enlever()
{
  
  for(int j=0; j<listeJoueurs.size(); j++)
    {
      int n = 0;
      for(int i=0; i<listeLieux.size(); i++)
	{if(possibLieu[i][j] == 1){n = n + 1;}}
      for(int i=0; i<listeSuspects.size(); i++)
        {if(possibSuspect[i][j] == 1){n = n + 1;}}
      for(int i=0; i<listeArmes.size(); i++)
        {if(possibArme[i][j] == 1){n = n + 1;}}

      if(n == 7)
	{
	  for(int i=0; i<listeLieux.size(); i++)
	    {if(possibLieu[i][j] == -1){possibLieu[i][j] = 0;}}
	  for(int i=0; i<listeSuspects.size(); i++)
	    {if(possibSuspect[i][j] == -1){possibSuspect[i][j] = 0;}}
	  for(int i=0; i<listeArmes.size(); i++)
	    {if(possibArme[i][j] == -1){possibArme[i][j] = 0;}}
	}
    }
}

void Cluedo::reflechir()
{
  reduire(listeLieux, possibLieu);
  reduire(listeSuspects, possibSuspect);
  reduire(listeArmes, possibArme);
  enlever();
}


void Cluedo::suppo(std::string j, std::string l, std::string s, std::string a, std::string r)
{
  int posJoueur = qJoueur(j);
  int posLieu = qLieu(l);
  int posSuspect = qSuspect(s);
  int posArme = qArme(a);
  int posRep = qJoueur(r);
  
  if(posJoueur>-1 && posLieu>-1 && posSuspect>-1 && posArme>-1 && posRep>-1)
    {
      suppositions.push_back(vector<int>(5,-1));
      suppositions[suppositions.size()-1][0] = posJoueur;
      suppositions[suppositions.size()-1][1] = posLieu;
      suppositions[suppositions.size()-1][2] = posSuspect;
      suppositions[suppositions.size()-1][3] = posArme;
      suppositions[suppositions.size()-1][4] = posRep;
    }
  else
    {cout << "COIN COIN COIN COIN COIN " << endl;}
}

void Cluedo::afficherSuppo()
{
  for(int i=0; i<suppositions.size(); i++)
    {
      cout << listeJoueurs[suppositions[i][0]] << " : ";
      cout << listeLieux[suppositions[i][1]] << " : ";
      cout << listeSuspects[suppositions[i][2]] << " : ";
      cout << listeArmes[suppositions[i][3]] << " : ";
      cout << listeJoueurs[suppositions[i][4]] << endl;
    }
}


void Cluedo::pas(std::string j, std::string l, std::string s, std::string a)
{
  int posJoueur = qJoueur(j);
  int posLieu = qLieu(l);
  int posSuspect = qSuspect(s);
  int posArme = qArme(a);

  if(posJoueur>-1 && posLieu>-1 && posSuspect>-1 && posArme>-1)
    {
      possibLieu[posLieu][posJoueur] = 0;
      possibSuspect[posSuspect][posJoueur] = 0;
      possibArme[posArme][posJoueur] = 0;
    }
  else
    {cout << "COIN COIN COIN COIN COIN " << endl;}
}
