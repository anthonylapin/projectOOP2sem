//
//  Color.hpp
//  ProjectOOP
//
//  Created by Anton Lapin on 2019-05-21.
//  Copyright © 2019 Anton Lapin. All rights reserved.
//

#ifndef Color_hpp
#define Color_hpp
#include "iostream"
using namespace std;
#include <stdio.h>
namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}
#endif /* Color_hpp */
