# QT中的基础数据类型

> 基础数据类型,
>
> Log日志输出,
>
> 字符串类型,
>
> QVariant,
>
> 位置和尺寸相关类型,
>
> 日期和时间相关类型



## 基础类型

> ==Qt是一个C++ 框架,== 因此==C++中所有的语法和数据类型在Qt中都是被支持==的,
>
> 但是Qt中也定义了一些属于自己的数据类型

![image-20231130154953139](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130154953139.png) 

> 虽然在Qt中有属于自己的整形或者浮点型, 但是在变成过程中这些一般不用, 常用的类型关键字还是 C/C++中的 int, float, double 等。

## log输出

> 在Qt中进行log输出, ==一般不使用c中的printf, 也不是使用C++中的cout==,
>
> Qt框架提供了专门用于日志输出的类, ==头文件名为 QDebug,== 使用方法如下:
>
> 自动换行

```c++
// 包含了QDebug头文件, 直接通过全局函数 qDebug() 就可以进行日志输出了
qDebug() << "Date:" << QDate::currentDate();
qDebug() << "Types:" << QString("String") << QChar('x') << QRect(0, 10, 50, 40);
qDebug() << "Custom coordinate type:" << coordinate;

// 和全局函数 qDebug() 类似的日志函数还有: qWarning(), qInfo(), qCritical()
int number = 666;
float i = 11.11;
qWarning() << "Number:" << number << "Other value:" << i;
qInfo() << "Number:" << number << "Other value:" << i;
qCritical() << "Number:" << number << "Other value:" << i;

qDebug() << "我是要成为海贼王的男人!!!";
qDebug() << "我是隔壁的二柱子...";
qDebug() << "我是鸣人, 我擅长嘴遁!!!";

```

<img src="C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130155247470.png" alt="image-20231130155247470" style="zoom:33%;" /> 



### 终端(黑框)输出日志

> 使用上面的方法只能在项目调试过程中进行日志输出, 如果不是通过IDE进行程序调试, 而是直接执行可执行程序==在这种情况下是没有日志输出窗口的, 因此也就看不到任何的日志输出。==
>
> ==默认情况下日志信息是不会打印到终端窗口的,== 如果想要实现这样的效果, 必须在项目文件中添加相关的属性信息

1. 打开项目文件（*.pro）找到配置项 config, 添加 console 控制台属性
2. ![image-20231130155840925](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130155840925.png) 







## 字符串类型

> 在Qt中不仅支持C, C++中的字符串类型,
>
> 而且还在框架中定义了专属的字符串类型,
>
> 我们**必须要掌握在Qt中关于这些类型的使用和相互之间的转换。**

![image-20231130155907068](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130155907068.png) 



### QByteArray

> Qt中==QByteArray可以看做是c语言中 char*的升级版本==。
>
> 我们在使用这种类型的时候可通过==这个类的构造函数申请一块动态内存==，用于存储我们需要处理的字符串数据。
>
> 下面给大家介绍一下这个类中常用的一些API函数，大家要养成遇到问题主动查询帮助文档的好习惯。。
>

#### 构造函数

```c++
// 构造空对象, 里边没有数据
QByteArray::QByteArray();
// 将data中的size个字符进行构造, 得到一个字节数组对象
// 如果 size==-1 函数内部自动计算字符串长度, 计算方式为: strlen(data)
QByteArray::QByteArray(const char *data, int size = -1);
// 构造一个长度为size个字节, 并且每个字节值都为ch的字节数组
QByteArray::QByteArray(int size, char ch);

```

> <img src="C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130160734162.png" alt="image-20231130160734162" style="zoom:50%;" /> 

#### 数据操作

```c++
// 在尾部追加数据
// 其他重载的同名函数可参考Qt帮助文档, 此处略
QByteArray &QByteArray::append(const QByteArray &ba);
void QByteArray::push_back(const QByteArray &other);

// 头部添加数据
// 其他重载的同名函数可参考Qt帮助文档, 此处略
QByteArray &QByteArray::prepend(const QByteArray &ba);
void QByteArray::push_front(const QByteArray &other);

// 插入数据, 将ba插入到数组第 i 个字节的位置(从0开始)
// 其他重载的同名函数可参考Qt帮助文档, 此处略
QByteArray &QByteArray::insert(int i, const QByteArray &ba);

// 删除数据
// 从大字符串中删除len个字符, 从第pos个字符的位置开始删除
QByteArray &QByteArray::remove(int pos, int len);
// 从字符数组的尾部删除 n 个字节
void QByteArray::chop(int n);
// 从字节数组的 pos 位置将数组截断 (前边部分留下, 后边部分被删除)
void QByteArray::truncate(int pos);
// 将对象中的数据清空, 使其为null
void QByteArray::clear();

// 字符串替换
// 将字节数组中的 子字符串 before 替换为 after
// 其他重载的同名函数可参考Qt帮助文档, 此处略
QByteArray &QByteArray::replace(const QByteArray &before, const QByteArray &after);

```

> ```c++
> QByteArray *qb=new QByteArray("hello world");
> QByteArray *qb1=new QByteArray();
> QByteArray *qb2=new QByteArray(10,'a');
> QByteArray q;
> q.push_back(*qb);
>     qDebug()<<q;
>         q.append("dsa").append("dsadsa");
> qDebug()<<q;
> //    "hello world"
> //"hello worlddsadsadsa"
> ```
>
> 

