#  JavaWeb_MySQL

涉及哪些知识 

![image-20231219171056484](JavaWeb/image-20231219171056484.png) 

> 1. MySql:数据库
> 2. JDBC:是java操作数据库API
> 3. Maven :管理项目很方便的东西
> 4. Mybaties:简化JDBC的框架
> 5. vue和Elementui是前端的框架，。，
>
> ---
>
> Maven（也称为Apache Maven）是一个用于**项目管理和构建的开源工具**。它提供了一种管理项目的方式，可以帮助开发团队更有效地构建、发布和管理软件项目。

## Java Web简介

![image-20231217124725145](JavaWeb/image-20231217124725145.png)

> 网页那些东西是前端的
>
> java web和数据库是后端

## 数据库MySql

### 关于数据库

![image-20231219171120023](JavaWeb/image-20231219171120023.png)  

![image-20231217125611456](JavaWeb/image-20231217125611456.png)

数据库管理系统：MySql。。。

### 数据库了解

> ![image-20231217125748079](JavaWeb/image-20231217125748079.png) 

**SQL就是去操作-花里胡哨-的==关系型==数据库的语言**



### MySql数据模型

> 关系型数据库
>
> 非关系型数据库

![image-20231217155512382](JavaWeb/image-20231217155512382.png) 

多张有关系的二维表组成的数据库！

而且数据存储在硬盘里

不易丢失

![image-20231217160031591](JavaWeb/image-20231217160031591.png) 

表frm，，数据myd

![image-20231217155952887](JavaWeb/image-20231217155952887.png) 



## SQL

### SQL简介

![image-20231217160129669](JavaWeb/image-20231217160129669.png) 

### SQL分类

![image-20231217160917368](JavaWeb/image-20231217160917368.png) 



### SQL的通用语法

> 1. **分号结尾**
>
> 2. 不区分大小写CREAT和creat是同理的--建议关键字用大写
>
> 3. 注释
>
>    **`-- 注释内容`两个-和一个空格，后面是注释的语句(SQL的特有)**
>
>    `#注释内容`#紧跟着注释内容
>
>    `/*注释内容*/`中间被抱起来的就是注释内容

演示

![image-20231219171142058](JavaWeb/image-20231219171142058.png) 

 

### DDL(Data Definition Language)数据定义

<img src="JavaWeb/image-20231217160959495.png" alt="image-20231217160959495" style="zoom:50%;" /> 

![image-20231217161129705](JavaWeb/image-20231217161129705.png)

找规律：数据库名一般在最后 

exist加s

只有show的时候database才+s

特殊的是查询当前数据库的时候要加();emmmm理解为函数吧，暂时。。

#### 查询数据库show

> `SHOW DATABASES;`

代码演示:

![image-20231217162427105](JavaWeb/image-20231217162427105.png) 

自带的四个数据库：

---

特殊的表，视图，是逻辑表。

性能数据库，，，的信息，

玩我们自己的数据库

#### 创建数据库(条件)create

> 无脑创建
>
> `CREATE DATABASE 数据库名;`
>
> 条件创建
>
> `CREATE IF NOt EXISTS 数据库名;`
>
> 为什么需要条件创建呢？
>
> 如果存在了你再去创建就给你报错。。
>
> ![image-20231217163654672](JavaWeb/image-20231217163654672.png) 

代码演示:

![image-20231217162427105](JavaWeb/image-20231217162427105.png) 

创建数据库

![image-20231217162443492](JavaWeb/image-20231217162443492.png) 

条件创建数据库

![image-20231217162509672](JavaWeb/image-20231217162509672.png) 

#### 删除数据库(条件)drop

> 无脑删除
>
> `DROP DATABASE 数据库名;`
>
> 条件删除
>
> `DROP DATABASE IF EXISIS 数据库名;`
>
> 存在的意义就是防止删除一个不存在的数据库报错，，

代码演示 

![image-20231219171226792](JavaWeb/image-20231219171226792.png) 

普通删除

![image-20231219171258796](JavaWeb/image-20231219171258796.png) 

条件删除

![image-20231217162849841](JavaWeb/image-20231217162849841.png) 

