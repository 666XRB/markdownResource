# 180Mins爬虫?

![image-20230718172722933](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20230718172722933.png)

## 网络爬虫的概述

### 网络爬虫与浏览器的联系

浏览器与对象服务器

> ### 发送请求，获取响应数据，进行渲染

爬虫程序与对象服务器

> ### 发送请求，获取响应数据

网络爬虫的作用

### 爬取信息

模拟客户端发送请求，按照规则返回信息



## Requests库

> #### 优雅简单的http请求库

作用，发送请求获取响应数据3



### 基本使用



```python
#导入模块
import requests


#发送get请求，获取响应
data=requests.get("https://www.bilibili.com/video/BV1464y1c7Eq?p=3&spm_id_from=pageDriver&vd_source=45cf0df1cf29fd12377b442a74b95876")
print(data.content.decode())



```

data.text是响应体的str类型，查看data.encoding，修改属性为utf8，再打印就ok了

data.content是响应体的bytes类型，需要encode解码

## beautiful soup库

`BeautifulSoup()`可以接受以下参数：

1. `markup`：要解析的HTML或XML文档内容，可以是字符串、文件对象或类文件对象。
2. `features`：**解析器**的名称，可以是以下几种：
   - `"html.parser"`：Python标准库中的HTML解析器。
   - `"lxml"`：使用lxml库作为解析器。
   - `"lxml-xml"`：使用lxml库解析XML文档。
   - `"xml"`：Python标准库中的XML解析器。
   - `"html5lib"`：使用html5lib库作为解析器，它可以处理一些比较复杂的HTML文档。
3. `from_encoding`：指定解析器使用的编码方式，默认为`None`，表示自动检测编码。
4. `exclude_encodings`：要排除的编码列表，用于指定解析器不应该尝试的编码。
5. `element_classes`：一个字典，用于指定特定标签名称对应的自定义类。
6. `builder`：指定解析器使用的解析树构建器。

```python
from bs4 import BeautifulSoup

html = '''
<html>
<body>
    <h1>BeautifulSoup Demo</h1>
    <ul>
        <li>Item 1</li>
        <li>Item 2</li>
        <li>Item 3</li>
    </ul>
</body>
</html>
'''

soup = BeautifulSoup(html, 'html.parser')
```

在上述示例中，我们使用`BeautifulSoup()`构造函数将HTML字符串`html`解析为一个BeautifulSoup对象。解析器的名称为`html.parser`，这是Python标准库中的HTML解析器。可以根据需要选择不同的解析器。

---

> 从html xml 中	提取数据

---

BeautifulSoup(response.content.decode(),"xml")是用来解析XML格式的文档的对象。

该对象的方法包括：

- `name`：要查找的标签名称或标签名称列表，可以是字符串或正则表达式。
- `attrs`：要查找的标签的属性，可以是字典或关键字参数。
- `recursive`：是否递归查找，默认为True，表示在子孙节点中查找。
- `text`：要查找的标签的文本内容。
- `**kwargs`：其他关键字参数，用于查找指定属性值的标签。

1. find(name, attrs, recursive, string, **kwargs): 在文档中找到第一个匹配给定参数的标签，并返回该标签的内容。
2. find_all(name, attrs, recursive, string, limit, \**kwargs): 在文档中找到所有匹配给定参数的标签，**并返回一个列表**。
3. find_parents(name, attrs, recursive, string, **kwargs): 在文档中找到所有匹配给定参数的标签的父标签，并返回一个生成器。
4. find_parent(name, attrs, recursive, string, **kwargs): 在文档中找到第一个匹配给定参数的标签的父标签，并返回该标签的内容。
5. find_next_siblings(name, attrs, recursive, string, **kwargs): 在文档中找到所有匹配给定参数的标签的下一个兄弟标签，并返回一个生成器。
6. find_next_sibling(name, attrs, recursive, string, **kwargs): 在文档中找到第一个匹配给定参数的标签的下一个兄弟标签，并返回该标签的内容。
7. find_previous_siblings(name, attrs, recursive, string, **kwargs): 在文档中找到所有匹配给定参数的标签的前一个兄弟标签，并返回一个生成器。
8. find_previous_sibling(name, attrs, recursive, string, **kwargs): 在文档中找到第一个匹配给定参数的标签的前一个兄弟标签，并返回该标签的内容。
9. find_all_next(name, attrs, recursive, string, limit, **kwargs): 在文档中找到所有匹配给定参数的标签的后续标签，并返回一个生成器。
10. find_next(name, attrs, recursive, string, **kwargs): 在文档中找到第一个匹配给定参数的标签的后续标签，并返回该标签的内容。
11. find_all_previous(name, attrs, recursive, string, limit, **kwargs): 在文档中找到所有匹配给定参数的标签的前面标签，并返回一个生成器。
12. find_previous(name, attrs, recursive, string, **kwargs): 在文档中找到第一个匹配给定参数的标签的前面标签，并返回该标签的内容。
13. select(selector): 使用CSS选择器来选择文档中的元素，并返回一个列表。

