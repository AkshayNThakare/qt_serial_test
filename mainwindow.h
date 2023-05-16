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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//    bool eventFilter(QObject *watched, QEvent *event);

    void openPorts() ;
    void closePorts();


public slots:
    void onDataAvailable1();
    void onDataAvailable2();
    void onDataAvailable3();
    void onDataAvailable4();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
