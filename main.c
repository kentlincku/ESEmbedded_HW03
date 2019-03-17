int summand=9;
int add(int a, int b){return a+b;}
void addp(int *a, int *b, int *c){*c=*a+*b;}
void reset_handler(void)
{
	int addend=10;
	int sum=0;
	sum=add(summand, addend);
	sum=0;
	addp(&summand, &addend, &sum);
	while (1);
}
