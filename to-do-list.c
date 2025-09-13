#include<stdio.h>
#include<string.h>
#define MAX_TASKS 100
#define MAX_LEN 100

char tasks[MAX_TASKS][MAX_LEN]; // mảng chứa công việc
int taskCount = 0;

void Introduction(){
    printf("Welcome to HungLe's to-do-List\n");
    printf("1. Create new list\n");
    printf("2. Resume the previous list\n");
    printf("3. Show list to screen\n");
    printf("4. Delete list\n");
    printf("5. Exit\n");
}
void CreateNewList() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter new task: ");
    getchar(); // để bỏ cái \n sau scanf
    fgets(tasks[taskCount], MAX_LEN, stdin);
    tasks[taskCount][strcspn(tasks[taskCount], "\n")] = '\0'; // xóa \n thay bằng \0
    taskCount++;
    printf("Task added!\n");
}

void ShowList() {
    if (taskCount == 0) {
        printf("No tasks in the list.\n");
        return;
    }
    printf("Your tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

void DeleteList() {
    if (taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }
    int index;
    printf("Enter task number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > taskCount) {
        printf("Invalid task number.\n");
        return;
    }
    for (int i = index - 1; i < taskCount - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }
    taskCount--;
    printf("Task deleted!\n");
}


int main(){
    int option;
    do{
        Introduction();
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option){
            case 1: CreateNewList(); break;
            case 2: printf("This task is not finish yet"); break;
            case 3: ShowList(); break;
            case 4: DeleteList();break;
            case 5: printf("Thank you for using our list\n");
                return 0;
        }
    }
    while(option!= 5);
    return 0;
}