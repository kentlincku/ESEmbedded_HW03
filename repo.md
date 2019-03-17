HW03
===
## 1. 實驗題目
設計一段c程式，並觀察程式運作時，記憶體和register的變動，及c語言中的function是如何運作
## 2. 實驗步驟
1. 先將資料夾 gnu-mcu-eclipse-qemu 完整複製到 ESEmbedded_HW03 資料夾中

2. 設計測試程式 main.c 

main.c:
```int adder=9;//
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
```
程式中用兩種方式去回傳參數，function `add` 是return by value，而function `addp` 則是return by referance

3. 在編譯完程式後，用objdump與qemu來觀察
![](https://github.com/kentlincku/ESEmbedded_HW03/blob/master/add.png)
![](https://github.com/kentlincku/ESEmbedded_HW03/blob/master/addp.png)
![](https://github.com/kentlincku/ESEmbedded_HW03/blob/master/reset_handler.png)
![](https://github.com/kentlincku/ESEmbedded_HW03/blob/master/loadsummand.png)

## 3. 結果與討論

