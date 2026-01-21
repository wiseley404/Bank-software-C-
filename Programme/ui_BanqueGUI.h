/********************************************************************************
** Form generated from reading UI file 'BanqueGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANQUEGUI_H
#define UI_BANQUEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BanqueGUI
{
public:
    QAction *actionAjouter_un_Compte_Cheque;
    QAction *actionEpargne;
    QAction *actionCheque;
    QAction *actionQuitter;
    QAction *actionSu_rimer_un_Comopte;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_un_Compte;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BanqueGUI)
    {
        if (BanqueGUI->objectName().isEmpty())
            BanqueGUI->setObjectName(QString::fromUtf8("BanqueGUI"));
        BanqueGUI->resize(800, 600);
        actionAjouter_un_Compte_Cheque = new QAction(BanqueGUI);
        actionAjouter_un_Compte_Cheque->setObjectName(QString::fromUtf8("actionAjouter_un_Compte_Cheque"));
        actionEpargne = new QAction(BanqueGUI);
        actionEpargne->setObjectName(QString::fromUtf8("actionEpargne"));
        actionCheque = new QAction(BanqueGUI);
        actionCheque->setObjectName(QString::fromUtf8("actionCheque"));
        actionQuitter = new QAction(BanqueGUI);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionSu_rimer_un_Comopte = new QAction(BanqueGUI);
        actionSu_rimer_un_Comopte->setObjectName(QString::fromUtf8("actionSu_rimer_un_Comopte"));
        centralwidget = new QWidget(BanqueGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BanqueGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BanqueGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_un_Compte = new QMenu(menuMenu);
        menuAjouter_un_Compte->setObjectName(QString::fromUtf8("menuAjouter_un_Compte"));
        BanqueGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(BanqueGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BanqueGUI->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_un_Compte->menuAction());
        menuMenu->addAction(actionSu_rimer_un_Comopte);
        menuMenu->addAction(actionQuitter);
        menuAjouter_un_Compte->addAction(actionEpargne);
        menuAjouter_un_Compte->addAction(actionCheque);

        retranslateUi(BanqueGUI);
        QObject::connect(actionQuitter, SIGNAL(triggered()), BanqueGUI, SLOT(close()));
        QObject::connect(actionEpargne, SIGNAL(triggered()), BanqueGUI, SLOT(AjoutEpargne()));
        QObject::connect(actionCheque, SIGNAL(triggered()), BanqueGUI, SLOT(AjoutCheque()));
        QObject::connect(actionSu_rimer_un_Comopte, SIGNAL(triggered()), BanqueGUI, SLOT(SupprimerCompte()));

        QMetaObject::connectSlotsByName(BanqueGUI);
    } // setupUi

    void retranslateUi(QMainWindow *BanqueGUI)
    {
        BanqueGUI->setWindowTitle(QCoreApplication::translate("BanqueGUI", "BanqueGUI", nullptr));
        actionAjouter_un_Compte_Cheque->setText(QCoreApplication::translate("BanqueGUI", "Ajouter un Compte Cheque", nullptr));
        actionEpargne->setText(QCoreApplication::translate("BanqueGUI", "Epargne", nullptr));
        actionCheque->setText(QCoreApplication::translate("BanqueGUI", "Cheque", nullptr));
        actionQuitter->setText(QCoreApplication::translate("BanqueGUI", "Quitter", nullptr));
        actionSu_rimer_un_Comopte->setText(QCoreApplication::translate("BanqueGUI", "Supprimer un Compte", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("BanqueGUI", "Menu", nullptr));
        menuAjouter_un_Compte->setTitle(QCoreApplication::translate("BanqueGUI", "Ajouter un Compte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BanqueGUI: public Ui_BanqueGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANQUEGUI_H
