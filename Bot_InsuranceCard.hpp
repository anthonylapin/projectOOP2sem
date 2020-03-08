//
//  Bot_InsuranceCard.hpp
//  ProjectOOP
//
//  Created by Anton Lapin on 2019-05-10.
//  Copyright © 2019 Anton Lapin. All rights reserved.
//

#ifndef Bot_InsuranceCard_hpp
#define Bot_InsuranceCard_hpp
#include <string>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <iostream>
#include "Color.hpp"
using namespace std;
static const string names1[20] = {"Jeremy", "Addison", "Marshall", "Michael", "John", "Calvin", "Lionel", "Dominik", "Tanvin", "Anna", "Katerina", "Andrea", "Rafael", "Rodger", "Bogdan", "Jughead", "Emily", "Barley", "Bobby", "Brayden" };
static const string surnames1[] = {"Anderton", "Timlin", "Allen", "White", "Green", "Hailey", "Blackwood", "Bristol", "Lanester", "Snow", "Lincoln", "Milton", "Elton", "Ramsey", "Dayton", "Digby", "Oakley" };
static const string situations[] = {"Stolen Car", "Car accident", "Car damage", "Health Insurance", "Medical Procedures", "Natural Disaster", "House Fire", "Death", "Renter's Insurance", "ZzZ", "欺詐者", " :) " };
class InsuranceCard
{
private:
    string name;
    string surname;
    unsigned int number;
    unsigned int expiry_year;
    unsigned int sum; // sum of money for insurance case
    string situation;
    bool cheater;
public:
    InsuranceCard(string name, string surname, unsigned int number, unsigned int expiry_year, unsigned int sum, string situation);
    InsuranceCard(); 
    void print();
    string Get_Name();
    string Get_Surname();
    string Get_Situation();
    unsigned int Get_Number();
    unsigned int Get_ExpiryYear();
    unsigned int Get_Sum();
    bool Get_Cheater();
    void Set_Cheater();
    void Set_Name(string name);
    void Set_Surname(string surname);
    void Set_ExpiryYear(unsigned int y);
    void Set_Situations(string situation);
    void Set_Number(unsigned int n);
    void Set_Sum(unsigned int sum);
};
#endif /* Bot_InsuranceCard_hpp */
