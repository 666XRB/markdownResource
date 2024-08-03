# Qt中按钮类型的控件

包括: `QAbstractButton`, `QPushButton`, `QToolButton`, `QRadioButton`, `QCheckBox`

# 按钮基类 QAbstractButton

> 在QT中为我们提供了可以直接使用的按钮控件, 如下图。这些按钮种类虽然繁多， 但是**它们都拥有相同的父类** `QAbstractButton`。**这些子类按钮的大部分属性都是从这个基类继承的**，因此搞明白这个类为我们提供的相关功能还是非常重要的。
> 其中`Dialog Button Box`**比较特殊不是一个单一控件, 它是两个`QPushButton`的组合并且水平排列**, 这个不能作为一个新控件来研究。

![image-20231206215553984](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231206215553984.png)

关系图

![image-20231206215606034](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231206215606034.png) 

## `QAbstractButton`中的一些常用API



##  标题和图标 

```c++
// 参数text的内容显示到按钮上
void QAbstractButton::setText(const QString &text);
// 得到按钮上显示的文本内容, 函数的返回就是
QString QAbstractButton::text() const;

// 得到按钮设置的图标
QIcon icon() const;
// 给按钮设置图标
void setIcon(const QIcon &icon);

// 得到按钮图标大小
QSize iconSize() const
// 设置按钮图标的大小
[slot]void setIconSize(const QSize &size);
```

实践代码

```
    QPushButton *btn1=new QPushButton(this);
    btn1->setText("牛啊吗按钮");
    QIcon icon(":/D:/icon/img.png");
    btn1->setIcon(icon);
    qDebug()<<"按钮的icon信息为"<<btn1->icon()<<"\n"<<btn1->iconSize();
                    btn1->setIconSize(QSize(50,50));
```

实践效果

![image-20231206220302283](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231206220302283.png) 

## 按钮的 `Check` 属性 

> 对应按钮来说, 一般有三种常见状态, 分别为: `Normal`, `Hover`, `Pressed`。
>
> - `Normal`: 普通状态, 没有和鼠标做任何接触
> - `Hover`: 悬停状态, 鼠标位于按钮之上, 但是并未按下
> - `Pressed`: 按压状态, 鼠标键在按钮上处于按下状态
>
> **默认情况下, 鼠标在按钮上按下, 按钮从 `Normal` 切换到 `Pressed`状态, 鼠标释放, 按钮从 `Pressed`恢复到`Normal`状态。**
> 当我们给按钮设置了 `check` 属性之后，情况就有所不同了， 在按钮上释放鼠标键， 按钮依然会处在 `Pressed`状态, 再次点击按钮, 按钮才能恢复到 `Normal` 状态。**具有`check`属性的按钮就相当于一个开关, 每点击一次才能实现一次状态的切换**。

代码和实现效果

![image-20231206223234362](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231206223234362.png) 

## 信号

> 这些信号**都按钮被点击之后发射出来**的, 只是在细节上有细微的区别, **其中最常用的是 `clicked()`**, 通过鼠标的**不同瞬间状态可以发射出`pressed()` 和 `released()` 信号**,
>
> **如果鼠标设置了 `check`属性, 一般通过 `toggled()`信号判断当前按钮是选中状态还是非选中状态。**
>
> //选中/不选中这两个状态发生改变的时候就会发出toggled信号
> [signal] void QAbstractButton::toggled(bool checked);

```c++
/*
当按钮被激活时(即，当鼠标光标在按钮内时按下然后释放)，当键入快捷键时，或者当click()或animateClick()被调用时，这个信号被发出。值得注意的是，如果调用setDown()、setChecked()或toggle()，则不会触发此信号。
*/
[signal] void QAbstractButton::clicked(bool checked = false);
// 在按下按钮的时候发射这个信号
[signal] void QAbstractButton::pressed();
// 在释放这个按钮的时候发射直观信号
[signal] void QAbstractButton::released();
// 每当可检查按钮改变其状态时，就会发出此信号。checked在选中按钮时为true，在未选中按钮时为false。
//选中/不选中这两个状态发生改变的时候就会发出toggled信号
[signal] void QAbstractButton::toggled(bool checked);
```

