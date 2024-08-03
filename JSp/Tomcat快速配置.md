# Tomcat快速配置

## Tomcat简介

Tomcat是Apache、Sun 和其他一些公司及个人[共同开发](https://baike.baidu.com/item/共同开发/12674474?fromModule=lemma_inlink)而成的一款免费的[开放源代码](https://baike.baidu.com/item/开放源代码/114160?fromModule=lemma_inlink)的[Web](https://baike.baidu.com/item/Web/150564?fromModule=lemma_inlink) 应用服务器。

## 为什么选用Tomcat？
### 2.1.原因
因为Tomcat 技术先进、性能稳定，而且免费，深受Java 爱好者的喜爱并得到了部分软件开发商的认可，成为比较流行的Web 应用服务器。同时Tomcat 服务器属于轻量级应用服务器，在中小型系统和并发访问用户不是很多的场合下被普遍使用，是开发和调试JSP 程序的首选。

## Tomcat的作用

当在一台机器上配置好Apache 服务器，可利用它响应HTML（标准通用标记语言下的一个应用）页面的访问请求。实际上Tomcat是Apache 服务器的扩展，但运行时它是独立运行的，所以当你运行tomcat 时，它实际上作为一个与Apache 独立的进程单独运行的。

当配置正确时，Apache 为HTML页面服务，而Tomcat 实际上运行JSP 页面和Servlet。另外，Tomcat和IIS等Web服务器一样，具有处理HTML页面的功能，另外它还是一个Servlet和JSP容器，独立的Servlet容器是Tomcat的默认模式。

## Tomcat安装&&配置

[Apache Tomcat - Apache Tomcat® 10 软件下载](https://tomcat.apache.org/download-10.cgi)

根据java版本来安装对应的Tomcat

![image-20231225104519204](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20231225104519204.png) 

查看java版本

![image-20231225104543984](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20231225104543984.png) 

![image-20231225104700235](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20231225104700235.png) 

下载到soft\tomcat下

![image-20231225105118629](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20231225105118629.png) 

![image-20231225105154686](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20231225105154686.png) 

解压完

bin目录：包含启动和停止Tomcat服务器的脚本文件，以及其他一些可执行文件。

conf目录：包含Tomcat服务器的配置文件，如server.xml、web.xml等。

lib目录：包含Tomcat服务器所需的Java类库文件。

logs目录：包含Tomcat服务器的日志文件，如访问日志、错误日志等。

temp目录：包含Tomcat服务器运行时生成的临时文件。

webapps目录：包含Web应用程序的根目录，每个Web应用程序都应该放在一个单独的子目录中。

work目录：包含Tomcat服务器编译JSP文件时生成的临时文件。

wtpwebapps目录：wtpwebapps目录是 Eclipse WTP 插件中用于存放 Web 项目的目录。

LICENSE文件： LICENSE 文件包含了 Tomcat 的许可证条款。

NOTICE文件：NOTICE 文件包含了 Tomcat 使用的第三方库的版权信息。

RELEASE-NOTES文件：RELEASE-NOTES 文件包含了 Tomcat 的版本更新信息。

RUNNING.txt文件：RUNNING.txt 文件包含了 Tomcat 的运行指南。

### 配置环境变量

1. 变量名 `CATALINA_HOME`
2. 变量值: 解压后bin目录的位置

![image-20231225105631408](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20231225105631408.png) 

修改path

![image-20231225105703608](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20231225105703608.png) 

测试Tomcat环境是否配置成功 

双鸡start.bat文件

![image-20231225105941626](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20231225105941626.png)

> 关于这里乱码的问题，
>
> Tomcat日志输出编码与cmd编码不一致，
>
> windows下的cmd的默认编码是GBK编码，
>
> Tomcat控制台默认输出设置为UTF-8编码
>
> 找到
>
> ![image-20231225110741872](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20231225110741872.png)
>
>  修改为
>
> ![image-20231225110834218](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20231225110834218.png)
>
> 然后重启tomcat服务
>
> ![image-20231225111007724](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20231225111007724.png)
>
>   ![image-20231225111034856](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20231225111034856.png) 
>
> 正常了！

访问[Apache Tomcat/10.1.17](http://localhost:8080/)

![image-20231225110007690](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20231225110007690.png) 

就ok了

