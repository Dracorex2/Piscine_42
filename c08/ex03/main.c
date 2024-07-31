#include "ft_point.h"

void set_point(t_point *point)
{
    point->x = 42;
    point->y = 21;
    point->lucaslesalop = "Lucas c'est un salop";
}
int main(void)
{
    t_point point;

    set_point(&point);
    return (0);
}