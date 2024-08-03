# Maven

## Maven的概念

Maven是专门用于管理和构建Java项目的工具，它的主要功能有：

+ 提供了一套标准化的项目结构
+ 提供了一套标准化的构建流程（编译，测试，打包，发布....)
+ 提供了一套依赖管理机制

## 标准化的项目结构

![image-20231221102116411](Maven/image-20231221102116411.png) 

不同IDE项目结构不一样，不能很方便的移植。

---

现在是不同的IDE用Maven创建的项目就解决了这个问题，可以方便的移植

![image-20231221102406561](Maven/image-20231221102406561.png) 



## 标准化的构建流程

编译生成字节码文件

构建：编译，测试，打包，发布

原本是打包每一个jar包，就很麻烦，现在Maveb可以用一套简单的命令来执行构建



## 依赖管理机制

导入的那些需要的jar包，第三方资源，插件。。。

从前，我们创建一个lib目录，然后把jar包复制到，然后jar包加入到库(工作环境)

jar包少的话是简单的，多的话就麻烦了。。



现在

在配置文件里

Maven可以可以，方便的导入jar包！！！

![image-20231221103043426](Maven/image-20231221103043426.png)

写了这一段代码，就去仓库找对应的jar包，然后就导入了 .

其实是去仓库引用我们配置的jar包

导入一刷新就导入了，贼番茄好用 

## 为什么要学Maven

![image-20231221103315231](Maven/image-20231221103315231.png) 

## Maven的正式学习

### Maven简介

Apach Mavehn是一个项目管理和构建工具

基于POM(project object modoule)项目对象模型，通过一段描述信息来管理项目的构建，报告，和文档

其实是去仓库引用我们配置的jar包

![image-20231221104053148](Maven/image-20231221104053148.png) 

#### 仓库

![image-20231221104210378](Maven/image-20231221104210378.png) 

  中央仓库放的是一些免费开源的jar包

![image-20231221104449568](Maven/image-20231221104449568.png) 

![image-20231221104713822](Maven/image-20231221104713822.png) 

### Maven安装配置

> 1. 解压apache-maven-3.6.1.rar既安装完成
> 2. 配置环境变量MAVEN_HOME为安装路径的bin目录配置本地仓库：修改conf/settings.xml中的\<localRepository\>为一个指定目录
> 3. 配置阿里云私服：修改conf/settings.xml中的\<mirrors\>标签
> 4. 为其添加如下子标签：
> 5. ![image-20231221104844688](Maven/image-20231221104844688.png) 

