#include <stdio.h>
#include <string.h>
#define stuNum 10

typedef struct score {
    int sum;
    double avg;
    char grade[3];
    int rank;
}SCR;

typedef struct student {
    char name[20];
    int  ban;
    char id[10];
    int kor, eng, math;
    SCR score;
} STU;

int addStudent (STU** Arr, int* pos);
void printArr(STU** arr, int* pos);

int main(void) {
    int pos=0;
    int stu=0;
    STU* pArr[stuNum];
    
    printf("몇명의 학생 정보를 입력하시겠습니까? (이름에 0입력시 종료)\n");
    scanf("%d",&stu);
   
    
    while(((addStudent(pArr,&pos))!=-1) && --stu);
    

    printArr(pArr, &pos);
}

int addStudent (STU** Arr, int* pos) {
    STU* tmp = malloc(sizeof(STU));
    
    printf("추가할 학생의 정보를 입력하세요.\n");
    printf("이름\t\t반\t학번\n");

    
    scanf("%s %d %s",tmp->name, &tmp->ban, tmp->id);
    if(strcmp(tmp->name, "0")==0) return -1;
    Arr[(*pos)++]=tmp;
    
    
    return 0;

}
void printArr(STU** arr, int* pos) {
    
    printf("========printArr========\n");
    printf("이름\t\t반\t학번\n");
    for(int i=0;i<*pos;i++)
        printf("%s\t%d\t%s\n",arr[i]->name, arr[i]->ban, arr[i]->id);
    
}