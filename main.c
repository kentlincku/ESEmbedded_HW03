int add(int a, int b){return a+b;}
int addbad(int a, int b, int c){return c;}
void addp(int *a, int *b, int *c){*c=*a+*b;}
void reset_handler(void)
{
	int summand=9;
	int addend=10;
	int sum=0;
	sum=add(summand, addend);
	sum=0;
	sum=addbad(summand, addend, sum);
	sum=0;
	addp(&summand, &addend, &sum);
	while (1);
}
