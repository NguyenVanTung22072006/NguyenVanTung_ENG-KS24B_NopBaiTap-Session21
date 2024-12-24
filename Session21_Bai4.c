#include <stdio.h>

int main (){
    FILE *fptr;
    char line[500];
    fptr=fopen("bt01.txt", "r");
    if(fptr==NULL){
        printf("Khong the mo file\n");
        return 1;
    }
    if(fgets(line, sizeof(line), fptr) != NULL){
        printf("Dong dau tien trong file la: %s", line);
    }else{
        printf("File rong\n");
    }
    fclose(fptr);

    return 0;
}
