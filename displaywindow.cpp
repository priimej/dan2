#include "displaywindow.h"
#include "ui_displaywindow.h"

DisplayWindow::DisplayWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DisplayWindow)
{
    ui->setupUi(this);
}

DisplayWindow::~DisplayWindow()
{
    delete ui;
}

// slightly overcomplicated but it gets the job done
void DisplayWindow::display_content() {
    QString name = "Name";
    QString age  = "Age";
    QString date = "Date";

    QString jName, jDate; int jAge;
    jName  = DisplayWindow::get_value(name).toString();
    jAge   = DisplayWindow::get_value(age).toInt();
    jDate  = DisplayWindow::get_value(date).toString();

    QString nameOut = "Name: ", ageOut = "Age: ", dateOut = "Date: ";
    ui->NameLabel->setText(nameOut.append(jName));
    ui->AgeLabel->setText(ageOut.append(QString::number(jAge)));
    ui->DateLabel->setText(dateOut.append(jDate));
}