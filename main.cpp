//
//  main.cpp
//  ProjectOOP
//
//  Created by Anton Lapin on 2019-05-10.
//  Copyright © 2019 Anton Lapin. All rights reserved.
//

#include <iostream>
#include "Game.hpp"
#include <thread>
#include <chrono>
using namespace std;
int main()
{
    
   auto start_time = chrono::high_resolution_clock::now();
    cout << "Choose mode: " << endl;
    cout << "1. Game scenario (callin' all methods in main" << endl;
    cout << "2. Game with MENU" << endl;
    int a;
    cin >> a;
 
    Game* g = new Game;
    do
    {
        if(a == 2)
        {
            
            g->menu();
            delete g;
            break;
        }
        else if(a == 1)
        {
            g->playerInfo(); // prints player's information.
            g->rules(); // prints game rules
            cout << endl;
            g->start(); // game mode
            cout << endl;
            g->playerInfo(); // prints info about player, shows that after the end of the game player takes his initial amount of money and initial skill;
            cout << endl;
            g->start();
            cout << endl;
            g->playerInfo();
            g->rules();
            cout << endl;
            delete g;
            break;
        }
        else
        {
            cout << "Try again!" << endl;
            if(!cin.good())
            {
                // cout << "Not an integer." << endl;
                cin.clear();
                cin.ignore(2147483647, '\n'); // NB: preferred method for flushing cin
            }
            
        }
    }while(a != 1 || a != 2);
    srand(time(NULL));
    auto end_time = chrono::high_resolution_clock::now();
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
    cout << red << endl << "Playing time: " <<  chrono::duration_cast<chrono::seconds>(end_time - start_time).count() << " sec." << def << endl;
    return 0;
    
}
