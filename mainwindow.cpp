#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("com1");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity((QSerialPort::NoParity));
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open((QIODevice::ReadWrite));

    socket = new QTcpSocket(this);

    socket->connectToHost("127.0.0.1", 5000);




}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->hor_scroll->setText(s);
}


void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->ver_label->setText(s);

}


void MainWindow::on_pushButton_2_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        if (ui->checkBox->checkState()){
            serial->write("ADZZ;VFL:1");
        }
        else{
            serial->write("ADZZ;VFL:0");
        }
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        if (ui->checkBox->checkState()){
            socket->write("ADZZ;VFL:1");
        }
        else{
            socket->write("ADZZ;VFL:0");
        }
        socket->write("\x03");
    }

}


void MainWindow::on_pushButton_3_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VRH:");
        auto num = ui->hor_scroll->text().toUtf8();
        serial->write(num);
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VRH:");
        auto num = ui->hor_scroll->text().toUtf8();
        socket->write(num);
        socket->write("\x03");
    }
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VRV:");
        auto num = ui->ver_label->text().toUtf8();
        serial->write(num);
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VRV:");
        auto num = ui->ver_label->text().toUtf8();
        socket->write(num);
        socket->write("\x03");
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    std::vector<std::string> mas {"ENG", "DEU", "FRA", "ESP", "ITL", "JPN", "CHI",
                                   "RUS", "KOR", "POR", "SVE", "NOR", "DAN", "POL",
                                   "CES", "MAG", "THA", "NLD", "FIN", "RUM", "TUR",
                                   "ARA", "KAZ", "VIE"};

    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;OLG:");
        serial->write(mas[ui->comboBox->currentIndex()].c_str());
        serial->write("\x03");
}
    else{
        socket->write("\x02");
        socket->write("ADZZ;OLG:");
        socket->write(mas[ui->comboBox->currentIndex()].c_str());
        socket->write("\x03");
    }
}




void MainWindow::on_pushButton_5_clicked()
{
    std::vector<std::string> mas {"00000", "00001", "00010", "00011"};
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VXX:DMDI1=+");
        serial->write(mas[ui->comboBox_2->currentIndex()].c_str());
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VXX:DMDI1=+");
        socket->write(mas[ui->comboBox_2->currentIndex()].c_str());
        socket->write("\x03");
    }
}


void MainWindow::on_horizontalSlider_3_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_7->setText(s);
}


void MainWindow::on_pushButton_6_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VXX:DSNI2=+");
        std::string str = ui->label_7->text().toStdString();
        if (str.size() < 5){
            for (int i = str.size(); i < 5; ++i){
                serial->write("0");
            }
        }
        serial->write(str.c_str());
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VXX:DSNI2=+");
        std::string str = ui->label_7->text().toStdString();
        if (str.size() < 5){
            for (int i = str.size(); i < 5; ++i){
                socket->write("0");
            }
        }
        socket->write(str.c_str());
        socket->write("\x03");
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VXX:DSWI1=+");

        if (ui->comboBox_3->currentIndex() == 0){
            serial->write("00000");
        }
        else{
            serial->write("00001");
        }
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VXX:DSWI1=+");

        if (ui->comboBox_3->currentIndex() == 0){
            socket->write("00000");
        }
        else{
            socket->write("00001");
        }
        socket->write("\x03");
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VXX:DSWI2=+");

        if (ui->comboBox_4->currentIndex() == 0){
            serial->write("00000");
        }
        else{
            serial->write("00001");
        }
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VXX:DSWI2=+");

        if (ui->comboBox_4->currentIndex() == 0){
            socket->write("00000");
        }
        else{
            socket->write("00001");
        }
        socket->write("\x03");
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    std::vector<std::string> mas {"00000", "00001", "00003", "00004", "00006"};
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VXX:DIFI1=+");
        serial->write(mas[ui->comboBox_5->currentIndex()].c_str());
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VXX:DIFI1=+");
        socket->write(mas[ui->comboBox_5->currentIndex()].c_str());
        socket->write("\x03");
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VXX:DMGI1=+");

        if (ui->comboBox_6->currentIndex() == 0){
            serial->write("00000");
        }
        else{
            serial->write("00001");
        }
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VXX:DMGI1=+");

        if (ui->comboBox_6->currentIndex() == 0){
            socket->write("00000");
        }
        else{
            socket->write("00001");
        }
        socket->write("\x03");
    }
}




void MainWindow::on_pushButton_11_clicked()
{
    std::vector<std::string> mas {"00000", "00001", "00002", "00004"};
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VXX:CMAI0=+");
        serial->write(mas[ui->comboBox_7->currentIndex()].c_str());
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VXX:CMAI0=+");
        socket->write(mas[ui->comboBox_7->currentIndex()].c_str());
        socket->write("\x03");
    }
}


