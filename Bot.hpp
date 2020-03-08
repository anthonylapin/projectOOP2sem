//
//  Bot.hpp
//  ProjectOOP
//
//  Created by Anton Lapin on 2019-05-10.
//  Copyright © 2019 Anton Lapin. All rights reserved.
//

#ifndef Bot_hpp
#define Bot_hpp
#include "BotPassport.hpp"
#include "Bot_InsuranceCard.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class Bot
{
private:
    BotPassport passport;
    InsuranceCard card;
    bool cheater;
public:
    Bot();
    Bot(BotPassport& passport, InsuranceCard& card); 
    void Set_CardNameParameters(string name, string surname, unsigned int number, unsigned int expiry_year, unsigned int sum, string situation);
    void Set_PassportParameters(string name, string surname, string nationality, unsigned int birthday, unsigned int number, unsigned int expiry_year);
    void print();
    bool Get_Cheater();
    void Set_Cheater();
    string Get_Name();
};
#endif /* Bot_hpp */
