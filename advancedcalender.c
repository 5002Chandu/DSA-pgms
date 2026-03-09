#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct Activity { 
 char date[11]; 
 char activity[100]; 
}; 

void create(struct Activity calendar[], int size) { 
 for (int i = 0; i < size; i++) { 
 printf("Enter activity details for Day %d (YYYY-MM-DD): ", i 
+ 1); 
 scanf("%s", calendar[i].date); 
 printf("Enter activity details for Day %d: ", i + 1); 
 getchar();  
 fgets(calendar[i].activity, sizeof(calendar[i].activity), 
stdin); 
 } 
} 
void read(struct Activity calendar[], int size) { 
 for (int i = 0; i < size; i++) { 
 printf("Enter activity details for Day %d (YYYY-MM-DD): ", i 
+ 1); 
 scanf("%s", calendar[i].date); 
 printf("Enter activity details for Day %d: ", i + 1); 
 getchar(); 
 fgets(calendar[i].activity, sizeof(calendar[i].activity), 
stdin); 
 } 
} 
void display(struct Activity calendar[], int size) { 
 printf("Weekly Activity Details Report:\n"); 
 for (int i = 0; i < size; i++) { 
 printf("Day %d: Date: %s\n", i + 1, calendar[i].date); 
 printf("Activity: %s", calendar[i].activity); 
 } 
} 
int main() { 
 int size; 
 printf("Enter the number of days in the calendar: "); 
 scanf("%d", &size); 
 struct Activity calendar[size]; 
 
 int choice; 
 printf("Choose an option:\n"); 
 printf("1. Create Calendar\n"); 
 printf("2. Read Calendar\n"); 
 scanf("%d", &choice); 
 if (choice == 1) { 
 create(calendar, size); 
 } else if (choice == 2) { 
 read(calendar, size); 
 } else { 
 printf("Invalid choice\n"); 
 return 1; 
 } 
 
 display(calendar, size); 
 return 0; 
}