#### 子字符串查找和判断

```c++
// 判断字节数组中是否包含子字符串 ba, 包含返回true, 否则返回false
bool QByteArray::contains(const QByteArray &ba) const;
bool QByteArray::contains(const char *ba) const;
// 判断字节数组中是否包含子字符 ch, 包含返回true, 否则返回false
bool QByteArray::contains(char ch) const;

// 判断字节数组是否以字符串 ba 开始, 是返回true, 不是返回false
bool QByteArray::startsWith(const QByteArray &ba) const;
bool QByteArray::startsWith(const char *ba) const;
// 判断字节数组是否以字符 ch 开始, 是返回true, 不是返回false
bool QByteArray::startsWith(char ch) const;

// 判断字节数组是否以字符串 ba 结尾, 是返回true, 不是返回false
bool QByteArray::endsWith(const QByteArray &ba) const;
bool QByteArray::endsWith(const char *ba) const;
// 判断字节数组是否以字符 ch 结尾, 是返回true, 不是返回false
bool QByteArray::endsWith(char ch) const;

```



#### 遍历

```c++
// 使用迭代器
iterator QByteArray::begin();
iterator QByteArray::end();

// 使用数组的方式进行遍历
// i的取值范围 0 <= i < size()
char QByteArray::at(int i) const;
char QByteArray::operator[](int i) const;

```



#### 查看字节数

```c++
// 返回字节数组对象中字符的个数
int QByteArray::length() const;
int QByteArray::size() const;
int QByteArray::count() const;

// 返回字节数组对象中 子字符串ba 出现的次数
int QByteArray::count(const QByteArray &ba) const;
int QByteArray::count(const char *ba) const;
// 返回字节数组对象中 字符串ch 出现的次数
int QByteArray::count(char ch) const;

```



#### 类型转换

```c++
// 将QByteArray类型的字符串 转换为 char* 类型
char *QByteArray::data();
const char *QByteArray::data() const;

// int, short, long, float, double -> QByteArray
// 其他重载的同名函数可参考Qt帮助文档, 此处略
QByteArray &QByteArray::setNum(int n, int base = 10);
QByteArray &QByteArray::setNum(short n, int base = 10);
QByteArray &QByteArray::setNum(qlonglong n, int base = 10);
QByteArray &QByteArray::setNum(float n, char f = 'g', int prec = 6);
QByteArray &QByteArray::setNum(double n, char f = 'g', int prec = 6);
[static] QByteArray QByteArray::number(int n, int base = 10);
[static] QByteArray QByteArray::number(qlonglong n, int base = 10);
[static] QByteArray QByteArray::number(double n, char f = 'g', int prec = 6);

// QByteArray -> int, short, long, float, double
int QByteArray::toInt(bool *ok = Q_NULLPTR, int base = 10) const;
short QByteArray::toShort(bool *ok = Q_NULLPTR, int base = 10) const;
long QByteArray::toLong(bool *ok = Q_NULLPTR, int base = 10) const;
float QByteArray::toFloat(bool *ok = Q_NULLPTR) const;
double QByteArray::toDouble(bool *ok = Q_NULLPTR) const;

// std::string -> QByteArray
[static] QByteArray QByteArray::fromStdString(const std::string &str);
// QByteArray -> std::string
std::string QByteArray::toStdString() const;

// 所有字符转换为大写
QByteArray QByteArray::toUpper() const;
// 所有字符转换为小写
QByteArray QByteArray::toLower() const;

```

### QString

> QString也是封装了字符串, 但是内部的编码为utf8,
>
> ==UTF-8属于Unicode字符集, 它固定使用多个字节（window为2字节, linux为3字节）来表示一个字符==
>
> 这样可以将世界上几乎所有语言的常用字符收录其中。

#### 构造函数

```c++
// 构造一个空字符串对象
QString::QString();
// 将 char* 字符串 转换为 QString 类型
QString::QString(const char *str);
// 将 QByteArray 转换为 QString 类型
QString::QString(const QByteArray &ba);
// 其他重载的同名构造函数可参考Qt帮助文档, 此处略
```

> ```c++
> QString *qs=new QString("dsadsad");
> qDebug()<<*qs;
> ```

#### 数据操作

```c++
// 尾部追加数据
// 其他重载的同名函数可参考Qt帮助文档, 此处略
QString &QString::append(const QString &str);
QString &QString::append(const char *str);
QString &QString::append(const QByteArray &ba);
void QString::push_back(const QString &other);

// 头部添加数据
// 其他重载的同名函数可参考Qt帮助文档, 此处略
QString &QString::prepend(const QString &str);
QString &QString::prepend(const char *str);
QString &QString::prepend(const QByteArray &ba);
void QString::push_front(const QString &other);

// 插入数据, 将 str 插入到字符串第 position 个字符的位置(从0开始)
// 其他重载的同名函数可参考Qt帮助文档, 此处略
QString &QString::insert(int position, const QString &str);
QString &QString::insert(int position, const char *str);
QString &QString::insert(int position, const QByteArray &str);

// 删除数据
// 从大字符串中删除len个字符, 从第pos个字符的位置开始删除
QString &QString::remove(int position, int n);

// 从字符串的尾部删除 n 个字符
void QString::chop(int n);


// 从字节串的 position 位置将字符串截断 (前边部分留下, 后边部分被删除)
void QString::truncate(int position);


// 将对象中的数据清空, 使其为null
void QString::clear();

// 字符串替换
// 将字节数组中的 子字符串 before 替换为 after
// 参数 cs 为是否区分大小写, 默认区分大小写
// 其他重载的同名函数可参考Qt帮助文档, 此处略
QString &QString::replace(const QString &before, const QString &after, Qt::CaseSensitivity cs = Qt::CaseSensitive);


```



