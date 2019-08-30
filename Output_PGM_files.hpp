//  
//  Output_PGM_files.hpp  
//  practice2  
//  
//  Created by Moxiao He on 01/03/2018.  
//  Copyright © 2018 Moxiao He. All rights reserved.  
//  

#ifndef Output_PGM_files_hpp  
#define Output_PGM_files_hpp  
#include "Input_PGM_files.hpp"  
#include <string>  

using namespace std;  

class Output_PGM_files  
{  
    public:  
        char Check_files();  
        void Output_top_views(Input_PGM_files& theinput);  
        void Output_front_views(Input_PGM_files& theinput);  
        void Output_side_views(Input_PGM_files& theinput);  
    private:  
        string No_top, No_front, No_side;  
        string file_name;  
        string line;  
};  

#endif /* Output_PGM_files_hpp */  

