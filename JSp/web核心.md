# HTTP，TomCat，Servelet

![image-20231228162222816](web核心/image-20231228162222816.png) 

## 导言

Web：全球广域网，也称为万维网(www)，能够通过浏览器访问的网站

JavaWeb：是用Java技术来解决相关web互联网领域的技术栈

## 了解一下javaweb技术栈

B/S架构：Browser/Server，浏览器/服务器架构模式，它的特点是，客户端只需要浏览器，应用程序的逻辑和数据都存储在服务器端。浏览器只需要请求服务器，获取Web资源，服务器把Web资源发送给浏览器即可

==好处：易于维护升级：服务器端升级后，客户端无需任何部署就可以使用到新的版本==

服务器的升级。。。客户端只管使用就ok了

![image-20231228161933467](web核心/image-20231228161933467.png) 

+ 静态资源：HTML,CSS,JavaScript;

  三剑客

+ 动态资源 Servlet和JSp，负责逻辑处理，实现不同用户登录实现不同的效果

+ 数据库：存储数据

## HTTP

+ 概念：HyperText TransferProtocol，超文本传输协议，规定了浏览器和服务器之间数据传输的规则

![image-20231228162506576](web核心/image-20231228162506576.png) 

HTTP特点：![image-20231228162558208](web核心/image-20231228162558208.png) 

## 请求数据的格式

![image-20231228162929597](web核心/image-20231228162929597.png)

![image-20231228162956008](web核心/image-20231228162956008.png)  

![image-20231228162454339](web核心/image-20231228162454339.png) 

![image-20231228163121581](web核心/image-20231228163121581.png) 

![image-20231228163123741](web核心/image-20231228163123741.png) 





## 响应数据的格式

![image-20231228163704916](web核心/image-20231228163704916.png) 

## 响应状态码

> HTTP协议中定义了一系列的状态码（Status Code），用于表示服务器对请求的处理结果。以下是一些常见的HTTP响应状态码：
>
> - **1xx（信息性状态码）：**
>   - 100 Continue：继续。表示服务器已经接收到请求的部分，客户端可以继续发送请求的其余部分。
>
> - **2xx（成功状态码）：**
>   - 200 OK：请求成功。表示请求已经成功处理。
>   - 201 Created：已创建。表示请求已经被成功处理，并且服务器创建了新的资源。
>   - 204 No Content：无内容。表示服务器成功处理了请求，但没有返回任何内容。
>
> - **3xx（重定向状态码）：**
>   - 301 Moved Permanently：永久重定向。**请求的资源已被永久移动到新位置。**
>   - 302 Found：临时重定向。请求的资源临时移动到新位置。
>   - 304 Not Modified：未修改。表示资源未被修改，可以直接从缓存中获取。
>
> - **4xx（客户端错误状态码）：**
>   - 400 Bad Request：请求错误。表示请求出现语法错误。
>   - 401 Unauthorized：未授权。表示请求需要用户身份验证。
>   - 403 Forbidden：禁止访问。表示服务器理解请求，但拒绝执行。
>   - 404 Not Found：**未找到。表示服务器无法找到请求的资源。**
>
> - **5xx（服务器错误状态码）：**
>   - 500 Internal Server Error：**服务器错误。表示服务器在执行请求时发生了错误。**
>   - 502 Bad Gateway：坏的网关。表示服务器作为网关或代理，从上游服务器接收到无效的响应。
>   - 503 Service Unavailable：**服务不可用。表示服务器暂时无法处理请求**。
>
> ![image-20231228164049225](web核心/image-20231228164049225.png) 

tomcat帮我们处理的响应头什么的

## ---------------



## TomCat服务器

![image-20231228164932783](web核心/image-20231228164932783.png)

可以把web项目丢进去部署

别的人就可以用我们电脑的ip和开放的端口号和项目来访问了

`localhost/hello/a.html`

`127.0.0.1:8080/hello/a.html`

![image-20231228170011347](web核心/image-20231228170011347.png)

![image-20231228170128388](web核心/image-20231228170128388.png)  



## TomCat|web服务器

![image-20231228165430369](web核心/image-20231228165430369.png) 

