HW03
===
## 1. 實驗題目
設計一段c程式，並觀察程式運作時，記憶體和register的變動，及c語言中的function是如何運作
## 2. 實驗步驟
1. 先將資料夾 gnu-mcu-eclipse-qemu 完整複製到 ESEmbedded_HW03 資料夾中

2. 設計測試程式 main.c 

main.c:
```int add(int a, int b){return a+b;}
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
```

3. 在編譯完程式後，用objdump與qemu來觀察
![](https://github.com/kentlincku/ESEmbedded_HW03/blob/master/add.png)
![](https://github.com/kentlincku/ESEmbedded_HW03/blob/master/addbad.png)
![](https://github.com/kentlincku/ESEmbedded_HW03/blob/master/reset_handler.png)
![](https://github.com/kentlincku/ESEmbedded_HW03/blob/master/gdb.png)

## 3. 結果與討論

在程式中，為了測試C語言中的function會如何表現，簡單的設計了三個function
```int add(int a, int b){return a+b;}
int addbad(int a, int b, int c){return c;}
void addp(int *a, int *b, int *c){*c=*a+*b;}
```
由結果不難看出
1. 參數的傳遞是藉由register來進行的，在
```
7e:	f7ff ffc3 	bl	8 <add>
```
前，會先有
```7a:	4610      	mov	r0, r2
7c:	4619      	mov	r1, r3
```
預先將用到的參數傳到register內

2. 如果是以return by value的方式來傳遞時，register中存的是數值，可以直接進行加法
```
16:	4413      	add	r3, r2
```
而如果是以pointer的行式為參數時，register中是位址，會先經過`ldr`將位址中的值取出，最後再將數值存回

3. 如果是return by value，則因為register在function結束時，function中對由讀取參數register的變動都不會存至記憶體，因此
```
int addbad(int a, int b, int c){return c;}
```
中的`c`將會是原本的值而不會變動
