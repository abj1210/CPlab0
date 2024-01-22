# NJU2023秋编译原理Lab3

姓名：闻嘉迅  
学号：211220091  
首次编写日期：2023.11.23
### 1.功能实现

- 基础功能，生成中间代码
- 支持高维数组,一维数组可作为参数传入(可能有问题)   

### 2.编译方法

编译工具版本：  
gcc version 11.4.0     
flex 2.6.4  
bison (GNU Bison) 3.8.2  

进入Code文件夹，在此目录下输入`make parser`命令进行编译，`./parser [filename]` 执行命令。  

### 3.文件结构

lex.l:词法分析器相关代码  
parser.y:语法分析器相关代码  
syntax_tree.h:语法树生成的相关函数声明  
syntax_tree.c:语法树生成的相关函数实现  
syntax_check_update.h:语法树的检查和更新的函数声明
syntax_check_update.c:语法树的检查和更新的函数实现  
hash.h:哈希表相关函数的声明
hash.c:哈希表相关函数的实现
stack.h:栈的声明
stack.c:栈的实现
ir.h:中间代码生产函数的声明
ir.c:中间代码生产函数的实现
main.c:主函数部分  

### 4.具体实现

在`ir.c`中,`genIrcode`通过遍历进行语法检查的语法树.并通过相应的处理函数打印中间代码. 

**临时变量和标签的实现**  
临时变量以`temp_x`命名,其中x>=10.当x<10时为特殊变量:`temp_0`为`READ`指令写入数据的地址,`temp_1`-`temp_5`为常用常量.`temp_8`,`temp_9`为数组寻址时的临时变量.  
标签以`L_xt`命名,其中x>=1为唯一标识的一组标签,t区分了标签的种类:0表示失败情况,1表示成功情况,2表示这一组中间代码的起始处,3为语句组的结尾.  

**if,while等语句组的实现**  
对于条件表达式,可以分解为数个基本关系表达式与逻辑运算符的组合.

对于每个基本表达式,用IF-GOTO语句和GOTO语句翻译,例如:
```
    LABEL L_a2 :
    IF x < y GOTO L_a1
    GOTO L_a0
```
L_a1表示条件满足时的跳转标签,L_a0表示条件不满足时的跳转标签.  
随后将L_a2,L_a0,L_a1依次压栈.  

对于每个逻辑表达式,用GOTO语句和LABEL语句进行翻译,翻译时先将所需的子表达式的那组符号弹栈.例如,翻译一个exp1 AND exp2语句:  
先弹栈6次,获得exp1和exp2的标签组,即:  
exp1:  
L_a0 L_a1 L_a2  
exp2:  
L_b0 L_b1 L_b2  
随后构造跳转表,设该语句的标签组为L_c0,L_c1:
```
    LABEL L_a0 :  
    LABEL L_b0 :  
    GOTO L_c0  
    LABEL L_a1 :  
    GOTO L_b2  
    LABEL L_b1 :  
    GOTO L_c1  
```  
最后将L_c0,L_c1,L_a2重新压栈(此时L_a2作为L_c2使用)  

对于if语句,用GOTO语句和LABEL语句进行翻译,翻译时先将所需的表达式的那组符号弹栈.例如翻译一个if-else语句:  
先弹栈三次:  
L_a0, L_a1, L_a2  
接着构造if-else语句:  
```
    LABEL L_a2 :
    {
        if条件表达式代码
    }
    LABEL L_a1 :
    {
        if语句代码
    }
    GOTO L_a3
    LABEL L_a0 :
    {
        else语句代码
    }
    LABEL L_a3 :
```

对于while语句,用GOTO语句和LABEL语句进行翻译,翻译时先将所需的表达式的那组符号弹栈.例如翻译一个while语句:  
先弹栈三次:  
L_a0, L_a1, L_a2  
接着构造while语句:  
```
    LABEL L_a2 :
    {
        while条件表达式代码
    }
    LABEL L_a1 :
    {
        循环体代码
    }
    GOTO L_a2
    LABEL L_a0 :
```

**中间代码的翻译**  
对于每条中间代码,对应一条相应的宏,用以构造中间代码字符串.  