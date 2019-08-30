// Find_origin.hpp practice2
// Created by Moxiao He on 18/03/2018.
// Copyright © 2018 Moxiao He. All rights reserved.

using namespace std;
#include <vector>
#include <Set_boundaries.hpp>

class Find_origin
{
    public:
        Find_origin(Set_boundaries& theboundaries)
            :boundary_x(theboundaries.boundary_x),boundary_y(theboundaries.boundary_y),
            boundary_z(theboundaries.boundary_z)
    {}
        void find_origin_LT(int input_origin_x,int input_origin_y,int input_origin_z);
        void find_origin_LS(int input_origin_x,int input_origin_y,int input_origin_z);
        void find_origin_IH(int input_origin_x,int input_origin_y,int input_origin_z);
        void find_origin_SH(int input_origin_x,int input_origin_y,int input_origin_z);

        int output_origin_x,output_origin_y,output_origin_z;
        int origin_available;
        vector <vector <vector <int > > > model_array;
    private:
        int P_ori_X, P_ori_Y, P_ori_Z;
        vector <int>& boundary_x;
        vector <int>& boundary_y;
        vector <int>& boundary_z;
};

#endif /* Find_origin_hpp */
