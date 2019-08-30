#include "mainwindow.h"  
#include "ui_mainwindow.h"  
#include <QDebug>  
#include <QMessageBox>  


MainWindow::MainWindow(QWidget *parent) :  
    QMainWindow(parent),  
    ui(new Ui::MainWindow)  
{  
    ui->setupUi(this);  
    ui->spinBox->setRange(1,490);  
    ui->horizontalSlider->setRange(1,490);  
    ui->spinBox_2->setRange(1,265);  
    ui->horizontalSlider_2->setRange(1,265);  
    ui->spinBox_3->setRange(1,286);  
    ui->horizontalSlider_3->setRange(1,286);  
    ui->spinBox_4->setRange(1,490);  
    ui->horizontalSlider_4->setRange(1,490);  
    ui->spinBox_5->setRange(1,265);  
    ui->horizontalSlider_5->setRange(1,265);  
    ui->spinBox_6->setRange(1,286);  
    ui->horizontalSlider_6->setRange(1,286);  

    ui->comboBox->addItem("Ischemic: Large-vessel Thrombosis");  
    ui->comboBox->addItem("Ischemic: lacunar Stroke");  
    ui->comboBox->addItem("Hemorrhagic: Intracerebral Hemorrhage");  
    ui->comboBox->addItem("Hemorrhagic: Subarachnoid Hemorrhage");  

    ui->delete_models->hide();  

    ui->spinBox_7->setRange(3,7);  
    ui->spinBox_8->setRange(3,7);  
    ui->spinBox_9->setRange(3,7);  

    ui->spinBox_10->setRange(12,231);  
    ui->spinBox_11->setRange(161,338);  
    ui->spinBox_12->setRange(0,194);  
    type=ui->comboBox->currentIndex();  


    if(ui->radioButton->isChecked()==1)  
        size='S';  
    else if(ui->radioButton_2->isChecked()==1)  
        size='M';  
    else  
        size='L';  

    origin_x=ui->spinBox_10->value();  
    origin_y=ui->spinBox_11->value();  
    origin_z=ui->spinBox_12->value();  

    a=ui->spinBox_7->value();  
    b=ui->spinBox_8->value();  
    c=ui->spinBox_9->value();  
}  

MainWindow::~MainWindow()  
{  
    delete ui;  
}  


void MainWindow::on_horizontalSlider_valueChanged(int count_files)  
{  


    QString file_name;  
    QString No_files;  
    No_files= QString::number(count_files);  

    //name the file  
    if(0 < count_files && count_files < 10)  
        file_name="side_0000" + No_files + ".pgm";  
    else if (9 < count_files && count_files < 100)  
        file_name="side_000" + No_files + ".pgm";  
    else if (99< count_files && count_files < 1000)  
        file_name="side_00" + No_files + ".pgm";  
    else  
        file_name="side_0" + No_files + ".pgm";  

    QPixmap pix("/Users/moxiaohe/Desktop/three_views_models/side_view/"+file_name);  

    ui->side->setPixmap(pix.scaled(w1,h1,Qt::KeepAspectRatio));  
}  

void MainWindow::on_horizontalSlider_2_valueChanged(int count_files)  
{  
    QString file_name;  
    QString No_files;  
    No_files= QString::number(count_files);  

    //name the file  
    if(0 < count_files && count_files < 10)  
        file_name="front_0000" + No_files + ".pgm";  
    else if (9 < count_files && count_files < 100)  
        file_name="front_000" + No_files + ".pgm";  
    else if (99< count_files && count_files < 1000)  
        file_name="front_00" + No_files + ".pgm";  
    else  
        file_name="front_0" + No_files + ".pgm";  

    QPixmap pix("/Users/moxiaohe/Desktop/three_views_models/front_view/"+file_name);  

    ui->front->setPixmap(pix.scaled(w2,h2,Qt::KeepAspectRatio));  
}  

