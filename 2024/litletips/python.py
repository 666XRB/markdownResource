import os

def create(n):
    for i in range(1,n+1):
        filename=f"数据结构第{i}周.md"
        with open(filename,'w') as file:
            file.write(f"这是数据结构第{i}周的内容")

if __name__=="__main__":
    try:
        n=int(input("请输入你要创建多少个.md文档"))
        create(n)
        print("芜湖，创建成功")

    except ValueError:
        print("请输入有效的数ok？")
    except Exception as e:
        print("看看你自己报的错"+e);
