#!/bin/bash
#程序功能：各种增1操作的方法，运行的结果是1 2 3 4 5 6 7 8 9 10 11
# 使用10种不同的方法计数到11.

n=1; echo -n "$n " #输出1

let "n = $n + 1"   # let "n = n + 1"  也可以.
echo -n "$n " #输出2


: $((n = $n + 1))
#  ":" 是必需的, 因为如果没有":"的话, 
#+ Bash将会尝试把"$((n = $n + 1))"解释为一个命令.
echo -n "$n " #输出3

(( n = n + 1 ))
#  上边这句是一种更简单方法.
#  感谢, David Lombard, 指出这点.
echo -n "$n " #输出4

n=$(($n + 1))
echo -n "$n " #输出5

: $[ n = $n + 1 ]
#  ":" 是必需的, 因为如果没有":"的话,
#+ Bash将会尝试把"$[ n = $n + 1 ]"解释为一个命令.
#  即使"n"被初始化为字符串, 这句也能够正常运行. 
echo -n "$n " #输出6

n=$[ $n + 1 ]
#  即使"n"被初始化为字符串, 这句也能够正常运行.
#* 应该尽量避免使用这种类型的结构, 因为它已经被废弃了, 而且不具可移植性.
#  感谢, Stephane Chazelas.
echo -n "$n " #输出7

# 现在来一个C风格的增量操作.
# 感谢, Frank Wang, 指出这点.

let "n++"          # let "++n"  也可以.感觉这个方法最好记!!!!!!
echo -n "$n " #输出8

(( n++ ))          # (( ++n )  也可以.
echo -n "$n " #输出9

: $(( n++ ))       # : $(( ++n )) 也可以.
echo -n "$n " #输出10

: $[ n++ ]         # : $[ ++n ]] 也可以.
echo -n "$n " #输出11

echo

exit 0