代码&实现

```c++
    QPushButton *btn1=new QPushButton(this);
    btn1->setText("普通按钮");
    QPushButton *btn2=new QPushButton(this);
    btn2->move(100,0);
    btn2->setText("可选择按钮");

    connect(btn1,&QPushButton::clicked,this,[=](){
        qDebug()<<"a按钮被点击了！";
    });

    connect(btn1,&QPushButton::pressed,this,[=](){
        qDebug()<<"a按钮被按压了！";
    });
    connect(btn1,&QPushButton::released,this,[=](){
        qDebug()<<"a按钮被释放了！";
    });
    connect(btn1,&QPushButton::toggled,this,[=](){
        qDebug()<<"a按钮被toggled了！";
    });

    btn2->setCheckable(true);
    connect(btn2,&QPushButton::clicked,this,[=](){
        qDebug()<<"可选择按钮被点击了！";
    });

    connect(btn2,&QPushButton::pressed,this,[=](){
        qDebug()<<"可选择按钮被按压了！";
    });
    connect(btn2,&QPushButton::released,this,[=](){
        qDebug()<<"可选择按钮被释放了！";
    });
    connect(btn2,&QPushButton::toggled,this,[=](){
        qDebug()<<"可选择按钮被toggled了！";
    });
```



## 槽函数

```c++
// 执行一个动画点击:按钮被立即按下，并在毫秒后释放(默认是100毫秒)。
[slot] void QAbstractButton::animateClick(int msec = 100);
// 执行一次按钮点击, 相当于使用鼠标点击了按钮
[slot] void QAbstractButton::click();

// 参考 1.2 中的函数介绍
[slot] void QAbstractButton::setChecked(bool);
// 设置按钮上图标大小
[slot]void setIconSize(const QSize &size);
// 切换可检查按钮的状态。 checked <==> unchecked
[slot] void QAbstractButton::toggle();
```

> 这些槽函数是 Qt 框架中的 QAbstractButton 类提供的一些用于处理按钮点击和状态切换的函数。下面是对每个槽函数的详细解释：
>
> 1. `void QAbstractButton::animateClick(int msec = 100);`
>    - 功能：模拟一个按钮点击的动画效果，按钮会立即按下并在指定的时间后释放。
>    - 参数：msec（可选）- 动画持续的时间，以毫秒为单位，默认是100毫秒。
>
> 2. `void QAbstractButton::click();`
>    - 功能：执行一次按钮点击操作，相当于使用鼠标点击了按钮。
>    - 参数：无。
>
> 3. `void QAbstractButton::setChecked(bool);`
>    - 功能：设置按钮的选中状态。
>    - 参数：bool - true 表示选中按钮，false 表示取消选中按钮。
>
> 4. `void setIconSize(const QSize &size);`
>    - 功能：设置按钮上图标的大小。
>    - 参数：size - 图标的尺寸，以 QSize 类型表示。
>
> 5. `void QAbstractButton::toggle();`
>    - 功能：切换**可检查按钮的状态，从选中到取消选中，或从取消选中到选中**。
>    - 参数：无。
>    
>    槽函数可以直接调用
>

了解了基类提供的功能之后, 下边着重给大家介绍一下按钮组中常用的几这个按钮控件： `QPushButton`, `QToolButton`, `QRadioButton`, `QCheckBox`。

# QPushButton

## 常用API

> 这种类型的按钮是Qt按钮中使用频率最高的一个, 对这个类进行操作, 大部分时候都需要使用它从父类继承过来的那些 API。
> 在`QPushButton`类中, 比较常用的一些API函数如下:

