# QT入门

> 包括Qt的特点, Qt中的模块划分, Qt的安装, Qt项目文件介绍, Qt中的窗口类, Qt窗口的坐标体系, Qt框架的内存回收机制。



## QT概述



### 什么是Qt

> 是一个跨平台的C++应用程序开发框架
>
> 具有短平快的优秀特质: 投资少、周期短、见效快、效益高
>
> 几乎支持所有的平台, 可用于桌面程序开发以及嵌入式开发

1. 有属于自己的事件处理机制
2. 可以搞效率的开发基于窗口的应用程序。
3. Qt是标准 C++ 的扩展, C++的语法在Qt中都是支持的
4. 良好封装机制使得 Qt 的模块化程度非常高，可重用性较好，可以快速上手。
5. Qt 提供了一种称为 signals/slots 的安全类型来替代 callback（回调函数），这使得各个元件 之间的协同工作变得十分简单.



### QT的特点

> 就是因为具有了这些优秀的特质才使得现在很多企业都首选Qt进行基于窗口的应用程序开发，并且近年来市场对Qt程序猿的需求也在不断攀升。

广泛用于开发GUI程序，也可用于开发非GUI程序。

---

GUI = Graphical User Interface
也就是基于窗口的应用程序开发。
有丰富的 API

---

Qt 包括多达 250 个以上的 C++ 类
可以处理正则表达式。
支持 2D/3D 图形渲染，支持 OpenGL
Qt给程序猿提供了非常详细的官方文档
支持XML，Json
框架底层模块化， 使用者可以根据需求选择相应的模块来使用

---

可以轻松跨平台
和Java的跨平台方式不同
在不同的平台使用的是相同的上层接口，但是在底层封装了不同平台对应的API（暗度陈仓）。





### QT种的模块

> Qt类库里大量的类根据功能分为各种模块，这些模块又分为以下几大类：

Qt 基本模块（Qt Essentials)：提供了 Qt 在所有平台上的基本功能。
Qt 附加模块（Qt Add-Ons)：实现一些特定功能的提供附加价值的模块。
增值模块（Value-AddModules)：单独发布的提供额外价值的模块或工具。
技术预览模块（Technology Preview Modules）：一些处于开发阶段，但是可以作为技术预览使用的模块。
Qt 工具（Qt Tools)：帮助应用程序开发的一些工具。

![image-20231130151944416](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130151944416.png) 



### QT案例

> Qt发展至今已经是一个非常成熟的框架，基于这个框架许多公司开发出了很多优秀的软件，下边给大家介绍几款我们常见到的软件：

VirtualBox：虚拟机软件。
VLC多媒体播放器：一个体积小巧、功能强大的开源媒体播放器。
YY语音：又名“歪歪语音”，是一个可以进行在线多人语音聊天和语音会议的免费软件。
咪咕音乐：咪咕音乐是中国移动倾力打造的正版音乐播放器
WPS Office：金山公司（Kingsoft）出品的办公软件，与微软Office兼容性良好，个人版免费。
Skype：一个使用人数众多的基于P2P的VOIP聊天软件。

## QT安装

Qt官方下载地址：https://download.qt.io/archive/qt/

![image-20231130152055946](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130152055946.png) 

镜像网站

中国科学技术大学：http://mirrors.ustc.edu.cn/qtproject/
清华大学：https://mirrors.tuna.tsinghua.edu.cn/qt/
北京理工大学：https://mirrors.bit.edu.cn/qtproject/
中国互联网络信息中心：https://mirrors.cnnic.cn/qt/

找到archive/目录下载离线安装包即可

