#include<stdio.h>
#include<math.h>
#define x0 0
#define xn .5
float f(float x)
{
	if(x==0)
	{
		return 1.0;
	}
	else
	{
		float ans;
		ans=x/sin(x);
		return ans;
	}
}
void main()
{
	float a[5][5],h1,h;
	int i,n,j;
	printf("Enter the step size\n");
	scanf("%f",&h);
	for(i=0;pow(2,i)<((xn-x0)/h);i++);
	n=i+1;
	printf("\n%d\n",n);
	for(i=0;i<n;i++)
	{
		int d=pow(2,i);
		h1=(xn-x0)/d;
		printf("step %d h=%f ",i+1,h1);
		a[i][0]=f(x0);
		for(j=1;(x0+j*h1)<xn;j++)
		{
			a[i][0]+=2*f((x0+j*h1));
		}
		a[i][0]+=f(xn);
		a[i][0]=a[i][0]*h1/2;
		printf(" I[%d]=%f\n",i,a[i][0]);
	}

	
	//printf("%d\n",n);
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			a[j][i]=(pow(2,(2*i))*a[j+1][i-1]-a[j][i-1])/(pow(2,(2*i))-1);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%f\t",a[i][j]);
		}
		printf("\n");
	}
	printf("Value of integral is %f",a[0][n-1]);
}
