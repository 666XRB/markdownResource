# Qt定时器类QTimer

## 前言

在进行窗口程序的处理过程中, ==经常要周期性的执行某些操作,== 或者制作一些动画效果，看似比较复杂的问题使用定时器就可以完美的解决这些问题， 

Qt中提供了两种定时器方式

一种是使用==Qt中的事件处理函数==这个在后续章节会给大家做细致的讲解，本节主要给大家介绍一下==Qt中的定时器类 QTimer==的使用方法。

要使用它

> 只需创建一个**QTimer类对象**，然后**调用其 start() 函数开启定时器**，此后**QTimer对象**就会**周期性的**发出 **timeout() 信号。**





## public/slot function



了解一下这个类的相关API。

> 秒的单位是msc
>
> `    timer.setTimerType(Qt::PreciseTimer);`
>
> 设置定时器的准确度
>
> `    qDebug()<<timer.timerType();`
>
> 返回定时器的准确度
>
> `QTimer::singleShot(5000,this,&MainWindow::close);`
>
> 单发定时器
>
> 

```c++
// 构造函数
// 如果指定了父对象, 创建的堆内存可以自动析构
QTimer::QTimer(QObject *parent = nullptr);

// 设置定时器时间间隔为 msec 毫秒
// 默认值是0，一旦窗口系统事件队列中的所有事件都已经被处理完，一个时间间隔为0的QTimer就会触发
void QTimer::setInterval(int msec);
// 获取定时器的时间间隔, 返回值单位: 毫秒
int QTimer::interval() const;

// 根据指定的时间间隔启动或者重启定时器, 需要调用 setInterval() 设置时间间隔
[slot] void QTimer::start();
// 启动或重新启动定时器，超时间隔为msec毫秒。
[slot] void QTimer::start(int msec);
// 停止定时器。
[slot] void QTimer::stop();

// 设置定时器精度
/*
参数: 
    - Qt::PreciseTimer -> 精确的精度, 毫秒级
    - Qt::CoarseTimer  -> 粗糙的精度, 和1毫秒的误差在5%的范围内, 默认精度
    - Qt::VeryCoarseTimer -> 非常粗糙的精度, 精度在1秒左右
*/
void QTimer::setTimerType(Qt::TimerType atype);
Qt::TimerType QTimer::timerType() const;	// 获取当前定时器的精度

// 如果定时器正在运行，返回true; 否则返回false。
bool QTimer::isActive() const;

// 判断定时器是否只触发一次
bool QTimer::isSingleShot() const;
// 设置定时器是否只触发一次, 参数为true定时器只触发一次, 为false定时器重复触发, 默认为false
void QTimer::setSingleShot(bool singleShot);

```





## Singal

这个类的信号只有一个, 当**定时器超时时，该信号就会被发射出来**。

给这个信号通过conect()关联一个槽函数, 就可以在槽函数中**处理超时事件**了。

```c++
[signal] void QTimer::timeout();
```







## static public function

> `QTimer::singleShot(5000,this,&MainWindow::close);`

1. ##### 首先要创建定时器

2. ##### 设置好时间间隔,这是必要的

3. 其次可以设置无关紧要的定时器类型

4. 有两个状态is

5. 有个静态函数，返回值为void,可以搞一个几秒钟发射信号给谁，谁在做出具体的行为

```c++
// 其他同名重载函数可以自己查阅帮助文档
/*
功能: 在msec毫秒后发射一次信号, 并且只发射一次
参数:
	- msec:     在msec毫秒后发射信号
	- receiver: 接收信号的对象地址
	- method:   槽函数地址
*/
[static] void QTimer::singleShot(
        int msec, const QObject *receiver, 
        PointerToMemberFunction method);


```





## 周期定时器

<img src="C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231201190101971.png" alt="image-20231201190101971" style="zoom: 67%;" /> 每过1s就更新文本框的时间

```c++
// 创建定时器对象
QTimer* timer = new QTimer(this);

// 修改定时器对象的精度
timer->setTimerType(Qt::PreciseTimer);

// 按钮 loopBtn 的点击事件
// 点击按钮启动或者关闭定时器, 定时器启动, 周期性得到当前时间
connect(ui->loopBtn, &QPushButton::clicked, this, [=]()
{
    // 启动定时器
    if(timer->isActive())
    {
        timer->stop();  // 关闭定时器
        ui->loopBtn->setText("开始");
    }
    else
    {
        ui->loopBtn->setText("关闭");
        timer->start(1000); // 1000ms == 1s
    }
});

connect(timer, &QTimer::timeout, this, [=]()
{
    QTime tm = QTime::currentTime();
    // 格式化当前得到的系统时间
    QString tmstr = tm.toString("hh:mm:ss.zzz");
    // 设置要显示的时间
    ui->curTime->setText(tmstr);
});
```





## 小结

> 1. QTimer类是Qt中的一个计时器类，用于==在一定时间间隔内发出信号。==
>
> 2. QTimer可以设置==单次==或**重复**定时器，可以设**置定时器的时间间隔**和启动方式。
>
> 3. QTimer的**信号槽机制**可以与**其他Qt对象进行连接**，实现定时执行某些任务的功能。
>
> 4. QTimer的**start()方法用于启动定时器**，**stop()方法用于停止定时器**。
>
> 5. QTimer的**timeout()信号在定时器到达指定时间间隔时发出**，可以与其他Qt对象的槽函数进行连接。
>
> 6. QTimer的singleShot()方法可以设置**单次定时器**，只在指定的时间间隔后执行一次。
>
> 7. QTimer的isActive()方法可以判断定时器是否处于活动状态。
>
> 8. QTimer的interval()方法可以获取或设置定时器的时间间隔。
>
> 9. QTimer的remainingTime()方法可以**获取定时器还剩余的时间**。
>
> 10. QTimer的timerId()方法可以**获取定时器的ID**。he