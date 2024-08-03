# QT信号和槽机制

> 信号槽的本质
>
>  信号槽的关系
>
> 标准信号槽的使用
>
> 自定义信号槽的使用
>
>  信号槽的拓展
>
>  Lambda表达式







## 信号和槽概述

> ==信号槽是 Qt 框架引以为豪的机制之一==。所谓信号槽，实际就是观察者模式(发布-订阅模式)。
>
> 当某个事件发生之后，比如，按钮检测到自己被点击了一下，它就会发出一个信号（signal）。==这种发出是没有目的的==，类似广播。如果有对象对这个信号感兴趣，它就会使==用连接（connect）函数==
>
> 意思是，将想要处理的信号和自己的一个函数（称为槽（slot））绑定来处理这个信号。也就是说，当信号发出时，被连接的槽函数会自动被回调。
>
> 这就类似观察者模式：当发生了感兴趣的事件，某一个操作就会被自动触发。

### 信号的本质

> 信号是由于用户对窗口或控件进行了某些操作，导致窗口或控件产生了某个特定事件，这时候Qt对应的窗口类会发出某个信号，以此对用户的挑选做出反应。

![image-20231130164740519](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130164740519.png) 

###  槽的本质

> 在Qt中槽函数是一类特殊的功能的函数，在编码过程中也可以作为类的普通成员函数来使用。之所以称之为槽函数是因为它们还有一个职责就是对Qt框架中产生的信号进行处理。

```
举个简单的例子：

    女朋友说：“我肚子饿了！”，于是我带她去吃饭。
```

上边例子中相当于女朋友发出了一个信号， 我收到了信号并其将其处理掉了。

![image-20231130164816443](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130164816443.png) 

==在Qt中槽函数的所有者也是某个类的实例对象。==

==再Qt中信号的发出者是某个实例化的类对象==

### 信号和槽的关系

> 在Qt中信号和槽函数都是独立的个体，本身没有任何联系
>
> 但是由于某种特性需求我们可以将二者连接到一起，好比牛郎和织女想要相会必须要有喜鹊为他们搭桥一样。==在Qt中我们需要使用**QOjbect类中的connect函数进二者的关联**。==
>
> ---
>
> > connect()操作一般写在**窗口的构造函数中**，相当于在***事件产生之前在qt框架中先进行注册***，这样在程序运行过程中**假设产生了按钮的点击事件，框架就会调用信号接收者对象对应的槽函数了，如果信号不产生，槽函数也就一直不会被调用。**可不是connect一调用就发生了



> 连接信号和槽的connect()函数原型如下, 其中PointerToMemberFunction是一个指向函数地址的指针

```c++
QMetaObject::Connection QObject::connect(
    	const QObject *sender, PointerToMemberFunction signal, 
        const QObject *receiver, PointerToMemberFunction method, 
		Qt::ConnectionType type = Qt::AutoConnection);
参数:
  - sender:   发出信号的对象
  - signal:   属于sender对象, 信号是一个函数, 这个参数的类型是函数
              指针, 信号函数地址
  - receiver: 信号接收者
  - method:   属于receiver对象, 当检测到sender发出了signal信号, 
              receiver对象调用method方法，信号发出之后的处理动作
 
//  参数 signal 和 method 都是函数地址, 因此简化之后的 connect() 如下:
connect(const QObject *sender, &QObject::signal, 
        const QObject *receiver, &QObject::method);
```

![image-20231130165043582](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130165043582.png) 





### 快速上手

==在Qt中槽函数的所有者也是某个类的实例对象。==

==再Qt中信号的发出者是某个实例化的类对象==

四个参数

1.信号发送者

2，发送的信号

3，接收者

4，接收者的行为

==connect函数的连接参数应该是函数指针或者函数对象，并且需要使用信号槽机制进行连接。==

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton*btn=new QPushButton(this);
    btn->show();
    btn->setText("第一个按钮");
    btn->setFixedSize(200,200);
    btn->move(300,300);

    //connect函数的连接参数应该是函数指针或者函数对象，并且需要使用信号槽机制进行连接。
    connect(btn,&QPushButton::clicked,this,&MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}