![image-20231217162841878](JavaWeb/image-20231217162841878.png) 

#### ==使用数据库(当前，想要)select use==

> 查看当前用的哪个数据库
>
> `SELECT DATABASE();`
>
> 要使用数据库
>
> `USE 数据库名;`

代码演示:

查询当前使用的数据库:

![image-20231217163126232](JavaWeb/image-20231217163126232.png)  

使用数据库

![image-20231217163111255](JavaWeb/image-20231217163111255.png) 

#### TEST

> 用优雅的方式完成下列操作:
>
> 1. 创建一个db1的数据库
> 2. 使用创建的数据库
> 3. 删除创建的数据库
> 4. 展示当前正在使用数据库

#### --------------------------------

#### 查询表/表结构

> 先进入一个数据库
>
> ---
>
> 查询数据库有哪些表
>
> `SHOW tables;`
>
> 想看哪一个表的结构description描述
>
> `desc 表名;`
>
> ---
>
> ==**desc查的是表的结构，而不是数据**== 
>
> `SELECT * from 表名;`才是看表的数据
>
> ![image-20231219171343234](JavaWeb/image-20231219171343234.png)  

代码演示;

![image-20231217164727662](JavaWeb/image-20231217164727662.png) 

使用的sys数据库

![image-20231219171404633](JavaWeb/image-20231219171404633.png) 

得到数据库的所有表

![image-20231219171422022](JavaWeb/image-20231219171422022.png)

查看第一张**表的结构**！

==**desc查的是表的结构，而不是数据**==

#### ==创建表==

<img src="JavaWeb/image-20231217165027778.png" alt="image-20231217165027778" style="zoom:67%;" /> 

最后一行末尾不能有,

![image-20231219171439080](JavaWeb/image-20231219171439080.png) 

代码演示: 

![image-20231219171450324](JavaWeb/image-20231219171450324.png) 

切换库 

![image-20231219171502668](JavaWeb/image-20231219171502668.png) 

创建表 

![image-20231219171516646](JavaWeb/image-20231219171516646.png) 

查看创建的表的结构

==查看的是表的结构==

##### 案例

![image-20231219171527496](JavaWeb/image-20231219171527496.png)   

![image-20231219171539494](JavaWeb/image-20231219171539494.png)  

![image-20231219171553806](JavaWeb/image-20231219171553806.png) 

更正》》》

学生状态因为只有一个数字可以用tinyint



----

#### 删除表

> 无脑删除
>
> `DROP TABLE 表名;`
>
> 条件删除
>
> `DROP TABLE IF EXISTS 表名;`
>
> 也是为了防止删除不存在的表的时候报错;

代码演示:

![image-20231217173355440](JavaWeb/image-20231217173355440.png) 

#### ==修改表==

![image-20231217174019809](JavaWeb/image-20231217174019809.png)  

##### 修改表名称

> `ALTER TABLE 表名 RENAME TO 新的表名;`

代码演示:

![image-20231217173827750](JavaWeb/image-20231217173827750.png) 

![image-20231217173844468](JavaWeb/image-20231217173844468.png) 

##### 添加新列

> `ALTER TABLE 表名 ADD 列名 列数据类型;`

![image-20231217174210522](JavaWeb/image-20231217174210522.png) 

![image-20231217174219720](JavaWeb/image-20231217174219720.png) 

##### 修改某一列的数据类型

> `ALTER TABLE 表名 MODIFY 列名 新的数据类型;`

代码演示

![image-20231217174502377](JavaWeb/image-20231217174502377.png) 

##### 修改列名并顺手改数据类型

> `ALTER TABLE 表名 CHANGE 列 新列名 数据类型;`

代码演示：

![image-20231217174938399](JavaWeb/image-20231217174938399.png) 

![image-20231217174958588](JavaWeb/image-20231217174958588.png) 

经过测试，不能不写新的数据类型。

##### 删除列

> `ALTER TABLE 表名 DROP 列名; `

代码演示:

![image-20231217175255811](JavaWeb/image-20231217175255811.png) 

#### SQL的数据类型

![image-20231217170252619](JavaWeb/image-20231217170252619.png)

用法