void MainWindow::on_horizontalSlider_3_valueChanged(int count_files)  
{  
    QString file_name;  
    QString No_files;  
    No_files= QString::number(count_files);  

    //name the file  
    if(0 < count_files && count_files < 10)  
        file_name="top_0000" + No_files + ".pgm";  
    else if (9 < count_files && count_files < 100)  
        file_name="top_000" + No_files + ".pgm";  
    else if (99< count_files && count_files < 1000)  
        file_name="top_00" + No_files + ".pgm";  
    else  
        file_name="top_0" + No_files + ".pgm";  



    QPixmap pix("/Users/moxiaohe/Desktop/three_views_models/top_view/"+file_name);  

    ui->top->setPixmap(pix.scaled(w3,h3,Qt::KeepAspectRatio));  
}  

void MainWindow::on_horizontalSlider_4_valueChanged(int count_files)  
{  
    QString file_name;  
    QString No_files;  
    No_files= QString::number(count_files);  

    //name the file  
    if(0 < count_files && count_files < 10)  
        file_name="side_0000" + No_files + "(copy).pgm";  
    else if (9 < count_files && count_files < 100)  
        file_name="side_000" + No_files + "(copy).pgm";  
    else if (99< count_files && count_files < 1000)  
        file_name="side_00" + No_files + "(copy).pgm";  
    else  
        file_name="side_0" + No_files + "(copy).pgm";  

    QPixmap pix("/Users/moxiaohe/Desktop/three_views_models/side_view/"+file_name);  

    ui->processed_side_image->setPixmap(pix.scaled(w1,h1,Qt::KeepAspectRatio));  
}  

void MainWindow::on_horizontalSlider_5_valueChanged(int count_files)  
{  
    QString file_name;  
    QString No_files;  
    No_files= QString::number(count_files);  

    //name the file  
    if(0 < count_files && count_files < 10)  
        file_name="front_0000" + No_files + "(copy).pgm";  
    else if (9 < count_files && count_files < 100)  
        file_name="front_000" + No_files + "(copy).pgm";  
    else if (99< count_files && count_files < 1000)  
        file_name="front_00" + No_files + "(copy).pgm";  
    else  
        file_name="front_0" + No_files + "(copy).pgm";  



    QPixmap pix("/Users/moxiaohe/Desktop/three_views_models/front_view/"+file_name);  

    ui->processed_front_image->setPixmap(pix.scaled(w2,h2,Qt::KeepAspectRatio));  
}  

void MainWindow::on_horizontalSlider_6_valueChanged(int count_files)  
{  
    QString file_name;  
    QString No_files;  
    No_files= QString::number(count_files);  

    //name the file  
    if(0 < count_files && count_files < 10)  
        file_name="top_0000" + No_files + "(copy).pgm";  
    else if (9 < count_files && count_files < 100)  
        file_name="top_000" + No_files + "(copy).pgm";  
    else if (99< count_files && count_files < 1000)  
        file_name="top_00" + No_files + "(copy).pgm";  
    else  
        file_name="top_0" + No_files + "(copy).pgm";  



    QPixmap pix("/Users/moxiaohe/Desktop/three_views_models/top_view/"+file_name);  

    ui->processed_top_image->setPixmap(pix.scaled(w3,h3,Qt::KeepAspectRatio));  
}  


void MainWindow::on_comboBox_currentIndexChanged(int index)  
{  
    if(index==1)  
    {  

        ui->groupBox_11->show();  
        ui->groupBox_14->hide();  
    }  
    else  
    {  
        ui->groupBox_11->hide();  
        ui->groupBox_14->show();  
    }  

    type=ui->comboBox->currentIndex();  

}  

