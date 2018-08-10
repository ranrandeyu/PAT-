#include <stdio.h>
#include <string.h>

int main()
{
	int i;
    int n;
    scanf("%d", &n);
	char id[15];
	char tin[10];
	char tout[10];
	char firstid[15];
	char lastid[15];
	char maxtime[10]="00:00:00";
	char mintime[10]="23:59:59";
	for(i=0;i<n;i++)
	{
		scanf("%s %s %s",id,tin,tout);
		if(strcmp(tin,mintime)<=0)
		{
			strcpy(mintime,tin);
			strcpy(firstid,id);
		}
		if(strcmp(tout,maxtime)>=0)
		{
			strcpy(maxtime,tout);
			strcpy(lastid,id);
		}
	}
	printf("%s %s",firstid,lastid);
	return 0;
}