>  age int
>
> score double(分数值的总长度，小数点后保留的位数)
>
> 0-100分，保留两位小数；score double(5,2)
>
> birthday date;
>
> 字符串
>
> name char(10);字符个数不可以超过十个
>
> name varchar(10);;字符个数不可以超过十个
>
> > 定长和变长的区别
> >
> > varchar先去计算实际数据的空间来决定实际占用
> >
> > 张三存在varchgar(10) 占了2个字符
> >
> > 张三存在char(10)里面占了10个，其他的都用空格
> >
> > ---
> >
> > varchar节约空间但是存储性能低
> >
> > char浪费空间但是存储性能高

> 保留两位小数89.020,100.02,9.0900

### DML(Data Manipulation Language)==数据操作==

<img src="JavaWeb/image-20231217161005871.png" alt="image-20231217161005871" style="zoom:50%;" /> 

#### 添加数据INSERT INTO

![image-20231217194454551](JavaWeb/image-20231217194454551.png) 

##### 给指定列添加数据

> `INSERT INTO 表名(列名1,列名2,...) VALUES(值1,值2...);`

代码演示：

![image-20231217194904806](JavaWeb/image-20231217194904806.png) 

![image-20231217194914225](JavaWeb/image-20231217194914225.png) 

##### 给全部列都添加数据

> `INSERT INTO 表明 VALUES(值1,值2,,,,,,)`
>
> 值是一一对应的

代码演示:

![image-20231217195432336](JavaWeb/image-20231217195432336.png)

![image-20231217195508427](JavaWeb/image-20231217195508427.png) 

##### 批量添加数据

> `INSERT INTO 表名(列1,列2,...) VALUES(值1，值2....),(值1，值2....),(值1，值2....)...;`
>
> `INSERT INTO 表名 VALUES(值1，值2....),(值1，值2....),(值1，值2....)....;`

代码演示:

![image-20231217200034637](JavaWeb/image-20231217200034637.png) 

![image-20231217200043544](JavaWeb/image-20231217200043544.png) 

---

![image-20231217200219170](JavaWeb/image-20231217200219170.png) 

![image-20231217200225661](JavaWeb/image-20231217200225661.png) 

> 推荐把对应的列名写出来，而不是暗中默默对应。。。。

#### *修改数据UPDATE

> `UPDATE 表名 set 列=值，列2=值......[where 条件];`
>
> 判断相等是=
>
> ----
>
> **如果不写条件的话，默认把所有数据都改掉;**

代码演示:



![image-20231219171642950](JavaWeb/image-20231219171642950.png)  

![image-20231219171657198](JavaWeb/image-20231219171657198.png)  

![image-20231219171712515](JavaWeb/image-20231219171712515.png) 

这里的where理解为if就好了...

或者。。在哪里改呢，在分数为101.03哪一行改

神踏马定语从句hh



#### *删除数据DELETE FROM

> `DELETE FROM 表名 [where 条件];`
>
> 如果不加条件，默认把表弄为空！

代码演示:

![image-20231219171729713](JavaWeb/image-20231219171729713.png) 

![image-20231219171740410](JavaWeb/image-20231219171740410.png) 

---

![image-20231217203852198](JavaWeb/image-20231217203852198.png) 

空空如也

#### 条件

![image-20231217210658918](JavaWeb/image-20231217210658918.png) 

### DQL(Data Query Language)==数据查询==

<img src="JavaWeb/image-20231217161009789.png" alt="image-20231217161009789" style="zoom:50%;" /> 

![image-20231219171754574](JavaWeb/image-20231219171754574.png)  

#### 基础查询

> `SELECT 列，列1,列2...(*全部列) FROM 表名;`
>
> 去除重复的结果
>
> `SELECT DISTINCT 列，列1,列2...(*全部列) FROM 表名;`

代码演示：

![image-20231219171822321](JavaWeb/image-20231219171822321.png)  

---

![image-20231217210242435](JavaWeb/image-20231217210242435.png) 

---

起别名

![image-20231219171835487](JavaWeb/image-20231219171835487.png)  

---

![image-20231219171846188](JavaWeb/image-20231219171846188.png)  

去除重复

![image-20231219171853571](JavaWeb/image-20231219171853571.png)  



