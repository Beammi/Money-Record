/*
 * Name: Ratchwalee Wongritdechakit
 * Student ID: 63011290
 */
#include"dialoglogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogLogin w;
    w.show();
    return a.exec();
}
