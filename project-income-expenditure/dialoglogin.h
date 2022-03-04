#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>
#include <QDebug>
#include<QMessageBox>
#include<QList>
#include<QFile>
#include<QIODevice>
#include<QDir>
#include<QString>
#include <QTextStream>
#include <QRegularExpression>

#include"dialog.h"
#include"dialogchangepassword.h"
namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = nullptr);
    ~DialogLogin();

private slots:
    void on_pushButtonEnter_clicked();

    void on_pushButtonChange_clicked();

    void append();

    void on_pushButtonCancel_clicked();

    void on_pushButtonClear_clicked();

private:
    Ui::DialogLogin *ui;
    QString temp;
    QString password;
    QString passwordTemp;
    QStringList listPassword;

    void load();

    QString path = QDir::currentPath() + QDir::separator() + "login.txt";

};

#endif // DIALOGLOGIN_H