还有其他一些方法用于处理标签内容、属性、文本等。

```python
from bs4 import BeautifulSoup
import requests


response=requests.get("http://www.baidu.com")
# print(response.encoding)
# response.encoding="utf8"
# print(response.text)
data=response.content.decode()

soup=BeautifulSoup(response.content.decode(),"xml")
print(soup)
```



### find方法的实例

```python
from bs4 import BeautifulSoup
import requests



html='''<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>东风校区图书馆开放时间</title>
    <style>
        table{
            border-collapse: collapse;
        }
    </style>
</head>
<body>
    <table border="1" bgcolor="pink">
        <caption><b>东风校区图书馆开放时间</b></caption>
        <thead>
        <tr bgcolor="yellow">
            <th>楼层区域</th>
            <th>周一到周五</th>
            <th>周六，周日</th>
            <th>备注</th>
        </tr>
        </thead>
        <tbody>
        <tr>
            <td bgcolor="green">东风校区图书馆二，三，四层</td>
            <td>7:30-22:00</td>
            <td>7:30-22:00</td>
            <td rowspan="2" bgcolor="purple">周四下午政治,业务学习(12:00-18:00闭馆)</td>
        </tr>
        <tr>
            <td bgcolor="green">东风校区图书馆五层</td>
            <td>上午:08:00-12:00<br>下午:15:00-18:00(夏)<br>14:00-15:30(冬)</td>
            <td>不开放</td>
        </tr>
        </tbody>
        今天是否去图书馆？<label><input type="radio" name="heh"> 去！</label>
        <label><input type="radio" name="heh"> 不去！</label>
        &#128515;
        &#128516;
        &#128517;




    </table>
</body>
</html>'''




soup=BeautifulSoup(html,"html.parser")

data1=soup.find("title")
print(data1)
data_td=soup.find("td")
print(data_td)
data_text=soup.find(string="备注")
print(data_text)
data_class=soup.find(bgcolor="purple")
print(data_class)
data_aims=soup.find(attrs={"bgcolor":"purple"})
# print("-------------")
print(data_aims)


# <title>东风校区图书馆开放时间</title>
# <td bgcolor="green">东风校区图书馆二，三，四层</td>
# 备注
# <td bgcolor="purple" rowspan="2">周四下午政治,业务学习(12:00-18:00闭馆)</td>
# <td bgcolor="purple" rowspan="2">周四下午政治,业务学习(12:00-18:00闭馆)</td>
```

### TAG对象

![image-20230718191518369](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20230718191518369.png)

```python
<class 'bs4.element.Tag'>
<class 'bs4.element.Tag'>
```







### robots.txt协议

网站后面加上/robots.txt得到君子协议，哪些可以爬，哪些不可以爬取





### http协议

服务器与客户端交互数据的一种方式

https是安全的数据传输，密钥

### User-Agent

User-Agent是HTTP请求头中的一个字段，用于标识发送请求的客户端（例如浏览器、爬虫等）。

![image-20230719104225944](C:\Users\许闰博\AppData\Roaming\Typora\typora-user-images\image-20230719104225944.png)

### `json.dump()`和`json.dumps()`

`json.dump()`和`json.dumps()`都是Python中用于将数据对象转换为JSON格式的方法，但它们之间有一些区别。

