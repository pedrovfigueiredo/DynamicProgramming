//
//  compare_structs.h
//  TravellingSalesman
//
//  Created by Pedro Figueirêdo on 19/10/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#ifndef compare_structs_h
#define compare_structs_h

struct compareSet{
    bool operator()(const std::string& a, const std::string& b) const
    {
        int counta = 0,countb = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '1')
                counta++;
            if (b[i] == '1')
                countb++;
        }
        
        if(counta == countb)
            for (int i = 0; i < a.size(); i++)
                if (a[i] != b[i])
                    return a[i] < b[i];
            
        return counta < countb;
    }
};


#endif /* compare_structs_h */
