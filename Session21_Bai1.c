#include <stdio.h>

int main (){
	char arr[500];
	FILE *fptr;
	fptr= fopen("bt01.txt", "w");
	    if(fptr==NULL){
        printf("Khong the mo file\n");
        return 1;
    }
	printf("Nhap mot chuoi bat ki: ");
	fgets(arr, sizeof(arr), stdin);
	fprintf(fptr, "%s", arr);
	fclose(fptr);
	
	return 0;
}
