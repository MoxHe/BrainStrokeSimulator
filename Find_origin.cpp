//  
//  Find_origin.cpp  
//  practice2  
//  
//  Created by Moxiao He on 18/03/2018.  
//  Copyright © 2018 Moxiao He. All rights reserved.  
//  

#include "Find_origin.hpp"  
using namespace std;  
void Find_origin::find_origin_LT(int input_origin_x,int input_origin_y,int input_origin_z)  
{  
    if(model_array[input_origin_x][input_origin_y][input_origin_z]==1 || model_array[input_origin_x][input_origin_y][input_origin_z]==2 || model_array[input_origin_x][input_origin_y][input_origin_z]==3 || model_array[input_origin_x][input_origin_y][input_origin_z]==4 || model_array[input_origin_x][input_origin_y][input_origin_z]==6 || model_array[input_origin_x][input_origin_y][input_origin_z]==9 || model_array[input_origin_x][input_origin_y][input_origin_z]==10 || model_array[input_origin_x][input_origin_y][input_origin_z]==11 || model_array[input_origin_x][input_origin_y][input_origin_z]==12 || model_array[input_origin_x][input_origin_y][input_origin_z]==14)  
    {  

        origin_available=1;  
        output_origin_x=input_origin_x;  
        output_origin_y=input_origin_y;  
        output_origin_z=input_origin_z;  

        cout<<"The origin of the sroke is: X ="<<" "<<output_origin_x<<", "<<"Y = "<<output_origin_y<<", "<<"Z = "<<output_origin_z<<endl;  
        cout<<endl;  
    }  

    else    // search the nearest point that contains pixel value of 1,2,3 or 4  
    {  
        origin_available=0;  

        for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
            for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
                for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
                {  
                    if(model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4 || model_array[i][j][k]==6 || model_array[i][j][k]==9 || model_array[i][j][k]==10 || model_array[i][j][k]==11 || model_array[i][j][k]==12 || model_array[i][j][k]==14)  
                    {  
                        P_ori_X=i;  
                        P_ori_Y=j;  
                        P_ori_Z=k;  
                        output_origin_x=i;  
                        output_origin_y=j;  
                        output_origin_z=k;  
                        break;break;break;  
                    }  
                }  
        for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
            for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
                for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
                {  
                    if(model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4 || model_array[i][j][k]==6 || model_array[i][j][k]==9 || model_array[i][j][k]==10 || model_array[i][j][k]==11 || model_array[i][j][k]==12 || model_array[i][j][k]==14)  
                    {  
                        P_ori_X=i;  
                        P_ori_Y=j;  
                        P_ori_Z=k;  
                    }  
                    if( pow((input_origin_x-P_ori_X),2)+pow((input_origin_y-P_ori_Y),2)+pow((input_origin_z-P_ori_Z),2) < pow((input_origin_x-output_origin_x),2)+pow((input_origin_y-output_origin_y),2)+pow((input_origin_z-output_origin_z),2))  
                    {  
                        output_origin_x=P_ori_X;  
                        output_origin_y=P_ori_Y;  
                        output_origin_z=P_ori_Z;  
                    }  
                }  

        cout<<"The nearest origin of the sroke available is: X ="<<" "<<output_origin_x<<", "<<"Y = "<<output_origin_y<<", "<<"Z = "<<output_origin_z<<endl;  
        cout<<endl;  
    }  
}  
void Find_origin::find_origin_LS(int input_origin_x,int input_origin_y,int input_origin_z)  
{  
    if(model_array[input_origin_x][input_origin_y][input_origin_z]==2 || model_array[input_origin_x][input_origin_y][input_origin_z]==4)  
    {  

        origin_available=1;  
        output_origin_x=input_origin_x;  
        output_origin_y=input_origin_y;  
        output_origin_z=input_origin_z;  

        cout<<"The origin of the sroke is: X ="<<" "<<output_origin_x<<", "<<"Y = "<<output_origin_y<<", "<<"Z = "<<output_origin_z<<endl;  
        cout<<endl;  
    }  

    else    // search the nearest point that contains pixel value of 2 or 4  
    {  
        origin_available=0;  

        for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
            for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
                for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
                {  
                    if( model_array[i][j][k]==2 ||  model_array[i][j][k]==4)  
                    {  
                        P_ori_X=i;  
                        P_ori_Y=j;  
                        P_ori_Z=k;  
                        output_origin_x=i;  
                        output_origin_y=j;  
                        output_origin_z=k;  
                        break;break;break;  
                    }  
                }  
        for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
            for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
                for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
                {  
                    if( model_array[i][j][k]==2 ||  model_array[i][j][k]==4)  
                    {  
                        P_ori_X=i;  
                        P_ori_Y=j;  
                        P_ori_Z=k;  
                    }  
                    if( pow((input_origin_x-P_ori_X),2)+pow((input_origin_y-P_ori_Y),2)+pow((input_origin_z-P_ori_Z),2) < pow((input_origin_x-output_origin_x),2)+pow((input_origin_y-output_origin_y),2)+pow((input_origin_z-output_origin_z),2))  
                    {  
                        output_origin_x=P_ori_X;  
                        output_origin_y=P_ori_Y;  
                        output_origin_z=P_ori_Z;  
                    }  
                }  

        cout<<"The nearest origin of the sroke available is: X ="<<" "<<output_origin_x<<", "<<"Y = "<<output_origin_y<<", "<<"Z = "<<output_origin_z<<endl;  
        cout<<endl;  
    }  
}  
void Find_origin::find_origin_IH(int input_origin_x,int input_origin_y,int input_origin_z)  
{  
    if(model_array[input_origin_x][input_origin_y][input_origin_z]==1 || model_array[input_origin_x][input_origin_y][input_origin_z]==2 || model_array[input_origin_x][input_origin_y][input_origin_z]==3 || model_array[input_origin_x][input_origin_y][input_origin_z]==4)  
    {  

        origin_available=1;  
        output_origin_x=input_origin_x;  
        output_origin_y=input_origin_y;  
        output_origin_z=input_origin_z;  

        cout<<"The origin of the sroke is: X ="<<" "<<output_origin_x<<", "<<"Y = "<<output_origin_y<<", "<<"Z = "<<output_origin_z<<endl;  
        cout<<endl;  
    }  

    else    // search the nearest point that contains pixel value of 1,2,3 or 4  
    {  
        origin_available=0;  

        for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
            for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
                for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
                {  
                    if(model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4)  
                    {  
                        P_ori_X=i;  
                        P_ori_Y=j;  
                        P_ori_Z=k;  
                        output_origin_x=i;  
                        output_origin_y=j;  
                        output_origin_z=k;  
                        break;break;break;  
                    }  
                }  
        for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
            for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
                for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
                {  
                    if(model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4)  
                    {  
                        P_ori_X=i;  
                        P_ori_Y=j;  
                        P_ori_Z=k;  
                    }  
                    if( pow((input_origin_x-P_ori_X),2)+pow((input_origin_y-P_ori_Y),2)+pow((input_origin_z-P_ori_Z),2) < pow((input_origin_x-output_origin_x),2)+pow((input_origin_y-output_origin_y),2)+pow((input_origin_z-output_origin_z),2))  
                    {  
                        output_origin_x=P_ori_X;  
                        output_origin_y=P_ori_Y;  
                        output_origin_z=P_ori_Z;  
                    }  
                }  

        cout<<"The nearest origin of the sroke available is: X ="<<" "<<output_origin_x<<", "<<"Y = "<<output_origin_y<<", "<<"Z = "<<output_origin_z<<endl;  
        cout<<endl;  
    }  
}  

