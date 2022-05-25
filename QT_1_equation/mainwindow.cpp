#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_commandLinkButton_clicked()
{
    int val_a = ui->number_a->text().toInt();
    int val_b = ui->number_b->text().toInt();
    int val_c = ui->number_c->text().toInt();
    int D = val_b * val_b - 4 * val_a * val_c;
    if (D < 0)
    {
        ui->answer_x1->setText(QString("Нет корней"));
        ui->answer_x2->setText(QString("Нет корней"));
    }
    else if (D > 0)
    {

        float x1 = (-val_b + qSqrt(D)/(2*val_a));
        float x2 = (-val_b + qSqrt(D)/(2*val_a));
        ui->answer_x1->setText(QString::number(x1));
        ui->answer_x2->setText(QString::number(x2));
    }
    else
    {
        float x12 = -val_b/(2*val_a);
        ui->answer_x1->setText(QString::number(x12));
        ui->answer_x2->setText(QString::number(x12));
    }
}

