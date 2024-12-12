#include <stdio.h>
#include <stdlib.h>  // for abs() function

int board[20], count = 0;

// Function to print the solution
void print(int n) {
    int i, j;
    printf("\n\nSolution %d:\n\n", ++count);
    
    // Print column numbers (for clarity)
    for(i = 1; i <= n; ++i) {
        printf("\t%d", i);
    }

    // Print the board configuration
    for(i = 1; i <= n; ++i) {
        printf("\n\n%d", i);  // Print row number
        for(j = 1; j <= n; ++j) {  // Print columns
            if(board[i] == j)
                printf("\tQ");  // Queen at (i,j)
            else
                printf("\t-");  // Empty slot
        }
    }
}

// Function to check if a queen can be placed at (row, column)
int place(int row, int column) {
    int i;
    for(i = 1; i <= row - 1; ++i) {
        // Check for column conflict
        if(board[i] == column) 
            return 0;
        // Check for diagonal conflicts
        else if(abs(board[i] - column) == abs(i - row)) 
            return 0;
    }
    return 1; // No conflicts
}

// Function to solve the N-Queens problem
void queen(int row, int n) {
    int column;
    for(column = 1; column <= n; ++column) {
        if(place(row, column)) {
            board[row] = column;  // Place queen in this column
            if(row == n)  // If all queens are placed, print the solution
                print(n);
            else  // Try placing queen in the next row
                queen(row + 1, n);
        }
    }
}

int main() {
    int n;

    printf(" - N Queens Problem Using Backtracking - ");
    printf("\n\nEnter number of Queens: ");
    scanf("%d", &n);

    queen(1, n);  // Start the process from the first row
    return 0;
}



/*

 - N Queens Problem Using Backtracking - 

Enter number of Queens: 4


Solution 1:

	1	2	3	4

1	-	Q	-	-

2	-	-	-	Q

3	Q	-	-	-

4	-	-	Q	-

Solution 2:

	1	2	3	4

1	-	-	Q	-

2	Q	-	-	-

3	-	-	-	Q

4	-	Q	-	-


*/
