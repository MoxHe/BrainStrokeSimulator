//
// Input_PGM_files.hpp
// practice2
//
// Created by Moxiao He on 08/02/2018.
// Copyright © 2018 Moxiao He. All rights reserved.
//

#ifndef Input_PGM_files_hpp
#define Input_PGM_files_hpp
#include <string>
#include <vector>

#define Width 265
#define Height 490
#define NooFiles 286

using namespace std;

class Input_PGM_files
{
    public:
        Input_PGM_files()
            : image_array (Width, vector < vector < int > > (Height,vector<int> (NooFiles)))
        {}
        void Input();
        vector <vector <vector <int > > > image_array;
    private:
        int count_files;
        string No_files;
        string file_name;
        string line;
};
#endif /* Input_PGM_files_hpp */
