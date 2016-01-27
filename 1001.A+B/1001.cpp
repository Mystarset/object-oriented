#include <cstdio>
int data[101]={0};
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int sum=a+b,k=0;
	if (sum<0) printf("-"),sum=-sum;
	if (sum==0) printf("0");
	else
	{
	while (sum>0)
	 {
	    data[++k]=sum%10;
		sum=sum/10; 
	 }
	for (int i=k;i>=1;i--)
	 {
	 	printf("%d",data[i]);
	 	if (i!=1 && (i-1)%3==0) printf(",");
	 }
    }
    
    return 0;
} 
