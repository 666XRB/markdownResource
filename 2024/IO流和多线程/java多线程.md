# java多线程

## 认识多线程

### 什么是线程?

+ 线程（Thread）是**操作系统**能够进行运算调度的最小单位
+ **一个进程可以包含多个线程,**线程是进程中的实际运作单位。
+ **线程共享进程的资源**，如内存空间、文件句柄等。线程间可以通过共享的内存空间进行通信，也可以通过同步机制（如锁）来协调彼此的执行。

![image-20240320180216043](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240320180216043.png) 

简单理解为：应用软件中互相独立，可以同时运行的功能



### 什么是多线程？

多线程：

+ 在一个进程中同时运行多个线程。
+ 多线程的优点包括提高程序的并发性和响应性，因为它允许程序同时执行多个任务，也可以利用多核处理器来提高性能。

### 小结

![image-20240320180950913](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240320180950913.png) 





## 并发和并行

### 并发

**并发**：在同一时刻，有多条指令在**`单个`CPU上`交替`执行**

![PixPin03-20_18-13-33](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/PixPin03-20_18-13-33.gif) 

### 并行

**并行**：在同一时刻，有多条指令在**`多个`CPU上`同时`执行**

![PixPin03-20_18-18-21](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/PixPin03-20_18-18-21.gif) 

### 区别

![PixPin03-20_18-17-20](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/PixPin03-20_18-17-20.gif)



### 小结

> 1. **并发（Concurrency）**：指的是在单个系统中**同时执行多个独立的任务**。多个线程可能会交替执行，但并不一定同时执行。在单核处理器上，实现并发通常是通过时间片轮转的方式，即每个线程分配一段时间片段，在这段时间内执行自己的任务。在多核处理器上，也可以实现并发，但这并不意味着所有线程都同时执行，而是多个线程可以在多个核心上并发执行。
> 2. **并行（Parallelism）**：指的是在**多个处理单元上同时执行多个任务**。在多线程编程中，如果**多个线程能够同时在不同的处理单元（如多核处理器的多个核心）上执行**，那么就实现了并行。并行可以显著提高程序的执行速度，因为多个任务可以同时进行，而不需要等待.
>
> ---
>
> - **并发（Concurrency）**：你同时在做这两个任务，但不一定是同时进行。比如，你可以开始洗衣服，洗到一半时停下来，然后去做饭，然后回来继续洗衣服。这就是并发，你在处理多个任务，但不一定同时进行。
> - **并行（Parallelism）**：现在假设你有一个助手，你和助手可以同时做洗衣服和做饭这两个任务。你可以和助手一起分担工作，这样洗衣服和做饭可以同时进行。这就是并行，多个任务在同一时间段内同时进行。

## 多线程的实现方式

### 1.继承Thread类的方式进行实现

#### How to do

> + 创建一个自定义的类，**继承** `Thread` 并重写 `run()` 方法来定义线程的任务。
> + 然后，创建该类的实例并调用 `start()` 方法来启动线程。

#### MyThread.java

```java
package org.example;

public class MyThread extends Thread{
    private String work;

    public MyThread(String work) {
        this.work = work;
    }

    @Override
    public void run() {
        System.out.println("我在"+work);
    }
}

```

重写方法



#### Main.java

```java
package org.example;

public class Main {
    public static void main(String[] args) {


        // 创建并启动第一个线程
        MyThread myThread1 = new MyThread("唱歌,线程1");
        myThread1.start();


        // 创建并启动第二个线程
        MyThread myThread2 = new MyThread("跳舞，线程2");
        myThread2.start();
    }
}

```



#### 效果

非多线程应该是先执行10次线程1后执行10次线程2

现在是交替进行

![image-20240320183709272](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240320183709272.png) 

### 2.实现Runnable接口的方式进行实现

#### How to do

> + 创建一个实现了 `Runnable` 接口的类，并重写 `run()` 方法来**定义线程的任务。**
> + 然后将该实现了 `Runnable` 接口的**类的实例****作为参数传递给 `Thread` 类的构造函数**来创建线程，并调用 `start()` 方法来启动线程。
>
> 只创建一次

#### MyThread.java

```java
package org.example1;

public class MyThread implements Runnable{

    private String work;

    public MyThread(String work) {
        this.work = work;
    }

    @Override
    public void run() {
        for(int i=0;i<10;i++)
        {
            System.out.println("正在"+work);
        }
    }
}

```



#### Main.java

```java
package org.example1;

public class Main {
    public static void main(String[] args) {

        MyThread myThread1=new MyThread("吃饭，线程1");
        MyThread myThread2=new MyThread("带小孩，线程2");

        Thread thread1=new Thread(myThread1);
        Thread thread2=new Thread(myThread2);

        thread1.start();
        thread2.start();
    }
}

```



#### 效果

![image-20240320184512954](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240320184512954.png) 

#### ---------------

#### Main.java

![image-20240320185346002](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240320185346002.png) 

```java
package org.example1;

public class Main {
    public static void main(String[] args) {

        MyThread myThread1=new MyThread("吃饭");
        MyThread myThread2=new MyThread("吃饭");



        //创建两个线程
        Thread thread1=new Thread(myThread1,"线程1");
        Thread thread2=new Thread(myThread2,"线程2");
//
//        thread1.setName("线程1");
//        thread1.setName("线程2");



        thread1.start();
        thread2.start();
    }
}

```





