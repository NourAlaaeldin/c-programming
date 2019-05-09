#include <stdio.h>
#include <stdlib.h>
//I've provided "min" and "max" functions in
//case they are useful to you
int min (int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

//Declare your rectangle structure here!
typedef struct {
  int x;
  int y;
  int width;
  int height;
}rectangle;

rectangle canonicalize(rectangle r) {
  if(r.width < 0)
    {
      r.width = r.width * -1;
      r.x = r.x - r.width;
    }
  if(r.height < 0)
    {
      r.height = r.height * -1;
      r.y = r.y - r.height;
    }
  //WRITE THIS FUNCTION
  return r;
}
rectangle intersection(rectangle r1, rectangle r2) {

  //creating the resultant rectangle 
  rectangle r;
  r1 = canonicalize(r1);
  r2 = canonicalize(r2);
  //get (x2,y2) of rectangle one
  int r1_x2 = r1.x + r1.width;
  int r1_y2 = r1.y + r1.height;
  //get (x2,y2) of rectangle two
  int r2_x2 = r2.x + r2.width;
  int r2_y2 = r2.y + r2.height;
  //get the coordinates of top right of the new rectangle
  int r_x = min(r1_x2,r2_x2);
  int r_y = min(r1_y2,r2_y2);
  //get the coordinates of bottom left of the new rectangle
  r.x = max(r1.x,r2.x);
  r.y = max(r1.y,r2.y);
  //checking whether the triangles intersect or not
  int spaceX = r1.x - r2_x2;
  int spaceY = r1.y - r2_y2;
  int space2X = r2.x - r1_x2;
  int space2Y = r2.y - r1_y2;
  if((spaceX > 0) || (spaceY > 0) || (space2X > 0) || (space2Y > 0))
    {
      r.width = 0;
      r.height = 0;
      return r;
    }
  //getting the new width and height
  r.width = r_x - r.x;
  r.height = r_y - r.y;
  //WRITE THIS FUNCTION
  return r;
}

//You should not need to modify any code below this line
void printRectangle(rectangle r) {
  r = canonicalize(r);
  if (r.width == 0 && r.height == 0) {
    printf("<empty>\n");
  }
  else {
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y, 
	                           r.x + r.width, r.y + r.height);
  }
}

int main (void) {
  rectangle r1;
  rectangle r2;
  rectangle r3;
  rectangle r4;

  r1.x = 2;
  r1.y = 3;
  r1.width = 5;
  r1.height = 6;
  printf("r1 is ");
  printRectangle(r1);

  r2.x = 4;
  r2.y = 5;
  r2.width = -5;
  r2.height = -7;
  printf("r2 is ");
  printRectangle(r2);
  
  r3.x = -2;
  r3.y = 7;
  r3.width = 7;
  r3.height = -10;
  printf("r3 is ");
  printRectangle(r3);

  r4.x = 0;
  r4.y = 7;
  r4.width = -4;
  r4.height = 2;
  printf("r4 is ");
  printRectangle(r4);

  //test everything with r1
  rectangle i = intersection(r1,r1);
  printf("intersection(r1,r1): ");
  printRectangle(i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  printRectangle(i);
  
  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  printRectangle(i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  printRectangle(i);

  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  printRectangle(i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  printRectangle(i);
  
  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  printRectangle(i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  printRectangle(i);

  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  printRectangle(i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  printRectangle(i);
  
  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  printRectangle(i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  printRectangle(i);

  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  printRectangle(i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  printRectangle(i);
  
  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  printRectangle(i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  printRectangle(i);


  return EXIT_SUCCESS;

}
