#include "dialogexpenditure.h"
#include "ui_dialogexpenditure.h"

DialogExpenditure::DialogExpenditure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogExpenditure)
{
    ui->setupUi(this);

    load(); //always load the data
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime()); //set to the current time as default
    connect(ui->moneyLineEdit,&QLineEdit::textChanged,this,&DialogExpenditure::on_moneyLineEdit_inputRejected); //connet signal to check the user input(money)
}

DialogExpenditure::~DialogExpenditure()
{
    delete ui;
}

void DialogExpenditure::load()
{
    //load the data by using QSettings
    QSettings settings("Beam2","MyApp"); //this is like a file name
    int listsize = settings.beginReadArray("Expenditure1"); //create the name of array
    QString allItemsinListwidget;
    QList<QString> split;
    for (int i = 0;i < listsize; i++)
    {
        settings.setArrayIndex(i);
        qInfo() << "load";
        ui->listWidget->addItem(settings.value("Expenditure").toString()); //add item to listwidget

        allItemsinListwidget = settings.value("Expenditure").toString(); //get each the data, and use for calculating
        split = allItemsinListwidget.split(QRegularExpression("\n")); //split and put it in QList<QString>
        forCalculate << split[2]; //add only the money
    }

    settings.endArray();
    qInfo() << settings.fileName();
}

void DialogExpenditure::save()
{
    QSettings settings("Beam2","MyApp");
    settings.clear(); //always clear, careful with redundant data
    settings.beginWriteArray("Expenditure1");

    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        settings.setArrayIndex(i);

        settings.setValue("Expenditure", ui->listWidget->item(i)->text());

    }
    settings.endArray();


}


void DialogExpenditure::on_addPushBtn_clicked()
{

    QString sum = "";
    QList<QString> temp = {ui->dateTimeEdit->dateTime().toString(),ui->activitiesLineEdit->text(),ui->moneyLineEdit->text()}; //get the data

    QString forCalculateInAdd = {ui->moneyLineEdit->text()}; //when user just add the new data and want to calculate
    forCalculate << forCalculateInAdd;

    //check the money input
    bool ok;
    double checkNum;
    checkNum = QString(ui->moneyLineEdit->text()).toDouble(&ok);
    if (checkNum == 0)
    {
        QMessageBox::critical(this,"Not Number", "You doesn't enter money");
        return;
    }

    //make the format
    for (int i = 0;i<3 ;i++ )
    {
        sum += temp[i];
        sum += "\n";
    }

    ui->listWidget->addItem(sum); //add to the listWidget
}

void DialogExpenditure::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button->text().contains("OK"))
    {
        save(); //save the data
        accept();
    }
    if(button->text().contains("Cancel"))
    {
        reject(); //reject all the data that user put
    }
}

void DialogExpenditure::on_removePushBtn_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems(); //item that user select


    QString removeText = ui->listWidget->currentItem()->text(); //get that QString
    qInfo() << removeText;

    //make the question to ensure that user really want to remove
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Remove", "Are you sure that you want to remove this record?\n" +removeText, QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        foreach(QListWidgetItem* item, items)
        {
            ui->listWidget->removeItemWidget(item);
            delete item;
        }
        qInfo() << "Yes was clicked";
    }
    else
    {
        qInfo() <<"No was clicked";
    }

}

void DialogExpenditure::on_pushButton_clicked()
{
    //push button clear
    //make the question to ensure that user really want to clear
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Clear", "Are you sure that you want to clear all records?", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        ui->listWidget->clear();
        qInfo() << "Yes was clicked";
    }
    else
    {
        qInfo() <<"No was clicked";
    }

}

void DialogExpenditure::on_calculatePushBtn_clicked()
{
    double sum = 0;

    for (int i = 0; i < ui->listWidget->count() ; i++ )
    {
        sum += forCalculate[i].toDouble();
    }
    QString changeToString = QString::number(sum); //change it back to QString
    QMessageBox::information(this,"Calculate","Expenditures = "+changeToString);


}

void DialogExpenditure::on_moneyLineEdit_inputRejected()
{
    bool ok;
    double test;
    test = QString(ui->moneyLineEdit->text()).toDouble(&ok);

    QVariant test2 = ui->moneyLineEdit->text(); //use to check that user input nothing or not
    if (test2 == "")
    {
        QMessageBox::critical(this,"Warning", "You enter nothing");
        return;
    }

    if (test == 0)
    {
        QMessageBox::critical(this,"Not number", "You enter "+ui->moneyLineEdit->text());
    }

}