```

connect()操作一般写在**窗口的构造函数中**，相当于在***事件产生之前在qt框架中先进行注册***，这样在程序运行过程中**假设产生了按钮的点击事件，框架就会调用信号接收者对象对应的槽函数了，如果信号不产生，槽函数也就一直不会被调用。**可不是connect一调用就发生了

## 标准信号槽使用

#### 标准信号/槽

> 在Qt提供的**很多标准类中都可以对用户触发的某些特定事件进行检测,** 因此当用户做了这些操作之后, 事件被触发类的内部就会产生对应的信号,
>
> ==这些信号都是Qt类内部自带的, 因此称之为标准信号。==
>
> 同样的，在**Qt的很多类内部为我们了提供了很多功能函数**，并且这些函数也可以作为触发的信号的处理动作，
>
> 这类特性的函数在Qt中称之为标准槽函数。
>
> 系统自带的信号和槽通常如何查找呢，这个就需要利用帮助文档了，比如在帮助文档中查询按钮的点击信号，那么需要在帮助文档中输入QPushButton
>

![image-20231130165625597](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130165625597.png) 

<img src="C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130165802030.png" alt="image-20231130165802030" style="zoom:50%;" /> 

QAbstractButton

<img src="C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130165823700.png" alt="image-20231130165823700" style="zoom:50%;" /> 

### 使用

> 掌握标准信号、槽的查找方式之后以及connect()函数的作用之后, 下面通过一个简单的例子给大家讲解一下他们的使用方式。

```
功能实现： 点击窗口上的按钮, 关闭窗口
功能分析:
	- 按钮: 信号发出者          -> QPushButton 类型
	- 窗口: 信号的接收者和处理者  -> QWidget 类型
```

信号和槽函数准备

```c++
// 单击按钮发出的信号
[signal] void QAbstractButton::clicked(bool checked = false)
// 关闭窗口的槽函数
[slot] bool QWidget::close();


```

connect

```c++
// 单击按钮关闭窗口
connect(ui->closewindow, &QPushButton::clicked, this, &MainWindow::close);
```

》》》

> ==connect()操作一般写在**窗口的构造函数中**, 相当于在事件产生之前在qt框架中先进行注册==
>
> 这样在程序运行过程中假设产生了按钮的点击事件, 框架就会调用信号接收者对象对应的槽函数了
>
>  如果信号不产生, 槽函数也就一直不会被调用。





## 自定义信号和槽

> Qt框架提供的信号槽在某些特定场景下是无法满足我们的项目需求的
>
> 因此我们还==设计自己需要的的信号和槽==
>
> ==同样还是使用connect()对自定义的信号槽进行连接。==



![image-20231130170107888](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130170107888.png)

 

```c++
// 在头文件派生类的时候，首先像下面那样引入Q_OBJECT宏：
class MyMainWindow : public QWidget
{
    Q_OBJECT
    ......
}
```

### **创建新的类的注意事项**

---

在Qt中，创建新的类来定义自定义信号和槽时，有以下要求：

**如果要继承QObject和使用Q_OBJECT宏的时候就要引入对应的文件**

```c++\
#include <QObject>
```

1. **继承自QObject类：**或者继承QObject的子类也就是间接继承QObject
   **新的类必须继承/间接继承自QObject类，以便能够使用Qt的信号和槽机制。**

   ```cpp
   class MyClass : public QObject
   {
       Q_OBJECT
       // ...
   };
   ```

2. **添加Q_OBJECT宏**：
   在新的类的声明中，需要添加Q_OBJECT宏。**这个宏告诉Qt元对象编译器（MOC）生成必要的代码，以支持信号和槽的使用。**

   ```cpp
   class MyClass : public QObject
   {
       Q_OBJECT
       // ...
   };
   ```

3. **声明信号和槽函数：**
   在新的类中，可以声明自定义的信号和槽函数。**信号函数声明在`signals`关键字下，槽函数声明在`public slots`关键字下。**

   ```cpp
   class MyClass : public QObject
   {
       Q_OBJECT
   public:
       explicit MyClass(QObject *parent = nullptr);
   
   signals:
       void mySignal(int value);
   
   public slots:
       void mySlot(int value);
   };
   ```

4. **实现信号和槽函数：**
   在新的类的实现中，可以实现自定义的信号和槽函数。**信号函数使用`emit`关键字来发出信号，槽函数用于接收信号并进行相应的处理。**

   ```cpp
   MyClass::MyClass(QObject *parent) : QObject(parent)
   {
       // ...
   }
   
   void MyClass::mySlot(int value)
   {
       // 处理槽函数的代码
   }
   
   void MyClass::mySignal(int value)
   {
       emit mySignal(value);
   }
   ```

### 自定义信号

> 在Qt中==信号的本质是事件==, ==但是**在框架中也是以函数的形式存在的**==,
>
> 只不过==**信号对应的函数只有声明, 没有定义。**==
>
> 如果Qt中的标准信号不能满足我们的需求，可以在程序中进行信号的自定义
>
> 当自定义信号对应的事件产生之后，认为的**将这个信号发射出去即可**（其实就是调用一下这个信号函数）。

![image-20231130170523063](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130170523063.png) 

```c++
// 举例: 信号重载
// Qt中的类想要使用信号槽机制必须要从QObject类派生(直接或间接派生都可以)
class Test : public QObject
{
    Q_OBJECT
signals:
    void testsignal();
	// 参数的作用是数据传递, 谁调用信号函数谁就指定实参
	// 实参最终会被传递给槽函数
    void testsignal(int a);
};