```c++
// 构造函数
/*
参数:
    - icon: 按钮上显示的图标
    - text: 按钮上显示的标题
    - parent: 按钮的父对象, 可以不指定
*/
QPushButton::QPushButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr);
QPushButton::QPushButton(const QString &text, QWidget *parent = nullptr);
QPushButton::QPushButton(QWidget *parent = nullptr);

// 判断按钮是不是默认按钮
bool isDefault() const;
// 一般在对话框窗口中使用, 将按钮设置为默认按钮, 自动关联 Enter 键 
void setDefault(bool);

/*
将弹出菜单菜单与此按钮关联起来。这将把按钮变成一个菜单按钮，
在某些样式中会在按钮文本的右边产生一个小三角形。
*/
void QPushButton::setMenu(QMenu *menu);

/*
显示(弹出)相关的弹出菜单。如果没有这样的菜单，这个函数什么也不做。
这个函数直到弹出菜单被用户关闭后才返回。
*/
[slot] void QPushButton::showMenu();
```

> ///////////////////////////// 槽函数 /////////////////////////////QPushButton 是 Qt 中常用的按钮类，它继承自 QAbstractButton，因此包含了 QAbstractButton 的槽函数，并且还额外提供了一些自己的槽函数。下面是 QPushButton 的一些常用槽函数：
>
> 1. `void QPushButton::clicked(bool checked = false);`
>    - 功能：当按钮被点击时触发的信号，通常用于响应按钮的点击操作。
>    - 参数：checked（可选）- 指示按钮是否处于选中状态。
>
> 2. `void QPushButton::pressed();`
>    - 功能：当按钮被按下时触发的信号。
>
> 3. `void QPushButton::released();`
>    - 功能：当按钮被释放时触发的信号。
>
> 4. `void QPushButton::toggled(bool checked);`
>    - 功能：当按钮的选中状态发生切换时触发的信号。
>    - 参数：checked - 指示按钮是否处于选中状态。
>

## 按钮的使用 

> 通过API的介绍, 我们可以知道, 使用`QToolButton`这种类型的按钮, 有三种使用方式:
>
> 1. `作为普通按钮, 可以显示文本信息和图标`
> 2. `按钮的图标可以使用不同的方式设置, 并且制定图标和文本信息的显示模式`
> 3. `设置check属性, 使其可以处于持续的被选中状态`
> 4. `关联一个菜单, 点击按钮菜单弹出, 并且可以设置菜单的弹出方式`
>
> 具体操作可以参考如下代码:

![PixPin_2023-12-06_22-50-04](D:/pixpinGif/PixPin_2023-12-06_22-50-04.gif)





# QToolButton

## 常用API

> 这个类也是一个常用按钮类, 使用方法和功能跟`QPushButton`基本一致, 只不过在对于关联菜单这个功能点上, `QToolButton`类可以设置弹出的菜单的属性, 以及在显示图标的时候可以设置更多的样式, 可以理解为是一个增强版的`QPushButton`。
> 和`QPushButton`类相同的是, 操作这个按钮使用的大部分函数都是从父类`QAbstractButton`继承过来的。

