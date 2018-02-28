/*
A1027. 拼写检查
时间限制：1.0s   内存限制：512.0MB  
总提交次数：   AC次数：   平均分：
将本题分享到：         查看未格式化的试题   提交   试题讨论
问题描述
　　微软的Word有一个拼写检查功能，如果你拼写错了单词，它会用红线标出以示提醒，然后给出可能正确的单词。现在要你编程实现类似的一个系统：给定一个词表以及一个待检查的单词，判断这个单词是否在词表中，如果不在词表中，程序应该给出一个相似的单词。
　　在寻找相似的单词时，你只需要考虑如下几个简单的情况：
　　1、漏写了一个字母，如把abacus误拼写为abacs
　　2、多写了一个字母，如把abacus误拼写为abaacus
　　3、将某处的一个字母写成了另一个字母，如abacus误拼写为abacup
　　编程实现这个系统。
输入格式
　　输入数据的第一行是一个由小写字母组成的字符串，表示要进行拼写检查的单词
　　第二行是一个数N（1<=N<=100）,表示词表中词的数目
　　接下来有N行，每行都是一个由小写字母组成的字符串，代表词表中的每一个单词
　　所有字符串的长度在2到20之间
输出格式
　　仅输出一个字符串：
　　1、如果要检查的单词在词表中出现，则原样输出该单词
　　2、如果要检查的单词在词表中未出现，但在词表中找到相似的单词，则输出在词表中和它相似的那个单词。如果在此表中找到多个相似单词，仅输出在输入文件中最靠前的一个。
　　3、如果要检查的单词在词表中未出现，并且在词表中找不到与它相似的单词，输出NOANSWER
样例输入
abstaine
4
abacus
abstract
abstain
abstainer
样例输出
abstain
*/

#include <stdio.h>
int check(char a[], char b[]){
	int hit = 0;
	int diff = 0;
	int i=0, j=0, i1=0, j1=0;
	// check string length
	int la = 0;
	int lb = 0; //length
	while(a[la] != '\0'){
		la ++;
	}
	while(b[lb] != '\0'){
		lb ++;
	}

	if (la == lb){
		i = 0;
		diff = 0;
		for (i = 0; i < la; i++){
			if (a[i] != b[i]){
				diff ++;
			}
		}
		//printf("diff,hit,la,lb=%d,%d,%d,%d\n", diff,hit,la,lb);
		if (diff == 0){			
			hit = 2;
		//	printf("diff==0 %d, hit=%d\n",diff==0, hit);
		}
		else if (diff == 1){
		//	printf("diff==1%d\n",diff==1);
			hit = 1;
		}
		else{
			hit = 0;
		}
		//printf("diff,hit,la,lb=%d,%d,%d,%d\n", diff,hit,la,lb);
	}
	else if (la == lb + 1){
		i = 0;
		j = 0;
		while (a[i] == b[j] && i<la && j<lb){
			i++;
			j++;
		}
		i1 = la - 1;
		j1 = lb - 1;
		while (a[i1] == b[j1] && i1 >= 0 && j1 >= 0){
			i1--;
			j1--;
		}
		//abc ab, i==2,j==2, i1==2,j1==1
		//abcde abde, i==2,j==2, i1==2, j1==1
		//aabc abc, i==1, b==1, i1==1, j1==0
		if (i == i1 || i==la-1 || i1 == 0){
			hit = 1;
		}
		else{
			hit = 0;
		}
	}
	else if (la + 1 == lb){
		i = 0;
		j = 0;
		while (a[i] == b[j] && i<la && j<lb){
			i++;
			j++;
		}
		i1 = la - 1;
		j1 = lb - 1;
		while (a[i1] == b[j1] && i1 >= 0 && j1 >= 0){
			i1--;
			j1--;
		}
		//ab aaa, i==1, j==1, i1==1,j1==2
		if (j == j1 || j == lb-1 || j1 == 0){
			hit = 1;
		}
		else{
			hit = 0;
		}
	}
	else{
		hit = 0;
	}
	//printf("i,j,i1,j1,la,lb=%d,%d,%d,%d,%d,%d\n", i,j,i1,j1,la,lb);
	return hit;
}
int main(){
	char s[30]; // target
	int N;
	char table[200][30];

	scanf("%s", s);
	//printf("%s\n", s);
	scanf("%d", &N);
	//printf("N=%d\n",N);
	int hit = 0;
	char* simi_first = 0;
	for (int i=0; i<N; i++){
		scanf("%s", table[i]);
		//printf("table[i]=%s ", table[i]);
		hit = check(s, table[i]);
		//printf("hit=%d\n", hit);
		if (hit == 2){
			//printf("%s true\n", table[i]);
			//printf("hit=%s\n", table[i]);
			printf("%s\n", table[i]);
			simi_first = table[i];
			return 0;
		}
		else if (hit == 1){
			if (simi_first == 0){
				simi_first = table[i];
			}
		}
		else{
			//printf("%s false\n", table[i]);
		}
	}

	if ( simi_first == 0){
		printf("NOANSWER");
	}
	else{
		printf("%s\n", simi_first);
	}
	//printf("DONE\n");

	return 0;
}