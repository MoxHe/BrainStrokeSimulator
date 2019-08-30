//  
//  Output_PGM_files.cpp  
//  practice2  
//  
//  Created by Moxiao He on 01/03/2018.  
//  Copyright © 2018 Moxiao He. All rights reserved.  
//  
#include "Output_PGM_files.hpp"  
#include <iostream>  
#include <sstream>  
#include <fstream>  
#include <vector>  

#define Width 265  
#define Height 490  
#define NooFiles 286  

using namespace std;  

char Output_PGM_files::Check_files()  
{  
    // check whether three views without stroke models have been created  
    fstream file;  
    file.open("/Users/moxiaohe/Desktop/three_views_models/front_view/front_00001.pgm",ios::in);  
    if(!file)  
    {  
        cout<<"three views without stroke models haven't been created"<<endl;  
        cout<<endl;  
        return 'N';  
    }  
    else  
    {  
        cout<<"three views without stroke models have already been created"<<endl;  
        cout<<endl;  
        return 'Y';  
    }  
}  

void Output_PGM_files::Output_top_views(Input_PGM_files& theinput)  
{  

    // output top_view files  
    for (int top_count=1;top_count<NooFiles+1;top_count++)  
    {  
        //convert "number_of_file" from int to string  
        stringstream ss;  
        ss << top_count;  
        ss >> No_top;  

        //name the file  
        if(0 < top_count && top_count < 10)  
            file_name="top_0000" + No_top + ".pgm";  
        else if (9 < top_count && top_count < 100)  
            file_name="top_000" + No_top + ".pgm";  
        else if (99< top_count && top_count < 1000)  
            file_name="top_00" + No_top + ".pgm";  
        else  
            file_name="top_0" + No_top + ".pgm";  

        //create files  
        ofstream outfile;  
        outfile.open("/Users/moxiaohe/Desktop/three_views_models/top_view/" + file_name);  

        outfile<<"P2"<<'\n';    //write magic number  
        outfile<<"# test"<<'\n';    //wirte comments  
        outfile<<"265 490"<<'\n';  // wirte dimension of top view  
        outfile<<"94"<<'\n';    // maximum value  

        // write each pixel value  
        for(int j=0;j<Height;j++)  
            for(int i=0;i<Width;i++)  
                outfile<<theinput.image_array[i][j][top_count-1]<<'\n';  

        outfile.close();  
    }  

}  

void Output_PGM_files::Output_front_views(Input_PGM_files& theinput)  
{  
    // output front_view files  
    for (int front_count=1;front_count<Width+1;front_count++)  
    {  
        //convert "number_of_file" from int to string  
        stringstream ss;  
        ss << front_count;  
        ss >> No_front;  

        //name the file  
        if(0 < front_count && front_count < 10)  
            file_name="front_0000" + No_front + ".pgm";  
        else if (9 < front_count && front_count < 100)  
            file_name="front_000" + No_front + ".pgm";  
        else if (99< front_count && front_count < 1000)  
            file_name="front_00" + No_front + ".pgm";  
        else  
            file_name="front_0" + No_front + ".pgm";  

        //create files  
        ofstream outfile;  
        outfile.open("/Users/moxiaohe/Desktop/three_views_models/front_view/" + file_name);  

        outfile<<"P2"<<'\n';    //write magic number  
        outfile<<"# test"<<'\n';    //wirte comments  
        outfile<<"490 286"<<'\n';  // wirte dimension of front view  
        outfile<<"94"<<'\n';    // maximum value  

        // write each pixel value  
        for(int k=0;k<NooFiles;k++)  
            for(int j=0;j<Height;j++)  
                outfile<<theinput.image_array[front_count-1][j][k]<<'\n';  

        outfile.close();  
    }  

}  

void Output_PGM_files::Output_side_views(Input_PGM_files& theinput)  
{  
    // output side_view files  
    for (int side_count=1;side_count<Height+1;side_count++)  
    {  
        //convert "number_of_file" from int to string  
        stringstream ss;  
        ss << side_count;  
        ss >> No_side;  

        //name the file  
        if(0 < side_count && side_count < 10)  
            file_name="side_0000" + No_side + ".pgm";  
        else if (9 < side_count && side_count < 100)  
            file_name="side_000" + No_side + ".pgm";  
        else if (99< side_count && side_count < 1000)  
            file_name="side_00" + No_side + ".pgm";  
        else  
            file_name="side_0" + No_side + ".pgm";  

        ofstream outfile;  
        outfile.open("/Users/moxiaohe/Desktop/three_views_models/side_view/" + file_name);  

        outfile<<"P2"<<'\n';    //write magic number  
        outfile<<"# test"<<'\n';    //wirte comments  
        outfile<<"265 286"<<'\n';  // wirte dimension of front view  
        outfile<<"94"<<'\n';    // maximum value  

        // write each pixel value  
        for(int k=0;k<286;k++)  
            for(int i=0;i<Width;i++)  
                outfile<<theinput.image_array[i][side_count-1][k]<<'\n';  

        outfile.close();  
    }  
} 

