#ifndef DIALOGINCOME_H
#define DIALOGINCOME_H

#include <QDialog>
#include<QDebug>
#include<QSettings>
#include<QVariant>
#include<QMessageBox>
#include<QList>
#include<QString>
#include <QRegularExpression>
namespace Ui {
class DialogIncome;
}

class DialogIncome : public QDialog
{
    Q_OBJECT

public:
    explicit DialogIncome(QWidget *parent = nullptr);
    ~DialogIncome();

private slots:
    void on_addPushBtn_clicked();

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_removePushBtn_clicked();

    void on_pushButton_clicked();

    void on_calculatePushBtn_clicked();

    void on_moneyLineEdit_inputRejected();



private:
    Ui::DialogIncome *ui;

    QList<QString> forCalculate;

    void load();
    void save();



};

#endif // DIALOGINCOME_H
