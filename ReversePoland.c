#include<stdio.h>
#include<stdlib.h>
#define ArraySize 10
#define ArrayExpanse 10
typedef int type;
typedef struct Array{
	type *top;
	type *base;
	int Size;
}Array;

void *init(Array *s){
	s->base = (type*)malloc(sizeof(type)*ArraySize);
	if (!s->base){
		exit(0);
	}
	s->top = s->base;
	s->Size = ArraySize;
}

void *pusharray(Array *s,type n){
	if(s->top - s->base > ArraySize){
		printf("%d****\n",s->top - s->base);
		s->base = (type*)realloc(s->base,sizeof(type)*(ArrayExpanse+ArraySize));
		//printf("233++\n");
		s->top = s->base + ArraySize;
		s->Size = ArraySize + ArrayExpanse;
		if (!s->base){
		exit(0);
		}
	}
	*(s->top) = n;
	s->top++;
}

int printvalue(Array* s){
	type *a = s->top;
	while(1){
		if (s->base == s->top){
			s->top = a;
			return 1;
		}
		(s->top)--;
		printf("%d\n",*(s->top));
	}
}

type output(Array*s){
	type n;
	//free(s->top);
	if(s->top - s->base == 0)
	{
		return 1;
	}
	n = *(--s->top);
	return n;
} 
int destory(Array*s){
	while(1){
		free(s->base);
		if(s->base == s->top){
			return 1;
		}
		s->base++;
	}
}
int main()
{
	int re;
	char c;
	char s[50]; 
	int num = 0;
	Array *ernum = (Array*)malloc(sizeof(Array));
	printf("请输入计算用逆波兰表达式#\n");
	gets(s);
	char *str = s;
	init(ernum);
	puts(str);
	while(*str != '#')
	{
		c = *str;
		if((c >= '0'&&c <= '9')||c == ' ')
		{	
			if(c == ' ')
			{
				pusharray(ernum,num);
				printf("%d+++++",num);
				num = 0;
			}
			else
			{
				num = (c - '0') + num * 10;
				
			}
		}
		switch(c)
		{
			case '+':pusharray(ernum,output(ernum)+output(ernum));break;
			case '-':pusharray(ernum,-1*(output(ernum)-output(ernum)));break;
			case '*':pusharray(ernum,output(ernum)*output(ernum));break;
			case '/':pusharray(ernum,output(ernum)/output(ernum));break;
		}
		str++;
		//printvalue(ernum);
	}
	printvalue(ernum);
	re = output(ernum);
	printf("%d",re);
	destory(ernum);
	return 0;
}

