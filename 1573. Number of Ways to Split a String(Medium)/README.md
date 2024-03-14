1573. Number of Ways to Split a String
Medium
>Given a binary string s, you can split s into 3 non-empty strings s1, s2, and s3 where s1 + s2 + s3 = s.
>Return the number of ways s can be split such that the number of ones is the same in s1, s2, and s3. Since the answer may be too large, return it modulo 10^9 + 7.

給一個由'0'和'1'組成的字串，把字串切三分不為空的字串，其中三分裡面的'1'的數量必須相同，求總共有幾種切法

先計算總共有多少個'1'，計算完之後會有三種情況
1. 沒有'1'：直接計算有幾種切法
2. '1'的數量無法整除3：無法達成條件，答案為0
3. '1'的數量可以整除3：
此時字串可以被分成五個部分，以"101010010011"舉例，六個'1'表示三個part裡面各有兩個'1'
字串可以被理解成"101 0 1001 00 11"這五個部分，其中第1 3 5個字串是不能被切開的，否則會無法達成條件，所以可以切的部分只有第2 4的"0"和"00"，"0"可以有兩個切法，"00"則可以有三個切法，2*3答案為6，以此邏輯計算第2和第4個區間總共有幾個0就可以乘出答案