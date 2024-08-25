#include <stdio.h>
#include <string.h>

//H�m n�y vi�'t ph�p c�.ng 
void sum2number(char a[], char b[]){
	//tao. 1 array de? luu kq 
	char sum[51];
	//Khoi tao cac gia tri can su dung 
	int la, lb, i, j, k, c = 0,s;
	//Lay chieu dai cua 2 chuoi ki tu
	la = strlen(a);
	lb = strlen(b);
	//Lay do dai cua day so nguyen
	i = la-1;
	j = lb-1;
	//tao mot gia tri k de luu do dai chuoi dai  
	k = la > lb ? la : lb;
	//Dat gia tri cuoi cung cua chuoi kqua bang gia tri /0
	sum[k] = '\0';
	//Giam gia tri cua k
	k--;
	//tao 1 vong lap de thuc hien phep cong cho den khi 1 trong 2 chuoi ban dau bang 0
	while(i >=0 && j >= 0){
		//Dua gia tri cuoi cua moi chuoi ve so nguyen xong thuc hien phep cong
		s = (a[i] -'0') + (b[j] - '0') + c;
		//Gan gia tri cuoi cung cua phep cong vao o thu k cua ket qua
		sum[k] = s%10 + '0';
		//Tinh gia tri con du c;
		c = s/10;
		//Giam vi tri cua moi chuoi di 1
		i--;
		j--;
		k--;
	}
	//Neu 1 trong 2 chuoi ban dau con do dai
	if(i >= 0){
		//tao vong lap den khi chuoi do ket thuc
		while(i >=0){
		//Thuc hien phep cong voi gia tri du
		s= (a[i] - '0') + c;
		//Gan gia tri vao o ket qua
		sum[k] = s%10 + '0';
		//Tinh gia tri con du c;
		c = s/10;
		//Giam vi tri cua chuoi di 1
		i--;
		k--;
		}
	}
	//Neu hang 2 du thi tuong tu
	if(j >= 0){
		while(j>= 0){
		s= (b[j] - '0') + c;
		sum[k] = s%10 + '0';
		c = s/10;
		j--;
		k--;
		}
	}
	//Giai quyet trg hop dac biet neu c du
	if(c > 0){
		//Tao vong lap chay tu cuoi len dau chuoi ket qua
		for(k = strlen(sum); k >=0; k--){
			//Gan gia tri cua chuoi kq sang 1 o
			sum[k+1] = sum[k];
		}
		//Gan gia tri du c vo vao dau chuoi
		sum[0] = c + '0';
	}
	//In chuoi kq 
	printf("%s", sum);
}
int isLarger(char a[], char b[]){
	int la, lb,i;
	la = strlen(a);
	lb = strlen(b);
	if(la > lb)
		return 1;
	if(lb > la)
		return 2;
	for(i = 0; i < la;i++){
		if(a[i] > b[i])
			return 1;
		if(a[i] < b[i])
			return 2;
	}
	return 0;
}
void subtract(char a[], char b[]){
	int la, lb, i, j, k, c = 0, s;
	la = strlen(a);
	lb = strlen(b);
	char sub[51];
	i = la -1;
	j = lb -1;
	k = la;
	sub[k] = '\0';
	k--;
	while(i>= 0 && j >=0){
		s = ((a[i] - '0') - (b[j] - '0') - c);
		
		if (s < 0) {
			s = s + 10 ;
			c = 1;
		}
		else
			c = 0;
			
		sub[k] = s +'0';
		i--;
		j--;
		k--;
	}
	if(i >= 0){
		while(i >=0){
		s= (a[i] - '0') - c;
		if (s < 0) {
			s = s + 10 ;
			c = 1;
		}
		else
			c = 0;
		sub[k] = s + '0';
		i--;
		k--;
		}
	}
	printf("%s",sub);
}

void mul2number(char a[],char b[]){
		char kq[250],product[101], ans[101];
	int la, lb, i, j, shift, k, k1, k2, c, pro, sum, n =0 ; 
	la = strlen(a);
	lb = strlen(b);
	
	for(j = lb - 1; j > 0; j--){
		
		if(b[j]=='-'){
               break;
        }
        
		shift = lb - 1 - j;
		c = 0;
		
		for( i = 0; i < la + lb; i++){
			product[i] = 0;
		}
		
		k1 = b[j] - '0';
		
		for(i = la-1, k = la + lb -1 - shift; i>= 0; i--,k--){
			if(a[i]=='-'){
                   break;
            }
			k2 = a[i] - '0';
			pro = k1 * k2 + c;
			
			if(pro > 10){
				product[k] = pro % 10;
				pro = pro / 10;
				c = pro;
			} else {
				product[k] = pro ;
				c = 0;
			}
		}
		
		if (c > 0){
			product[k] = c;
		}
		
		c = 0;
		for(i=la+lb-1; i>=0; i--)
           {
               sum=product[i]+ans[i]+c;
               
               if(sum>=10){
                   ans[i]=(sum%10);
                   sum=sum/10;
                   c=sum;
               }else{
                   ans[i]=sum;
                   c=0;
               }
           }
	}
	
	i = 0;
	while(ans[i] == 0){
		i++;
	}
	
	 if(a[0]=='-' && b[0]!='-'){
           kq[n] =('-');
           n++;
       }else if(a[0]!='-' && b[0]=='-'){
           kq[n] =('-');
           n++;
       }
    
	for(;i<la+lb; i++, n++)
       {
           kq[n]= ans[i]+ '0';
       }
    printf("%s",kq);
}

int main(){
	//Tao 2 array de luu gia tri 2 chuoi a,b
	char a[50], b[50];
	//Nhap tu ban phim vao 2 chuoi a,b
	printf("Type the first number: ");
	scanf("%s",a);
	printf("\n");
	printf("Type the second number:");
	scanf("%s",b);
	printf("\n");
	//Truyen gia tri cho ham phep cong
	sum2number(a,b);
	printf("\n");
	if(isLarger(a,b) == 1){
		subtract(a,b);
	}
	else if(isLarger(a,b) == 2){
		subtract(b,a);
	}
	else
		printf("0");
	printf("\n");
	mul2number(a,b);
}
