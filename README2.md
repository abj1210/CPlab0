# NJU2023秋编译原理Lab2

姓名：闻嘉迅  
学号：211220091  
首次编写日期：2023.11.8  
修改日期：2023.11.9  
### 1.功能实现

- 基础功能，在构建语法树时进行语义错误检查。  
- 错误识别，对于出现的不同类型语义错误进行报错  
- 结构体等价时采用类型等价。   

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
main.c:主函数部分  

### 4.具体实现

每识别一条语法规则并构建相应的节点后，进行语法树检查。在检查函数中，首先识别该非终结符的名称并调用相应的函数进行处理。  
在处理函数中，进行相应的判定和数值更新。  

符号表采用hash表实现，可以将各种变量、结构体和函数名进行插入，便于后续查找。hash表中的表项为`val_node`结构体，储存变量名和变量类型。`val_node`结构体中的`next`变量为`struct val_node *`类型，可以形成链表，便于结构体存储不同域的类型或函数的形参。在用于记录函数时，用于记录变量类型的`type_idx`项用于表示函数的返回值类型。

对于匿名的结构体，会自动调用`get_name()`函数获得独特的结构体名，例如"?0"、"?18"等，以防止和其他变量名相冲突。

实现中的特点如下：  
- 在实现语法树检查函数时使用了较多的宏定义，便于代码调试和修改。  

*2023.11.9修改： 修复若干bug(返回值类型判定错误、变量在带初值定义时丢失所属类型、一些操作符的匹配类型失误。)*