#ifndef __POSITION_H

#define __POSITION_H

#include <string>

class Position
{
public:
    Position() = default;
    Position(char row, char coulumn);
    bool operator==(const Position & op1) const;
    bool operator!=(const Position & op1) const;
    char rowToChar() const;
    char coulumnToChar() const;
    void Update(const Position & position);
    ~Position() = default;
    int Row;
    int Coulumn;
};

#endif