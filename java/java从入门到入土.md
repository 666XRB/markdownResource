

# JAVA认识&配置

## 1. 人机交互

### 1.1 什么是cmd？

就是在windows操作系统中，利用**命令行**的方式去**操作计算机**。

我们可以利用cmd命令去操作计算机，比如：打开文件，打开文件夹，创建文件夹等。

### 1.2 如何打开CMD窗口？

1. 按下快捷键：win + R。

   	此时会出现运行窗口。

2. 在运行窗口中输出cmd

3. 输出回车。

解惑：

​	cmd默认操作C盘下的users文件夹下的XXX文件夹。（XXX就是计算机名）

 ![image-20210923091350952](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/cmd.png)

### ==cmd和wt==

> 在Windows系统中，`win+r`打开运行对话框，可以输入不同的命令来执行相应的操作。`cmd`和`wt`是两个常用的命令。
>
> 1. `cmd`是==命令提示符==（Command Prompt）的缩写，它是Windows系统中经典的命令行界面。通过运行`cmd`命令，可以打开一个窗口，在其中执行各种命令、批处理脚本等。
>
> 2. `wt`是Windows Terminal的缩写。Windows Terminal是Microsoft官方推出的==新一代终端程序==，用于替代传统的命令提示符和PowerShell窗口。与传统的命令提示符相比，Windows Terminal提供了更多功能和自定义选项，可以同时打开多个标签页，支持多种终端环境（如命令提示符、PowerShell、WSL等），并且具有更好的界面和用户体验。
>
> 总结：
>
> - `cmd`是经典的命令行界面；
> - `wt`是Windows Terminal的缩写，是一种新一代的终端程序，提供更多功能和自定义选项。



### 1.3 常用CMD命令

 扩展一个小点：

==cmd命令！=DOS命令==

​	在很多资料中都说成是DOS命令，其实是不对的。

真正的DOS命令是1981年微软和IBM出品的MS-DOS操作系统中的命令才叫做DOS命令。

​	而在Windows中，win98之前的操作系统是以非图形化的DOS为基础的，可以叫做DOS命令。到了2000年以后，windows逐渐的以==图形化界面为主了==，这个时候就不能叫DOS命令了，他只是模拟了DOS环境而已，很多的原本的DOS命令已经无法使用了，所以这个时候叫做CMD命令会更准确一些。

常见的CMD命令如下：

> /是根目录
>
> ~是用户的工作目录
>
> 类似Linux
>
> ![image-20231125150010687](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231125150010687.png) 

| 操作               | 说明                              |
| ------------------ | --------------------------------- |
| 盘符名称:          | 盘符切换。E:回车，表示切换到E盘。 |
| dir                | 查看当前路径下的内容。            |
| cd 目录            | 进入单级目录。cd itheima          |
| cd ..              | 回退到上一级目录。                |
| cd 目录1\目录2\... | 进入多级目录。cd itheima\JavaSE   |
| cd \               | 回退到盘符目录。                  |
| cls                | 清屏。                            |
| exit               | 退出命令提示符窗口。              |

### 1.4 CMD练习

### 如何查看电脑软件安装的位置？



1. 鼠标移到上面就有

   <img src="java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231125150401997.png" alt="image-20231125150401997" style="zoom:50%;" /> 

2. 属性

   <img src="java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231125150406522.png" alt="image-20231125150406522" style="zoom:50%;" /> 

需求：

`cd /d D:\software\newqq`。

==使用`/d`选项可以同时切换目录和驱动器，并更新显示的当前工作目录路径。==

  利用cmd命令打开自己电脑上的QQ。

完成步骤：

```java
1,确定自己电脑上的QQ安装在哪里
2,启动cmd
3,进入到启动程序QQ.exe所在的路径。
4,输出qq.exe加回车表示启动qq。
```

![image-20231125151254839](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231125151254839.png) 

解惑：

​	在windows操作系统当中，文件名或者文件夹名是忽略大小写的。

### 1.5 环境变量

作用：

​	如果我想要在CMD的任意目录下，都可以启动某一个软件，那么就可以==把这个软件的路径配置到环境变量中的PATH里面==

> 在启动软件的时候，
>
> 操作系统会==先在当前路径==下找，
>
> 如果在当前路径没有==再到环境变量的路径==中去找。
>
> 如果都找不到就提示无法启动。



步骤：

- 右键我的电脑，选择属性。
- 点击左侧的高级系统设置
- 选择高级，再点击下面的环境变量。
- 找系统变量里面的PATH
- 把软件的完整路径，配置到PATH当中就可以了。
- （可做可不做）就是把自己配置的路径，移动到最上面。

图解示例如下：

第一步：右键点击我的电脑并选择属性。

（如果无法出现第二步界面，可以打开我的电脑之后右键点击空白处）

![image-20210923091350952](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/1.png)

第二步：点击高级系统设置。

​	 ![image-20210923091350952](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/2.png)

第三步：选择高级，再点击下面的环境变量。

 ![image-20210923091350952](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/3.png)



第四步：找系统变量里面的PATH

 ![image-20210923091350952](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/4.png)

第五步：点击新建，把软件的完整路径，配置到PATH当中，再点击确定即可。

第六步：（可做可不做）点击上移，把当前配置的路径移动到最上面。

移动的好处：在CMD中打开软件时，会先找当前路径，再找环境变量，在环境变量中是从上往下依次查找的，如果路径放在最上面查找的速度比较快。

 ![image-20210923091350952](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/5.png)

### 微信添加到环境变量

![image-20231125151759099](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231125151759099.png)



就可以win+r+cmd+WeChat.exe启动了！ 

以此类推，另一种方式打开应用！

## 2. Java概述

### 1.1 Java是什么？

语言：人与人交流沟通的表达方式

计算机语言：人与计算机之间进行信息交流沟通的一种特殊语言

Java是一门非常火的计算机语言。（也叫做编程语言）

我们想要让计算机做一些事情，那么就可以通过Java语言告诉计算机就可以了

### 1.2下载和安装

#### 1.2.1 下载

通过官方网站获取JDK

