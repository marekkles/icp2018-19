#ifndef __POSITION_H

#define __POSITION_H

#include <string>

class Position
{
public:
    Position(int row, int coulumn);
    ~Position();
    int Row;
    int Coulumn;
};

#endif