[tomcat配置 | cout<<"金缕衣"; (gitee.io)](https://xu-runbo.gitee.io/xu-runbo/post/41f2fbd7.html)

![image-20231228165512258](web核心/image-20231228165512258.png) 

有的版本添加的是TOMCAT_HOME有的是什么CAt。。。

根据jdk版本去适配对应的tomcat

下载完成然后创建变量，然后指定path到bin目录

![image-20231228165834108](web核心/image-20231228165834108.png) 

## TomCat项目部署

![image-20231228170749981](web核心/image-20231228170749981.png) 

可以直接复制过去

1. 项目打包为war包，优点：会自动解压，也能正常访问

## WEb项目结构

maven的package打包为war包

install打包为jar包

![image-20231228171301105](web核心/image-20231228171301105.png)  





## IDEA创建Maven Web项目

社区版本的，只能用骨架，如果这里没有提示，我们可以先创建这俩文件夹，然后右键依次右键这俩文件夹，找到Mark D啥啥啥 as我们自己手动更改就好了

### 使用骨架

![image-20231228171725772](web核心/image-20231228171725772.png) 

![image-20231228171432170](web核心/image-20231228171432170.png)

 ![](web核心/PixPin12-28_17-21-31.gif)



### 不使用骨架

不勾选框架创建

然后修改package

![image-20231228171829386](web核心/image-20231228171829386.png) 

![image-20231228173121535](web核心/image-20231228173121535.png)

直接去修改打包为war，这样部署tomcat的时候才有提示！

![image-20231228173255776](web核心/image-20231228173255776.png)  

![image-20231228173138403](web核心/image-20231228173138403.png)

![image-20231228173206721](web核心/image-20231228173206721.png)

----

==不管是修改路径还是移动位置后再修改目录名称==

一定是webapp而不是web！！！

![image-20231229115741818](web核心/image-20231229115741818.png) 

![image-20231229115859550](web核心/image-20231229115859550.png) 

最终的项目结构一定是这样

![image-20231229115658644](web核心/image-20231229115658644.png) 

   然后添加a.html文件测试

![image-20231229115944322](web核心/image-20231229115944322.png)

ok! 

## IDEA使用TomCat

为了解决每次都打包好的war，放入tomcat中运行部署，反复就很麻烦

然后测试很方便

![image-20231228173536304](web核心/image-20231228173536304.png) 

IDEA继承tomcat

> 这 URL 分别对应了不同的部署方式，具体选择取决于你的应用是如何被部署的。
>
> 1. **http://localhost:9527/untitled18_war_exploded/a.html:**
>    - `_exploded` 通常表示这是一个以 exploded 形式部署的 Web 应用。Exploded 形式指的是将应用以文件夹的形式解压到服务器上，而不是打包成 WAR 文件。这种部署方式主要用于开发和调试阶段。
>    - `untitled18_war_exploded` 可能是你的项目的上下文路径，这个上下文路径的名称是根据你的项目名称和服务器配置来的。
> 2. **http://localhost:9527/untitled18_war/a.html:**
>    - 没有 `_exploded`，通常表示这是一个以 WAR 文件形式部署的 Web 应用。WAR 文件是 Web 应用的打包格式，它包含了应用的所有资源和配置。
>    - `untitled18_war` 可能是你的项目的上下文路径。
>
> **区别：**
>
> - 如果你处于开发和调试阶段，通常会使用 exploded 形式部署，因为这样可以更方便地进行修改和查看文件，而无需每次重新打包 WAR 文件。
> - 如果你要在生产环境中部署应用，通常会使用 WAR 文件形式部署，因为这样更便于管理和维护，也有利于应用的安全性。
>
> **建议：**
>
> - 在开发和调试阶段，你可以使用 `http://localhost:9527/untitled18_war_exploded/a.html` 这个URL，因为它更适合快速修改和查看代码。
> - 在生产环境中，应该使用 `http://localhost:9527/untitled18_war/a.html` 这个URL，以确保更好的安全性和部署管理。





## 插件集成Tomcat

![image-20231229110505802](web核心/image-20231229110505802.png) 

![image-20231229111702020](web核心/image-20231229111702020.png)

也是一样的只不过是不用手动去配置tomcat了，但是只能有tomcat7好像



## ---------

## Servlet

![image-20231229111743638](web核心/image-20231229111743638.png) 

**传入不同的参数，返回不同的页面**

![image-20231229111923527](web核心/image-20231229111923527.png) 

## servlet简介

Servlet 是 Java 语言编写的**服务器端程序**，用于处理客户端的请求和生成响应。它主要用于**构建动态的、交互性的网页应用**，能够处理用户提交的表单、与数据库交互、管理用户会话等。Servlet 运行在支持 Java 的 Web 服务器上，例如 Apache Tomcat。





## <a name="快速上手">快速上手</a>

### 快速上手 1

![image-20231231100335209](web核心/image-20231231100335209.png)

依赖项：

```xml
    <dependencies>
        <dependency>
            <groupId>javax.servlet</groupId>
            <artifactId>servlet-api</artifactId>
            <version>2.5</version>
        </dependency>
        <dependency>
            <groupId>org.apache.tomcat</groupId>
            <artifactId>tomcat-servlet-api</artifactId>
            <version>7.0.47</version>
        </dependency>
    </dependencies>
```

代码效果

![image-20231231101134206](web核心/image-20231231101134206.png) 

使用注解就不用在webxml里面写了

 ![image-20231231101205340](web核心/image-20231231101205340.png)



### 快速上手 

1. **安装 Java 开发工具：** 确保你的计算机上安装了 JDK（Java Development Kit）。你可以从 Oracle 官网或其他渠道下载并安装 JDK。

2. **下载并配置一个 Servlet 容器：** 常用的 Servlet 容器有 Apache Tomcat。下载并解压 Tomcat，然后设置环境变量 `CATALINA_HOME` 指向 Tomcat 的安装目录。

3. **创建一个简单的 Servlet 项目：**
   - 在你的开发工具（如Eclipse、IntelliJ IDEA等）中创建一个新的 Java 项目。
   - 在项目中创建一个 Java 类，该类**继承**自 `HttpServlet` 类。**重写** `doGet` 或 `doPost` 方法，这两个方法用于处理 HTTP GET 或 POST 请求。
   ```java
   import javax.servlet.http.HttpServlet;
   import javax.servlet.http.HttpServletRequest;
   import javax.servlet.http.HttpServletResponse;
   import java.io.IOException;
   
   public class MyServlet extends HttpServlet {
       protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
           response.getWriter().println("Hello, Servlet!");
       }
   }
   ```
   
4. **配置 Servlet 映射：**
   
   - 在项目中创建一个 `web.xml` 文件（如果使用 Servlet 3.0+，也可以使用注解方式代替）。
   ```xml
   <web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
            xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
            xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_3_1.xsd"
            version="3.1">
   
   <servlet>
       <servlet-name>Servletdemo</servlet-name>
       <servlet-class>comhello.Servletdemo</servlet-class>
   </servlet>
   <servlet-mapping>
       <servlet-name>Servletdemo</servlet-name>
       <url-pattern>/hello</url-pattern>
   </servlet-mapping>
   
   </web-app>
   ```
   这个配置将 `/hello` 映射到 `MyServlet`。
   
5. **部署和运行：**
   - 将你的项目打包成 WAR 文件（Web Application Archive）。
   - 将 WAR 文件复制到 Tomcat 的 `webapps` 目录下。
   - 启动 Tomcat。你可以运行 Tomcat 的启动脚本，如 `catalina.bat` 或 `catalina.sh`。
   - 在浏览器中访问 `http://localhost:8080/your-web-app-context/hello`，你应该看到 "Hello, Servlet!"。

代码效果：

![image-20231231095625262](web核心/image-20231231095625262.png) 

Servletdemo.java

```java
package com.hello;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class Servletdemo extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.getWriter().println("hello servlet!");
    }
}

```

web.xml

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">
    <servlet-mapping>
        <servlet-name>Servletdemo</servlet-name>
        <url-pattern>/hello</url-pattern>
    </servlet-mapping>

    <servlet>
        <servlet-name>Servletdemo</servlet-name>
        <servlet-class>com.hello.Servletdemo</servlet-class>
    </servlet>
</web-app>
```

> web应用程序的部署描述文件（Deployment Descriptor）的一部分，通常命名为`web.xml`。这个文件用于配置Servlet和其他Web组件的映射和参数。
>
> **Servlet声明部分：**
>
> 1. ```xml
>    <servlet>
>        <servlet-name>Servletdemo</servlet-name>
>        <servlet-class>comhello.Servletdemo</servlet-class>
>    </servlet>
>    ```
>    - `<servlet-name>`：指定**Servlet的名称**。在这里，Servlet的名字是"MyServlet"。
>    - `<servlet-class>`：指定**Servlet类的完全限定名**（包括包路径）。在这里，Servlet的类是"com.example.MyServlet"。
>    
> 2. **Servlet映射部分：**
>    
>    ```xml
>    <servlet-mapping>
>        <servlet-name>Servletdemo</servlet-name>
>        <url-pattern>/hello</url-pattern>
>    </servlet-mapping>
>    ```
>    - `<servlet-name>`：指定**要映射的Servlet的名称**。这**与Servlet声明中的名称相同**，这里是"MyServlet"。
>    
>    - `<url-pattern>`：指定URL模式，**即定义了请求到达服务器时由该Servlet处理的URL**。在这里，URL模式是"/hello"，这意味着**当请求的URL以"/hello"结尾时**，将由"MyServlet"处理。
>    
>      也可以注解的方式来指定url
>
> 表示一个Servlet（名为"MyServlet"）的**声明和映射**。当Web应用程序收到以"/hello"结尾的URL请求时，容器（如Tomcat）将请求交给"MyServlet"来处理。这是Java EE Web应用程序中配置Servlet的一种方式。



## Servlet的执行流程&生命周期

### 执行流程

我们只是实现了接口，也没用创建对象，是怎么执行的呢？

![image-20231231101830235](web核心/image-20231231101830235.png)

Servlet由谁创建？Servlet方法由谁调用？

> Servlet由**web服务器创建**，

Servlet方法由web服务器调用2.服务器怎么知道Servlet中一定有service方法？

> 因为我们自定义的Servlet，**必须实现servlet接口并复写其方法，而Servlet接口中有service方法**

---

1. **加载和实例化：**
   - 当第一次请求到达Servlet时，Servlet容器（如Tomcat）会负责**加载并实例化Servlet类**。这**发生在Web应用程序启动时或首次访问与Servlet关联的URL时**。
2. **初始化：**
   - 一旦Servlet实例被创建，**容器会调用Servlet的`init(ServletConfig config)`方法**，用于执行初始化操作。`init`方法**只会在Servlet的生命周期内被调用一次**。
3. **请求处理：**
   - 当有新的请求到达与Servlet关联的URL时，容器**会创建一个新的线程来处理这个请求。**
   - **对于每个请求，容器会调用Servlet的`service(ServletRequest request, ServletResponse response)`方法**。
   - `service`方法**会根据请求类型（GET、POST等）调用相应的`doXXX`方法，例如`doGet`或`doPost`**。
4. **线程安全：**
   - Servlet的`service`方法是**单例多线程的**，因此需要注意实现线程安全的逻辑，或通过在`service`方法中使用局部变量来确保线程安全。
5. **销毁：**
   - 当**Web应用程序关闭或Servlet容器需要释放资源时，容器会调用Servlet的`destroy`方法**。在这个方法中，你可以执行一些清理工作，如**关闭数据库连接、释放资源**等。

---





### ==生命周期==

![image-20231231102224581](web核心/image-20231231102224581.png) 默认是-1

修改为0/1。服务器一旦启动就执行了init方法。

---

1. **实例化（Instantiation）：**
   - 当Servlet容器启动或者在第一次请求到达相关URL时，**Servlet容器会创建Servlet的一个实例**。

2. **初始化（Initialization）：**
   - 在实例化后，容器会调用**Servlet的`init`方法**，允许Servlet执行一些初始化的操作。这个方法只在Servlet的生命周期中被调用一次。

3. **请求处理（Request Handling）：**
   - 在Servlet的生命周期中，**`service`方法会被多次调用**，每次处理一个HTTP请求。具体调用哪个`doXXX`方法取决于请求的类型。

4. **销毁（Destruction）：**
   - 当Web应用程序关闭或者容器需要释放资源时，容器会调用Servlet的`destroy`方法。在这个方法中，你可以执行一些清理操作。
   - 服务器关闭。内存释放，Servlet对象会被销毁

5. **垃圾回收（Garbage Collection）：**
   - 一旦Servlet实例不再被引用，它就会成为垃圾收集的对象。

这就是Servlet的基本执行流程和生命周期。理解Servlet的生命周期对于有效地管理资源和确保应用程序的正确行为非常重要。





## Servlet方法介绍&体系结构

### 方法介绍



![image-20231231102830972](web核心/image-20231231102830972.png) 

默认返回空字符串就行了

![image-20231231103120163](web核心/image-20231231103120163.png) 

### 体系结构

![image-20231231103228466](web核心/image-20231231103228466.png) 

![image-20231231103304786](web核心/image-20231231103304786.png)  

```java
package com.hello;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
@WebServlet("/demo4")
public class Servlethttp extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("......get");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("......post");
    }
}
```

测试表单

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<form action="/untitled19_war/demo4" method="post">
    <input name="username">
    <input type="submit">
</form>
</body>
</html>
```

