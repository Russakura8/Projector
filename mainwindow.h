#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <vector>
#include <string>
#include <QTcpServer>
#include <QTcpSocket>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_2_sliderMoved(int position);



    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_horizontalSlider_3_sliderMoved(int position);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_horizontalSlider_4_sliderMoved(int position);

    void on_horizontalSlider_5_sliderMoved(int position);

    void on_horizontalSlider_6_sliderMoved(int position);

    void on_horizontalSlider_8_sliderMoved(int position);

    void on_horizontalSlider_7_sliderMoved(int position);

    void on_horizontalSlider_9_sliderMoved(int position);

    void on_horizontalSlider_10_sliderMoved(int position);

    void on_horizontalSlider_11_sliderMoved(int position);

    void on_horizontalSlider_12_sliderMoved(int position);

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_horizontalSlider_13_sliderMoved(int position);

    void on_horizontalSlider_14_sliderMoved(int position);

    void on_horizontalSlider_15_sliderMoved(int position);

    void on_horizontalSlider_16_sliderMoved(int position);

    void on_horizontalSlider_29_sliderMoved(int position);

    void on_horizontalSlider_30_sliderMoved(int position);

    void on_horizontalSlider_31_sliderMoved(int position);

    void on_horizontalSlider_32_sliderMoved(int position);

    void on_horizontalSlider_33_sliderMoved(int position);

    void on_horizontalSlider_34_sliderMoved(int position);

    void on_horizontalSlider_35_sliderMoved(int position);

    void on_horizontalSlider_36_sliderMoved(int position);

    void on_horizontalSlider_37_sliderMoved(int position);

    void on_horizontalSlider_38_sliderMoved(int position);

    void on_horizontalSlider_39_sliderMoved(int position);

    void on_horizontalSlider_40_sliderMoved(int position);

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QTcpSocket *socket;
};
#endif // MAINWINDOW_H
