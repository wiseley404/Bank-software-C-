/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   Accueil.h
 * Author: etudiant
 *
 * Created on 20 avril 2025, 06 h 52
 */

#ifndef _ACCUEIL_H
#define _ACCUEIL_H

#include "ui_Accueil.h"
#include "Client.h"

class Accueil : public QMainWindow
{
  Q_OBJECT
public:
  Accueil ();
  virtual ~Accueil ();
  
  private slots:
    void slotAjouterEpargne();
    void slotAjouterCheque();
    void slotSupprimerCompte();
    
private:
  Ui::Accueil widget;
  bancaire::Client m_client;
};
 
#endif /* _ACCUEIL_H */
