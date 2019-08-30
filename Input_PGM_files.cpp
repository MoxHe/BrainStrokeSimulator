//  
//  Input_PGM_files.cpp  
//  practice2  
//  
//  Created by Moxiao He on 08/02/2018.  
//  Copyright © 2018 Moxiao He. All rights reserved.  
//  

#include "Input_PGM_files.hpp"  
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


using namespace std;  

#define Width 265  
#define Height 490  
#define NooFiles 286  

void Input_PGM_files::Input()  
{  
    // open and read files  
    for(int k=0;k<NooFiles;k++)  
    {  
        count_files = k+14;  

        //convert "number_of_file" from int to string  
        stringstream ss;  
        ss << count_files;  
        ss >> No_files;  

        //name the file  
        if(0 < count_files && count_files < 10)  
            file_name="v1_0000" + No_files + ".pgm";  
        else if (9 < count_files && count_files < 100)  
            file_name="v1_000" + No_files + ".pgm";  
        else if (99< count_files && count_files < 1000)  
            file_name="v1_00" + No_files + ".pgm";  
        else  
            file_name="v1_0" + No_files + ".pgm";  

        //open each file  
        ifstream infile;  
        infile.open("/Users/moxiaohe/Desktop/riken/"+file_name);  
        if(!infile)  
            cout<<"error"<<endl;  

        getline(infile,line);    // skip magic number  
        getline(infile,line);    // skip comments  
        getline(infile,line);    // skip top dimension  
        getline(infile,line);    // skip maximum value  


        //extract every pixel value and convert it to int  
        for(int j=0;j<Height;j++)  
            for(int i=0;i<Width;i++)  
            {  
                getline(infile,line);  
                image_array[i][j][k]=atoi(line.c_str());  
            }  
        infile.close();  

    }  


} 

