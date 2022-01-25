/*
    Viết hàm is_in_circle trả về 1 nếu điểm p nằm trong đường tròn C.
    Kiểm tra hàm bằng một chương trình.
*/

#include <stdio.h>
typedef struct point
{
    double x;
    double y;
}point;

typedef struct circle
{
    point center;
    double radius;
}circle;

int is_in_circle(point *p, circle *c)
{
    double x_dist, y_dist;
    x_dist = p->x - c->center.x;
    y_dist = p->y - c->center.y;
    return (x_dist * x_dist + y_dist * y_dist <= c->radius * c->radius);

}

int main()
{
    point p;
    circle c;
    printf("Enter point coordinates: ");
    scanf("%lf %lf", &p.x, &p.y);
    printf("Enter point center coordinates: ");
    scanf("%lf %lf", &c.center.x, &c.center.y);
    printf("Enter circle radius: ");
    scanf("%lf", &c.radius);
    if(is_in_circle(&p, &c))
        printf("Point is in circle.\n");
    else printf("Point is out of circle\n");
    return 0;
}