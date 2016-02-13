#include<stdio.h>
void main()
{
	float x[10],y[10],xi=0,yi=0,xiyi=0,m,c,xi2=0;
	int i,j,k,n;
	system("clear");
	printf("Enter the number of points to specify\n");
	scanf("%d",&n);
	printf("Enter xi followed by yi\n");
	for(i=0;i<n;i++)
	{
		scanf("%f%f",&x[i],&y[i]);
	}
	//Calculate sigma xi,+++++yi and xiyi
	for(i=0;i<n;i++)
	{
		xi=xi+x[i];
		yi=yi+y[i];
		xiyi=xiyi+x[i]*y[i];
		xi2=xi2+x[i]*x[i];
	}
	//Calculate value of m
	m=(n*xiyi-xi*yi)/(n*xi2-xi*xi);
	//Calculate y intercept c
	c=(yi-m*xi)/n;
	printf("Required straight line is y=%.4fx+%.4f",m,c);
}