#### MyThread.java

```java
package org.example1;

public class MyThread implements Runnable{

    private String work;

    public MyThread(String work) {
        this.work = work;
    }

    @Override
    public void run() {
        Thread currentThread=Thread.currentThread();
        //获取当前进程
        for(int i=0;i<10;i++)
        {
            System.out.println("正在"+currentThread.getName());
//            System.out.println("正在"+Thread.currentThread().getName());
        }
    }
}

```



#### 效果

 ![image-20240321220454045](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240321220454045.png) 

### 3.利用Callable接口和Futrue接口方式实现

特点：可以获取多线程运行的结果

#### How to do

> 使用`Callable`接口和`Future`接口来实现多线程。
>
> `Callable`接口类似于`Runnable`接口，重写call方法定义线程的任务
>
> 但是它可以返回结果并且可以抛出异常。
> `Future`接口用于表示异步计算的结果，可以通过它来获取`Callable`的返回值。具体使用要用**FutureTask实现类**

#### MyCallable.java

```java
package org.example2;

import java.util.concurrent.Callable;

public class MyCallaable implements Callable<Integer> {
    //泛型里面是返回的结果
    String work;

    public MyCallaable(String work) {
        this.work = work;
    }

    @Override
    public Integer call() throws Exception {

        int sum=0;
        for (int i = 0; i < 100; i++) {
            sum+=i;
            System.out.println(work+Thread.currentThread().getName());
        }
        return sum;
    }
}

```

Main.java

```java
package org.example2;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.FutureTask;

public class Main {
    public static void main(String[] args) throws ExecutionException, InterruptedException {

//        创建Mycallable对象,,表示多线程要处理的任务
        MyCallaable myCallaable1=new MyCallaable("吃饭");
        MyCallaable myCallaable2=new MyCallaable("睡觉");

        //Future对象管理多线程运行 的结果
        FutureTask<Integer> future1=new FutureTask<>(myCallaable1);
        FutureTask<Integer> future2=new FutureTask<>(myCallaable2);

        Thread thread1=new Thread(future1,"1");
        Thread thread2=new Thread(future2,"2");

        thread1.start();
        thread2.start();

        int result=future1.get();
        System.out.println(result);



    }
}

```

效果

![image-20240321220518793](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240321220518793.png)  





### 三种方法 的区别

![image-20240321220850500](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240321220850500.png) 

因为java只有单继承，所以第一种有一定的缺点

> 三种在Java中实现多线程的不同方式，它们分别继承自不同的基类或接口。下面是它们之间的区别：
>
> 1. **继承Thread类的方式进行实现：**
>    - 这种方式直接继承`Thread`类，**覆盖其中的`run()`方法来定义线程的任务**。
>    - 优点是简单直接，可以通过继承和重写来实现多线程。
>    - 缺点是由于Java是单继承的，如果一个类已经继承了其他类，则无法再通过继承`Thread`类来实现多线程，限制了代码的灵活性。
>
> 2. **实现Runnable接口的方式进行实现：**
>    - 这种方式实现了`Runnable`接口，并将其作为参数传递给`Thread`类的构造函数，然后通过`Thread`对象来启动线程。
>    - **优点是**避免了单继承的限制，因为**Java允许类实现多个接口**，因此可以灵活地将多线程逻辑和业务逻辑分离。
>    - 缺点是**需要在类中实现`run()`方法**，这可能使代码稍微复杂一些。
>
> 3. **利用Callable接口和Future接口方式实现：**
>    - 这种方式是使用`Callable`接口和`Future`接口，`Callable`接口类似于`Runnable`接口，但是可以返回结果并且可以抛出异常，**`Future`接口用于表示异步计算的结果**。
>    - 优点是可以获得任务的返回结果，还可以捕获任务抛出的异常，这在某些情况下很有用。
>    - 缺点是相对于前两种方式，代码相对复杂一些，需要处理异常以及使用`Future`对象来获取结果。
>
> 如果只是简单的多线程任务，继承`Thread`类或者实现`Runnable`接口都是不错的选择。
>
> 如果需要**获取任务的返回结果或者处理异常**，可以考虑使用`Callable`接口和`Future`接口。
>
> ---
>
> 更好的是第二种！





## 多线程中常见的成员方法

### 概括

| 方法名称                            | 说明                                    |
| ----------------------------------- | --------------------------------------- |
| `String getName()`                  | 返回此线程的名称                        |
| `void setName(String name)`         | 设置线程的名字 (构造方法也可以设置名字) |
| `static Thread currentThread()`     | 获取当前线程的对象                      |
| `static void sleep(long time)`      | 让线程休眠指定的时间，单位为毫秒        |
| `void setPriority(int newPriority)` | 设置线程的优先级                        |
| `final int getPriority()`           | 获取线程的优先级                        |
| `final void setDaemon(boolean on)`  | 设置为守护线程                          |
| `public static void yield()`        | 出让线程/礼让线程                       |
| `public static void join()`         | 插入线程/插队线程                       |

### String getName()

> `String getName()` 方法用于获取当前线程的名称。线程名称是一个字符串，用于标识线程。

#### 方法一

Main.java

```java
package test.example;

public class Main {
    public static void main(String[] args) {


        // 创建并启动第一个线程
        MyThread myThread1 = new MyThread("唱歌,线程1");
        myThread1.start();


        // 创建并启动第二个线程
        MyThread myThread2 = new MyThread("跳舞，线程2");
        myThread2.start();
    }
}

```

