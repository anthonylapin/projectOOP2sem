//
//  Level.hpp
//  ProjectOOP
//
//  Created by Anton Lapin on 2019-05-11.
//  Copyright © 2019 Anton Lapin. All rights reserved.
//

#ifndef Level_hpp
#define Level_hpp
#include "Bot.hpp"
#include "Player.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include "Color.hpp"
using namespace std;

class Level
{
private:
    
    int id; // level №
    unsigned int bot_number;
    vector<Bot> bots;
    unsigned int available_money;
    unsigned int obtained_money;
    double obtained_skill;
public:
    static int Count; // already
    Level(int bot_number, int level_number);
    void add_bot(string insurance_name, string insurance_surname, unsigned int insurance_number, unsigned int insurance_expiry_year, unsigned int insurance_sum, string insurance_situation, string passport_name, string passport_surname, string passport_nationality, unsigned int passport_birthday, unsigned int passport_number, unsigned int passport_expiry_year);
    Level(); // already
    int GetID(); // already
    int Get_ObtainedMoney();
    void Start(); //
    void Set_AvailableMoney(); // already
    void Obtain(int right, int wrong);
    void Set_ObtainedMoney(int money); // already
    void Set_BotNumber(); // already
    void Set_Bots(); // already
    void Set_Parameters(); // already
    void Set_Taxes(); // write down funct.
    void Set_ObtainedSkill(int right, int wrong);
    double Get_ObtainedSkill();
    int Get_BotSize();
    int Taxes(int s);
    void start();
    unsigned int Right(unsigned int right);
    unsigned int Wrong(unsigned int wrong);
    void Set_Parameters1();
    void print();
    void remove_bot(string name);
    ~Level();
};
#endif /* Level_hpp */
   // int level_no;
