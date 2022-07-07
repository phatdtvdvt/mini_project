//Gauss Elimination
#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
float a[100][101], x[100]; 
int n,m;
using namespace std;
void SET_COLOR(int color)
{
	WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
void sortt(int n, float a[][101], int m){
	for (int i=1;i<=n;i++)                    
        for (int k=i+1;k<=n;k++)
            if (fabs(a[i][i])<fabs(a[k][i]))
                for (int j=1;j<=m;j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
}
void output(int n, float a[][101], int m){
	for (int i=1;i<=n;i++)            
    {
        for (int j=1;j<=m;j++)
            printf("%10.4f", a[i][j]);
        printf("\n");
    }    
}
void solve1(int n, float a[][101], int m){
    for (int i=1;i<=n-1;i++){
	    for (int k=i+1;k<=n;k++)
            {
                double t=a[k][i]/a[i][i];
                for (int j=1;j<=m;j++)
                    a[k][j]=a[k][j]-t*a[i][j];    
			}
    }
}
void solve2(int n, float a[][101], float x[], int m){
	 for (int i=n;i>=1;i--)                
    {                        
        x[i]=a[i][m];                
        for (int j=i+1;j<m;j++)
            if (j!=i)            
                x[i]=x[i]-a[i][j]*x[j];
        x[i]=x[i]/a[i][i];            
    }
}
void delete_row(int n,float a[][101],int k, int m){
	for(int i=k;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=a[i+1][j];
		}
	}	
}
int test(float a[][101],int n){
	for(int i=1;i<=n;i++){
		if(a[i][i]==0) return 0;		
	}
	return 1;
}
int main(){
	m=0;
	int i,j,k;
	int finish;
	int chucnang;
	cout.precision(4);        
    cout.setf(ios::fixed);
    char tenfile[50];
   	do{
	SET_COLOR(6);
	printf("NHOM 8\t\t\t|\n1.Tran Thi Huynh Linh   |\n2.Pham Nguyen Anh Phat  |\nLop SH: 21TCLC_KHDL\t|\nDO AN CO SO NGANH:\t|\n________________________|\n\n\n");
	printf("\t\t\t\t<GIAI HE PHUONG TRINH BANG PHUONG PHAP GAUSS>\n\t\t\t-----------------------------------------------------------\n");
	SET_COLOR(14);
	printf("\t1.Doc du lieu tu file chua ma tran vuong ma ban muon tinh.\n");
	printf("\t2.Xuat ra ma tran vua doc tu file.\n");
	printf("\t3.Xoa 1 hang va giai he phuong trinh tu ma tran moi.\n");
	printf("\t4.Xuat nghiem ra file .\n");
	printf("\t5.Ket thuc chuong trinh.\n");
	SET_COLOR(3);
	printf("\n\tNhap lenh ban muon thuc hien: ");
	scanf("%d",&chucnang);
		if(chucnang==1)
			{
				printf("\n\tNhap file can doc du lieu:"); scanf("%s",tenfile);
				FILE *f0;
					f0=fopen(tenfile,"r");
					if(f0==NULL){
						printf("\n\tBan chua tao file nay\n");
						exit(1);
					}
					fscanf(f0,"%d",&m);
					for(int i=1;i<=m;i++){
						for(int j=1;j<=m;j++){
							fscanf(f0,"%f",&a[i][j]);
						}
					}
				fclose(f0);
				SET_COLOR(12);	
				printf("\n\tNhan enter de tiep tuc.");
				getch();
				system("cls");				
			}
		else if(chucnang==2)
			{
				SET_COLOR(11);
				if(m==0) printf("\n\tChua co ma tran dau vao\n");
				else {
					printf("\n\tMa tran doc tu file la: \n");
					output(m,a,m);
				}
				SET_COLOR(12);
				printf("\n\tNhan enter de tiep tuc.");
				getch();
				system("cls");			
			}
		else if(chucnang==3)
			{
				SET_COLOR(11);
				if(m==0){ 
					printf("\n\tChua co du lieu ma tran dau vao");
					SET_COLOR(12);
					printf("\n\tNhan enter de tiep tuc.");	
				}
				else{
					printf("\n\tNhap hang ma ban muon xoa: "); scanf("%d",&k);
					while(k>m||k<1){
						printf("\n\tHang ban nhap khong hop le, hay nhap lai!: ");
						scanf("%d",&k);
					}
					n=m-1;
					delete_row(n,a,k,m);
					printf("\n\tMa tran sau khi xoa hang:\n");
					output(n,a,m);
					sortt(n,a,m);
					printf("\n\tMa tran sau khi sap xep la: \n");
					output(n,a,m);
					printf("\n\tMa tran tam giac tren sau khi bien doi la:\n");
			   		solve1(n,a,m);
					output(n,a,m);
					printf("\n\tNghiem cua he sau khi giai bang phuong phap Gauss la:\n");
    				solve2(n,a,x,m);
					if(test(a,n)==1){
						for(int i=1;i<=n;i++){
							printf("\tx%d = %0.3f\n",i,x[i]);
						}
						SET_COLOR(12);
	    				printf("\n\tNhan enter de tiep tuc.");
	    			}
					else{
	    				printf("\n\t==> He phuong trinh khong co nghiem doc lap");
	    				SET_COLOR(12);
	    				printf("\n\tNhan enter de tiep tuc.");
					}
				}
				getch();
				system("cls");
			}		
		else if(chucnang==4)
			{
				FILE *f1;
					f1=fopen("DATA.OUT","w");
					if(m==0) printf("\n\tBan chua nhap ma tran de giai");					
					else if(test(a,n)==0){
							printf("\t==> phuong trinh khong co nghiem doc lap.");
						}else{
							for(int i=1;i<=n;i++){
							fprintf(f1,"x%d = %0.3f\n",i,x[i]);
							}
							printf("\n\tNghiem da duoc luu vao file");
						}
				fclose(f1);
				SET_COLOR(12);
				printf("\n\tNhan enter de tiep tuc.");
				getch();
				system("cls");	
			}
		else if(chucnang==5)
			{
				SET_COLOR(13);
				printf("\t\t\t\t KET THUC!");
				finish=0;
			}
		else{
			printf("\n\tban da nhap sai chuc nang, xin nhap lai!.");
			printf("\n\tNhan enter de nhap lai chuc nang.");
			getch();
			system("cls");
		}
	}while(chucnang!=5);  
return 0;
}