```



### 自定义槽

> 槽函数就是信号的处理动作，在Qt中==槽函数可以作为普通的成员函数来使用。==
>
> 如果标准槽函数提供的功能满足不了需求，可以自己定义槽函数进行某些特殊功能的实现。
>
> ==**自定义槽函数和自定义的普通函数写法是一样的**。==

![image-20231130170713549](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130170713549.png) 



例如

信号函数: `void testsig(int a, double b);`
槽函数:` void testslot(int a, double b);`



==**槽函数的参数**应该和**对应的信号的参数个数**, **从左到右类型依次对应**==
==**信号的参数可以大于等于槽函数的参数个数** == **此信号传递的数据被忽略了**==
信号函数: `void testsig(int a, double b);`
槽函数: `void testslot(int a);`



Qt中槽函数的类型是多样的

==Qt中的槽函数可以是类的成员函数、全局函数、静态函数、Lambda表达式（匿名函数）==



槽函数可以使用关键字进行声明: slots (Qt5中slots可以省略不写)

`public slots:`
·`private slots:` –> 这样的槽函数==不能在类外部被调用==
·`protected slots:`· –> 这样的槽函数==不能在类外部被调用==

```c++
// 槽函数书写格式举例
// 类中的这三个函数都可以作为槽函数来使用
class Test : public QObject
{
    public:
    void testSlot();
    static void testFunc();

    public slots:
    void testSlot(int id);
};

```



### explicit关键字

explicit关键字是用来==修饰构造函数的==，它**表示该构造函数是显式的，不允许隐式转换**。

**必须显式地调用该构造函数**。这样可以避免一些意外的类型转换和不必要的隐式转换，提高代码的可读性和安全性。



### 例子

me.class

```c++
// class Me
class Me : public QObject
{
    Q_OBJECT
public:
    explicit Me(QObject *parent = nullptr);

public slots:
    // 槽函数
    void eatMeal();             // 不能知道信号发出者要吃什么
    void eatMeal(QString msg);  // 可以知道信号发出者要吃什么
};
```

 class GirlFriend

```c++
// class GirlFriend
class GirlFriend : public QObject
{
    Q_OBJECT
public:
    explicit GirlFriend(QObject *parent = nullptr);

signals:
    void hungry();	            // 不能表达出想要吃什么
    void hungry(QString msg);	// 可以通过参数表达想要吃什么
};


```

### 例子2

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "student.h"
#include "teacher.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    创建对象
    teacher=new Teacher;
    student=new Student;
//两个函数指针代替
    //函数指针
//    void (Student::*myslot)(QString)=&Student::treat_special;
//    void (Teacher::*mysignal)(QString)=&Teacher::Teacher_is_hungery_but;
//    connect(teacher,mysignal,student,myslot);
//    --------------
//    原始写法，函数名的地址
    connect(teacher,&Teacher::Teacher_is_hungery_but,student,&Student::treat_special);
//创建一个按钮
    QPushButton *btn=new QPushButton(this);
    btn->setFixedSize(100,100);
    btn->setText("老师饿了");
    btn->move(500,500);
    btn->show();

//#点击按钮触发下课函数
     connect(btn,&QPushButton::clicked,this,&MainWindow::classover);

//错误的写法
//     connect(btn,&QPushButton::clicked,teacher,&Teacher::Teacher_is_hungery_but("大竹比"));


//    信号连接信号,点击按钮触发老师饿了
//     connect(btn,&QPushButton::clicked,teacher,&Teacher::Teacher_is_hungery);
//     connect(btn,&QPushButton::clicked,std::bind(&Teacher::Teacher_is_hungery_but,teacher,"大竹比"));
//      connect(btn, &QPushButton::clicked, std::bind(&Teacher::Teacher_is_hungery_but, teacher, "大苏打"));
     classover();
        
        //////////////////
    void (QToolBox::*s)(int)=&QToolBox::currentChanged;

    connect(tb,s,this,[=](int index){
        qDebug()<<"新年好"<<index;
    });
        ////////////////////



     connect(ui->closebtn,&QPushButton::clicked,this,&MainWindow::close);




}

//下课函数触发老师饿了
void MainWindow:: classover(){
    //下课函数出发老师饿了的信号
//    emit zt->hungery();
    emit teacher->Teacher_is_hungery_but("宫保鸡丁");
}
MainWindow::~MainWindow()
{
    delete ui;
}


```



