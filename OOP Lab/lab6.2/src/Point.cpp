#include "Point.h"

Point Point::TinhtienPoint(Vector A, Point M)
{
    M.a= M.a + A.x;
    M.b= M.b +A.y;
    return M;

}
