//
//  Game.hpp
//  ProjectOOP
//
//  Created by Anton Lapin on 2019-05-11.
//  Copyright © 2019 Anton Lapin. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include "Level.hpp"
#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <stdio.h>
#include "Color.hpp"
using std::cout;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using namespace std;
class Game
{
private:
    Player *player;
    vector<Level> levels;
public:
    Game(); // initializing all the things.
    void Set_Player();
    void preview();
    void rules();
    void menu();
    void start();
    void playerInfo();
    void slow_print(const string&, unsigned int);
    void Set_Levels();
    void GameOver();
    void Count(unsigned int r, unsigned int wx);
    void remove_playerInfo();
    ~Game();
    
};
#endif /* Game_hpp */








// unsigned int right = 0;
//unsigned int wrong = 0;
