#include "Position.h"

int CoulumnToNumber(PositionCoulumn_t coulumn)
{
    switch (coulumn)
    {
    case COULUMN_A:
        return 1;
        break;
    case COULUMN_B:
        return 2;
        break;
    case COULUMN_C:
        return 3;
        break;
    case COULUMN_D:
        return 4;
        break;
    case COULUMN_E:
        return 5;
        break;
    case COULUMN_F:
        return 6;
        break;
    case COULUMN_G:
        return 7;
        break;
    case COULUMN_H:
        return 8;
        break;
    default:
        break;
    }
}

Position::Position(int row, PositionCoulumn_t coulumn)
{
    this->Coulumn = CoulumnToNumber(coulumn);
    this->Row = row;
}

Position::Position(char row, char coulumn)
{
    this->Row = row - '1' + 1;
    this->Coulumn = coulumn - 'a' +  1;
}
bool Position::operator==(const Position & op1)
{
    return this->Coulumn == op1.Coulumn && this->Row == op1.Row;
}
bool Position::operator!=(const Position & op1)
{
    return ! ((*this) == op1);
}
void  Position::Update(Position & position){
    this->Row = position.Row;
    this->Coulumn = position.Coulumn;
}