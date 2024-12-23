#include <stdio.h>
#include <string.h>

struct Shop{
	int productCode;
	char productName[50];
	float importPrice;
	float sellingPrice;
	int numbers;
};

void numbersAndInfo();

void printInfo();

void addProduct();

void updateProduct();

void sortProduct();

void findProduct();

void sellProduct();

void cash(float money);

int main(){
	struct Shop products[50];
	int type,n,check=0;
	float money=0;
	do{
		printf("\nMENU\n");
		printf("1. Nhap so luong va thong tin san pham\n");
		printf("2. Hien thi danh sach san pham\n");
		printf("3. Nhap san pham\n");
		printf("4. Cap nhat thong tin san pham\n");
		printf("5. Sap xep san pham theo gia\n");
		printf("6. Tim kiem san pham\n");
		printf("7. Ban san pham\n");
		printf("8. Danh thu hien tai\n");
		printf("9. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d",&type);
		fflush(stdin);
		switch(type){
			case 1:
				numbersAndInfo(products,&n);
				check=-1;
				break;
			case 2:
				if(check){
					printInfo(products,n);
				}
				break;
			case 3:
				if(check){
					addProduct(products,&n,&money);
				}
				break;
			case 4:
				if(check){
					updateProduct(products,n);
				}
				break;
			case 5:
				if(check){
					sortProduct(products,n);
				}
				break;
			case 6:
				if(check){
					findProduct(products,n);
				}
				break;
			case 7:
				if(check){
					sellProduct(products,n,&money);
				}
				break;
			case 8:
				if(check){
					cash(money);
				}
				break;
		}
	}while(type!=9);
	return 0;
}

void numbersAndInfo(struct Shop products[],int *n){
	printf("vui long nhap so luong mat hang: ");
	scanf("%d",n);
	fflush(stdin);
	int i=0;
	while(i<*n){
		printf("vui long nhap ma san pham: ");
		scanf("%d",&(products[i].productCode));
		fflush(stdin);
		printf("	vui long nhap ten san pham: ");
		fgets(products[i].productName,sizeof products[i].productName,stdin);
		products[i].productName[strcspn(products[i].productName,"\n")]='\0';
		printf("	vui long nhap gia nhap: ");
		scanf("%f",&(products[i].importPrice));
		fflush(stdin);
		printf("	vui long nhap gia ban: ");
		scanf("%f",&(products[i].sellingPrice));
		fflush(stdin);
		printf("	vui long nhap so luong: ");
		scanf("%d",&(products[i].numbers));
		fflush(stdin);
		i++;
	}
}

void printInfo(struct Shop products[],int n){
	int i=0;
	while(i<n){
		printf("Ma san pham: %d\n",products[i].productCode);
		printf("	Ten san pham: %s\n",products[i].productName);
		printf("	Gia nhap: %.2f\n",products[i].importPrice);
		printf("	Gia ban: %.2f\n",products[i].sellingPrice);
		printf("	So luong: %d\n",products[i].numbers);
		i++;
	}
}

void addProduct(struct Shop products[],int *n,int *money){
	int index,i=0,more;
	printf("vui long nhap ma san pham: ");
	scanf("%d",&index);
	fflush(stdin);
	while(i<*n){
		if(products[i].productCode==index){
			printf("	vui long nhap so luong hang nhap vao: ");
			scanf("%d",&more);
			fflush(stdin);
			*money-=more*products[i].importPrice;
			products[i].numbers+=more;
			return;
		}
		i++;
	}
	printf("vui long nhap ma san pham: ");
	scanf("%d",&(products[*n].productCode));
	fflush(stdin);
	printf("	vui long nhap ten san pham: ");
	fgets(products[*n].productName,sizeof products[*n].productName,stdin);
	products[*n].productName[strcspn(products[*n].productName,"\n")]='\0';
	printf("	vui long nhap gia nhap: ");
	scanf("%f",&(products[*n].importPrice));
	fflush(stdin);
	printf("	vui long nhap gia ban: ");
	scanf("%f",&(products[*n].sellingPrice));
	fflush(stdin);
	printf("	vui long nhap so luong: ");
	scanf("%d",&(products[*n].numbers));
	fflush(stdin);
	(*n)++;
	
}
void updateProduct(struct Shop products[],int n){
	int index;
	printf("vui long nhap vi tri muon thay doi(1->%d): ",n);
	scanf("%d",&index);
	fflush(stdin);
	if(index>0&&index<=n){
		index--;
		printf("vui long nhap ma san pham: ");
		scanf("%d",&(products[index].productCode));
		fflush(stdin);
		printf("	vui long nhap ten san pham: ");
		fgets(products[index].productName,sizeof products[index].productName,stdin);
		products[index].productName[strcspn(products[index].productName,"\n")]='\0';
		printf("	vui long nhap gia nhap: ");
		scanf("%f",&(products[index].importPrice));
		fflush(stdin);
		printf("	vui long nhap gia ban: ");
		scanf("%f",&(products[index].sellingPrice));
		fflush(stdin);
		printf("	vui long nhap so luong: ");
		scanf("%d",&(products[index].numbers));
		fflush(stdin);
	}
}

void sortProduct(struct Shop products[],int n){
	struct Shop save;
	int i=0,j,choose;
	printf("	1. sap xep tang dan\n");
	printf("	2. sap xep giam dan\n");
	printf("Lua chon cua ban: ");
	scanf("%d",&choose);
	fflush(stdin);
    while(i<n-1){
    	j=i+1;
        while(j<n){
            if((choose==1&&products[i].sellingPrice>products[j].sellingPrice)||(choose==2&&products[i].sellingPrice<products[j].sellingPrice)){
                save=products[i];
                products[i]=products[j];
                products[j]=save;
            }
            j++;
        }
        i++;
    }
}

void findProduct(struct Shop products[],int n){
	char name[50];
	printf("vui long nhap ten mon can tim: ");
	fgets(name,sizeof name,stdin);
	name[strcspn(name,"\n")]='\0';
	int i=0;
	while(i<n){
		if(strcmp(products[i].productName,name)==0){
			printf("Ma san pham: %d\n",products[i].productCode);
			printf("	Ten san pham: %s\n",products[i].productName);
			printf("	Gia nhap: %.2f\n",products[i].importPrice);
			printf("	Gia ban: %.2f\n",products[i].sellingPrice);
			printf("	So luong: %d\n",products[i].numbers);
		}
		i++;
	}
}

void sellProduct(struct Shop products[],int n,int *money){
	int index,i=0,sell;
	printf("vui long nhap ma san pham: ");
	scanf("%d",&index);
	fflush(stdin);
	while(i<n){
		if(products[i].productCode==index){
			printf("	vui long nhap so luong hang ban ra: ");
			scanf("%d",&sell);
			fflush(stdin);
			if(products[i].numbers<sell){
				if(products[i].numbers==sell){
					printf("gio mat hang da het");
				}
				*money+=sell*products[i].sellingPrice;
				products[i].numbers-=sell;
				return;
			}
			printf("hang khong du vui long nhap them");
			return;
		}
		i++;
	}
}

void cash(float money){
	printf("so tien hien co: %f",money);
}
