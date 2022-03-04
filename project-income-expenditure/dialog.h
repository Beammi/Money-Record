#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "dialogincome.h"
#include "dialogexpenditure.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_incomePushbtn_clicked();

    void on_expenditurePushbtn_clicked();

private:
    Ui::Dialog *ui;
    DialogIncome *dialog2 = new DialogIncome(this);
    DialogExpenditure *dialog = new DialogExpenditure(this);
};
#endif // DIALOG_H
