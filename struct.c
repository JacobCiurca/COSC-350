#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	struct student {
	char fname[20];
	char lname[20];
	int id;
	};
	char first[20];
	char last[20];
	int no;
	int size;
	int i;
	printf("Please enter the number of students in the stuct\n");
	scanf("%d", &size);
	typedef struct student list;
	list *ptr;
	list *tmp;

	ptr = (list *) calloc (size, sizeof(list));
	tmp = ptr;
	for(i = 0; i < size; i++){
	printf("Please enter the first name of student %d\n", i+1);
	scanf("%s", first);
	strcpy(tmp->fname, first);
	printf("Please enter the last name of student %d\n", i+1);
	scanf("%s", last);
	strcpy(tmp->lname, last);
	printf("Please enter the id of student %d\n", i+1);
	scanf("%d", &no);
	tmp->id = no;
	tmp++;
	}
	tmp = ptr;
	for(i = 0; i < size; i++){
	printf("Student %d: ", i+1);
	printf("%s", tmp->fname);
	printf(", %s", tmp->lname);
	printf(", %d\n", tmp->id);
	tmp++;
	}
	return 0;
}


