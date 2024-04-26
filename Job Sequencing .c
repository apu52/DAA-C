#include <stdio.h>

#define MAX_JOBS 10

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

void inputJobs(Job jobs[], int *num_jobs) {
    printf("Enter the number of jobs: ");
    scanf("%d", num_jobs);
    int i;

    printf("Enter job details (id, deadline, profit) one by one:\n");
    for (i = 0; i < *num_jobs; i++) {
        printf("Job %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &jobs[i].id);
        printf("Deadline: ");
        scanf("%d", &jobs[i].deadline);
        printf("Profit: ");
        scanf("%d", &jobs[i].profit);
    }
}

void swap(Job *a, Job *b) {
    Job temp = *a;
    *a = *b;
    *b = temp;
}

void sortJobs(Job jobs[], int num_jobs) {
	int i;
	int j;
    for (i = 0; i < num_jobs - 1; i++) {
        for (j = 0; j < num_jobs - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                swap(&jobs[j], &jobs[j + 1]);
            }
        }
    }
}

void jobSequencing(Job jobs[], int num_jobs) {
    int max_deadline = 0;
    int i;
    for (i = 0; i < num_jobs; i++) {
        if (jobs[i].deadline > max_deadline) {
            max_deadline = jobs[i].deadline;
        }
    }

    int sequence[max_deadline];
    for (i = 0; i < max_deadline; i++) {
        sequence[i] = -1;
    }

    int total_profit = 0;
    for (i = 0; i < num_jobs; i++) {
        int deadline = jobs[i].deadline;
        while (deadline > 0 && sequence[deadline - 1] != -1) {
            deadline--;
        }
        if (deadline > 0) {
            sequence[deadline - 1] = jobs[i].id;
            total_profit += jobs[i].profit;
        }
    }

    printf("Job sequence with deadlines:\n");
    for (i = 0; i < max_deadline; i++) {
        if (sequence[i] != -1) {
            printf("Job %d\n", sequence[i]);
        }
    }
    printf("Total profit: %d\n", total_profit);
}

int main() {
    Job jobs[MAX_JOBS];
    int num_jobs;

    inputJobs(jobs, &num_jobs);
    sortJobs(jobs, num_jobs);
    jobSequencing(jobs, num_jobs);

    return 0;
}
