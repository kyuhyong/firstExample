#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonQuit_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_actionOpen_triggered()
{
    QString folderName = QFileDialog::getExistingDirectory(this,tr("Open Folder"), QString());

    if (!folderName.isEmpty()) {
        QFile file(folderName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        //ui->textEdit->setText(in.readAll());
        file.close();
    }
}

void MainWindow::on_lineEditHomeLat_textEdited(const QString &arg1)
{
    QString inputStr = ui->lineEditHomeLat->text();
    double lat = inputStr.toDouble();
    if(lat <0.0) {
        QMessageBox::critical(this, tr("Error"), tr("Error input"));
        return;
    }
    homePosition.lat = lat;
}