> ```c++
> ///////////////////////////// 构造函数 /////////////////////////////
> QToolButton::QToolButton(QWidget *parent = nullptr);
> 
> /////////////////////////// 公共成员函数 ///////////////////////////
> /*
>     1. 将给定的菜单与此工具按钮相关联。
>     2. 菜单将根据按钮的弹出模式显示。
>     3. 菜单的所有权没有转移到“工具”按钮(不能建立父子关系)
> */
> void QToolButton::setMenu(QMenu *menu);
> // 返回关联的菜单，如果没有定义菜单，则返回nullptr。
> QMenu *QToolButton::menu() const;
> 
> /*
> 弹出菜单的弹出模式是一个枚举类型: QToolButton::ToolButtonPopupMode, 取值如下:
>     - QToolButton::DelayedPopup: 
>         - 延时弹出, 按压工具按钮一段时间后才能弹出, 比如:浏览器的返回按钮
>         - 长按按钮菜单弹出, 但是按钮的 clicked 信号不会被发射
>     - QToolButton::MenuButtonPopup: 
>         - 在这种模式下，工具按钮会显示一个特殊的箭头，表示有菜单。
> 	- 当按下按钮的箭头部分时，将显示菜单。按下按钮部分发射 clicked 信号
>     - QToolButton::InstantPopup: 
>         - 当按下工具按钮时，菜单立即显示出来。
>         - 在这种模式下，按钮本身的动作不会被触发(不会发射clicked信号
> */
> // 设置弹出菜单的弹出方式
> void setPopupMode(QToolButton::ToolButtonPopupMode mode);
> // 获取弹出菜单的弹出方式
> QToolButton::ToolButtonPopupMode popupMode() const;
> 
> /*
> QToolButton可以帮助我们在按钮上绘制箭头图标, 是一个枚举类型, 取值如下: 
>     - Qt::NoArrow: 没有箭头
>     - Qt::UpArrow: 箭头向上
>     - Qt::DownArrow: 箭头向下
>     - Qt::LeftArrow: 箭头向左
>     - Qt::RightArrow: 箭头向右
> */
> // 显示一个箭头作为QToolButton的图标。默认情况下，这个属性被设置为Qt::NoArrow。
> void setArrowType(Qt::ArrowType type);
> // 获取工具按钮上显示的箭头图标样式
> Qt::ArrowType arrowType() const;
> 
> ///////////////////////////// 槽函数 /////////////////////////////
> QToolButton 是 Qt 中的工具按钮类，它继承自 QPushButton，并且还额外提供了一些自己的槽函数。下面是 QToolButton 的一些常用槽函数：
> 
> 1. `void QToolButton::triggered(QAction *action);`
>    - 功能：当工具按钮中的动作被触发时触发的信号。
>    - 参数：action - 被触发的动作对象。
> 
> 2. `void QToolButton::pressed();`
>    - 功能：当工具按钮被按下时触发的信号。
> 
> 3. `void QToolButton::released();`
>    - 功能：当工具按钮被释放时触发的信号。
> 
> 4. `void QToolButton::toggled(bool checked);`
>    - 功能：当工具按钮的选中状态发生切换时触发的信号。
>    - 参数：checked - 指示按钮是否处于选中状态。
> 
> 这些槽函数为 QToolButton 提供了响应工具按钮的点击、按下、释放等操作的信号，可以在程序中连接这些信号并编写相应的槽函数来实现特定的功能。另外，QToolButton 还可以通过 setMenu() 方法设置一个菜单，可以使用 triggered() 信号来响应菜单项的触发。
> ```

##  按钮的使用

> 通过API的介绍, 我们可以知道, 使用`QToolButton`这种类型的按钮, 有三种使用方式:
>
> 1. `作为普通按钮, 可以显示文本信息和图标`
> 2. `按钮的图标可以使用不同的方式设置, 并且制定图标和文本信息的显示模式`
> 3. `设置check属性, 使其可以处于持续的被选中状态`
> 4. `关联一个菜单, 点击按钮菜单弹出, 并且可以设置菜单的弹出方式`
>
> 具体操作可以参考如下代码:

> QToolButton::DelayedPopup（值为0）：按住工具按钮一段时间后（超时时间由样式决定，参见 QStyle::SH_ToolButton_PopupDelay），菜单会显示出来。一个典型的应用示例是一些网页浏览器工具栏中的“返回”按钮。如果用户单击它，浏览器会简单地返回到上一页。如果用户长按按钮一段时间，工具按钮将显示一个包含当前历史记录列表的菜单。
>
> QToolButton::MenuButtonPopup（值为1）：在这种模式下，工具按钮显示一个特殊的箭头，表示存在菜单。当点击按钮上的箭头部分时，菜单会显示出来。
>
> QToolButton::InstantPopup（值为2）：当按下工具按钮时立即显示菜单，不延迟。在这种模式下，按钮自身的动作不会被触发。
>
> 以上三个常量描述了 QToolButton 的下拉菜单的不同显示方式：
>
> - 如果希望用户长按按钮后才显示菜单，可以使用 DelayedPopup。
> - 如果希望在按钮上明确显示有菜单的箭头，点击箭头部分显示菜单，可以使用 MenuButtonPopup。
> - 如果希望按钮被点击后立即显示菜单，可以使用 InstantPopup。
>
> 根据需求选择合适的常量来设置 QToolButton 的下拉菜单的显示方式。

![tool](D:/pixpinGif/tool.gif)![image-20231206230918990](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231206230918990.png) 

