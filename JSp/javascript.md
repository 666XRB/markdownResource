# Javascript快速入土

 

## 什么是javascript

javaScript 是一种脚本编程语言，它可以在网页上实现复杂的功能，网页展现给你的不再是简单的静态信息，而是实时的内容更新——交互式的地图、2D/3D 动画、滚动播放的视频等等——JavaScript 就在其中。

> 结构 ：HTML
>
> 表现 ： CSS
>
> 行为 ：JavaScript

JavaScript和Java是完全不同的语言。

ECMAScrpt是最新的javascript的版本;



## javascript引入方式

### 内部式：

HTML内部嵌入

对于位置和数量没有限制

但是不能放在body里面

推荐放在body下面





```html
<script>
  // 在此编写 JavaScript 代码
</script>
```



### 外部式：

写在js文件里，然后引入。

```html
<script src="script.js" defer></script>
```



## javascript基础语法

### 书写语法

> 去分大小写
>
> 分号有无都可以
>
> 注释:	![image-20231225144120127](javascript/image-20231225144120127.png) 
>
> {}代表代码块
>
> 内部

![image-20231225145307241](javascript/image-20231225145307241.png) 

外部：

![image-20231225145327904](javascript/image-20231225145327904.png) 

嵌入

![image-20231225145336598](javascript/image-20231225145336598.png) 





### 输入输出语句

输出语句

![image-20231225144156440](javascript/image-20231225144156440.png)

