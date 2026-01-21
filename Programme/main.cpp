/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 10 avril 2025, 20 h 57
 */

#include <QApplication>
#include <qt5/QtWidgets/qwidget.h>
#include "Accueil.h"

int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  
  Accueil FenetrePrincipale;
  FenetrePrincipale.show ();
  
  return app.exec ();
}
