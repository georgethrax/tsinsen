/*
A1009. 数列特征2
时间限制：1.0s   内存限制：512.0MB  
总提交次数：   AC次数：   平均分：
将本题分享到：         查看未格式化的试题   提交   试题讨论
问题描述
　　给出n个数，找出这n个数的第二大值，第二小值，平方和。
输入格式
　　第一行为整数n，表示数的个数。(2<=n<=100)
　　第二行有n个数，为给定的n个数，每个数的绝对值都小于1000。
输出格式
　　输出三行，每行一个整数。第一行表示这些数中的第二大值，第二行表示这些数中的第二小值，第三行表示这些数的平方和。
样例输入
5
100 100 -30 30 1
样例输出
100
1
21801

*/


// echo -e "11\n281 -951 -862 -590 -132 821 72 836 742 680 -449\n" | ./a.out
#include<stdio.h>
#define N 10000

//#define DEBUG

void dump(int a[], int i, int max[], int min[]){
#ifdef DEBUG
	printf("a[%d] %d, max %d %d, min %d %d\n", i, a[i], max[0], max[1], min[0], min[1]);
#endif
}

int main(){

	int n = 0;
	int a[N];
	int max[2], min[2], sum; // max[0]:maximum, min[0]:minimum
	scanf("%d\n", &n);
	for (int i=0; i < n; i++){
		scanf("%d", &a[i]);
	}

	if (a[0] > a[1]){
		max[0] = a[0];
		min[0] = a[1];	
		max[1] = a[1];
		min[1] = a[0];	
	}
	else{
		max[0] = a[1];
		min[0] = a[0];	
		max[1] = a[0];
		min[1] = a[1];		
	}
	sum = a[0]*a[0]+a[1]*a[1];
	dump(a, 1, max, min);

	for (int i=2; i < n; i++){
		if (a[i] > max[0]){
			max[1] = max[0];
			max[0] = a[i];
		}
		else if (a[i] > max[1]){
			max[1] = a[i];
		}
		if (a[i] < min[0]){
			min[1] = min[0];
			min[0] = a[i];			
		}
		else if (a[i] < min[1]){
			min[1] = a[i];
		}
		sum += a[i]*a[i];
		dump(a, i, max, min);

	}
	printf("%d\n%d\n%d\n", max[1], min[1], sum);
	return 0;
}