#### 子字符串查找和判断

```c++
// 参数 cs 为是否区分大小写, 默认区分大小写
// 其他重载的同名函数可参考Qt帮助文档, 此处略

// 判断字符串中是否包含子字符串 str, 包含返回true, 否则返回false
bool QString::contains(const QString &str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;

// 判断字符串是否以字符串 ba 开始, 是返回true, 不是返回false
bool QString::startsWith(const QString &s, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;

// 判断字符串是否以字符串 ba 结尾, 是返回true, 不是返回false
bool QString::endsWith(const QString &s, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;

```



#### 遍历

```c++
// 使用迭代器
iterator QString::begin();
iterator QString::end();

// 使用数组的方式进行遍历
// i的取值范围 0 <= position < size()
const QChar QString::at(int position) const
const QChar QString::operator[](int position) const;
```

> ```c++
>     QString *qs=new QString("dsadsad");
>     qDebug()<<*qs;
>     for(QString::Iterator i=qs->begin();i!=qs->end();i++)
>     {
>         qDebug()<<*i<<" ";
>     }
> //    "dsadsad"
> //        'd'  
> //        's'  
> //        'a'  
> //        'd'  
> //        's'  
> //        'a'  
> //        'd'  
> ```

#### 查看字节数

```c++
// 返回字节数组对象中字符的个数 (字符个数和字节个数是不同的概念)
int QString::length() const;
int QString::size() const;
int QString::count() const;

// 返回字节串对象中 子字符串 str 出现的次数
// 参数 cs 为是否区分大小写, 默认区分大小写
int QString::count(const QStringRef &str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;

```

> 字符数和字节数是计量文本长度的两种不同方式。
>
> ==字符数指的是文本中包含的字符的数量==，不论是英文字母、数字、标点符号还是其他语言的字符都计算在内。举例来说，单词"Hello"的字符数为5。
>
> ==字节数则是指文本所占据的存储空间大小，每个字符在计算机中都有对应的编码方式。常见的编码方式包括ASCII、UTF-8、UTF-16等，不同的编码方式会占用不同数量的字节==。举例来说，以UTF-8编码计算，单词"Hello"的字节数为5个字节。
>
> 需要注意的是，对于大部分英文文本而言，一个字符通常只占用一个字节的存储空间。然而，对于一些使用了多字节编码的字符集（如中文、日文、韩文等），一个字符可能占用多个字节的存储空间。。
>

#### 类型转换

> 将int, short, long, float, double 转换为 QString 类型
>
> QString 转换为 int, short, long, float, double 类型
>
> ---
>
>  将标准C++中的 std::string 类型 转换为 QString 类型
>
> 将 QString 转换为 标准C++中的 std::string 类型
>
> ---
>
> QString -> QByteArray
>
> 所有字符转换为大/小写
>
> ==// 转换为 utf8 编码格式的字符串 (常用)==

```c++
// 将int, short, long, float, double 转换为 QString 类型
// 其他重载的同名函数可参考Qt帮助文档, 此处略
QString &QString::setNum(int n, int base = 10);
QString &QString::setNum(short n, int base = 10);
QString &QString::setNum(long n, int base = 10);
QString &QString::setNum(float n, char format = 'g', int precision = 6);
QString &QString::setNum(double n, char format = 'g', int precision = 6);
[static] QString QString::number(long n, int base = 10);
[static] QString QString::number(int n, int base = 10);
[static] QString QString::number(double n, char format = 'g', int precision = 6);

// 将 QString 转换为 int, short, long, float, double 类型
int QString::toInt(bool *ok = Q_NULLPTR, int base = 10) const;
short QString::toShort(bool *ok = Q_NULLPTR, int base = 10) const;
long QString::toLong(bool *ok = Q_NULLPTR, int base = 10) const
float QString::toFloat(bool *ok = Q_NULLPTR) const;
double QString::toDouble(bool *ok = Q_NULLPTR) const;

// 将标准C++中的 std::string 类型 转换为 QString 类型
[static] QString QString::fromStdString(const std::string &str);
// 将 QString 转换为 标准C++中的 std::string 类型
std::string QString::toStdString() const;

// QString -> QByteArray
// 转换为本地编码, 跟随操作系统
QByteArray QString::toLocal8Bit() const;
// 转换为 Latin-1 编码的字符串 不支持中文
QByteArray QString::toLatin1() const;
// 转换为 utf8 编码格式的字符串 (常用)
QByteArray QString::toUtf8() const;

// 所有字符转换为大写
QString QString::toUpper() const;
// 所有字符转换为小写
QString QString::toLower() const;


```



