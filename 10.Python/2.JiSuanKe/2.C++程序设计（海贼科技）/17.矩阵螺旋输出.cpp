#include <iostream>
using namespace std;

	int circle_count=0; //circle的运行次数   转了几圈  0开始 
	int ab_count=0; //a的顺序 
	int m_count;
	int n_count;

void Circle(int zongshu,int &m_count,int &n_count,int a[],int b[],int &max_length,int &max_hight)
{

	for(int j=circle_count;j<=n_count-1;j++)
	{
		if(ab_count>=zongshu)
		{
			break;
		 } 
		a[ab_count]=circle_count;
		b[ab_count]=j;
		ab_count+=1;
	}
	
	for(int i=circle_count+1;i<=m_count-1;i++)
	{
		if(ab_count>=zongshu)
		{
			break;
		 } 
		a[ab_count]=i;
		b[ab_count]=n_count-1;
		ab_count+=1;

	}
	
	for(int j=n_count-2;j>=circle_count;j--)
	{
		if(ab_count>=zongshu)
		{
			break;
		 } 
		a[ab_count]=m_count-1;
		b[ab_count]=j;
		ab_count+=1;

	}
	for(int i=m_count-2;i>=circle_count+1;i--)
	{
		if(ab_count>=zongshu)
		{
			break;
		 } 
		a[ab_count]=i;
		b[ab_count]=circle_count;
		ab_count+=1;
	}
	max_length-=2;
	max_hight-=2;
	circle_count+=1;
	n_count-=1;
	m_count-=1;
	return; 

}

int main() {
    int matrix[100][100];
    int m;
    int n;
    cin>>m>>n;
    m_count=m;
    n_count=n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
	int a[m*n],b[m*n];  //a    i    b  j   matrix[i][j]
	int max_length=n;
	int max_hight=m;
	int zongshu=m*n; 
	while(max_length>=1 && max_hight>=1)
	{
		Circle(zongshu,m_count,n_count,a,b,max_length,max_hight);
	}
	
	cout<<matrix[0][0];
	for(int i=1;i<m*n;i++)
	{
		cout<<" "<<matrix[a[i]][b[i]]; 
	 } 
	
    return 0;
}