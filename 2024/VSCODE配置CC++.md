# VSCODE配置C/C++

## VScode下载安装

[Visual Studio Code - Code Editing. Redefined](https://code.visualstudio.com/)



## g++下载安装

[MinGW Distro - nuwen.net](https://nuwen.net/mingw.html)

自己选择安装路径，安装的路径需要记住

注意路径中不能出现中文

添加环境变量

测试安装成功：

`g++ --version`

![image-20240516113306282](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20240516113306282.png) 



## 配置代码环境

创建一个文件夹`DATASTRUCT`，用vscode打开

### 创建一个`.vscode`文件夹

四个文件

### `c_cpp_properties.json`

修改` "compilerPath": "C:/MinGW/bin/g++.exe",`

![image-20240516113938795](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20240516113938795.png) 

```json
{
  "configurations": [
    {
      "name": "Win64",
      "includePath": ["${workspaceFolder}/**"],
      "defines": ["_DEBUG", "UNICODE", "_UNICODE"],
      "windowsSdkVersion": "10.0.18362.0",
        
      "compilerPath": "C:/MinGW/bin/g++.exe",

      "cStandard": "c17",
      "cppStandard": "c++17",
      "intelliSenseMode": "gcc-x64"
    }
  ],
  "version": 4
}
```



### `launch.json`

修改`        "miDebuggerPath": "C:\\MinGW\\bin\\gdb.exe",`

```json
{
    "version": "0.2.0",
    "configurations": [
      {
        "name": "(gdb) Launch", 
        "type": "cppdbg", 
        "request": "launch", 
        "program": "${fileDirname}\\${fileBasenameNoExtension}.exe", 
        "args": [], 
        "stopAtEntry": false,
        "cwd": "${workspaceRoot}",
        "environment": [],
        "externalConsole": true, 
        "MIMode": "gdb",
          
        "miDebuggerPath": "C:\\MinGW\\bin\\gdb.exe",
          
        "preLaunchTask": "g++",
        "setupCommands": [
          {
            "description": "Enable pretty-printing for gdb",
            "text": "-enable-pretty-printing",
            "ignoreFailures": true
          }
        ]
      }
    ]
  }
```



### `settings.json`

```json
{
    "files.associations": {
      "*.py": "python",
      "iostream": "cpp",
      "*.tcc": "cpp",
      "string": "cpp",
      "unordered_map": "cpp",
      "vector": "cpp",
      "ostream": "cpp",
      "new": "cpp",
      "typeinfo": "cpp",
      "deque": "cpp",
      "initializer_list": "cpp",
      "iosfwd": "cpp",
      "fstream": "cpp",
      "sstream": "cpp",
      "map": "c",
      "stdio.h": "c",
      "algorithm": "cpp",
      "atomic": "cpp",
      "bit": "cpp",
      "cctype": "cpp",
      "clocale": "cpp",
      "cmath": "cpp",
      "compare": "cpp",
      "concepts": "cpp",
      "cstddef": "cpp",
      "cstdint": "cpp",
      "cstdio": "cpp",
      "cstdlib": "cpp",
      "cstring": "cpp",
      "ctime": "cpp",
      "cwchar": "cpp",
      "exception": "cpp",
      "ios": "cpp",
      "istream": "cpp",
      "iterator": "cpp",
      "limits": "cpp",
      "memory": "cpp",
      "random": "cpp",
      "set": "cpp",
      "stack": "cpp",
      "stdexcept": "cpp",
      "streambuf": "cpp",
      "system_error": "cpp",
      "tuple": "cpp",
      "type_traits": "cpp",
      "utility": "cpp",
      "xfacet": "cpp",
      "xiosbase": "cpp",
      "xlocale": "cpp",
      "xlocinfo": "cpp",
      "xlocnum": "cpp",
      "xmemory": "cpp",
      "xstddef": "cpp",
      "xstring": "cpp",
      "xtr1common": "cpp",
      "xtree": "cpp",
      "xutility": "cpp",
      "stdlib.h": "c",
      "string.h": "c"
    },
    "editor.suggest.snippetsPreventQuickSuggestions": false,
    "aiXcoder.showTrayIcon": true
  }
```



### `tasks.json`

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "g++",
            "command": "g++",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}.exe"
            ],
            "problemMatcher": {
                "owner": "cpp",
                "fileLocation": [
                    "relative",
                    "${workspaceRoot}"
                ],
                "pattern": {
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "column": 3,
                    "severity": 4,
                    "message": 5
                }
            },
            "group": "build"
        },
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe 生成活动文件",
            "command": "C:/mingw64/bin/g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "C:/mingw64/bin"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ]
}
```





## 测试

`hello.cpp`

```c++
#include <iostream>

using namespace std;


int main()
{
    cout<<"你好啊helloworld"<<endl;
    return 0;
}
```

现在默认是![image-20240516114518154](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20240516114518154.png) 

所以会出现

![image-20240516114535257](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20240516114535257.png) 

修改编码

![image-20240516114613443](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20240516114613443.png) 

重新运行

![image-20240516114623452](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20240516114623452.png) 





![image-20240516114656080](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20240516114656080.png) 