#### MyThread

```java
package test.example;

public class MyThread extends Thread{
    private String work;

    public MyThread(String work) {
        this.work = work;
    }

    @Override
    public void run() {
        for(int i=0;i<10;i++)
        {
            System.out.println("我在"+"@"+this.getName());
        }

    }
}

```

#### 测试效果

![image-20240417105814739](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240417105814739.png) 

#### 线程有默认的名字吗?

线程的默认名称是由系统自动分配的，通常采用类似 "Thread-N" 的格式，其中 N 是一个递增的数字。例如，第一个线程的默认名称可能是 "Thread-0"，第二个线程是 "Thread-1"，依此类推。 

### void setName(String name)

CTRL+F12查找方法

CTRL+N查找类

![image-20240417110944191](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240417110944191.png) 

》》》构造方法和setname方法

#### Main.java

```java
package test.example;

public class Main {
    public static void main(String[] args) {


        // 创建并启动第一个线程
        MyThread myThread1 = new MyThread("线程1","唱歌");
//        myThread1.setName("线程1");
        myThread1.start();


        // 创建并启动第二个线程
        MyThread myThread2 = new MyThread("线程2","跳舞");
//        myThread2.setName("线程2");
        myThread2.start();

    }
}

```

#### MyThread.java

```java
package test.example;

public class MyThread extends Thread{
    private String work;

    public MyThread(String work) {
        this.work = work;
    }

    public MyThread(String name, String work) {
        super(name);
        this.work = work;
    }

    @Override
    public void run() {
        for(int i=0;i<10;i++)
        {
            System.out.println("我在"+work+"@"+this.getName());
        }

    }
}

```

#### 测试效果

![image-20240417111343828](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240417111343828.png) 



### static Thread currentThread()

> `static Thread currentThread()` 方法是 `Thread` 类的一个静态方法
>
> 用于**获取当前正在执行的线程对象**。调用这个方法将返回一个 `Thread` 对象，该对象表示当前正在执行的线程。
>
> 这个方法通常用于获取当前线程的引用，以便进行一些与线程相关的操作，例如获取线程的名称、优先级等信息，或者在多线程程序中对当前线程进行操作和管理。

#### MyThread.java

```java
package test.example;

public class MyThread extends Thread{
    private String work;

    public MyThread(String work) {
        this.work = work;
    }

    public MyThread(String name, String work) {
        super(name);
        this.work = work;
    }

    @Override
    public void run() {
        Thread thread=Thread.currentThread();
        for(int i=0;i<10;i++)
        {
            System.out.println("我在"+work+thread.getName());
        }

    }
}

```

Maikn.java

```java
package test.example;

public class Main {
    public static void main(String[] args) {


        // 创建并启动第一个线程
        MyThread myThread1 = new MyThread("线程1","唱歌");
//        myThread1.setName("线程1");
        myThread1.start();


        // 创建并启动第二个线程
        MyThread myThread2 = new MyThread("线程2","跳舞");
//        myThread2.setName("线程2");
        myThread2.start();

        System.out.println("当前线程是"+Thread.currentThread().getName());

    }
}

```

#### 测试效果

![image-20240417111643897](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240417111643897.png) 

### static void sleep(long time)

> `static void sleep(long time)` 方法是 `Thread` 类的一个静态方法
>
> 用于让**当前线程休眠指定的时间长度**。调用这个方法将**使当前线程**进入休眠状态，暂时停止执行，直到指定的时间过去或者被其他线程中断。
>
> 以下是关于 `sleep(long time)` 方法的一些细节：
>
> - 参数：接受一个 long 类型的参数 `time`，表示线程将要休眠的时间长度，单位为毫秒。
> - 异常：这个方法会抛出 `InterruptedException` 异常，当当前线程在睡眠期间被其他线程中断时抛出。因此，在调用 `sleep()` 方法时需要处理该异常或者将其抛出。
> - 静态方法：`sleep(long time)` 是一个静态方法，因此可以直接通过类名 `Thread` 调用，而不需要创建 `Thread` 对象。
> - 用途：通常用于控制线程的执行顺序、模拟并发执行、实现定时任务等场景。



#### MyThread.java

```java
package test.example;

public class MyThread extends Thread{
    private String work;

    public MyThread(String work) {
        this.work = work;
    }

    public MyThread(String name, String work) {
        super(name);
        this.work = work;
    }

    @Override
    public void run() {
        Thread thread=Thread.currentThread();

        for(int i=0;i<10;i++)
        {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            System.out.println("我在"+work+thread.getName());
        }

    }
}

```

#### Main.java

```java
package test.example;

public class Main {
    public static void main(String[] args) throws InterruptedException {


//        Thread.sleep(5000);

        // 创建并启动第一个线程
        MyThread myThread1 = new MyThread("线程1","唱歌");
//        myThread1.setName("线程1");
        myThread1.start();


        // 创建并启动第二个线程
        MyThread myThread2 = new MyThread("线程2","跳舞");
//        myThread2.setName("线程2");
        myThread2.start();

        System.out.println("当前线程是"+Thread.currentThread().getName());


    }
}

```

#### 测试效果

![PixPin04-17_11-22-59](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/PixPin04-17_11-22-59.gif)