[maven的下载](#https://archive.apache.org/dist/maven/maven-3/3.6.3/binaries/apache-maven-3.6.3-bin.zip)

[maven3.6.3下载与安装](https://blog.csdn.net/qq_46554590/article/details/119428896?ops_request_misc=%7B%22request%5Fid%22%3A%22170312700516800213057232%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=170312700516800213057232&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-119428896-null-null.142^v96^control&utm_term=apache-maven-3.6.3-bin.zip&spm=1018.2226.3001.4187)

下载解压后

![image-20231221105333209](Maven/image-20231221105333209.png) 

bin下的

![image-20231221105409315](Maven/image-20231221105409315.png) 

最常用，为了能再任何地方都使用这个命令，所以要配置化境变量

#### 配置环境变量

![PixPin12-21_11-16-59](Maven/PixPin12-21_11-16-59-17031308522653.gif)

<video src="D:/OBSvideo/2023-12-21 11-49-18.mp4"></video>



> 1. ![image-20231221111822543](Maven/image-20231221111822543.png) 
>
> 2. ![image-20231221111920953](Maven/image-20231221111920953.png) 
>
> 3. ![image-20231221111943332](Maven/image-20231221111943332.png) 
>
> 4. 验证![image-20231221112007696](Maven/image-20231221112007696.png) 
>
>    OKl！

#### 配置本地仓库

修改配置文件

conf/settings.xml

![image-20231221122732266](Maven/image-20231221122732266.png) 

![image-20231221122918728](Maven/image-20231221122918728.png) 

配置本地仓库

习惯在maven安装目录下新建一个目录

![image-20231221123048838](Maven/image-20231221123048838.png) 

![image-20231221123150045](Maven/image-20231221123150045.png) 

#### 配置阿里云私服

```
	<mirror>
		<id>alimaven</id>
		<name>aliyun aven</name>
		<url>http://maven.aliyun.com/nexus/content/groups/public/</url>
		<mirrorOf>central</mirrorOf>
	</mirror>
```

![image-20231221123531572](Maven/image-20231221123531572.png)

就配置好了！

### Maven 基本使用

#### 常用命令

> 1. compile ：编译
> 2. clean ：清理
> 3. test ：测试
> 4. package：打包
> 5. install： 安装

可以在maven面板里点击声明周期去执行！

或者安装插件

或者cmd到项目目录

```
mvn +命令
```

然后那些生成都在target下面

![image-20231221135103582](Maven/image-20231221135103582.png) 





#### Maven生命周期:

![image-20231221125019477](Maven/image-20231221125019477.png) 

![image-20231221125039889](Maven/image-20231221125039889.png) 

### IDEA配置Maven

#### IDEA配置Maven环境

![image-20231221125418520](Maven/image-20231221125418520.png) 

#### Maven坐标详解

![image-20231221125541787](Maven/image-20231221125541787.png)

![image-20231221125608814](Maven/image-20231221125608814.png) 

![image-20231221125639412](Maven/image-20231221125639412.png) 



#### IDEA创建Maven项目

![image-20231221130530619](Maven/image-20231221130530619.png) 

![image-20231221130659395](Maven/image-20231221130659395.png) 

![image-20231221130832502](Maven/image-20231221130832502.png) 

肥肠的智能



#### 注意事项

但是现在idea会默认继承maven

很难修改掉maven3默认的

[五招轻松帮你替换IDEA内置maven_idea切换maven仓库-CSDN博客](https://blog.csdn.net/lai_zhe/article/details/125423184?ops_request_misc=&request_id=&biz_id=102&utm_term=解除idea里已捆绑maven3&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-7-125423184.142^v96^control&spm=1018.2226.3001.4187) 

![image-20231221134151221](Maven/image-20231221134151221.png) 

才能修改

![image-20231221134159477](Maven/image-20231221134159477.png) 

IDEA下面是能看到我们的maven版本和路径的

![image-20231221134254719](Maven/image-20231221134254719.png)

现在就是使用我们自己的maven版本了

 ![image-20231221134408312](Maven/image-20231221134408312.png) 

![image-20231221134420436](Maven/image-20231221134420436.png) 

好用的插件

#### IDE导入Maven项目

![image-20231221134558286](Maven/image-20231221134558286.png) 

![image-20231221134607710](Maven/image-20231221134607710.png) 

![image-20231221134622294](Maven/image-20231221134622294.png) 

就导入maven项目了，非常的方便

![image-20231221134709724](Maven/image-20231221134709724.png) 



### 依赖管理



#### 自行手写

![image-20231221140932999](Maven/image-20231221140932999.png) 

```java
    <dependencies>
        <dependency>
            <groupId>mysql</groupId>
            <artifactId>mysql-connector-java</artifactId>
            <version>8.0.32</version>
        
        </dependency>

    </dependencies>
```

![image-20231221135426409](Maven/image-20231221135426409.png) 

dependency后刷新就会去查找，没有就去下载

![image-20231221135918575](Maven/image-20231221135918575.png) 

如果我们本地库没有对应的jar包，他就会去远程库找，私人库，或者远程中心，下载。

然后再添加到本地库，下次就可以使用了

![image-20231221140121871](Maven/image-20231221140121871.png) 

验证成功

#### 注意

![image-20231221140301043](Maven/image-20231221140301043.png) 

这样就可以实现实时的修改了并且添加jar包了

==若果前提本地仓库已经有的jar包了==

也可一快速的生成

![PixPin12-21_14-07-54](Maven/PixPin12-21_14-07-54.gif)





#### 依赖范围

```java
<scope>test<scop>
```

![image-20231221141138315](Maven/image-20231221141138315.png) 

test:

在test目录下才可以使用

compile是最大环境

默认就好了，，

如果测试的就放测试下面，，。，

> ![image-20231221141540478](Maven/image-20231221141540478.png) 
>
> 了解一下会显得专业。。。

import先不了解

依赖范围指定了依赖项在项目构建和运行时的作用域。以下是不同依赖范围的解释：

1. compile：这是默认的依赖范围，它表示依赖项将在编译和运行时都可用。

2. provided：这个依赖范围表示依赖项在编译时可用，但是在运行时不会包含在项目中。这意味着依赖项应该由运行时环境提供，例如，Java EE容器提供的API。

3. runtime：这个依赖范围表示依赖项在运行时可用，但是在编译时不需要。例如，JDBC驱动程序是运行时依赖项，因为它们在编译时不需要，但是在运行时需要。

4. test：这个依赖范围表示依赖项只在测试时可用，不会在编译或运行时包含在项目中。例如，JUnit测试框架就是一个测试依赖项。

5. system：这个依赖范围类似于provided，但是需要手动提供依赖项的路径。这个依赖范围通常用于本地文件系统中的JAR文件。

在Maven项目中，可以使用以下方式指定依赖项的范围：

```xml
<dependency>
    <groupId>group-id</groupId>
    <artifactId>artifact-id</artifactId>
    <version>version</version>
    <scope>scope</scope>
</dependency>
```

其中，`scope`元素指定了依赖项的范围。例如，以下是一个指定了`test`范围的依赖项：





![image-20231221142023500](Maven/image-20231221142023500.png) 

默认的compile就ok！

web项目打包为war包 
