//  
//  Build_up_models.cpp  
//  practice2  
//  
//  Created by Moxiao He on 02/03/2018.  
//  Copyright © 2018 Moxiao He. All rights reserved.  
//  

#include "Models_operation.hpp"  

void Models_operation::insert_top_models()  
{  
    for (int top_count=model_z[0];top_count<model_z[1]+1;top_count++)    //output top view with stroke models  
    {  
        //convert "number_of_file" from int to string  
        stringstream ss;  
        ss << top_count;  
        ss >> No_top;  

        //name the file  
        if(0 < top_count && top_count < 10)  
            file_name="top_0000" + No_top + "(copy).pgm";  
        else if (9 < top_count && top_count < 100)  
            file_name="top_000" + No_top + "(copy).pgm";  
        else if (99< top_count && top_count < 1000)  
            file_name="top_00" + No_top + "(copy).pgm";  
        else  
            file_name="top_0" + No_top + "(copy).pgm";  

        ofstream outfile;  
        outfile.open("/Users/moxiaohe/Desktop/three_views_models/top_view/" + file_name);  

        outfile<<"P2"<<'\n';    //write magic number  
        outfile<<"# test"<<'\n';    //wirte comments  
        outfile<<"265 490"<<'\n';  // wirte dimension of top view  
        outfile<<"94"<<'\n';    // maximum value  

        // write each pixel value  
        for(int j=0;j<Height;j++)  
            for(int i=0;i<Width;i++)  
                outfile<<model_array[i][j][top_count-1]<<'\n';  

        outfile.close();  
    }  
}  

void Models_operation::insert_front_models()  
{  
    // output front_view files  
    for (int front_count=model_x[0];front_count<model_x[1]+1;front_count++)  
    {  
        //convert "number_of_file" from int to string  
        stringstream ss;  
        ss << front_count;  
        ss >> No_front;  

        //name the file  
        if(0 < front_count && front_count < 10)  
            file_name="front_0000" + No_front + "(copy).pgm";  
        else if (9 < front_count && front_count < 100)  
            file_name="front_000" + No_front + "(copy).pgm";  
        else if (99< front_count && front_count < 1000)  
            file_name="front_00" + No_front + "(copy).pgm";  
        else  
            file_name="front_0" + No_front + "(copy).pgm";  

        ofstream outfile;  
        outfile.open("/Users/moxiaohe/Desktop/three_views_models/front_view/" + file_name);  

        outfile<<"P2"<<'\n';    //write magic number  
        outfile<<"# test"<<'\n';    //wirte comments  
        outfile<<"490 286"<<'\n';  // wirte dimension of front view  
        outfile<<"94"<<'\n';    // maximum value  

        // write each pixel value  
        for(int k=0;k<286;k++)  
            for(int j=0;j<Height;j++)  
                outfile<<model_array[front_count-1][j][k]<<'\n';  

        outfile.close();  
    }  
}  
void Models_operation::insert_side_models()  
{  
    // output side_view files  
    for (int side_count=model_y[0];side_count<model_y[1]+1;side_count++)  
    {  
        //convert "number_of_file" from int to string  
        stringstream ss;  
        ss << side_count;  
        ss >> No_side;  

        //name the file  
        if(0 < side_count && side_count < 10)  
            file_name="side_0000" + No_side + "(copy).pgm";  
        else if (9 < side_count && side_count < 100)  
            file_name="side_000" + No_side + "(copy).pgm";  
        else if (99< side_count && side_count < 1000)  
            file_name="side_00" + No_side + "(copy).pgm";  
        else  
            file_name="side_0" + No_side + "(copy).pgm";  

        ofstream outfile;  
        outfile.open("/Users/moxiaohe/Desktop/three_views_models/side_view/" + file_name);  

        outfile<<"P2"<<'\n';    //write magic number  
        outfile<<"# test"<<'\n';    //wirte comments  
        outfile<<"265 286"<<'\n';  // wirte dimension of front view  
        outfile<<"94"<<'\n';    // maximum value  

        // write each pixel value  
        for(int k=0;k<286;k++)  
            for(int i=0;i<Width;i++)  
                outfile<<model_array[i][side_count-1][k]<<'\n';  

        outfile.close();  
    }  

    cout<<"outputing pgm files in three views with storke models is completed"<<endl;  
    cout<<endl;  
}  

void Models_operation::delete_top_models()  
{  
    // delete models in top views  
    for (int top_count=model_z[0];top_count<model_z[1]+1;top_count++)  
    {  
        //convert "number_of_file" from int to string  
        stringstream ss;  
        ss << top_count;  
        ss >> No_top;  

        //name the file  
        if(0 < top_count && top_count < 10)  
            file_name="top_0000" + No_top + "(copy).pgm";  
        else if (9 < top_count && top_count < 100)  
            file_name="top_000" + No_top + "(copy).pgm";  
        else if (99< top_count && top_count < 1000)  
            file_name="top_00" + No_top + "(copy).pgm";  
        else  
            file_name="top_0" + No_top + "(copy).pgm";  

        file_name="/Users/moxiaohe/Desktop/three_views_models/top_view/" + file_name;  

        std::remove(file_name.c_str()); // delete file  
    }  
}  

void Models_operation::delete_front_models()  
{  
    // delete models in front views  
    for (int front_count=model_x[0];front_count<model_x[1]+1;front_count++)  
    {  
        //convert "number_of_file" from int to string  
        stringstream ss;  
        ss << front_count;  
        ss >> No_front;  

        //name the file  
        if(0 < front_count && front_count < 10)  
            file_name="front_0000" + No_front + "(copy).pgm";  
        else if (9 < front_count && front_count < 100)  
            file_name="front_000" + No_front + "(copy).pgm";  
        else if (99< front_count && front_count < 1000)  
            file_name="front_00" + No_front + "(copy).pgm";  
        else  
            file_name="front_0" + No_front + "(copy).pgm";  

        ofstream outfile;  
        outfile.open("/Users/moxiaohe/Desktop/three_views_models/front_view/" + file_name);  

        file_name="/Users/moxiaohe/Desktop/three_views_models/front_view/" + file_name;  

        std::remove(file_name.c_str()); // delete file  
    }  
}  

void Models_operation::delete_side_models()  
{  
    // delete models in side views  
    for (int side_count=model_y[0];side_count<model_y[1]+1;side_count++)  
    {  
        //convert "number_of_file" from int to string  
        stringstream ss;  
        ss << side_count;  
        ss >> No_side;  

        //name the file  
        if(0 < side_count && side_count < 10)  
            file_name="side_0000" + No_side + "(copy).pgm";  
        else if (9 < side_count && side_count < 100)  
            file_name="side_000" + No_side + "(copy).pgm";  
        else if (99< side_count && side_count < 1000)  
            file_name="side_00" + No_side + "(copy).pgm";  
        else  
            file_name="side_0" + No_side + "(copy).pgm";  

        file_name="/Users/moxiaohe/Desktop/three_views_models/side_view/" + file_name;  

        std::remove(file_name.c_str()); // delete file  
    }  
} 