## 线程的优先级

### 概括

> 1. **优先级范围**：
>    - 线程的优先级范围通常是从 1 到 10，其中 1 是最低优先级，10 是最高优先级。默认是5
>    - Java 虚拟机中，优先级被分为三个级别：最低、普通和最高，对应的数值分别是 1、5 和 10。
> 2. **优先级的设置**：
>    - 在 Java 中，可以使用 `setPriority(int newPriority)` 方法设置线程的优先级。传递给 `setPriority()` 方法的参数应该在合法范围内，即 1 到 10。
>    - 默认情况下，线程的优先级为普通优先级，即 5。
> 3. **优先级调度**：
>    - 线程的优先级可以**影响线程在竞争CPU资源时的执行顺序**，但**并不保证绝对的执行顺序。**
>    - **高优先级的线程通常会在低优先级线程之前执行，但调度程序可能会根据具体情况进行调整。**
>    - 调度程序可能会考虑线程的状态、调度策略等因素来决定线程的执行顺序。

### 线程的调度

#### 抢占式调度

> 抢占式调度是指
>
> 操作系统或者Java虚拟机可以**随时**中断当前正在执行的线程，并将CPU控制权交给优先级更高的线程。
>
> 这种调度方式确保了高优先级任务能够及时执行，适用于对响应时间要求高的系统。

随机，抢夺CPU的执行权



#### 非抢占式调度

> 非抢占式调度是指
>
> 线程**只有在主动放弃CPU控制权或者自然结束时**，才会释放CPU资源给其他线程。
>
> 在这种调度方式下，线程的执行由线程本身决定，调度程序不会中断正在执行的线程。这种方式更简单且消耗更少的系统资源，适用于一般的多线程应用程序。

优先级高的执行，轮流执行。





### 优先级

### setPriority&&getPriority

#### MyThread.java

```java
package test.example;

public class MyThread extends Thread{
    private String work;

    public MyThread(String work) {
        this.work = work;
    }

    public MyThread(String name, String work) {
        super(name);
        this.work = work;
    }

    @Override
    public void run() {
        Thread thread=Thread.currentThread();

        for(int i=0;i<10;i++)
        {
            System.out.println("我在"+work+thread.getName());
        }

    }
}

```



#### Main.java

```java
package test.example;

public class Main {
    public static void main(String[] args) throws InterruptedException {


//        Thread.sleep(5000);

        // 创建并启动第一个线程
        MyThread myThread1 = new MyThread("线程1","唱歌");
//        myThread1.setName("线程1");
        myThread1.start();
        myThread1.setPriority(10);


        // 创建并启动第二个线程
        MyThread myThread2 = new MyThread("线程2","跳舞");
//        myThread2.setName("线程2");
        myThread2.start();

        System.out.println("线程1 的优先级是"+myThread1.getPriority());
        System.out.println("线程2 的优先级是"+myThread2.getPriority());
        System.out.println("当前线程的优先级是+"+Thread.currentThread().getPriority());


    }
}

```

#### 测试代码

![image-20240417222941634](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240417222941634.png) 

> 优先级越高只能证明抢到CPU的概率高!=100%抢到CPU的执行权
>
> 现在线程1 的优先级高了
>
> 但是并不说明谁先运行完，只是概率问题



## 守护线程

### 什么是守护线程

又叫备胎线程

女神(非守护)线程结束后，(守护线程)备胎也就没有必要了

> 守护线程（Daemon Thread）是一种在后台提供服务的线程，它的存在并不会阻止程序的终止。
>
> 当所有的**非守护线程结束时，守护线程会自动终止**，**即使它们正在执行某些操作**。
>
> 它们通常被用于执行一些后台任务，如垃圾回收等。

![image-20240417224447125](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240417224447125.png) 

### final void setDaemon(boolean on)

> 注意下set后开启线程
>
> - 参数 `on`：接受一个布尔值参数，如果传入 `true`，则将线程设置为守护线程；
>
>   如果传入 `false`，则将线程设置为用户线程（非守护线程）。
>
> - 守护线程特性：当一个线程被设置为守护线程时，它的存在不会阻止程序的终止。当所有的非守护线程结束时，守护线程会自动终止，即使它们正在执行某些操作。
>
> - 调用时机：通常在启动线程之前调用 `setDaemon(true)` 方法将线程设置为守护线程。
>
> - 注意事项：
>
>   - 必须在**启动线程之前**调用 `setDaemon(boolean on)` 方法，否则会抛出 `IllegalThreadStateException` 异常。
>   - 守护线程应该谨慎使用，因为它们可能会在程序终止时被强制终止，而且不能保证它们的执行顺序和行为。

#### Main.java

```java
package test.example;

public class Main {
    public static void main(String[] args) throws InterruptedException {


//        Thread.sleep(5000);

        // 创建并启动第一个线程
        MyThread myThread1 = new MyThread("线程1","唱歌");
        myThread1.start();


        // 创建并启动第二个线程
        MyThread myThread2 = new MyThread("线程2","跳舞");
        myThread2.setDaemon(true);
        myThread2.start();




    }
}
```

#### MyThred.java

```java
package test.example;

public class MyThread extends Thread{
    private String work;

    public MyThread(String work) {
        this.work = work;
    }

    public MyThread(String name, String work) {
        super(name);
        this.work = work;
    }

    @Override
    public void run() {
        Thread thread=Thread.currentThread();

        for(int i=0;i<10;i++)
        {
            System.out.println("我在"+work+thread.getName()+"循环:"+i);
        }

    }
}

```



