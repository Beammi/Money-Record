#ifndef DIALOGCHANGEPASSWORD_H
#define DIALOGCHANGEPASSWORD_H

#include <QDialog>
#include<QDebug>
#include<QMessageBox>
#include<QList>
#include<QFile>
#include<QIODevice>
#include<QDir>
#include<QString>
#include <QTextStream>
#include<iostream>
#include <QRegularExpression>
namespace Ui {
class DialogChangePassword;
}

class DialogChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChangePassword(QWidget *parent = nullptr);
    ~DialogChangePassword();

private slots:
    void on_pushButtonVerify_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::DialogChangePassword *ui;

    QString path = QDir::currentPath() + QDir::separator() + "login.txt";
    QString password;
    QStringList listPassword;
    void changePassword();
};

#endif // DIALOGCHANGEPASSWORD_H
