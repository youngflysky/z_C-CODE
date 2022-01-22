---

layout: post
title: Shuffling Machines
date: 2021-11-06
categories: C
tags: C语言

---

# Shuffling Machines

Shuffling is a procedure used to randomize a deck of playing cards. Because standard shuffling techniques are seen as weak, and in order to avoid "inside jobs" where employees collaborate with gamblers by performing inadequate shuffles, many casinos employ automatic shuffling machines. Your task is to simulate a shuffling machine.

The machine shuffles a deck of 54 cards according to a given random order and repeats for a given number of times. It is assumed that the initial status of a card deck is in the following order:

```c
S1, S2, ..., S13, 
H1, H2, ..., H13, 
C1, C2, ..., C13, 
D1, D2, ..., D13, 
J1, J2
```

where "S" stands for "Spade", "H" for "Heart", "C" for "Club", "D" for "Diamond", and "J" for "Joker". A given order is a permutation of distinct integers in [1, 54]. If the number at the i-th position is j, it means to move the card from position i to position j. For example, suppose we only have 5 cards: S3, H5, C1, D13 and J2. Given a shuffling order {4, 2, 5, 3, 1}, the result will be: J2, H5, D13, S3, C1. If we are to repeat the shuffling again, the result will be: C1, H5, S3, J2, D13.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer K (≤20) which is the number of repeat times. Then the next line contains the given order. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the shuffling results in one line. All the cards are separated by a space, and there must be no extra space at the end of the line.

Sample Input:

```c
2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
```

Sample Output:

```c
S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5
```

------
## 解法核心：
1. 定义过程**数组crr[]**来进行洗牌的重复；
2. 通过数字与牌面的数学关系，**只需要**定义字符数组 ch[5]={'S','H','C','D','J'}，即可打印出所有牌面。

---

### 初始化brr，代表扑克牌原本的顺序，注意brr[i]=i+1,因为扑克牌没有第0张牌；

```c
int brr[55]={0};
	for(i=0;i<54;i++){
			brr[i]=i+1;
		}
```

### 定义过程数组crr，先将brr中的数字按照arr中的顺序写入crr中，再将crr复制到brr中，这样就完成了一次洗牌，brr中的brr[0]就代表了洗过一次牌后，第一张牌是初始状态的第几张牌；

### 每重复一次该过程，就洗过了一次牌。

### count用来控制洗牌次数；

```c
	int crr[55]={0};
	while(count<t){
		for(i=0;i<54;i++){
			crr[arr[i]-1]=brr[i];
		}
		for(i=0;i<54;i++){
			brr[i]=crr[i];
		}
		count++;
	}
```

### 定义字符数组cards[]={'S','H','C','D','J'},并通过对数字brr[i]和相应牌的关系打印出扑克牌；

```c
	char ch[5]={'S','H','C','D','J'};
	for(i=0 ;i<54;i++){
			int op1,op2;
			op1=brr[i]/13;
			op2=brr[i]%13;
			if(op2!=0){
				printf("%c%d",ch[op1],op2);
			}
			else{
				printf("%c13",ch[op1-1]);
			}
			if(i<53)
			printf(" ");
		}
```

---

## 完整代码如下：

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int t;
	scanf("%d",&t);
	
	int i;
	int count=0;
	char temp[3]="";
	int arr[55]={0};
	for(i=0;i<54;i++){
		scanf("%d",&arr[i]);
	}
	int brr[55]={0};
	for(i=0;i<54;i++){
			brr[i]=i+1;
		}
	
	int crr[55]={0};
	while(count<t){
		for(i=0;i<54;i++){
			crr[arr[i]-1]=brr[i];
		}
		for(i=0;i<54;i++){
			brr[i]=crr[i];
		}
		count++;
	}
	
	char ch[5]={'S','H','C','D','J'};
	for(i=0 ;i<54;i++){
			int op1,op2;
			op1=brr[i]/13;
			op2=brr[i]%13;
			if(op2!=0){
				printf("%c%d",ch[op1],op2);
			}
			else{
				printf("%c13",ch[op1-1]);
			}
			if(i<53)
			printf(" ");
		}
	return 0;
}
```

