#include <stdio.h>

struct Book {
    char id[10];
    char name[100];
    char tacGia[100];
    double price;
    char theLoai[50];
};

void inputBooks(struct Book books[], int *n);
void saveBooks(struct Book books[], int n);
void loadBooks(struct Book books[], int *n);
void displayBooks(struct Book books[], int n);

int main(){
	struct Book books[100];
    int n=0;
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice){
            case 1:
                inputBooks(books, &n);
                break;
            case 2:
                saveBooks(books, n);
                break;
            case 3:
                loadBooks(books, &n);
                break;
            case 4:
                displayBooks(books, n);
                break;
            case 5:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    }while(choice!=5);
	
	return 0;
}
void inputBooks(struct Book books[], int *n){
    printf("Nhap so luong sach: ");
    scanf("%d", n);
    getchar();
    for(int i=0; i<*n; i++){
        printf("Nhap thong tin sach thu %d:\n", i+1);
        printf("Ma sach: ");
        fgets(books[i].id, sizeof(books[i].id), stdin);
        books[i].id[strcspn(books[i].id, "\n")] = '\0';
        fflush(stdin);
        printf("Ten sach: ");
        fgets(books[i].name, sizeof(books[i].name), stdin);
        books[i].name[strcspn(books[i].name, "\n")] = '\0';
        fflush(stdin);
        printf("Tac gia: ");
        fgets(books[i].tacGia, sizeof(books[i].tacGia), stdin);
        books[i].tacGia[strcspn(books[i].tacGia, "\n")] = '\0';
        fflush(stdin);
        printf("Gia tien: ");
        scanf("%lf", &books[i].price);
        getchar();
        fflush(stdin);
        printf("The loai: ");
        fgets(books[i].theLoai, sizeof(books[i].theLoai), stdin);
        books[i].theLoai[strcspn(books[i].theLoai, "\n")] = '\0';
    }
}
void saveBooks(struct Book books[], int n){
    FILE *file;
	file=fopen("books.bin", "wb");
    if(file == NULL){
        printf("Khong the mo file\n");
        return 1;
    }
    fwrite(books, sizeof(struct Book), n, file);
    fclose(file);
}
void loadBooks(struct Book books[], int *n){
    FILE *file;
	file=fopen("books.bin", "rb");
    if(file==NULL){
        printf("Khong the mo file\n");
        return 1;
    }
    *n=fread(books, sizeof(struct Book), 100, file);
    fclose(file);
}
void displayBooks(struct Book books[], int n){
    if(n==0){
        printf("Danh sach sach trong\n");
        return 1;
    }
    printf("Danh sach cac sach:\n");
    for(int i=0; i<n; i++){
        printf("Ma sach: %s\n", books[i].id);
        printf("Ten sach: %s\n", books[i].name);
        printf("Tac gia: %s\n", books[i].tacGia);
        printf("Gia tien: %.0f\n", books[i].price);
        printf("The loai: %s\n\n", books[i].theLoai);
    }
}

