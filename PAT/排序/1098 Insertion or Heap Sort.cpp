/*先模拟插入排序
找中间过程有没有一样的，如果一直找不到就表示是堆排序的
未排序的部分中第一个一定是未排序的序列中最大的，堆是一棵完全二叉树
用数组就能完成的堆的创建每次将未排序序列中的第一个元素与最后一个元素进行交换
然后对剩余的未排序序列进行堆调整就好 */ 
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
 

 

