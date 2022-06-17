#include<stdio.h>
int size(char* arr);
int cal(char* arr,int size);
int bit=0;
int k=0;
char* decal(int num);
int main(){
	char num[4][50] = {' '};
	int si[4]={0},sum[4]={0},differ[2];
	
	for(int i=0;i<4;i++){
		scanf("%s",num[i]);
		si[i]=size(&num[i][0]);
		sum[i]=cal(&num[i][0],si[i]);
	}
	differ[0] = (sum[1]-sum[0]>0?sum[1]-sum[0]:sum[0]-sum[1]);
	differ[1] = (sum[3]-sum[2]>0?sum[3]-sum[2]:sum[2]-sum[3]);
	char *p[2];
	for(int i=0;i<2;i++){
		p[i]=decal(differ[i]);
		if(differ[i]==0){
			printf("ZERO\n");
		}
		else {
			puts(p[i]);			
		}
	}
} 
int size(char* arr){
	int i=0;
	while(arr[i]!=0){
		i++;
	}
	return i;
}
int cal(char* arr,int size){
	int sum=0;
	int equal[size];
	for(int i=0;i<size;i++){
		switch(arr[i]){
			case 'I':
				equal[i]=1;
				break;
			case 'V':
				equal[i]=5;
				break;
			case 'X':
				equal[i]=10;
				break;
			case 'L':
				equal[i]=50;
				break;
			case 'C':
				equal[i]=100;
				break;
			case 'D':
				equal[i]=500;
				break;
			case 'M':
				equal[i]=1000;
				break;
			default:
				equal[i]=1;
				
		}
	}
	sum=equal[size-1];
	for(int i=size-1;i>=1;i--){
		if(equal[i-1]>=equal[i]){
			sum+=equal[i-1];
		}
		else sum-=equal[i-1];
	}
	return sum;
}
char *decal(int num){
	char arr[100];
	bit=0;
	while(num!=0){
		if(num/1000>=1){
			arr[bit]='M';
			num-=1000;
		}
		else if(num/500>=1){
			arr[bit]='D';
			num-=500;
		}
		else if(num/100>=1){
			arr[bit]='C';
			num-=100;
		}else if(num/50>=1){
			arr[bit]='L';
			num-=50;
		}
		else if(num/10>=1){
			arr[bit]='X';
			num-=10;
		}
		else if(num/5>=1){
			arr[bit]='V';
			num-=5;
		}
		else {
			arr[bit]='I';
			num-=1;
		}
		bit++;
	}
	for(int i=0;i<bit;i++){
		if((arr[i]==arr[i+1])&&(arr[i+1]==arr[i+2])&&(arr[i+2]==arr[i+3]))
			{
				k++;
				switch(arr[i]){
					case 'D':
						arr[i+1]='M';
						break;
					case 'C':
						arr[i+1]='D';
						break;	
					case 'L':
						arr[i+1]='C';
						break;	
					case 'X':
						arr[i+1]='L';
						break;	
					case 'V':
						arr[i+1]='X';
						break;	
					default:
						arr[i+1]='V';
						break;		
				}
				arr[i+2]=' ';
				arr[i+3]=' ';		
			}
	}
	for(int i=0;i<bit;i++){
		if(arr[i]==' '){
			for(int j=i;j<bit-2;j++){
				arr[j]=arr[j+2];
				arr[j+1]=arr[j+3];
			}
		}
	}
	char *p=arr;
	return p;
}
