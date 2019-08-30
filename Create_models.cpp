//  
//  Create_models.cpp  
//  practice2  
//  
//  Created by Moxiao He on 09/03/2018.  
//  Copyright © 2018 Moxiao He. All rights reserved.  
//  
  
#include "Create_models.hpp"  
  
#define Width 265  
#define Height 490  
#define NooFiles 286  
  
using namespace std;  
  
void Create_models::Create_LT_models(char size,int origin_x,int origin_y,int origin_z)  
{  
    vector <int> next_ori_x(100,origin_x);  
    vector <int> next_ori_y(100,origin_y);  
    vector <int> next_ori_z(100,origin_z);  
    int dist;  
  
    // specify the radius of stroke  
    if(size=='L')  
        r=20;  
    else if(size=='M')  
        r=15;  
    else  
        r=10;  
  
    //generarte random number  
    std::random_device rd; //used to obtain a seed for the random number engine  
    std::mt19937 gen(rd()); //Standard 'mersenne_twister_engine' seeded with rd()  
    std::uniform_int_distribution<> rand_Ori_X(boundary_x[0], boundary_x[1]); //generate a random integer  
    std::uniform_int_distribution<> rand_Ori_Y(boundary_y[0], boundary_y[1]);  
    std::uniform_int_distribution<> rand_Ori_Z(boundary_z[0], boundary_z[1]);  
    std::uniform_int_distribution<> next_Ori_X(origin_x-r, origin_x+r); //generate a random integer  
    std::uniform_int_distribution<> next_Ori_Y(origin_y-r, origin_y+r);  
    std::uniform_int_distribution<> next_Ori_Z(origin_z, origin_z+2);  
    std::uniform_int_distribution<> rand_distance(3, 6);  
  
    cout<<next_ori_x[0]<<endl;  
    cout<<next_ori_y[0]<<endl;  
    cout<<next_ori_z[0]<<endl;  
    cout<<endl;  
    int n=0;  
    while( pow((next_ori_x[n]-origin_x),2)+pow((next_ori_y[n]-origin_y),2)+pow((next_ori_z[n]-origin_z),2)<=pow(r,2))  
    {  
         n++;  
        dist=rand_distance(gen);  
  
        if(origin_x<121 && origin_y<250)  
        {  
            do  
            {  
                next_ori_x[n]=rand_Ori_X(gen);  
                next_ori_y[n]=rand_Ori_Y(gen);  
                next_ori_z[n]=rand_Ori_Z(gen);  
            }  
            while(   pow((next_ori_x[n]-next_ori_x[n-1]),2)+pow((next_ori_y[n]-next_ori_y[n-1]),2)+pow((next_ori_z[n]-next_ori_z[n-1]),2) != pow(dist,2) || next_ori_x[n]<next_ori_x[n-1] || next_ori_y[n]<next_ori_y[n-1] );  
  
        }  
        else if(origin_x<121 && origin_y>250)  
        {  
            do  
            {  
                next_ori_x[n]=rand_Ori_X(gen);  
                next_ori_y[n]=rand_Ori_Y(gen);  
                next_ori_z[n]=rand_Ori_Z(gen);  
            }  
            while(   pow((next_ori_x[n]-next_ori_x[n-1]),2)+pow((next_ori_y[n]-next_ori_y[n-1]),2)+pow((next_ori_z[n]-next_ori_z[n-1]),2) != pow(dist,2) || next_ori_x[n]<next_ori_x[n-1] || next_ori_y[n]>next_ori_y[n-1] );  
  
        }  
        else if(origin_x>121 && origin_y <250)  
        {  
            do  
            {  
                next_ori_x[n]=rand_Ori_X(gen);  
                next_ori_y[n]=rand_Ori_Y(gen);  
                next_ori_z[n]=rand_Ori_Z(gen);  
            }  
            while(   pow((next_ori_x[n]-next_ori_x[n-1]),2)+pow((next_ori_y[n]-next_ori_y[n-1]),2)+pow((next_ori_z[n]-next_ori_z[n-1]),2) != pow(dist,2) || next_ori_x[n]>next_ori_x[n-1] || next_ori_y[n]<next_ori_y[n-1] );  
  
        }  
        else  
        {  
            do  
            {  
                next_ori_x[n]=rand_Ori_X(gen);  
                next_ori_y[n]=rand_Ori_Y(gen);  
                next_ori_z[n]=rand_Ori_Z(gen);  
            }  
            while(   pow((next_ori_x[n]-next_ori_x[n-1]),2)+pow((next_ori_y[n]-next_ori_y[n-1]),2)+pow((next_ori_z[n]-next_ori_z[n-1]),2) != pow(dist,2) || next_ori_x[n]>next_ori_x[n-1] || next_ori_y[n]>next_ori_y[n-1] );  
  
        }  
  
        cout<<next_ori_x[n]<<endl;  
        cout<<next_ori_y[n]<<endl;  
        cout<<next_ori_z[n]<<endl;  
        cout<<endl;  
  
        int d;  
        d=sqrt(pow(next_ori_x[n-1]-next_ori_x[n],2)+pow(next_ori_y[n-1]-next_ori_y[n],2)+pow(next_ori_z[n-1]-next_ori_z[n],2));  
  
        for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
            for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
                for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
                    {  
                        for(int t=0;t<d+1;t++)  
                        {  
                            if(d!=0 && i==next_ori_x[n-1] +t*(next_ori_x[n]-next_ori_x[n-1])/d && j==next_ori_y[n-1] +t*(next_ori_y[n]-next_ori_y[n-1])/d && k==next_ori_z[n-1] +t*(next_ori_z[n]-next_ori_z[n-1])/d && ( model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4 || model_array[i][j][k]==6 || model_array[i][j][k]==9 || model_array[i][j][k]==10 || model_array[i][j][k]==11 || model_array[i][j][k]==12 || model_array[i][j][k]==14) )  
                            {  
                                model_array[i][j][k]=76;  
  
                                if(k<model_z[0])  
                                    model_z[0]=k;  
  
                                if(k>model_z[1])  
                                    model_z[1]=k;  
  
                                if(i<model_x[0])  
                                    model_x[0]=i;  
  
                                if(i>model_x[1])  
                                    model_x[1]=i;  
  
                                if(j<model_y[0])  
                                    model_y[0]=j;  
  
                                if(j>model_y[1])  
                                    model_y[1]=j;  
                            }  
  
                            if(pow((i-(next_ori_x[n-1]+t*(next_ori_x[n]-next_ori_x[n-1])/d ) ),2)+pow((j-(next_ori_y[n-1]+t*(next_ori_y[n]-next_ori_y[n-1])/d ) ),2)+pow((k-(next_ori_z[n-1]+t*(next_ori_z[n]-next_ori_z[n-1])/d ) ),2)<=pow(4,2)&& ( model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4 || model_array[i][j][k]==6 || model_array[i][j][k]==9 || model_array[i][j][k]==10 || model_array[i][j][k]==11 || model_array[i][j][k]==12 || model_array[i][j][k]==14) )  
                            {  
                                model_array[i][j][k]=76;  
  
                                if(k<model_z[0])  
                                    model_z[0]=k;  
  
                                if(k>model_z[1])  
                                    model_z[1]=k;  
  
                                if(i<model_x[0])  
                                    model_x[0]=i;  
  
                                if(i>model_x[1])  
                                    model_x[1]=i;  
  
                                if(j<model_y[0])  
                                    model_y[0]=j;  
  
                                if(j>model_y[1])  
                                    model_y[1]=j;  
                            }  
                    }  
  
                }  
    }  
  
  
  
    for(int c=0; c < 5; c++ )  
    {  
        do  
        {  
            direvative_ori_x[c]=rand_Ori_X(gen);  
            direvative_ori_y[c]=rand_Ori_Y(gen);  
            direvative_ori_z[c]=rand_Ori_Z(gen);  
        }  
        while(pow((direvative_ori_x[c]-origin_x),2)+pow((direvative_ori_y[c]-origin_y),2)+pow((direvative_ori_z[c]-origin_z),2)>pow(r,2));  
    }  
  
    for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
    {  
        for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
            for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
            {  
                if( (pow((i-origin_x),2)+pow((j-origin_y),2)+pow((k-origin_z),2)<=pow(r,2)) && ( model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4 || model_array[i][j][k]==6 || model_array[i][j][k]==9 || model_array[i][j][k]==10 || model_array[i][j][k]==11 || model_array[i][j][k]==12 || model_array[i][j][k]==14) )  
                {  
                    model_array[i][j][k]=66;  
  
                    if(k<model_z[0])  
                        model_z[0]=k;  
  
                    if(k>model_z[1])  
                       model_z[1]=k;  
  
                    if(i<model_x[0])  
                        model_x[0]=i;  
  
                    if(i>model_x[1])  
                        model_x[1]=i;  
  
                    if(j<model_y[0])  
                        model_y[0]=j;  
  
                    if(j>model_y[1])  
                        model_y[1]=j;  
                }  
  
                for(int c=0; c < 5; c++)  
                {  
                    if( (pow((i-direvative_ori_x[c]),2)+pow((j-direvative_ori_y[c]),2)+pow((k-direvative_ori_z[c]),2)<=0.5*pow(r,2)) && ( model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4 || model_array[i][j][k]==6 || model_array[i][j][k]==9 || model_array[i][j][k]==10 || model_array[i][j][k]==11 || model_array[i][j][k]==12 || model_array[i][j][k]==14) )  
                    {  
                        model_array[i][j][k]=66;  
  
                        if(k<model_z[0])  
                            model_z[0]=k;  
  
                        if(k>model_z[1])  
                            model_z[1]=k;  
  
                        if(i<model_x[0])  
                            model_x[0]=i;  
  
                        if(i>model_x[1])  
                            model_x[1]=i;  
  
                        if(j<model_y[0])  
                            model_y[0]=j;  
  
                        if(j>model_y[1])  
                            model_y[1]=j;  
                    }  
                }  
            }  
    }  
  
    for(int c=0;c<5;c++)  
    {  
        n=0;  
        for(int a =0; a<100;a++)  
        {  
            next_ori_x[a]=direvative_ori_x[c];  
            next_ori_y[a]=direvative_ori_y[c];  
            next_ori_z[a]=direvative_ori_z[c];  
        }  
        while( pow((next_ori_x[n]-direvative_ori_x[c]),2)+pow((next_ori_y[n]-direvative_ori_y[c]),2)+pow((next_ori_z[n]-direvative_ori_z[c]),2)<=0.5*pow(r,2))  
        {  
             n++;  
            dist=rand_distance(gen);  
  
            if(origin_x<121 && origin_y<250)  
            {  
                do  
                {  
                    next_ori_x[n]=rand_Ori_X(gen);  
                    next_ori_y[n]=rand_Ori_Y(gen);  
                    next_ori_z[n]=rand_Ori_Z(gen);  
                }  
                while(   pow((next_ori_x[n]-next_ori_x[n-1]),2)+pow((next_ori_y[n]-next_ori_y[n-1]),2)+pow((next_ori_z[n]-next_ori_z[n-1]),2) != pow(dist,2) || next_ori_x[n]<next_ori_x[n-1] || next_ori_y[n]<next_ori_y[n-1] );  
  
            }  
            else if(origin_x<121 && origin_y>250)  
            {  
                do  
                {  
                    next_ori_x[n]=rand_Ori_X(gen);  
                    next_ori_y[n]=rand_Ori_Y(gen);  
                    next_ori_z[n]=rand_Ori_Z(gen);  
                }  
                while(   pow((next_ori_x[n]-next_ori_x[n-1]),2)+pow((next_ori_y[n]-next_ori_y[n-1]),2)+pow((next_ori_z[n]-next_ori_z[n-1]),2) != pow(dist,2) || next_ori_x[n]<next_ori_x[n-1] || next_ori_y[n]>next_ori_y[n-1] );  
  
            }  
            else if(origin_x>121 && origin_y <250)  
            {  
                do  
                {  
                    next_ori_x[n]=rand_Ori_X(gen);  
                    next_ori_y[n]=rand_Ori_Y(gen);  
                    next_ori_z[n]=rand_Ori_Z(gen);  
                }  
                while(   pow((next_ori_x[n]-next_ori_x[n-1]),2)+pow((next_ori_y[n]-next_ori_y[n-1]),2)+pow((next_ori_z[n]-next_ori_z[n-1]),2) != pow(dist,2) || next_ori_x[n]>next_ori_x[n-1] || next_ori_y[n]<next_ori_y[n-1] );  
  
            }  
            else  
            {  
                do  
                {  
                    next_ori_x[n]=rand_Ori_X(gen);  
                    next_ori_y[n]=rand_Ori_Y(gen);  
                    next_ori_z[n]=rand_Ori_Z(gen);  
                }  
                while(   pow((next_ori_x[n]-next_ori_x[n-1]),2)+pow((next_ori_y[n]-next_ori_y[n-1]),2)+pow((next_ori_z[n]-next_ori_z[n-1]),2) != pow(dist,2) || next_ori_x[n]>next_ori_x[n-1] || next_ori_y[n]>next_ori_y[n-1] );  
  
            }  
  
            cout<<next_ori_x[n]<<endl;  
            cout<<next_ori_y[n]<<endl;  
            cout<<next_ori_z[n]<<endl;  
            cout<<endl;  
  
            int d;  
            d=sqrt(pow(next_ori_x[n-1]-next_ori_x[n],2)+pow(next_ori_y[n-1]-next_ori_y[n],2)+pow(next_ori_z[n-1]-next_ori_z[n],2));  
  
            for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
                for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
                    for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
                        {  
                            for(int t=0;t<d+1;t++)  
                            {  
                                if(d!=0 && i==next_ori_x[n-1] +t*(next_ori_x[n]-next_ori_x[n-1])/d && j==next_ori_y[n-1] +t*(next_ori_y[n]-next_ori_y[n-1])/d && k==next_ori_z[n-1] +t*(next_ori_z[n]-next_ori_z[n-1])/d && ( model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4 || model_array[i][j][k]==6 || model_array[i][j][k]==9 || model_array[i][j][k]==10 || model_array[i][j][k]==11 || model_array[i][j][k]==12 || model_array[i][j][k]==14) )  
                                {  
                                    model_array[i][j][k]=76;  
  
                                    if(k<model_z[0])  
                                        model_z[0]=k;  
  
                                    if(k>model_z[1])  
                                        model_z[1]=k;  
  
                                    if(i<model_x[0])  
                                        model_x[0]=i;  
  
                                    if(i>model_x[1])  
                                        model_x[1]=i;  
  
                                    if(j<model_y[0])  
                                        model_y[0]=j;  
  
                                    if(j>model_y[1])  
                                        model_y[1]=j;  
                                }  
  
                                if(pow((i-(next_ori_x[n-1]+t*(next_ori_x[n]-next_ori_x[n-1])/d ) ),2)+pow((j-(next_ori_y[n-1]+t*(next_ori_y[n]-next_ori_y[n-1])/d ) ),2)+pow((k-(next_ori_z[n-1]+t*(next_ori_z[n]-next_ori_z[n-1])/d ) ),2)<=pow(4,2)&& ( model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4 || model_array[i][j][k]==6 || model_array[i][j][k]==9 || model_array[i][j][k]==10 || model_array[i][j][k]==11 || model_array[i][j][k]==12 || model_array[i][j][k]==14) )  
                                {  
                                    model_array[i][j][k]=76;  
  
                                    if(k<model_z[0])  
                                        model_z[0]=k;  
  
                                    if(k>model_z[1])  
                                        model_z[1]=k;  
  
                                    if(i<model_x[0])  
                                        model_x[0]=i;  
  
                                    if(i>model_x[1])  
                                        model_x[1]=i;  
  
                                    if(j<model_y[0])  
                                        model_y[0]=j;  
  
                                    if(j>model_y[1])  
                                        model_y[1]=j;  
                                }  
                        }  
  
                    }  
        }  
    }  
  
  
  
    cout<<"The boudary of the stroke on X axis is from "<<model_x[0]<<" to "<<model_x[1]<<endl;  
    cout<<"The boudary of the stroke on Y axis is from "<<model_y[0]<<" to "<<model_y[1]<<endl;  
    cout<<"The boudary of the stroke on Z axis is from "<<model_z[0]<<" to "<<model_z[1]<<endl;  
    cout<<endl;  
  
}  
  
  
void Create_models::Create_LS_models(int a, int b, int c, int origin_x, int origin_y, int origin_z)  
{  
    for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
        for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
            for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
                    if( (pow((i-origin_x),2)/pow(a,2)+pow((j-origin_y),2)/pow(b,2)+pow((k-origin_z),2)/pow(c,2)<=1) && ( model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4 || model_array[i][j][k]==6 || model_array[i][j][k]==9 || model_array[i][j][k]==10 || model_array[i][j][k]==11 || model_array[i][j][k]==12 || model_array[i][j][k]==14) )  
                    {  
                        model_array[i][j][k]=46;  
  
                        if(k<model_z[0])  
                            model_z[0]=k;  
  
                        if(k>model_z[1])  
                            model_z[1]=k;  
  
                        if(i<model_x[0])  
                            model_x[0]=i;  
  
                        if(i>model_x[1])  
                            model_x[1]=i;  
  
                        if(j<model_y[0])  
                            model_y[0]=j;  
  
                        if(j>model_y[1])  
                            model_y[1]=j;  
                    }  
  
    cout<<"The boudary of the stroke on X axis is from "<<model_x[0]<<" to "<<model_x[1]<<endl;  
    cout<<"The boudary of the stroke on Y axis is from "<<model_y[0]<<" to "<<model_y[1]<<endl;  
    cout<<"The boudary of the stroke on Z axis is from "<<model_z[0]<<" to "<<model_z[1]<<endl;  
    cout<<endl;  
}  
  
  
void Create_models::Create_IH_models(char size, int origin_x, int origin_y, int origin_z)  
{  
  
    //generarte random number  
    std::random_device rd; //used to obtain a seed for the random number engine  
    std::mt19937 gen(rd()); //Standard 'mersenne_twister_engine' seeded with rd(  
    std::uniform_int_distribution<> rand_Ori_X(boundary_x[0], boundary_x[1]); //generate a random integer  
    std::uniform_int_distribution<> rand_Ori_Y(boundary_y[0], boundary_y[1]);  
    std::uniform_int_distribution<> rand_Ori_Z(boundary_z[0], boundary_z[1]);  
      
    //insert model  
      
      
    // specify the radius of stroke  
    if(size=='L')  
        r=15;  
    else if(size=='M')  
        r=10;  
    else  
        r=5;  
      
  
    for(int c=0; c < 5; c++ )  
    {  
        do  
        {  
            direvative_ori_x[c]=rand_Ori_X(gen);  
            direvative_ori_y[c]=rand_Ori_Y(gen);  
            direvative_ori_z[c]=rand_Ori_Z(gen);  
        }  
        while(pow((direvative_ori_x[c]-origin_x),2)+pow((direvative_ori_y[c]-origin_y),2)+pow((direvative_ori_z[c]-origin_z),2)>pow(r,2));  
    }  
      
    for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
    {  
        for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
            for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
            {  
                if( (pow((i-origin_x),2)+pow((j-origin_y),2)+pow((k-origin_z),2)<=pow(r,2)) && ( model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4 || model_array[i][j][k]==6 || model_array[i][j][k]==9 || model_array[i][j][k]==10 || model_array[i][j][k]==11 || model_array[i][j][k]==12 || model_array[i][j][k]==14) )  
                {  
                    model_array[i][j][k]=66;  
                      
                    if(k<model_z[0])  
                        model_z[0]=k;  
                      
                    if(k>model_z[1])  
                       model_z[1]=k;  
                      
                    if(i<model_x[0])  
                        model_x[0]=i;  
                      
                    if(i>model_x[1])  
                        model_x[1]=i;  
                      
                    if(j<model_y[0])  
                        model_y[0]=j;  
                      
                    if(j>model_y[1])  
                        model_y[1]=j;  
                }  
                  
                for(int c=0; c < 5; c++)  
                {  
                    if( (pow((i-direvative_ori_x[c]),2)+pow((j-direvative_ori_y[c]),2)+pow((k-direvative_ori_z[c]),2)<=0.5*pow(r,2)) && ( model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4 || model_array[i][j][k]==6 || model_array[i][j][k]==9 || model_array[i][j][k]==10 || model_array[i][j][k]==11 || model_array[i][j][k]==12 || model_array[i][j][k]==14) )  
                    {  
                        model_array[i][j][k]=66;  
                          
                        if(k<model_z[0])  
                            model_z[0]=k;  
                          
                        if(k>model_z[1])  
                            model_z[1]=k;  
                          
                        if(i<model_x[0])  
                            model_x[0]=i;  
                          
                        if(i>model_x[1])  
                            model_x[1]=i;  
                          
                        if(j<model_y[0])  
                            model_y[0]=j;  
                          
                        if(j>model_y[1])  
                            model_y[1]=j;  
                    }  
                }  
            }  
    }  
      
    cout<<"The boudary of the stroke on X axis is from "<<model_x[0]<<" to "<<model_x[1]<<endl;  
    cout<<"The boudary of the stroke on Y axis is from "<<model_y[0]<<" to "<<model_y[1]<<endl;  
    cout<<"The boudary of the stroke on Z axis is from "<<model_z[0]<<" to "<<model_z[1]<<endl;  
    cout<<endl;  
      
      
}  
  
  
void Create_models::Create_SH_models(char size,int origin_x,int origin_y,int origin_z)  
{      
    vector <int> next_ori_x(100,origin_x);  
    vector <int> next_ori_y(100,origin_y);  
    vector <int> next_ori_z(100,origin_z);  
    int dist;  
  
    // specify the radius of stroke  
    if(size=='L')  
        r=60;  
    else if(size=='M')  
        r=45;  
    else  
        r=30;  
  
    //generarte random number  
    std::random_device rd; //used to obtain a seed for the random number engine  
    std::mt19937 gen(rd()); //Standard 'mersenne_twister_engine' seeded with rd()  
    std::uniform_int_distribution<> rand_Ori_X(origin_x-r, origin_x+r); //generate a random integer  
    std::uniform_int_distribution<> rand_Ori_Y(origin_y-r, origin_y+r);  
    std::uniform_int_distribution<> rand_Ori_Z(origin_z, origin_z+2);  
    std::uniform_int_distribution<> rand_distance(3, 6);  
  
    cout<<next_ori_x[0]<<endl;  
    cout<<next_ori_y[0]<<endl;  
    cout<<next_ori_z[0]<<endl;  
    cout<<endl;  
    int n=0;  
    while( pow((next_ori_x[n]-origin_x),2)+pow((next_ori_y[n]-origin_y),2)+pow((next_ori_z[n]-origin_z),2)<=pow(r,2))  
    {  
         n++;  
        dist=rand_distance(gen);  
  
        if(origin_x<121 && origin_y<250)  
        {  
            do  
            {  
                next_ori_x[n]=rand_Ori_X(gen);  
                next_ori_y[n]=rand_Ori_Y(gen);  
                next_ori_z[n]=rand_Ori_Z(gen);  
            }  
            while(   pow((next_ori_x[n]-next_ori_x[n-1]),2)+pow((next_ori_y[n]-next_ori_y[n-1]),2)+pow((next_ori_z[n]-next_ori_z[n-1]),2) != pow(dist,2) || next_ori_x[n]<next_ori_x[n-1] || next_ori_y[n]<next_ori_y[n-1] );  
  
        }  
        else if(origin_x<121 && origin_y>250)  
        {  
            do  
            {  
                next_ori_x[n]=rand_Ori_X(gen);  
                next_ori_y[n]=rand_Ori_Y(gen);  
                next_ori_z[n]=rand_Ori_Z(gen);  
            }  
            while(   pow((next_ori_x[n]-next_ori_x[n-1]),2)+pow((next_ori_y[n]-next_ori_y[n-1]),2)+pow((next_ori_z[n]-next_ori_z[n-1]),2) != pow(dist,2) || next_ori_x[n]<next_ori_x[n-1] || next_ori_y[n]>next_ori_y[n-1] );  
  
        }  
        else if(origin_x>121 && origin_y <250)  
        {  
            do  
            {  
                next_ori_x[n]=rand_Ori_X(gen);  
                next_ori_y[n]=rand_Ori_Y(gen);  
                next_ori_z[n]=rand_Ori_Z(gen);  
            }  
            while(   pow((next_ori_x[n]-next_ori_x[n-1]),2)+pow((next_ori_y[n]-next_ori_y[n-1]),2)+pow((next_ori_z[n]-next_ori_z[n-1]),2) != pow(dist,2) || next_ori_x[n]>next_ori_x[n-1] || next_ori_y[n]<next_ori_y[n-1] );  
  
        }  
        else  
        {  
            do  
            {  
                next_ori_x[n]=rand_Ori_X(gen);  
                next_ori_y[n]=rand_Ori_Y(gen);  
                next_ori_z[n]=rand_Ori_Z(gen);  
            }  
            while(   pow((next_ori_x[n]-next_ori_x[n-1]),2)+pow((next_ori_y[n]-next_ori_y[n-1]),2)+pow((next_ori_z[n]-next_ori_z[n-1]),2) != pow(dist,2) || next_ori_x[n]>next_ori_x[n-1] || next_ori_y[n]>next_ori_y[n-1] );  
  
        }  
  
        cout<<next_ori_x[n]<<endl;  
        cout<<next_ori_y[n]<<endl;  
        cout<<next_ori_z[n]<<endl;  
        cout<<endl;  
  
        int d;  
        d=sqrt(pow(next_ori_x[n-1]-next_ori_x[n],2)+pow(next_ori_y[n-1]-next_ori_y[n],2)+pow(next_ori_z[n-1]-next_ori_z[n],2));  
  
        for(int k=boundary_z[0]; k < boundary_z[1]+1; k++)  
            for(int j=boundary_y[0]; j < boundary_y[1]+1; j++)  
                for(int i=boundary_x[0]; i < boundary_x[1]+1; i++)  
                    {  
                        for(int t=0;t<d+1;t++)  
                        {  
                            if(d!=0 && i==next_ori_x[n-1] +t*(next_ori_x[n]-next_ori_x[n-1])/d && j==next_ori_y[n-1] +t*(next_ori_y[n]-next_ori_y[n-1])/d && k==next_ori_z[n-1] +t*(next_ori_z[n]-next_ori_z[n-1])/d && ( model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4 || model_array[i][j][k]==6 || model_array[i][j][k]==9 || model_array[i][j][k]==10 || model_array[i][j][k]==11 || model_array[i][j][k]==12 || model_array[i][j][k]==14) )  
                            {  
                                model_array[i][j][k]=66;  
  
                                if(k<model_z[0])  
                                    model_z[0]=k;  
  
                                if(k>model_z[1])  
                                    model_z[1]=k;  
  
                                if(i<model_x[0])  
                                    model_x[0]=i;  
  
                                if(i>model_x[1])  
                                    model_x[1]=i;  
  
                                if(j<model_y[0])  
                                    model_y[0]=j;  
  
                                if(j>model_y[1])  
                                    model_y[1]=j;  
                            }  
  
                            if(pow((i-(next_ori_x[n-1]+t*(next_ori_x[n]-next_ori_x[n-1])/d ) ),2)+pow((j-(next_ori_y[n-1]+t*(next_ori_y[n]-next_ori_y[n-1])/d ) ),2)+pow((k-(next_ori_z[n-1]+t*(next_ori_z[n]-next_ori_z[n-1])/d ) ),2)<=pow(2,2)&& ( model_array[i][j][k]==1 || model_array[i][j][k]==2 || model_array[i][j][k]==3 || model_array[i][j][k]==4 || model_array[i][j][k]==6 || model_array[i][j][k]==9 || model_array[i][j][k]==10 || model_array[i][j][k]==11 || model_array[i][j][k]==12 || model_array[i][j][k]==14) )  
                            {  
                                model_array[i][j][k]=66;  
  
                                if(k<model_z[0])  
                                    model_z[0]=k;  
  
                                if(k>model_z[1])  
                                    model_z[1]=k;  
  
                                if(i<model_x[0])  
                                    model_x[0]=i;  
  
                                if(i>model_x[1])  
                                    model_x[1]=i;  
  
                                if(j<model_y[0])  
                                    model_y[0]=j;  
  
                                if(j>model_y[1])  
                                    model_y[1]=j;  
                            }  
                    }  
  
                }  
    }  
    cout<<"The boudary of the stroke on X axis is from "<<model_x[0]<<" to "<<model_x[1]<<endl;  
    cout<<"The boudary of the stroke on Y axis is from "<<model_y[0]<<" to "<<model_y[1]<<endl;  
    cout<<"The boudary of the stroke on Z axis is from "<<model_z[0]<<" to "<<model_z[1]<<endl;  
    cout<<endl;  
  
  
} 

