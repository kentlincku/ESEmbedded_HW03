int adder=9;
int add(int a, int b){return a+b;}
void addp(int *a, int *b, int *c){*c=*a+*b;}
void reset_handler(void)
{
	int beadd=10;
	int sum=0;
	sum=add(adder, beadd);
	sum=0;
	addp(&adder, &beadd, &sum);
	while (1);
}