#### 字符串格式

```c++
// 其他重载的同名函数可参考Qt帮助文档, 此处略
QString QString::arg(const QString &a, 
          int fieldWidth = 0, 
          QChar fillChar = QLatin1Char( ' ' )) const;
QString QString::arg(int a, int fieldWidth = 0, 
          int base = 10, 
          QChar fillChar = QLatin1Char( ' ' )) const;

```

> ```c++
>     // 示例程序
>     int i;                // 假设该变量表示当前文件的编号
>     int total;            // 假设该变量表示文件的总个数
>     QString fileName="dsadsa";     // 假设该变量表示当前文件的名字
>     // 使用以上三个变量拼接一个动态字符串
>     QString status = QString("Processing file %1 of %2: %3").arg(i).arg(total).arg(fileName);
> 
>     qDebug()<<status;
> //    "Processing file 0 of 1: dsadsa"
> ```
>
> %1..........





##  QVariant

> QVariant这个类很神奇，或者说方便。
>
> 很多时候，需要几种不同的数据类型需要传递，如果用结构体，又不大方便，容器保存的也只是一种数据类型，而QVariant则可以统统搞定。
>
> ==QVariant 这个类型充当着最常见的数据类型的联合。==
>
> QVariant 可以保存很多Qt的数据类型，包括QBrush、QColor、QCursor、QDateTime、QFont、QKeySequence、 QPalette、QPen、QPixmap、QPoint、QRect、QRegion、QSize和QString，并且还有C++基本类型，如 int、float等。

### 标准类型

> 将标准类型转换为QVariant类型

```c++
// 这类转换需要使用QVariant类的构造函数, 由于比较多, 大家可自行查阅Qt帮助文档, 在这里简单写几个
QVariant::QVariant(int val);
QVariant::QVariant(bool val);
QVariant::QVariant(double val);
QVariant::QVariant(const char *val);
QVariant::QVariant(const QByteArray &val);
QVariant::QVariant(const QString &val);
......
    
// 使用设置函数也可以将支持的类型的数据设置到QVariant对象中
// 这里的 T 类型, 就是QVariant支持的类型
void QVariant::setValue(const T &value);
// 该函数行为和 setValue() 函数完全相同
[static] QVariant QVariant::fromValue(const T &value);
// 例子:
#if 1
QVariant v;
v.setValue(5);
#else
QVariant v = QVariant::fromValue(5);
#endif

int i = v.toInt();          // i is now 5
QString s = v.toString();   // s is now "5"
	 
```

### 判断QVariant封装的实际类型

```c++
// 该函数的返回值是一个枚举类型, 可通过这个枚举判断出实际是什么类型的数据
Type QVariant::type() const;
```

> ```c++
>     QVariant a("hello");
>     qDebug()<<a.typeName();
> //    QString
> ```
>
> 返回值Type的部分枚举定义, 全部信息可以自行查阅Qt帮助文档
>
> ![image-20231130162709759](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130162709759.png) 

### 拆开封装的数据

`to拆包后的数据类型`

```c++
// 如果要实现该操作, 可以使用QVariant类提供的 toxxx() 方法, 全部转换可以参考Qt帮助文档
// 在此举列举几个常用函数:
bool QVariant::toBool() const;
QByteArray QVariant::toByteArray() const;
double QVariant::toDouble(bool *ok = Q_NULLPTR) const;
float QVariant::toFloat(bool *ok = Q_NULLPTR) const;
int QVariant::toInt(bool *ok = Q_NULLPTR) const;
QString QVariant::toString() const;
......
```

### 自定义类型

> 除了标准类型, 我们==自定义的类型也可以使用QVariant类进行封装==,
>
> ==被QVariant存储的数据类型**需要有一个默认的构造函数和一个拷贝构造函数**==
>
> 为了实现这个功能，通常会将这个宏放在类的声明所在头文件的下面， 原型为：
>
> 1. 首先必须使用Q_DECLARE_METATYPE()宏。
>
>   Q_DECLARE_METATYPE(Type)

自定义类型的头文件

```c++
// *.h
struct MyTest
{
    int id;
    QString name;
};
// 自定义类型注册
Q_DECLARE_METATYPE(MyTest)
```

自定义类型的源文件

```c++
MyTest t;
t.name = "张三丰";
t.num = 666;
// 值的封装
QVariant vt = QVariant::fromValue(t);

// 值的读取
if(vt.canConvert<MyTest>())
{
    MyTest t = vt.value<MyTest>();
    qDebug() << "name: " << t.name << ", num: " << t.num;
}

```

> ```c++
> // 值的封装
> QVariant vt = QVariant::fromValue(t);
> // 如果当前QVariant对象可用转换为对应的模板类型 T, 返回true, 否则返回false
> bool QVariant::canConvert() const;
> // 将当前QVariant对象转换为实际的 T 类型
> T QVariant::value() const;
> 
> ```
>
> 



## QT位置和尺寸

![image-20230803140624518](E:\MD\QTT.assets\image-20230803140624518.png)

### QPOINT

![image-20230803140635397](E:\MD\QTT.assets\image-20230803140635397.png)

