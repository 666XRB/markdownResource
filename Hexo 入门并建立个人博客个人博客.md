# Hexo 入门并建立个人博客个人博客



### 步骤 1: 安装 Node.js 和 Git
Hexo 是基于 Node.js 的，因此首先需要安装 Node.js。此外，还需要安装 Git 作为版本控制工具。

- [Node.js](https://nodejs.org/)
- [Git ](https://git-scm.com/)

安装完成后，通过以下命令验证它们是否成功安装：

```bash
node -v
npm -v
git --version
```

![image-20231120201612567](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231120201612567.png) 

### 步骤 2: 安装 Hexo

打开终端（命令行界面）并运行以下命令来安装 Hexo：

```bash
npm install -g hexo-cli
```

### 步骤 3: 创建 Hexo 项目
选择一个文件夹作为你的博客目录，然后在终端中运行以下命令来初始化 Hexo 项目：

```bash
hexo init myblog
cd my-blog
npm install
```

> `hexo init myblog`
>
> 会从 Hexo 的模板库中克隆一个基本的博客结构到指定的目录（`myblog`）
>
> 。这个模板包含了一些默认的配置文件、示例文章以及其他必要的文件，提供了一个快速启动 Hexo 博客的起点。会创一个文件夹myblog里面有依赖项
>
> > `hexo init`这个命令是自动生成hexo目录时使用的命令，使用他有一个前提是==必须是空文件夹==
>
> `npm install`
>
> 会根据项目根目录下的 `package.json` 文件中列出的依赖信息，从 npm（Node.js 包管理器）中安装这些依赖项。这些依赖项包括 Hexo 本身以及其他一些插件和工具，它们是构建、生成和部署 Hexo 博客所必需的。
>
> 

这将在你选择的目录中创建一个 Hexo 项目，并安装所需的依赖项。

![image-20231120202559252](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231120202559252.png) 

![image-20231120202009690](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231120202009690.png)

> 至此已经完成了很大一部分了

### 步骤 4: 配置 Hexo

github创建一个仓库

![image-20231120203223928](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231120203223928.png) 

打开 `_config.yml` 文件以配置 Hexo。需要配置 `url` 和 `deploy` 部分，以便在发布博客时正确设置链接。

![image-20231120205038448](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231120205038448.png) 

```yaml
url: https://your-blog-url.com
deploy:
  type: git
  repo: https://github.com/yourusername/yourusername.github.io.git
  branch: master
```

> 1. **`url: https://your-blog-url.com`：**
>    - 这个是博客的基本网址，它用于生成你博客文章中的链接。在这里，`https://your-blog-url.com` 是一个占位符，你需要将它替换成你实际博客的域名或者自定义的网址。
> 2. **`deploy` 部分：**
>    - 这个部分是用于配置 Hexo 如何部署生成的静态文件。在这个例子中，配置了使用 Git 进行部署。
>    - **`type: git`：** 表示使用 Git 进行部署。
>    - **`repo: https://github.com/yourusername/yourusername.github.io.git`：** 这是你的博客的 GitHub 仓库地址。一般来说，GitHub Pages 会将你的个人页面托管在 `https://yourusername.github.io`，所以仓库名要按照一定的规则来命名。具体规则是 `<yourusername>.github.io`，==其中 `<yourusername>` 是你的 GitHub 用户名。这样的仓库名才能被 GitHub 自动识别为一个 GitHub Pages 仓库，从而用于托管你的博客。==
>    - **`branch: master`：** 这是你的 GitHub Pages 仓库的分支，一般是 `master` 分支。这表示 Hexo 会将生成的静态文件推送到这个分支上。
>
> ==确保 `repo` 符合 GitHub Pages 的规范，即仓库名为 `<yourusername>.github.io`。==

### 步骤 5: 创建一篇新博文

运行以下命令创建一篇新的博文：

```bash
hexo new "My First Post"
```

这将在 `source/_posts` 目录中创建一个 Markdown 文件，其中包含你的新博文的初始内容。

### 步骤 6: 本地预览

使用以下命令启动本地服务器并在浏览器中预览你的博客：

```bash
hexo server
```

然后在浏览器中访问 `http://localhost:4000`。

![image-20231120202902347](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231120202902347.png) 

### 步骤 7: 发布到 GitHub Pages

安装hexo-deployer-git 自动部署发布工具

```sql
npm install hexo-deployer-git --save
```

![image-20231120204051983](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231120204051983.png) 

如果你希望将你的博客部署到 GitHub Pages，运行以下命令：

```bash
hexo clean
hexo deploy
```

这将清理之前的部署并将新的博客版本发布到你在 `_config.yml` 中配置的 GitHub 仓库。

![image-20231120205130146](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231120205130146.png) 

> ```
> hexo c
> hexo g
> hexo s
> ```
>
> 三连！

[666xrb.github.io)](https://666xrb.github.io/)

### config.yml配置文件

```bash

# Hexo Configuration

## Docs: http://hexo.io/docs/configuration.html

## Source: https://github.com/hexojs/hexo/

# Site #站点信息

title:  #标题

subtitle:  #副标题

description:  #站点描述，给搜索引擎看的

author:  #作者

email:  #电子邮箱

language: zh-CN #语言

# URL #链接格式

url:  #网址

root: / #根目录

permalink: :year/:month/:day/:title/ #文章的链接格式

tag_dir: tags #标签目录

archive_dir: archives #存档目录

category_dir: categories #分类目录

code_dir: downloads/code

permalink_defaults:

# Directory #目录

source_dir: source #源文件目录

public_dir: public #生成的网页文件目录

# Writing #写作

new_post_name: :title.md #新文章标题

default_layout: post #默认的模板，包括 post、page、photo、draft（文章、页面、照片、草稿）

titlecase: false #标题转换成大写

external_link: true #在新选项卡中打开连接

filename_case: 0

render_drafts: false

post_asset_folder: false

relative_link: false

highlight: #语法高亮

enable: true #是否启用

line_number: true #显示行号

tab_replace:

# Category & Tag #分类和标签

default_category: uncategorized #默认分类

category_map:

tag_map:

# Archives

2: 开启分页

1: 禁用分页

0: 全部禁用

archive: 2

category: 2

tag: 2

# Server #本地服务器

port: 4000 #端口号

server_ip: localhost #IP 地址

logger: false

logger_format: dev

# Date / Time format #日期时间格式

date_format: YYYY-MM-DD #参考http://momentjs.com/docs/#/displaying/format/

time_format: H:mm:ss

# Pagination #分页

per_page: 10 #每页文章数，设置成 0 禁用分页

pagination_dir: page

# Disqus #Disqus评论，替换为多说

disqus_shortname:

# Extensions #拓展插件

theme: landscape-plus #主题

exclude_generator:

plugins: #插件，例如生成 RSS 和站点地图的

- hexo-generator-feed

- hexo-generator-sitemap

# Deployment #部署，将 lmintlcx 改成用户名

deploy:

type: git

repo: 创建仓库成功后的http地址

branch: master

```

### 常见的问题

```
hexo  d
```

![image-20231120204239832](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231120204239832.png) 

source的文章要用命令生成啊

```bash
hexo new "sadsda"
```



### 博客美化

[【精选】Butterfly主题安装文档(三)之主题配置2_butterfly activate_power_mode-CSDN博客](https://blog.csdn.net/qq_38157825/article/details/112783083?ops_request_misc=%7B%22request%5Fid%22%3A%22169548330616800186546490%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=169548330616800186546490&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-112783083-null-null.142^v94^control&utm_term=_config.butterfly.yml&spm=1018.2226.3001.4187)