[Qt安装教程_Loken2020的博客-CSDN博客](https://blog.csdn.net/u012117034/article/details/125619848?ops_request_misc=%7B%22request%5Fid%22%3A%22170132901516800215054534%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=170132901516800215054534&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-125619848-null-null.142^v96^control&utm_term=qt的安装&spm=1018.2226.3001.4187)





### 配置环境变量

> 当我们编写一个Qt程序，并且生成了可执行程序，这个可执行程序运行的时候默认需要加载相关的Qt动态库（因为默认是动态链接，静态链接则不需要）。为了保证可执行程序在任何目录执行都能链接到对应的动态库，我们可以将Qt模块对应的动态库目录设置到系统的环境变量中（这一点对于Linux系统也是一样的）。

![image-20231130152448766](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130152448766.png) 

![image-20231130152541671](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130152541671.png) 





## 第一个QT项目

### 创建项目

![image-20231130152725792](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130152725792.png) 

![image-20231130152742164](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130152742164.png) 

![image-20231130152747689](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130152747689.png) 

![image-20231130152752240](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130152752240.png) 





###  项目文件（.pro）

```c++
# 在项目文件中, 注释需要使用 井号(#)
# 项目编译的时候需要加载哪些底层模块
QT       += core gui 

# 如果当前Qt版本大于4, 会添加一个额外的模块: widgets
# Qt 5中对gui模块进行了拆分, 将 widgets 独立出来了
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
   
# 使用c++11新特性
CONFIG += c++11	

#如果在项目中调用了废弃的函数, 项目编译的时候会有警告的提示    
DEFINES += QT_DEPRECATED_WARNINGS

# 项目中的源文件
SOURCES += \
        main.cpp \
        mainwindow.cpp
        
# 项目中的头文件
HEADERS += \
        mainwindow.h
        
# 项目中的窗口界面文件
FORMS += \
        mainwindow.ui
```

> Qt项目文件（通常以.pro为扩展名），用于配置和构建Qt项目。一步步解释每个部分的含义：
>
> 1. QT += core gui：这一行指示项目==需要使用Qt的core和gui模块==。这意味着项目将使用Qt的基本功能和图形用户界面功能。
>
> 2. greaterThan(QT_MAJOR_VERSION, 4): QT += widgets：这一行表示如果==Qt的主要版本号大于4，则添加widgets模块==。这意味着如果使用的是Qt 5或更高版本，将添加Qt的widgets模块，用于构建窗口小部件应用程序。
>
> 3. CONFIG += c++17：这一行指示项目使用C++17标准进行编译。
>
> 4. DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000：这一行是注释掉的，如果取消注释，将会使代码在使用已弃用的API时编译失败。这可以帮助开发人员在使用不推荐的API时及时发现问题。
>
> 5. SOURCES += \ main.cpp \ mainwindow.cpp：这一行列出了项目的源文件，包括main.cpp和mainwindow.cpp。这些是项目的主要代码文件。
>
> 6. HEADERS += \ mainwindow.h：这一行列出了项目的头文件，包括mainwindow.h。这些文件包含了项目中使用的类和函数的声明。
>
> 7. FORMS += \ mainwindow.ui：这一行列出了项目的UI文件，包括mainwindow.ui。这些文件是Qt Designer创建的用户界面文件，用于定义应用程序的界面布局和元素。
>
> 8. qnx: target.path = /tmp/$${TARGET}/bin else: unix:!android: target.path = /opt/$${TARGET}/bin !isEmpty(target.path): INSTALLS += target：这一部分是默认的部署规则，用于指定项目的部署路径。根据不同的操作系统和平台，部署路径会有所不同。
>
> 总之，Qt的项目文件用于配置项目的构建和部署规则，包括指定需要使用的Qt模块、编译标准、源文件、头文件、UI文件以及部署路径等信息。通过编辑项目文件，开发人员可以灵活地配置项目的构建和部署过程。

### main.cpp

```c++
#include "mainwindow.h"		// 生成的窗口类头文件
#include <QApplication>		// 应用程序类头文件

int main(int argc, char *argv[])
{
    // 创建应用程序对象, 在一个Qt项目中实例对象有且仅有一个
    // 类的作用: 检测触发的事件, 进行事件循环并处理
    QApplication a(argc, argv);
    // 创建窗口类对象
    MainWindow w;
    // 显示窗口
    w.show();
    // 应用程序对象开始事件循环, 保证应用程序不退出
    return a.exec();
}


```

> 典型的Qt应用程序的入口点，它包括了主函数和一些Qt类的使用。一步步来解释每一部分的含义：
>
> 1. #include "mainwindow.h"：这一行包含了mainwindow.h头文件，这是一个==生成的窗口类的头文件==。在Qt中，通常会创建一个窗口类来定义应用程序的主窗口。
>
> 2. #include <QApplication>：这一行包含了QApplication文件，这是Qt中的**应用程序类文件**。QApplication类==负责管理应用程序的事件循环和处理。==
>
> 3. int main(int argc, char *argv[])：这是==主函数的定义，它是程序的入口点==。argc是命令行参数的数量，argv是命令行参数的数组。
>
> 4. QApplication a(argc, argv)：这一行==创建了一个QApplication对象a==，它是整个应用程序的核心。这个对象负责处理应用程序的事件循环，接收并处理用户输入。
>
> 5. MainWindow w：这一行==创建了一个MainWindow对象w，这是应用程序的主窗口类的实例化对象==。
>
> 6. w.show()：这一行调用了MainWindow对象的show()方法，用于显示主窗口。
>
> 7. return a.exec()：这一行==启动了应用程序的事件循环，保证应用程序不会立即退出==。a.exec()会一直运行，直到应用程序被关闭。
>
> 总之，这段代码初始化了一个Qt应用程序，并创建了一个主窗口对象并显示出来，然后启动了应用程序的事件循环。这样，当用户与应用程序交互时，Qt会处理用户的输入并触发相应的事件处理。



### mainwindow.ui

> 在Qt中每一个窗口都对应一个可编辑的可视化界面（*.ui）, 这个界面对应的是一个xml格式的文件, 一般情况下不需要在xml格式下对这个文件进行编辑, 关于这个文件结构了解即可。

```c++
<!-- 双击这个文件看到的是一个窗口界面, 如果使用文本编辑器打开看到的是一个XML格式的文件 -->
<!-- 看不懂这种格式没关系, 我们不需要在这种模式下操作这个文件。 -->
<!-- 这里只是给大家介绍这个文件的本质 -->
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>MainWindow</class>
 <widget class="QMainWindow" name="MainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>800</width>
    <height>600</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>MainWindow</string>
  </property>
  <widget class="QWidget" name="centralwidget"/>
  <widget class="QMenuBar" name="menubar"/>
  <widget class="QStatusBar" name="statusbar"/>
 </widget>
 <resources/>
 <connections/>
</ui>

```

### mainwindow.h

```c++
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>		// Qt标准窗口类头文件

QT_BEGIN_NAMESPACE
// mainwindow.ui 文件中也有一个类叫 MainWindow, 将这个类放到命名空间 Ui 中
namespace Ui { class MainWindow; }	
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT	// 这个宏是为了能够使用Qt中的信号槽机制

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;		// 定义指针指向窗口的 UI 对象
};
#endif // MAINWINDOW_H

```





### mainwindow.cpp

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"
//构造函数的实例化

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)	// 基于mainwindow.ui创建一个实例对象
{
    // 将 mainwindow.ui 的实例对象和 当前类的对象进行关联
    // 这样同名的连个类对象就产生了关联, 合二为一了
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
```



## Qt中的窗口类

> 在通过Qt向导窗口基于窗口的应用程序的项目过程中倒数第二步让我们选择跟随项目创建的第一个窗口的基类, 下拉菜单中有三个选项, 分别为: QMainWindow、QDialog、QWidget如下图：

![image-20231130153732879](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130153732879.png) 

![image-20231130153740272](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130153740272.png) 





### 窗口的显示

![image-20231130153822059](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130153822059.png) 

```c++
// QWidget是所有窗口类的基类, 调用这个提供的 show() 方法就可以显示将任何窗口显示出来
// 非模态显示
void QWidget::show();	// 显示当前窗口和它的子窗口

// 对话框窗口的非模态显示: 还是调用show() 方法
// 对话框窗口的模态显示
[virtual slot] int QDialog::exec();
```





## 坐标体系

### 窗口的坐标原点

> 所有坐标的确定都需要先找到坐标原点, Qt的坐标原点在窗口的左上角

![image-20231130153922176](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130153922176.png) 



### 窗口的相对坐标

> 在一个Qt窗口中一般都有很多子窗口内嵌到这个父窗口中，其中每个窗口都有自己的坐标原点
>
> 子窗口的位置也就是其使用的坐标点就是它的父窗口坐标体系中的坐标点。

![image-20231130153956352](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130153956352.png)

```c++
// 所有窗口类的基类: QWidget
// QWidget中提供了移动窗口的 API函数
// 参数 x, y是要移动的窗口的左上角的点, 窗口的左上角移动到这个坐标点
void QWidget::move(int x, int y);
void QWidget::move(const QPoint &);
```

==所有窗口类的基类: QWidget==



## 内存回收

> 在Qt中**创建对象**的时候会提供一个 **Parent对象指针**（可以查看类的构造函数），下面来解释这个parent到底是干什么的。
>
> ==QObject是以对象树的形式组织起来的==。当你创建一个QObject对象时，会看到QObject的构造函数接收一个QObject指针作为参数，这个参数就是 parent，也就是父对象指针。
>
> <img src="C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130154209840.png" alt="image-20231130154209840" style="zoom: 50%;" /> 
>
> 这相当于，在==创建QObject对象时，可以提供一个其父对象==，我们创建的这个QObject对象会自动添加到其父对象的children()列表。==当父对象析构的时候，这个列表中的所有对象也会被析构。==（注意，这里的父对象并不是继承意义上的父类！）
>
> ==QWidget是能够在屏幕上显示的一切组件的父类==。QWidget继承自QObject，因此也继承了这种对象树关系。
>
> ==**一个孩子自动地成为父组件的一个子组件**。因此，**它会显示在父组件的坐标系统中**，被父组件的边界剪裁。==
>
> 例如，当用户关闭一个对话框的时候，应用程序将其删除，那么，我们希望属于这个对话框的按钮、图标等应该一起被删除。事实就是如此，因为这些都是对话框的子组件。
>
> Qt 引入对象树的概念，在一定程度上解决了内存问题。
>
> ==当一个QObject对象在**堆**上创建的时候，Qt 会同时为其创建一个**对象树**。==
>
> 不过，==**对象树中对象的顺序是没有定义的**==。这意味着，销毁这些对象的顺序也是未定义的。
>
> ---
>
> 任何对象树中的 QObject对象 delete 的时候，如果这个对象有 parent，则自动将其从 parent 的children()列表中删除；
>
> ==如果有孩子，则自动 delete 每一个孩子。Qt 保证没有QObject会被 delete 两次，这是由析构顺序决定的。==

<img src="C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130154513512.png" alt="image-20231130154513512" style="zoom: 67%;" /> 

![image-20231130154626074](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231130154626074.png)

1. 方式1: 通过构造函数
   parent: 当前窗口的父对象, 找构造函数中的 parent 参数即可

   ```c++
   QWidget::QWidget(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
   QTimer::QTimer(QObject *parent = nullptr);
   ```

2.  方式2: 通过setParent()方法
   假设这个控件没有在构造的时候指定符对象, 可以调用QWidget的api指定父窗口对象

   ```c++
   void QWidget::setParent(QWidget *parent);
   void QObject::setParent(QObject *parent);
   ```

   