void MainWindow::on_horizontalSlider_4_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_25->setText(s);
}


void MainWindow::on_horizontalSlider_5_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_26->setText(s);
}


void MainWindow::on_horizontalSlider_6_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_27->setText(s);

}


void MainWindow::on_horizontalSlider_7_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_28->setText(s);
}


void MainWindow::on_horizontalSlider_8_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_29->setText(s);
}


void MainWindow::on_horizontalSlider_9_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_30->setText(s);
}


void MainWindow::on_horizontalSlider_10_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_31->setText(s);
}


void MainWindow::on_horizontalSlider_11_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_32->setText(s);
}


void MainWindow::on_horizontalSlider_12_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_33->setText(s);
}


void MainWindow::on_pushButton_12_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VMR:");
        std::string str = ui->label_25->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_26->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_27->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VMR:");
        std::string str = ui->label_25->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_26->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_27->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write("\x03");
    }



}


void MainWindow::on_pushButton_13_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VMG:");
        std::string str = ui->label_28->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_29->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_30->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VMG:");
        std::string str = ui->label_28->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_29->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_30->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write("\x03");
    }
}


void MainWindow::on_pushButton_14_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VMB:");
        std::string str = ui->label_31->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_32->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_33->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VMB:");
        std::string str = ui->label_31->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_32->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_33->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write("\x03");
    }
}


void MainWindow::on_pushButton_15_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VMW:");
        std::string str = ui->label_35->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VMW:");
        std::string str = ui->label_35->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write("\x03");
    }
}


void MainWindow::on_horizontalSlider_13_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_35->setText(s);
}


void MainWindow::on_horizontalSlider_14_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_36->setText(s);
}


void MainWindow::on_horizontalSlider_15_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_37->setText(s);
}


void MainWindow::on_horizontalSlider_16_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_38->setText(s);
}


void MainWindow::on_horizontalSlider_29_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_73->setText(s);
}


void MainWindow::on_horizontalSlider_30_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_75->setText(s);
}


void MainWindow::on_horizontalSlider_31_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_77->setText(s);
}


void MainWindow::on_horizontalSlider_32_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_80->setText(s);
}


void MainWindow::on_horizontalSlider_33_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_82->setText(s);
}


void MainWindow::on_horizontalSlider_34_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_84->setText(s);
}


void MainWindow::on_horizontalSlider_35_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_87->setText(s);
}


void MainWindow::on_horizontalSlider_36_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_89->setText(s);
}


void MainWindow::on_horizontalSlider_37_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_91->setText(s);
}


void MainWindow::on_horizontalSlider_38_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_94->setText(s);
}


void MainWindow::on_horizontalSlider_39_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_96->setText(s);
}


void MainWindow::on_horizontalSlider_40_sliderMoved(int position)
{
    QString s = QString::number(position);
    ui->label_98->setText(s);
}


void MainWindow::on_pushButton_16_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VXX:C7CS0=");
        std::string str = ui->label_36->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_37->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_38->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VXX:C7CS0=");
        std::string str = ui->label_36->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_37->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_38->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write("\x03");
    }
}


void MainWindow::on_pushButton_17_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VXX:C7CS1=");
        std::string str = ui->label_73->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_75->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_77->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VXX:C7CS1=");
        std::string str = ui->label_73->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_75->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_77->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write("\x03");
    }
}


void MainWindow::on_pushButton_18_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VXX:C7CS2=");
        std::string str = ui->label_80->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_82->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_84->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VXX:C7CS2=");
        std::string str = ui->label_80->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_82->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_84->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write("\x03");
    }
}


void MainWindow::on_pushButton_19_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VXX:C7CS3=");
        std::string str = ui->label_87->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_89->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_91->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VXX:C7CS3=");
        std::string str = ui->label_87->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_89->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_91->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write("\x03");
    }
}


void MainWindow::on_pushButton_20_clicked()
{
    if (ui->combo_main->currentIndex() == 0){
        serial->write("\x02");
        serial->write("ADZZ;VXX:C7CS4=");
        std::string str = ui->label_94->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_96->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write(".");
        str = ui->label_98->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            serial->write("0");
        }
        serial->write(str.c_str());
        serial->write("\x03");
    }
    else{
        socket->write("\x02");
        socket->write("ADZZ;VXX:C7CS4=");
        std::string str = ui->label_94->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_96->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write(".");
        str = ui->label_98->text().toStdString();
        for (int i = str.size(); i < 4; ++i){
            socket->write("0");
        }
        socket->write(str.c_str());
        socket->write("\x03");
    }
}

