#ifndef __POSITION_H

#define __POSITION_H

#include <string>

typedef enum {COULUMN_A, COULUMN_B, COULUMN_C, COULUMN_D, COULUMN_E, COULUMN_F, COULUMN_G, COULUMN_H} PositionCoulumn_t;

int CoulumnToNumber(PositionCoulumn_t coulumn);

class Position
{
public:
    Position();
    Position(int row, PositionCoulumn_t coulumn);
    Position(char row, char coulumn);
    bool operator==(const Position & op1);
    bool operator!=(const Position & op1);
    void Update(Position & position);
    ~Position();
    int Row;
    int Coulumn;
};

#endif