#### 条件查询WHERE

> `SELECT 列表 FROM 表名 WHERE 条件列表;`
>
> ==**基础查询加了WHERE 条件列表**==
>
> 注意where不要省略
>
> 推荐用and而不是&&

代码演示

![image-20231217211057668](JavaWeb/image-20231217211057668.png) 

![image-20231217211413940](JavaWeb/image-20231217211413940.png) 

![image-20231217211500610](JavaWeb/image-20231217211500610.png) 

==推荐使用and==;

![image-20231217211822855](JavaWeb/image-20231217211822855.png) 

![image-20231217212104048](JavaWeb/image-20231217212104048.png)  

> > > 注意null不能用= !=
> > >
> > > 而是用is null和is not null

![image-20231217212223132](JavaWeb/image-20231217212223132.png) 



----

##### ==模糊查询like==

> 记住_匹配一个字符
>
> %匹配人一个字符
>
> 再配合like使用
>
> 加上""
>
> 食用更佳

![image-20231219171910632](JavaWeb/image-20231219171910632.png)  

![image-20231219171919715](JavaWeb/image-20231219171919715.png)  

![image-20231219171931843](JavaWeb/image-20231219171931843.png)  

![image-20231219171940471](JavaWeb/image-20231219171940471.png)  



##### 条件

![image-20231217211637486](JavaWeb/image-20231217211637486.png)  

#### 分组查询GROUP BY

##### 聚合函数

概念:将一列作为一个整体，进行纵向计算。

![image-20231218094547291](JavaWeb/image-20231218094547291.png) 

==**null都不参与聚合函数的运算**==

> `SELECT 聚合函数名(列名) FROM 表;`

代码演示

![image-20231218095340865](JavaWeb/image-20231218095340865.png)  

![image-20231218095441297](JavaWeb/image-20231218095441297.png)  

![image-20231218095624112](JavaWeb/image-20231218095624112.png) 

---

##### 分组查询

![image-20231218095952578](JavaWeb/image-20231218095952578.png) 

> 要查的东西必须是
>
> 分组字段，聚合函数。
>
> 其他的没有意义。
>
> ![image-20231219171958036](JavaWeb/image-20231219171958036.png) 
>
> ![image-20231218101152334](JavaWeb/image-20231218101152334.png)
>
> 会直接报错！

代码演示: 

![image-20231218101250534](JavaWeb/image-20231218101250534.png) 

 现在需求

 ![image-20231218101530685](JavaWeb/image-20231218101530685.png) 

![image-20231218101640888](JavaWeb/image-20231218101640888.png) 

需求
![image-20231218101754826](JavaWeb/image-20231218101754826.png) 

因为having是能对聚合函数进行操作的，而where不可以。

![image-20231218101921751](JavaWeb/image-20231218101921751.png) 

> 分组查询：
>
> 那些聚合函数会默认的去对分完组的列表进行计算，而不是对整张表。。。

#### 排序查询ORDER BY

![image-20231218092005198](JavaWeb/image-20231218092005198.png) 

==**如果有多个排序条件，只有前面的条件值一样的时候才根据第二条件排序**==

代码演示：

![image-20231219172012674](JavaWeb/image-20231219172012674.png) 

![image-20231219172021255](JavaWeb/image-20231219172021255.png)  

**前面查询表结构的desc是describe的缩写，这里降序的desc是descend的缩写** 

> 现在我想让根据mathscore降序且mathscore相等的时候，id进行升序；
>
> ![image-20231218093253473](JavaWeb/image-20231218093253473.png) 
>
> 代码演示
>
> ![image-20231218093500333](JavaWeb/image-20231218093500333.png) 

#### ==分页查询LIMIT==

效果：

![image-20231218102136842](JavaWeb/image-20231218102136842.png) 

> `SELECT 列表 FROM 表名 LIMIT 起始索引，查询条目数;`
>
> 起始索引是从0开始的
>
> ==**起始索引=(当前页码-1)*每页显示的条数**==
>
> ![image-20231218102354649](JavaWeb/image-20231218102354649.png) 

 代码演示:

![image-20231218103058443](JavaWeb/image-20231218103058443.png) 





