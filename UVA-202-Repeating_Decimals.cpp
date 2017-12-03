#include<cstdio>
#include<cstring>
#define MAXN 3005
using namespace std;
int div[MAXN],rem[MAXN];
int find(int n,int len){
	for(int i=0;i<len;i++)if(n==rem[i])return i;
	return -1;
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int a,b,remind;
	while(scanf("%d%d",&a,&b)!=EOF){
		memset(div,0,sizeof(div));
		memset(rem,0,sizeof(rem));
		printf("%d/%d = %d.",a,b,a/b);
		int GCD=gcd(a,b);
		a/=GCD;b/=GCD;
		remind=a%b;
		int pos;
		for(int len=0;true;len++){
			div[len]=remind*10/b;
			if(!remind){
				for(int i=0;i<len;i++)printf("%d",div[i]);
				printf("(0)\n   1 = number of digits in repeating cycle\n\n");
				break;
			}
			rem[len]=remind=remind*10%b;
			pos=find(remind,len);
			if(pos>=0){
				if(b%2==0 || b%5==0){pos++;len++;}
				for(int i=0;i<pos;i++)printf("%d",div[i]);
				printf("(");
				for(int i=pos;i<len && i<50+pos;i++)printf("%d",div[i]);
				if(len-pos>50)printf("...");
				printf(")\n   %d = number of digits in repeating cycle\n\n",len-pos);
				break;
			}
		}
	}
}
