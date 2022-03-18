#include "navigate.h"

#define COL_NUM 10
#define ROW_NUM 10

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define STUCK 4


int chooseDirection (int [3], int*);

struct Position
{
    int r;
    int c;
};

static struct Position position;
static struct Position destination;
static int matrix[COL_NUM][ROW_NUM]; 

int initNavigation(int start_r, int start_c, int dest_r, int dest_c) // Call this before the first time you
{
    int i, j;
    for (i=0; i<ROW_NUM; i++)
        for (j=0; j<COL_NUM; j++)
            matrix[i][j] = 0;
    position.r = start_r;
    position.c = start_c;
    destination.r = dest_r;
    destination.c = dest_c;
    return 0;
}

int navigate (int obstacles[4], int *chosen_direction)
{
    int directions[4];
    int choice;
    int obstacle_num;
    if (position.r == destination.r && position.c == destination.c) return 0; // Returns zero when at destination.
    else
    {
        // Updating matrix. Update value only if it's an obstacle. Ignore otherwise. 
        matrix[position.r - 1][position.c] = (obstacles[UP] == 0) ? matrix[position.r - 1][position.c] : 1; // Up
        matrix[position.r + 1][position.c] = (obstacles[DOWN] == 0) ? matrix[position.r + 1][position.c] : 1; // Down
        matrix[position.r][position.c - 1] = (obstacles[LEFT] == 0) ? matrix[position.r][position.c - 1] : 1; // Left
        matrix[position.r][position.c + 1] = (obstacles[RIGHT] == 0) ? matrix[position.r][position.c + 1] : 1; // Right
        directions[UP] = matrix[position.r - 1][position.c];
        directions[DOWN] = matrix[position.r + 1][position.c];
        directions[LEFT] = matrix[position.r][position.c - 1];
        directions[RIGHT] = matrix[position.r][position.c + 1];
        obstacle_num = 0;
        // Incrementing number of visits. Smaller number means more visits. 0 means no visits.
        matrix[position.r][position.c] = matrix[position.r][position.c] - 1;
        choice = chooseDirection(directions, &obstacle_num);
        if (obstacle_num == 3) matrix[position.r][position.c] = 2; // 3 obstacles means a dead end. Set current position to 2 so that its treated as an obstacle. 2 so it can be distinguisced from true obstacle if needed.
        //down 0
        if (choice == DOWN)
        { 
            (*chosen_direction) = DOWN;
            position.r++; // Position update
        }
        //right 1
        else if (choice == RIGHT)
        {  
            (*chosen_direction) = RIGHT;
            position.c++; 
        }
        //left 2
        else if (choice == LEFT)
        {   
            (*chosen_direction) = LEFT;
            position.c--; 
        }
        //up 3
        else if (choice == UP)
        {
            position.r--;
            (*chosen_direction) = UP;
        }
        else if (choice == STUCK)
        {
            (*chosen_direction) = STUCK; // Stuck, can't choose a direction.
        }
    }
    return 1;
}


int chooseDirection(int directions[4], int *obstacles) // Find the index of the direction with highest number i.e. the smallest number of visits.
{
    int i;
    int index = STUCK;
    for (i=0; i<4; i++)
    {
        if (directions[i] < 1)  // Find direction that has no obstacle. If the loop finishes without changing index it means that there are obstacles on all four sides.
        {
            index = i;
            break;
        }
        else (*obstacles)++; // Count obstacles (not all will be counted here)
    }
    for (; i<4; i++)
    {
        if (directions[i] < 1 )
        {
            if (directions[i] > directions[index]) index = i; // Look for smallest numebr of visits. Ignore ones (obstacles).
        }
        else (*obstacles)++; // Count obstacles
    }
    return index;
}
