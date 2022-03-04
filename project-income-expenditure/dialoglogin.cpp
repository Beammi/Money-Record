#include "dialoglogin.h"
#include "ui_dialoglogin.h"

DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);

    DialogLogin::setWindowTitle("Log in");
    connect(ui->pushButton_0,&QPushButton::clicked,this,&DialogLogin::append);
    connect(ui->pushButton_1,&QPushButton::clicked,this,&DialogLogin::append);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&DialogLogin::append);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&DialogLogin::append);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&DialogLogin::append);
    connect(ui->pushButton_5,&QPushButton::clicked,this,&DialogLogin::append);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&DialogLogin::append);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&DialogLogin::append);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&DialogLogin::append);
    connect(ui->pushButton_9,&QPushButton::clicked,this,&DialogLogin::append);
    load();

}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::on_pushButtonEnter_clicked()
{
    load(); //make sure that we have the correct data
    for (int i = 0;i<listPassword.size() ;i++ ) //loop for checking the password
    {
        qInfo()<<passwordTemp;
        if(passwordTemp == listPassword[i]) //if it's correct it will create the dialog and close dialoglogin
        {
            close();
            Dialog *dialog = new Dialog(this);
            dialog->show();

        }

    }

    if(listPassword[0] != passwordTemp and listPassword[1]!=passwordTemp) //if the password is wrong
    {
        QMessageBox::critical(this,"Warning","Wrong Password entered");
        ui->label_2->setText("You already entered: ");
        temp.clear();
        passwordTemp.clear();
    }

}

void DialogLogin::on_pushButtonChange_clicked()
{
    DialogChangePassword *dialogChangePassword = new DialogChangePassword(this);
    dialogChangePassword->setWindowTitle("Change Password");
    dialogChangePassword->show();
}

void DialogLogin::append()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender()); //casting
    if(!btn)
    {
        return;
    }

    temp.append("*"); //to show the user that their input becomes "*"
    passwordTemp.append(btn->text()); //get this to compare with password that it is equal
    ui->label_2->setText("You already entered: "+temp);

    if(temp.size()>0 and temp.size()<4)
    {
        ui->pushButtonEnter->setEnabled(true);
    }
    if(temp.size()>4) //input have to be no more than 4
    {
        QMessageBox::critical(this,"Warning","The lenght of password is too long");
        ui->pushButtonEnter->setEnabled(false);
    }

}

void DialogLogin::load()
{
    //load the file that contains the passwords
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning() << file.errorString();
        QMessageBox::critical(this,"Cannot Open the file",file.errorString());

    }
    QTextStream stream(&file);
    password = stream.readAll();
    qInfo()<<"This "+password;
    listPassword = password.split(QRegularExpression("\n")); //split because we let user has 2 passwords one for default, another for creating new password
    file.close();
}

void DialogLogin::on_pushButtonCancel_clicked()
{
    reject();
}

void DialogLogin::on_pushButtonClear_clicked()
{
    ui->label_2->setText("You already entered: ");
    temp.clear();
    passwordTemp.clear();
}
