//
//  Player.cpp
//  ProjectOOP
//
//  Created by Anton Lapin on 2019-05-10.
//  Copyright © 2019 Anton Lapin. All rights reserved.
//

#include "Player.hpp"


Player::Player()
{
    Set_DefaultParameters();
    Set_ID();
}
void Player::Set_DefaultParameters()
{
    savings = 30;
    skill = 1.0;
    id = 0;
    username = "DEFAULT";
}
string Player::print()
{
    string info;
    info = "Player's information: \n1.ID: " + to_string(Get_ID()) + "\n2.Player's name: " + Get_UserName() + "\n3.Savings: " + to_string(Get_Savings()) + "$" + "\n4.Skill: " + to_string(Get_Skill()) + "\n";
    return info;
}
string Player::Get_UserName()
{
    return username;
}

unsigned int Player::Get_ID()
{
    return id;
}

int Player::Get_Savings()
{
    return savings;
}

void Player::Set_ID()
{
    srand(time(NULL));
    id = rand() % 100;
}

void Player::Set_Savings(int s)
{
    savings += s*skill;
}

void Player::Set_UserName()
{
    
    string name, surname;
    cout << "Enter your name: ";; cin >> name; cout << endl << "Enter your surname: "; cin >> surname;
    username = name + " " + surname;
    
}

void Player::Set_Skill(float s)
{
    skill += s;
}

float Player::Get_Skill()
{
    return skill;
}
