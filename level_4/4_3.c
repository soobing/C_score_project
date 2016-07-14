#include <stdio.h>
#include <string.h>
#include <stdlib.h> //atoi()
#define stuNum 10

typedef struct score {
    int sum;
    double avg;
    char grade[3];
    int rank;
}SCR;

typedef struct student {
    int id;
    char name[20];
    int  ban;
    int kor, eng, math;
    SCR score;
} STU;


void printArr(STU** arr, int* pos);
void calcStudent(STU** arr, int* pos);
void sortArr(STU** arr, int* pos);
void addStudent (STU** Arr, int* pos);

int main(void) {
    int i;
    int pos=3;
    
    STU stuArr[stuNum] = {
        {13010470, "박수빈", 2, 100, 100, 100},
        {10182929, "남궁성", 1, 40, 20, 60},
        {16273271, "이재승", 3, 80, 100, 20}
    };
    
    STU* pArr[stuNum];
    for(i=0;i<pos;i++)
        pArr[i] = &stuArr[i];
    
    printArr(pArr, &pos);
    puts("");
    addStudent(pArr, &pos);
    printArr(pArr, &pos);
    
}

void printArr(STU** arr, int* pos) {
    printf("========printArr========\n");
    printf("학번\t\t\t이름\t\t반\t국어\t영어\t수학\t\t총점\t\t평균\t\t\t\t순위\n");
    for(int i=0;i<*pos;i++)
        printf("%7d\t%3s\t%2d\t%3d\t%3d\t%3d\t\t%d\t\t%lf\t\t%d\n",arr[i]->id, arr[i]->name, arr[i]->ban, arr[i]->kor, arr[i]->eng, arr[i]->math, arr[i]->score.sum, arr[i]->score.avg, arr[i]->score.rank);
    
}

void calcStudent(STU** arr, int* pos) {
    
    for(int i=0;i<*pos;i++) {
        arr[i]->score.sum = arr[i]->kor + arr[i]->eng + arr[i]->math;
        arr[i]->score.avg = arr[i]->score.sum  / 3.0;
    }
}
void sortArr(STU** arr, int* pos) {
    int i, j;
    STU tmp;
    for(i=0;i<*pos-1;i++)
        for(j=0;j<*pos-i-1;j++)
            if(arr[j]->score.sum<arr[j+1]->score.sum) {
                tmp = *arr[j];
                *arr[j] = *arr[j+1];
                *arr[j+1] = tmp;
            }
    
    for(i=0;i<*pos;i++)
        arr[i]->score.rank = i+1;
}

void addStudent (STU** arr, int* pos) {
    STU* tmpStu = malloc(sizeof(STU));
    tmpStu->score.sum = 0;
    tmpStu->score.avg = 0.0;
    tmpStu->score.rank = 0;
    char tmp[30];
    char* delimeter=" ";
    char* token;
    char* arg[6];
    int i=0;
    
    printf("추가할 학생의 정보를 입력하세요.(종료:'Enter')\n");
    printf("학번\t\t\t이름\t\t반\t국어\t영어\t수학\t\t총점\t\t평균\t\t\t\t순위\n");
    
    while(1) {
        gets(tmp);
        if(strlen(tmp)==0) break;

        token = strtok(tmp, delimeter);
        while(token) {
            //strcpy(arg[i], token);
            arg[i] = token;
            i++;
            token = strtok(NULL, delimeter);
        }
        tmpStu->id = atoi(arg[0]);
        strcpy(tmpStu->name, arg[1]);
        tmpStu->ban = atoi(arg[2]);
        tmpStu->kor = atoi(arg[3]);
        tmpStu->eng = atoi(arg[4]);
        tmpStu->math = atoi(arg[5]);
        
        arr[(*pos)++]=tmpStu;
        
    }
    
}



