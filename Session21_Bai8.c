#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien{
    int id;
    char name[100];
    int age;
};
int main(){
    FILE *fptr;
    struct SinhVien sv[100];
    int count=0;
    fptr=fopen("students.txt", "r");
    if(fptr==NULL){
        printf("Khong the mo file students.txt\n");
        return 1;
    }
    while (fscanf(fptr, "%d, %[^,], %d\n", &sv[count].id, sv[count].name, &sv[count].age) == 3){
        count++;
    }
    fclose(fptr);
    printf("Danh sach sinh vien:\n");
    for(int i=0; i<count; i++){
        printf("ID: %d, Name: %s, Age: %d\n", sv[i].id, sv[i].name, sv[i].age);
    }

    return 0;
}