### DCL(Data Control Language)数据权限控制

<img src="JavaWeb/image-20231217161017542.png" alt="image-20231217161017542" style="zoom:50%;" /> 

#### 约束

##### 概念&分类

> 作用于列上的规则，限制加入表的数据
>
> 保证了数据的正确性，有效性，完整性

![image-20231218142846479](JavaWeb/image-20231218142846479.png) 

==**MySQL不支持检查约束**==

> 主键是指在一个表中用来唯一标识每一行数据的字段或字段组合。
>
> 主键的作用是**确保表中的每一行都有一个唯一的标识符**。
>
> 非空且唯一

##### 约束的使用

```sql
create table stuff(
id int primary key,
name varchar(20) unique,
birthday date not null,
salary double(7,2) not null,
bonus double(7,2) default 0
);
```

主键约束:非空唯一

![image-20231219172045470](JavaWeb/image-20231219172045470.png) 

![image-20231219172058264](JavaWeb/image-20231219172058264.png)  

唯一约束

![image-20231219172110834](JavaWeb/image-20231219172110834.png)  

默认约束

![image-20231218145138379](JavaWeb/image-20231218145138379.png)

主键自增

当列是数字类型并且唯一约束的时候会自己增加；

![image-20231218150023336](JavaWeb/image-20231218150023336.png) 

#####  ==外键约束==

> ![image-20231218204906190](JavaWeb/image-20231218204906190.png)  
>
> 如果有这样的两张表，mysql会认为这是两张独立的表，
>
> 我们认为是有逻辑关系但是没有物理联系
>
> 如何外键连接起来呢。
>
> ---
>
> 现在可以删除郑州那一行，是没问题的
>
> 但实际中，要删除郑州这个部门，是要先把张三和李四给开除掉，然后再删除郑州部门。
>
> ---
>
> 如何实现呢
>
> > `CREAT TABLE 表(`
> >
> > `	   			列名 数据类型,`	   			
> >
> > `.......`
> >
> > `CONSTRAINT 外键名称 FRREIGN KEY(外键列名，从表的列) REFERENCES 主表(主列表名))`
> >
> > RFOREIGN KEY后面的是从表的列，REFERENCES 后面的主表和主表的列;
> >
> > 创建外键的时候要保证主表已经创建好了。。。
> >
> > ![image-20231219172129127](JavaWeb/image-20231219172129127.png)  

代码演示:

在创建外键约束时，主表的列通常需要有索引以提高查询性能。

**primary**  key

```sql
create table stuff(
id int,
name varchar(20),
depid int,
constraint forekey foreign key(depid) references dep(did)
);
insert into stuff(id,name,depid) values(1,"张三",1);
insert into stuff(id,name,depid) values(2,"李四",1);
insert into stuff(id,name,depid) values(3,"王五",2);



create table dep(
did int primary key auto_increment,
address varchar(10)
);
insert  into dep(address) values("郑州");
insert  into dep(address) values("杭州");

select * from stuff;
select * from dep;

delete from stuff where depid=1;
delete from dep where address="郑州";
```

![image-20231218204735025](JavaWeb/image-20231218204735025.png) 

利用外键建立depid和did之间的物理联系 

![image-20231218211110756](JavaWeb/image-20231218211110756.png)

![image-20231218211309650](JavaWeb/image-20231218211309650.png) 

 ![image-20231218211424136](JavaWeb/image-20231218211424136.png) 

> 涉及的问题
>
> 在创建外键约束时，被引用的列(主表的列)通常**需要有主键**或**唯一约束**。
>
> 需要确保(主)`dep` 表中的 `did` 列有**主键**或唯一约束，这样才能成功创建**外键约束**。
>
> 建表后的添加外键
>
> `ALTER TABLE 次表名 ADD CONSTRAINT FOREIGN KEY(次表的列) REFERENCES 主表(主表的列);`

##### 删除外键

> 外键是表和表的关系
> `ALTER TABLE 次表 DROP FOREIGN KEY 外键名;`

代码演示:

![image-20231219172148930](JavaWeb/image-20231219172148930.png) 

##### 小结

---

