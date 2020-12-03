#include "Selection_FA.h"

SelectionStrategiesRegister Selection_FA::selectionStrategiesRegister("FA", getInstance());

Selection_FA * Selection_FA::selection_FA = 0;

Selection_FA * Selection_FA::getInstance() {
    if ( selection_FA == 0 )
        selection_FA = new Selection_FA();

    return selection_FA;
}

int Selection_FA::apply(Router * router, const vector < int >&directions, const RouteData & route_data){
    assert(directions.size()!=0);
    /*
       int output = directions[rand() % directions.size()];
       return output;
       */
    int output;
    if(directions.size()==1){
        output = directions[0];
        return output;
    }
    else{
        /* 
        Note: The elements are priority order not directions

        3210 = 0123
        2301 = 2301
        1032 = 1023
        0123 = 3210
        */

        static int pr_order[4][4] = {{3,2,1,0},{2,3,0,1},{1,0,3,2},{0,1,2,3}};
        //static int pr_order[4][4] = {{0,1,2,3},{2,3,0,1},{1,0,2,3},{3,2,1,0}};
        int dir1 = directions[0]; 
        int dir2 = directions[1];
        int idx1,idx2,ptr = GlobalParams::fa_ptr;
        /*
        for(int i=0;i<4;i++){
            if(pr_order[ptr][i] == dir1)
                idx1=i;
            if(pr_order[ptr][i] == dir2)
                idx2=i;
        }
        [3 1] = CI same
        */
        idx1 = pr_order[ptr][dir1];
        idx2 = pr_order[ptr][dir2];
        GlobalParams::fa_ptr++;
        if(ptr>3)
            GlobalParams::fa_ptr=0;
        if(idx1 < idx2)
            output = dir1;
        else
            output = dir2;
        return output;
    }
}

void Selection_FA::perCycleUpdate(Router * router){ }
