```
binary search：
第一次做题：
未考虑数组只有一个元素的情况，应将while循环的条件设置为left<=right。

左闭右开：当更新left要+1，因为右边是开，mid每次更新后的数值在if的情况中已经被check过，
无需重复check。
 
Always learning something new！
Summary of Differences
>> 1: Divides the number by 2.
<< 1: Multiplies the number by 2.
>> 2: Divides the number by 4.
<< 2: Multiplies the number by 4.

Example
Let’s take the number 8 (binary 1000):
8 >> 1:
Binary: 1000 becomes 0100
Decimal: 8 becomes 4 (divided by 2)
8 << 1:
Binary: 1000 becomes 10000
Decimal: 8 becomes 16 (multiplied by 2)
8 >> 2:
Binary: 1000 becomes 0010
Decimal: 8 becomes 2 (divided by 4)
8 << 2:
Binary: 1000 becomes 100000
Decimal: 8 becomes 32 (multiplied by 4)

remove element:
忘记了暴力写法，但是双指针却记得很清楚怎么写。。。
记住 num[i-1] = num[i]的
```