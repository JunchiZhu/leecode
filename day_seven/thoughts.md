```
fourSumCount：
要灵活运用，四数之和可以将他们分成两个groups，并且关键点在于将map的value贮存成两者之和的次数，方便在遍历第二组时找到正确的个数。

canConstruct:
easy

threeSum:
一直没有意识到去重的重要性，而且对情况的判断也很重要，nums[i]==num[i-1]要比nums[i]==nums[i+1]多出一组排列组合。
之后的fast and slow的去重也是看到edge case[-2,0,0,2,2]之后才意识到，要在insert之后要立刻重新检查下一组数据是否有重复的数字的出现。

fourSum:
概念掌握，就是在处理一些特殊情况时还要注意，例如负数，两次循环内的去重
```