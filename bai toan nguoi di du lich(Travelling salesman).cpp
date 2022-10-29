#include <stdio.h>
//#include<stdlib.h>
#include <Windows.h> 
int d[30] = {}, s = 0, c[20][20] = {},min = 0;
int Try(int a[],int i,int n){
	if(i == n+1 && c[1][a[i-1]] != 0 && min>= s+c[1][a[i-1]]){
		system("cls"); 
		min = s + c[1][a[i-1]];
		printf("\n");
		for(int j = 1;j<= n;j++)
			printf("%d -->",a[j]);
		printf("1");
	
		return 1; 
	}
	for(a[i] = 1;a[i]<= n;a[i]++){
		if((c[a[i-1]][a[i]] == 0 && c[a[i]][a[i-1]] == 0)||d[a[i]] == 1)	
			continue;
		d[a[i]] = 1;
		s = (a[i-1]<a[i])? s+ c[a[i-1]][a[i]] : s+ c[a[i]][a[i-1]];
		Try(a,i+1,n);
		d[a[i]] = 0;
		s = (a[i-1]<a[i])? s- c[a[i-1]][a[i]] : s- c[a[i]][a[i-1]];
	}
	
}
int main(){
	int n,m,a[30] = {},x,y;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<= m;i++){
		scanf("%d%d",&x,&y);
		scanf("%d",&c[x][y]);
		min += c[x][y];
	}	
	a[1] = 1; d[1] = 1;
	Try(a,2,n);
	printf("\nQuang duong co trong so min %d",min);
	return 0;
}
