/*******************************************
**                                        **
** Auteur: Steeve �Oltarus� Droz          **
** Nom: ZEQ (ZEQ  Enum�rateur Quotidient) **
** Date de cr�ation: 06.12.08             **
** Version: 0.1                           **
** Licence: GPL                           **
**                                        **
*******************************************/

/*****************************************
** Bienvenue dans le code-source de ZEQ **
*****************************************/

/* Ce fichier ne fait rien, merci de vous r�f�rer � "Zeq.h" et "Zeq.cpp" pour le contenu effectif du programme. */
#include <QApplication>
#include "ZeqMainWindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    ZeqMainWindow *fenetre = new ZeqMainWindow();
    fenetre->show();
    return app.exec();
}
