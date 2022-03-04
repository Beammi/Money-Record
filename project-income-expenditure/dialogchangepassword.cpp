#include "dialogchangepassword.h"
#include "ui_dialogchangepassword.h"

DialogChangePassword::DialogChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChangePassword)
{
    ui->setupUi(this);
}

DialogChangePassword::~DialogChangePassword()
{
    delete ui;
}

void DialogChangePassword::changePassword()
{
    QFile file(path); //write new password
    if(!file.open(QIODevice::WriteOnly))
    {
        qWarning() << file.errorString();
        QMessageBox::critical(this,"Cannot Open the file",file.errorString());

    }
    QTextStream stream(&file);
    stream << "0000";
    stream << "\n";
    stream << ui->lineEditNewPw->text(); //get the new password and put it in the file
    file.close();
}

void DialogChangePassword::on_pushButtonVerify_clicked()
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning() << file.errorString();
        QMessageBox::critical(this,"Cannot Open the file",file.errorString());
    }

    QTextStream stream(&file);
    password = stream.readAll();

    listPassword = password.split(QRegularExpression("\n")); //split to get the default password
    file.close();

    if(ui->lineEditCurrentPw->text() != listPassword[0]) //check that default password is correct
    {
        QMessageBox::critical(this, "Warning","Your default password is wrong");
    }

    else
    {

        QMessageBox::information(this,"Notification","We have changed your password");
        changePassword();
        close();
    }




}

void DialogChangePassword::on_pushButtonClear_clicked()
{
    ui->lineEditCurrentPw->clear();
    ui->lineEditNewPw->clear();
}

void DialogChangePassword::on_pushButtonCancel_clicked()
{
    reject();
}
