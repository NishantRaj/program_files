#include <stdio.h>

int main(){
	int a, b, l, t, c;
	char s[101], p;
	scanf ("%d",&t);
	for (a=0; a <t; a++){
		scanf ("%d ",&l);
		gets(s);
		for (b=0; b <l-1; b++)
			for (c=b+1; c <l; c++)
				if (s[b]<s[c]){
					p=s[b];
					s[b]=s[c];
					s[c]=p;
				}
		puts (s);
	}
	return 0;
}