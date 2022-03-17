#include <stdio.h>
#include <stdlib.h>

#define COL_NUM 10
#define ROW_NUM 10

#define DEST_c 9
#define DEST_r 9

#define DOWN 0
#define RIGHT 1
#define LEFT 2
#define UP 3
#define STUCK 4

void freadMatrix(int [COL_NUM][ROW_NUM]);
void printMatrix(int [COL_NUM][ROW_NUM], int, int);
void navigate(int [COL_NUM][ROW_NUM]);
int chooseDirection (int [3], int*);

struct Position
{
    int r;
    int c;
};



int main ()
{
    int matrix[COL_NUM][ROW_NUM];
    
    freadMatrix(matrix);
    navigate(matrix);
    return 0;
}

void printMatrix (int matrix[COL_NUM][ROW_NUM], int position_r, int position_c)
{
    int i,j;
    for (i=0; i<ROW_NUM; i++)
    {
        for (j=0; j<COL_NUM; j++)
        {
            if (position_r == i && position_c == j)
            {
                fprintf(stdout, "@\t");
            }
            else
            {
                fprintf(stdout, "%d\t", matrix[i][j]);
            }
            
        }
        fprintf(stdout, "\n\n");
    }
    printf("\n");
}

void freadMatrix (int matrix[COL_NUM][ROW_NUM])
{
    FILE *fp = NULL;
    fp = fopen("matrix.txt", "r");
    int i, j;
    for (i=0; i<ROW_NUM; i++)
    {
        for (j=0; j<COL_NUM; j++)
        {
            fscanf(fp, "%d ", &matrix[i][j]);
        }
    }
    return;
}

void navigate (int matrix[COL_NUM][ROW_NUM])
{
    struct Position position; 
    position.r = 0; 
    position.c = 0;
    int directions[4];
    int choice;
    int obstacles;
    while (!(position.r == DEST_r && position.c == DEST_c))
    {
        printMatrix(matrix, position.r, position.c);
        obstacles = 0;
        // Incrementing number of visits. Smaller number means more visits. 0 means no visits.
        matrix[position.r][position.c] = matrix[position.r][position.c] - 1;
        //Checking if direction is out of bound. In case it is assign 1 so that it's treated as an obstacle.
        directions[UP] = (position.r - 1 < 0) ? 1 : matrix[position.r - 1][position.c];
        directions[RIGHT] = (position.c + 1 < COL_NUM) ? matrix[position.r][position.c + 1] : 1;
        directions[DOWN] = (position.r + 1 < ROW_NUM) ? matrix[position.r + 1][position.c] : 1;
        directions[LEFT] = (position.c - 1 < 0) ? 1 : matrix[position.r][position.c - 1];
        choice = chooseDirection(directions, &obstacles);
        if (obstacles == 3) matrix[position.r][position.c] = 2;
        //down 0
        if (choice == DOWN)
        {   // Obstacle check, out of bound check, number of previous visits check.
            position.r++; // Position update
        }
        //right 1
        else if (choice == RIGHT)
        {   // Obstacle check, out of bound check, number of previous visits check.
            position.c++; // Position update
        }
        //left 2
        else if (choice == LEFT)
        {   // Obstacle check, out of bound check, number of previous visits check.
            position.c--; // Position update
        }
        //up 3
        else if (choice == UP)
        {   // Obstacle check, out of bound check, number of previous visits check.
            position.r--; // Position update
        }
        else if (choice == STUCK)
        {
            printf("Stuck!\n");
        }
    }
    return;
}

int chooseDirection(int directions[4], int *obstacles) // Find the index of the direction with highest number i.e. the smallest number of visits. If visits are euqal then priority order down, left, up, right
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