```c++
// 构造函数
// 构造一个坐标原点, 即(0, 0)
QPoint::QPoint();
// 参数为 x轴坐标, y轴坐标
QPoint::QPoint(int xpos, int ypos);

// 设置x轴坐标
void QPoint::setX(int x);
// 设置y轴坐标
void QPoint::setY(int y);

// 得到x轴坐标
int QPoint::x() const;
// 得到x轴坐标的引用
int &QPoint::rx();
// 得到y轴坐标
int QPoint::y() const;
// 得到y轴坐标的引用
int &QPoint::ry();

// 直接通过坐标对象进行算术运算: 加减乘除
QPoint &QPoint::operator*=(float factor);
QPoint &QPoint::operator*=(double factor);
QPoint &QPoint::operator*=(int factor);
QPoint &QPoint::operator+=(const QPoint &point);
QPoint &QPoint::operator-=(const QPoint &point);
QPoint &QPoint::operator/=(qreal divisor);

// 其他API请自行查询Qt帮助文档,
```

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
// 创建坐标对象
    QPoint p;
    QPoint p1(2,3);

//设置x，y坐标
    p.setX(10);
    p.setY(20);
    //2/2/2/2/2/

//得到x，y坐标
    qDebug()<<p.x();
    qDebug()<<p.y();
    qDebug()<<p1.x();
    qDebug()<<p1.y();

//得到x，y坐标的引用
    int &x1=p.rx();
    int &y1=p.ry();
    x1=100;
    y1=200;

    int &x2=p1.rx();
    int &y2=p1.ry();

    x2=1;
    y2=2;
//再次得到通过引用修改后的坐标
    qDebug()<<p.x();
    qDebug()<<p.y();
    qDebug()<<p1.x();
    qDebug()<<p1.y();

}

MainWindow::~MainWindow()
{
    delete ui;
}
10
20
2
3
100
200
1

```

----

### QLINE

![image-20230803141547493](E:\MD\QTT.assets\image-20230803141547493.png)

```c++
// 构造函数
// 构造一个空对象
QLine::QLine();
// 构造一条直线, 通过两个坐标点
QLine::QLine(const QPoint &p1, const QPoint &p2);
// 从点 (x1, y1) 到 (x2, y2)
QLine::QLine(int x1, int y1, int x2, int y2);

// 给直线对象设置坐标点
void QLine::setPoints(const QPoint &p1, const QPoint &p2);
// 起始点(x1, y1), 终点(x2, y2)
void QLine::setLine(int x1, int y1, int x2, int y2);
// 设置直线的起点坐标
void QLine::setP1(const QPoint &p1);
// 设置直线的终点坐标
void QLine::setP2(const QPoint &p2);

// 返回直线的起始点坐标
QPoint QLine::p1() const;
// 返回直线的终点坐标
QPoint QLine::p2() const;
// 返回值直线的中心点坐标, (p1() + p2()) / 2
QPoint QLine::center() const;

// 返回值直线起点的 x 坐标
int QLine::x1() const;
// 返回值直线终点的 x 坐标
int QLine::x2() const;
// 返回值直线起点的 y 坐标
int QLine::y1() const;
// 返回值直线终点的 y 坐标
int QLine::y2() const;

// 用给定的坐标点平移这条直线
void QLine::translate(const QPoint &offset);
void QLine::translate(int dx, int dy);
// 用给定的坐标点平移这条直线, 返回平移之后的坐标点
QLine QLine::translated(const QPoint &offset) const;
QLine QLine::translated(int dx, int dy) const;

// 直线对象进行比较
bool QLine::operator!=(const QLine &line) const;
bool QLine::operator==(const QLine &line) const;

// 其他API请自行查询Qt帮助文档, 不要犯懒哦哦哦哦哦......

```



```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPoint p1(10,10);
    QPoint p2(20,20);

//创建直线，传入有参构造的时候直接传入两个点point
 //先创建一个空对象，然后空对象.setpoints
    //直接用四个参数的有参构造函数创建
    QLine line(p1,p2);
    QLine line1(1,2,3,4);
    QLine line2;
    line2.setPoints(p1,p2);
//可以得到直线的坐标起点，中点，重点.四个坐标，x1,x2,y1,y2或者得到起/末点再 .x()
    qDebug()<<line.p1();
    qDebug()<<line.p2();
    qDebug()<<line.center();
//    QPoint(10,20)
//    QPoint(20,40)
//    QPoint(15,30)

    //这个是根据这个点平移后，修改直线相当于方法使用
    // 平移线段的起点和终点，偏移量为 (5, 5)
    line.translate(5, 5);

    qDebug() << line.p1(); // 输出 (15, 15)
    qDebug() << line.p2(); // 输出 (55, 55)

    //这个是根据这个点平移后返回线段对象,相当于函数使用
    QLine newline=line.translated(10,20);
    qDebug() << newline.p1(); // 输出 (15, 15)
    qDebug() << newline.p2(); // 输出 (55, 55)

}

MainWindow::~MainWindow()
{
    delete ui;
}


```



### QSIZE

![image-20230803143027470](E:\MD\QTT.assets\image-20230803143027470.png)

```c++
// 构造函数
// 构造空对象, 对象中的宽和高都是无效的
QSize::QSize();
// 使用宽和高构造一个有效对象
QSize::QSize(int width, int height);

