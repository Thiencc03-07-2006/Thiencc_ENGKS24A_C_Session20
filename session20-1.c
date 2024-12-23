#include <stdio.h>
#include <string.h>

struct Library{
	int bookCode;
	char bookTitle[50];
	char author[50];
	float price;
};

void numbersAndInfo();

void printInfo();

void addBook();

void deleteBook();

void updateBook();

void sortBook();

void findBook();

int main(){
	struct Library books[50];
	int type,n,check=0;
	do{
		printf("\nMENU\n");
		printf("1. Nhap so luong va thong tin sach\n");
		printf("2. Hien thi thong tin sach\n");
		printf("3. Them sach vao vi tri\n");
		printf("4. Xoa sach theo ma sach\n");
		printf("5. Cap nhat thong tin theo ma sach\n");
		printf("6. Sap xep sach theo gia\n");
		printf("7. Tim kiem theo ten sach\n");
		printf("8. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d",&type);
		fflush(stdin);
		switch(type){
			case 1:
				numbersAndInfo(books,&n);
				check=-1;
				break;
			case 2:
				if(check){
					printInfo(books,n);
				}
				break;
			case 3:
				if(check){
					addBook(books,&n);
				}
				break;
			case 4:
				if(check){
					deleteBook(books,&n);
				}
				break;
			case 5:
				if(check){
					updateBook(books,n);
				}
				break;
			case 6:
				if(check){
					sortBook(books,n);
				}
				break;
			case 7:
				if(check){
					findBook(books,n);
				}
				break;
		}
	}while(type!=8);
	return 0;
}

void numbersAndInfo(struct Library books[],int *n){
	printf("vui long nhap so luong sach: ");
	scanf("%d",n);
	fflush(stdin);
	int i=0;
	while(i<*n){
		printf("vui long nhap ma sach: ");
		scanf("%d",&(books[i].bookCode));
		fflush(stdin);
		printf("	vui long nhap ten sach: ");
		fgets(books[i].bookTitle,sizeof books[i].bookTitle,stdin);
		books[i].bookTitle[strcspn(books[i].bookTitle,"\n")]='\0';
		printf("	vui long nhap tac gia: ");
		fgets(books[i].author,sizeof books[i].author,stdin);
		books[i].author[strcspn(books[i].author,"\n")]='\0';
		printf("	vui long nhap gia sach: ");
		scanf("%f",&(books[i].price));
		fflush(stdin);
		i++;
	}
}

void printInfo(struct Library books[],int n){
	int i=0;
	while(i<n){
		printf("Ma sach: %d\n",books[i].bookCode);
		printf("	Ten sach: %s\n",books[i].bookTitle);
		printf("	Tac gia: %s\n",books[i].author);
		printf("	Gia sach: %.2f\n",books[i].price);
		i++;
	}
}

void addBook(struct Library books[],int *n){
	int index;
	printf("vui long nhap vi tri muon chen sach(1->%d): ",*n);
	scanf("%d",&index);
	if(index>0&&index<=*n){
		index--;
		int i=0;
		while(*n-i>index){
			books[*n-i]=books[*n-i-1];
			i++;
		}
		printf("vui long nhap ma sach: ");
		scanf("%d",&(books[index].bookCode));
		fflush(stdin);
		printf("	vui long nhap ten sach: ");
		fgets(books[index].bookTitle,sizeof books[index].bookTitle,stdin);
		books[index].bookTitle[strcspn(books[index].bookTitle,"\n")]='\0';
		printf("	vui long nhap tac gia: ");
		fgets(books[index].author,sizeof books[index].author,stdin);
		books[index].author[strcspn(books[index].author,"\n")]='\0';
		printf("	vui long nhap gia sach: ");
		scanf("%f",&(books[index].price));
		fflush(stdin);
		(*n)++;
	}
}

void deleteBook(struct Library books[],int *n){
	int index,i=0,j;
	printf("vui long nhap ma muon xoa: ");
	scanf("%d",&index);
	while(i<*n){
		if(index==books[i].bookCode){
			j=i;
			while(j<*n-1){
				books[j]=books[j+1];
				j++;
			}
			(*n)--;
		}
		i++;
	}
}

void updateBook(struct Library books[],int n){
	int index;
	printf("vui long nhap vi tri muon thay doi(1->%d): ",n);
	scanf("%d",&index);
	if(index>0&&index<=n){
		index--;
		printf("vui long nhap ma sach: ");
		scanf("%d",&(books[index].bookCode));
		fflush(stdin);
		printf("	vui long nhap ten sach: ");
		fgets(books[index].bookTitle,sizeof books[index].bookTitle,stdin);
		books[index].bookTitle[strcspn(books[index].bookTitle,"\n")]='\0';
		printf("	vui long nhap tac gia: ");
		fgets(books[index].author,sizeof books[index].author,stdin);
		books[index].author[strcspn(books[index].author,"\n")]='\0';
		printf("	vui long nhap gia sach: ");
		scanf("%f",&(books[index].price));
		fflush(stdin);
	}
}

void sortBook(struct Library books[],int n){
	struct Library save;
	int i=0,j,choose;
	printf("	1. sap xep tang dan\n");
	printf("	2. sap xep giam dan\n");
	printf("Lua chon cua ban: ");
	scanf("%d",&choose);
	fflush(stdin);
    while(i<n-1){
    	j=i+1;
        while(j<n){
            if((choose==1&&books[i].price>books[j].price)||(choose==2&&books[i].price<books[j].price)){
                save=books[i];
                books[i]=books[j];
                books[j]=save;
            }
            j++;
        }
        i++;
    }
}

void findBook(struct Library books[],int n){
	char name[50];
	printf("vui long nhap ten mon can tim: ");
	fgets(name,sizeof name,stdin);
	name[strcspn(name,"\n")]='\0';
	int i=0;
	while(i<n){
		if(strcmp(books[i].bookTitle,name)==0){
			printf("Ma sach: %d\n",books[i].bookCode);
			printf("	Ten sach: %s\n",books[i].bookTitle);
			printf("	Tac gia: %s\n",books[i].author);
			printf("	Gia sach: %.2f\n",books[i].price);
		}
		i++;
	}
}
