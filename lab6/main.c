#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#include "bitmap.h"

typedef struct shape{
    point* pvec;
    int len;
    int closed;
    int color;
    struct shape* next;
} shape;

void rectangle(point p1, point p2, shape** slist, int col)
{
    /*
     * add four points to the  list, with color added
     */
    shape* head = *slist;

    shape* s1 = (shape*)malloc(sizeof(shape));
    point* p_arr = (point*)malloc(4*sizeof(point));
    p_arr[0] = p1;
    p_arr[1] = (point){p2.x,p1.y};
    p_arr[2] = p2;
    p_arr[3] = (point){p1.x,p2.y};
    s1->pvec = p_arr;
    s1->color = col;
    s1->closed = 1;

    if(head == NULL){
        s1->next = NULL;
    }
    else {
        s1->next = head;
    }

    *slist = s1;
}

void circle(point c, double r, shape** slist,int col)
{
    /*
     * add a circle to the list of shapes (100 points)
     */
    int i = 0;
    shape* head = *slist;
    shape* s1 = (shape*)malloc(sizeof(shape));
    point* p_arr = (point*)malloc(100*sizeof(point));
    s1->color = col;
    s1->closed = 1;

    for(double angle = 0;angle < 2*(22.0/7.0); angle += 2*(22.0/7.0)/100)
    {
        point x = {c.x + r*cos(angle), c.y + r*sin(angle)};
        p_arr[i] = x;
        i++;
    }

    s1->pvec = p_arr;

    if(head == NULL){
        s1->next = NULL;
    }
    else {
        s1->next = head;
    }
    *slist = s1;
}

void segment(point p1, point p2, shape** slist, int col)
{
    /*
     * add two points to the list
     */

    shape* head = *slist;

    shape* s1 = (shape*)malloc(sizeof(shape));
    point* p_arr = (point*)malloc(4*sizeof(point));
    p_arr[0] = p1;
    p_arr[1] = p2;
    s1->pvec = p_arr;
    s1->color = col;
    s1->closed = 0;

    if(head == NULL){
        s1->next = NULL;
    }
    else {
        s1->next = head;
    }

    *slist = s1;
}

void load_shapes(char* fname, shape** slist)
{
    /*
     * add line by line
     * add shapes to the shape list as they are read
     */
    point p1;
    point p2
        ;
    int r;
    int col
        ;
    FILE *fp;
    fp = fopen(fname, "r");

    char buffer[256];

    while(fscanf(fp, "%s", buffer)!=EOF) {
		    if (strcmp(buffer,"rectangle")==0) {
			    fscanf(fp, "%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
			    fscanf(fp, "%d\n", &col);
			    rectangle(p1, p2, slist, col);
			    continue;
		    }

		    if (strcmp(buffer, "circle")==0) {
			    fscanf(fp, "%d %d %d", &p1.x, &p1.y, &r);
			    fscanf(fp, "%d\n", &col);
			    circle(p1, r, slist, col);
			    continue;
		    }

		    if (strcmp(buffer, "segment")==0) {
			    fscanf(fp, "%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
			    fscanf(fp, "%d\n", &col);
			    segment(p1, p2, slist, col);
			    continue;
		    }

		    printf("Entity %s unknown\n", buffer);
		    break;
	    }
        fclose(fp);
}

void convert(shape* sp, canvas *cp) {

}

int main(int argv, char* argc[]){

    shape* shapes = NULL;
    canvas* canvas = make_canvas();

    load_shapes(argc[1],&shapes);

    printf("Hello World");
    return 0;
}