![tooldekay](D:/pixpinGif/tooldekay.gif) 

**对于下拉列表如何捕捉信号呢？**

![menuaction](D:/pixpinGif/menuaction.gif) 





# QRADiobutton

> QRadioButton`是Qt提供的单选按钮, 一般都是以组的方式来使用(`多个按钮中同时只能选中其中一个`)。操作这个按钮使用的大部分函数都是从父类继承过来的, 它的父类是`QAbstractButton`。
> 关于单选按钮的使用我们还需要注意一点, `**如果单选按钮被选中, 再次点击这个按钮选中状态是不能被取消的。**

## 常用API

> 这个类混的很失败, 一直生活在父类的阴影之下, 也没有什么作为, 在官方的帮助文档中, 处理构造函数就没有再提供其他可用的 API了

```c++
// 构造函数
/*
参数:
    - text: 按钮上显示的标题
    - parent: 按钮的父对象
*/
QRadioButton::QRadioButton(const QString &text, QWidget *parent = nullptr);
QRadioButton::QRadioButton(QWidget *parent = nullptr);
```

## 按钮的使用

> 单选按钮一般是以组的形式来使用的, 如果在一个窗口中需要有多个单选按钮组, 应该如何处理呢?
> `在同一窗口中, Qt会认为所有的单选按钮都属于同一组, 如果需要多个单选按钮组, 应该将他们放到不同的子窗口中。`

![image-20231207152355064](Qt%E4%B8%AD%E6%8C%89%E9%92%AE%E7%B1%BB%E5%9E%8B%E7%9A%84%E6%8E%A7%E4%BB%B6/image-20231207152355064.png) 

> 通过上图可以看到有两个单选按钮组, 在制作的时候分别将单选按钮放到了不同的容器窗口（组框）中，这样就被人为分隔为两组了。

![image-20231207152439330](Qt%E4%B8%AD%E6%8C%89%E9%92%AE%E7%B1%BB%E5%9E%8B%E7%9A%84%E6%8E%A7%E4%BB%B6/image-20231207152439330.png) 

如果我们使用鼠标点击了某个单选按钮, 按钮还是会发射出 `clicked()`信号, 简单的按钮测试代码如下所示:

```
void MainWindow::on_radioButton_clicked()
{
    QMessageBox::information(this,"警告","没有妹子");
}

connect(ui->radioButton_2,&QAbstractButton::clicked,this,[=](){
QMessageBox::information(this,"警告","没有妹子");
});
```

![qradio](Qt%E4%B8%AD%E6%8C%89%E9%92%AE%E7%B1%BB%E5%9E%8B%E7%9A%84%E6%8E%A7%E4%BB%B6/qradio.gif)

# QCheckBox

> QCheckBox是Qt中的复选框按钮, 可以单独使用, 也可以以组的方式使用(同一组可以同时选中多个), `当复选按钮被选中, 再次点击之后可以取消选中状态, 这一点和单选按钮是不同的。`
> 操作这个按钮使用的大部分函数都是从父类继承过来的, 它的父类是`QAbstractButton`。

##  常用API

> 我们对复选框按钮操作的时候, **可以设置选中和未选中状态, 并且还可以设置半选中状态**,
>
> 这种半选中状态**一般需要当前复选框按钮下还有子节点**, 类似一树状结构。

```c++

// 构造函数
/*
参数:
    - text: 按钮上显示的文本信息
    - parent: 按钮的父对象
*/
QCheckBox::QCheckBox(const QString &text, QWidget *parent = nullptr);
QCheckBox::QCheckBox(QWidget *parent = nullptr);

// 判断当前复选框是否为三态复选框, 默认情况下为两种状态: 未选中, 选中
bool isTristate() const;
// 设置当前复选框为三态复选框: 未选中, 选中, 半选中
void setTristate(bool y = true);

/*
参数 state, 枚举类型 Qt::CheckState:
    - Qt::Unchecked	      --> 当前复选框没有被选中
    - Qt::PartiallyChecked    --> 当前复选框处于半选中状态, 部分被选中(三态复选框)
    - Qt::Checked	      --> 当前复选框处于选中状态
*/
// 设置复选框按钮的状态
void QCheckBox::setCheckState(Qt::CheckState state);
// 获取当前复选框的状态
Qt::CheckState QCheckBox::checkState() const;
```

