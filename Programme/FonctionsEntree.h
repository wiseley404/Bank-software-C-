/* 
 * File:   FonctionsEntree.h
 * Author: etudiant
 *
 * Created on 10 avril 2025, 07 h 34
 */
#include <vector>

#ifndef FONCTIONSENTREE_H
#define FONCTIONSENTREE_H

int EntreeFolio() ;
std::string EntreeNom();
std::string EntreePrenom();
std::vector<int> EntreeDate();
std::string EntreeTel();

int EntreeNoCompteCheque();
std::string EntreeDescriptionCheque();
double EntreeTauxCheque();
double EntreeSoldeCheque();
int EntreeTransactionsCheque();
double EntreeTauxminCheque();

int EntreeNoCompteEpargne();
std::string EntreeDescriptionEpargne();
double EntreeTauxEpargne();
double EntreeSoldeEpargne();

#endif /* FONCTIONSENTREE_H */

