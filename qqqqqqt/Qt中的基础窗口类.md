# Qt中的基础窗口类

Qt中常用的窗口类:

> 窗口类的基类QWidget
>
>  对话框基类QDialog
>
>  带菜单栏工具栏状态栏的QMainWindow
>
> ,消息对话框QMessageBox
>
> 文件对话框QFileDialog,
>
> 字体对话框QFontDialog
>
>  颜色对话框QColorDialog,
>
> 输入型对话框QInputDialog
>
> 进度条对话框QProgressDialog,
>
> 资源文件





## QWidget

> ==QWidget类是所有窗口类的父类(控件类是也属于窗口类),==
>
>  并且==**QWidget类的父类的QObject**==, 也就意味着**所有的窗口类对象只要指定了父对象, 都可以实现内存资源的自动回收**。
>
> 常用的一些API函数。
> 关于这个窗口类的属性介绍, 请参考容器控件之QWidget。

![image-20231201190858977](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231201190858977.png) 





### 设置父对象

> 1. 在构造的时候就指定父亲
> 2. 单独setparents指定父亲
> 3. parentWidget()返回它的父亲

```c++
// 构造函数
QWidget::QWidget(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

// 公共成员函数
// 给当前窗口设置父对象
void QWidget::setParent(QWidget *parent);
void QWidget::setParent(QWidget *parent, Qt::WindowFlags f);
// 获取当前窗口的父对象, 没有父对象返回 nullptr
QWidget *QWidget::parentWidget() const;
```

![image-20231201191049438](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231201191049438.png)  



### 窗口位置

```c++
//------------- 窗口位置 -------------
// 得到相对于当前窗口父窗口的几何信息, 边框也被计算在内
QRect QWidget::frameGeometry() const;

// 得到相对于当前窗口父窗口的几何信息, 不包括边框
const QRect &geometry() const;
// 设置当前窗口的几何信息(位置和尺寸信息), 不包括边框
//左上角坐标，宽，高
void setGeometry(int x, int y, int w, int h);
void setGeometry(const QRect &);
    
// 移动窗口, 重新设置窗口的位置
void move(int x, int y);
void move(const QPoint &);
```

![image-20231201191734142](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231201191734142.png) 

窗口的坐上点就是代表窗口的点

#### 测试

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QTimer>
#include <QDebug>
#include <QTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(static_cast<unsigned int>(time(0)));
    ui->setupUi(this);
    this->setGeometry(0,0,500,500);
    this->setGeometry(QRect(0,0,600,600));
    qDebug()<<this->frameGeometry();//包括边框
    qDebug()<<this->geometry();//不包括边框
    this->move(300,300);
    on_positionBtn_clicked();
    on_geometryBtn_clicked();
    on_moveBtn_clicked();



}

MainWindow::~MainWindow()
{
    delete ui;
}


// 获取当前窗口的位置信息
void MainWindow::on_positionBtn_clicked()
{
    QRect rect = this->frameGeometry();
    qDebug() << "左上角: " << rect.topLeft()
             << "右上角: " << rect.topRight()
             << "左下角: " << rect.bottomLeft()
             << "右下角: " << rect.bottomRight()
             << "宽度: " << rect.width()
             << "高度: " << rect.height();
}

// 重新设置当前窗口的位置以及宽度, 高度
void MainWindow::on_geometryBtn_clicked()
{
    int x = 100 + rand() % 500;
    int y = 100 + rand() % 500;
    int width = this->width() + 10;
    int height = this->height() + 10;
    setGeometry(x, y, width, height);
}

// 通过 move() 方法移动窗口
void MainWindow::on_moveBtn_clicked()
{
    QRect rect = this->frameGeometry();
    move(rect.topLeft() + QPoint(10, 20));
}


```



### 窗口尺寸



```c++
//------------- 窗口尺寸 -------------
// 获取当前窗口的尺寸信息
QSize size() const
// 重新设置窗口的尺寸信息
void resize(int w, int h);
void resize(const QSize &);
// 获取当前窗口的最大尺寸信息
QSize maximumSize() const;
// 获取当前窗口的最小尺寸信息
QSize minimumSize() const;
// 设置当前窗口固定的尺寸信息
void QWidget::setFixedSize(const QSize &s);
void QWidget::setFixedSize(int w, int h);
// 设置当前窗口的最大尺寸信息
void setMaximumSize(const QSize &);
void setMaximumSize(int maxw, int maxh);
// 设置当前窗口的最小尺寸信息
void setMinimumSize(const QSize &);
void setMinimumSize(int minw, int minh);


// 获取当前窗口的高度    
int height() const;
// 获取当前窗口的最小高度
int minimumHeight() const;
// 获取当前窗口的最大高度
int maximumHeight() const;
// 给窗口设置固定的高度
void QWidget::setFixedHeight(int h);
// 给窗口设置最大高度
void setMaximumHeight(int maxh);
// 给窗口设置最小高度
void setMinimumHeight(int minh);

// 获取当前窗口的宽度
int width() const;
// 获取当前窗口的最小宽度
int minimumWidth() const;
// 获取当前窗口的最大宽度
int maximumWidth() const;
// 给窗口设置固定宽度
void QWidget::setFixedWidth(int w);
// 给窗口设置最大宽度
void setMaximumWidth(int maxw);
// 给窗口设置最小宽度
void setMinimumWidth(int minw);

```



### 窗口标题和图标

```c++
//------------- 窗口图标 -------------
// 得到当前窗口的图标
QIcon windowIcon() const;
// 构造图标对象, 参数为图片的路径
QIcon::QIcon(const QString &fileName);
// 设置当前窗口的图标
void setWindowIcon(const QIcon &icon);

//------------- 窗口标题 -------------
// 得到当前窗口的标题
QString windowTitle() const;
// 设置当前窗口的标题
void setWindowTitle(const QString &);

```



### 信号

设置发射策略

```c++
// QWidget::setContextMenuPolicy(Qt::ContextMenuPolicy policy);
// 窗口的右键菜单策略 contextMenuPolicy() 参数设置为 Qt::CustomContextMenu, 按下鼠标右键发射该信号
[signal] void QWidget::customContextMenuRequested(const QPoint &pos);
// 窗口图标发生变化, 发射此信号
[signal] void QWidget::windowIconChanged(const QIcon &icon);
// 窗口标题发生变化, 发射此信号
[signal] void QWidget::windowTitleChanged(const QString &title);

