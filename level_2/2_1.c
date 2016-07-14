#include <stdio.h>
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


void printArr(STU** arr, int pos);
void calcStudent(STU** arr, int pos);
void sortArr(STU** arr, int pos);


int main(void) {
    int i;
    int pos=3;
    
    STU stuArr[stuNum] = {
        {"박수빈", 2, "13010470", 100, 100, 100},
        {"남궁성", 1, "17028972", 40, 20, 60},
        {"이재승", 3, "11672937", 80, 100, 20}
    };

    STU* pArr[stuNum];
    
    for(i=0;i<pos;i++)
        pArr[i] = &stuArr[i];
    
    printArr(pArr, pos);
    calcStudent(pArr, pos);
    printArr(pArr, pos);
    sortArr(pArr, pos);
    printArr(pArr, pos);
    
}

void printArr(STU** arr, int pos) {
    printf("========printArr========\n");
    printf("이름\t\t반\t학번\t\t\t국어\t영어\t수학\t\t총점\t\t평균\t\t\t\t순위\n");
    for(int i=0;i<pos;i++)
        printf("%s\t%d\t%s\t%d\t%d\t%d\t\t%d\t\t%lf\t\t%d\n",arr[i]->name, arr[i]->ban, arr[i]->id, arr[i]->kor, arr[i]->eng, arr[i]->math, arr[i]->score.sum, arr[i]->score.avg, arr[i]->score.rank);

}

void calcStudent(STU** arr, int pos) {

        for(int i=0;i<pos;i++) {
        arr[i]->score.sum = arr[i]->kor + arr[i]->eng + arr[i]->math;
        arr[i]->score.avg = arr[i]->score.sum  / 3.0;
    }
}
void sortArr(STU** arr, int pos) {
    int i, j;
    STU tmp;
    for(i=0;i<pos-1;i++)
        for(j=0;j<pos-i-1;j++)
            if(arr[j]->score.sum<arr[j+1]->score.sum) {
                tmp = *arr[j];
                *arr[j] = *arr[j+1];
                *arr[j+1] = tmp;
            }

    for(i=0;i<pos;i++)
        arr[i]->score.rank = i+1;
}



