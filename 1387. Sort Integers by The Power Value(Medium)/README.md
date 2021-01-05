# 1387. Sort Integers by The Power Value

> The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:

> if x is even then x = x / 2
> if x is odd then x = 3 * x + 1
> For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).
> 
> Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if two or more integers have the same power value > sort them by ascending order.
> 
> Return the k-th integer in the range [lo, hi] sorted by the power value.
> 
> Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in 32 bit signed integer.

題目自定義了一種運算規則，每個輸入可以對應到一個輸出(3 > 7)
問題會給一段連續的數字以及一個k，我們需要把這段數字計算出對應的輸出之後由小至大重新排序，回傳第K個位置他原本是什麼數字

根據他的運算規則的特性我起初想到用二元樹來記錄整個路徑，然後計算的同時查詢二元樹中的元素來避免重複計算，但是後來覺得其實並不需要二元樹那樣的關聯資訊，我只需要紀錄每個數字對應的輸出就好，於是就想要用list來記錄運算過的數字和其輸出
按原本的想法是要用一個list存輸入另一個list存輸出，但我想嘗試看看把兩個東西綁在一起，於是自訂了一個node的class來存輸入輸出
在查詢和重新排列的部分使用了python自己的in和sort，寫起來比較簡單
要加速的話應該要再研究看看他自訂的運算規則、少用python的in來查詢、以及用兩個list來分開存輸出輸入