![image-20231219172156290](JavaWeb/image-20231219172156290.png) 

 ![image-20231219172205371](JavaWeb/image-20231219172205371.png)

![image-20231219172226473](JavaWeb/image-20231219172226473.png)  

> 最好用的就是
>
> `alter table 表名 modify 列名 去掉约束的数据类型;`
>
> varchar(20) unique->varchar(20);

### 数据库设计

> 对于软件的开发很有用
>
> 软件研发步骤:\
>
> + ![image-20231219172238282](JavaWeb/image-20231219172238282.png)  
>
> + 数据库设计概念
>
>   根据业务系统的具体需求，结合DDBMS，为业务系统选择最好的数据存储模型
>
>   建立数据库中的表结构和表与表之间的关联关系的过程
>
>   哪些表，哪些列，表和表之间的关系
>
> + 数据库设计 的步骤
>
>   ![image-20231219115747293](JavaWeb/image-20231219115747293.png) 

#### 表关系

> 1. 一对一

人和身份证

+ 一对一关系多用于表的拆分，将一个实体中常用到的字段放到一张表，不经常使用的字段放到另一张表提升查询性能

> 1. 一对多(很多)，多对一

部门和员工

从部门来看是一对多

从员工来看是多对一

> 1. 多对多

商品和订单

一个商品对应多个订单

一个订单对应多个商品

---

#### MYSQL实现表关系

##### 一对多/多对一

![image-20231219122044220](JavaWeb/image-20231219122044220.png) 

代码演示

```sql
create table dep(
id int primary key auto_increment,
func varchar(10),
address varchar(20)
);

insert into dep(func,address) values("研发部","郑州"),("销售部","洛阳");
select * from dep;



create table stuff(
stuff_id int primary key auto_increment,
name varchar(10),
depid int,
constraint forekey foreign key(depid) references dep(id)
)

insert into stuff(name,depid) values("张三",1);
insert into stuff(name,depid) values("李四",2);
insert into stuff(name,depid) values("王五",2);
insert into stuff(name,depid) values("赵六",1);
select  * from stuff; 
select  * from dep; 
```

##### 多对多

![image-20231219122932632](JavaWeb/image-20231219122932632.png) 

代码实现:

```sql
create table tb_order(
id int primary key auto_increment,
payment double(10,2),
payment_type varchar(10),
status varchar(10)
);


create table tb_goods(
id int primary key auto_increment,
title varchar(20),
price double(10,2)
);


insert into tb_order(payment,payment_type,status) values(1234,"微信支付","未付款");
insert into tb_order(payment,payment_type,status) values(234,"微信支付","未付款");
insert into tb_order(payment,payment_type,status) values(104,"支付宝支付","已付款");


insert into tb_goods(title,price) values("华为P90",9999);
insert into tb_goods(title,price) values("华为P80",1111);
insert into tb_goods(title,price) values("华为P70",2222);
insert into tb_goods(title,price) values("华为P60",7777);
insert into tb_goods(title,price) values("华为P30",8888);



create table tb_middle(
id int primary key auto_increment,
order_id int,
goods_id int,
count int
);

alter table tb_middle add constraint middle_order foreign key(order_id) references tb_order(id);
alter table tb_middle add constraint middle_goods foreign key(goods_id) references tb_goods(id);

select * from tb_goods;
select * from tb_order;
select * from tb_middle;
```

![PixPin12-19_12-49-22](JavaWeb/PixPin12-19_12-49-22.gif) 

##### 一对一

代码实现

```sql
create table qq_user(
id int primary key auto_increment,
nickname varchar(10),
age int,
sex varchar(5)
);


create table qq_user_desc(
id int primary key auto_increment,
city varchar(10),
edu varchar(5),
income double(10,2),
status varchar(5),
detail varchar(5) default "---"
);

insert  into qq_user(nickname,age,sex) values("马车",19,"男");
insert  into qq_user(nickname,age,sex) values("赵晕",39,"男");
insert  into qq_user(nickname,age,sex) values("张飞",29,"女");
#_---
insert  into qq_user_desc(city,edu,income,status) values("广州","博士",3000,"单身狗");
insert  into qq_user_desc(city,edu,income,status) values("湖南","高中",23000,"已婚");
insert  into qq_user_desc(city,edu,income,status) values("湖北","小学",13000,"离异带俩娃");

select * from qq_user;
select * from qq_user_desc;

alter table qq_user add desc_id int primary key;



alter table qq_user drop desc_id;
alter table qq_user add constraint qqkey foreign key(id) references qq_user_desc(id);
alter table qq_user drop foreign key qqkey;
```

