#ifndef DIALOGEXPENDITURE_H
#define DIALOGEXPENDITURE_H

#include <QDialog>
#include<QDebug>
#include<QSettings>
#include<QVariant>
#include<QMessageBox>
#include<QList>
#include<QString>
namespace Ui {
class DialogExpenditure;
}

class DialogExpenditure : public QDialog
{
    Q_OBJECT
public:
    explicit DialogExpenditure(QWidget *parent = nullptr);
    ~DialogExpenditure();
private slots:
    void on_addPushBtn_clicked();


    void on_removePushBtn_clicked();

    void on_pushButton_clicked();

    void on_calculatePushBtn_clicked();

    void on_moneyLineEdit_inputRejected();

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::DialogExpenditure *ui;

    QList<QString> forCalculate;

    void load();
    void save();

};

#endif // DIALOGEXPENDITURE_H
