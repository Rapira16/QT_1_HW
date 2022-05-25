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
    int val_angle = ui->angle->text().toInt();
    int val_side_1 = ui->side_1->text().toInt();
    int val_side_2 = ui->side_2->text().toInt();

    if (ui->angle_radians_radio->isChecked())
    {
        float side_3 = qSqrt(val_side_1 * val_side_1 + val_side_2*val_side_2 - 2 * val_side_1 * val_side_2 * qCos(val_angle));
        ui->answer->setText(QString::number(side_3));
    }
    else
    {
        float val_radians = qDegreesToRadians(val_angle);
        float side_3 = qSqrt(val_side_1 * val_side_1 + val_side_2*val_side_2 - 2 * val_side_1 * val_side_2 * qCos(val_radians));
        ui->answer->setText(QString::number(side_3));
    }
}

