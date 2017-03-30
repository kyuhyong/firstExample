#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);   //parent = 0 means its top level widget
    ~MainWindow();

    struct position {
        double lat;
        double lon;
        double utmx_lat;
        double utmx_lon;
    };
    position homePosition;

private slots:
    void on_pushButtonQuit_clicked();

    void on_actionOpen_triggered();

    void on_lineEditHomeLat_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
