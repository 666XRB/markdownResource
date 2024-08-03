# 定义栈类
class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def top(self):
        return self.items[-1]

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)

# 创建栈实例
stack_example = Stack()

# 向栈中压入元素
stack_example.push(1)
stack_example.push(2)
stack_example.push(3)

# 弹出栈顶元素
popped_item = stack_example.pop()
print("Popped item:", popped_item)  # 输出: Popped item: 3

# 查看栈顶元素
top_item = stack_example.top()
print("Top item:", top_item)  # 输出: Top item: 2

# 检查栈是否为空
is_empty = stack_example.is_empty()
print("Is the stack empty?", is_empty)  # 输出: Is the stack empty? False

# 获取栈的大小
stack_size = stack_example.size()
print("Stack size:", stack_size)  # 输出: Stack size: 2