// 设置宽度
void QSize::setWidth(int width)
// 设置高度
void QSize::setHeight(int height);

// 得到宽度
int QSize::width() const;
// 得到宽度的引用
int &QSize::rwidth();
// 得到高度
int QSize::height() const;
// 得到高度的引用
int &QSize::rheight();

// 交换高度和宽度的值
void QSize::transpose();
// 交换高度和宽度的值, 返回交换之后的尺寸信息
QSize QSize::transposed() const;

// 进行算法运算: 加减乘除
QSize &QSize::operator*=(qreal factor);
QSize &QSize::operator+=(const QSize &size);
QSize &QSize::operator-=(const QSize &size);
QSize &QSize::operator/=(qreal divisor);

// 其他API请自行查询Qt帮助文档, 不要犯懒哦哦哦哦哦......

```

```c++
#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//实例化对象，注意无参的时候千万不能有（）；
    QSize p;
    QSize p1(20,30);

//手动设置宽高
    p.setWidth(10);
    p.setHeight(20);

//得到宽和高
    qDebug()<<p.width();
    qDebug()<<p.height();
    qDebug()<<p1.width();
    qDebug()<<p1.height();
//得到宽和高的引用并且修改
    int &w1=p.rwidth();
    int &w2=p1.rwidth();
    int &h1=p.rheight();
    int &h2=p1.rheight();

    w1=1;
    w2=1;
    h1=2;
    h2=2;

    qDebug()<<p.width();
    qDebug()<<p.height();
    qDebug()<<p1.width();
    qDebug()<<p1.height();

//将宽和高反转
    p.transpose();
    p1.transpose();
    qDebug()<<p.width();
    qDebug()<<p.height();
    qDebug()<<p1.width();
    qDebug()<<p1.height();
qDebug()<<"------------------";
//
    QSize newp=p.transposed();
    QSize newp1=p1.transposed();
    qDebug()<<newp.width();
    qDebug()<<newp.height();
    qDebug()<<newp1.width();
    qDebug()<<newp1.height();

    return a.exec();
}
10
20
20
30
    
1
2
1
2
    
2
1
2
1
------------------
1
2
1
2
```







### QRECT

![image-20230803144048156](E:\MD\QTT.assets\image-20230803144048156.png)

**长/宽是末减初+1**

```c++
// 构造函数
// 构造一个空对象
QRect::QRect();
// 基于左上角坐标, 和右下角坐标构造一个矩形对象
QRect::QRect(const QPoint &topLeft, const QPoint &bottomRight);


默认是左上角和右下角的关系，如果穿了一个左下角和一个右上角的，顺序就相反了，避免
// 基于左上角坐标, 和 宽度, 高度构造一个矩形对象
QRect::QRect(const QPoint &topLeft, const QSize &size);

长/宽是末减初+1
    
    
// 通过 左上角坐标(x, y), 和 矩形尺寸(width, height) 构造一个矩形对象
QRect::QRect(int x, int y, int width, int height);

// 设置矩形的尺寸信息, 左上角坐标不变
void QRect::setSize(const QSize &size);
// 设置矩形左上角坐标为(x,y), 大小为(width, height)
void QRect::setRect(int x, int y, int width, int height);
// 设置矩形宽度
void QRect::setWidth(int width);
// 设置矩形高度
void QRect::setHeight(int height);

// 返回值矩形左上角坐标
QPoint QRect::topLeft() const;
// 返回矩形右上角坐标
// 该坐标点值为: QPoint(left() + width() -1, top())
QPoint QRect::topRight() const;
// 返回矩形左下角坐标
// 该坐标点值为: QPoint(left(), top() + height() - 1)
QPoint QRect::bottomLeft() const;
// 返回矩形右下角坐标
// 该坐标点值为: QPoint(left() + width() -1, top() + height() - 1)
QPoint QRect::bottomRight() const;
// 返回矩形中心点坐标
QPoint QRect::center() const;

// 返回矩形上边缘y轴坐标
int QRect::top() const;
int QRect::y() const;
// 返回值矩形下边缘y轴坐标
int QRect::bottom() const;
// 返回矩形左边缘 x轴坐标
int QRect::x() const;
int QRect::left() const;
// 返回矩形右边缘x轴坐标
int QRect::right() const;

// 返回矩形的高度
int QRect::width() const;
// 返回矩形的宽度
int QRect::height() const;
// 返回矩形的尺寸信息
QSize QRect::size() const;
```

## 日期和时间

### QDATE

需要引入头文件！

![image-20230804080321434](E:\MD\QTT.assets\image-20230804080321434.png)

```c++
// 构造函数
QDate::QDate();
QDate::QDate(int y, int m, int d);

// 公共成员函数
// 重新设置日期对象中的日期
bool QDate::setDate(int year, int month, int day);
// 给日期对象添加 ndays 天
QDate QDate::addDays(qint64 ndays) const;
// 给日期对象添加 nmonths 月
QDate QDate::addMonths(int nmonths) const;
// 给日期对象添加 nyears 月
QDate QDate::addYears(int nyears) const;

