#ifndef DEF_CLUEDO
#define DEF_CLUEDO

#include <iostream>
#include <string>
#include <vector>

class Cluedo
{
 public:
  Cluedo(std::vector<std::string> liste);
  void toutAfficher();
  void liste();
  void info(std::string joueur, std::string indice);
  void reflechir();
  void suppo(std::string j, std::string l, std::string s, std::string a, std::string r);
  void afficherSuppo();
  void pas(std::string j, std::string l, std::string s, std::string a);
  
 private:
  std::vector<std::string> listeJoueurs;
  std::vector<std::string> listeLieux;
  std::vector<std::string> listeSuspects;
  std::vector<std::string> listeArmes;
  
  std::vector<std::vector<int> > possibLieu;
  std::vector<std::vector<int> > possibSuspect;
  std::vector<std::vector<int> > possibArme;

  std::vector<std::vector<int> > suppositions;

  int qLieu(std::string indice);
  int qSuspect(std::string indice);
  int qArme(std::string indice);
  int qJoueur(std::string indice);
 
  int tailleMax;

  void enlever();
  void reduire(std::vector<std::string> liste, std::vector<std::vector<int> > &possib);
  void afficher(std::vector<std::string> liste, std::vector<std::vector<int> > possib);

};

#endif