信号

```c++
// 当复选框的状态改变时，即当用户选中或取消选中复选框时，他的信号就会发出。
// 参数 state 表示的是复选框的三种状态中某一种, 可参考 Qt::CheckState
[signal] void QCheckBox::stateChanged(int state);
```

## 按钮的使用 

> 下面针对于复选框按钮的三种状态, 为大家展示一下对应的操作流程, 首先第一步搭建一个有树状关系的界面:

![复选框gif](Qt%E4%B8%AD%E6%8C%89%E9%92%AE%E7%B1%BB%E5%9E%8B%E7%9A%84%E6%8E%A7%E4%BB%B6/%E5%A4%8D%E9%80%89%E6%A1%86gif.gif)

代码实现

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextEdit>
#include <qgridlayout.h>
#include <qpushbutton.h>
#include <QMessageBox>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QMenu>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->father->setTristate(true);
    connect(ui->father, &QCheckBox::clicked, this, [=](bool bl)
    {
        if(bl)
        {
            // 子节点全部设置为选中状态
            ui->son1->setChecked(true);
            ui->son2->setChecked(true);
            ui->son3->setChecked(true);
            ui->son4->setChecked(true);
            ui->son5->setChecked(true);

        }
        else
        {
            // 子节点全部设置为非选中状态
            ui->son1->setChecked(false);
            ui->son2->setChecked(false);
            ui->son3->setChecked(false);
            ui->son4->setChecked(false);
            ui->son5->setChecked(false);
        }
    });

    //     Qt::CheckState checkState() const

    connect(ui->son1,&QCheckBox::stateChanged,this,&MainWindow::statusChanged);
    connect(ui->son2,&QCheckBox::stateChanged,this,&MainWindow::statusChanged);
    connect(ui->son3,&QCheckBox::stateChanged,this,&MainWindow::statusChanged);
    connect(ui->son4,&QCheckBox::stateChanged,this,&MainWindow::statusChanged);
    connect(ui->son5,&QCheckBox::stateChanged,this,&MainWindow::statusChanged);


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::statusChanged(int state)
{
    if(state==Qt::Checked)
    {
        this->m_number++;
    }
    else
    {
        this->m_number--;
    }

    if(this->m_number==5)
    {
        ui->father->setCheckState(Qt::Checked);
    }
    else if(this->m_number==0)
    {
        ui->father->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->father->setCheckState(Qt::PartiallyChecked);
    }

}

```

![image-20231207163458286](Qt%E4%B8%AD%E6%8C%89%E9%92%AE%E7%B1%BB%E5%9E%8B%E7%9A%84%E6%8E%A7%E4%BB%B6/image-20231207163458286.png) 

UI实现

![image-20231207163644000](Qt%E4%B8%AD%E6%8C%89%E9%92%AE%E7%B1%BB%E5%9E%8B%E7%9A%84%E6%8E%A7%E4%BB%B6/image-20231207163644000.png) 





信号解释

![image-20231207163324327](Qt%E4%B8%AD%E6%8C%89%E9%92%AE%E7%B1%BB%E5%9E%8B%E7%9A%84%E6%8E%A7%E4%BB%B6/image-20231207163324327.png) 

连接操作中使用的关键是`&QCheckBox::checkState`和`this`，它们指定了信号和槽的具体函数。`&QCheckBox::checkState`表示连接`QCheckBox`的`checkState`信号，而`this`表示连接当前对象（即`MainWindow`）的`statusChanged`槽函数。

当连接建立后，当`ui->son1`的`checkState`信号发出时，会调用`MainWindow`的`statusChanged`槽函数，并将`Qt::CheckState`类型的参数传递给该槽函数。因此，槽函数`MainWindow::statusChanged`中的`int state`参数就会接收到`Qt::CheckState`类型的参数，并可以根据其值进行相应的处理。