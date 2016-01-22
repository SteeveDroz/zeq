#include "Zeq.h"
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QDate>

Zeq::Zeq(QWidget *parent) : QWidget(parent)
{
    dateLabel = new QLabel(tr("Date (JJ.MM.AAAA)"),this);
    sortieLabel = new QLabel("Bienvenue\nVeuillez entrer une date valide",this);
    sortieLabel->setFont(QFont("Arial",18,QFont::Bold));

    jour = new QLineEdit(this);
    jour->setMaxLength(2);
    jour->setMaximumWidth(20);
    mois = new QLineEdit(this);
    mois->setMaxLength(2);
    mois->setMaximumWidth(20);
    annee = new QLineEdit(this);
    annee->setMaxLength(4);
    annee->setMaximumWidth(30);

    naissance = new QDate();
    maintenant = new QDate(QDate::currentDate());

    QGridLayout *grille = new QGridLayout(this);
    grille->addWidget(dateLabel,0,0);
    grille->addWidget(jour,0,1);
    grille->addWidget(mois,0,2);
    grille->addWidget(annee,0,3);
    grille->addWidget(sortieLabel,2,0,1,5);
    grille->setRowStretch(1,1);
    grille->setColumnStretch(4,1);

    QObject::connect(jour,SIGNAL(textChanged(const QString &)),this,SLOT(afficherNombreJours(const QString &)));
    QObject::connect(mois,SIGNAL(textChanged(const QString &)),this,SLOT(afficherNombreJours(const QString &)));
    QObject::connect(annee,SIGNAL(textChanged(const QString &)),this,SLOT(afficherNombreJours(const QString &)));
}

void Zeq::afficherNombreJours(const QString &string)
{
    naissance->setDate(annee->text().toInt(),mois->text().toInt(),jour->text().toInt());
    if (naissance->isValid()) calculerAge();
    else sortieLabel->setText(tr("Veuillez entrer une date valide"));
}

void Zeq::calculerAge()
{
    int nbJours =  naissance->daysTo(*maintenant);
    if (nbJours > 1) sortieLabel->setText(tr("C'était il y a %n jours","",nbJours));
    else if (nbJours < -1) sortieLabel->setText(tr("C'est dans %n jours","",-nbJours));
    else if (nbJours == 1) sortieLabel->setText(tr("C'était hier"));
    else if (nbJours == -1) sortieLabel->setText(tr("C'est demain"));
    else sortieLabel->setText(tr("C'est aujourd'hui..."));
}

void Zeq::nouveau()
{
    jour->setText("");
    mois->setText("");
    annee->setText("");
}
