Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

思路：只要字符落在a<z 或者 A<<Z之间，除了E /e 之外，全部视为false，若出现两次E/e为false

若 "0e10" 这样算TRUE吗？
若数字间有空格 "2 1"这样呢？
"1e1.2"


用一次循环遍历整个字符串，每个字符进行判断所处区间，若出现以下情况则判为false,头尾的空格特殊处理
1、字符为s = = 0--9 ||flag&&s!=.||flage&&(s!=e ||s!=E ||);
2、字符若为e/E 则flage =0;初始flage =1；
3、字符若为. 则flag =0;初始flag =1；
