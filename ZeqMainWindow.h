#ifndef _ZEQMAINWINDOW_H_
#define _ZEQMAINWINDOW_H_

#include <QMainWindow>

class QMenu;
class Zeq;

class ZeqMainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        ZeqMainWindow(QWidget *parent=0);

    private:
        Zeq *zeq;

        QMenu *menuFichier;
        QMenu *menuAide;

        QAction *actionNouveau;
        QAction *actionQuitter;
        QAction *actionAide;
        QAction *actionAPropos;
        QAction *actionAboutQt;

    private slots:
        void aide();
        void aPropos();
        void aboutQt();
};

#endif
