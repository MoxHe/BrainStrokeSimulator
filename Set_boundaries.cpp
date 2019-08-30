//  
//  Set_boundaries.cpp  
//  practice2  
//  
//  Created by Moxiao He on 02/03/2018.  
//  Copyright © 2018 Moxiao He. All rights reserved.  
//  

#include "Set_boundaries.hpp"  

void Set_boundaries:: boundary_Z()  
{  
    //find the boundary on Z_axis for inserting stroke models  
    for(int j=0; j<Height; j++)  
    {  
        for(int i=0;i<Width;i++)  
        {  
            for(int k=0; k<NooFiles-1; k++)  
            {  
                count++;  
                if(image_array[i][j][k]==0 && image_array[i][j][k+1]==51)    // find the position that last pixel represents air and the next one represents skin  
                    if(count<count_Top)    // find the lowest position for top boundary on  Z axis  
                    {  
                        count_Top=count;  
                        boundary_z[0]=k;  
                    }  

                if(image_array[i][j][k]==13)    //set the tongue as the bottom boundary on Z axis  
                    boundary_z[1]=k;  
            }  
            count=0;  
        }  
    }  
}  

void Set_boundaries:: boundary_X()  
{  
    //find the boudary on X_axis for inserting stroke models  
    for(int k=boundary_z[0]; k<boundary_z[1]; k++)  
    {  
        for(int j=0;j<Height;j++)  
        {  
            for(int i=0;i<Width-1;i++)  
            {  
                count++;  
                if(image_array[i][j][k]==0 && image_array[i+1][j][k]==51)    // find the position that last pixel represents air and the next one represents skin  
                    if(count<count_Front)    // find the most back position for front boundary on X axis  
                    {  
                        count_Front=count;  
                        boundary_x[0]=i;  
                    }  

                if(image_array[i][j][k]==51 && image_array[i+1][j][k]==0)    // find the position that last pixel represents skin and the next one represents air  
                    if(count>count_Back)    // find the most front position for back boundary on X axis  
                    {  
                        count_Back=count;  
                        boundary_x[1]=i;  
                    }  
            }  
            count=0;  
        }  
    }  
}  

void Set_boundaries:: boundary_Y()  
{  
    //find boundary on Y_axis  
    for(int k=boundary_z[0]; k<boundary_z[1]; k++)  
    {  
        for(int i=0;i<Width;i++)  
        {  
            for(int j=0;j<Height-1;j++)  
            {  
                count++;  
                if(image_array[i][j][k]==0 && image_array[i][j+1][k]==51)  
                    if(count<count_Left)  
                    {  
                        count_Left=count;  
                        boundary_y[0]=j;  
                    }  

                if(image_array[i][j][k]==51 && image_array[i][j+1][k]==0)  
                    if(count>count_Right)  
                    {  
                        count_Right=count;  
                        boundary_y[1]=j;  
                    }  
            }  
            count=0;  
        }  
    }  
}  

void Set_boundaries::display_boundaries()  
{  
    cout<<"The boudary on X axis for inserting stroke is from "<<boundary_x[0]<<" to "<<boundary_x[1]<<endl;  
    cout<<"The boudary on Y axis for inserting stroke is from "<<boundary_y[0]<<" to "<<boundary_y[1]<<endl;  
    cout<<"The boudary on Z axis for inserting stroke is from "<<boundary_z[0]<<" to "<<boundary_z[1]<<endl;  
    cout<<endl;  
}  