![PixPin12-19_13-18-35](JavaWeb/PixPin12-19_13-18-35.gif) 

![image-20231219132040358](JavaWeb/image-20231219132040358.png) 

#### 数据库设计案例

![image-20231219133311156](JavaWeb/image-20231219133311156.png) 

### 多表查询

引入:

> `select * from 表1,表2;`
>
> 笛卡尔积：A，B两个集合，去A，B的所有组合情况

测试代码

```sql
create table dep(
id int primary key auto_increment,
func varchar(10),
address varchar(20)
);

insert into dep(func,address) values("研发部","郑州"),("销售部","洛阳");

create table stuff(
stuff_id int primary key auto_increment,
name varchar(10),
depid int,
constraint forekey foreign key(depid) references dep(id)
)

insert into stuff(name,depid) values("张三",1);
insert into stuff(name,depid) values("李四",2);
insert into stuff(name,depid) values("王五",2);
insert into stuff(name,depid) values("赵六",1);
select  * from stuff;
select * from dep;
select * from stuff,dep;
select * from stuff,dep where stuff.depid=dep.id;
```

![image-20231219133934032](JavaWeb/image-20231219133934032.png) 

`select * from stuff,dep;`

![image-20231219134107741](JavaWeb/image-20231219134107741.png) 

`select * from stuff,dep where depid=id;`

![image-20231219134128140](JavaWeb/image-20231219134128140.png) 

#### 连接查询

##### 内连接(交集)

> -- 隐式内连接
>
> `seect 字段列表 from 表1，表2 where 条件;`
>
> 查询AB**交集的数据**
>
> -- 显示内连接
>
> `select 字段列表 from 表1 [inner] join 表2 on 条件;`
>
> Inner可以省略/。。。。。

> **select** * **from** stuff,dep **where** stuff.depid=dep.id;
>
> **select** * **from** stuff **inner** **join** dep **on** stuff.depid=dep.id;
>
> ![image-20231219134948387](JavaWeb/image-20231219134948387.png)  

现在我要求：

![image-20231219135029337](JavaWeb/image-20231219135029337.png) 

代码实现:

```sql
create table dep(
id int primary key auto_increment,
func varchar(10),
address varchar(20)
);

insert into dep(func,address) values("研发部","郑州"),("销售部","洛阳");




create table stuff(
stuff_id int primary key auto_increment,
name varchar(10),
depid int,
addr varchar(20)
);

insert into stuff(name,depid,addr) values("张三",1,"日本");
insert into stuff(name,depid,addr) values("李四",2,"日本");
insert into stuff(name,depid,addr) values("王五",2,"日本");
insert into stuff(name,depid,addr) values("赵六",1,"日本");
insert into stuff(name,depid,addr) values("赵六",999,"日本");

select  * from stuff;
select * from dep;
select * from stuff,dep;

select * from stuff,dep where stuff.depid=dep.id;
select * from stuff inner join dep on stuff.depid=dep.id;
select stuff.stuff_id,stuff.name,dep.func,dep.address from stuff inner join dep on stuff.depid=dep.id;
select sf.stuff_id,sf.name,dp.func,dp.address from stuff sf inner join dep dp on sf.depid=dp.id;
select sf.stuff_id,sf.name,dp.func,dp.address from stuff sf,dep dp where sf.depid=dp.id;

select * from stuff left join dep on stuff.depid=dep.id;

select * from stuff right join dep on stuff.depid=dep.id;
drop table stuff;
```

![image-20231219135148254](JavaWeb/image-20231219135148254.png) 

给表起别名，字段起别名；

![image-20231219135456151](JavaWeb/image-20231219135456151.png) 



##### 外连接

> 左外连接：
>
> `select 字段列表 from 表1 left [outer] join 表2 on 条件;`
>
> 右外连接：
>
> `select 字段列表 from 表1 right [outer] join 表2 on 条件;`

