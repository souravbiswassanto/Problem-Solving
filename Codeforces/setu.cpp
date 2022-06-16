#include<stdio.h>
#include<string.h>
int main(){
	int n, m,i;
	char s[1006];
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	while (m--){
		int l, r;
		char c,d;
		scanf("%d %d %c %c",& l, & r,& c, & d);
		l--; r--;
		for (i = l; i <= r; i++){
			if(s[i]==c){
				s[i] =d;
			}
	}
	}
	printf("%s",s);
}