void Find_origin::find_origin_SH(int input_origin_x,int input_origin_y,int input_origin_z)  
{  
    if(model_array[input_origin_x][input_origin_y][input_origin_z]==14 )  
    {  

        origin_available=1;  
        output_origin_x=input_origin_x;  
        output_origin_y=input_origin_y;  
        output_origin_z=input_origin_z;  

        cout<<"The origin of the sroke is: X ="<<" "<<output_origin_x<<", "<<"Y = "<<output_origin_y<<", "<<"Z = "<<output_origin_z<<endl;  
        cout<<endl;  
    }  

    else    // search the nearest point that contains pixel value of 1,2,3 or 4  
    {  
        origin_available=0;  

        for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
            for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
                for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
                {  
                    if(model_array[i][j][k]==14 )  
                    {  
                        P_ori_X=i;  
                        P_ori_Y=j;  
                        P_ori_Z=k;  
                        output_origin_x=i;  
                        output_origin_y=j;  
                        output_origin_z=k;  
                        break;break;break;  
                    }  
                }  
        for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
            for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
                for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
                {  
                    if(model_array[i][j][k]==14 )  
                    {  
                        P_ori_X=i;  
                        P_ori_Y=j;  
                        P_ori_Z=k;  
                    }  
                    if( pow((input_origin_x-P_ori_X),2)+pow((input_origin_y-P_ori_Y),2)+pow((input_origin_z-P_ori_Z),2) < pow((input_origin_x-output_origin_x),2)+pow((input_origin_y-output_origin_y),2)+pow((input_origin_z-output_origin_z),2))  
                    {  
                        output_origin_x=P_ori_X;  
                        output_origin_y=P_ori_Y;  
                        output_origin_z=P_ori_Z;  
                    }  
                }  

        cout<<"The nearest origin of the sroke available is: X ="<<" "<<output_origin_x<<", "<<"Y = "<<output_origin_y<<", "<<"Z = "<<output_origin_z<<endl;  
        cout<<endl;  
    }  
} 