// 得到日期对象中的年/月/日
int QDate::year() const;
int QDate::month() const;
int QDate::day() const;
void QDate::getDate(int *year, int *month, int *day) const;

// 日期对象格式化
/*
    d    - The day as a number without a leading zero (1 to 31)
    dd   - The day as a number with a leading zero (01 to 31)
    ddd	 -  周四
    dddd - 星期四
    M    - The month as a number without a leading zero (1 to 12)
    MM   - The month as a number with a leading zero (01 to 12)
    MMM	 9月
    MMMM 九月
    yy   - The year as a two digit number (00 to 99)
    yyyy - The year as a four digit number. If the year is negative, a minus sign is prepended, making five characters.
*/
QString QDate::toString(const QString &format) const;

// 操作符重载 ==> 日期比较
bool QDate::operator!=(const QDate &d) const;
bool QDate::operator<(const QDate &d) const;
bool QDate::operator<=(const QDate &d) const;
bool QDate::operator==(const QDate &d) const;
bool QDate::operator>(const QDate &d) const;
bool QDate::operator>=(const QDate &d) const;

// 静态函数 -> 得到本地的当前日期
[static] QDate QDate::currentDate();
```

```c++
    #include "mainwindow.h"
    #include "ui_mainwindow.h"
    #include <QDate>
    #include <QDebug>
    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        QDate a(2023,8,4);
        QDate b;
        b.setDate(2023,8,5);
        //////
        QDate c=QDate::currentDate();
        //////
        qDebug()<<c;
        c=c.addDays(10);
        c=c.addMonths(1);
        qDebug()<<c;
        qDebug()<<c.year();

        QString str=c.toString("yy-MMM-ddd");
        qDebug()<<str;


    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }


```



### QTIME

![image-20230804082459651](E:\MD\QTT.assets\image-20230804082459651.png)

```c++
// 构造函数
QTime::QTime();
/*
    h 		==> 取值范围： 0 ~ 23
    m and s 	==> 取值范围： 0 ~ 59
    ms 		==> 取值范围： 0 ~ 999
*/ 
QTime::QTime(int h, int m, int s = 0, int ms = 0);

// 公共成员函数
// Returns true if the set time is valid; otherwise returns false.
bool QTime::setHMS(int h, int m, int s, int ms = 0);
QTime QTime::addSecs(int s) const;
QTime QTime::addMSecs(int ms) const;

// 示例代码
  QTime n(14, 0, 0);                // n == 14:00:00
  QTime t;
  t = n.addSecs(70);                // t == 14:01:10
  t = n.addSecs(-70);               // t == 13:58:50
  t = n.addSecs(10 * 60 * 60 + 5);  // t == 00:00:05
  t = n.addSecs(-15 * 60 * 60);     // t == 23:00:00

// 从时间对象中取出 时/分/秒/毫秒
// Returns the hour part (0 to 23) of the time. Returns -1 if the time is invalid.
int QTime::hour() const;
// Returns the minute part (0 to 59) of the time. Returns -1 if the time is invalid.
int QTime::minute() const;
// Returns the second part (0 to 59) of the time. Returns -1 if the time is invalid.
int QTime::second() const;
// Returns the millisecond part (0 to 999) of the time. Returns -1 if the time is invalid.
int QTime::msec() const;


// 时间格式化
/*
    -- 时 --
    h	==>	The hour without a leading zero (0 to 23 or 1 to 12 if AM/PM display)
    hh	==>	The hour with a leading zero (00 to 23 or 01 to 12 if AM/PM display)
    H	==>	The hour without a leading zero (0 to 23, even with AM/PM display)
    HH	==>	The hour with a leading zero (00 to 23, even with AM/PM display)
    -- 分 --
    m	==>	The minute without a leading zero (0 to 59)
    mm	==>	The minute with a leading zero (00 to 59)
    -- 秒 --
    s	==>	The whole second, without any leading zero (0 to 59)
    ss	==>	The whole second, with a leading zero where applicable (00 to 59)
    -- 毫秒 --
    zzz	==>	The fractional part of the second, to millisecond precision, 
			including trailing zeroes where applicable (000 to 999).
    -- 上午或者下午
    AP or A	==>	使用AM/PM(大写) 描述上下午, 中文系统显示汉字
    ap or a	==>	使用am/pm(小写) 描述上下午, 中文系统显示汉字
*/
QString QTime::toString(const QString &format) const;

// 阶段性计时
// 过时的API函数
// 开始计时
void QTime::start();
// 计时结束
int QTime::elapsed() const;
// 重新计时
int QTime::restart();

// 推荐使用的API函数
// QElapsedTimer 类
void QElapsedTimer::start();
qint64 QElapsedTimer::restart();
qint64 QElapsedTimer::elapsed() const;


// 操作符重载 ==> 时间比较
bool QTime::operator!=(const QTime &t) const;
bool QTime::operator<(const QTime &t) const;
bool QTime::operator<=(const QTime &t) const;
bool QTime::operator==(const QTime &t) const;
bool QTime::operator>(const QTime &t) const;
bool QTime::operator>=(const QTime &t) const;

