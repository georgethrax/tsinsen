/*
A1021. 集合运算
时间限制：1.0s   内存限制：512.0MB  
总提交次数：   AC次数：   平均分：
将本题分享到：         查看未格式化的试题   提交   试题讨论
问题描述
　　给出两个整数集合A、B，求出他们的交集、并集以及B在A中的余集。
输入格式
　　第一行为一个整数n，表示集合A中的元素个数。
　　第二行有n个互不相同的用空格隔开的整数，表示集合A中的元素。
　　第三行为一个整数m，表示集合B中的元素个数。
　　第四行有m个互不相同的用空格隔开的整数，表示集合B中的元素。
　　集合中的所有元素均为int范围内的整数，n、m<=1000。
输出格式
　　第一行按从小到大的顺序输出A、B交集中的所有元素。
　　第二行按从小到大的顺序输出A、B并集中的所有元素。
　　第三行按从小到大的顺序输出B在A中的余集中的所有元素。
样例输入
5
1 2 3 4 5
5
2 4 6 8 10
样例输出
2 4
1 2 3 4 5 6 8 10
1 3 5
样例输入
4
1 2 3 4
3
5 6 7
样例输出
1 2 3 4 5 6 7
1 2 3 4
*/

/*
hashmap:H(A),H(B)



*/

#include <stdio.h>
#include <string.h>

#include <set>
using namespace std;

#define M 2200

int input(int a[]){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	return n;
}

void quicksort(int a[], int l, int r){
	if ( l >= r){
		return;
	}
	int pivot = a[l];
	int i = l;
	int j = r-1;
	while (i < j){		
		while ( i < j && pivot <= a[j]){
			j --;
		}
		a[i] = a[j];

		while ( i < j &&  a[i] <= pivot){
			i ++;
		}
		a[j] = a[i];		

	}
	a[i] = pivot;
	// 3 1 2 4 2 5
	//       i j
	// 2 1 3 4 5
	quicksort(a, l, i);
	quicksort(a, i+1, r);
}



int main(){
	int A[M];
	int B[M];
	int n = input(A);
	int m = input(B);

	set<int> SB;
	for (int i=0; i<m; i++){
		SB.insert(B[i]);
	}

	quicksort(A, 0, n);

//intersection
	int AB[M];
	int C[M];
	int c = 0;
	int j = 0; 
	for (int i=0; i<n; i++){
		if ( SB.find(A[i]) != SB.end()){
			printf("%d ", A[i]); // intersection
		}
		else{
			AB[j] = A[i]; // union part
			C[j] = A[i];	//complement
			j ++;
		}
	}
	printf("\n");
	c=j;

	for (int i=0; i<m; i++){
		AB[j] = B[i]; // union
		j ++;
	}
	
//union
	quicksort(AB, 0, j);
	for (int i=0; i<j; i++){
		printf("%d ", AB[i]);
	}
	printf("\n");

//comlement
	for (int i=0; i<c; i++){
		printf("%d ", C[i]);
	}
	printf("\n");

	return 0;
}



