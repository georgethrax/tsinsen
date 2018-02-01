/*
123
*/


#include <stdio.h>
//#define DEBUG
int N=100001;
const int  Nfour  = 400001;
// 121
// 123
void dump(bool bin[], int n){
#ifdef DEBUG
	for (int i = 0; i< n; i++){
		printf("%d", (int)bin[i]);		
	}
	printf("\n");
#endif
}
void dump(int v, char s[]){
	#ifdef DEBUG
	printf("%s,%d ", s, v);
	#endif
}

void nibbleTbin   (    bool bin[4], char nibble) {
	int ni = nibble >= 'A' ? nibble - 'A' + 10: nibble - '0';
	//dump(ni, "ni");
	bin[0] = ni & 1;
	bin[1] = ni & 2;
	bin[2] = ni & 4;
	bin[3] = ni & 8;
	//dump(bin, 4);
}

char bin2oct(bool bin[3]){
	return '0' + bin[0] + bin[1] * 2 + bin[2] * 4;
}

int count_len(bool bin[4]){
	int l = 4;
	for (l = 4; bin[l-1]==0; l--){

	}

	return l;
}


int main(){

	int n;
	scanf("%d\n", &n);

	char h[N]; // hex
	bool a[Nfour]; // bin
	char o[Nfour]; // oct
	for (int i=0; i<n; i++){
		
		scanf("%s", h);
		
		int j = 0;
		for (j = 0; h[j] != '\0'; j++);
		int LH = j; // j -> end of h[]. LH : length of h[]

		for (j = 0; j < LH; j++){
			nibbleTbin(a + 4 * j, h[ LH - 1 - j ]);
		}		
		int b_count = 4 * (LH - 1) + count_len(a + 4 * (LH-1));		
		dump(a, b_count);
		int o_count = (b_count - 1) / 3 + 1;
		dump(o_count, "o_count");
		int o_top = b_count % 3;
		dump(o_top, "o_top");
		o[0] = bin2oct(&a[3 * (o_count-1)]); //o[0] : high digit
		dump(o[0],"o[0]");
		for (j = 1; j < o_count; j ++){
			o[j] = bin2oct( &a[ 3 * (o_count - 1 - j)] );
			dump(o[j],"o[j]");

		}
		o[o_count] = '\0';
		printf("%s\n", o);



	}
	return 0;
}