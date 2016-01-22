#include "ZeqMainWindow.h"
#include "Zeq.h"
#include <QMenuBar>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

ZeqMainWindow::ZeqMainWindow(QWidget *parent) : QMainWindow(parent)
{
    //Organisation de la fenêtre:
    zeq = new Zeq(this);
    setCentralWidget(zeq);

    setWindowTitle(tr("ZEQ Enumérateur Quotidien v0.1"));

    menuFichier = menuBar()->addMenu(tr("Fichier"));
    menuAide = menuBar()->addMenu(tr("?"));

    actionNouveau = new QAction(tr("Nouveau"),this);
    actionNouveau->setShortcut(tr("Ctrl+N"));
    actionQuitter = new QAction(tr("Quitter"),this);
    actionQuitter->setShortcut(tr("Ctrl+Q"));
    actionAide = new QAction(tr("Aide"),this);
    actionAPropos = new QAction(tr("A propos de ZEQ..."),this);
    actionAboutQt = new QAction(tr("A propos de Qt..."),this);

    menuFichier->addAction(actionNouveau);
    menuFichier->addSeparator();
    menuFichier->addAction(actionQuitter);
    menuAide->addAction(actionAide);
    menuAide->addSeparator();
    menuAide->addAction(actionAPropos);
    menuAide->addAction(actionAboutQt);

    QObject::connect(actionNouveau,SIGNAL(triggered()),zeq,SLOT(nouveau()));
    QObject::connect(actionQuitter,SIGNAL(triggered()),this,SLOT(close()));
    QObject::connect(actionAide,SIGNAL(triggered()),this,SLOT(aide()));
    QObject::connect(actionAPropos,SIGNAL(triggered()),this,SLOT(aPropos()));
    QObject::connect(actionAboutQt,SIGNAL(triggered()),this,SLOT(aboutQt()));
}

void ZeqMainWindow::aide()
{
    QMessageBox *aideMessage = new QMessageBox(QMessageBox::Information,tr("Aide ZEQ"),tr("ZEQ est un mini-logiciel qui permet de calculer le nombre de jours écoulés depuis une certaine date.\nEntrez une date au format \"jour-mois-année\", ZEQ calculera le nombre de jours écoulés."),QMessageBox::Ok,this);
    aideMessage->exec();
}

void ZeqMainWindow::aPropos()
{
    QMessageBox::about(this,tr("A propos de ZEQ"),tr("Auteur: Steeve «Oltarus» Droz\nCréé le 06.12.08\nVersion 0.1\nDistribué sous license GPL"));
}

void ZeqMainWindow::aboutQt()
{
    QMessageBox::aboutQt(this);
}
