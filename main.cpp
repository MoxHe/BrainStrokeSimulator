#include "mainwindow.h"  
#include <QApplication>  
#include "Input_PGM_files.hpp"  
#include "Output_PGM_files.hpp"  
#include "Set_boundaries.hpp"  
#include "Create_models.hpp"  
#include "Models_operation.hpp"  
#include "Find_origin.hpp"  
#include <iostream>  
#include <fstream>  
#include<sstream>  
#include <string>  
#include <random>  
#include <vector>  

#define Width 265  
#define Height 490  
#define NooFiles 286  
using namespace std;  

Input_PGM_files original_input;  
Output_PGM_files output;  
Set_boundaries boundaries(original_input);  
Find_origin origin(boundaries);  
Create_models models(boundaries);  
Models_operation operation(models);  

int main(int argc, char *argv[])  
{  
    QApplication pro(argc, argv);  
    MainWindow w;  
    w.show();  

    //static int a, b, c;    // Three parameters for ellipsoid  

    //instantiate classes  



    original_input.Input();    // input the entire DHP wthout stroke models files and store it in a vector  

    if(output.Check_files()=='N')    // Check if three views have been created. If not, then generate three views without stroke models  
    {  
        output.Output_top_views(ref(original_input));  

        output.Output_front_views(ref(original_input));  

        output.Output_side_views(ref(original_input));  

        cout<<"outputing pgm files in three views without storke models is completed"<<endl;  
        cout<<endl;  
    }  

    //set the boundaries for inserting models  
    boundaries.boundary_Z();  
    boundaries.boundary_X();  
    boundaries.boundary_Y();  
    boundaries.display_boundaries();  

    return pro.exec();  
} 

