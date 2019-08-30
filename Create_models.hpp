// Create_models.hpp practice2
// Created by Moxiao He on 09/03/2018.
// Copyright © 2018 Moxiao He. All rights reserved.
#ifndef Create_models_hpp
#define Create_models_hpp
#include "Set_boundaries.hpp"
#include <math.h>
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

class Create_models
{
public:
Create_models(Set_boundaries& theboundaries)
:boundary_x(theboundaries.boundary_x),boundary_y(theboundaries.boundary_y), boun
dary_z(theboundaries.boundary_z)
{}
void Create_LT_models(char size,int origin_x,int origin_y,int origin_z);
void Create_LS_models(int a, int b, int c, int origin_x, int origin_y, int origi
                   n_z);
void Create_IH_models(char size, int origin_x, int origin_y, int origin_z);
void Create_SH_models(char size,int origin_x,int origin_y,int origin_z);

vector <int> model_x;
vector <int> model_y;
vector <int> model_z;
<vector <vector <int > > > model_array;

private:
vector <int>& boundary_x;
vector <int>& boundary_y;
vector <int>& boundary_z;
int r;
int direvative_ori_x[5],direvative_ori_y[5],direvative_ori_z[5];
};
#endif /* Create_models_hpp */