void MainWindow::on_generate_models_clicked()  
{  
    extern Input_PGM_files original_input;  
    extern Output_PGM_files output;  
    extern Set_boundaries boundaries;  
    extern Find_origin origin;  
    extern Create_models models;  
    extern Models_operation operation;  


    ui->delete_models->show();  
    ui->generate_models->hide();  

    models.model_array=original_input.image_array;  
    origin.model_array=original_input.image_array;  

    models.model_x= {265,0};  
    models.model_y= {490,0};  
    models.model_z= {286,0};  

    if(type==0)  
    {  
        origin.find_origin_LT(origin_x,origin_y,origin_z);  
        models.Create_LT_models(size,origin.output_origin_x,origin.output_origin_y,origin.output_origin_z);  
    }  
    else if(type==1)  
    {  
        origin.find_origin_LS(origin_x,origin_y,origin_z);  
        models.Create_LS_models(a,b,c,origin.output_origin_x,origin.output_origin_y,origin.output_origin_z);  
    }  

    else if(type==2)  
    {  
        origin.find_origin_IH(origin_x,origin_y,origin_z);  
        models.Create_IH_models(size,origin.output_origin_x,origin.output_origin_y,origin.output_origin_z);  
    }  

    else  
    {  
        origin.find_origin_SH(origin_x,origin_y,origin_z);  
        models.Create_SH_models(size,origin.output_origin_x,origin.output_origin_y,origin.output_origin_z);  
    }  


    ui->spinBox_4->setRange(models.model_y[0],models.model_y[1]);  
    ui->horizontalSlider_4->setRange(models.model_y[0],models.model_y[1]);  
    ui->spinBox_5->setRange(models.model_x[0],models.model_y[1]);  
    ui->horizontalSlider_5->setRange(models.model_x[0],models.model_x[1]);  
    ui->spinBox_6->setRange(models.model_z[0],models.model_z[1]);  
    ui->horizontalSlider_6->setRange(models.model_z[0],models.model_z[1]);  

    if(origin.origin_available==0)  
    {  
        QString stroke;  
        if(type==0)  
            stroke="Ischemic: Large-vessel Thrombosis";  
        else if(type==1)  
            stroke="Ischemic: lacunar Stroke";  
        else if(type==2)  
            stroke="Hemorrhagic: Intracerebral Hemorrhage";  
        else  
            stroke="Hemorrhagic: Subarachnoid Hemorrhage";  

        QMessageBox::critical(this,"title","Selected oringin ("+QString::number(origin_x)+","+ QString::number(origin_y)+","+QString::number(origin_z)+") does not contain the tissue where "+ stroke+" can occur. The nearest available origin ("+QString::number(origin.output_origin_x)+","+ QString::number(origin.output_origin_y)+","+QString::number(origin.output_origin_z)+") was used instead");  
    }  

    operation.insert_front_models();  
    operation.insert_side_models();  
    operation.insert_top_models();  


}  

void MainWindow::on_delete_models_clicked()  
{  
    ui->generate_models->show();  
    ui->delete_models->hide();  

    extern Models_operation operation;  
    extern Create_models models;  


    operation.delete_front_models();  
    operation.delete_side_models();  
    operation.delete_top_models();  

}  



void MainWindow::on_spinBox_10_valueChanged(int arg1)  
{  
    origin_x=arg1;  
}  

void MainWindow::on_spinBox_11_valueChanged(int arg1)  
{  
    origin_y=arg1;  
}  

void MainWindow::on_spinBox_12_valueChanged(int arg1)  
{  
    origin_z=arg1;  
}  



void MainWindow::on_radioButton_pressed()  
{  
    size='S';  
}  

void MainWindow::on_radioButton_2_pressed()  
{  
    size='M';  
}  


void MainWindow::on_radioButton_3_pressed()  
{  
    size='L';  
}  


void MainWindow::on_spinBox_7_valueChanged(int arg1)  
{  
    a=arg1;  
}  

void MainWindow::on_spinBox_8_valueChanged(int arg1)  
{  
    b=arg1;  
}  

void MainWindow::on_spinBox_9_valueChanged(int arg1)  
{  
    c=arg1;  
}  