#### 代码效果

![image-20240417225159603](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240417225159603.png) 







## 礼让线程

### 什么是礼让线程？

> 礼让线程是指当前正在执行的线程**主动让出CPU资源**，以便其他线程有机会执行。
>
> 调用线程的 `yield()` 方法可以**实现线程的礼让。**
>
> 礼让线程的作用是告诉调度程序**当前线程没有更重要的任务要执行**，可以将CPU资源分配给其他线程。
>
> 但是，调度程序可能会选择继续执行当前线程，也可能选择执行其他线程，具体取决于调度程序的策略。
>
> 调用 `yield()` 方法不会导致线程阻塞，而是使当前线程进入就绪状态，**重新竞争CPU资源**。
>
> 因此，它只是一种提示，而不是强制性的要求。

### public static void yield()

> - 作用：`yield()` 方法的作用是**告诉调度器当前线程没有更重要的任务要执行，可以让其他线程有机会执行。**
> - 不保证生效：调用 `yield()` 方法**不会保证当前线程立即让出CPU资源**，具体的行为取决于操作系统和Java虚拟机的调度策略。
> - 静态方法：`yield()` 方法是一个**静态方法**，因此可以直接**通过类名** `Thread.yield()` 调用。
> - 使用建议：`yield()` 方法应该谨慎使用，因为它仅是一种提示，而不是强制性的要求。过度使用 `yield()` 可能会导致线程调度的不稳定性，影响程序的性能和可预测性。

原本线程1和线程2交织执行，很乱

有了礼让线程，会让分布均匀一点，但是不是一定，因为只是让出，重新抢CPU的时候还可以抢到

#### MyThread.java

```java
package lirangxiancheng;

public class MyThread extends Thread{
    private String work;

    public MyThread(String work) {
        this.work = work;
    }

    public MyThread(String name, String work) {
        super(name);
        this.work = work;
    }

    @Override
    public void run() {
        Thread thread=Thread.currentThread();

        for(int i=0;i<10;i++)
        {
            System.out.println("我在"+work+thread.getName());
        }

    }
}

```



#### MyThread1.java

```java
package lirangxiancheng;

public class MyThread1 extends Thread{
    private String work;

    public MyThread1(String work) {
        this.work = work;
    }

    public MyThread1(String name, String work) {
        super(name);
        this.work = work;
    }

    @Override
    public void run() {
        Thread thread=Thread.currentThread();

        for(int i=0;i<10;i++)
        {
            Thread.yield();
            //主动让出CPU
            System.out.println("我在"+work+thread.getName());
        }

    }
}

```

#### Main.java

```java
package lirangxiancheng;

public class Main {
    public static void main(String[] args) throws InterruptedException {


//        Thread.sleep(5000);

        // 创建并启动第一个线程
        MyThread myThread1 = new MyThread("线程1","唱歌");
        Thread.yield();
        myThread1.start();


        // 创建并启动第二个线程
        MyThread1 myThread2 = new MyThread1("线程2","跳舞");
        myThread2.start();




    }
}

```

![image-20240417230032242](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240417230032242.png) 





## 插入线程

### 什么是插入线程？





### public static void join()

##### Main.java

```java
package charuxiancheng;

public class Main {
    public static void main(String[] args) throws InterruptedException {


//        Thread.sleep(5000);

        // 创建并启动第一个线程
        MyThread myThread = new MyThread();
        myThread.setName("土豆");
        myThread.start();

        myThread.join();

        for(int i=0;i<10 ;i++)
        {
            System.out.println("主线程的"+i);
        }



    }
}

```

##### MyThread.java

```java
package charuxiancheng;

public class MyThread extends Thread{

    @Override
    public void run() {
        Thread thread=Thread.currentThread();

        for(int i=0;i<10;i++)
        {
            System.out.println("我在"+thread.getName()+"循环:"+i);
        }

    }
}

```

不加` myThread.join();`

![image-20240417231351094](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240417231351094.png) 

> 由于线程是并发执行的，因此主线程和 `MyThread` 线程的任务可能交错执行，具体执行顺序取决于系统的调度策略。
>
> 但通常情况下，主线程会先执行，因为它是通过 `main` 方法启动的，并且在启动 `MyThread` 线程之前执行。

加入` myThread.join();`

![image-20240417231336754](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240417231336754.png) 

> 主线程在启动 `MyThread` 线程后立即调用了 `myThread.join()` 方法。
>
> `join()` 方法的作用是让**主线程等待 `MyThread` 线程执行完毕，然后再继续执行主线程的任务**。
>
> 因此，主线程会启动并等待 `MyThread` 线程执行完毕，然后再执行自己的任务。所以，虽然主线程和 `MyThread` 线程都是并发执行的，但主线程会在等待 `MyThread` 线程执行完毕后再继续执行自己的任务。
>
> 因为 `join()` 方法会阻塞主线程，直到目标线程执行完毕







## 线程生命周期

![image-20240424105708221](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240424105708221.png) 

