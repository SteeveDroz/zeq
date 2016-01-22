#ifndef _ZEQ_H_
#define _ZEQ_H_

#include <QWidget>

class QLabel;
class QLineEdit;
class QDate;

class Zeq : public QWidget
{
    Q_OBJECT

    public:
        Zeq::Zeq(QWidget *parent=0);

    private:
        QLabel *dateLabel;
        QLabel *sortieLabel;

        QLineEdit *jour;
        QLineEdit *mois;
        QLineEdit *annee;

        QDate *naissance;
        QDate *maintenant;

        void calculerAge();

    private slots:
        void afficherNombreJours(const QString &string);
        void nouveau();
};

#endif
