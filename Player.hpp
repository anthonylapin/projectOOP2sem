//
//  Player.hpp
//  ProjectOOP
//
//  Created by Anton Lapin on 2019-05-10.
//  Copyright © 2019 Anton Lapin. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp
#include <iostream>
#include <string>
#include <stdio.h>
#include <ostream>
#include "Color.hpp"
using namespace std;
class Player
{
private:
    string username;
    int savings; // initial amount of player's money
    unsigned int id; // player's id
    float skill; // initial value of player's skill
public:
    
    Player();
    string Get_UserName();
    unsigned int Get_ID();
    int Get_Savings();
    float Get_Skill();
    void Set_UserName();
    void Set_ID();
    void Set_Savings(int s);
    string print();
    void Set_Skill(float s);
    void Set_DefaultParameters();
};
#endif /* Player_hpp */
