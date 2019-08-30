//  
//  Build_up_models.hpp  
//  practice2  
//  
//  Created by Moxiao He on 02/03/2018.  
//  Copyright © 2018 Moxiao He. All rights reserved.  
//  

#ifndef Build_up_models_hpp  
#define Build_up_models_hpp  
#include "Create_models.hpp"  
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

class Models_operation  
{  
    public:  
        Models_operation(Create_models& themodels)
            : model_array (themodels.model_array), model_x (themodels.model_x), model_y (themodels.model_y), model_z (themodels.model_z)  
        {}  
        void insert_top_models();  
        void insert_front_models();  
        void insert_side_models();  

        void delete_top_models();  
        void delete_front_models();  
        void delete_side_models();  



    private:  
        string No_top, No_front, No_side;  
        string file_name;  
        vector <int>& model_x;  
        vector <int>& model_y;  
        vector <int>& model_z;  
        vector <vector <vector <int > > >& model_array;  
};  
#endif /* Build_up_models_hpp */  

