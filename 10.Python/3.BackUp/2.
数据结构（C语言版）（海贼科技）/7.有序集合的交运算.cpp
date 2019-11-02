#include <stdio.h>
#include <stdlib.h>

typedef struct Vector{
    int size, length;
    int* data;
} Vector;

Vector* Init(Vector* v, int _size) {
    v->size = _size;
    v->data = (int* )malloc(sizeof(int) * v->size);
    v->length = 0;
    return v;
}
Vector* add (Vector* v, int index) {
    v->data[(v->length)++] = index;
    return v;
}

void show(Vector* v) {
    for(int i = 0; i < v->length; i++) {
    	i == 0 || printf(" ");
        printf("%d", v->data[i]);
    }
}
Vector* get_ans(Vector* v1, Vector* v2, Vector* v) {
    int p1 = 0;
    int p2 = 0;
    int p = 0;
    while (!((p1 == v1->length-1) && (p2 == v2->length-1))) {
        //printf("p1 = %d p2 = %d p = %d\n", p1, p2, p);
        //printf("vp1 = %d  vp2 = %d  \n", v1->data[p1], v2->data[p2]);
        if(v1->data[p1] == v2->data[p2]) {
            int needadd = v1->data[p1];
            //printf("needadd = %d  p = %d \n", needadd, p);
            if(p != 0 ) {
                if(v->data[p-1] != needadd) {
                v = add(v, needadd);
                p++;
                }
            } else {
                v = add(v, needadd);
                p++;
            }
            p1++;
            p2++;
        } else if(v1->data[p1] > v2->data[p2]) {
            if(p2 < ((v2->length)-1)) p2++; else break;
        } else {
            if(p1 < ((v1->length)-1)) p1++; else break;
        }
    //printf("*****************************\n");
    }
    
    if (p1 == v1->length-1 && p2 == v2->length-1) {
		if(v1->data[p1] == v2->data[p2]) {
            int needadd = v1->data[p1];
            if(p != 0 ) {
                if(v->data[p-1] != needadd) {
                v = add(v, needadd);
                p++;
                }
            } else {
                v = add(v, needadd);
                p++;
            }
        }
    }
    //printf("\n show v :\n");
    //show(v);
    return v;
}
int main() {
    Vector *v1, *v2, *v3;
    v1 = (Vector* )malloc(sizeof(Vector));
    v2 = (Vector* )malloc(sizeof(Vector));
    v3 = (Vector* )malloc(sizeof(Vector));
    int t1, t2, t3;
    scanf("%d", &t1);
    v1 = Init(v1, t1);
    int temp = 0;
    for (int i = 0; i < t1; i++) {
        scanf("%d", &temp);
        v1 = add(v1, temp);
    }
    //show(v1);
    scanf("%d", &t2);
    v2 = Init(v2, t2);
    for (int i = 0; i < t2; i++) {
        scanf("%d", &temp);
        v2 = add(v2, temp);
    }
    //show(v2);
    t3 = (t1 > t2 ? t2 : t1);
    t3++;
    t3 = 100;
    //printf("\n111111 t3 = %d\n", t3);
    v3 = Init(v3, t3);
    //printf("\n2222222\n");
    //printf("t3 = %d\n", t3);
    
    v3 = get_ans(v1, v2, v3);
    //printf("\n3333333\n");
    /*
    int p1 = v1->length - 1, p2 = v2->length - 1;
    while(p1 >= 0 && p2 >= 0) {
        if(p1 == 0 && p2 ==0) {
			if(v1->data[0] == v2->data[0]) {
				v3 = add(v3, v1->data[0]); 
			}
			break;
		} 
        if(v1->data[p1] == v2->data[p2]) {
            v3 = add(v3, v1->data[p1]);
            if(p1 != 0) {
              p1--;  
            } else {
              p2--;   
            }
        } else if (v1->data[p1] > v2->data[p2]) {
            if(p1 > 0) {
              p1--;  
            } else {
              p2--;  
            } 
        } else {
            if(p2 > 0) {
              p2--;  
            } else {
              p1--;  
            }
        }
    }
    */
	printf("%d\n", v3->length);
    show(v3);
    return 0;
}