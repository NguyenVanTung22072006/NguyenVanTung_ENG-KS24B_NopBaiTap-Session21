#include <stdio.h>

int main(){
    FILE *fptr;
    char chuDauTien;

    fptr=fopen("bt01.txt","r");
    if(fptr==NULL){
        printf("Khong the mo file\n");
        return 1;
    }
    chuDauTien=fgetc(fptr);
    printf("Ky tu dau tien trong file la: %c\n", chuDauTien);
    fclose(fptr);
    
    return 0;
}
