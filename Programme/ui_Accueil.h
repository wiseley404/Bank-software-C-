/********************************************************************************
** Form generated from reading UI file 'Accueil.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCUEIL_H
#define UI_ACCUEIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Accueil
{
public:
    QAction *actionSupprimer_un_Compte;
    QAction *actionQuitter;
    QAction *actionEpargne;
    QAction *actionCheque;
    QWidget *centralwidget;
    QTextEdit *textEditReleveClient;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_un_Compte;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Accueil)
    {
        if (Accueil->objectName().isEmpty())
            Accueil->setObjectName(QString::fromUtf8("Accueil"));
        Accueil->resize(707, 600);
        actionSupprimer_un_Compte = new QAction(Accueil);
        actionSupprimer_un_Compte->setObjectName(QString::fromUtf8("actionSupprimer_un_Compte"));
        actionQuitter = new QAction(Accueil);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionEpargne = new QAction(Accueil);
        actionEpargne->setObjectName(QString::fromUtf8("actionEpargne"));
        actionCheque = new QAction(Accueil);
        actionCheque->setObjectName(QString::fromUtf8("actionCheque"));
        centralwidget = new QWidget(Accueil);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEditReleveClient = new QTextEdit(centralwidget);
        textEditReleveClient->setObjectName(QString::fromUtf8("textEditReleveClient"));
        textEditReleveClient->setGeometry(QRect(50, 40, 611, 491));
        Accueil->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Accueil);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 707, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_un_Compte = new QMenu(menuMenu);
        menuAjouter_un_Compte->setObjectName(QString::fromUtf8("menuAjouter_un_Compte"));
        Accueil->setMenuBar(menubar);
        statusbar = new QStatusBar(Accueil);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Accueil->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_un_Compte->menuAction());
        menuMenu->addAction(actionSupprimer_un_Compte);
        menuMenu->addAction(actionQuitter);
        menuAjouter_un_Compte->addAction(actionEpargne);
        menuAjouter_un_Compte->addAction(actionCheque);

        retranslateUi(Accueil);
        QObject::connect(actionEpargne, SIGNAL(triggered()), Accueil, SLOT(slotAjouterEpargne()));
        QObject::connect(actionQuitter, SIGNAL(triggered()), Accueil, SLOT(close()));
        QObject::connect(actionSupprimer_un_Compte, SIGNAL(triggered()), Accueil, SLOT(slotSupprimerCompte()));
        QObject::connect(actionCheque, SIGNAL(triggered()), Accueil, SLOT(slotAjouterCheque()));

        QMetaObject::connectSlotsByName(Accueil);
    } // setupUi

    void retranslateUi(QMainWindow *Accueil)
    {
        Accueil->setWindowTitle(QCoreApplication::translate("Accueil", "Accueil", nullptr));
        actionSupprimer_un_Compte->setText(QCoreApplication::translate("Accueil", "Supprimer un Compte", nullptr));
        actionQuitter->setText(QCoreApplication::translate("Accueil", "Quitter", nullptr));
        actionEpargne->setText(QCoreApplication::translate("Accueil", "Epargne", nullptr));
        actionCheque->setText(QCoreApplication::translate("Accueil", "Cheque", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("Accueil", "Menu", nullptr));
        menuAjouter_un_Compte->setTitle(QCoreApplication::translate("Accueil", "Ajouter un Compte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Accueil: public Ui_Accueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCUEIL_H
