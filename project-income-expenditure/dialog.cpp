#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    Dialog::setWindowTitle("Incomes and Expenditures");
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_incomePushbtn_clicked()
{
    dialog2->setWindowTitle("Income");
    dialog2->show();
}


void Dialog::on_expenditurePushbtn_clicked()
{
    dialog->setWindowTitle("Expenditure");
    dialog->show();
}
