#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};
struct rectangle {
    struct point p1;
    struct point p2;
};

int main() {
    struct point p;
    scanf("%d %d",&p.x,&p.y);
    struct rectangle rect;
    scanf("%d%d%d%d",&rect.p1.x,&rect.p1.y,&rect.p2.x,&rect.p2.y);
    if((p.x-rect.p1.x)*(p.x-rect.p2.x)<0 && (p.y-rect.p1.y)*(p.y-rect.p2.y)<0)
    {
        printf("YES");
    }
	else
    {
        printf("NO");
    }
    return 0;
}