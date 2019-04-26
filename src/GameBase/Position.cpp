#include "Position.h"

Position::Position(char row, char coulumn)
{
    this->Row = row - '1' + 1;
    this->Coulumn = coulumn - 'a' +  1;
}
bool Position::operator==(const Position & op1) const
{
    return this->Coulumn == op1.Coulumn && this->Row == op1.Row;
}
bool Position::operator!=(const Position & op1) const
{
    return ! ((*this) == op1);
}

char Position::rowToChar() const 
{
    return Row - 1 + '1';
}

char Position::coulumnToChar() const 
{
    return Coulumn - 1 + 'a';
}

void  Position::Update(const Position & position){
    this->Row = position.Row;
    this->Coulumn = position.Coulumn;
}