> 在 网站输入url的形式是get请求
>
> 表单实现post请求

访问`[localhost:9527/untitled19_war/demo4](http://localhost:9527/untitled19_war/demo4)`输出了...get

![PixPin12-31_10-42-57](web核心/PixPin12-31_10-42-57.gif)

并且跳转到了action指定的路径



### 解释

![image-20231231104954011](web核心/image-20231231104954011.png) 

![image-20231231104806894](web核心/image-20231231104806894.png) 





## urlPattern配置

> ![image-20231231105101467](web核心/image-20231231105101467.png) 

```java
@WebServlet(urlPatterns = {"/hello","/h"})
```

这样都能访问到对应的资源

### 匹配规则

拓展名匹配的时候不能加/

![image-20231231105718787](web核心/image-20231231105718787.png) 

![image-20231231105445804](web核心/image-20231231105445804.png) 

当一个资源可以有多个不同的匹配规则都能访问到的时候

==越精确的优先级越高！==





### 配置

任意匹配很危险，不建议使用

![image-20231231105813058](web核心/image-20231231105813058.png)  

![image-20231231110345500](web核心/image-20231231110345500.png) 

> 理解`/`和`/*`在Servlet映射中的区别需要考虑Servlet规范中的URL匹配规则以及Tomcat中的默认Servlet的影响。
>
> 1. **`/`的含义：**
>    - 当你配置Servlet的URL模式为`/`时，表示这个Servlet会处理应用程序的根路径，也就是**所有的请求都会被这个Servlet处理。**
>    - 例如，如果你有一个Servlet配置为`<url-pattern>/</url-pattern>`，那么它将拦截所有的请求，无论是`/page1`、`/images/logo.png`还是其他路径，都将由这个Servlet处理。
>
> 2. **`/*`的含义：**
>    - 当你配置Servlet的URL模式为`/*`时，表示这个Servlet会匹配所有的URL路径，包括子路径。
>    - 例如，如果你有一个Servlet配置为`<url-pattern>/*</url-pattern>`，那么它将匹配所有路径，包括`/page1`、`/images/logo.png`等。
>
> 3. **Tomcat中的默认Servlet：**
>    - **Tomcat中有一个默认的Servlet，通常用于处理静态资源（如HTML、图片、CSS等）的请求**。这个默认的Servlet的URL模式是`/`。
>    - 如果你的应用程序中配置了一个Servlet的URL模式为`/`，它将覆盖Tomcat默认的Servlet，这意味着你的Servlet将处理所有请求，包括静态资源请求。
>
> 4. **总结：**
>    - 配置Servlet的URL模式为`/`时，它会处理应用程序的根路径，覆盖Tomcat默认的Servlet。
>    - 配置Servlet的URL模式为`/*`时，它会匹配所有路径，包括子路径。
>
> 在使用`/`时，要小心不要阻止对静态资源的访问，因为这可能会覆盖默认Servlet。而`/*`则需要谨慎使用，因为它可能导致所有请求都被该Servlet处理，包括一些本不应该由Servlet处理的静态资源。





## XML配置Servlet

参见[快速上手](#快速上手)

3.0+就可以进行@WebServlet注解来实现url了

![image-20231231110435691](web核心/image-20231231110435691.png) 
