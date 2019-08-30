//  
//  Set_boundaries.hpp  
//  practice2  
//  
//  Created by Moxiao He on 02/03/2018.  
//  Copyright © 2018 Moxiao He. All rights reserved.  
//  
  
#ifndef Set_boundaries_hpp  
#define Set_boundaries_hpp  
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

class Set_boundaries
{
    public:
        Set_boundaries(Input_PGM_files& theinput)
            : image_array (theinput.image_array),boundary_x (2), boundary_y (2), boundary_z (2)
        {}
        void boundary_X();
        void boundary_Y();
        void boundary_Z();
        void display_boundaries();
        vector <int> boundary_x, boundary_y, boundary_z;
    private:
        int count=0,count_Front=265,count_Back=0,count_Left=490,count_Right=0,count_Top=286;

        vector <vector <vector <int > > >& image_array;
};

#endif /* Set_boundaries_hpp */
