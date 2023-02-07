## (签到)Diary

> After experiencing so many events in the Blue Planet, Yunyan'd like to make a summary and write them all in his Abyss Log.

Yunyan wrote diary in a weird way. It's made up of many articles. Each article had $n$ events, and it must be written with the order from the 1-st event to the n-th event. Writing each event spent him $1$ minute. 

He would wrote for $m$ periods. For each period he would only wrote $1$ specific kind of event for all the existing articles. In the 1-st period he wrote 1-st event for all the articles. In the next period he wrote the next kind of event. Specially, if in one day he's writing the n-th event, then in the next day he'd write the 1-st event again. 

At first there's no article to write. At the beginning of the i-th period he'd get $a_i$ new articles to write. At one period, he would write articles as much as possible. If one article can't be written at current period because the previous events aren't written, it will be hanged out until the previous events can be written in the future period. When all the events are written, the article is finished. 

Please calculate how many pages he need within the $m$ periods.



The first line contains two integer $n,m(1\le n,m\le10^3)$ .

The second line contains $m$ integers, the i-th integer is $a_i(0\le a_i\le10^3)$ .



Output a single line with an integer denoting the total pages he used.



Sample Input

```c++
3 6
1 1 4 5 1 4
```

Sample output

```c++
33
```



Sample Input2

```c++
5 7
1 9 1 9 8 1 0
```

Sample Output2

```c++
61
```

Here're what happened in the first example:

In the 1st period the 1st article appears, he writes the 1st event of the 1st article, 1 page is used; 

In the 2nd period the 2nd article appears, 2nd article can't be written, he writes the 2nd event of the 1st article, 1 page is used; 

In the 3rd period the 3rd, 4th, 5th, 6th article appear, all articles from 2nd to 6th can't be written, he writes the 3rd event of the 1st article, and 1st article is finished, 1 page is used;

In the 4th period, the 7th, 8th, 9th, 10th, 11st article appear, he writes the 1st event of all the article from 2nd to 11st, 10 pages is used;

In the 5th period, the 12nd article appears, 12nd article can't be written, he writes the 2nd event of all the article from 2nd to 11st, 10 pages is used;

In the 6th period, the 13rd, 14th, 15th, 16th article appear, all articles from 12nd to 16th can't be written, he writes the 3rd event of all the article from 2nd to 11st, and all of them is finished, 10 pages is used;

So he used 33 pages in total.





## 题解raw

设第 $i$ 天加入的学生在第 $f_i$ 天开始上课。第一天加入的没有前置课程，所以 $f_1=1$ 。在第 $[2,n]$ 天加入的学生刚加入的时候都至少有一门前置课程没学，所以只能等待，并在第 $n+1$ 天重新讲授第一门课时开始学，即 $f_i=n+1(2\le i\le n)$ 。以此类推……不难发现，第 $x$ 天加入的学生总是在不小于 $x$ 的第一个 $ny+1$ 天开始学习 $(y\in N)$ 。总结为：$f_x=n\times\lfloor\dfrac{x-1}n\rfloor+1$ 。由于变量是 $x$ ，且 $\lfloor\dfrac{x-1}n\rfloor$ 每隔 $n$ 变化一次，所以总是有 $n$ 天的人一起开始学习，且在同一天毕业。事实上在解题的时候我们甚至不需要用到上面的 $f$ 公式。

用两个整型变量记录当前有多少人正在上课和多少人正在等待。然后逐天遍历，把每天新来的人数累加到等待变量里，然后判断第 $i$ 天是否是满足 $ny+1(y\in N)$ 的形式，若 $i-1\equiv0\mod n$ ，那么说明今天在教第一门课，同时也说明之前学习的人都学完毕业了。所以此时清零正在上课的人数，将等待的人数全部放到上课人数里，然后等待人数清零。处理完后，每天向正在上课的人收 $1$ 金币即可。

时间复杂度为 $O(m)$ ，空间复杂度为 $O(1)$

C++ 参考代码

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
ll n, m, wait, learn, a;
long long ans;
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= m; ++i)
    {
        sc(a);
        wait += a;
        if ((i - 1) % n == 0)
        {
            learn = wait;
            wait = 0;
        }
        ans += learn;
    }
    printf("%lld", ans);
    return 0;
}
```



## 题解

题意翻译：每篇文章由 $n$ 件事件组成，每件事件篇幅 $1$ 页纸。初始无文章。有 $m$ 阶段，第 $i$ 阶段初新增 $a_i$ 篇文章，设 $j=(i-1)\bmod n+1$，并对所有前 $j-1$ 件事件都写完且第 $j$ 件事件未写完的文章，写上第 $j$ 件事件。问全过程用多少页纸。$1\le n,m,a_i\le10^3$。



考点：模拟

设第 $i$ 阶段加入的文章在第 $f_i$ 天开始写第一件事件。第一天加入的没有前置事件要写，所以 $f_1=1$ 。在第 $[2,n]$ 天加入的文章刚加入的时候都至少有一件前置事件没写，所以只能等待，并在第 $n+1$ 阶段重新开始写第一件事件时开始写这些文章，即 $f_i=n+1(2\le i\le n)$ 。以此类推……不难发现，第 $x$ 阶段加入的文章总是在不小于 $x$ 的第一个 $ny+1$ 阶段开始写 $(y\in N)$ 。总结为：$f_x=n\times\lfloor\dfrac{x-1}n\rfloor+1$ 。由于变量是 $x$ ，且 $\lfloor\dfrac{x-1}n\rfloor$ 每隔 $n$ 变化一次，所以总是有 $n$ 阶段的文章一起开始写，且在同一天写完。事实上在解题的时候我们甚至不需要用到上面的 $f$ 公式。

用两个整型变量记录当前有多少文章正在被写和多少文章正在等待。然后逐阶段遍历，把每阶段新来的文章数累加到等待变量里，然后判断第 $i$ 阶段是否是满足 $ny+1(y\in N)$ 的形式，若 $i-1\equiv0\mod n$ ，那么说明今天在写第一件事件，同时也说明之前的文章都写完了。所以此时清零正在被写的文章数目，并将等待的文章全部放到正在被写的文章里，然后等待的文章数目清零。处理完后，每阶段增加使用正在被写的文章数目张纸张。

时间复杂度为 $O(m)$ ，空间复杂度为 $O(1)$。

> 作为签到题，数据范围故意放过了一些时空复杂度更高的解法，可自行尝试。

C++ 参考代码

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) scanf("%lld", &x)
ll n, m, wait, writing, a, ans;
signed main()
{
    sc(n), sc(m);
    for (ll i = 1; i <= m; ++i)
    {
        sc(a);
        wait += a;
        if ((i - 1) % n == 0)
        {
            writing = wait;
            wait = 0;
        }
        ans += writing;
    }
    printf("%lld", ans);
    return 0;
}
```

