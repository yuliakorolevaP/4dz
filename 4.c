#include<stdio.h> 
#include<string.h> 
#include <stdlib.h> 
#define N 100

void qs(int *Arr, int *c, int first, int last) 
{ 
	if (first < last) 
	{ 
		int left = first, right = last, middle = Arr[(left + right) / 2]; 
			do 
		{ 
			while (Arr[left] < middle) left++; 
			while (Arr[right] > middle) right--; 
			if (left <= right) 
			{ int time = Arr[left]; 
				Arr[left] = Arr[right]; 
				Arr[right] = time; 
				int ttime = c[left]; 
				c[left] = c[right]; 
				c[right] = ttime; 
				left++; 
				right--; 
			} 
		} 
		while (left <= right); 
			qs(Arr, c, first, right); 
		qs(Arr, c, left, last); 
	} 
}


int main(void) 
{ 
int versh,rebr,cnt,i,j,a; 
char a1,b1; 
FILE *f; 
f=fopen("graph.gv","w"); 
fputs("graph G {\n",f); 

printf("Enter znach verchin:\n"); 
scanf("%d", &versh); 
printf("Enter znach reber:\n"); 
scanf("%d", &rebr); 
int arr[versh][versh]; 

printf("Vvedite:\n\t0:net rebra\n\t1:est' rebro\n\n"); 
for( j=0; j<versh; j++){ 
	a1='A'; 
	b1='A'; 
	a1=a1+j; 
	for(i=0; i<versh; i++){ 
		printf("%d vershina v %d vershinu: ", j+1,i+1); 
		scanf("%d", &a); 
		if (arr[j][i]!=1){ 
			if (a==1){ 
				arr[j][i] =arr[i][j]= 1; 
				fprintf(f,"%c--%c;\n",a1,b1); 
				} 
			if (a==0){ 
				arr[j][i]=0; 
				}
			} 
		b1++; 
		} 
	} 
for( j=0; j<versh; j++){ 
	a1='A'; 
	b1='A'; 
	a1=a1+j; 
	cnt=0; 
	for(i=0; i<versh; i++){ 
		if (arr[j][i]==0) 
			cnt++; 
			if (cnt==versh) { 
				fprintf(f,"%c\n",b1); 
				} 
			b1++; 
		} 
	} 
	
	
printf("\n\tMatritsa smejnosti:\n"); 
for( i=0; i<versh; i++){ 
	printf("\t"); 
	for( j=0; j<versh; j++){ 
		printf("%2d ", arr[j][i]); 
		} 
	printf("\n"); 
	} 
fputs("}",f); 
fclose(f); 

int c=0, k=0, n;

for( i=0; i<versh; i++){ 
	for( j=0; j<versh; j++){ 
		c=arr[i][j]+c;
		}
	if(c%2!=0){
		k++;	
		}
	c=0;
	}
 
n=k;
int A[n], C[n];
k=0;
for( i=0; i<versh; i++){ 
	for( j=0; j<versh; j++){ 
		c=arr[i][j]+c;
		}
	if((c%2!=0)){
		A[k]=i+1; 
		C[k]=c;
		k++;	
		}
	c=0;
	}
qs(C, A, 0, k-1);
for (i = 0; i<n; i++)
        printf("versh %4d (%d)", A[i], C[i]);
return 0; 
}
