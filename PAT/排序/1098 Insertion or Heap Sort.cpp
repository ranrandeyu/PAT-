/*��ģ���������
���м������û��һ���ģ����һֱ�Ҳ����ͱ�ʾ�Ƕ������
δ����Ĳ����е�һ��һ����δ��������������ģ�����һ����ȫ������
�����������ɵĶѵĴ���ÿ�ν�δ���������еĵ�һ��Ԫ�������һ��Ԫ�ؽ��н���
Ȼ���ʣ���δ�������н��жѵ����ͺ� */ 
#include <iostream>
#include <algorithm>
int main() {
	int n, i, count, length, a[100], b[100];
	int flag = 1;
	scanf("%d", &n);
	for (i = 0;i < n;i++)
		scanf("%d", &a[i]);
	for (i = 0;i < n;i++)
		scanf("%d", &b[i]);
 
	for (i = 1; b[i] >= b[i - 1]; i++);
	count = i;
	for (;i < n && a[i] == b[i];i++);
 
	if (i == n) {
		printf("Insertion Sort\n");
		std::sort(b, b + count + 1);
		printf("%d", b[0]);
		for (i = 1;i < n;i++)
			printf(" %d", b[i]);
	}
 
	else {
		printf("Heap Sort\n");
		for (i = n - 1;i > 0 && b[i] > b[i - 1];i--);
		std::pop_heap(b, b + i + 1);
		printf("%d", b[0]);
		for (i = 1;i < n;i++)
			printf(" %d", b[i]);
	}
	return 0;
}
 

 