> 1. **创建（Creation）**：线程被创建时，系统分配必要的资源，并为其分配一个唯一的标识符。在这个阶段，线程还未开始执行，**只是存在于系统中。**
> 2. **就绪（Ready）**：线程进入就绪状态意味着它已经准备好执行，但是**尚未获得 CPU 时间片来执行**。当线程处于就绪状态时，它**等待操作系统调度来分配 CPU 时间片。**
> 3. **运行（Running）**：一旦线程被调度并获得 CPU 时间片，它就会进入运行状态，开始执行其任务。在线程运行时，它会使用 CPU 执行其代码，并在需要时访问系统资源。
> 4. **阻塞（Blocked）**：在某些情况下，线程可能会被阻塞，**无法继续执行**。这可能是由于等待外部事件的发生，如 I/O 操作、锁或信号量的获取等。当线程处于阻塞状态时，它会暂停执行，直到满足特定条件，然后**重新转换为就绪状态**。
> 5. **终止（Termination）**：线程的生命周期最终会结束，通常是因为它完成了其任务、显式终止请求或发生了无法恢复的错误。在线程终止时，它会**释放所占用的资源，并从系统中移除**。

![image-20240426083207858](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240426083207858.png) 

但是只有六种

没有运行状态，是因为线程抢夺到cpu执行权就把线程的执行权给操作系统了。

![image-20240426083356422](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240426083356422.png) 

## 同步代码块

### 什么是同步代码块

> 多线程环境中**访问共享资源时保持线程安全的机制**。
>
> 在同步代码块中，**只有一个线程可以同时访问被同步的代码块**，其他线程必须等待直到当前线程执行完毕。
>
> 1. **锁对象（Lock Object）**：同步代码块使用**锁对象**来**确保只有一个线程可以进入被同步的代码块**。锁对象可以是任何对象，通常是一个共享资源或特定的对象。
>
> 2. **锁定（Locking）**：当一个线程进入同步代码块时，它会尝试获取锁对象的锁。如果锁对象的锁已经被其他线程获取，那么当前线程会被阻塞，直到锁对象的锁被释放。
>
> 3. **执行代码块（Executing the Code Block）**：一旦线程获得了锁对象的锁，它就可以执行同步代码块中的代码。在这个阶段，只有这个线程可以访问同步代码块中的代码，其他线程被阻塞。
>
> 4. **释放锁（Releasing the Lock）**：当线程执行完同步代码块中的代码后，它会释放锁对象的锁。这样，其他线程就有机会获取锁对象的锁，并进入同步代码块。
>
> 5. **线程安全性（Thread Safety）**：同步代码块的主要目的是确保在多线程环境中对共享资源的访问是安全的。通过在关键部分使用同步代码块，可以避免竞态条件和数据不一致等并发问题。
>
> 6. **范围（Scope）**：同步代码块应该尽可能小而**精确地包围需要同步的代码**。这样可以最大程度地减小锁的持有时间，提高程序的并发性能。
>
> 7. **性能影响（Performance Impact）**：过多地使用同步代码块可能会导致性能问题，因为它们会引入线程间的竞争和等待。因此，在设计同步代码块时需要权衡代码的并发性和性能。
>

> 线程执行时，有随机性，任何时候cpu执行权都可能被抢走

### 电影院卖票问题

#### Main.java

```java
package dianyingyuan;

public class Main {
    public static void main(String[] args) {


        MyThread thread1=new MyThread();
        MyThread thread2=new MyThread();
        MyThread thread3=new MyThread();


        thread1.setName("窗口1");
        thread2.setName("窗口2");
        thread3.setName("窗口3");


        thread1.start();
        thread2.start();
        thread3.start();

    }
}

```

#### MyThread.java

```java
package dianyingyuan;

public class MyThread extends Thread{

    static int ticket=0;
    //也得是静态u

    static Object object=new Object();
    //必须是static的！！！
    @Override
    public void run() {
        while (true)
        {
            //同步代码块
            //（）里面的对象很随意，随意到任意一个对象都ok，但是必须是static的！！！
            //一般写MyThread.class
            synchronized (object)
            {
                if(ticket<100)
                {
                    try {
                        Thread.sleep(10);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                    ticket++;
                    System.out.println(this.getName()+"正在卖第"+ticket+"张电影票");
                }
                else
                {
                    break;
                }
            }
        }
    }
}

```

解决问题，把操作数据这段代码锁起来，然后一个线程一个线程进。

```c
synchronized(锁){
	操作共享数据的代码
}
```

#### 运行效果

![image-20240424112056549](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240424112056549.png) 

> 锁默认是打开的，有一个线程进入，锁会自动关闭
>
> 里面的代码全部执行完毕，线程出来，锁会自动打开
>
> 或许前者仍然会抢到cpu执行的机会然后再执行。





### 同步代码块的细节

#### 问题1

synchronized的位置在while外面会怎么样？

会只有一个线程卖票

因为只要有一个线程进去就等他执行完了才会让其他线程进入。

#### 问题2

synchronized（）的锁对象不唯一会怎么样呢？

> 锁对象不唯一synchronized白写
>
> 线程123，对应着不同的锁。。。
>
> **一般会直接写当前类的字节码文件！！！**



### 同步方法

> 上面是锁代码，如果我们要**锁一个方法的所有代码**，那就把关键字加在方法的修饰符的后面
>
> 1. 同步方法是所著方法里的所有代码
> 2. 现在锁对象**不能自己指定**
>    1. 如果是静态方法，那么就是**当前类的字节码文件对象**
>    2. 非静态**this**

