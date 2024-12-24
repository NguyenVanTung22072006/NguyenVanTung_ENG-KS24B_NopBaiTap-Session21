#include <stdio.h>

int main(){
    FILE *fptr01, *fptr06;
    char ch;
    fptr01=fopen("bt01.txt", "r");
    if(fptr01==NULL){
        printf("Khong the mo file bt01.txt\n");
        return 1;
    }
    fptr06=fopen("bt06.txt", "w");
    if(fptr06==NULL){
        printf("Khong the tao file bt06.txt\n");
        fclose(fptr01);
        return 1;
    }
    while((ch=fgetc(fptr01))!=EOF){
        fputc(ch, fptr06);
    }
    fclose(fptr01);
    fclose(fptr06);

    return 0;
}