window.alert(）警告

document.write()写入html输出

console.log()写入浏览器控制台

![image-20231225145144214](javascript/image-20231225145144214.png)

==alert和prompt他们会跳过页面渲染鲜卑执行而且啊，prompt优先执行==

### 变量

 ![image-20231225151724394](javascript/image-20231225151724394.png)

![image-20231225151905285](javascript/image-20231225151905285.png)

let声明的也就比较严格了。而且不可以重复声明更好接受  

let var

var不用了，会出bug

![image-20231225145455535](javascript/image-20231225145455535.png) 

命名方法和规则

![image-20231225145534539](javascript/image-20231225145534539.png) 

数组：

![image-20231225145626708](javascript/image-20231225145626708.png)

常量：

![image-20231225145642267](javascript/image-20231225145642267.png)  

### 数据类型

![image-20231225152240435](javascript/image-20231225152240435.png) 

![image-20231225145654213](javascript/image-20231225145654213.png) 

![image-20231225150144733](javascript/image-20231225150144733.png)

![image-20231225150202533](javascript/image-20231225150202533.png)

![image-20231225150225674](javascript/image-20231225150225674.png)   

![image-20231225150123381](javascript/image-20231225150123381.png)

typeof

![image-20231225152608190](javascript/image-20231225152608190.png)  

### 运算符

赋值运算符

![image-20231225150538802](javascript/image-20231225150538802.png) 

一元运算符

![image-20231225150600043](javascript/image-20231225150600043.png) 

比较运算符

![image-20231225150615076](javascript/image-20231225150615076.png)

逻辑运算符

![image-20231225150641280](javascript/image-20231225150641280.png) 

### 运算符优先级

![image-20231225150652663](javascript/image-20231225150652663.png) 

![image-20231225150305319](javascript/image-20231225150305319.png) 

![image-20231225150711757](javascript/image-20231225150711757.png) 

### 类型转换

![image-20231225153143168](javascript/image-20231225153143168.png)

  ![image-20231225153230378](javascript/image-20231225153230378.png)

![image-20231225153336454](javascript/image-20231225153336454.png)  

![image-20231225150408096](javascript/image-20231225150408096.png) 

![image-20231225150448107](javascript/image-20231225150448107.png)

![image-20231225152813574](javascript/image-20231225152813574.png)

小结：

![image-20231225153439605](javascript/image-20231225153439605.png)   

### 流程控制语句

![image-20231225150752716](javascript/image-20231225150752716.png) 

#### 分支语句

![image-20231225150854655](javascript/image-20231225150854655.png) 

![image-20231225150904302](javascript/image-20231225150904302.png)

![image-20231225150923045](javascript/image-20231225150923045.png) 

#### 循环语句

![image-20231225151012693](javascript/image-20231225151012693.png) 

![image-20231225151045654](javascript/image-20231225151045654.png) 

### 函数

![image-20231225154249089](javascript/image-20231225154249089.png) 

![image-20231225151328692](javascript/image-20231225151328692.png) 

![image-20231225151341941](javascript/image-20231225151341941.png)

无参函数

![image-20231225151352161](javascript/image-20231225151352161.png)

![image-20231225151428625](javascript/image-20231225151428625.png)

![image-20231225151443940](javascript/image-20231225151443940.png)

![image-20231225151520607](javascript/image-20231225151520607.png)      

### 作用域

![image-20231225151617641](javascript/image-20231225151617641.png) 

### 数组

![image-20231225155322605](javascript/image-20231225155322605.png)  

arry.length获得数组的长度 

类似java的集合，是变长课类型可变的数据，可以自动扩大

![image-20231225151209865](javascript/image-20231225151209865.png) 

![image-20231225151251075](javascript/image-20231225151251075.png)

![image-20231225151305753](javascript/image-20231225151305753.png)  

## javascript常用对象

Array数组对象

[JavaScript 数组 (w3school.com.cn)](https://www.w3school.com.cn/js/js_arrays.asp)

String字符串对象

[JavaScript 字符串 (w3school.com.cn)](https://www.w3school.com.cn/js/js_strings.asp) 

Object对象

[JavaScript 对象定义 (w3school.com.cn)](https://www.w3school.com.cn/js/js_object_definition.asp)

![image-20231227101818969](javascript/image-20231227101818969.png) 







## DOM

![image-20231227110306729](javascript/image-20231227110306729.png) 

### 获取elements！

![image-20231227110710777](javascript/image-20231227110710777.png)

## BOM

[JavaScript Window - 浏览器对象模型 (w3school.com.cn)](https://www.w3school.com.cn/js/js_window.asp)  

![image-20231227101920744](javascript/image-20231227101920744.png)

![image-20231227102035300](javascript/image-20231227102035300.png)  

![image-20231227102224644](javascript/image-20231227102224644.png) 

![image-20231227102644067](javascript/image-20231227102644067.png)



#### History 

![image-20231227102818567](javascript/image-20231227102818567.png)

![image-20231227103616519](javascript/image-20231227103616519.png) 

**window.location 对象可用于获取当前页面地址（URL）并把浏览器重定向到新页面。** 

 ## Cookie

![image-20231227105141097](javascript/image-20231227105141097.png) [JavaScript Cookies (w3school.com.cn)](https://www.w3school.com.cn/js/js_cookies.asp) 

## 事件监听

[JavaScript 事件 (w3school.com.cn)](https://www.w3school.com.cn/js/js_events.asp) 

![image-20231227113349040](javascript/image-20231227113349040.png) 

![image-20231227113331687](javascript/image-20231227113331687.png) 





## 表单验证

![image-20231227154051054](javascript/image-20231227154051054.png) 

```html
<form id="registerForm" action="" method="get">

    <input type="text" id="Username" placeholder="用户名">
    <span id="wrong1">用户名错误</span>


    <input type="password" id="Password" placeholder="密码">
    <span id="wrong2">密码错误</span>


    <input type="password" id="Phonenum" placeholder="手机号！">
    <span id="wrong3">手机号错误</span>


    <button type="submit">Register</button>
  </form>
```

```javascript

let userinput1=document.getElementById("Username");

let userinput2=document.getElementById("Password");

let userinput3=document.getElementById("Phonenum");
userinput1.onblur=usercheck;

function usercheck(){

    //获取密码
    let name=userinput1.value.trim();
    // alert(name);
    const ip1=document.getElementById("wrong1");
    let flag=name.length>6&&name.length<12;
    if(flag)
    {
        ip1.style.display="none";
    }
    else{
        ip1.style.display="block";
    } 
    return flag;

}


userinput2.onblur=passwordcheck;

function passwordcheck(){

    //获取密码
    let password=userinput2.value.trim();
    // alert(password);
    const ip2=document.getElementById("wrong2");
    let flag=password.length>=6;
    if(flag)
    {
        ip2.style.display="none";
    }
    else{
        ip2.style.display="block";
    } 
    return flag;

}
userinput3.onblur=phonecheck;

function phonecheck(){

    //获取密码
    let phonenum=userinput3.value.trim();
    // alert(phonenum);
    const ip3=document.getElementById("wrong3");
    let flag=phonenum.length==11;
    if(flag)
    {
        ip3.style.display="none";
    }
    else{
        ip3.style.display="block";
    } 
    return flag;

}

let ok=document.getElementById("registerForm");

ok.onsubmit=function(){
    // event.preventDefault();
    let flag=passwordcheck()&&usercheck()&&phonecheck();
    alert("提交成功！")
    return flag;
}
```