可以先写原始的然后提取为抽象方法，，，

![image-20240424114854055](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240424114854055.png) 

#### Main.java

```java
package tongbufangfa;

public class Main {
    public static void main(String[] args) {

        MyThread myThread=new MyThread();


        Thread thread1=new Thread(myThread);
        Thread thread2=new Thread(myThread);
        Thread thread3=new Thread(myThread);

        thread1.setName("窗口1");
        thread2.setName("窗口2");
        thread3.setName("窗口3");

        thread1.start();
        thread2.start();
        thread3.start();
    }
}

```

#### MyThread.java

```java
package tongbufangfa;

public class MyThread implements Runnable{
    static int ticket=0;
    //可以是非静态的

    @Override
    public void run() {
        while (true) {
            //2同步代码块
            if (method()) break;
        }
    }

    private synchronized boolean method() {
            if (ticket < 100) {
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                ticket++;
                System.out.println(Thread.currentThread().getName() + "正在卖第" + ticket + "张票");
            } else {
                //判断空想数据是否到了末尾
                return true;
            }
        return false;
    }

}

```

#### 代码效果

![image-20240424221410027](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240424221410027.png) 

> ticket必须是静态的吗，nonono，因为是作为参数传入了，不是第一种那样公用类的变量
>
> 只创建了一个 `MyThread` 实例，无论 `ticket` 是静态的还是实例的，三个线程都将影响同一个 `ticket`。



### 字符串StringBuffer和StringBuilder

> 1. **StringBuffer**:
>    - `StringBuffer` 是线程安全的，适合在多线程环境中使用。
>    - 所有的 `StringBuffer` 方法都是**同步**的，这意味着在进行修改操作时，`StringBuffer` 会使用 `synchronized` 关键字进行同步，保证了线程安全性。
>    - 由于需要进行同步处理，`StringBuffer` 的性能相对较差，因此在单线程环境下不太推荐使用。
> 2. **StringBuilder**:
>    - `StringBuilder` 是**非线程安全**的，适合在**单线程环境中使用**。
>    - `StringBuilder` 的方法没有同步，因此在单线程环境中速度更快。
>    - 由于没有同步处理，`StringBuilder` 不保证线程安全性，如果在多线程环境中使用，可能会导致数据不一致或其他问题。





### lock锁

> 锁的开关都是自动化的，线程执行完毕，自动开锁，线程进入自动锁住

或许我们可以手动的操作锁？

虽然我们可以理解同步代码块和同步方法的锁对象问题，

但是我们并没有直接看到在哪里加上了锁，在哪里释放了锁，

为了更清晰的表达如何加锁和释放锁，JDK5以后提供了一个新的锁对象Lock

Lock实现提供比使用synchronized方法和语句可以获得更广泛的锁定操作

Lock中提供了获得锁和释放锁的方法

`void lock()`：获得锁

==手动上锁、手动释放锁==

`voidunlock()`：释放锁

**Lock是接口不能直接实例化**这里采用它的**实现类ReentrantLock来实例化**

**ReentrantLock的构造方法ReentrantLock()：创建一个ReentrantLock的实例**

![image-20240424223210630](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240424223210630.png) 

```java
package dianyingyuan;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class MyThread extends Thread{

    static int ticket=0;
    //需要是静态的，这样保证是同一把锁
     static Lock lock=new ReentrantLock();
    //

    static Object object=new Object();
    //必须是static的！！！
    @Override
    public void run() {
        while (true)
        {
            lock.lock();
            try {
                if(ticket<100)
                {
                    try {
                        Thread.sleep(10);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                    ticket++;
                    System.out.println(this.getName()+"正在卖第"+ticket+"张电影票");
                }
                else
                {
                    break;
                }
            } finally {
                //一定要去执行开锁的过程.
                //算是扫尾的代码
                lock.unlock();
            }
        }
    }
}

```

> `lock.lock()` 用于**获取锁**，确保**只有一个线程能够执行临界区的代码**，而**其他线程需要等待直到锁被释放**。`lock.unlock()` 则用于**释放锁**，以**允许其他线程获取锁继续执行**。
>
> >  `try-finally` 块中使用 `lock.unlock()` 确保无论临界区代码是否出现异常，锁都会被释放。这样可以防止发生**死锁**等问题。

### 死锁

> 1. 锁的嵌套
> 2. 死锁是一个错误！



---

> 死锁：**指两个或多个线程互相等待对方释放资源而无法继续执行的情况**。
>
> 在死锁中，每个线程都在等待另一个线程释放资源，而导致所有线程都无法继续执行，最终导致程序无法完成任务。
>
> ---
>
> 死锁是指两个或多个线程互相卡住，因为**它们在等待彼此释放资源**，但又无法继续执行。这就像两个人都拿着对方需要的东西，却不肯把自己手中的东西放下，导致彼此都无法前进的情况。
>
> 举个例子：假设有两个线程 A 和 B，A 持有资源 X，同时想要资源 Y；而 B 持有资源 Y，同时想要资源 X。那么，A 就在等待 B 释放资源 Y，而 B 又在等待 A 释放资源 X。由于彼此都在等待对方释放资源，它们就会一直卡住，无法继续执行，这就是死锁。







## 生产者和消费者

也就是等待唤醒机制

