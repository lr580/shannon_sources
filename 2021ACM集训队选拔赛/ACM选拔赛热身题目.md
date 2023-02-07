## End Portal

> It seemed like a dream, a long long but sweet sweet dream. In the dream, every day is Sunday.
>
> Seemingly a long time ago, Yunyan was playing Minecraft with Hefeng. It's known to us all that we can locate end portal by throwing two ender pearls. When throwing one ender pearl, it's trail forms a spatial line. And the end portal is located at the intersection point of the two lines at the projection plain. So Yunyan threw two pearls, and you need to calculate where is the end portal located.

Suppose the trial of the first pearl starts at coordinate point of $A$ and ends at $B$ , the second starts at $C$ and ends at $D$ . We name the two horizontal axes as $X,Z$ , and the vertical axis as $Y$ . The coordinate point of the end portal $P$ is the intersection of two lines $AB,CD$ in the projection plain $XOZ$ . You need to calculate the coordinate of $P$ .

Input four lines. Each line contains three integers $x_i,y_i,z_i$ , stands for the coordinates of a spatial point $A,B,C,D$ in order.

It's guaranteed that solution must exist. That is, $AB,CD$ are not parallel in $XOZ$ and no two points are the same in coordinates. And $|x_i|,|y_i|,|z_i|\le10^4$ .

Output a single line with two real number stands for the $X,Z$ coordinates of point $P$ .

Your answer will be regarded correct if and only if either the relative error or the absolute error between your answer and the standard answer is no more than $10^{-6}$ . In other word, suppose your answer is $a$ , and the standard answer is $a'$ , your answer will be correct when $\dfrac{|a-a'|}{\max(1,a')}\le10^{-6}$ .

```c++
0 64 0
0 81 12
-100 70 100
-88 85 100
```

```c++
0 100
```



## Making Colors

> When Yunyan first arrived the Blue Planet through the Abyss portal, everything is a little blueish. The blue makes people blue. So Yunyan wanna make the planet more colorful. Also, the more colorful, the more powerful magic power would spring up in the Blue Planet. Luckily, he owns an Abyss machine which can make colors. So he'd like to use it to paint the planet.

There're three dimensions of an color, which are $R, G, B$ . They are real numbers and at first they are all $1$ . You can use $3$ basic transformations below:

1. Give $\dfrac13G$ and $\dfrac23B$ to $R$ 
2. Give $\dfrac13B$ and $\dfrac23R$ to $G$ 
3. Give $\dfrac13R$ and $\dfrac23G$ to $B$ 

For example, if origin $(R,G,B)$ is $(R_0,G_0,B_0)$ , then after transformation $1$ it becomes $(R_0+\dfrac13G_0+\dfrac23B_0,\dfrac23G_0,\dfrac13B_0)$ .

Now there's a transformation sequence $s$ of length $n$ . The i-th element $s_i$ denotes one kind of the three transformations.

There're $m$ queries. For each query. you need to perform some serial transformations in order $s_l, s_{l+1},\cdots, s_r$ from origin $(R,G,B)=(1,1,1)$ and figure out the final $(R,G,B)$ . 

Suppose the answer value is an fraction $\dfrac xy$ , you should output $\dfrac xy\bmod (10^9+7)$ for every value.

Input the first line with two integers $n,m(1\le n,m\le10^5)$ .

Input the second line with $n$ integers, the i-th integer is $s_i(1\le s_i\le 3)$ .

Then input $m$ lines, each line with two integers $l,r(1\le l\le r\le n)$ , denoting an query.

Output $m$ lines, each line with three integers, denoting the final $(R,G,B)\bmod(10^9+7)$ .

```c++
5 6
1 2 3 1 1
1 1
2 2
3 3
1 2
3 4
1 5
```

```c++
2 666666672 333333336
333333336 2 666666672
666666672 333333336 2
666666672 111111114 222222224
111111114 222222224 666666672
814814823 794238689 390946505
```

For the first query, $(2,\dfrac23,\dfrac13)\bmod(10^9+7)=(2,666666672,333333336)$ .

For the fourth query, $(2\times\dfrac13,\dfrac23+\dfrac23\times 2+\dfrac13\times\dfrac13,\dfrac13\times\dfrac23)=(\dfrac23,\dfrac{19}9,\dfrac29)$ , and $(\dfrac23,\dfrac{19}9,\dfrac29)\bmod(10^9+7)=(666666672,111111114,222222224)$ .

You may use a fast way to input/output, such as scanf in C/C++.



## Omen

> During the long joyful time with Hefeng, though, Yunyan sometimes felt weird and had nightmares, in which his power vanished and he would then disappeared. He got afraid and decided to prepare some contingencies. He found an Abyss Chronosphere which can go back to the previous time. Feeling restless, he decided to carry it all the time in case of accidents. However, it's too big to carry. To compress it, he needed to do as follow:

Given $n$ integer points in two dimensional Euclidean plane indexed from $1$ to $n$ (inclusive). You should divide these points into $k$ groups, satisfying every point belongs to only one group and every group has at least one point. Define the distance of two groups is the shortest distance of two points where one point belongs to the first group and the other point belongs to the second group. In other word, given two groups $G_i,G_j(i\neq j,1\le i,j\le m)$ , $\forall P(x_p,y_p)\in G_i,Q(x_q,y_q)\in G_j$ , the distance of $G_i,G_j$ is $d(i,j)=\min{\sqrt{|x_p-x_q|^2+|y_p-y_q|^2}}$ . Let $p=\min_{i,j\in[1,m],i\neq j} d(i,j)$ .You should find a division scheme, so that $p$ is maximized among all possible division schemes. 

Input the first line with two integers $n,k(2\le k\le n\le10^3)$ .

Then input $n$ lines, the i-th line with two integers $x_i,y_i(-10^5\le x_i,y_i\le10^5)$ .

It's guaranteed that $\forall i\le i < j\le n$ , it's impossible that $x_i=x_j\wedge y_i=y_j$ .

Output the first line with one integer $p^2$ .

Then output $k$ lines, for each line: the first integer $s_i$ in the i-th line is the number of points in the i-th group. Then output $s_i$ integers denoting the indexes of all points in the i-th group. You can output them in any order.

If multiple schemes available, output any.

```c++
4 2
0 0
0 1
1 1
1 0
```

```c++
1
2 1 2
2 3 4
```



```c++
9 3
2 2
2 3
3 2
3 3
3 5
3 6
4 6
6 2
6 3
```

```c++
4
4 1 2 3 4
3 5 6 7
2 8 9
```