- `json.dump()`: 这个方法用于将数据对象转换为JSON格式，并将其写入文件对象中。它接受两个参数：第一个参数是要转换为JSON的数据对象，第二个参数是要写入的文件对象。示例代码如下：

  ```python
  import json

  data = {"name": "John", "age": 30}
  with open("data.json", "w") as file:
      json.dump(data, file)
  ```

  在上述代码中，`data`是一个字典对象，我们使用`json.dump()`方法将其转换为JSON格式，并将结果写入名为"data.json"的文件中。

- `json.dumps()`: 这个方法用于将数据对象转换为JSON格式，并返回一个字符串。它只接受一个参数，即要转换为JSON的数据对象。示例代码如下：

  ```python
  import json
  
  data = {"name": "John", "age": 30}
  json_str = json.dumps(data)
  ```

  在上述代码中，`data`是一个字典对象，我们使用`json.dumps()`方法将其转换为JSON格式，并将结果赋值给`json_str`变量。

json.dump()`用于将数据对象转换为JSON格式，并将其写入文件对象中，而`json.dumps()`用于将数据对象转换为JSON格式，并返回一个字符串`。

### requests`库中`Response`对象的response.json()

`response.json()`是`requests`库中`Response`对象的一个方法，用于将服务器返回的JSON格式的响应体转换为Python字典对象或列表对象。

当服务器返回的响应体是JSON格式时，你可以使用`response.json()`方法来方便地将其转换为Python对象，以便于后续的数据处理和操作。

示例代码如下：

```python
import requests

response = requests.post(url=aim_url, headers=headers, params=data_dict)
dic_obj = response.json()
```

在上述代码中，我们发送了一个POST请求，并得到了服务器返回的响应。然后，我们使用`response.json()`方法将响应体转换为Python字典对象，并将结果赋值给`dic_obj`变量。

`response.json()`**方法只能用于处理服务器返回的JSON格式的响应体。**如果响应体不是有效的JSON格式，或者服务器返回的是其他类型的数据（如HTML文档、纯文本等），那么调用`response.json()`方法会抛出`json.decoder.JSONDecodeError`异常。在这种情况下，你可以使用`response.text`属性获取响应体的文本内容，然后根据实际情况进行进一步的处理。

### 百度翻译案例

```python
aim_url="https://fanyi.baidu.com/sug"#抓包工具捕获
import requests,json
#ua伪装
headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 Edg/114.0.1823.82"
}
#动态
word=input("enter a world")
data_dict={
    "kw":word
}
#发送请求
response=requests.post(url=aim_url,headers=headers,params=data_dict)
#获取相应数据
dic_obj=response.json()
# print(dic_obj)

# position=word+".json"
# f=open(position,"w",encoding="utf8")
# json.dump(obj=dic_obj,fp=f,ensure_ascii=False)

# print(len(dic_obj["data"]))
for i in dic_obj["data"]:
    for k in i:
        print(k,end=":")
        print(i[k])


```

### 爬取豆瓣电影名

```python
import time
import requests
import json
import tqdm
aim_url="https://movie.douban.com/j/chart/top_list"

headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 Edg/114.0.1823.82"
}
count=input("想要爬取前几部数据?")
mydict={
    "type": "11",
    "interval_id":"100:90",
    "action":"",
    "start": "1",
    "limit": count
}
response=requests.get(url=aim_url,headers=headers,params=mydict)
print(time.time())
star_time=time.time()
data=response.json()
# print(data)
# with open("./豆瓣.txt","a",encoding="utf8") as fp :
#     json.dump(data,fp=fp,ensure_ascii=False)

for k,item in enumerate(tqdm.tqdm(data, desc="Processing data")):
    print(f"第{k+1}部:{item['title']}")
    # time.sleep(0.1)
end_time = time.time()

print(f"爬取{count}部成功,用时{end_time-star_time}s")
    # 创建了一个进度条对象，然后将其作为可迭代对象传递给enumerate函数。在每次迭代时，进度条会自动更新并显示当前的进度。


```

time.time()获取子1970年开始到现在经过的秒数

### 	获取本地时间

```python
import time
local_time=time.localtime()

str_localtime=time.strftime("%Y-%m-%d %H:%M:%S")
print(f"当前本地时间为{str_localtime}",end="")

```

### 判断是否是ajax请求

当输入查询的东西后，点击搜索，如过url变了就算ajax请求，如果没变就算get请求，ajax是局部变化 。