+ 左外连接

  查询A表所有数据+交集数据

  ![image-20231219172311638](JavaWeb/image-20231219172311638.png) 

+ 右外连接

  查询B表所有数据+交集数据

  ![image-20231219172322831](JavaWeb/image-20231219172322831.png)  



代码演示：

![image-20231219140735962](JavaWeb/image-20231219140735962.png) 

![image-20231219140051069](JavaWeb/image-20231219140051069.png) 

左外连接

![image-20231219140903659](JavaWeb/image-20231219140903659.png) 

右外连接

![image-20231219140841377](JavaWeb/image-20231219140841377.png) 

##### 子查询

问题引入：

![image-20231219141359873](JavaWeb/image-20231219141359873.png) 

查出工资高于李四的人员信息

1. 李四的工资

   ![image-20231219172335441](JavaWeb/image-20231219172335441.png)  

2. 查询高于2000的人员信息

   ![image-20231219172344529](JavaWeb/image-20231219172344529.png) 

如何把这两个步骤合二为一？？？

![image-20231219141652509](JavaWeb/image-20231219141652509.png) 

> 字查询
>
> 查询中嵌套语句，称嵌套查询为子查询.

+ 单行单列

![image-20231219141844983](JavaWeb/image-20231219141844983.png)

上面问题引入就是 

+ 多行单列

> `select 字段列表 from where 字段名 in (子查询)`
>
> 作为条件之，使用in关键字进行条件判断

![image-20231219142501583](JavaWeb/image-20231219142501583.png)

如果要查询郑州和杭州的呢？

![image-20231219142747485](JavaWeb/image-20231219142747485.png)  

+ 多行多列

> `select 字段列表 from(子查询得到的虚拟表) where 条件;`
>
> 作为虚拟表

![image-20231219144109298](JavaWeb/image-20231219144109298.png) 

![image-20231219144313662](JavaWeb/image-20231219144313662.png) 

#### 多表查询的案例

[10多表查询案例](https://www.bilibili.com/video/BV1Qf4y1T7Hx?p=28&vd_source=45cf0df1cf29fd12377b442a74b95876)





### 事务

#### 事务简介

![image-20231219144637434](JavaWeb/image-20231219144637434.png)

问题引入 

![image-20231219145223921](JavaWeb/image-20231219145223921.png) 

语法

> 开启事务
>
> `START TRANSACTION;`or`BEGIN;`
>
> 提交事务
>
> `COMMIT;`
>
> 回滚事务
>
> `ROLLBACK;`

#### 事务操作

1. 查询李四的余额
2. 李四金额-500
3. 张三金额+500





begin之后开启事务，先是在模拟操作一样

自己这里在扣，与此同时其他端还是初始状态

当遇到错误了，rollback就回到初始状态了 

![image-20231219150929139](JavaWeb/image-20231219150929139.png) 

现在

![image-20231219151040612](JavaWeb/image-20231219151040612.png) 

![image-20231219151058996](JavaWeb/image-20231219151058996.png) 

在另一端还是看到的是初始状态，因为没有提交



---

现在修改了问题，，完成整个事务

就真正完成了转账操作

![PixPin12-19_15-13-13](JavaWeb/PixPin12-19_15-13-13.gif)

测试代码：

```sql
create table account(
id int primary key auto_increment,
name varchar(10),
money int
);

insert into account(name,money) values("张三",1000);
insert into account(name,money) values("李四",1000);

select * from account;

update account set money=1000;

begin;
update account set money=500 where name="李四";
-- 出错了
update account set money=1500 where name="张三";
-- rollback;
commit;
```

#### 事物四大特征

面试问题？：

![image-20231219151615416](JavaWeb/image-20231219151615416.png) 

mysql默认写一句sql语句就是默认自带执行的，后面尾随了commit

![image-20231219151908708](JavaWeb/image-20231219151908708.png) 

```sql
select @@autocommit;
```

修改为手动提交

```sql
set @@sautocommit=0;
```

之后的操作都是临时的，没有真正的改掉数据，需要commit才能真正修改硬盘上的数据.
