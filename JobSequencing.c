#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char id;
    int deadline;
    int profit;
} Job;

// Comparison function for sorting jobs based on profit
int compareJob(const void *a, const void *b) {
    return ((Job*)b)->profit - ((Job*)a)->profit; // Compare profits in descending order
}

// Function to find the best job sequence
void bestJob(Job jobs[], int sizeOfJobs) {
    char jobsToDo[5] = {'\0'}; // Assign every element of array to '\0'

    int i, k;

    // For each job, find the nearest available slot to its deadline
    for (i = 0; i < sizeOfJobs; i++) {
        k = jobs[i].deadline - 1;
        // Searching for empty date nearest to deadline backwards
        while (jobsToDo[k] != '\0' && k >= 0) {
            k--;
        }
        if (k != -1) {
            jobsToDo[k] = jobs[i].id;
        }
    }

    printf("Best order and jobs to do is:\n");
    k = 0;
    while (jobsToDo[k] != '\0') {
        printf("%c ", jobsToDo[k]);
        k++;
    }
    printf("\n");
}

// Function to display the jobs
void display(Job jobs[], int n) {
    int i;

    printf("Job Id: \t");
    for (i = 0; i < n; i++) {
        printf("%c \t", jobs[i].id);
    }
    printf("\n");

    printf("Job Deadline: \t");
    for (i = 0; i < n; i++) {
        printf("%d \t", jobs[i].deadline);
    }
    printf("\n");

    printf("Job Profit: \t");
    for (i = 0; i < n; i++) {
        printf("%d \t", jobs[i].profit);
    }
    printf("\n");
}

// Driver program to test above functions
int main() {
    Job jobs[] = {
        {'w', 1, 19},
        {'v', 2, 100},
        {'x', 2, 27},
        {'y', 1, 25},
        {'z', 3, 15}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    display(jobs, n);

    // Sorting jobs[] w.r.t profit in descending order
    qsort(jobs, n, sizeof(jobs[0]), compareJob);

    bestJob(jobs, n);

    return 0;
}




/*
Job Id:     w     v     x     y     z
Job Deadline:     1     2     2     1     3
Job Profit:     19     100     27     25     15
Best order and jobs to do is:
v x w 
*/