## 信号和槽拓展

### 信号槽使用拓展

1. **==一个信号可以连接多个槽函数, 发送一个信号有多个处理动作==**
   1. ==**需要写多个connect（）连接**==
   2. **槽函数的执行顺序是随机的, 和connect函数的调用顺序没有关系**
   3. **信号的接收者可以是一个对象, 也可以是多个对象**
2. **一个槽函数可以连接多个信号, 多个不同的信号, 处理动作是相同的**
   1. ==**需要写多个connect（）连接**==
3. ==信号可以连接信号==

> ==**信号接收者可以不处理接收的信号**, 而是**继续发射新的信号**，这相当于**传递了数据,** 并没有对数据进行处理==

```c++
connect(const QObject *sender, &QObject::signal, 
        const QObject *receiver, &QObject::siganl-new);

```

信号断开

```c++
disconnect(const QObject *sender, &QObject::signal, 
        const QObject *receiver, &QObject::method);

```



### 信号槽的连接方式

#### [Qt5推荐](#应用举例)

==但是也有缺陷，传入函数地址，如果函数有重载版本的化，就要具体指定了，函数指针！==

```c++
// 语法:
QMetaObject::Connection QObject::connect(
    	const QObject *sender, PointerToMemberFunction signal, 
        const QObject *receiver, PointerToMemberFunction method, 
		Qt::ConnectionType type = Qt::AutoConnection);

// 信号和槽函数也就是第2,4个参数传递的是地址, 编译器在编译过程中会对数据的正确性进行检测
connect(const QObject *sender, &QObject::signal, 
        const QObject *receiver, &QObject::method);

```

==信号和槽函数也就是**第2,4个参数传递的是地址,** **编译器在编译过程中会对数据的正确性进行检测**==

#### Qt4

> 这种**旧的信号槽连接方式在Qt5中是支持的,** 但是**不推荐使用**,
>
> 因为这种方式在进行信号槽连接的时候==, 信号槽函数**通过宏SIGNAL和SLOT**转换为**字符串类型**。==
>
> 因为信号槽函数的转换是通过宏来进行转换的，因此==传递到宏函数内部的数据不会被进行检测，==
>
>  如果使用者传错了数据，编译器也不会报错，但实际上信号槽的连接已经不对了，只有在程序运行起来之后才能发现问题，而且==问题不容易被定位。==

```c++
// Qt4的信号槽连接方式
[static] QMetaObject::Connection QObject::connect(
    const QObject *sender, const char *signal, 
    const QObject *receiver, const char *method, 
    Qt::ConnectionType type = Qt::AutoConnection);

connect(const QObject *sender,SIGNAL(信号函数名(参数1, 参数2, ...)),
        const QObject *receiver,SLOT(槽函数名(参数1, 参数2, ...)));
```

==Qt4中声明槽函数必须要使用 slots 关键字, 不能省略。==

### <a name="应用举例">应用举例</a>

```
场景描述：
	- 我肚子饿了, 我要吃东西。
 分析： 
 	- 信号的发出者是我自己, 信号的接收者也是我自己
```

#### 我们首先定义出一个Qt的类。

```c++
class Me : public QObject
{
    Q_OBJECT
    // Qt4中的槽函数必须这样声明, qt5中的关键字 slots 可以被省略
public slots:
    void eat();
    void eat(QString somthing);
    signals:
    void hungury();
    void hungury(QString somthing);
};

// 基于上边的类写出解决方案
// 处理如下逻辑: 我饿了, 我要吃东西
// 分析: 信号的发出者是我自己, 信号的接收者也是我自己
Me m;
// Qt4处理方式
connect(&m, SIGNAL(eat()), &m, SLOT(hungury()));
connect(&m, SIGNAL(eat(QString)), &m, SLOT(hungury(QString)));

// Qt5处理方式
connect(&m, &Me::eat, &m, &Me::hungury);	// error

```