// 静态函数 -> 得到当前时间
[static] QTime QTime::currentTime();
```

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QDebug>
#include <QElapsedTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QElapsedTimer time;
    time.start();
    QTime a(8,26,40,999);
//    h 0~23
//    m 0~59
//    s 0~59
//    ms 0~999
    qDebug()<<a;
    qDebug()<<a.hour();
    qDebug()<<a.minute();
    qDebug()<<a.second();
    qDebug()<<a.msec();
    QTime b;
    b.setHMS(20,20,20,20);
    qDebug()<<b;
    QTime c=c.currentTime();
    qDebug()<<c;
//    QTime("08:35:08.486")
    qint64 time1=time.elapsed();
    qDebug()<<time1;

        QElapsedTimer timer;

        timer.start(); // 开始计时

        // 执行一些需要测量的代码
        for (int i = 0; i < 300; i++) {
            qDebug()<<"-";
        }

        qint64 elapsedTime = timer.elapsed(); // 获取经过的时间（以毫秒为单位）
        qDebug() << "Elapsed Time:" << elapsedTime << "ms";
//        Elapsed Time: 7 ms
}

MainWindow::~MainWindow()
{
    delete ui;
}
```



### QDATETIME

![image-20230804084530792](E:\MD\QTT.assets\image-20230804084530792.png)

```Cpp
// 构造函数
QDateTime::QDateTime();
QDateTime::QDateTime(const QDate &date, const QTime &time, Qt::TimeSpec spec = Qt::LocalTime);

// 公共成员函数
// 设置日期
void QDateTime::setDate(const QDate &date);
// 设置时间
void QDateTime::setTime(const QTime &time);
// 给当前日期对象追加 年/月/日/秒/毫秒, 参数可以是负数
QDateTime QDateTime::addYears(int nyears) const;
QDateTime QDateTime::addMonths(int nmonths) const;
QDateTime QDateTime::addDays(qint64 ndays) const;
QDateTime QDateTime::addSecs(qint64 s) const;
QDateTime QDateTime::addMSecs(qint64 msecs) const;

// 得到对象中的日期
QDate QDateTime::date() const;
// 得到对象中的时间
QTime QDateTime::time() const;

// 日期和时间格式, 格式字符参考QDate 和 QTime 类的 toString() 函数
QString QDateTime::toString(const QString &format) const;


// 操作符重载 ==> 日期时间对象的比较
bool QDateTime::operator!=(const QDateTime &other) const;
bool QDateTime::operator<(const QDateTime &other) const;
bool QDateTime::operator<=(const QDateTime &other) const;
bool QDateTime::operator==(const QDateTime &other) const;
bool QDateTime::operator>(const QDateTime &other) const;
bool QDateTime::operator>=(const QDateTime &other) const;

// 静态函数
// 得到当前时区的日期和时间(本地设置的时区对应的日期和时间)
[static] QDateTime QDateTime::currentDateTime();

```

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QDate>
#include <QDateTime>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDate date(2023,8,4);
    QTime time(8,55,30,876);
    QDateTime datetime(date,time);
    qDebug()<<datetime;

    QDateTime newtime;
    newtime.setDate(date);
    newtime.setTime(time);


    newtime=newtime.addDays(1);
    newtime=newtime.addSecs(23);
        qDebug()<<newtime;
        
    QDateTime now= QDateTime::currentDateTime();
qDebug()<<now;
        
   QString str=now.toString("yyyy-MM-dddd hh:mm:ss ap");
   qDebug()<<str;
}

MainWindow::~MainWindow()
{
    delete ui;
}


```

> ```c++
>     QDateTime now= QDateTime::currentDateTime();
>     qDebug()<<now;
> //QDateTime(2023-11-30 16:42:47.860 中国标准时间 Qt::LocalTime)
> 
>     QString str=now.toString("yyyy-MM-dddd HH:mm:ss ap");
>     qDebug()<<str;
> //"2023-11-Thursday 16:42:47 pm"
> ```
>
> ==最常用的一集==
>
> > ```c++
> > // 静态函数
> > // 得到当前时区的日期和时间(本地设置的时区对应的日期和时间)
> > [static] QDateTime QDateTime::currentDateTime();
> > ```
>
> > ```
> > // 时间格式化
> > /*
> >     -- 时 --
> >     h	==>	The hour without a leading zero (0 to 23 or 1 to 12 if AM/PM display)
> >     hh	==>	The hour with a leading zero (00 to 23 or 01 to 12 if AM/PM display)
> >     H	==>	The hour without a leading zero (0 to 23, even with AM/PM display)
> >     HH	==>	The hour with a leading zero (00 to 23, even with AM/PM display)
> >     -- 分 --
> >     m	==>	The minute without a leading zero (0 to 59)
> >     mm	==>	The minute with a leading zero (00 to 59)
> >     -- 秒 --
> >     s	==>	The whole second, without any leading zero (0 to 59)
> >     ss	==>	The whole second, with a leading zero where applicable (00 to 59)
> >     -- 毫秒 --
> >     zzz	==>	The fractional part of the second, to millisecond precision, 
> > 			including trailing zeroes where applicable (000 to 999).
> >     -- 上午或者下午
> >     AP or A	==>	使用AM/PM(大写) 描述上下午, 中文系统显示汉字
> >     ap or a	==>	使用am/pm(小写) 描述上下午, 中文系统显示汉字
> > */
> > ```
> >
> > 