#include<stdio.h>
void main()
{
	float a[3],x[10],y[10],xi=0,yi=0,xi2=0,xi3=0,xi4=0,xiyi=0,xi2yi=0,c[3][4];
	int n,i,j,k;
	system("clear");
	printf("Enter number of points to specify\n");
	scanf("%d",&n);
	printf("Enter x and y for each point \n");
	for(i=0;i<n;i++)
		scanf("%f%f",&x[i],&y[i]);
	for(i=0;i<n;i++)
	{
		xi=xi+x[i];
		yi=yi+y[i];
		xi2=xi2+x[i]*x[i];
		xi3=xi3+x[i]*x[i]*x[i];
		xi4=xi4+x[i]*x[i]*x[i]*x[i];
		xiyi=xiyi+x[i]*y[i];
		xi2yi=xi2yi+x[i]*x[i]*y[i];
	}
	//We assign coefficients of 3 simultaneous equations to the matrix c[3][4]
	c[0][0]=n;	c[0][1]=xi;	c[0][2]=xi2;	c[0][3]=yi;
	c[1][0]=xi;	c[1][1]=xi2;	c[1][2]=xi3;	c[1][3]=xiyi;
	c[2][0]=xi2;	c[2][1]=xi3;	c[2][2]=xi4;	c[2][3]=xi2yi;
	//Now we have to solve the equations using Gauss-Elimination method
	//First make upper diagonal matrix
	for(i=0;i<2;i++)
	{
		for(j=i+1;j<3;j++)
		{
			float t=c[j][i]/c[i][i];
			for(k=0;k<=3;k++)
			{
				c[j][k]-=t*c[i][k];
			}
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<=3;j++)
		{
			printf("%f\t",c[i][j]);
		}
		printf("\n");
	}
	//Now find the value of constants and store it in the array a[3]
	for(i=2;i>=0;i--)
	{
		float s=0;
		for(j=i+1;j<3;j++)
		{
			s+=a[j]*c[i][j];
		}
		a[i]=(c[i][3]-s)/c[i][i];
	}
	//That's all . Now display the equation of parabolla
	printf("Equation of parabolla that fits given points is \n");
	printf("%fx^2+%fx+%f",a[2],a[1],a[0]);
}
