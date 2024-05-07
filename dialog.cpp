#include "dialog.h"
#include "ui_dialog.h"
//########################################################################################################
#include <fstream>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
using namespace std;
#include <string>
//########################################################################################################
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
//########################################################################################################
////////////////////////////////////////////// загрузка нейронов и сигнала из файла в вектор ////////////////// //////////////////////////////////////////////////////////////////////////////////////////////////////////////
//QString Nazvaniye_fayla_s_neyronami_i_signalom="/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji_2/6/neurons_and_signal.txt";
///// 
//    std::ifstream is(
//            Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str() 
//        );
//        std::vector<unsigned long long> list_of_neurons(250, 0ULL);
//    std::istream_iterator<unsigned long long> start(is), end;  // end

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
//########################################################################################################

std::vector<unsigned long long> list_of_neurons;

//void loadFromFile(const QString& fileName) 
QString Nazvaniye_fayla_s_neyronami_i_signalom="/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji_2/7/neurons_and_signal.txt";
const QString& fileName=Nazvaniye_fayla_s_neyronami_i_signalom;
{
    std::ifstream file(fileName.toStdString().c_str());
    if (file.is_open()) {
        unsigned long long value;
        while (file >> value) {
            list_of_neurons.push_back(value);
        }
        file.close();
    } else {
        qDebug() << "Unable to open file: " << fileName;
    }
}
//########################################################################################################
// Создаем файл для записи вектора
QString fileName2 = Nazvaniye_fayla_s_neyronami_i_signalom; // имя файла для записи вектора
QFile file2(fileName2);
if (file2.open(QFile::WriteOnly | QFile::Text)) {
    QTextStream out(&file2);
    for (unsigned long long neuron : list_of_neurons) {
        out << neuron << "\n";
    }
    file2.close();
} else {
    qDebug() << "Error: unable to open file for writing";
}

//########################################################################################################  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
               fstream file3;
                file3.open(

                   Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str() 
        
                 ,ios_base::out);
                
                vector<unsigned long long>::iterator itr2;
                
for (itr2=list_of_neurons.begin(); itr2 != list_of_neurons.begin() + 250; ++itr2) {
    file3 << *itr2 << endl;
}
                
        file3.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//########################################################################################################
}

Dialog::~Dialog()
{
    delete ui;
}

