#include<stdio.h>
#include<string.h> 
int main()
{
	int min,max,num;
	int left;
	char item;
	int right[1000];
	int index=-1;
	scanf("%d %d %d",&min,&max,&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d %c %d",&left,&item,&right[i]);///����������ַ����γɵ����� 
	} 
	 

	 for(int i=0;i<num;i++)
	 {
	 	for(int j=i+1;j<num;j++)
	 	{
	 		if(right[i]==right[j])
	 		{
	 			index=i;
			 }
		 }
	 }
	if(index==-1)
	printf("-1");
	else if(right[index]<0)
	printf("%d",right[index]);
	else
	printf("%05d",right[index]);
	
	return 0;
}

