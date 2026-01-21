/* 
 * File:   AjoutEpargne.h
 * Author: etudiant
 *
 * Created on 20 avril 2025, 07 h 17
 */

#ifndef _AJOUTEPARGNE_H
#define _AJOUTEPARGNE_H

#include "ui_AjoutEpargne.h"

class AjoutEpargne : public QDialog
{
  Q_OBJECT
public:
  AjoutEpargne ();
  virtual ~AjoutEpargne ();
  
  int reqNoCompte() const;
  double reqSolde() const;
  double reqTauxInteret() const;
  std::string reqDescription() const;
  
  private slots :
    void slotConfirmerEpargne();
    
private:
  Ui::AjoutEpargne widget;
};

#endif /* _AJOUTEPARGNE_H */