```







### 槽函数

```c++
//------------- 窗口显示 -------------
// 关闭当前窗口
[slot] bool QWidget::close();
// 隐藏当前窗口
[slot] void QWidget::hide();
// 显示当前创建以及其子窗口
[slot] void QWidget::show();
// 全屏显示当前窗口, 只对windows有效
[slot] void QWidget::showFullScreen();
// 窗口最大化显示, 只对windows有效
[slot] void QWidget::showMaximized();
// 窗口最小化显示, 只对windows有效
[slot] void QWidget::showMinimized();
// 将窗口回复为最大化/最小化之前的状态, 只对windows有效
[slot] void QWidget::showNormal();

//------------- 窗口状态 -------------
// 判断窗口是否可用
bool QWidget::isEnabled() const; // 非槽函数
// 设置窗口是否可用, 不可用窗口无法接收和处理窗口事件
// 参数true->可用, false->不可用
[slot] void QWidget::setEnabled(bool);
// 设置窗口是否可用, 不可用窗口无法接收和处理窗口事件
// 参数true->不可用, false->可用
[slot] void QWidget::setDisabled(bool disable);
// 设置窗口是否可见, 参数为true->可见, false->不可见
[slot] virtual void QWidget::setVisible(bool visible);


```



#### 信号+槽函数测试

> ```c++
> this->setContextMenuPolicy(Qt::CustomContextMenu);
>     connect(this,&QMainWindow::customContextMenuRequested,this,[=](){
>         QMenu a;
>         a.addAction("茄子");
>         a.addAction("西红花是");
>         a.addAction("牛马");
>         a.addAction("Odasd");
>         a.exec(QCursor::pos());
>         //显示在当前光标所在的一个全局坐标。
>     });
> ```
>
> > ![image-20231201192611204](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231201192611204.png) 
> >
> > 首先，设置了触发策略(自定义的)
> >
> > `this->setContextMenuPolicy(Qt::CustomContextMenu)` **设置了窗口的上下文菜单策略为自定义菜单。这意味着当用户右键单击窗口时，不会显示默认的上下文菜单，而是使用自定义的菜单。**
> >
> > 接下来，连接信号,QMainWindow::customContextMenuRequested
> >
> > `connect(this, &QMainWindow::customContextMenuRequested, this, [=]() { ... })` 用于连接 `customContextMenuRequested` 信号和一个 lambda 表达式。当用户请求上下文菜单时，即右键单击窗口时，该 lambda 表达式将被执行。
> >
> > 在 lambda 表达式中，首先创建了一个 `QMenu` 对象 `a`。然后，使用 `a.addAction("...")` 添加了多个动作（菜单项）。每个 `addAction` 调用都会创建一个新的 `QAction` 对象，并将其添加到菜单中。
> >
> > **接下来，使用 `a.exec(QCursor::pos())` 显示菜单。`QCursor::pos()` 返回当前鼠标光标的全局坐标位置，这样菜单就会显示在光标所在的位置。**
> >
> > 总结起来，这段代码的作用是：==当用户右键单击窗口时，显示一个自定义的上下文菜单==，菜单中包含了多个动作（菜单项）。菜单显示在当前鼠标光标的位置。







## QDialog

> 对话框类==是QWidget类的子类==, 处理继承自父类的属性之外, 还有一些自己所特有的属性, 常用的一些API函数如下:

```c++
// 构造函数
QDialog::QDialog(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

// 模态显示窗口
[virtual slot] int QDialog::exec();




// 隐藏模态窗口, 并且解除模态窗口的阻塞, 将 exec() 的返回值设置为 QDialog::Accepted
[virtual slot] void QDialog::accept();
// 隐藏模态窗口, 并且解除模态窗口的阻塞, 将 exec() 的返回值设置为 QDialog::Rejected
[virtual slot] void QDialog::reject();
// 关闭对话框并将其结果代码设置为r。finished()信号将发出r;
// 如果r是QDialog::Accepted 或 QDialog::Rejected，则还将分别发出accept()或Rejected()信号。
[virtual slot] void QDialog::done(int r);

[signal] void QDialog::accepted();
[signal] void QDialog::rejected();
[signal] void QDialog::finished(int result);

```

### 常用方法

![image-20231201202640122](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231201202640122.png) 

> 场景介绍:
>     1. 有两个窗口, 主窗口和一个对话框子窗口
>         2. 对话框窗口先显示, 根据用户操作选择是否显示主窗口

1. 添加MyDialog类

2. 并且添加三个按钮代表accept，reject，done

3. ```c++
   #include "mydialog.h"
   #include "ui_mydialog.h"
   
   MyDialog::MyDialog(QWidget *parent) :
       QDialog(parent),
       ui(new Ui::MyDialog)
   {
       ui->setupUi(this);
   }
   
   MyDialog::~MyDialog()
   {
       delete ui;
   }
   
   void MyDialog::on_accepted_clicked()
   {
       this->accept();
   }
   
   
   void MyDialog::on_rejected_clicked()
   {
       this->reject();
   }
   
   
   void MyDialog::on_finished_clicked()
   {
       this->done(10);
   }
   
   
   ```

4. mainwindow测试

   ```c++
   // 创建对话框对象
   MyDialog dlg;    
   int ret = dlg.exec();
   if(ret == QDialog::Accepted)
   {
       qDebug() << "accept button clicked...";
       // 显示主窗口
       MainWindow* w = new MainWindow;
       w->show();
   }
   else if(ret == QDialog::Rejected)
   {
       qDebug() << "reject button clicked...";
       // 不显示主窗口
       ......
       ......
   }
   else
   {
       // ret == 666
       qDebug() << "done button clicked...";
       // 根据需求进行逻辑处理
       ......
       ......
   }
   
   
   ```

   

![image-20231201202550017](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231201202550017.png) 

### 小结

> QDialog是Qt框架中用于创建对话框的类，它是QWidget的子类，可以用于显示模态或非模态的对话框窗口。
>
> 1. 创建对话框：可以通过继承QDialog类或者直接实例化一个QDialog对象来创建对话框。
>
> 2. 显示对话框：可**以使用exec()方法以模态方式显示对话框，也可以使用show()方法以非模态方式显示对话框。**
>
> 3. 对话框按钮：**可以在对话框中添加按钮，并为按钮添加相应的槽函数来响应用户的操作**。
>
> 4. 对话框布局：可以使用布局管理器来管理对话框中的控件，以确保它们在对话框中正确地布局和显示。
>
> 5. 对话框返回值：可以使用exec()方法来显示模态对话框，==**并通过返回值来获取用户的操作结果。**==
>
> 6. 自定义对话框：可以通过**重写QDialog的方法来自定义对话框的外观和行为，以满足特定的需求**。
>
> 7. 对话框样式：可以使用样式表来设置对话框的外观，包括背景颜色、字体样式等。
>
> 总之，QDialog是Qt中用于创建对话框的重要类，掌握其核心知识点可以帮助开发者更好地使用和定制对话框。



## QDialog的子类





### QMessageBox

> QMessageBox 对话框类是 QDialog 类的子类, 通过这个类可以**显示一些简单的提示框**, 用于展示警告、错误、问题等信息。关于这个类我们**只需要掌握一些静态方法**的使用就可以了。



#### 静态方法

> 这是关于Qt框架中QMessageBox类的question方法的参数说明：
>
> 1. parent：指定消息框的父窗口部件，即消息框要在哪个窗口部件的上下文中显示。
>
> 2. title：指定消息框的标题，即消息框中显示的标题文本内容。
>
> 3. text：指定消息框的主要文本内容，即显示在消息框中的主要信息。
>
> 4. buttons：指定消息框中显示的按钮集合，可以是Yes、No、Cancel等标准按钮组合。
>
> 5. defaultButton：指定默认情况下的按钮，即消息框中默认被选中的按钮。
>
> 这些参数用于自定义和控制消息框的外观和行为，使开发人员能够根据需要创建不同样式和交互方式的消息框。

> ```c++
> // 显示一个模态对话框, 将参数 text 的信息展示到窗口中
> [static] void QMessageBox::about(QWidget *parent, const QString &title, const QString &text);
> 
> /*
> 参数:
> - parent: 对话框窗口的父窗口
> - title: 对话框窗口的标题
> - text: 对话框窗口中显示的提示信息
> - buttons: 对话框窗口中显示的按钮(一个或多个)
> - defaultButton
>     1. defaultButton指定按下Enter键时使用的按钮。
>     2. defaultButton必须引用在参数 buttons 中给定的按钮。
>     3. 如果defaultButton是QMessageBox::NoButton, QMessageBox会自动选择一个合适的默认值。
> */
> // 显示一个信息模态对话框
> [static] QMessageBox::StandardButton QMessageBox::information(
>            QWidget *parent, const QString &title, 
>            const QString &text, 
>            QMessageBox::StandardButtons buttons = Ok,
>            QMessageBox::StandardButton defaultButton = NoButton);
> 
> // 显示一个错误模态对话框
> [static] QMessageBox::StandardButton QMessageBox::critical(
>            QWidget *parent, const QString &title, 
>            const QString &text, 
>            QMessageBox::StandardButtons buttons = Ok,
>            QMessageBox::StandardButton defaultButton = NoButton);
> 
> // 显示一个问题模态对话框
> [static] QMessageBox::StandardButton QMessageBox::question(
>            QWidget *parent, const QString &title, 
>            const QString &text, 
>            QMessageBox::StandardButtons buttons = StandardButtons(Yes | No), 
>            QMessageBox::StandardButton defaultButton = NoButton);
> 
> // 显示一个警告模态对话框
> [static] QMessageBox::StandardButton QMessageBox::warning(
>            QWidget *parent, const QString &title, 
>            const QString &text, 
>            QMessageBox::StandardButtons buttons = Ok,
>            QMessageBox::StandardButton defaultButton = NoButton);
> 
> ```
>
> 

#### 测试

> 指定显示的按钮和enter对应的默认按钮
>
> ```c++
>     QMessageBox::about(this,"警告","你要干什么?");
>     QMessageBox::critical(this,"abc","你错了！",QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
>     QMessageBox::warning(this,"警告","警告",QMessageBox::Close|QMessageBox::Help,QMessageBox::Help);
>     QMessageBox::question(this,"问题","问题窗口",QMessageBox::Apply|QMessageBox::Discard,QMessageBox::Discard);
> ```
>
> 

```c++
void MainWindow::on_msgbox_clicked()
{
    QMessageBox::about(this, "about",  "这是一个简单的消息提示框!!!");
    QMessageBox::critical(this, "critical", "这是一个错误对话框-critical...");
    int ret = QMessageBox::question(this, "question", 
             "你要保存修改的文件内容吗???",                                 
              QMessageBox::Save|QMessageBox::Cancel, 
              QMessageBox::Cancel);
    if(ret == QMessageBox::Save)
    {
        QMessageBox::information(this, "information", "恭喜你保存成功了, o(*￣︶￣*)o!!!");
    }
    else if(ret == QMessageBox::Cancel)
    {
        QMessageBox::warning(this, "warning", "你放弃了保存, ┭┮﹏┭┮ !!!");
    }
}

```

返回对应的枚举值，然后可以进行后续

### QFileDialog

#### API - 静态函数

```c++
/*
通用参数:
  - parent: 当前对话框窗口的父对象也就是父窗口
  - caption: 当前对话框窗口的标题
  - dir: 当前对话框窗口打开的默认目录
  - options: 当前对话框窗口的一些可选项,枚举类型, 一般不需要进行设置, 使用默认值即可
  - filter: 过滤器, 在对话框中只显示满足条件的文件, 可以指定多个过滤器, 使用 ;; 分隔
    - 样式举例: 
	- Images (*.png *.jpg)
	- Images (*.png *.jpg);;Text files (*.txt)
  - selectedFilter: 如果指定了多个过滤器, 通过该参数指定默认使用哪一个, 不指定默认使用第一个过滤器
*/
// 打开一个目录, 得到这个目录的绝对路径
[static] QString QFileDialog::getExistingDirectory(
                  QWidget *parent = nullptr, 
                  const QString &caption = QString(), 
                  const QString &dir = QString(), 
                  QFileDialog::Options options = ShowDirsOnly);

// 打开一个文件, 得到这个文件的绝对路径
[static] QString QFileDialog::getOpenFileName(
    	          QWidget *parent = nullptr, 
    		  const QString &caption = QString(), 
                  const QString &dir = QString(), 
                  const QString &filter = QString(), 
                  QString *selectedFilter = nullptr, 
                  QFileDialog::Options options = Options());

// 打开多个文件, 得到这多个文件的绝对路径
[static] QStringList QFileDialog::getOpenFileNames(
    	          QWidget *parent = nullptr, 
                  const QString &caption = QString(), 
                  const QString &dir = QString(), 
                  const QString &filter = QString(), 
                  QString *selectedFilter = nullptr, 
                  QFileDialog::Options options = Options());

// 打开一个目录, 使用这个目录来保存指定的文件
[static] QString QFileDialog::getSaveFileName(
    		  QWidget *parent = nullptr, 
                  const QString &caption = QString(), 
                  const QString &dir = QString(), 
                  const QString &filter = QString(), 
                  QString *selectedFilter = nullptr, 
                  QFileDialog::Options options = Options());

```

都返回的是QString字符串

#### 测试

1. 打开一个目录, 得到这个目录的绝对路径

   ![image-20231205095902734](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205095902734.png) 

2. 打开一个文件, 得到这个文件的绝对路径

   ![image-20231205100052563](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205100052563.png) 

3. 打开多个文件, 得到这多个文件的绝对路径

   ![image-20231205100535032](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205100535032.png)

4. 打开一个目录, 使用这个目录来保存指定的文件

   ![image-20231205102546727](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205102546727.png) 

   <img src="Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205102617890.png" alt="image-20231205102617890" style="zoom:50%;" /> 





### QFontDialog

> QFontDialog类是QDialog的子类, 通过这个类我们==**可以得到一个进行字体属性设置的对话框窗口**==, 和前边介绍的对话框类一样, 我们只需要调用这个类的静态成员函数就可以得到想要的窗口了。

#### QFont 字体类

关于字体的属性信息, 在QT框架中被封装到了一个叫QFont的类中, 下边为大家介绍一下这个类的API, 了解一下关于这个类的使用。

> ```c++
> // 构造函数
>   QFont::QFont();
>   /*
>   参数:
>     - family: 本地字库中的字体名, 通过 office 等文件软件可以查看
>     - pointSize: 字体的字号
>     - weight: 字体的粗细, 有效范围为 0 ~ 99
>     - italic: 字体是否倾斜显示, 默认不倾斜
>   */
>   QFont::QFont(const QString &family, int pointSize = -1, int weight = -1, bool italic = false);
>   
>   // 设置字体
>   void QFont::setFamily(const QString &family);
>   // 根据字号设置字体大小
>   void QFont::setPointSize(int pointSize);
>   // 根据像素设置字体大小
>   void QFont::setPixelSize(int pixelSize);
>   // 设置字体的粗细程度, 有效范围: 0 ~ 99
>   void QFont::setWeight(int weight);
>   // 设置字体是否加粗显示
>   void QFont::setBold(bool enable);
>   // 设置字体是否要倾斜显示
>   void QFont::setItalic(bool enable);
>   
>   // 获取字体相关属性(一般规律: 去掉设置函数的 set 就是获取相关属性对应的函数名)
>   QString QFont::family() const;
>   bool QFont::italic() const;
>   int QFont::pixelSize() const;
>   int QFont::pointSize() const;
>   bool QFont::bold() const;
>   int QFont::weight() const;
> 
> ```
>
> 如果一个QFont对象被创建, 并且进行了初始化, 我们可以将这个属性设置给某个窗口, 或者设置给当前应用程序对象。

```c++
// QWidget 类
// 得到当前窗口使用的字体
const QWidget::QFont& font() const;
// 给当前窗口设置字体, 只对当前窗口类生效
void QWidget::setFont(const QFont &);

// QApplication 类
// 得到当前应用程序对象使用的字体
[static] QFont QApplication::font();
// 给当前应用程序对象设置字体, 作用于当前应用程序的所有窗口
[static] void QApplication::setFont(const QFont &font, const char *className = nullptr);

```



#### QFontDialog

#### 静态API

```c++
/*
参数:
  - ok: 传出参数, 用于判断是否获得了有效字体信息, 指定一个布尔类型变量地址
  - initial: 字体对话框中默认选中并显示该字体信息, 用于对话框的初始化
  - parent: 字体对话框窗口的父对象
  - title: 字体对话框的窗口标题
  - options: 字体对话框选项, 使用默认属性即可, 一般不设置
*/
  [static] QFont QFontDialog::getFont(
		bool *ok, const QFont &initial, 
		QWidget *parent = nullptr, const QString &title = QString(), 
		QFontDialog::FontDialogOptions options = FontDialogOptions());
  
  [static] QFont QFontDialog::getFont(bool *ok, QWidget *parent = nullptr);
。
```

![image-20231205103727375](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205103727375.png)  

![image-20231205103744817](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205103744817.png) 





### QColorDialog

> QColorDialog类是QDialog的子类, 通过这个类我们可以==得到一个选择颜色的对话框窗口==, 和前边介绍的对话框类一样, 我们只需要调用这个类的静态成员函数就可以得到想要的窗口了。

#### 颜色类 QColor

> 关于颜色的属性信息, 在**QT框架中被封装到了一个叫QColor的类**中, 下边为大家介绍一下这个类的API, 了解一下关于这个类的使用。
> 各种颜色都是基于**红, 绿, 蓝**这三种颜色调配而成的, 并且颜色还可以进行透明度设置, 默认是不透明的。

```c++
// 构造函数
QColor::QColor(Qt::GlobalColor color);
QColor::QColor(int r, int g, int b, int a = ...);
QColor::QColor();

// 参数设置 red, green, blue, alpha, 取值范围都是 0-255
void QColor::setRed(int red);		// 红色
void QColor::setGreen(int green);	// 绿色
void QColor::setBlue(int blue);	// 蓝色
void QColor::setAlpha(int alpha);	// 透明度, 默认不透明(255)
///////////
void QColor::setRgb(int r, int g, int b, int a = 255);

int QColor::red() const;
int QColor::green() const;
int QColor::blue() const;
int QColor::alpha() const;
void QColor::getRgb(int *r, int *g, int *b, int *a = nullptr) const;

```

#### 静态API函数

```c++
  // 弹出颜色选择对话框, 并返回选中的颜色信息
/*
参数:
    - initial: 对话框中默认选中的颜色, 用于窗口初始化
    - parent: 给对话框窗口指定父对象
    - title: 对话框窗口的标题
    - options: 颜色对话框窗口选项, 使用默认属性即可, 一般不需要设置
*/
  [static] QColor QColorDialog::getColor(
		const QColor &initial = Qt::white, 
		QWidget *parent = nullptr, const QString &title = QString(), 
		QColorDialog::ColorDialogOptions options = ColorDialogOptions());

```

#### 测试

```c++
void MainWindow::on_pushButton_2_clicked()
{
    QColor color = QColorDialog::getColor();  // 弹出颜色选择对话框，获取用户选择的颜色
    QBrush brush(color);  // 用选定的颜色创建一个画刷对象
    QRect rect(0, 0, ui->color->width(), ui->color->height());  // 创建一个矩形区域，用于绘制
    QPixmap pix(rect.width(), rect.height());  // 创建一个大小与矩形相同的空白画布
    QPainter p(&pix);  // 在画布上创建一个 QPainter 对象，用于绘制操作
    p.fillRect(rect, brush);  // 使用画刷填充矩形区域
    ui->color->setPixmap(pix);  // 将绘制好的画布设置为名为“color”的部件的显示内容

    // 创建包含颜色信息的字符串
    QString text = QString("red: %1, green: %2, blue: %3, 透明度: %4")
                       .arg(color.red()).arg(color.green()).arg(color.blue()).arg(color.alpha());
    ui->colorlabel->setText(text);  // 将包含颜色信息的字符串设置为名为“colorlabel”的部件的文本内容
}
```

![image-20231205104956328](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205104956328.png) 





### QInputDialog

> QInputDialog类是QDialog的子类, 通过这个类我们可以**得到一个输入对话框窗口**, 根据实际需求我们可以在这个**输入窗口中输入整形, 浮点型, 字符串类型的数据**, 并且**还可以显示下拉菜单供使用者选择**。
> 和前边介绍的对话框类一样, 我们只需要调用这个类的静态成员函数就可以得到想要的窗口了。

#### API - 静态函数

```c++
// 得到一个可以输入浮点数的对话框窗口, 返回对话框窗口中输入的浮点数
/*
参数:
  - parent: 对话框窗口的父窗口
  - title: 对话框窗口显示的标题信息
  - label: 对话框窗口中显示的文本信息(用于描述对话框的功能)
  - value: 对话框窗口中显示的浮点值, 默认为 0
  - min: 对话框窗口支持显示的最小数值
  - max: 对话框窗口支持显示的最大数值
  - decimals: 浮点数的精度, 默认保留小数点以后1位
  - ok: 传出参数, 用于判断是否得到了有效数据, 一般不会使用该参数
  - flags: 对话框窗口的窗口属性, 使用默认值即可
*/
[static] double QInputDialog::getDouble(
    		QWidget *parent, const QString &title, 
    		const QString &label, double value = 0, 
    		double min = -2147483647, double max = 2147483647, 
    		int decimals = 1, bool *ok = nullptr, 
    		Qt::WindowFlags flags = Qt::WindowFlags());

// 得到一个可以输入整形数的对话框窗口, 返回对话框窗口中输入的整形数
/*
参数:
  - parent: 对话框窗口的父窗口
  - title: 对话框窗口显示的标题信息
  - label: 对话框窗口中显示的文本信息(用于描述对话框的功能)
  - value: 对话框窗口中显示的整形值, 默认为 0
  - min: 对话框窗口支持显示的最小数值
  - max: 对话框窗口支持显示的最大数值
  - step: 步长, 通过对话框提供的按钮调节数值每次增长/递减的量
  - ok: 传出参数, 用于判断是否得到了有效数据, 一般不会使用该参数
  - flags: 对话框窗口的窗口属性, 使用默认值即可
*/
[static] int QInputDialog::getInt(
    		QWidget *parent, const QString &title, 
    		const QString &label, int value = 0, 
    		int min = -2147483647, int max = 2147483647, 
    		int step = 1, bool *ok = nullptr, 
    		Qt::WindowFlags flags = Qt::WindowFlags());

// 得到一个带下来菜单的对话框窗口, 返回选择的菜单项上边的文本信息
/*
参数:
  - parent: 对话框窗口的父窗口
  - title: 对话框窗口显示的标题信息
  - label: 对话框窗口中显示的文本信息(用于描述对话框的功能)
  - items: 字符串列表, 用于初始化窗口中的下拉菜单, 每个字符串对应一个菜单项
  - current: 通过菜单项的索引指定显示下拉菜单中的哪个菜单项, 默认显示第一个(编号为0)
  - editable: 设置菜单项上的文本信息是否可以进行编辑, 默认为true, 即可以编辑
  - ok: 传出参数, 用于判断是否得到了有效数据, 一般不会使用该参数
  - flags: 对话框窗口的窗口属性, 使用默认值即可
  - inputMethodHints: 设置显示模式, 默认没有指定任何特殊显示格式, 显示普通文本字符串
    - 如果有特殊需求, 可以参数帮助文档进行相关设置
*/
[static] QString QInputDialog::getItem(
    		QWidget *parent, const QString &title, 
    		const QString &label, const QStringList &items, 
    		int current = 0, bool editable = true, bool *ok = nullptr, 
    		Qt::WindowFlags flags = Qt::WindowFlags(), 
    		Qt::InputMethodHints inputMethodHints = Qt::ImhNone);

// 得到一个可以输入多行数据的对话框窗口, 返回用户在窗口中输入的文本信息
/*
参数:
  - parent: 对话框窗口的父窗口
  - title: 对话框窗口显示的标题信息
  - label: 对话框窗口中显示的文本信息(用于描述对话框的功能)
  - text: 指定显示到多行输入框中的文本信息, 默认是空字符串
  - ok: 传出参数, 用于判断是否得到了有效数据, 一般不会使用该参数
  - flags: 对话框窗口的窗口属性, 使用默认值即可
  - inputMethodHints: 设置显示模式, 默认没有指定任何特殊显示格式, 显示普通文本字符串
    - 如果有特殊需求, 可以参数帮助文档进行相关设置
*/
[static] QString QInputDialog::getMultiLineText(
    		QWidget *parent, const QString &title, const QString &label, 
    		const QString &text = QString(), bool *ok = nullptr, 
    		Qt::WindowFlags flags = Qt::WindowFlags(), 
    		Qt::InputMethodHints inputMethodHints = Qt::ImhNone);

// 得到一个可以输入单行信息的对话框窗口, 返回用户在窗口中输入的文本信息
/*
参数:
  - parent: 对话框窗口的父窗口 
  - title: 对话框窗口显示的标题信息
  - label: 对话框窗口中显示的文本信息(用于描述对话框的功能)
  - mode: 指定单行编辑框中数据的反馈模式, 是一个 QLineEdit::EchoMode 类型的枚举值
    - QLineEdit::Normal: 显示输入的字符。这是默认值
    - QLineEdit::NoEcho: 不要展示任何东西。这可能适用于连密码长度都应该保密的密码。
    - QLineEdit::Password: 显示与平台相关的密码掩码字符，而不是实际输入的字符。
    - QLineEdit::PasswordEchoOnEdit: 在编辑时按输入显示字符，否则按密码显示字符。
  - text: 指定显示到单行输入框中的文本信息, 默认是空字符串
  - ok: 传出参数, 用于判断是否得到了有效数据, 一般不会使用该参数
  - flags: 对话框窗口的窗口属性, 使用默认值即可
  - inputMethodHints: 设置显示模式, 默认没有指定任何特殊显示格式, 显示普通文本字符串
     - 如果有特殊需求, 可以参数帮助文档进行相关设置
*/
[static] QString QInputDialog::getText(
    		QWidget *parent, const QString &title, const QString &label,
    		QLineEdit::EchoMode mode = QLineEdit::Normal, 
    		const QString &text = QString(), bool *ok = nullptr, 
    		Qt::WindowFlags flags = Qt::WindowFlags(), 
    		Qt::InputMethodHints inputMethodHints = Qt::ImhNone);

```





#### 测试

```c++
void MainWindow::on_inputdlg_clicked()
{
    int ret = QInputDialog::getInt(this, "年龄", "您的当前年龄: ", 10, 1, 100, 2);
    QMessageBox::information(this, "年龄", "您的当前年龄: " + QString::number(ret));
}

```

#### 带下拉菜单的

```c++
void MainWindow::on_pushButton_3_clicked()
{
//    getItem(QWidget *parent, const QString &title, const QString &label, const QStringList &items, int current = 0,
//            bool editable = true, bool *ok = nullptr, Qt::WindowFlags flags = Qt::WindowFlags(), Qt::InputMethodHints inputMethodHints = Qt::ImhNone)

        QStringList items;
        items << "苹果" << "橙子" << "橘子" << "葡萄" << "香蕉" << "哈密瓜";
            QString item = QInputDialog::getItem(this, "请选择你喜欢的水果", "你最喜欢的水果:", items, 1, false);
        QMessageBox::information(this, "水果", "您最喜欢的水果是: " + item);

}
```





#### 多行字符输入框

```c++
void MainWindow::on_inputdlg_clicked()
{
    QString info = QInputDialog::getMultiLineText(this, "表白", "您最想对漂亮小姐姐说什么呢?", "呦吼吼...");
    QMessageBox::information(this, "知心姐姐", "您最想对小姐姐说: " + info);
}

```

#### 单行字符输入框

```c++
void MainWindow::on_inputdlg_clicked()
{
    QString text = QInputDialog::getText(this, "密码", "请输入新的密码", QLineEdit::Password, "helloworld");
    QMessageBox::information(this, "密码", "您设置的密码是: " + text);
}

```

![image-20231205110327030](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205110327030.png) 

> 这段文字描述了 `QLineEdit` 类中的四种不同的显示模式，分别是：
>
> 1. `Normal`（默认模式）：以输入的形式显示字符。也就是说，输入的字符会直接显示在文本框中。
>
> 2. `NoEcho`：不显示任何内容。这个模式适用于密码等需要保密的情况，甚至连密码长度都应该保密。
>
> 3. `Password`：显示与平台相关的密码屏蔽字符，而不是实际输入的字符。这个模式用于在输入密码时隐藏实际输入的字符。
>
> 4. `PasswordEchoOnEdit`：在编辑时显示输入的字符，其他情况下则按照 `Password` 模式显示字符。也就是说，在输入过程中字符会显示出来，但在非输入状态下会被替换成密码屏蔽字符。
>
> 以上是 `QLineEdit` 提供的几种不同的显示模式，可以根据具体需求选择合适的模式来展示文本框中的内容。





### QProgressDialog

> QProgressDialog类是QDialog的子类, 通过这个类我们可以得到一个**带进度条的对话框窗口,** 这种类型的对话框窗口一般常用于**文件拷贝、数据传输等实时交互的场景中。**

#### API

```c++
// 构造函数
/*
参数:
  - labelText: 对话框中显示的提示信息
  - cancelButtonText: 取消按钮上显示的文本信息
  - minimum: 进度条最小值
  - maximum: 进度条最大值
  - parent: 当前窗口的父对象
  - f: 当前进度窗口的flag属性, 使用默认属性即可, 无需设置
*/
QProgressDialog::QProgressDialog(
	QWidget *parent = nullptr, 
	Qt::WindowFlags f = Qt::WindowFlags());

QProgressDialog::QProgressDialog(
	const QString &labelText, const QString &cancelButtonText, 
	int minimum, int maximum, QWidget *parent = nullptr,
	Qt::WindowFlags f = Qt::WindowFlags());


// 设置取消按钮显示的文本信息
[slot] void QProgressDialog::setCancelButtonText(const QString &cancelButtonText);

// 公共成员函数和槽函数
QString QProgressDialog::labelText() const;
void QProgressDialog::setLabelText(const QString &text);

// 得到进度条最小值
int QProgressDialog::minimum() const;
// 设置进度条最小值
void QProgressDialog::setMinimum(int minimum);

// 得到进度条最大值
int QProgressDialog::maximum() const;
// 设置进度条最大值
void QProgressDialog::setMaximum(int maximum);

// 设置进度条范围(最大和最小值)
[slot] void QProgressDialog::setRange(int minimum, int maximum);


// 得到进度条当前的值
int QProgressDialog::value() const;



// 设置进度条当前的值
void QProgressDialog::setValue(int progress);


bool QProgressDialog::autoReset() const;
// 当value() = maximum()时，进程对话框是否调用reset()，此属性默认为true。
void QProgressDialog::setAutoReset(bool reset);


bool QProgressDialog::autoClose() const;
// 当value() = maximum()时，进程对话框是否调用reset()并且隐藏，此属性默认为true。
void QProgressDialog::setAutoClose(bool close);

// 判断用户是否按下了取消键, 按下了返回true, 否则返回false
bool wasCanceled() const;


// 重置进度条
// 重置进度对话框。wascancelled()变为true，直到进程对话框被重置。进度对话框被隐藏。
[slot] void QProgressDialog::cancel();
// 重置进度对话框。如果autoClose()为真，进程对话框将隐藏。
[slot] void QProgressDialog::reset();   

// 信号
// 当单击cancel按钮时，将发出此信号。默认情况下，它连接到cancel()槽。
[signal] void QProgressDialog::canceled();

// 设置窗口的显示状态(模态, 非模态)
/*
参数:
	Qt::NonModal  -> 非模态
	Qt::WindowModal	-> 模态, 阻塞父窗口
	Qt::ApplicationModal -> 模态, 阻塞应用程序中的所有窗口
*/
void QWidget::setWindowModality(Qt::WindowModality windowModality);



```

> `QProgressDialog` 类中的常用函数和参数的使用方法。根据具体需求和场景，可以使用这些函数来定制和控制进度对话框的行为和显示。
>
> 1. `QProgressDialog::QProgressDialog(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())`：构造函数，用于创建一个进度对话框窗口。可以传入父对象 `parent` 和窗口标志 `f`。
>
> 2. `QProgressDialog::QProgressDialog(const QString &labelText, const QString &cancelButtonText, int minimum, int maximum, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())`：另一个构造函数，除了父对象 `parent` 和窗口标志 `f` 参数外，还接受一些额外的参数，包括对话框中显示的提示信息 `labelText`、取消按钮上显示的文本信息 `cancelButtonText`、进度条的最小值 `minimum` 和最大值 `maximum`。
>
> 3. `void QProgressDialog::setCancelButtonText(const QString &cancelButtonText)`：设置取消按钮上显示的文本信息。
>
> 4. `QString QProgressDialog::labelText() const` 和 `void QProgressDialog::setLabelText(const QString &text)`：获取和设置对话框中显示的提示信息。
>
> 5. `int QProgressDialog::minimum() const` 和 `void QProgressDialog::setMinimum(int minimum)`：获取和设置进度条的最小值。
>
> 6. `int QProgressDialog::maximum() const` 和 `void QProgressDialog::setMaximum(int maximum)`：获取和设置进度条的最大值。
>
> 7. `void QProgressDialog::setRange(int minimum, int maximum)`：设置进度条的范围，即最小值和最大值。
>
> 8. `int QProgressDialog::value() const` 和 `void QProgressDialog::setValue(int progress)`：获取和设置进度条的当前值。
>
> 9. `bool QProgressDialog::autoReset() const` 和 `void QProgressDialog::setAutoReset(bool reset)`：获取和设置当进度达到最大值时，进度对话框是否自动重置为初始状态。
>
> 10. `bool QProgressDialog::autoClose() const` 和 `void QProgressDialog::setAutoClose(bool close)`：获取和设置当进度达到最大值时，进度对话框是否自动关闭。
>
> 11. `bool QProgressDialog::wasCanceled() const`：检查用户是否按下了取消按钮，如果按下了则返回 true，否则返回 false。
>
> 12. `void QProgressDialog::cancel()` 和 `void QProgressDialog::reset()`：重置进度对话框，`cancel()` 方法会调用 `reset()` 方法并隐藏进度对话框。
>
> 13. `signal void QProgressDialog::canceled()`：当点击取消按钮时发出的信号，默认情况下与 `cancel()` 槽连接。
>
> 14. `void QWidget::setWindowModality(Qt::WindowModality windowModality)`：设置窗口的显示状态，可以选择非模态、模态（阻塞父窗口）或应用程序模态（阻塞应用程序中的所有窗口）。
>

#### 测试

> 场景描述:
> 	1. 基于定时器模拟文件拷贝的场景
> 	2. 点击窗口按钮, 进度条窗口显示, 同时启动定时器
> 	3. 通过定时器信号, 按照固定频率更新对话框窗口进度条
> 	4. 当进度条当前值 == 最大值, 关闭定时器, 关闭并析构进度对话框

一个按钮加槽函数

```c++
void MainWindow::on_pushButton_3_clicked()
{
        // 1. 创建进度条对话框窗口对象
        QProgressDialog *progress = new QProgressDialog(
            "正在拷贝数据...", "取消拷贝", 0, 100, this);
        // 2. 初始化并显示进度条窗口
        progress->setWindowTitle("请稍后");
        progress->setWindowModality(Qt::WindowModal);
        progress->show();

        // 3. 更新进度条
        static int value = 0;
        QTimer *timer = new QTimer;
        connect(timer, &QTimer::timeout, this, [=]()
                {
                    progress->setValue(value);
                    value++;
                    // 当value > 最大值的时候
                    if(value > progress->maximum())
                    {
                        timer->stop();
                        value = 0;
                        delete progress;
                        delete timer;
                    }
                });

        connect(progress, &QProgressDialog::canceled, this, [=]()
                {
                    timer->stop();
                    value = 0;
                    delete progress;
                    delete timer;
                });

        timer->start(50);

}
```

 ![image-20231205111345920](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205111345920.png) 







## QMainWindow

> `QMainWindow`是标准基础窗口中结构最复杂的窗口, 其组成如下:
>
> - 提供了`菜单栏`, `工具栏`, `状态栏`, `停靠窗口`
> - ==菜单栏==: 只能有一个, 位于窗口的最上方
> - 工具栏: 可以有多个, 默认提供了一个, 窗口的上下左右都可以停靠
> - ==状态栏==: 只能有一个, 位于窗口最下方
> - 停靠窗口: 可以有多个, 默认没有提供, 窗口的上下左右都可以停靠

![image-20231205132834050](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205132834050.png) 

###  菜单栏

#### 添加菜单项

> 关于顶级菜单可以直接在UI窗口中双击, 直接输入文本信息即可, 对应子菜单项也可以通过先双击在输入的方式完成添加, 但是`这种方式不支持中文的输入`。
>
> ![image-20231205133011806](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205133011806.png) 

#### 常用的添加方式

> 一般情况下, 我们都是**先在外面创建出`QAction`对象**, 然后再将其拖拽到某个菜单下边, 这样子菜单项的添加就完成了。
>
> <img src="Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205133441347.png" alt="image-20231205133441347" style="zoom:50%;" /> 
>
> 然后拖入到ui的菜单栏就可以了！
>
> ![image-20231205133507561](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205133507561.png)** **![image-20231205133515859](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205133515859.png) 
>
> 拖入成功



#### 代码的方式

```c++
// 给菜单栏添加菜单
QAction *QMenuBar::addMenu(QMenu *menu);
QMenu *QMenuBar::addMenu(const QString &title);
QMenu *QMenuBar::addMenu(const QIcon &icon, const QString &title);

// 给菜单对象添加菜单项(QAction)
QAction *QMenu::addAction(const QString &text);
QAction *QMenu::addAction(const QIcon &icon, const QString &text);

// 添加分割线
QAction *QMenu::addSeparator();
```

#### 菜单项 QAction 事件的处理

> 单击菜单项, 该对象会发出一个信号

```c++
// 点击QAction对象发出该信号
[signal] void QAction::triggered(bool checked = false);
```



#### 测试

```c++
// save_action 是某个菜单项对象名, 点击这个菜单项会弹出一个对话框
connect(ui->save_action, &QAction::triggered, this, [=]()
{
      QMessageBox::information(this, "Triggered", "我是菜单项, 你不要调戏我...");
});
```







### 工具栏

默认是没有工具栏的

<img src="Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205134857102.png" alt="image-20231205134857102" style="zoom:50%;" /> 

> 窗口中的工具栏我们经常见到, 并不会为此感到陌生, 那么如何往工具栏中添加工具按钮呢? 一共有两种方式, 这里依次为大家进行介绍。
>
> 方式1：先创建QAction对象, 然后拖拽到工具栏中, 和添加菜单项的方式相同

<img src="Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205134834484.png" alt="image-20231205134834484" style="zoom:50%;" /> 

方式2：如果不通过UI界面直接操作，那么就需要调用相关的API函数了

```c++
// 在QMainWindow窗口中添加工具栏
void QMainWindow::addToolBar(Qt::ToolBarArea area, QToolBar *toolbar);
void QMainWindow::addToolBar(QToolBar *toolbar);
QToolBar *QMainWindow::addToolBar(const QString &title);

// 将Qt控件放到工具栏中
// 工具栏类: QToolBar
// 添加的对象只要是QWidget或者启子类都可以被添加
QAction *QToolBar::addWidget(QWidget *widget);

// 添加QAction对象
QAction *QToolBar::addAction(const QString &text);
QAction *QToolBar::addAction(const QIcon &icon, const QString &text);

// 添加分隔线
QAction *QToolBar::addSeparator()
```

> 通过代码的方式对工具栏进行操作

```c++
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 添加第二个工具栏
    QToolBar* toolbar = new QToolBar("toolbar");
    this->addToolBar(Qt::LeftToolBarArea, toolbar);

    // 给工具栏添加按钮和单行输入框
    ui->toolBar->addWidget(new QPushButton("搜索"));
    QLineEdit* edit = new QLineEdit;
    edit->setMaximumWidth(200);
    edit->setFixedWidth(100);
    ui->toolBar->addWidget(edit);
    // 添加QAction类型的菜单项
    ui->toolBar->addAction(QIcon(":/er-dog"), "二狗子");
}
```

#### 属性设置

> 在UI窗口的树状列表中, 找到工具栏节点, 就可以到的工具栏的属性设置面板了, 这样就可以根据个人需求对工具栏的属性进行设置和修改了。 

<img src="Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205135034779.png" alt="image-20231205135034779" style="zoom:67%;" /> 

> 在Qt控件的属性窗口中对应了一些属性, 这些属性大部分都应了一个设置函数
>
> - 在对应的类中函数名叫什么?
>   - 规律: `set+属性名 == 函数名`
> - 某些属性没有对应的函数, 只能在属性窗口中设置 

### 状态栏

addwidget方法！添加控件

> 一般情况下, 需要在状态栏中添加某些控件, 显示某些属性, 使用最多的就是添加标签 QLabel

> ```c++
> // 类型: QStatusBar
> void QStatusBar::addWidget(QWidget *widget, int stretch = 0);
> 
> [slot] void QStatusBar::clearMessage();
> [slot] void QStatusBar::showMessage(const QString &message, int timeout = 0);
> ```

> ```c++
> MainWindow::MainWindow(QWidget *parent)
>     : QMainWindow(parent)
>     , ui(new Ui::MainWindow)
> {
>     ui->setupUi(this);
> 
>     // 状态栏添加子控件
>     // 按钮
>     QPushButton* button = new QPushButton("按钮");
>     ui->statusBar->addWidget(button);
>     // 标签
>     QLabel* label = new QLabel("hello,world");
>     ui->statusBar->addWidget(label);
> }
> ```

###  停靠窗口

> 停靠窗口可以通过鼠标拖动停靠到窗口的上、下、左、右，或者浮动在窗口上方。如果需要这种类型的窗口必须手动添加，`如果在非QMainWindow类型的窗口中添加了停靠窗口, 那么这个窗口是不能移动和浮动的。`
> 浮动窗口在工具栏中， 直接将其拖拽到UI界面上即可。

<img src="Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205135427953.png" alt="image-20231205135427953" style="zoom:67%;" /> 

停靠窗口也有一个属性面板, 我们可以在其对应属性面板中直接进行设置和修改相关属性。 

![image-20231205135443641](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205135443641.png)





# 资源文件 .qrc

> 资源文件顾名思义就是一个存储资源的文件，在Qt中引入资源文件好处在于**他能提高应用程序的部署效率并且减少一些错误的发生。**
> `在程序编译过程中， 添加到资源文件中的文件也会以二进制的形式被打包到可执行程序中，这样这些资源就永远和可执行程序捆绑到一起了，不会出现加载资源却找不到的问题。`
> 虽然资源文件优势很明显，但是它也不是万能的，资源文件中一般添加的都是比较小的资源，比如： 图片，配置文件，MP3 等，**如果是类似视频这类比较大的文件就不适合放到资源文件中了**。

```c++
// 创建图标对象
QIcon::QIcon(const QString &fileName);
// QWidget类的 公共成员函数
void setWindowIcon(const QIcon &icon);

// 给窗口设置图标
// 弊端: 发布的 exe 必须要加载 d:\\pic\\1.ico 如果当前主机对应的目录中没有图片, 图标就无法被加载
// 发布 exe 需要额外发布图片, 将其部署到某个目录中
setWindowIcon(QIcon("d:\\pic\\1.ico"));
```

> 我们可以使用资源文件解决上述的弊端, 这样发布应用程序的时候直接发布exe就可以, 不需要再额外提供图片了。
>
> 下面介绍一下关于资源文件的创建步骤:

![image-20231205135658765](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205135658765.png) 

![image-20231205135733186](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205135733186.png) 

> ?资源文件添加完毕之后, 继续给大家介绍资源文件的使用

> 一个资源文件中可以添加多个前缀, 前缀就是添加的资源在资源文件中的路径, 前缀根据实际需求制定即可, 路径以 `/` 开头

> 前缀添加完毕, 就可以在某个前缀下边添加相关的资源了。

> - 弹出以文件选择对话框, 选择资源文件
>   - 资源文件放到什么地方?
>     - `放到和 项目文件 .pro 同一级目录或者更深的目录中`
>     - `错误的做法: 将资源文件放到 .pro文件的上级目录, 这样资源文件无法被加载到`

> 可以给添加的资源文件设置别名, 设置别名之后原来的名字就不能使用了

> ```
> 温馨提示:
>      1. 在高版本的QtCreator中, 资源文件名字或者别名不支持中文
>      2. 如果设置了中文会出现编译会报错
>      3. 在此只是演示, 使用过程中需要额外注意该问题
> ```

![image-20231205140230477](Qt%E4%B8%AD%E7%9A%84%E5%9F%BA%E7%A1%80%E7%AA%97%E5%8F%A3%E7%B1%BB/image-20231205140230477.png) 
