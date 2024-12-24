#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien{
    int id;
    char name[100];
    int age;
};
int main (){
    FILE *fptr;
    int n, i;
    struct SinhVien *sv;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    sv=(struct SinhVien *)malloc(n * sizeof(struct SinhVien));
    if(sv==NULL){
        printf("Khong du bo nho\n");
        return 1;
    }
    for(i=0; i<n; i++){
        printf("Nhap thong tin sinh vien thu %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &sv[i].id);
        getchar();
        fflush(stdin);
        printf("Name: ");
        fgets(sv[i].name, sizeof(sv[i].name), stdin);
        sv[i].name[strcspn(sv[i].name, "\n")]='\0';
        fflush(stdin);
        printf("Age: ");
        scanf("%d", &sv[i].age);
    }
    fptr=fopen("students.txt", "w");
    if(fptr==NULL){
        printf("Khong the tao file\n");
        free(sv);
        return 1;
    }
    for(i=0; i<n; i++){
        fprintf(fptr, "%d, %s, %d\n", sv[i].id, sv[i].name, sv[i].age);
    }
    fclose(fptr);
    free(sv);

    return 0;
}
