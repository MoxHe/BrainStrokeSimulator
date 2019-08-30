#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Input_PGM_files.hpp"
#include "Output_PGM_files.hpp"
#include "Set_boundaries.hpp"
#include "Create_models.hpp"
#include "Models_operation.hpp"
#include "Find_origin.hpp"
#include <QMainWindow>
#include <string>
#include <Qstring>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

        int type;
        char size;
        int origin_x, origin_y,origin_z;
        int a, b, c;
        int generate=0;

        private slots:


        void on_horizontalSlider_valueChanged(int value); 
        void on_horizontalSlider_2_valueChanged(int value); 
        void on_horizontalSlider_3_valueChanged(int value);
        void on_horizontalSlider_4_valueChanged(int value);
        void on_horizontalSlider_5_valueChanged(int value);
        void on_horizontalSlider_6_valueChanged(int value);
        void on_comboBox_currentIndexChanged(int index);
        void on_generate_models_clicked();
        void on_deletemodels_clicked();
        void  on_spinBox_10_valueChanged(int arg1); 
        void lon_spinBox_11_valueChanged(int arg1); 
        void on_spinBox_12_valueChanged(int arg1);
        void on_radioButton_pressed();

        void on_radioButton_2_pressed();

        void on_radioButton_3_pressed();

        void on_spinBox_7_valueChanged(int arg1);

        void on_spinBox_8_valueChanged(int arg1);

        void on_spinBox_9_valueChanged(int arg1);
    private:  
        Ui::MainWindow *ui;  
        int front_index,top_index,side_index;  
        int w1=265;  
        int h1= 286;  
        int w2=490;  
        int h2= 286;  
        int w3=265;  
        int h3= 490;  
};  
#endif // MAINWINDOW_H  