> 多线程中的生产者-消费者问题是一个经典的**同步问题**，
>
> 通常用于演示多线程环境下如何协调线程之间的操作。在这个问题中，有一个**共享的缓冲区（或队列）**
>
> 生产者线程**向缓冲区中放入数据**（生产）
>
> 而消费者线程则**从缓冲区中取出数据**（消费）。
>
> **生产者和消费者线程之间需要进行同步**，以确保缓冲区的**数据一致性**和避免竞争条件（race condition）。

![image-20240425225805291](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240425225805291.png) 

| 方法名称           | 说明                               |
| ------------------ | ---------------------------------- |
| `void wait()`      | 当前线程等待，直到被其他线程唤醒。 |
| `void notify()`    | **随机唤醒单个线程。**             |
| `void notifyAll()` | **唤醒所有正在等待的线程。**       |

### 第一种实现

#### Cook.java

```java
package shengchanzhehexiaofeizhe;

public class Cook extends  Thread{
    @Override
    public void run() {
        while (true)
        {
            synchronized (Desk.lock)
            {
                if(Desk.count==0)
                {
                    break;
                }
                else
                {
                    if(Desk.flag==0)//说明没有饭
                    {
                        System.out.println("厨师做饭");
                        Desk.flag=1;
                        Desk.lock.notifyAll();
                    }
                    else//说明有饭
                    {
                        try {
                            Desk.lock.wait();
                        } catch (InterruptedException e) {
                            throw new RuntimeException(e);
                        }
                    }
                }



            }
        }
    }
}

```

#### Dest.java

```java
package shengchanzhehexiaofeizhe;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Desk {
    public static int flag=0;
    //0代表没有面条
    //1代表有
    public static int count=10;

    public static Lock lock=new ReentrantLock();

//控制两条线程用boolean，多条线程y用int


}

```

#### Foodie.java

```java
package shengchanzhehexiaofeizhe;

public class Foodie extends Thread{
    @Override
    public void run() {

        while(true)
        {
            synchronized (Desk.lock)
            {
                if(Desk.count!=0)
                {
                    if(Desk.flag==1)
                    {
                        Desk.count--;
                        System.out.println("吃货正在吃"+"还能吃"+Desk.count+"碗！");

                        Desk.lock.notifyAll();

                        Desk.flag=0;

                    }
                    else
                    {
                        try {
                            Desk.lock.wait();
                        } catch (InterruptedException e) {
                            throw new RuntimeException(e);
                        }

                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
}

```

#### Main.java

```java
package shengchanzhehexiaofeizhe;

public class Main {
    public static void main(String[] args) {

        Cook cook=new Cook();

        Foodie foodie=new Foodie();

        cook.setName("厨师");
        foodie.setName("吃货");


        cook.start();
        foodie.start();
    }
}

```

#### 代码效果

![image-20240425231931053](java%E5%A4%9A%E7%BA%BF%E7%A8%8B/image-20240425231931053.png) 

而且正常结束





### 阻塞队列的继承结构

> 因为queue里面的方法是带锁的，若此线程还没被唤醒，那么就会反复执行wait直到被唤醒，此时打印语句无论是wait还是notify都会执行一次，而我们只需要notify的时候才需要打印

阻塞队列是一种特殊类型的队列，它**支持在队列为空时进行获取元素的线程阻塞**，或者在**队列已满时进行插入元素的线程阻塞**。在Java中，阻塞队列通常通过接口和其实现类的方式来使用。

Java中常见的阻塞队列接口是 `java.util.concurrent.BlockingQueue`，它定义了阻塞队列的基本操作，如插入、移除元素以及检索队列的头部元素等。常用的实现类有 `ArrayBlockingQueue`、`LinkedBlockingQueue`、`PriorityBlockingQueue`、`DelayQueue` 等。

#### Cook.java

```java
package zuseduilie;

import java.util.concurrent.ArrayBlockingQueue;

public class Cook extends  Thread{
   ArrayBlockingQueue queue;

    public Cook(ArrayBlockingQueue queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        while(true)
        {

            try {
                queue.put("面条");
                System.out.println("厨师做了一碗面条");
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }

        }
    }
}

```

#### Foodie.java

```java
package zuseduilie;

import java.util.concurrent.ArrayBlockingQueue;

public class Foodie extends Thread{
    ArrayBlockingQueue queue;

    public Foodie(ArrayBlockingQueue queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        while (true)
        {
            try {
                queue.take();
                System.out.println("吃货吃了一盘");
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}

```

#### Main.java

```java
package zuseduilie;

import java.util.concurrent.ArrayBlockingQueue;

public class Main {
    public static void main(String[] args) {

        ArrayBlockingQueue<String> queue=new ArrayBlockingQueue<>(1);


        Cook cook=new Cook(queue);
        Foodie foodie=new Foodie(queue);

        
        cook.setName("厨师");
        foodie.setName("吃货");

        cook.start();
        foodie.start();

    }
}

```

封装了常见的线程安全操作，使得在编写多线程程序时可以更加方便和安全。

> 1. 由于 `ArrayBlockingQueue` 是一个有界阻塞队列，所以在这里队列的容量设置为1，当生产者向队列中放入数据时，如果队列已满，则生产者线程会被阻塞，直到有消费者取走数据为止；同样，当消费者试图从空队列中取出数据时，消费者线程也会被阻塞，直到有生产者放入数据为止。







## 作业