#### Qt5处理方式错误原因分析：

> 上边的写法之所以错误是
>
> ==因为这个类中信号槽都是重载过的, 信号和槽都是通过函数名去关联函数的地址,==
>
> 但是这个同名函数对应两块不同的地址, 一个带参, 一个不带参,
>
> 因此==编译器就不知道去关联哪块地址了==, 所以如果我们在这种时候通过以上方式进行信号槽连接, 编译器就会报错。

#### 如何具体化是哪一个重载版本呢？

> 可以==通过**定义函数指针的方式**指定出函数的具体参数，这样就可以确定函数的具体地址了。==
> ==定义函数指针指向重载的某个信号或者槽函数==，
>
> 在connect（）函数中==将函数指针名字作为实参==就可以了。

```c++

void (Me::*func1)(QString) = &Me::eat;	// func1指向带参的信号
void (Me::*func2)() = &Me::hungury;	// func2指向不带参的槽函数
```

`返回值类型 (作用域::*函数指针变量名) (参数类型)`

然后用`函数指针变量名 = &函数名`来赋值函数地址。

```c++
void (Me::*func1)(QString);
func1=&Me::eat;
```

也可以一气呵成

```c++
void (Me::*func1)(QString) = &Me::eat;
```



#### 制定好后的connect

```c++
// 定义函数指针指向重载的某一个具体的信号地址
void (Me::*mysignal)(QString) = &Me::eat;
// 定义函数指针指向重载的某一个具体的槽函数地址
void (Me::*myslot)(QString) = &Me::hungury;
// 使用定义的函数指针完成信号槽的连接
connect(&m, mysignal, &m, myslot);
```

#### 函数指针拓展

==函数指针是一个指向函数的指针变量，它存储了函数的地址。==

通过函数指针，我们可以在程序运行时动态地调用不同的函数，从而实现更加灵活的编程。



### 总结

![image-20231130172926503](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130172926503.png) 





## Lambda表达式

> Lambda表达式是 C++ 11 最重要也是最常用的特性之一，是现代编程语言的一个特点
>
> 简洁，提高了代码的效率并且可以使程序更加灵活，Qt是完全支持c++语法的
>
>  因此在Qt中也可以使用Lambda表达式。

```c++
[capture](params) opt -> ret {body;};
    - capture: 捕获列表
    - params: 参数列表
    - opt: 函数选项
    - ret: 返回值类型
    - body: 函数体
```

![image-20231130173237175](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130173237175.png) 

### 定义和调用

> 因为==Lambda表达式是一个匿名函数, 因此是没有函数声明的==
>
>  直接在程序中**进行代码的定义**即可, 但是如果==只定义匿名函数在程序执行过程中是不会被调用的==。



==匿名函数的定义, 程序执行这个匿名函数是不会被调用的==

```c++
[](){
    qDebug() << "hello, 我是一个lambda表达式...";
};
```

==匿名函数的定义+调用:==

```c++

int ret = [](int a) -> int
{
    return a+1;
}(100);  // 100是传递给匿名函数的参数

```

> 在Lambda表达式的捕获列表中也就是 []内部添加不同的关键字, 就可以在函数体中使用外部变量了。

```c++
// 在匿名函数外部定义变量
int a=100, b=200, c=300;
// 调用匿名函数
[](){
    // 打印外部变量的值
    qDebug() << "a:" << a << ", b: " << b << ", c:" << c;  // error, 不能使用任何外部变量
}

[&](){
    qDebug() << "hello, 我是一个lambda表达式...";
    qDebug() << "使用引用的方式传递数据: ";
    qDebug() << "a+1:" << a++ << ", b+c= " << b+c;
}();

// 值拷贝的方式使用外部数据
[=](int m, int n)mutable{
    qDebug() << "hello, 我是一个lambda表达式...";
    qDebug() << "使用拷贝的方式传递数据: ";
    // 拷贝的外部数据在函数体内部是只读的, 如果不添加 mutable 关键字是不能修改这些只读数据的值的
    // 添加 mutable 允许修改的数据是拷贝到函数内部的副本, 对外部数据没有影响
    qDebug() << "a+1:" << a++ << ", b+c= " << b+c;
    qDebug() << "m+1: " << ++m << ", n: " << n;
}(1, 2);

```