[http://www.oracle.com](http://www.oracle.com/)

**注意1**：针对不同的操作系统，需要下载对应版本的JDK。

**注意2**：

​	如果你的电脑是windows32位的，建议重装系统，重装成64位的操作系统。

​	因为Java从9版本开始，就已经不提供32位版本的安装包了。

#### 1.2.2 安装

​	傻瓜式安装，下一步即可。默认的安装路径是在C:\Program Files下。

建议：

- ==安装路径不要有中文==，不要有空格等一些特殊的符号。
- 以后跟开发相关的所有软件建议都安装在同一个文件夹中，方便管理。

#### 1.2.3 JDK的安装目录介绍

| 目录名称 | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| bin      | 该路径下存放了JDK的各种工具命令。javac和java就放在这个目录。 |
| conf     | 该路径下存放了JDK的相关配置文件。                            |
| include  | 该路径下存放了一些平台特定的头文件。                         |
| jmods    | 该路径下存放了JDK的各种模块。                                |
| legal    | 该路径下存放了JDK各模块的授权文档。                          |
| lib      | 该路径下存放了JDK工具的一些补充JAR包。                       |

### 1.3 HelloWorld小案例

​	HelloWorld案例是指在计算机屏幕上输出“HelloWorld”这行文字。各种计算机语言都习惯使用该案例作为第一个演示案例。

#### 2.3.1 Java程序开发运行流程

开发Java程序，需要三个步骤：编写程序，编译程序，运行程序。

#### 2.3.2 HelloWorld案例的编写

1. 新建文本文档文件，修改名称为HelloWorld.java。

**注意**：后缀名为java的才是java文件。

2. 用记事本打开HelloWorld.java文件，输写程序内容。

**注意**：代码要跟我编写的完全保持一致。

```java
public class HelloWorld {
	public static void main(String[] args) {
		System.out.println("HelloWorld");
	}
}
```

3. 保存

**注意**：未保存的文件在左上角会有*符号标记

4. 编译文件。编译后会产生一个class文件。

   java文件：程序员自己编写的代码。

   class文件：交给计算机执行的文件。

5. 运行代码

   **注意**：运行的是编译之后的class文件。

> 用到两个命令：
>
> ​	javac + 文件名 + 后缀名 （就是编译java文件）==生成了java.class文件==
>
> ​	java + 文件名（运行编译之后的class文件）==现在一i的那个不能加后缀了==

### 1.4 HelloWorld案例常见问题

#### 1.4.1 BUG

​	在电脑系统或程序中，隐藏着的一些未被发现的缺陷或问题统称为bug（漏洞）。

#### 1.4.2 BUG的解决

1. 具备识别BUG的能力：多看
2. 具备分析BUG的能力：多思考，多查资料
3. 具备解决BUG的能力：多尝试，多总结

#### 1.4.3 HelloWorld常见问题

1、非法字符问题。Java中的符号都是英文格式的。

2、大小写问题。Java语言对大小写敏感（区分大小写）。

3、在系统中显示文件的扩展名，避免出现HelloWorld.java.txt文件。

4、编译命令后的java文件名需要带文件后缀.java

5、运行命令后的class文件名（类名）不带文件后缀.class

...

#### 常见错误代码1：

```java
publicclass HelloWorld{
    public static void main(String[] args){
        System.out.println("HelloWorld");
    }
}
```

问题：

​	public和class之间缺少一个空格。

技巧：一般来讲在单词之间的空格是不能省略的。

​	如果是单词和符号之间的空格是可以省略的。

#### 常见错误代码2：

```java
public class HelloWorld{
    public static void main(String[] args){
        system.out.println("HelloWorld");
    }
}
```

问题：

​	system首字母必须大写。

技巧：

==Java代码中，是严格区分大小写的。==

​	所以该大写的地方一定要大写，该小写的地方一定要小写。多多练习。

#### 常见错误代码3：

```java
public class HelloWorld{
    public static void main(String[] args){
        System.out.println(HelloWorld);
    }
}
```

问题：

​	第三行代码中的HelloWorld必须用双引号引起来，否则就会出现问题。

#### 常见错误代码4：

```java
public class HelloWorld{
    public static void main(String[] args){
        System.out.println("HelloWorld")；
    }
}
```

问题：

​	在以后代码当中，所有的标点符号必须是英文状态下的。

技巧：

​	可以在输入法中进行对应的设置。







### ==1.5 环境变量==

#### 1.5.1 为什么配置环境变量

​	开发Java程序，需要使用JDK提供的开发工具（比如javac.exe、java.exe等命令），而这些工具在JDK的安装目录的bin目录下

​    如果不配置环境变量，那么这些命令只可以在==bin目录==下使用，而我们想要在任意目录下都能使用，所以就要配置环境变量。

> bin目录下面都是可执行程序。。。就类比到了WeChat.exe的所在目录了吧。。。

注意：现在最新从官网上下载的JDK安装时会自动配置javac、java命令的路径到Path环境变量中去 ，所以javac、java可以直接使用。

#### 1.5.2配置方式

![image-20210923091654365](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20210923091654365.png)



以前下载的老版本的JDK是没有自动配置的，而且自动配置的也只包含了4个工具而已，所以我们需要删掉已经配置完毕的，再次重新配置Path环境变量。

![image-20231125153010169](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231125153010169.png) 

①**JAVA_HOME**：告诉操作系统JDK安装在了哪个位置（未来其他技术要通过这个找JDK）

②**Path**：告诉操作系统JDK提供的javac(编译)、java(执行)命令安装到了哪个位置

![image-20231125153051935](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231125153051935.png) 

> - `JAVA_HOME`是一个环境变量，用于指定Java的安装路径。
> - 将Java的`bin`目录添加到环境变量（`PATH`）可以让您在命令提示符下直接运行Java命令和相关工具。
> - 使用`JAVA_HOME`环境变量可以使其他应用程序或开发工具更方便地找到和使用Java的安装位置。



#### 1.5.3win10的bug

当电脑重启之后，环境变量失效了。表示操作系统不支持自定义的环境变量。

步骤：

- 还是要配置JAVA_HOME给以后的相关软件去使用

- 我们可以把java和javac的完整路径配置到PATH当中。

  E:\develop\JDK\bin

### 1.6 Notepad++

#### 1.6.1下载

​	打开百度，搜索一下notepad++就可以了。

#### 1.6.2 安装

傻瓜式安装，直接点击下一步就可以了。

​	对安装路径有两个小建议：

- 路径不要有中文，不要有空格，不要有一些特殊符号
- 建议最好把所有的跟开发相关的软件都放在一起，方便管理。

#### 1.6.3 设置

​	右键点击java文件，选择edit with notepad++。

​	点击设置，再点击首选项。在弹出的页面当中，左侧选择新建，中间选择Java，右侧选择ANSI。

#### 1.6.4 练习

​	利用notepad++去编写一个HelloWorld并能成功编译和运行。

### 1.7 Java语言的发展

三个版本：

* Java5.0：这是Java的第一个大版本更新。
* Java8.0：这个是目前绝大数公司正在使用的版本。因为这个版本最为稳定。
* Java15.0：这个是我们课程中学习的版本。

解惑：

​	我们学的跟工作中使用的版本不太一样啊。会不会影响以后工作呢？

==向下兼容==。新的版本只是在原有的基础上添加了一些新的功能而已。

举例：

用8版本开发的代码，用11版本能运行吗？必须可以的。

用11版本开发的代码，用8版本能运行吗？不一定。

如果11版本开发的代码，没有用到9~11的新特性，那么用8是可以运行的。

如果11版本开发的代码，用到了9~11的新特性，那么用8就无法运行了。

### 1.8 Java的三大平台

==JavaSE、JavaME、JavaEE==

#### 1.8.1 JavaSE

​	==是其他两个版本的基础。==

#### 1.8.2 JavaME

​	==Java语言的小型版，用于嵌入式消费类电子设备或者小型移动设备的开发。==

​	其中最为主要的还是小型移动设备的开发（手机）。渐渐的没落了，已经被安卓和IOS给替代了。

​	但是，安卓也是可以用Java来开发的。

#### 1.8.3 JavaEE

​	==用于Web方向的网站开发。（主要从事后台服务器的开发）==

​	在服务器领域，Java是当之无愧的龙头老大。

### 1.9 Java的主要特性

- 面向对象
- 安全性
- 多线程
- 简单易用
- 开源
- 跨平台

#### 1.9.1 Java语言跨平台的原理

- 操作系统本身其实是不认识Java语言的。
- 但是针对于不同的操作系统，==**Java提供了不同的虚拟机。**==

==虚拟机会把Java语言翻译成操作系统能看得懂的语言。==

![image-20210923091350952](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20210923091350952.png)

### ==1.10 JRE和JDK==

![image-20210923091544110](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20210923091544110.png)

JVM（Java ==Virtual Machine==），Java虚拟机

JRE（Java Runtime ==Environment==），==Java运行环境，包含了JVM和Java的核心类库（Java API）==

JDK（Java ==Development== Kit）称为Java**开发工具**，包含了JRE和开发工具

总结：我们只需安装JDK即可，它包含了java的运行环境和虚拟机。

---







## Java的环境配置和Eclipse的安装和使用

[Java的环境配置和Eclipse的安装和使用_粉面菜蛋哈哈哈的博客-CSDN博客](https://blog.csdn.net/xideaha/article/details/132671584)



# Java基础语法

## 1. 注释

​	注释是对代码的解释和说明文字。

Java中的注释分为三种：

* 单行注释：

~~~java
// 这是单行注释文字
~~~

* 多行注释：

~~~java
/*
这是多行注释文字
这是多行注释文字
这是多行注释文字
*/
注意：多行注释不能嵌套使用。
~~~

* 文档注释（暂时用不到）：

```java
/**
这是多行注释文字
这是多行注释文字
这是多行注释文字
*/
```

```java
package soft1;

public class Main {
    public static void main(String[] args) {
        System.out.println("hello world");
    }
}
//dasdasd

/*
*
* dasdasdhjka
* sdasdasdasd
*
* */

```

### 使用的技巧

​	如果我们要对代码进行解释，那么就可以使用注释。

​	当注释的内容比较少，一行就写完了，可以用单行注释。

​	如果注释的内容比较多，需要写在多行，那么可以使用多行注释。

### 注意点

​	注释的内容不会参与编译和运行的，仅仅是对代码的解释说明而已。

​	所以，不管在注释当中写什么内容，都不会影响代码运行的结果。

> (选中多行/默认当前行)CTRL+/



## 2. 关键字

### 2.1 概念

​	被Java赋予了特定含义的英文单词。

​	当我们在代码中写了关键字之后，程序在运行的时候，就知道要做什么事情了。

注意：关键字很多，不用刻意去记。

| **abstract**   | **assert**       | **boolean**   | **break**      | **byte**   |
| -------------- | ---------------- | ------------- | -------------- | ---------- |
| **case**       | **catch**        | **char**      | **class**      | **const**  |
| **continue**   | **default**      | **do**        | **double**     | **else**   |
| **enum**       | **extends**      | **final**     | **finally**    | **float**  |
| **for**        | **goto**         | **if**        | **implements** | **import** |
| **instanceof** | **int**          | **interface** | **long**       | **native** |
| **new**        | **package**      | **private**   | **protected**  | **public** |
| **return**     | **strictfp**     | **short**     | **static**     | **super**  |
| **switch**     | **synchronized** | **this**      | **throw**      | **throws** |
| **transient**  | **try**          | **void**      | **volatile**   | **while**  |

### 2.2 第一个关键字class

​	表示定义一个类。创建一个类。

类：==Java项目最基本的组成单元，一个完整的Java项目有可能会有成千上万个类来组成的。==

class后面跟随的就是这个类的名字，简称：类名。

在类名后面会有一对大括号，表示这个类的内容。

举例：

```java
public class HelloWorld{
    
   
}
```

解释：class表示定义类。

​	类名：HelloWorld

​	HelloWorld后面的大括号表示这个类的范围。

## 3. 字面量

作用：告诉程序员，数据在程序中的书写格式。

| **字面量类型** | **说明**                                  | **程序中的写法**           |
| -------------- | ----------------------------------------- | -------------------------- |
| 整数           | 不带小数的数字                            | 666，-88                   |
| 小数           | 带小数的数字                              | 13.14，-5.21               |
| 字符           | 必须使用单引号，有且仅能一个字符          | ‘A’，‘0’，   ‘我’          |
| 字符串         | 必须使用双引号，内容可有可无              | “HelloWorld”，“黑马程序员” |
| 布尔值         | 布尔值，表示真假，只有两个值：true，false | true 、false               |
| 空值           | 一个特殊的值，空值                        | 值是：null                 |

~~~java
public class Demo {
    public static void main(String[] args) {
        System.out.println(10); // 输出一个整数
        System.out.println(5.5); // 输出一个小数
        System.out.println('a'); // 输出一个字符
        System.out.println(true); // 输出boolean值true
        System.out.println("欢迎来到黑马程序员"); // 输出字符串
    }
}
~~~

### 区分技巧

1. 不带小数点的数字都是整数类型的字面量。
2. 只要带了小数点，那么就是小数类型的字面量。
3. 只要用双引号引起来的，不管里面的内容是什么，不管里面有没有内容，都是字符串类型的字面量。
4. ==字符类型的字面量必须用单引号引起来，不管内容是什么，但是个数有且只能有一个。==
5. 字符类型的字面量只有两个值，true、false。
6. 空类型的字面量只有一个值，null。

## 4. 变量

### 4.1 什么是变量？

​	变量就在程序中临时存储数据的容器。但是这个容器中只能存一个值。

### 4.2 变量的定义格式

​	数据类型 变量名 = 数据值；

#### 4.2.1 格式详解

​	数据类型：限定了变量当中能存储什么类型的数据。

​			   如果要存10，那么数据类型就需要写整数类型。

​			   如果要存10.0，那么数据类型就需要写小数类型。

​	变量名：其实就是这个容器的名字。

​			当以后想要使用变量里面的数据时，直接使用变量名就可以了。

​	数据值：真正存储在容器中的数据。

​	分号：表示语句的结束，就跟以前写作文时候的句号是一样的。

#### 4.2.2 常用的数据类型

​	整数：int

​	小数：（浮点数）double

​	其他数据类型稍后讲解

举例：

```java
public class VariableDemo{
	public static void main(String[] args){
		//定义一个整数类型的变量
		//数据类型 变量名 = 数据值;
		int a = 16;
		System.out.println(a);//16
		
		//定义一个小数类型的变量
		double b = 10.1;
		System.out.println(b);//10.1
	}
}
```

#### 4.2.3 变量的注意事项

- 变量名不能重复

- 在一条语句中，可以定义多个变量。但是这种方式影响代码的阅读，所以了解一下即可。

- ```java
  int a,b,c;
  int a;
  int b;
  int c;
  ```

  

- ==变量在使用之前必须要赋值。==

案例：

```java
public class VariableDemo2{
	public static void main(String[] args){
		//1.变量名不允许重复
		//int a = 10;
		//int a = 20;
		//System.out.println(a);
		
		//2.一条语句可以定义多个变量
		//了解。
		//int a = 10, b = 20, c = 20,d = 20;
		//System.out.println(a);//?
		//System.out.println(b);//?
		
		
		//3.变量在使用之前必须要赋值
		int a = 30;
		System.out.println(a);
	}
}
```

### 4.3 变量的练习

​	需求：说出公交车到终点站之后，车上一共有多少乘客？

​		    一开始没有乘客。

​		   第一站：上去一位乘客，没有下来乘客。

​		   第二站：上去两位乘客，下来一位乘客。

​		   第三站：上去两位乘客，下来一位乘客。

​		   第四站：没有上去乘客，下来一位乘客。

​		   第五站：上去一位乘客，没有下来乘客。

​		   问：到了终点站之后，车上一共多少乘客？

​	代码解析：

```java
public class VariableTest1{
	//主入口
	public static void main(String[] args){
		//一开始没有乘客。
		int count = 0;
		//第一站：上去一位乘客
		//在原有的基础上 + 1
		count = count + 1;
		//System.out.println(count);
		//第二站：上去两位乘客，下来一位乘客
		count = count + 2 - 1; 
		//第三站：上去两位乘客，下来一位乘客
		count = count + 2 - 1;
		//第四站：下来一位乘客
		count = count - 1;
		//第五站：上去一位乘客
		count = count + 1;
		//请问：到了终点站，车上一共几位乘客。
		System.out.println(count);//3
	}
}
```

## 5. ==数据类型==

### 5.1 Java语言==数据类型==的分类

- ==基本数据类型==
- 引用数据类型（面向对象的时候再深入学习）

### 5.2 基本数据类型的四类八种

| 数据类型 | 关键字  | 内存占用 |                 取值范围                  |
| :------: | :-----: | :------: | :---------------------------------------: |
|   整数   |  byte   |    1     |    负的2的7次方 ~ 2的7次方-1(-128~127)    |
|          |  short  |    2     | 负的2的15次方 ~ 2的15次方-1(-32768~32767) |
|          |   int   |    4     |        负的2的31次方 ~ 2的31次方-1        |
|          |  long   |    8     |        负的2的63次方 ~ 2的63次方-1        |
|  浮点数  |  float  |    4     |        1.401298e-45 ~ 3.402823e+38        |
|          | double  |    8     |      4.9000000e-324 ~ 1.797693e+308       |
|   字符   |  char   |    2     |                  0-65535                  |
|   布尔   | boolean |    1     |                true，false                |

#### 说明

​	e+38表示是乘以10的38次方，同样，e-45表示乘以10的负45次方。

​	在java中整数默认是int类型，浮点数默认是double类型。

#### 需要记忆以下几点

> byte类型的取值范围：
>
> ​	-128 ~ 127
>
> int类型的大概取值范围：
>
> ​	-21亿多  ~ 21亿多
>
> 整数类型和小数类型的取值==范围大小关系==：
>
> ​	double > float > long > int > short > byte

最为常用的数据类型选择：

- 在定义变量的时候，要根据实际的情况来选择不同类型的变量。

  比如：人的年龄，可以选择byte类型。

  比如：地球的年龄，可以选择long类型。

- 如果整数类型中，不太确定范围，那么默认使用int类型。

- 如果小数类型中，不太确定范围，那么默认使用double类型。

- 如果要定义字符类型的变量，那么使用char

- 如果要定义布尔类型的变量，那么使用==boolean==

### 5.3 定义8种基本数据类型变量

```java
public class VariableDemo3{
    public static void main(String[] args){
        //1.定义byte类型的变量
        //数据类型 变量名 = 数据值;
        byte a = 10;
        System.out.println(a);

        //2.定义short类型的变量
        short b = 20;
        System.out.println(b);

        //3.定义int类型的变量
        int c = 30;
        System.out.println(c);

        //4.定义long类型的变量
        long d = 123456789123456789L;
        System.out.println(d);

        //5.定义float类型的变量
        float e = 10.1F;
        System.out.println(e);

        //6.定义double类型的变量
        double f = 20.3;
        System.out.println(f);

        //7.定义char类型的变量
        char g = 'a';
        System.out.println(g);

        //8.定义boolean类型的变量
        boolean h = true;
        System.out.println(h);

    }
}
```

#### **注意点**

- 如果要定义 一个整数类型的变量，不知道选择哪种数据类型了，默认使用int。
- 如果要定义 一个小数类型的变量，不知道选择哪种数据类型了，默认使用double。
- 如果要定义一个long类型的变量，那么在数据值的后面需要加上L后缀。（大小写都可以，建议大写。）
- 如果要定义一个float类型的变量，那么在数据值的后面需要加上F后缀。（大小写都可以）

### 5.4 练习1

需求：定义5个变量记录老师的信息并打印

代码示例：

```java
public class VariableTest1{
	public static void main(String[] args){
		//1.定义字符串类型的变量记录老师的姓名
		String name = "牛马谢广坤";
		//2.定义整数类型的变量记录老师的年龄
		int age = 18;
		//3.定义字符类型的变量记录老师的性别
		char gender = '男';
		//4.定义小数类型的变量记录老师的身高
		double height = 180.1;
		//5.定义布尔类型的变量记录老师的婚姻状况
		boolean flag = true;
		//输出5个变量的值
		System.out.println(name);
		System.out.println(age);
		System.out.println(gender);
		System.out.println(height);
		System.out.println(flag);
		
	}
}
```

### 5.5 练习2

需求：将（电影名称，主演，年份，评分）四个信息选择不同类型的变量，随后打印出来。

 代码示例：

```java
public class VariableTest2{
	public static void main(String[] args){
		//1.定义字符串变量记录电影的名称
		String movie = "送初恋回家";
		//2.定义三个变量记录主演的名字
		String name1 = "刘鑫";
		String name2 = "张雨提";
		String name3 = "高媛";
		//3. 定义整数类型的变量记录年龄的年份
		int year = 2020;
		//4.定义小数类型的变量记录电影的评分
		double score = 9.0;
		
		//打印变量的信息
		System.out.println(movie);
		System.out.println(name1);
		System.out.println(name2);
		System.out.println(name3);
		System.out.println(year);
		System.out.println(score);
		
	}
}
```

### 5.6 练习3

需求：选择其中一部手机，将（手机价格，手机品牌）两个信息选择不同类型的变量，随后打印出来。 

 代码示例：

```java
public class VariableTest3{
	public static void main(String[] args){
		//1.定义小数类型的变量记录手机的价格
		double price = 5299.0;
		
		//2.定义字符串类型的变量记录手机的品牌
		String brand = "华为";
		
		//输出变量记录的值
		System.out.println(price);
		System.out.println(brand);
	}
}
```

## 6. 标识符

业内大多数程序员都在遵守阿里巴巴的命名规则。

### 6.1 硬性要求：

​	必须要这么做，否则代码会报错。

- ==必须由数字、字母、下划线_、美元符号$组成。==
- ==数字不能开头==
- ==不能是关键字==
- ==区分大小写的。==

### 6.2 软件建议：

​	如果不这么做，代码不会报错，但是会让代码显得比较low。

### 6.2.1 ==小驼峰命名法==

适用于变量名和方法名

* 如果是一个单词，那么全部小写，比如：name

* 如果是多个单词，那么从第二个单词开始，首字母大写，比如：firstName、maxAge

### 6.2.2 ==大驼峰命名法==

适用于类名

* 如果是一个单词，那么首字母大写。比如：Demo、Test。

* 如果是多个单词，那么每一个单词首字母都需要大写。比如：HelloWorld

不管起什么名字，都要做到见名知意。

> 小驼峰和大驼峰区别就是第一个是否大写，第一个大写就是大驼峰，繁殖小驼峰

### 阿里巴巴命名规范细节：

1. 尽量不要用拼音。但是一些国际通用的拼音可视为英文单词。

   正确：alibaba、hangzhou、nanjing

   错误：jiage、dazhe

2. ==平时在给变量名、方法名、类名起名字的时候，不要使用下划线或美元符号。==

   错误：_name

   正确：name

## 7.==Scaner键盘录入==

​	键盘录入的实际功能Java已经帮我们写好了，不需要我们自己再实现了，而Java写好的功能都放在了Scanner这个类中，所以，我们只要直接使用Scanner这个类就可以了。

使用步骤：

第一步：

​	导包：其实就是表示先找到Scanner这个类在哪。

```java
import java.util.Scanner;
```

第二步：

```java
Scanner s=new Scanner();
```

​	创建对象：其实就表示申明一下，我准备开始用Scanner这个类了。

第三步：

```java
s.nextInt();
```

​	接收数据：也是真正干活的代码。

代码示例：

```java
//导包，其实就是先找到Scanner这个类在哪
import java.util.Scanner;
public class ScannerDemo1{
	public static void main(String[] args){
		//2.创建对象，其实就是申明一下，我准备开始用Scanner这个类了。
		Scanner sc = new Scanner(System.in);
		//3.接收数据
		//当程序运行之后，我们在键盘输入的数据就会被变量i给接收了
		System.out.println("请输入一个数字");
		int i = sc.nextInt();
		System.out.println(i);
	}
}
```

## 1Java-API,JDK,JRE和IDE的区别

> - API是一组定义了软件组件之间交互的规范和协议。库，接口！
> - JDK是用于开发Java应用程序的软件包，包含了编译器、调试器、运行时环境、类库和其他工具。
> - JRE是用于运行Java应用程序的软件包，包含了Java虚拟机和Java类库。
> - IDE是集成开发环境，用于开发、编写和调试软件应用程序，提供了代码编辑器、编译器、调试器和其他辅助工具。

## 一个简单的java程序，jdk的组成，跨平台原理

```java
package input;
//import java.util.Scanner;

public class Hello {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		java.util.Scanner input=new java.util.Scanner(System.in);
		
       int a=input.nextInt();
		System.out.print(a);

	}

}
```

> 1. 每个java程序至少有一个类，每个类都要有自己的名字，而且要求是首字母大写。
> 2. 方法是包含语句的结构体
> 3. java中以;为每条语句的结束符
> 4. 保留字/关键字，class，public室友特殊含义的，不能用于其他目的，为变量或函数命名等操作
> 5. 用{}来划分代码块，块是可以嵌套的
> 6. ""来表示字符串

## Path环境变量

 ![image-20230905131704072](E:\MD\java\java从入门到入土.assets\image-20230905131704072.png)

![image-20230905131920109](E:\MD\java\java从入门到入土.assets\image-20230905131920109.png)

![image-20230905132321858](E:\MD\java\java从入门到入土.assets\image-20230905132321858.png)

没有配置之前

通过命令行是启动不了应用的

![image-20230905131527291](E:\MD\java\java从入门到入土.assets\image-20230905131527291.png)

![image-20230905131538492](E:\MD\java\java从入门到入土.assets\image-20230905131538492.png)

![image-20230905131600945](E:\MD\java\java从入门到入土.assets\image-20230905131600945.png)

添加环境变量后便可以在命令行启动exe应用程序了！！！

==系统变量和用户变量的区别，一个是全局一个是局部，所有用户和我的的区别==



## 创建，编译，执行java程序的步骤

1. 创建Java程序时，使用文本编辑器创建一个以`.java`为扩展名的Java源文件。

2. 编译Java程序时，使用`javac`命令将Java源文件编译成字节码文件（以`.class`为扩展名）。 

   javac Hello.java

3. 执行Java程序时，使用`java`命令来运行Java程序。JVM会加载字节码文件并执行其中的代码。

   java Hello

   ==这里运行.class文件的时候不能再加.class后缀了，这样的话相当于运行Heelo.class.class==

4. JVM会解释执行字节码文件中的指令。==它将逐条解释字节码指令，==并将其转换为特定机器上的机器语言指令。这使得Java程序可以在不同的操作系统和硬件平台上运行，而不需要重新编译。

   在运行java程序的时候

   JVM会用类加载器将==字节码==加载到内存中，如果还有别的类，则会保证你在用之前动态的加载他们

   JVM使用一个==字节码验证器==检验字节码的合法性

==***.java文件名必须与公共类名相同！==

这便体现了java的优点之一

1. java字节码可以在不同的硬件平台和操作系统上运行。
2. java可以在任意一个装有jvm虚拟机的计算机上运行
3. ==一次编译，处处可以用，编译产生的.class字节码文件拿到JVM上运行==
4. ![image-20230905130931022](E:\MD\java\java从入门到入土.assets\image-20230905130931022.png)

常见的错误

1. NoClassDefFoundError说明运行了一个找不到的.java文件
2. NosuchMethodError说明没有main方法或者敲错成了mian

---

![image-20230905130740382](E:\MD\java\java从入门到入土.assets\image-20230905130740382.png)

## ==第一章小结==

![3c776aa9423056cbefdf385c66957a8](E:\MD\java\java从入门到入土.assets\3c776aa9423056cbefdf385c66957a8.jpg)

# 第二章-基本程序设计

## 程序设计错误

1. 编译时的错误，语法错误,拼错关键字。。。
2. 运行时错误，有不可描述的程序，比如无限循环
3. 逻辑错误，让计算1+1了你写的程序是1-1



## 从控制台读取输入

```java
Scanner input=new Scanner(System.in);
```

语法new Scanner(System.in表明创建了一个Scanner类型的对象用于从标准输入流（键盘）读取用户输入。

> 首先，代码中的"Scanner"是一个类，它提供了一些方法来读取用户输入。
>
> 在创建Scanner对象时，需要传入一个InputStream对象作为参数，这里使用System.in作为参数，==表示从标准输入流读取输入。==
>
> 然后，将创建的Scanner对象赋值给一个名为"input"的变量，这样就可以通过该变量来调用Scanner对象的方法。
>
> 与之代替的方法
>
> ```java
> java.util.Scanner input=new java.util.Scanner(System.in);
> ```
>
> 通过这些方法，可以将用户输入的内容存储到相应的变量中
>
> nextInt(),nextDouble().........实例化出来的对象.next类型()方法读取对应的数据

## jdk的选择与安装

![image-20230905124519672](E:\MD\java\java从入门到入土.assets\image-20230905124519672.png)

![image-20230905124949092](E:\MD\java\java从入门到入土.assets\image-20230905124949092.png)

![image-20230905125124593](E:\MD\java\java从入门到入土.assets\image-20230905125124593.png)

![image-20230905130221819](E:\MD\java\java从入门到入土.assets\image-20230905130221819.png)

javac编译工具

java执行工具

## 掌握DOs窗口常见命令

> 切换盘符X:
>
> 查看当前路径的文件信息 dir
>
> 清屏 cls
>
> 前往指定路径 cd+路径
>
> cd ..上一级目录
>
> cd \进入盘的根目录

## java程序的执行原理

1. 计算机只能识别01，也就是机器语言
2. 汇编语言，汇编语言是一种低级语言，用于编写计算机程序。它使用与特定计算机体系结构相关的符号指令，以便直接控制计算机的硬件。
3. BUG虫子飞进去导致的bug，哈哈

## 赋值语句和复制表达式

==赋值语句将一个值赋值给变量，在java中复制语句可以作为一个表达式==

左右两边的类型要兼容

而且java可以a=b=c=2；这样连续赋值

## 命名常量

是一个调变不变值的标识符

java里的关键字是final

```java
final double PI=3.1415926;
```

常量必须在同一条语句中声明和赋值



## 命名规则

> 变量，方法，小写字母开头：dog如果包含多个单词第一个字母小写，后面每个单词的第一个字母大写smallPig
>
> 类名的首字母大写Student
>
> 常量的所有字母都大写PI，如果有多个单词，就用_连接

## 数据类型

| 类型   | 范围                                                   | 存储空间     |
| ------ | ------------------------------------------------------ | ------------ |
| byte   | -2<sup>7</sup>~-2<sup>7</sup>-1(127)                   | 8位带符号数  |
| short  | -2<sup>15</sup>~-2<sup>15</sup>-1(32767)               | 16位带符号数 |
| int    | -2<sup>31</sup>~-2<sup>31</sup>-1(2147483647)          | 32位带符号数 |
| long   | -2<sup>63</sup>~-2<sup>63</sup>-1(9223372036854775807) | 64位带符号数 |
| float  | -2<sup>31</sup>~-2<sup>31</sup>-1(2147483647)          | 32位带符号数 |
| double | -2<sup>63</sup>~-2<sup>63</sup>-1(9223372036854775807) | 64位带符号数 |

## 数值操作符

| 运算符 | 名字 | 实例      | 注意事项                                                     |
| ------ | ---- | --------- | ------------------------------------------------------------ |
| +      | 加   | 1+1=2     |                                                              |
| -      | 减   | 1-1=0     |                                                              |
| *      | 乘   | 2*3=6     |                                                              |
| /      | 除   | 3/2.0=1.5 | 除数不要为0，可以计算正负整数(二者其一为浮点数)，浮点数.     |
| %      | 取余 | 3%2=1     | 今天周六，10天后是周几？（6+10）%7，0代表周日，1代表周一...可以进项浮点数的取余，但是由于数据是以二进制存储的，误差很大的（2.4%0.5/=/=0.40000001==且只有被除数是负数的时候结果才是负数== |

## 幂运算pow（Java.lang）

[数学方法](#math)

```java
double Math.pow(double a,double b);
```

计算a的b次方，注意数据类型

+ ==Math包是隐式导入的==

+ `Math.sqrt()`方法接受一个`double`类型的参数，并返回一个`double`类型的结果，表示该数的平方根。

+ 注意，`Math.sqrt()`方法只能计算非负数的平方根。如果给定的参数是负数，将会返回`NaN`（不是一个数字）。

+ ```java
  //		x*x-2*x-3=0
  		double a=1,b=-2,c=-3;
  		double x1,x2;
  		x1=(-b+Math.sqrt(b*b-4*a*c))/2*a;
  		x2=(-b-Math.sqrt(b*b-4*a*c))/2*a;
  		System.out.println(x1);
  		System.out.print(x2);
  //		3.0
  //		-1.0
  ```

  

## 字面值

字面值是程序中出现的常量值。。。

### 整形字面值

1. 首先不要超出对应数据类型的范围

2. 整形字面值默认是int类型的

3. ==为了表示long类型需要i在其后面加上一个L/l==

   1. 要表示二进制就要0B为前缀来表示

   2. 八进制前面使用0

   3. 十六进制前面用0X

      ```java
      		System.out.println(0X2323);
      		
      		System.out.println(02323);
      		
      		System.out.println(0B111);
      		8995
      	    1235
      	    7
      ```

> java允许一个数值字面值的两个数字之间使用下划线
>
> ```java
> int ss=32_23;
> long bb=233_32323_22;
> System.out.print(ss);
> System.out.print(bb);
> ```
>

### 浮点型字面值

1. ==默认带小数点的数是double类型的==

2. 要想加以区分就在后面加对应的F/f或者D/d；

2. ### ==整数加上后缀也可以表示为浮点数==

3. ```java
   		System.out.println(1/3.0);
      		System.out.println(1F/3.0F);
   //		0.3333333333333333//16
   //		0.33333334//8
   System.out.println((9D/5D)*sd+32);
   ```
   
   [浮点数的比较！！！！！！](#bijiaofudianshu)

## 科学计数法

> 1. 使用科学计数法表示数字：在Java中，可以使用**字母e或E来**表示科学计数法。例如，1.23e6表示1.23乘以10的6次方，即1230000。同样，1.23e-6表示1.23乘以10的负6次方，即0.00000123。
>
> 2. 科学计数法的数据类型：**Java中的浮点数类型（float和double）可以用来表示科学计数法的数字**。例如，可以使用float类型来表示1.23e6，或使用double类型来表示1.23e-6。
>
> 3. 科学计数法的输出格式：在Java中，可以使用***String.format()方法或System.out.printf()方法***来指定科学计数法的输出格式。例如，**可以使用"%.2e"来表示输出两位小数的科学计数法。**
>
>    ```java
>    		double a= 1.23456789e-10;
>    		final double min=1e-14;
>    //		System.out.print(a);
>    		//1
>    		String n=String.format("%.2E",a);
>    		System.out.println(n);
>    		//2格式化输出
>    		System.out.printf("%.3e",a);
>    ```
>
> 
>
> 4. 科学计数法的输入格式：在Java中，可以使用Scanner类的nextDouble()方法来读取科学计数法的输入。例如，可以使用scanner.nextDouble()来读取1.23e6。
>
> 5. 科学计数法的运算：在Java中，可以对科学计数法的数字进行各种数学运算，包括加法、减法、乘法和除法。例如，可以使用double result = 1.23e6 + 2.34e6来计算两个科学计数法数字的和。



## Printf()格式化输出

> printf是一个格式化输出方法，用于将格式化的字符串输出到控制台或文件中语法：
>
> ```java
> System.out.printf(format, arguments);
> ```
>
> 其中，==format是一个字符串==，==用于指定输出的格式==，==可以包含普通文本和格式化占位符==。arguments是一个==可选的参数列表==
>
> 格式化占位符的语法如下：
>
> ```
> %[flags][width][.precision]conversion
> ```
>
> ==flags是可选的标志==，用于指定输出的格式，如左对齐、右对齐、补零等。width是可选的字段宽度，用于指定输出的最小宽度。precision是可选的精度，用于指定浮点数的小数部分位数或字符串的最大长度。conversion是必需的转换字符，用于指定输出的类型，如整数、浮点数、字符串等。
>
> > %[flags]：标志位，用于控制输出的格式。常用的标志位包括：
> >
> > "-"：左对齐输出
> >
> > ```java
> > 		System.out.printf("%8d\n",1234);
> > 		System.out.printf("%-8d",1234);
> > //	    	1234
> > //	    1234 
> > ```
> >
> > "+"：在正数前面显示加号
> > "0"：用零来填充字段宽度
> > ==" "（空格）：在正数前面显示空格，负数前面显示负号==
> > "#"：对于八进制和十六进制，添加前缀0和0x
> > ","：在数字中使用逗号分隔(`以千分位划分也就是从右到左三个三个划分`)
> >
> > ```java
> > 		System.out.printf("%,d",1234339244);
> > //		1,234,339,244
> > ```
> >
> > [width]：字段宽度，用于指定输出的最小宽度
> >
> > [.precision]：精度，用于指定浮点数或字符串的输出精度。对于浮点数，精度表示小数点后的位数。对于字符串，精度表示输出的字符数。
> >
> > ---
> >
> > 使用`printf()`方法进行格式化输出时，**会对小数部分进行四舍五入**。如果小数部分的第二位小于5，则向下舍入；如果小数部分的第二位大于等于5，则向上舍入
> >
> > ---
> >
> > conversion：==转换字符，用于指定要输出的数据类型==
> >
> > %：输出百分号
> > d：输出整数
> > f：输出浮点数
> > s：输出字符串
> > c：输出字符
> > x：输出十六进制整数（小写字母）
> > X：输出十六进制整数（大写字母）
> > o：输出八进制整数
> > b：输出布尔值
> > e：输出科学计数法表示的浮点数（小写字母）
> > E：输出科学计数法表示的浮点数（大写字母）
>
> 

> 以下是一些常用的格式化占位符：
>
> - %d：输出整数
> - %f：输出浮点数
> - %s：输出字符串
> - %c：输出字符
> - %b：==输出布尔值==
> - %x：输出十六进制数
> - %o：输出八进制数
> - %3：标准科学计数法形式的数
>
> ==如果后面对应项需要比指定宽度更多的空间，宽度会自动增加！==
>
> ```java
> printf("%3d",123434);
> //123434
> ```
>
> 以下是一些示例：
>
> ```java
> int num = 10;
> double pi = 3.14159;
> String name = "John";
> 
> System.out.printf("num = %d\n", num);
> System.out.printf("pi = %.2f\n", pi);
> System.out.printf("name = %s\n", name);
> ```
>
> 输出结果为：
>
> ```
> num = 10
> pi = 3.14
> name = John
> ```
>
> **printf方法不会自动换行，如果需要换行可以在格式化字符串中使用\n。**

## **表达式求值以及操作符优先级

1. 首先计算乘法，除法，取余，如果包含若干个乘除取余运算从左到右

2. 最后执行加减法，如果包含若干个加减法就从左到右

3. 3+4 * 4+5 * （4+3）-1

   先计算括号，然后是计算左边的乘法，然后是右边的乘法，最后综合

4. ==使用除法的时候要小心，默认是会剔除掉小数部分的，除数和被除数有一方含有小数点就会算出带小数点的结果==



## 显示当前时间GMT（格林尼治标准时间）

```java
System.currentTimeMillis()得到的是long类型的数据
```

这个是GMT（格林尼治标准时间）

```java
		long allms=System.currentTimeMillis();
		long h,m,s;
		//得到总秒数
		long alls=allms/1000;
		//得到当前的秒数
		s=alls%60;
		//得到总分钟数
		long allm=alls/60;
		//得到当前的分钟数
		m=allm%60;
		//得到总小时数
		long allh=allm/60;
		//得到当前小时
		h=allh%24;
		System.out.print(h+":"+m+":"+s);
```

```java
		int of=input.nextInt();
		LocalDateTime now=LocalDateTime.now();
		System.out.println(now);
		
		LocalDateTime oftime=now.plusHours(of);
		System.out.print(oftime);
//		使用now.plusHours(offset)将当前时间加上偏移量，得到在指定时区的时间。
如果用户输入的时区偏移量为+2，程序将显示当前在GMT+2时区的时间。

```

-----------

-----------

## 获取本地时间

```java
import java.time.LocalDateTime;
LocalDateTime now=LocalDateTime.now();获取本地时间
    System.out.println(now);
    2023-09-15T10:15:19.411448700
```



## 增强赋值操作运算符

+-*/%可以结合=形成增强操作符

count+=1

=》count=count+1；

==既可以构成赋值语句又是赋值表达式==

## 自增自减运算符

a++，++a；

a--,--a;

```java
		int a=1;
		int num=10*a++;//先用后增
//		a=a+1;
		System.out.println("num是"+num+"\na是"+a);
		
		int i=1;
//		i=i+1;
		int n=10*++i;//先增加后用
		System.out.println("n是"+n+"\ni是"+i);
		
		
```

> java从左到右对操作数求值
>
> 在右边操作数的任何部分被求值之前
>
> ==二元操作符左边的操作数先求值==
>
> int i=1;
>
> int k=++i + i*3;=============================================8
>
> *的左边先求出来再进行运算

## 数值类型转换（拓展类型/缩小类型）

通过显示转换浮点数可以转换为整数

1. java可以自动扩展类型，也就是小数据类型可以默认转换为大数据类型

2. 也就是==总可以将一个数值赋值给支持更大数据范围的类型的变量==

   ```java
   shor a=1;
   int b=2;
   b=a;
   
   //大到小就得显示转换
   a=(short)b;
   ```

3. 类型转换不改变被转换的变量

   也就是说

   ```java
   double d=4.8;
   int i=(int)d;
   d还是4.8
   ```

4. ```jav
   x1 op=x2;
   其实是x1=(T)(x1 op x2);
   T是x1的数据类型！
   ```

   ## 常见错误和陷阱

   + 未声明，未初始化的变量和未使用的变---》变量必须再使用前声明为一个类型并赋值
   + 整数溢出---》不要超过数据类型的范围
   + 舍入的错误---》==设计浮点数的计算都是近似的==，==整数可以精确的存储==
   + 非预期的整数除法，整数除以整数得不到浮点数，只要任意一个带了小数点就可以得到小鼠

## ==第二章小结==

![image-20230907133937371](E:\MD\java\java从入门到入土.assets\image-20230907133937371.png)

# 第三章-选择

## 选择

1. Boolean数据类型

+ 只有两个值，1，0，true，false==》字面值

==6种比较运算符==

> + \>
> + \>=
> + \<
> + \<=
> + \==
> + ==

==比较结果是一个bool值==

### if语句

```java
if(布尔表达式)
{
System.out.print("我是帅比");
}
if(1+1==2)
System.out.print("我是帅比");
//System.out.print("我是帅比dasdasdas")不执行
```

**如果if里面的条件成立就执行后面的语句，默认是只执行紧挨着的一句**

**通过{}可以执行这个代码块**

### 双分支if-else语句

```java
if(布尔表达式)
{
布尔表达式为true的时候执行
}
else
{
布尔表达式为false的时候执行
}
```

### 嵌套的if语句和多分枝if-else语句

```java
if(score>=90)
System.out.print("A");
else
	if(score>=80)
	System.out.print("B");
	else
		if(score>=70)
		System.out.print("C");
		else
			if(score>=60)
			System.out.print("D");    
			else
			System.out.print("E");            

等价于 避免深度缩进

if(score>=90)
System.out.print("A");
else if(score >=80)
System.out.print("B");
else if(score >=70)
System.out.print("C");
else if(score>=60)
System.out.print("D");
else
System.out.print("E");
```

### 常见错误和陷阱\*|*|*|*|*|*|

<a name="bijiaofudianshu"></a>

> 1. if（）下有多条语句的时候没有加{}
>
> 2. if（a>0）;逻辑错误，默认执行了个寂寞
>
> 3. 对布尔值的多余测试if(a==true)不如if(a)
>
> 4. 悬空else出现的歧义 ==在同一个块中else总是和理他最近的if匹配
>
>    ```java
>    		if(i>j)
>    			if(i>k)
>    				System.out.print("sdad");
>    			else
>    				System.out.print("dswedwr342");
>    ```
>
> 5. ==两个浮点数值的相等测试==
>
>    通常同10^-7^来比较float
>
>    用10^-14^来比较double
>
>    x-b<这个值
>
>    ```java
>    		double x=1.0-0.1-0.1-0.1-0.1-0.1;
>    		System.out.println(x);
>    //		0.5000000000000001
>    		System.out.println(x==0.5);
>    		//false
>    		final double min=1e-14;
>    		if((x-0.5)<min)
>    			System.out.print("浮点数比较大小测试");
>    ```
>
> 6. 简化布尔变量赋值
>
>    ```java
>    if(n%2==0)
>    	even=true;
>    else
>    	even=false;
>    plus版本
>    boolean even=n%2==0;
>    ```
>
> 



### 随机数的产生

Math.random（）来产生[0,1)的随机数，==返回类型为double==

`a=(int)(Math.random()*10);`会得到[0,10)的随机数0-----9

---

在Java中，`Math.random()`方法返回一个**0到1之间的随机浮点数**。要生成指定范围的随机数，您可以使用以下方法：

1. 生成0到指定范围的随机数：假设您要生成0到n（包括n）之间的随机整数，可以使用以下代码：

   ```java
   int randomNumber = (int) (Math.random() * (n + 1));
   ```

   这将生成一个介于0到n之间的随机整数。

2. 生成指定范围内的随机数：假设您要生成a到b之间（包括a和b）的随机整数，可以使用以下代码：

   ```java
   int randomNumber = (int) (Math.random() * (b - a + 1)) + a;
   ```

   这将生成一个介于a到b之间的随机整数。

请注意，`Math.random()`方法返回的是一个浮点数，所以我们需要使用强制类型转换将其转换为整数。另外，**生成的随机数是一个伪随机数**，**每次运行程序时都会生成不同的数值。**

## 逻辑操作符

| 操作符 | 名称 | 说明     |
| ------ | ---- | -------- |
| ！     | 非   | 逻辑非   |
| &&     | 与   | 逻辑与   |
| \|\|   | 或   | 逻辑或   |
| ^      | 异或 | 罗伊异或 |

**异或的时候^^^^^^^^^^^^^^^**

**真假 true**

**假真 true**

**真真 false**

**假假 false**

> 1. 使用逻辑与操作符判断多个条件：
>
>    ```java
>    if (condition1 && condition2 && condition3) {
>        // 执行代码
>    }
>    ```
>
>    只有当所有条件都为true时，才会执行相应的代码。
>
> 2. 使用逻辑或操作符判断多个条件：
>
>    ```java
>    if (condition1 || condition2 || condition3) {
>        // 执行代码
>    }
>    ```
>
>    只要有一个条件为true，就会执行相应的代码。
>
> 3. ```java
>    if(x%2==&&x%3==0),x同时被2，3整除
>    if(x%2==0||x%3==0),x被2或者3整除
>    if(x%2==0^x%3==0),x是否被2或者3整除蛋不能同时被着两者整除
>    ```
>
> 4. 德摩根定律
>
>    ```java
>    if(!(x%2==&&x%3==0))
>    等价
>    if(x%2!=||x%3！=0)
>    ```
>
>    

### 判定闰年

闰年2月29天

```java
		Scanner input=new Scanner(System.in);
		while(true)
		{
			int a=input.nextInt();
			if(((a%4==0)&&(a%100!=0))||(a%400==0))
			{
				System.out.print("这甜蜜是闰年");
			}
			elses
			{
				System.out.print("这甜蜜是平平年");
			}
		}
```

## Switch语句

`在Java中，`switch`语句的参数可以是整数类型（包括`byte`、`short`、`int`和`long`）、字符类型（`char`）以及枚举类型（`enum`）。`

switch里还可以是表达式

`case 表达式必须是常量表达式`

```java
public class Hello {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("请输入第一个浮点数：");
        float num1 = input.nextFloat();

        System.out.println("请输入第二个浮点数：");
        float num2 = input.nextFloat();

        System.out.println("请输入运算符（+、-、*、/）：");
//        next函数获取字符串，,charAt(0)是获取指定的字符
        char operator=input.next().charAt(0);

        float result = 0;

        switch (operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            default:
                System.out.println("无效的运算符");
                return;
        }

        System.out.println("运算结果：" + result);
    }
}

```

案例2

```java
package singl;
import java.util.Scanner;
public class H {

	public static void main(String[] args) {
		// TODO 自动生成的方法存
		Scanner input=new Scanner(System.in);
		System.out.println("输入你的出生年");
		System.out.println("1900是鼠年");
//		System.out.println(1900%12);
		int b;
		while(true)
		{
			b=input.nextInt()%12;
			switch(b) {
			case 0:
			{
				System.out.println("猴子");
				break;
			}
			case 1:
			{
				System.out.println("鸡");
				break;
			}
			case 2:
			{
				System.out.println("狗");
				break;
			}
			case 3:
			{
				System.out.println("猪");
				break;
			}
			case 4:
			{
				System.out.println("老鼠");
				break;
			}
			case 5:
			{
				System.out.println("牛");
				break;
			}
			case 6:
			{
				System.out.println("虎逼");
				break;
			}
			case 7:
			{
				System.out.println("兔子");
				break;
			}
			case 8:
			{
				System.out.println("辰龙");
				break;
			}
			case 9:
			{
				System.out.println("蛇");
				break;
			}
			case 10:
			{
				System.out.println("午马");
				break;
			}
			case 11:
			{
				System.out.println("沸羊羊");
				break;
			}
		}
		}
		
		
	}

}

```

**1900是老鼠也就是说年费对12取余等于4 的时候是老鼠，往后推11的时候是🐏**

**再推0是猴子-》4**

## 条件操作符(三元操作符)

```java
if(x>0)
y=1;
else
y=-1;
y=(x>0):1?-1;
```

## 操作符的优先级和结合规则

![IMG_20230910_142248](E:\MD\java\java从入门到入土.assets\IMG_20230910_142248.jpg)

1. 先计算括号内的，如果括号有嵌套的就先算内层的括号
2. 除了赋值操作符伊娃uii，所有的二元操作符都是左结合的

## 调试

jdk含有一个jdb

## ==第三章小结==



![image-20230910143043486](E:\MD\java\java从入门到入土.assets\image-20230910143043486.png)

12：除了赋值操作符伊娃uii，所有的二元操作符都是左结合的

# 第四章-数学函数，字符和字符串

## 常用数学函数

<a name="math"></a>

### 三角函数方法

| 方法              | 描述           |
| ----------------- | -------------- |
| sin(radians)      | 弧度计算sin    |
| cos(radians)      | 弧度计算cos    |
| tan(radians)      | 弧度计算tan    |
| toRadians(degree) | 角度转换为弧度 |
| toDegree(radians) | 弧度转换为度数 |
| asin(a)           | 弧度计算反sin  |
| asin(a)           | 弧度计算反cos  |
| atan(a)           | 弧度计算反tan  |

都返回浮点数

```java
		System.out.println(Math.sin(Math.toRadians(90)));
		System.out.print(Math.cos(Math.PI));
```

1.0 -1.0

### 指数函数方法

| 方法     | 描述          |
| -------- | ------------- |
| exp(x)   | e<sup>x</sup> |
| log(x)   | lnx           |
| log10(x) | lgx           |
| pow(a,b) | a<sup>b</sup> |
| sqrt(x)  | 根号下x       |

```java
		System.out.println(Math.log(3));
		System.out.println(Math.log10(100));
		System.out.println(Math.pow(3, 3));
		System.out.println(Math.sqrt(2));
		System.out.println(Math.exp(1));
//		1.0986122886681098
//		2.0
//		27.0
//		1.4142135623730951
//		2.718281828459045
```



### 取整方法

| 方法          | 描述                                                         |
| ------------- | ------------------------------------------------------------ |
| ceil(double)  | 天花板得到x向上取整与他最接近的整数1.2-》2，-1.2-》-1考虑正负号 |
| floor(double) | 地板 得到x向下取整与他最接近的整数1.2-》1，-1.2-》-2考虑正负号 |
|               |                                                              |
| round(double) | 小数点后第一位<5得到整数部分，=5，正数运算结果加1，负数运算结果为整数部分，**>5运算结果的绝对值加1 ，正负号不变** |

```java
		System.out.println(Math.round(-1.6));//-2
		System.out.println(Math.round(1.6));//2
		System.out.println(Math.round(-1.5));//-1
		System.out.println(Math.round(1.5));//2
```

### min,max,abs方法

| 方法 | 描述                |
| ---- | ------------------- |
| min  | 返回两个数的最小值  |
| max  | 返回两个数的最大值  |
| abs  | 返回一个数 的绝对值 |

![image-20230910150355108](E:\MD\java\java从入门到入土.assets\image-20230910150355108.png)

在Java中，**整数类型可以自动转换为浮点数类型**。这意味着，如果一个函数的参数是浮点数类型（如`float`或`double`），你可以传入整数作为实际参数，Java会自动将整数转换为对应的浮点数类型。

这种自动类型转换是由Java的类型提升规则决定的。`类型提升是指将低精度的数据类型自动转换为高精度的数据类型`。在整数和浮点数之间的类型提升中，整数类型会被自动提升为浮点数类型。

```java
System.out.println(Math.max(2, 3.1));
2就默认转换为了double类型
```

## 字符数据类型和操作

字符数据类型表示单个字符

```java
char a='a';
char b='2'
```

```java
"A",,,,'A'分别是字符串和字符
```

+ 字符串字面值必须放在""双引号里
+ 字符字面值必须放在''单引号里

## uiicodeh和ANCII

Unicode是一种字符编码标准，它为世界上几乎所有的字符都分配了一个唯一的数字代码点。Unicode字符集包含了各种语言的字符、标点符号、数学符号、货币符号、表情符号等。

ASCII码（American Standard Code for Information Interchange，美国信息交换标准代码）是一种字符编码标准，它使用7位二进制数（即128个不同的值）来表示字符。ASCII码最初是为英语和西欧语言设计的，它包含了英文字母、数字、标点符号等常见字符。

Unicode编码是ASCII码的超集，它包含了ASCII码中的字符，并且还增加了更多的字符。Unicode使用更多的位数（通常是16位或32位）来表示字符，以便能够表示更多的字符。

在Java中，字符类型`char`使用Unicode编码表示字符。你可以使用Unicode码点来表示字符，例如`char c = '\u0041';`表示字符'A'。Java中的字符串类型`String`也是使用Unicode编码表示的，可以包含任意字符。

**一个十六位的unicode占2个字节、u开头的四位16进制数表示**

\u0000------\uffff

### ==常用字符的ASCII码==

<a name="ANCII"></a>

| 字符    | 十进制编码值 | unicode       |
| ------- | ------------ | ------------- |
| '0'-'9' | 48-57        | \u0030-\u0039 |
| 'a'-'z' | 65-90        | \u0041-\u005A |
| 'A'-'Z' | 97-+(25)122  | \u0061-\u007A |

```java
char a='a';
等价
char a='\u0030';
		char a='\u0032';
		System.out.println(a);
```

## 特殊字符的转义序列

| 转义序列 | 名称        |
| -------- | ----------- |
| \b       | 退格        |
| \t       | tab，制表符 |
| \n       | 换行符      |
| \f       | 换页符      |
| \\ \     | \           |
| \\"      | "           |
|          |             |

```java
System.out.println("sdadsa\bdw");
sdadsbdw
```

## 字符型数据与数值型数据之间的转换

```java
		char c = '9';
		int num =Character.getNumericValue(c);
		int b=65;
//		char d=Character.toString(b).charAt(0);
//		String d=Character.toString(b);
		String d=Character.toString((char)b);//A
//		String d=Character.toString(('+'));//"+"
		System.out.println(num); 	// 输出：9
		System.out.println(d);//
//抗御得到对应的字符串
但是，参数为字符或者code
    1. 强制转换(char)int 65,就得到'A'这个字符了然后再得到单独的字符串"A"
	2. 得到a对应的ASCII码对应的字符Character.toString((a)
    得到"对应字符"
```

> 在Java中，`字符类型`char`可以与数值类型进行相互转换。`可以使用强制类型转换将字符类型转换为数值类型，或将数值类型转换为字符类型。
>
> 1. 将字符类型转换为数值类型：可以将字符类型转换为整数类型或浮点数类型。字符类型可以直接与整数类型进行运算，因为字符类型实际上是使用Unicode编码表示的整数。例如，将字符类型转换为整数类型可以使用强制类型转换，如下所示：
>
> ```java
> char c = 'A';
> int num = (int) c;
> ```
>
> 在上面的例子中，字符`'A'`被转换为整数类型，并赋值给变量`num`。
>
> 1. 将数值类型转换为字符类型：可以将整数类型或浮点数类型转换为字符类型。需要注意的是，只有当数值在`char`类型的表示范围内时，才能进行转换。例如，将整数类型转换为字符类型可以使用强制类型转换，如下所示：
>
> ```java
> int num = 65;
> char c = (char) num;
> ```
>
> 在上面的例子中，整数`65`被转换为字符类型，并赋值给变量`c`。

## 字符的比较与测试is函数

```
if('a'>'A')
实际上比较的是ANCII码
```

![IMG_20230910_154944](E:\MD\java\java从入门到入土.assets\IMG_20230910_154944.jpg)



## String类型

```java
String str="hello world";
```

String实际上与System的Scanner类一样

String不是基本数据类型而是引用类型

`任何java类都可以作为引用类型来声明一个变量，使用引用类型声明的变量是引用变量`

str就是一个引用变量，引用有一个内容为"hello world"的字符串对象

### 常用的String实例化方法，`空白字符`

<a name="charAt"></a>

> 常用的String方法------------------------------`实例方法`，在一个实例化对象的基础上进行的
>
> | 方法                          | 描述                                         |
> | ----------------------------- | -------------------------------------------- |
> | length()                      | 返回字符串中的字符数"hello"返回5             |
> | charAt(index)                 | `返回字符串中指定位置的字符`                 |
> | concat(s1)                    | `把sq串连接起来，并且返回一个心字符串`       |
> | [toUpperCase()](#toUpperCase) | 返回一个新的字符串，字符串的所有大写字母集合 |
> | toLowerCase()                 | 返回一个新的字符串，字符串的所有小写字母集合 |
> | [trim](#trim)                 | 返回一个新字符串，`去掉了两边的空白字符`     |
>
> 在Java中，==空白`字符`是指在字符串中不可见的字符，包括空格、制表符、换行符等。==没有\b
>
> ' ',    \t     \f     \r    \n
>
> Java中常见的空白字符有以下几种：
>
> 1. 空格字符（Space）：用于在字符串中分隔单词或语句。在Java中，空格字符的Unicode码是`\u0020`，可以使用空格字符的字面值或转义字符来表示，例如`char space = ' ';`或`char space = '\u0020';`。
> 2. 制表符（Tab）：用于在字符串中进行对齐。在Java中，制表符的Unicode码是`\u0009`，可以使用制表符的字面值或转义字符来表示，例如`char tab = '\t';`或`char tab = '\u0009';`。
> 3. 换行符（New Line）：用于在字符串中换行。在Java中，换行符的Unicode码是`\u000A`，可以使用换行符的字面值或转义字符来表示，例如`char newLine = '\n';`或`char newLine = '\u000A';`。
>
> 除了上述常见的空白字符外，Java还提供了其他一些空白字符，如==回车符（`\r`）和换页符（`\f`）==

### 引入`静态方法`和`实例方法`

<a name="静态方法和实例方法"></a>

静态方法也就是非实例方法

**静态方法的调用：类名.方法名字---------------------Math.pow(a,b);**

**实例方法的调用:已有对象str-----str.length();**

### 获取字符串的长度

```java
		String str="hello";
		System.out.print(str.length());//5

----------------------
    java 允许在不要撞见新变量的情况下直接引用字符串
    System.out.print("hello world".length());//11
```

`String的下标访问[0,len-1]`;

`保证不下标越界`

### 从字符串中获取字符

```java
		String str="hello";
		char c=str.charAt(4);
		System.out.print(c);//o
```

输入单个字符

```java
Scanner input=new Scanner(System.in);
char c=input.next().charAt(0);
```

### 连接字符串



```java
		String str="hello";
		String str1="java";
		String newstr=str.concat(str1);
		System.out.print("连接后的新字符串是"+newstr);
```

因为连接字符串操作非常常见，+ 也代表了连接字符串

```java
		String str="hello";
		String str1="java";
		
		String newstr=str+str1;
		
		System.out.print("连接后的新字符串是"+newstr);
```

》》》》》》》》》》》》

> 1. +号可以连接数字和字符串
>
> 2. `二者至少有一个是字符串，另一个不是字符串的时候会被转换为字符串，再进行连接`
>
> 3. ```java
>    	String str="hello";
>    	System.out.print(str+1);
>    	int a=65;
>    	int b=66;
>    	System.out.print(Character.toString(a)+Character.toString(b));//AB
>    ```
>
> 4. ```java
>    		int i=1,j=2;
>       		System.out.println("i+j"+i+j);//i+j12
>    "i+j"首先和i进行连接，然后得到"i+ji"再和j连接
>    等价于
>    		System.out.println((("i+j"+i)+j));//i+j12
>    		                                                                     
>    		System.out.println("i+j"+(i+j));//i+j3
>    ```

### 字符串的转换

<a name="toUpperCase"></a>

```java
		String str="Hello";
		String lowerstr=str.toLowerCase();
		String upperstr=str.toUpperCase();
		System.out.println(lowerstr);//hello
		System.out.println(upperstr);//HELLO
```

其实就是原来是大写，原来 是小写的转换为大写

trim方法，删除字符串两端的空白字符，抗御有多个，但是不能删除在字符串内部的空白字符

<a name="trim"></a>

```java
		String str=" \t\thello,+\r\n\f";
		System.out.println(str);
		String newstr=str.trim();// 		hello,+
		System.out.println(newstr);//hello,+
```

### 从控制台读取字符串

1. Scanner的对象的next（）方法

   `next方法以空白字符结束的字符串`

   ```java
   		
   		Scanner input=new Scanner(System.in);
   		String str=input.next();
   		System.out.print(str);
   hello world
   hello
   ```

2. Scanner的对象的nextline()方法

   `nextline以按下回车键为结束的字符串`

   ```java
   		
   		Scanner input=new Scanner(System.in);
   		String str=input.nextLine();
   		System.out.print(str);
   hello world
   hello world
   ```

### 字符串比较

![IMG_20230910_180050](E:\MD\java\java从入门到入土.assets\IMG_20230910_180050.jpg)



按照的是对应数值的比较

```java
		String str="hello";
		String str1="HeLlo";
		
		String son="lo";
		String noson="dasdasdasd";
//		System.out.println();
		System.out.println("严格判断是否相等"+str.equals(str1));//0
		System.out.println("忽略大小写比较结果"+str.equalsIgnoreCase(str1));//1
		
		
		System.out.println("一个一个紧挨着做减法直到比较出结果"+str.compareTo(str1));//32
		System.out.println("忽略大小写其实就是一个是大写一个是小写就算他们相等"+str.compareToIgnoreCase(str1));//0
		
		
		System.out.println(str.startsWith("he"));//1
		System.out.println(str.endsWith("ello"));//1
		
		System.out.println(str.contains(son));//1
		System.out.println(str.contains(noson));//0
```



> 如果使用\>=\<=\>\<去比较字符串的话就会发生语法错误，应该用compareTo

### 获得子字符串

[charAt(index)](#charAt)得到的是得到特定的字符

`String类包含的获取子串的方法`

| 方法                           | 描述                                              |
| ------------------------------ | ------------------------------------------------- |
| substring(beginindex)          | 返回该字符串的子串，从beginindex开始到字符串末尾  |
| substring(beginindex,endindex) | ==返回该字符串的字串，[从beginindex到enindex-1]== |

```java
		String str="hello world1111";
		System.out.println(str.substring(2));//llo world1111
		System.out.print(str.substring(6,11));//world
```

## 获取字符串中的字符或者字串

`String类包含获取字串的方法`

==找字符串的时候找到的时候返回的是子字符串的第一个对应的下nihaonihaoyawowoshioshizhangzhenxingh标==

| 方法                      | 描述                                                         |
| ------------------------- | ------------------------------------------------------------ |
| indexOf(char)             | 从头开始找的第一个字符,找到返回下标，找不到返回-1            |
| indexOf(char,index)       | 从指定的位置开始找的第一个字符,找到返回下标，找不到返回-1    |
| indexOf(String)           | 从头开始找的第一次出现的字符串,找到返回下标，找不到返回-1    |
| indexOf(String,index)     | 从指定的位置开始开始找的第一次出现的字符串,找到返回下标，找不到返回-1 |
| lastIndexOf(char)         | 从尾巴开始找的第一个字符,找到返回下标，找不到返回-1          |
| lastIndexOf(char,index)   | 从指定的位置往前开始找的第一个字符,找到返回下标，找不到返回-1 |
| lastIndexOf(String)       | 从尾巴开始找的第一次出现的字符串,找到返回下标，找不到返回-1  |
| lastIndexOf(String,index) | 从指定的位置往前开始找的第一次出现的字符串,找到返回下标，找不到返回-1 |

```java
		String str="hellow sseworlld";
//		System.out.println(str);
		System.out.println("从头开始找的第一个字符"+str.indexOf('e'));
		System.out.println("从指定的位置开始找的第一个字符"+str.indexOf('e',3));
		System.out.println("从头开始找指定的字符串"+str.indexOf("ll"));//2
		System.out.println("从指定的位置开始找指定的字符串"+str.indexOf("ll",5));//13
//		从头开始找的第一个字符1
//		从指定的位置开始找的第一个字符9
//		从头开始找指定的字符串2
//		从指定的位置开始找指定的字符串13
```

lastindexof只不过是从屁股开始找的而已，换了个方向，一个是有1个参数的一个是有两个参数的重载版本

![image-20230910183623904](E:\MD\java\java从入门到入土.assets\image-20230910183623904.png)

## String.format

```
		String s=String.format("%x",111);
		System.out.print(s);
```

> 在Java中，`%b`、`%o`、`%x`等是格式化字符串中的占位符，用于将数据以指定的格式进行格式化输出。
>
> - `%b`：用于将整数或布尔值格式化为布尔字符串。如果整数为0或布尔值为false，则输出字符串"false"；如果整数为非零或布尔值为true，则输出字符串"true"。
> - `%o`：用于将整数格式化为八进制字符串。
> - `%x`：用于将整数格式化为十六进制字符串（小写字母）。
>
> 再利用Integer.parseint(得到的string，对应的进制)；；；int
>
> ```
> 		String b=String.format("%o\n",111);
> 		System.out.print(b);
> 		int b1=Integer.parseInt("157", 8);
> 		System.out.print(b1);
> //		int b1=Integer.parseInt("b", 8);
> ```
>
> 直接用parseint，第二个重载的时候才是parseint的第二个重载是

## ==第四章小结==

![image-20230912095933209](E:\MD\java\java从入门到入土.assets\image-20230912095933209.png)

![image-20230912100018084](E:\MD\java\java从入门到入土.assets\image-20230912100018084.png)

# 第五章-循环

## while循环

```java
		while(循环继续条件))
		{
			循环体
		}

```

计数器控制的循环

```java
int count=0;
while(count<100)
{
System.out.print("dasdasd");
count++;
}

```

`只有当循环体只含有一条语句的时候或者不包含语句时花括号才可以省略`

CTRl+C可以强制退出无限循环

## for循环

在确定执行次数的时候使用for循环

```java
for(int i=0,int j=0;j<=0;i++)
{
System.out.print("dasdasd");
}
```



二者的等价转换

```java
for(;;;){
}
for(;true;){
}
while(true){
}
```

## Do while循环

```java
do
{
System.out.print("dasdasd");
}
while(true);

```

先执行循环体再判断是否继续



## 三者的选择

while和for都是前测循环

do-while是后测循环

## 嵌套循环

```java
		int count=0;
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<100;j++)
			{
				count++;
			}
		}
		System.out.print("执行了"+count+"次");
//		执行了10000次
		int count=0;
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<i;j++)
			{
				count++;
			}
			System.out.print(count+"-"+i+"\n");
//			System.out.print()
		}
		System.out.print("执行了"+count+"次");
//		执行了45次0+1+2+3+...9=45
```

## 注意事项

浮点数在计算机内就是近似表示的

`从大到小添加数字没有从小到大添加数字得到的值精确度高`



## ===求最大公约数

```java
		Scanner input=new Scanner(System.in);
		int a,b;
		a=input.nextInt();
		b=input.nextInt();
		int answer=0;
		for(int i=1;i<=a&&i<=b;i++)
		{
			if(a%i==0&&b%i==0)
			{
//				System.out.print("知道i到了 "+i);
				answer=i;
			}
		}
		System.out.print("最大公约数为"+answer);
//		12
//		16
//		最大公约数为4
```

## ===十进制转换为16进制

```java
		Scanner input=new Scanner(System.in);
		int a=input.nextInt();
		
		String sum="";
		int x;
		if(a!=0)
		{
			x=a%16;
			char temp=(x>=0&&x<=9)? (char)(x+'0'):(char)(x-10+'A');
			sum+=temp;
			a/=16;
		}
		System.out.print(sum);
```

## ===十进制迅速转换为二进制

Integer里的tobinary

integer整数

binary二进制

```java
public class w1{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		int d=input.nextInt();
		String str = Integer.toBinaryString(d);
		System.out.print(str);	
	}                        	
}
```

## 关键字break和continue

`continue语句总是再一个循环内`

总是可以不编写含有break和continue的程序

break立即终止含有break的内层循环

continue是直接进入下一次迭代的条件判断（for）

## ===回文数

```java
		Scanner input=new Scanner(System.in);
		System.out.println("输入你的要判断的数");
		String str=input.nextLine();
		int len=str.length();
		System.out.println("输入回文数的长度为"+len);
		
		int start=0;
		int end=len-1;
		boolean b=true;
		while(start<=end)
		{
			if(str.charAt(start)!=str.charAt(end))
			{
				System.out.print("不是回文数！！！");
				b=false;
				break;
				
			}
			start++;
			end--;
		}
		if(b)
			System.out.print("是回文数！！！");
```

## ===判断素数

```java
		Scanner input=new Scanner(System.in);
		while(true)
		{
			System.out.println("输入你要判断是否为素数的数据");
			int n=input.nextInt();
			boolean flag=true;
			for(int i=2;i<=Math.sqrt(n);i++)
			{
				if(n%i==0)
				flag=false;
//				break;
			}
			if(flag&&n!=1)
				System.out.println("是素数！！！");
			else
				System.out.print("不是素数！");
		}
```

实验二的题目

`1不是素数，然后判断的时候从2开始到这个数的根号开始找到可以被整除的就立马不是素数了！`

```java
		int sum=0;
		for(int i=2;i<=100;i++)
		{
			boolean flag=true;
			//判断是否为素数
			for(int j=2;j<=Math.sqrt(i);j++)
			{
				if(i%j==0)
				{
					flag=false;
					break;
				}
				
			}
			if(flag)
			sum+=i;
		}
		System.out.print("100内的素数和为"+sum);
1060
```

## ===十六进制转换为10进制

`霍纳算法`

```java
		Scanner input=new Scanner(System.in);
		
		String ip=input.next();
		
		System.out.println("你输入的十六进制为"+ip);
		
		int sum=0;
		
		int len=ip.length();
		
		System.out.println("你输入的十六进制长度为"+len);
		
		String newip=ip.toUpperCase();
		System.out.println("最终的十六进制为"+newip);
		
		for(int i=0;i<len;i++)
		{
			int x=Character.isDigit(newip.charAt(i))?(newip.charAt(i)-'0'):(newip.charAt(i)+10-'A');
			sum=sum*16+x;
		}
		System.out.print("现在转换为10进制为"+sum);
```

## ===冒泡排序

```java
int[] a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
for (int i = 0; i < a.length - 1; i++) {
    for (int j = 0; j < a.length - 1 - i; j++) {
        if (a[j] > a[j + 1]) {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
    }
}
	//	foreach
		for(int t:a)
		{
			System.out.print(t+" ");
		}
```



## ==第五章小结==

![1694530979932](E:\MD\java\java从入门到入土.assets\1694530979932.jpg)

# 第六章-方法

## 方法/函数

`修饰词 返回值类型 方法名 {`

`函数体}`

==写在类里，不能嵌套在方法里==

例如

```java
public static int max(int a,int b)
{
return a>b?a:b;
}
```

==在函数定义里面的参数是形参==

==真正调用函数的时候传入的参数是实参==

## 声明和定义的区别

==定义是指明定义的项是什么，定义了个方法还是变量==

==是指给数据分配内存和数值存储数据==



在java中有返回值的方法也可以当语句使用



`调用函数的时候程序的控制权在函数里面，当函数执行完毕的时候程序的控制权就返回给了main函数`



main函数最独特的是因为他是由java虚拟机JVM调用从而启动程序的



> 对于带返回值的函数return是必须的
>
> `每当调用方法的时候系统就会创建一个活动记录也就是活动框架，也就是栈`，用`于保存方法的参数和变量`，
>
> 调用栈以`先进后出`的方式保存记录
>
> 假如有main方法调用了max方法max方法调用了min方法
>
> 那么就是现有main，然后是max，min，
>
> 然后执行min执行完出来，max执行完出来，main执行完，出来！
>
> `一旦儿子的方法结束就把程序控制还给调用者`



## 注意事项

```
	public static void sw()
	{
		System.out.print("Sdadas");
		return;
	}
	与main函数并列
	在Java中，方法的定义不能嵌套在其他方法中。
```

==在Java中，方法的定义不能嵌套在其他方法中。==

也就是自己写的函数不能写在已有的函数里甚至是main函数



​	`形参和实参的名字相同是没用影响的，`形参是方法中具有自身存储空间的变量，`局部变量是在调用到时候分配的，`当方法返回到调用这后他就消失了

## 按值传参

调用方法的时候就是`通过传递值方式将实参传递给形参的`

而且还有`参数顺序匹配的规则`也就是实参传递的时候`参数的类型和数量要和形参的是类型和数量保持一致`

## 类型兼容

==·类型兼容是指不需要经过显示的类型转换·==

实参的值就可以传递给形参将int传递给double的形参的时候

```java
		System.out.print(add(1,2));	
	}
	public static double add(double a,double b)
	{

		return a+b;

	}
```

## 模块化代码

可以把实现具体功能封装在一个方法中，就可以实现重复性使用和模块化管理了

## 重载方法

> 要求
>
> 在Java中，函数重载（Method Overloading）是指`在同一个类中定义多个具有相同名称但参数列表不同的方法`。通过函数重载，可以`根据不同的参数类型和参数个数来区分不同的方法`，并且可以根据需要调用不同的方法。
>
> 函数重载的规则如下：
>
> 1. `方法名称必须相同`。
> 2. `参数列表必须不同，可以是参数的个数、类型或顺序不同`。
> 3. ==返回类型可以相同也可以不同。==

```java
	 public static int add(int a, int b) {
	        return a + b;
	}
	    
    public static double add(double a, double b) {
        return a + b;
    }
    
    public static int add(int a, int b, int c) {
        return a + b + c;
    }
```

==java编译器会查找最精确匹配的方法，因为方法max(int ,int)比max（double,double）要更加精确==

`不用基于不同修饰符或返回值进行重载！`

## 方法抽象和逐步求精

`方法抽象`是va方法的使用和他的实现分离开来

让用户不知道是如何实现的情况下，就可以使用方法

方法的实现细节封装在方法内

对用户来说是隐藏的

`方法的抽象`可以用分支的策略逐步求精将大问题分解为各个小问题，子问题再分解

## 分治案例输入年月输出对应的日历

```java
package mypacage;
import java.util.Scanner;
public class Ca {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
//		System.out.println();
//		System.out.println("1800年的1.1为周三");
		System.out.println("输入年和月:");
		
		Scanner in=new Scanner(System.in);
		
		int year=in.nextInt();
		int month=in.nextInt();
		
		
		PrintHead(year,month);
		
//		System.out.println("是闰年嘛"+Isrunyear(year));
//		System.out.println((SumDays(year,month))%7);
		Print(year,month);
		
		
//		System.out.println();
	}
	//判断闰年
	public static boolean Isrunyear(int year)
	{
//		if((year%4==0&&year%100!=0)||(year%400==0))
//		return true;
//		else
		return (year%4==0&&year%100!=0)||(year%400==0);
	}
	//打印日历的头
	public static void PrintHead(int year,int month)
	{
		
		if(month==1)
			System.out.println("\t"+year+" Ja1"+"    ");
		else if(month==2)
			System.out.println("\t"+year+" Feb2"+"    ");
		else if(month==3)
			System.out.println("\t"+year+" March3"+"    ");
		else if(month==4)
			System.out.println("\t"+year+" Apri4"+"    ");
		else if(month==5)
			System.out.println("\t"+year+" May5"+"    ");
		else if(month==6)
			System.out.println("\t"+year+" J6"+"    ");
		else if(month==7)
			System.out.println("\t"+year+" J7"+"    ");
		else if(month==8)
			System.out.println("\t"+year+" A8"+"    ");
		else if(month==9)
			System.out.println("\t"+year+" Se9"+"    ");
		else if(month==10)
			System.out.println("\t"+year+" Oc10"+"    ");
		else if(month==11)
			System.out.println("\t"+year+" No11"+"    ");
		else
			System.out.println("\t"+year+" De12"+"    ");
		
		System.out.println("---------------------------");
		System.out.print("周一 周二 周三 周四 周五 周六 周日\n");
		System.out.println("---------------------------");
	}
	//打印身体
//	public static void PrintBody(int year,int month)
//	{
//		
//	}
	//得到1800年1.1到现在这个月的第一天有多少天
	public static long SumDays(int year,int month)
	{
		long sum=3;
		for(int i=1800;i<year;i++)
		{
			if(Isrunyear(i))
				sum+=366;
			else
				sum+=365;
		}

		for(int j=1;j<month;j++)
		{
			sum+=GetMonthDay(year,j);
		}
		return sum;
	}
	public static int GetMonthDay(int year,int month)
	{
		if((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12))
		{
			return 31;
		}
		else if((month==4)||(month==6)||(month==9)||(month==11))
			return 30;
		else {
			return Isrunyear(year)?29:28;
		}
	}
	public static void Print(int year,int month)
	{
		long aim=(SumDays(year,month))%7;
//		System.out.print("asdasdasdasd"+aim);
		if(aim==0)
		{
			for(int i=0;i<6;i++)	
			{
				System.out.printf("    ");
			}
		}
		else
		{
			for(int i=0;i<aim-1;i++)
			{
				System.out.printf("    ");
			}
		}
		for(int i=1;i<=GetMonthDay(year,month);i++)
		{

			System.out.printf("%-4d",i);
			if((aim+i-1)%7==0)
			System.out.print("\n");

		}
	}
	

}
```

## ==第六章小结==

![image-20230913221619811](E:\MD\java\java从入门到入土.assets\image-20230913221619811.png)

# 第七章-一维数组

## 声明和创建数组变量

```java
		int[] a;//声明    推荐
		int b[];//声明//不是最好的方法
		b=new int[10];//创建数组
		a=new int[20];//创建数组

		int []a=new int[] {1,2,3,4,5};
         int[] b = {1, 5, 6, 4, 2, 3};
二者等效，后者是简化版本，前者的后半身用于创建匿名数组
		
		System.out.print(a.length);
```

`不同于基本数据类型变量，声明一个数组变量的时候并不会给数组怕分配任何内存空间`

他只是创建一个对数组的引用的存储位置，==如果变量不包含对数组的引用，那么这个变量的值就是null==

除非数组已经被创建，否则不能给他分配任何元素

创建数组

```java
arryname=new elementType[arraysize]
```



## 匿名数组

```java
package Mypackage;
import java.util.Scanner;
import java.time.LocalDateTime;
public class w1 {
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
//		int []a=new int[] {1,2,3,4,5};
		
//		System.out.print(a.length);
		p(new int[] {1,2,3,4,5});
		//匿名数组

	}
	public static void p(int[] a)
	{
		for(int i=0;i<a.length;i++)
		{
			System.out.print(a[i]);
		}
	}
}

```

==一个数组变量看起来是存储了一个数组，其实他存储的是指向数组的引用==



## 数组大小和默认值*)(&)&*

==当给数组分配空间的时候，必须指定该数组的元素个数==

```java
b=new int[]; wrong
    
    
    
    char[] RandomCharArray=new char[100];yes
```



使用array.lenth可以得到数组的长度
创建数组后元素默认值是0

char类型的默认值是\0000

bool类型的默认值是false



## 访问数组

通过下标访问，从【0，length-1】

## 数组初始化的简写

必须指定大小的写法

```java
int []a=new int[10];
```

声明+创建一气呵成

```java
		int []c;
		c= {1,2,3,45};
//数组常量只能在初始化操作中使用
一行写
int []a= {1,2,3,4,5,6,7,8,9,0};
		int []a=new int[] {1,2,3,4,5};
		
		System.out.print(a.length);
```

当给创建数组声明创建和初始化必须放在一行中，否则会产生语法错误

且不需要指出大小

`int []a= {1,2,3,4,5,6,7,8,9,0};` 就是一种不指定大小的数组初始化方式。在这种情况下，编译器会根据大括号中的初始值的数量来确定数组的大小，即数组 `a` 的大小为10

## 数组 的长度

在Java中，`length`是一个==特殊的属性而不是方法==，用于获取数组的长度。因此，您不需要在`length`后面使用括号来调用它。

```java
array.length
```



## 处理数组

》》》》》

`foreach`循环只能用于遍历数组或实现了`Iterable`接口的集合类和容器类对象。

> 1. 数组的输入
>
>    ```java
>    		int []a=new int[10];
>    		for(int i=0;i<a.length;i++)
>    		{
>    			a[i]=input.nextInt();
>    		}
>    ```
>
> 2. 使用随机数初始化数组
>
>    ```java
>    		Scanner input=new Scanner(System.in);
>    		char []a=new char[10];
>    		for(int i=0;i<a.length;i++)
>    		{
>    			int t=(int)(Math.random()*100);
>    			a[i]=(char)t;
>    		}
>    		for(char b:a)
>    		{
>    			System.out.print(b+" ");
>
>    		}
>    		System.out.println();
>    		for(char b:a)
>    		{
>    			System.out.printf("%c ",b);
>    		}
>    ```
>
> 3. 显示/遍历数组
>
>    ```java
>    		for(数组的数据类型 中间变量:数组名字)
>    		{
>    			System.out.printf("%c ",b);
>                b就代表a[i];
>    		}
>    //老版本
>    		for(int i=0;i<a.length;i++)
>    		{
>    			System.out.print(a[i]);
>    		}
>    ```
>
> 4. 对所有元素求和
>
>    ```java
>    		String sum="";
>    		for(int i=0;i<a.length;i++)
>    		{
>    			sum+=a[i];
>    		}
>    		System.out.println(sum);
>    ```
>
> 5. 找到最值和对应的下标
>
>    ```java
>    		char max=a[0];
>    		int flag=0;
>    		for(int i=0;i<a.length;i++)
>    		{
>    			if(a[i]>max)
>    			{
>    				max=a[i];
>    				flag=i;
>    			}
>    		}
>    		System.out.println(max+" "+(int)max+" " +flag);
>    ```
>
> 6. 随机打乱数组
>
>    ```java
>    		int []a= {1,2,3,4,5,6,7,8,9,0};
>
>    		for(int i=0;i<a.length;i++)
>    		{
>    			int t=(int)(Math.random()*a.length);
>    			int temp;
>    			temp=a[t];
>    			a[t]=a[i];
>    			a[i]=temp;
>    		}
>    		for(int b:a)
>    		{
>    			System.out.print(b+" ");
>    		}
>    //		2 1 7 6 3 0 8 9 4 5 
>    ```
>
> 7. 冒泡排序
>
>    
>    
>    ```java
>    
>    for(int i=0;i<a.length-1;i++)
>    		{
>    			for(int j=0;j<a.length-i-1;j++)
>    			{
>    				if(a[i]>a[j])
>    				{
>    					int t;
>    					t=a[i];
>    					a[i]=a[j];
>    					a[j]=t;
>    				}
>    			}
>    		}
>    		for(int b:a)
>    		{
>    			System.out.print(b+" ");
>    		}
>    ```

## Foreach循环

`foreach`循环只能用于遍历数组或实现了`Iterable`接口的集合类和容器类对象。

## 扑克牌案例

```java
package poker;
public class po {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
	System.out.print("一副牌右52张13个黑桃，红桃，方块，梅花");
	String[] PokerContent= {"1","2","3","4","5","6","7","8","9","10","jack","queen","king"};
	String[] PokerType= {"blackpeach","redpeach","block","club"};
	
	System.out.print(PokerType.length);
	
	int[] poker=new int[52];
	
	for(int i=0;i<poker.length;i++)
	{
		poker[i]=i;
	}
//	for(int i : poker)
//		System.out.print(i+" ");
	
	System.out.print("0-12全是黑桃，13-25全是红桃，26-38全是方块，39-51全是梅花");
	
	System.out.print("打乱并摸取前四张");
	int temp;
	int t;
	for(int i=0;i<poker.length;i++)
	{
		t=(int)(Math.random()*poker.length);
		//0-51
		temp=poker[i];
		poker[i]=poker[t];
		poker[t]=temp;
	}
//	for(int i : poker)
//	System.out.print(i+" ");
	System.out.println();
	
	
	
	for(int i=0;i<4;i++)
	{
		String pc=PokerContent[poker[i]%13];
		
		String pt=PokerType[poker[i]/13];

		
		System.out.printf("%d抽取的第%d张扑克的类型是%s,内容是%s\n",poker[i],i,pt,pc);
	}
	
	}

}

```

## 数组的赋值与克隆

```java
package Mypackage;
import java.util.Scanner;
import java.time.LocalDateTime;
public class w1 {
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		int []a= {1,2,3,4,5,6,7,8,9,0};
		int []b=a;
		//简单克隆并修改
		b[0]=100;
		//打印看结果
		for(int i :a)
		System.out.print(i);
		System.out.println();
		for(int i :b)
		System.out.print(i);
		//二者指向同一块内存
		System.out.println();
		//new克隆
		int c[]=new int[a.length];
		System.arraycopy(a, 0, c, 0, a.length);
		
		//打印看结果
		for(int i :a)
		System.out.print(i);
		System.out.println();
		for(int i :c)
		System.out.print(i);
		//简单克隆并修改
		c[0]=200;
		
		//打印看结果
		System.out.println();
		for(int i :a)
		System.out.print(i);
		System.out.println();
		for(int i :c)
		System.out.print(i);
//		100234567890
//		200234567890
		
		
	}
}

```

`System类里有一个arraycopy(a,0,b,0,len)`

> 是深拷贝相当于
>
> 第一个参数是---复制sRc
>
> 第2个参数是---复制SRc的起点
>
> 第3个参数是---复制aim
>
> 第4个参数是---复制aim的起点
>
> 第5个参数是--复制多少个单位？
>
> ==注意在没有目标的时候，System.arraycopy不会为其创造数组，需要手动先创建目标==
>
> ```java
> 		int c[]=new int[a.length];
> 		System.arraycopy(a, 0, c, 0, a.length);
> ```

==arraycopy违背了命名规则应该是arrayCopy==

## （数组）参数传递给方法

> + 数组，传递给方法的 时候是把引用传递给了方法，==`传递共享信息`==
> + 基本数据类型， ==传递的是实参的值。==

数组在java里是对象，==java的对象存储在堆区，==用于程序员管理他的生死，也就是动态内存分配

## 方法返回数组(数组的逆序)

==数组的引用被返回==



```java
package Mypackage;
import java.util.Scanner;
import java.time.LocalDateTime;
public class w1 {
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		
		int [] a=new int [] {1,5,6,4,2,3};
		
		//返回的是数组的引用
		for(int i :p(a))
		{
			System.out.print(i+" ");
		}
	}
	public static int[] p(int[] a)
	{
		int []result=new int[a.length];
		for(int i=a.length-1,j=0;i>=0;i--,j++)
		{
			result[j]=a[i];
		}
		return result;
	}
}

```



`改变真身的方法2`

```java
	public static void p(int [] a)
	{
//		int [] result=new int[a.length];
		for(int i=a.length-1,j=0;i>=j;i--,j++)
		{
			int t=a[i];
			a[i]=a[j];
			a[j]=a[i];
		}
	}
```

`改变真身的方法3`

```java
	public static void p(int[] a) {
	    for (int i = 0; i < a.length / 2; i++) {
	        int temp = a[i];
	        a[i] = a[a.length - 1 - i];
	        a[a.length - 1 - i] = temp;
	    }
	}
```



## 案例---字母出现的次数

[ 常见的字符 的ANCII码](#ANCII)

```java
package Mypackage;
import java.util.Scanner;
import java.time.LocalDateTime;
public class w1 {
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		
		char[] RandomCharArray=new char[100];
		//得到100个随机字符的字符数组
		for(int i=0;i<RandomCharArray.length;i++)
		{
			RandomCharArray[i]=GetRandomChar();
		}
		for(char i :RandomCharArray)
			System.out.print(i);
		
		int [] count=new int[RandomCharArray.length];
		for(int i=0;i<RandomCharArray.length;i++)
		{
			count[RandomCharArray[i]]++;
		}
		System.out.println();
		int sum=0;
		for(int i=0;i<count.length;i++)
		{
			if(count[i]!=0)
			{
			System.out.printf("字符%c出现的次数为%d\n",i,count[i]);
			sum+=count[i];
			}
		}
		System.out.printf("总数是%d",sum);

	}
	public static char GetRandomChar()
	{
		//65-90
		char result=(char)((int)(Math.random()*26)+65);
		return result;
	}
}

```

## 可变长参数列表(找数组的最值)

具有==同样类型的====数目可变的==参数可以传递给方法，并将其==作为数组对待==

```java
package Mypackage;
import java.util.Scanner;
import java.time.LocalDateTime;
public class w1 {
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		PrintMax(new int[]{9,2,3,4,5,6});
		
		System.out.println();
		PrintMax(1,2,3,4,5,6,7,8,9);
//		int []b = {1,2,3,4};

	}
	public static void PrintMax(int...a)
	{
		int max=a[0];
		for(int i=0;i<a.length;i++)
			if(a[i]>max)
				max=a[i];
		System.out.print(max);
	}
}

```

## 数组元素的查找（线性，二分）

```java
package Mypackage;
import java.util.Scanner;
import java.time.LocalDateTime;
public class w1 {
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);

		int[] a=new int[] {1,5,6,2,3,4,8,9};
//		for(int i=0;i<10;i++)
//			a[i]=(int)(Math.random()*10);
		System.out.print("数组的长度为"+a.length+'\n');
		int key=192;
		for(int i : a)
			System.out.print(i+" ");
		System.out.print("\n");
		System.out.print("线性查找2\n");
		for(int i=0;i<a.length;i++)
			if(a[i]==key)
				System.out.print("找到啦！下标为"+i+"\n");
		System.out.print("先排序\n");
		for(int i=0;i<a.length-1;i++)
		{
			for(int j=0;j<a.length-1-i;j++)
			{
				if(a[j]>a[j+1])
				{
					int t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
		}
		
		for(int i : a)
			System.out.print(i+" ");
		System.out.print("\n");
		System.out.print("二分查找2\n");
		
		System.out.print(Search(a,key)+"\n");
		
		System.out.print("通过返回-low-1，我们可以利用返回值的负号来判断是否找到了目标元素。如果返回值是负数，我们可以通过将其取反再减去1来获取目标元素应该插入的位置");
	}
	public static int Search(int []a,int key)
	{
		int start=0,end=a.length-1;
		while(end>=start)
		{
			int middle=(start+end)/2;
			if(key<a[middle])
			{
				end=middle-1;
			}
			else if(key>a[middle])
			{
				start=middle+1;
			}
			else
			{
				System.out.print("-=-=-=-=-=-=-=");
				return middle;
			}
				
		}
		return -start-1;
	}
}

```

》》》》》》》》

### Little tips

> 几个注意事项
>
> 1，二分的前提是数组==进行了升序排序==
>
> 不同顺序对应不同的写法,默认是升序为例子
> 2.==无论数组元素是奇数个还是偶数个都是ok的==
>
> ```java
> 	public static int Search(int []a,int key)
> 	{
> 		int start=0,end=a.length-1;
> 		while(end>=start)
> 		{
> 			int middle=(start+end)/2;
> 			if(key<a[middle])
> 			{
> 				end=middle-1;
> 			}
> 			else if(key>a[middle])
> 			{
> 				start=middle+1;
> 			}
> 			else
> 			{
> 				System.out.print("-=-=-=-=-=-=-=");
> 				return middle;
> 			}
> 				
> 		}
> 		return -start-1;
> 	}
> ```
>
> 1 2 3 4 5 6
>
> 中间元素是3
>
> 假设划分到了456
>
> 那么中间元素就是5了
>
> 》》》》》
>
> ==middle=(start+end)/2;==
>
> `对于找数组内不存在的元素我们返回-start-1`
>
> 将这个数取绝对值再减1
>
> ==就得到了这个数据应该放在排好序的数组的下标位置！==
>
> 小型数组用线性查找
>
> 大型数组用二分查找效率高

## 数组的排序

1. ### 冒泡排序

```java
package Mypackage;
import java.util.Scanner;
import java.time.LocalDateTime;
public class w1 {
	public static void main(String[] args)
	{
		
		int[] a=new int [10];
		for(int i=0;i<10;i++)
		{
			a[i]=(int)(Math.random()*10);
		}
		for(int i:a)
		{
			System.out.print(i+" ");
		}
		System.out.print("\n");
		for(int i=0;i<a.length-1;i++)
		{
			for(int j=0;j<a.length-1-i;j++)
			{
				if(a[j]>a[j+1])
				{
					int t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
							
				}
			}
		}
		for(int i:a)
		{
			System.out.print(i+" ");
		}
	}
	
}

```

## Arrays类

```java
import java.Arrays;
```

有一些常见的数组操作，数组的排序和查找

```java
package Mypackage;
import java.util.Scanner;
import java.util.Arrays;
import java.time.LocalDateTime;
public class w1 {
	public static void main(String[] args)
	{
		
		int[] a=new int [10];
		for(int i=0;i<10;i++)
		{
			a[i]=(int)(Math.random()*10);
		}
		for(int i:a)
		{
			System.out.print(i+" ");
		}
		System.out.print("\n");
		System.out.print("Arrays的排序\n");
		Arrays.sort(a);	
		
		for(int i:a)
		{
			System.out.print(i+" ");
		}
		p(a);
		System.out.print("\n");
		for(int i:a)
		{
			System.out.print(i+" ");
		}
		
		
	}
	public static void p(int [] a)
	{
		for(int i=a.length-1,j=0;i>=j;i--,j++)
		{
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
		
	}
//	public static void p(int[] a) {
//	    for (int i = 0; i < a.length / 2; i++) {
//	        int temp = a[i];
//	        a[i] = a[a.length - 1 - i];
//	        a[a.length - 1 - i] = temp;
//	    }
//	}
	
}

```

> Arrays.sort(数组)，默认是升序排序
>
> 在Java的`java.util.Arrays`类中，提供了一些常用的对数组进行操作的方法，包括但不限于以下几种：
>
> 1. `sort()`：对数组进行==升序排序。==
>
> 2. `parallelSort()`：对数组进行==并行排序==。效率更高
>
> 3. `binarySearch()`：在==已排序的数组中====使用二分查找算法查找指定元素的索引。==
>
> 4. `equals()`：==比较两个数组是否相等。==
>
> 5. `fill()`：将数组的所有元素都设置为指定的值。
>
>    ```java
>    		Arrays.fill(a, 2);
>    		for(int i:a)
>    		{
>    			System.out.print(i+" ");
>    		}
>    ```
>
>    
>
> 6. `copyOf()`：==复制指定的数组，可以指定新数组的长度。==
>
> 7. `copyOfRange()`：复制指定数组的指定范围内的元素。
>
> 8. `toString()`：==将数组转换为字符串表示形式。==
>
>    ```java
>    		String str=Arrays.toString(a);
>    		System.out.print(str);
>    //		9 8 4 4 3 3 2 1 0 0 
>    //		[9, 8, 4, 4, 3, 3, 2, 1, 0, 0]
>    ```
>
>    
>
> 9. `asList()`：将指定的元素转换为一个固定大小的列表。
>
> 这些方法提供了方便的数组操作功能，可以根据需要选择合适的方法来对数组进行处理。

## 命令行参数

```java
package Mypackage;
import java.util.Scanner;
import java.util.Arrays;
import java.time.LocalDateTime;
public class w1 {
	public static void main(String[] args)
	{
		String[] a= {"asdasd","dwd23e4"};
		
		student.main(a);
	}
	
}

class student{
	public static void main(String[] args)
	{

		for(int i=0;i<args.length;i++)
		{
			System.out.print(args[i]);
		}
	}
}

```

### 计算器

```java
public class w1{
	public static void main(String[] args)
	{
		int a=0,b=0;
		if(args.length!=3)
		{
			System.out.print("wrong");
		}
		else
		{
			switch(args[1].charAt(0))
			{
				case '+':
				{
					a=Integer.parseInt(args[0]);
					b=Integer.parseInt(args[2]);
					System.out.printf("%d+%d=%d!",a,b,a+b);
					break;
				}
				case '-':
				{
					a=Integer.parseInt(args[0]);
					b=Integer.parseInt(args[2]);
					System.out.printf("%d-%d=%d!",a,b,a-b);
					break;
				}
				case '.':
				{
					a=Integer.parseInt(args[0]);
					b=Integer.parseInt(args[2]);
					System.out.printf("%d*%d=%d!",a,b,a*b);
					break;
				}
				case '/':
				{
					a=Integer.parseInt(args[0]);
					b=Integer.parseInt(args[2]);
					System.out.printf("%d/%d=%d!",a,b,a/b);
					break;
				}
			}
			
			
		}
	}
	
}
```

![image-20230918172806794](E:\MD\java\java从入门到入土.assets\image-20230918172806794.png)





## ==数组小结==



![8bdd38340ad7886588e2741cc47d31a](E:\MD\java\java从入门到入土.assets\8bdd38340ad7886588e2741cc47d31a.jpg)



# 第八章-多维数组

==二维数组是一个数组里面每一个都是数组的引用==

表示表或者矩阵

## 二维数组的创建

初始化就不需要指出数组的大小了 ，会auto的识别

`int [][] d=new int[5][];=`===第一个也就是行数必须指定==

```java
public class w1{
	public static void main(String[] args)
	{
		
		int [][] a= {
				{1,2,3},{2,3,45,}
		};
		
		
		int [][] b=new int[][]{{1,2,3},{2,3,45}};
		
		
	}
	
}
```

## 二维数组的数据存入

```java
		int [][] b=new int[3][3];
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				b[i][j]=input.nextInt();
			}
		}
```

随机二维数组

```java
int [][] b=new int[3][3];	
for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
//				b[i][j]=input.nextInt();
				b[i][j]=(int)(Math.random()*10);
			}
		}
```

## 二维数组的遍历

```java
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				System.out.print(b[i][j]+" ");
			}
			System.out.println();
		}
```

## 由二维数组得到的信息

> array.length
> 得到的是二维数组的行数
> array[x].length
> 得到的是当前行的列数
> 如果是矩阵的话随便抽取一个就可以得到矩阵的列数
> 但多维数组可以是不规则的，也就是说他的

## 二维数组的随机打乱

```java
		int [][] c=new int[][] {{1,2,3},{4,5,6},{7,8,9}};
		System.out.println("---------------");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				System.out.print(c[i][j]+" ");
			}
			System.out.println();
		}

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				int ri=	(int)(Math.random()*c.length);
				int rj=(int)(Math.random()*c[i].length);
				int t=c[ri][rj];
				c[ri][rj]=c[i][j];
				c[i][j]=t;
			}
		}
		System.out.println("---------------");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				System.out.print(c[i][j]+" ");
			}
			System.out.println();
		}
```

## 二维数组的求和

```java
		int [][] c=new int[][] {{1,2,3},{4,5,6},{7,5,8,9}};
		
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				System.out.print(c[i][j]+" ");
			}
			System.out.println();
		}
		int sum1=0;
		for(int i=0;i<c.length;i++)
		{
			for(int j=0;j<c[i].length;j++)
			{
				sum1+=c[i][j];
			}
		}
		System.out.print("一行一行的遍历得到的综合是！"+sum1);
		int sum2=0;
		for(int i=0;i<c[0].length;i++)
		{
			for(int j=0;j<c.length;j++)
			{
				sum2+=c[i][j];
			}
		}
		System.out.print("一列一列的遍历得到的综合是！"+sum2);
```

首选一行一行的遍历，因为java 的数组存在不规则的时候，那样的列数会出现问题

1，2，3

4，5，6，7，8

1，2

那列数该选择哪个呢？`对于矩阵二者都使用`

## 二维数组传递给方法

==跟一维数组一样，是把数组的引用传递给了方法==

然后就可以操作地址一样操作数组了



## 多维数组

```java
int [3][2][1]
可以理解为三个二维数组
三张表一样
```



## 例子，多选择题评分

## 数独

# 第九章对象

==类为对象定义属性和行为==

`万物皆对象`

一个对象

有属性和行为

分别对应数据和方法

一个类模板可以实例化出多个对象，每个对象又可以有自己的属性，行为大家是公用类的。



> 创建实例的过程是实例化
>
> 包含main方法的是主类
>
> 有main才是程序的入口
>
> 而且public只有一个，而且public类的类名就是.java文件的名
>
> 一个文件可以有多个类，但是文件中只能有一个是公共类，而且公共类的名字和文件同名
>
> ==源代码中的每一个类被编译成一个.class字节码文件==
>
> 使用new操作符从构造方法创建一个对象
>
> ```java
> package Mypackage;
> import java.util.Scanner;
> public class w1{
> 	public static void main(String[] args)
> 	{
> 
> 		student s1=new student();
> 		//用到了默认的构造函数，编译器会给创建一个空的函数
> //		student s1;
> 		System.out.print(s1.age+" "+s1.name);
> 	}
> 
> }
> class student{
> 	int age=10;
> 	String name="牛马";
> }
> ```
>
> ==类是定义相同类型对象的结构==



## 使用构造方法构造构造对象

> 构造方法是一种特殊的方法
>
> + 构造方法的名字和类名相同
>
> + 没有返回值也不写void！
>
> + 用于new一个对象到时候初始化对象
>
> + 可以重载
>
> + ==在你没有自己写一个构造函数的时候，类中会隐式的顶一个一个空实现的无参构造函数==
>
> + ```java
>   public class w1{
>   	public static void main(String[] args)
>   	{
>   	              
>   		student s1=new student("大猪比");
>           student s2;
>   		System.out.print(s1.name);//大猪比
>   	}
>   	              
>   }
>   class student{
>   	public student(String a)
>   	{
>   		this.name=a;
>   	}
>   	int age=10;
>   	String name="牛马";
>   }
>   ```

## 通过引用变量访问对象

==对象都是数据和方法可以用（点操作符.）通过对象的引用变量进行访问==

类是一种引用类型，意味着该类型的变量都可以引用该类的一个实例

对象的引用

==java中数组被看作对象实际上是包含数组引用的变量==



## 访问对象的数据和方法

.

对象成员访问操作符

```java
public class w1{
	public static void main(String[] args)
	{
	
		student s1=new student("大猪比");
		System.out.print(s1.name);//大猪比
		s1.Say();
	}
	
}
class student{
	public student(String a)
	{
		this.name=a;
	}
	int age=10;
	String name="牛马";
	public void Say(){
		System.out.print("你好啊妹子");
	}
}
```

实例变量，实例方法。

只能在已有的对象的基础上进行使用。[静态方法和实例方法](#静态方法和实例方法)



Math类里面全是静态成员

静态成员使用static关键字创建的

==------------------------------------------------------------==

`new student("大猪比");`创建一个匿名对象

## 引用数据域和null值

null是引用类型的字面值

默认是null

在Java中，==引用对象的数据域是指对象中存储的数据==。当你创建一个对象时，它会分配一块内存来存储对象的数据域。==你可以通过对象的引用来访问和修改这些数据==。

当一个引用对象被赋值为`null`时，表示==该引用不指向任何有效的对象==。这意味着==该引用没有引用任何数据域==。如果你==尝试访问一个`null`引用的数据域==，将会抛出`NullPointerException`异常。

以下是一个示例代码，演示了引用对象的数据域和`null`值的相关知识：

```java
package Mypackage;
import java.util.Date;
import java.util.Scanner;
public class w1{
	public static void main(String[] args)
	{
	
		Person p=new Person("大猪比",27);
		
		System.out.print(p.getName()+"  "+p.getAge());//大猪比  27
		
		Person p2=null;
		
		System.out.print(p2.getName()+"  "+p2.getAge());
	}
	
}
class Person{
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}
```

`person2`引用为`null`，访问其数据域将抛出`NullPointerException`异常。

在使用引用对象的数据域之前，必须确保引用不为`null`。你可以使用条件语句或者空值检查来避免`NullPointerException`异常的发生。

## 基本类型变量和引用类型变量的区别

> 在Java中，==基本类型变量==和==引用类型变量==有以下几个区别：
>
> 1. **存储方式：==基本类型变量直接存储在栈内存中==，而==引用类型变量存储在栈内存中的引用地址==，==实际对象存储在堆内存中。==**
>
> 2. 大小：==基本类型变量的大小是固定的，不受对象的大小影响==，而引用类型变量的大小是固定的，但它指向的对象的大小是可变的。
>
> 3. 默认值：基本类型变量在声明时会有默认值，如`int`类型的默认值是0，`boolean`类型的默认值是`false`，而引用类型变量默认值是`null`。
>
> 4. 传递方式：基本类型变量在方法调用时是==按值传递的==，即传递的是==变量的副本==，而引用类型变量在方法调用时是==按引用传递的==，即传递的是==变量的地址。==
>
> 5. 包装类：Java提供了基本类型对应的包装类，如`Integer`、`Boolean`等，可以将基本类型转换为对应的包装类对象，也可以将包装类对象转换为对应的基本类型。
>
>    ```java
>    Integer.parseInt(String a)；
>    返回数字字符串对应的整数
>    ```

![image-20230919102600952](E:\MD\java\java从入门到入土.assets\image-20230919102600952.png)

java虚拟机会自动回收null的内存

如果我们不再使用某个对象就显示的给该对象的引用变量复制null



## 使用java库中的类

### Date类

```java
		
		Date date=new Date();
		System.out.print(date.toString());
		System.out.print(date.getTime());
		//27Tue Sep 19 10:28:14 CST 20231695090494725
```

### java的Random类

```java
		Random ra=new Random();
		//当前时间为种子
		System.out.println(ra.nextInt());
		System.out.println(ra.nextInt(10));
		System.out.println(ra.nextDouble());
		System.out.println(ra.nextBoolean());
//		451307293
//		7
//		0.6024241912199637
//		false

//固定种子
		Random ra2=new Random(1);
		System.out.println(ra2.nextInt());
		System.out.println(ra2.nextInt(10));
		System.out.println(ra2.nextDouble());
		System.out.println(ra2.nextBoolean());
//		-1155869325
//		8
//		0.41008081149220166
//		false
```

### java的SecureRandom类

==因为Random类擦还是你哼的随机数字是确定的可能被黑客预测到，然鹅SecureRandom类产生的随机数是不确定的，是安全的==

```java
		SecureRandom ra=new SecureRandom();

		System.out.println(ra.nextInt(10));
```

1. `SecureRandom`类：
   `SecureRandom`是Java库中提供的用于==生成安全随机数的类==。它使用强加密算法来生成随机数，适用于需要高度安全性的场景，如密码学、安全密钥生成等。

   使用示例：
   ```java
   import java.security.SecureRandom;
   
   public class SecureRandomExample {
       public static void main(String[] args) {
           SecureRandom secureRandom = new SecureRandom();
           byte[] randomBytes = new byte[16];
           secureRandom.nextBytes(randomBytes);
           System.out.println("随机字节数组：" + Arrays.toString(randomBytes));
       }
   }
   //随机字节数组：[-101, 33, -57, -71, -123, 32, 34, 81, -65, 106, 98, 16, 60, -32, 51, 32]
   ```
   
   在上面的示例中，我们创建了一个`SecureRandom`对象，并使用`nextBytes`方法生成了一个长度为16的随机字节数组。
   
2. `Random`类：
   `Random`是Java库中提供的用于生成伪随机数的类。它使用一个48位种子来生成随机数序列。虽然生成的随机数不是真正的随机数，但在大多数情况下已经足够使用。

   使用示例：
   ```java
   import java.util.Random;
   
   public class RandomExample {
       public static void main(String[] args) {
           Random random = new Random();
           int randomNumber = random.nextInt(100);
           System.out.println("随机数：" + randomNumber);
       }
   }
   ```

   在上面的示例中，我们创建了一个`Random`对象，并使用`nextInt`方法生成一个介于0和99之间的随机整数。

3. `Date`类：
   `Date`是Java库中提供的用于表示日期和时间的类。它提供了一系列方法来操作日期和时间，如获取当前日期和时间、比较日期、格式化日期等。

   使用示例：
   ```java
   import java.util.Date;
   import java.text.SimpleDateFormat;
   
   public class DateExample {
       public static void main(String[] args) {
           Date date = new Date();
           System.out.println("当前日期和时间：" + date.toString());
   //        当前日期和时间：Tue Sep 19 10:52:16 CST 2023
           //获取当前时间的对象
           SimpleDateFormat a=new SimpleDateFormat("yy-MM-dd hh:mm:ss");
           String nowtime=a.format(date);
           System.out.println("当前日期和时间：" + nowtime);
   //        当前日期和时间：2023-09-19 10:48:47
       }
   }
   ```
   
   在上面的示例中，我们创建了一个`Date`对象来表示当前日期和时间。然后，我们使用`SimpleDateFormat`类将日期格式化为"yyyy-MM-dd HH:mm:ss"的字符串。

## 静态变量，常量和方法

==静态变量、常量和方法是与类关联的，而不是与类的实例关联的。它们在类加载时就会被初始化，并且可以在整个程序运行期间被访问。==

1. 静态变量（Static Variables）：==静态变量是类级别的变量==，==也称为类变量==。它们使用`static`关键字声明，并且==在类加载时被初始化==。静态变量在内存中只有一份拷贝，并且==可以被所有该类的实例共享==。静态变量==可以通过类名直接访问，不需要创建类的实例。==

2. 常量（Constants）：常量是指在程序运行期间不会改变的值。在Java中，常量通常使用`final`关键字声明。常量一般用大写字母命名，以便与其他变量区分开。常量可以是静态的，也可以是实例级别的。

3. 静态方法（Static Methods）：==静态方法是属于类的方法==，而不是类的实例。它们使用`static`关键字声明，并且==可以直接通过类名调用，不需要创建类的实例==。==静态方法不能访问非静态的实例成员，只能访问静态的成员。==

静态成员和实例成员的关系如下：

- ==静态成员可以直接访问静态成员，包括静态变量和静态方法。==
- 静态成员不能直接访问实例成员，包括实例变量和实例方法。要访问实例成员，需要通过创建类的实例来访问。
- ==实例成员可以直接访问静态成员，包括静态变量和静态方法。==

> 实例方法可以调用
>
> ==实例方法和静态方法以及访问静态数据域和实例数据域==
>
> 静态方法可以调用
>
> ==静态方法和访问静态数据域==
>
> ---
>
> 因为静态方法和静态数据域不属于某个特定的对象相当于是类的





## 可见性修饰符

可以加在

类，方法，数据域

如果一个类默认没有可见性修饰符，那么他==默认是可以被同一个包中的所有类访问的成为包私有或包访问==。

==包可以用来组装类==，`package packagename；`



在Java中，可见性修饰符（visibility modifiers）用于控制类、变量、方法和构造函数的访问权限。Java提供了四种可见性修饰符：public、private、protected和默认（package-private）。

1. public：public是最宽松的可见性修饰符，==它表示被修饰的成员可以在任何地方被访问==。具有public修饰符的类、变量、方法和构造函数==可以被其他类的代码直接访问。==
2. private：private是最严格的可见性修饰符，它表示被修饰的成员==只能在同一个类中被访问==。具有private修饰符的类、变量、方法和构造函数对其他类是不可见的。
3. protected：protected修饰符表示==被修饰的成员可以在同一个包中的其他类中被访问，以及在不同包中的子类中被访问。==具有protected修饰符的类、变量、方法和构造函数对其他包中的非子类是不可见的。
4. 默认（package-private）：如果没有使用任何可见性修饰符，即没有使用public、private或protected修饰符，那么成员的可见性将被限制在同一个包中。这种默认的可见性修饰符也被称为==包级私有（==package-private）。

> 私有的限定符private把作用域==限制在类内‘==
>
> 默认限定符访问权限在==包内==
>
> 公共的修饰符可以==无限的访问==



private只能应用在类的成员上，public可以在类和类的成员上

==多数情况下构造函数是public的==

如果想防止用户创建类的实例就使用私有private的构造函数

Math类里面的所有数据域和方法都是静态的

## Integer类

> Java中的Integer类是一个包装类，用于将基本数据类型int封装成对象。Integer类提供了许多常用的方法来操作和处理整数值。下面是一些Integer类的常用方法：
>
> 1. parseInt(String s)：将==数字字符串转换为整数==。例如：`int num = Integer.parseInt("123");`
> 2. toString()：将==整数转换为字符串==。例如：`String str = Integer.toString(123);`
> 3. valueOf(int i)：返回一个表示指定整数值的Integer实例。例如：`Integer num = Integer.valueOf(123);`
> 4. intValue()：返回Integer对象的整数值。例如：`int num = numObj.intValue();`
> 5. compareTo(Integer anotherInteger)：比较两个Integer对象的大小。如果当前对象小于anotherInteger，则返回负数；如果当前对象等于anotherInteger，则返回0；如果当前对象大于anotherInteger，则返回正数。
> 6. equals(Object obj)：比较两个Integer对象是否相等。
> 7. max(int a, int b)：返回两个整数中的较大值。例如：`int maxNum = Integer.max(10, 20);`
> 8. ==Math.max(d, d)==
> 9. min(int a, int b)：返回两个整数中的较小值。例如：`int minNum = Integer.min(10, 20);`
> 9. parseInt(String s, int radix)：将指定基数的字符串转换为整数。例如：`int num = Integer.parseInt("FF", 16);`
>

## 向方法传递对象参数

传递的是对象的引用，就像数组一样

## 对象数组

数组既可以存储基本类型也可以存储对象

```java
Class[] classArrays=new Class[10];
```

`实际上存储的是引用变量的数组`

当使用new操作开辟一个对象数组之后，里面的每个元素都是默认值为null的引用变量

==引用变量的默认值是null==

## 不可变对象和类

定义不可变类这样的模板去除按照不可变的对象



不可改变的对象的内容不能被修改

==也就是该类的数据域都是私有的！==

==而且也没有对应的 方法获取数据==



>
>
>String类就是不可改变的类
>
>》》》》》
>
>1. 所有数据域都是私有的
>2. 没有获取数据的方法
>3. 没有修改器方法和访问的方法

==不可变对象是指一旦创建后就不能被修改的对象==。不可变对象的值在创建后是固定的，不能通过任何方法改变其状态。

1. - 值不可变：不可变对象的值在创建后不能被修改。
   - 状态不变：不可变对象的状态（成员变量）在对象的整个生命周期内保持不变。
2. 创建不可变对象的要素：
   - ==使用`final`关键字：将类、成员变量或方法声明为`final`，防止其被继承、修改或覆盖。==
   - 去除setter方法：不可变对象不提供修改值的方法，避免对对象状态的改变。
3. 不可变对象的优点：
   - 线程安全：不可变对象可以被多个线程安全地共享，无需担心并发修改问题。
   - 缓存友好：不可变对象的值不会变化，可以被缓存以提高性能。
   - 可靠性：不可变对象的值不会被意外修改，可以减少错误和bug的出现。
4. 创建不可变类的注意事项：
   - ==将所有成员变量声明为`final`和`private`，并通过构造函数初始化。==
   - ==如果需要返回对象的某个属性，应返回其副本而不是直接引用。==



## 变量的作用域

实例变量和静态变量的作用域是肾脏个类无论是在哪里声明的



一个类的实例里的实例变量和静态变量都是类变量或数据域



如果一个局部变量和一个类变量具有相同的名字，那么具备奴变量有限

```java
public class w1{
	public static void main(String[] args)
	{

		
		Student a=new Student(20);
		a.p();
		
	}                        
	
}
class Student
{
	Student(int a)
	{
		this.a=a;
	}
	int a;
	
	public void p()
	{
		int a=10;
		System.out.print(a);
	}
}
```

==不要将实例变量和静态变量或者静态变量作为局部变量的名字==

## this引用

> 关键字`this`是一个特殊的引用，它指向当前对象。以下是与`this`引用相关的一些重要知识点：
>
> 1. `this`的作用：
>    - 引用当前对象：`this`关键字用于引用当前对象，可以在对象内部访问当前对象的成员变量和方法。
>    - 解决命名冲突：当方法参数和成员变量同名时，可以使用`this`关键字来区分它们。
> 2. 使用`this`的情况：
>    - 访问成员变量：可以使用`this`关键字访问当前对象的成员变量，以区分局部变量和成员变量。
>    - 调用构造函数：在一个构造函数中，可以使用`this`关键字调用同一个类的其他构造函数，以重用代码和初始化对象。

```java
class Student
{
	Student(int a)
	{
		this.a=a;
	}
}
```

==this给出一种引用调用实例方法的对象的方法==

## 使用this调用构造方法

```java
class Student
{
	private int a;
	public Student(int a)
	{
		this.a=a;
	}
	
	public Student()
	{
		this(1);
		//相当于在使用有参构造构造一个对象
	}
}
```

## 第九章总结

![e4350c6333b7fe8a4e9aae54b6aadbd](E:\MD\java\java从入门到入土.assets\e4350c6333b7fe8a4e9aae54b6aadbd.jpg)

# 第十章封装继承多态

### 封装

把生活中的物体用对象表示

![image-20231116200045457](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116200045457.png) 







### 继承

#### 继承要学习什么？

![image-20231116200538333](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116200538333.png)

#### 继承的概述

![image-20231116200221444](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116200221444.png) 

#### 什么时候使用继承

![image-20231116200253834](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116200253834.png)



#### 继承的特点

![image-20231116200618322](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116200618322.png)

==不能多继承==

![image-20231116200717809](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116200717809.png) 

![image-20231116200920804](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116200920804.png)



#### 小结

![image-20231116201007684](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116201007684.png)

![image-20231116200440972](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116200440972.png)

#### 继承练习

![image-20231116201052335](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116201052335.png) 

![image-20231116202214767](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116202214767.png) 

![image-20231116202442987](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116202442987.png) 

```java
public class Main {
    public static void main(String[] args) {
        Taidi t=new Taidi();
        t.function();
        t.eat();
        t.drink();
        t.lookhome();
        Hashiqi h=new Hashiqi();
        h.function();
        h.drink();
        h.eat();
        h.lookhome();
        Hualimao hc=new Hualimao();
        hc.drink();
        hc.eat();
        hc.catchmouse();
        Buomao b=new Buomao();
        b.catchmouse();
        b.drink();
        b.eat();
    }
}
```





#### ==子类究竟可以继承父类的哪些东西！==

![image-20231116202710196](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116202710196.png)





#### 构造方法和成员变量继承内存图 

1. 构造方法

   ![image-20231116202812551](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116202812551.png)

2. 成员变量

   都继承下来了，但是不可以直接使用

   public的

   ![image-20231116203600530](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116203600530.png) 

   拷贝了一份，不影响父亲的

   private的

   ![image-20231116203628196](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116203628196.png)

    

   虽然继承下来了，但是不能直接使用，想用得要对应的方法

3. 内存继承图

   ![image-20231116204138801](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116204138801.png)

   程序运行完之后main方法就每没了，然后main里面创造的一些变量也就变成垃圾了，就被回收

4. 私有情况下

   ![image-20231116204824389](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116204824389.png)



#### 虚方法表

问题引入

![image-20231116205116984](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116205116984.png) 

a类成员想调用p类的方法P

一级一级往上找？拜托，太逊了，真的很耗费时间

1. 从最顶级(n)的父类那里设立了一个==虚方法表==
2. 这个虚方法表里面放了==经常要用到的非private,非final,非static的方法==
3. 下一级(n-1)会继承顶级的==虚方法表==并且把自己常用的方法也放入并且融合为一个心的proplus虚方法表
4. 以此类推循环，直到A类的成员就可以从虚方法表里面找到P类的方法P，虚方法！如果不是虚方法还要一层一层找 

![image-20231116205657488](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116205657488.png) 





#### 成员方法的内存继承图

![image-20231116210049547](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116210049547.png)





### 继承中成员的访问特点



#### 成员变量

![image-20231116210803824](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116210803824.png)

如果局部没有，就到父类，或者更上一层，如果还是没有，就报错



super，只能在子类中使用

![image-20231116210911070](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116210911070.png) 

![image-20231116211818318](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116211818318.png) 





#### 成员方法



方法 的调用要有调用者，实例方法

默认是this

如果this没有

就要super.方法显示的调用

super的时候就不会在本类里面找了

#### 方法的重写

![image-20231116212213297](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116212213297.png)



![image-20231116212358108](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116212358108.png)

> 重写后的方法
>
> 会覆盖从父类继承下来的虚方法表里面的同名方法

![image-20231116212726719](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116212726719.png)

#### ==构造方法==

![image-20231116213545043](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116213545043.png) 

![image-20231116214212641](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116214212641.png) 

![image-20231116214121742](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116214121742.png) 





#### this,super的总结

![image-20231116214823465](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116214823465.png)

![image-20231116214759664](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116214759664.png)





#### 案例

![image-20231116220458406](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116220458406.png) 



![image-20231116220436710](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231116220436710.png)





### 多态

> J可以让你以一种通用的方式操作对象，而不需要关心对象的具体类型：
>
> 1. **多态的概念**：多态是指==**同样的方法调用可以在不同的对象上产生不同的行为**==。在Java中，多态性通过==方法的重写==和==方法的重载==来实现。
>
> 2. **继承与多态**：==多态是建立在继承关系之上==。子类可以==覆盖（重写）==从父类继承而来的方法，当通过父类引用调用这些被子类重写的方法时，==**根据实际的子类类型会执行相应的重写方法。**==
>
> 3. **方法重写（Override）**：子类可以提供一个==**与父类方法签名相同的方法**==，并且可以==重新定义该方法的行为==。当使用父类的引用调用被子类重写的方法时，将根据实际的对象类型执行相应的重写方法。
>
> 4. **动态绑定**：Java中的多态是通过动态绑定实现的，也称为==运行时多态==。这意味着方法调用的具体实现是在运行时确定的，而不是在编译时确定的。
>
> 5. **抽象类和接口**：抽象类和接口是实现多态的重要方式。==**抽象类和接口定义了规范**==，子类可以根据需要去实现这些规范，并且可以==**通过父类或接口类型引用子类对象**==，实现统一的对外接口。
>
> 6. **向上转型**：可以使用==父类类型的引用指向子类对象==，这被称为向上转型。通过向上转型，可以在不关心具体子类类型的情况下，统一地对待各个子类对象，实现多态。
>
> 理解Java多态的核心知识包括继承关系、方法重写、动态绑定以及如何使用父类类型引用指向子类对象，从而实现统一的对外接口和统一的方法调用。
>
> 多态能够提高代码的灵活性和可扩展性，是面向对象编程中非常重要的概念。

![image-20231124204452286](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231124204452286.png) 

#### 多态调用成员的特点

![image-20231124205912921](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231124205912921.png)



#### 内存解释![image-20231124213633072](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231124213633072.png)

> 变量:编译和运行都是看左边
>
> 方法:编译看左边，运行看右边。



```java
package soft1;

import javax.lang.model.element.AnnotationMirror;

public class Main {

    public static void main(String[] args) {
        test(new Dog());
        test(new Cat());
        Animal a=new Dog();
        System.out.println(a.name);
//        a.Eat();
        //编译的时候会看左边是否有这个成员方法，没有就报错，也就是现在是子类特有的时候

        Dog b=(Dog)a;
        b.Eat();


    }
    public static void test(Animal a)
    {
        a.Say();
    }

}
 class Animal {
    String name="动物";
    int age;
    void Say(){};
}
class Dog  extends Animal{
    String name="狗";
    public void Say()
    {
        System.out.println("汪汪汪");
    }
    public  void Eat()
    {
        System.out.println("吃东西！Q");
    }
}

class Cat extends Animal{
    String name="猫";
    public void Say()
    {
        System.out.println("喵喵喵");
    }
}

```



#### 多态的优势和弊端

==子类转换为父类，这是默认的也就是自动类型转换==

==但是父类想要转换为子类，也就是降级？那就得强制转换了。==

![image-20231124215826563](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231124215826563.png) 































































# error

## java文件

java文件名要和public修饰的类名一样

同一个java文件只允许有一个public类





## 权限

### java默认权限

> Java中成员变量和方法的默认访问权限是"package-private"，也被称为"default"。这意味着如果没有指定任何访问修饰符，成员变量和方法只能在同一个包内被访问，而在其他包中是不可见的。相对于"public"权限来说，"package-private"权限的范围更小。









## 技巧

ctrl+f12找

ctrl+p可以输入参数的时候显示方法的参数列表









## 静态测试函数

因为在静态上下文中无法直接调用实例方法。你需要先创建一个类的实例，然后通过该实例调用实例方法。

`main`方法是程序的入口点，它必须是静态方法，因为在程序启动时，

==还没有创建任何对象实例，只能通过类名直接调用静态方法。==

 ![image-20231124204244426](java%E4%BB%8E%E5%85%A5%E9%97%A8%E5%88%B0%E5%85%A5%E5%9C%9F/image-20231124204244426.png) 





## instanceof关键字

`instanceof` 是 Java 中的一个关键字，用于检查一个对象是否是一个特定类的实例，或者是否是其子类的实例。它的语法是 `object instanceof Class`，其中 `object` 是要检查的对象，`Class` 是要检查的类。

```java
Animal a=new Dog();
//如果这个对象运行时是Dog类，那么就强制转换为DOg并且变量设置为b
if(a instanceof Dog b)
{
    b.Eat();
} else if (a instanceof Cat c) {
    c.Sleep();
} else {
    System.out.println("转不了，会报错");
}
```

