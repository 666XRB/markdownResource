# Spring注解开发

## 注解开发定义bean

原先

```xml
<!--    <bean id="studentdao" class="com.hello.dao.impl.StudentDaoimpl"/>-->
```

### StudentDao接口

```java
package com.hello.dao;

public interface StudentDao {
    void save();
}

```

### StudentDaoimpl实现类

```java
package com.hello.dao.impl;

import com.hello.dao.StudentDao;
import com.hello.dao.UserDao;
import org.springframework.stereotype.Component;

@Component("studentDao")
public class StudentDaoimpl implements StudentDao {
    @Override
    public void save() {
        System.out.println("sssssdao save....");
    }

}

```

### 测试代码

```java
package com.hello;

import com.hello.dao.StudentDao;
import com.hello.service.BookService;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class App10 {
    public static void main(String[] args) {

        ClassPathXmlApplicationContext applicationContext=new ClassPathXmlApplicationContext("ApplicationContext.xml");

        StudentDao studentdao= (StudentDao) applicationContext.getBean("studentDao");
        studentdao.save();


    }
}

```

### Applicationcontext,xml

```xml
    <context:component-scan base-package="com.hello.dao.impl"/>
```

```xml
    <context:component-scan base-package="com.hello"/>
```

![image-20240406152853821](spring%E6%B3%A8%E8%A7%A3%E5%BC%80%E5%8F%91/image-20240406152853821.png) 

### -----------------------------

@component

```java
package com.hello.dao.impl;

import com.hello.dao.StudentDao;
import com.hello.dao.UserDao;
import org.springframework.stereotype.Component;

@Component
public class StudentDaoimpl implements StudentDao {
    @Override
    public void save() {
        System.out.println("sssssdao save....");
    }

}

```

按照类型去找

```java
package com.hello;

import com.hello.dao.StudentDao;
import com.hello.service.BookService;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class App10 {
    public static void main(String[] args) {

        ClassPathXmlApplicationContext applicationContext=new ClassPathXmlApplicationContext("ApplicationContext.xml");

        StudentDao studentdao= (StudentDao) applicationContext.getBean(StudentDao.class);
        studentdao.save();


    }
}

```

### 小结

![image-20240406153147313](spring%E6%B3%A8%E8%A7%A3%E5%BC%80%E5%8F%91/image-20240406153147313.png) 







### 衍生注解  

![image-20240406153233524](spring%E6%B3%A8%E8%A7%A3%E5%BC%80%E5%8F%91/image-20240406153233524.png) 

作用一样，只是好区分，MVC





## 纯注解开发

不写配置文件。

换一种形式去表示

```xml
    <context:component-scan base-package="com.hello.dao.impl"/>
```

新建config包下的配置类

### 配置类SpringConfig.java

![image-20240406154233477](spring%E6%B3%A8%E8%A7%A3%E5%BC%80%E5%8F%91/image-20240406154233477.png) 

```java
package com.hello.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
    //代表这是配置类
@ComponentScan("com.hello")
    //代表了扫描路径
public class SpringConfig {

}

```

### 测试代码

现在不需要配置文件了

```java
import com.hello.config.SpringConfig;
import com.hello.dao.StudentDao;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class App11 {
    public static void main(String[] args) {

//        ClassPathXmlApplicationContext applicationContext=new ClassPathXmlApplicationContext("ApplicationContext.xml");
//
//        StudentDao studentdao= (StudentDao) applicationContext.getBean(StudentDao.class);
//        studentdao.save();


        ApplicationContext ctx=new AnnotationConfigApplicationContext(SpringConfig.class);

        StudentDao studentDao= (StudentDao) ctx.getBean("studentDao");
        studentDao.save();


    }
}

```

![image-20240406154226144](spring%E6%B3%A8%E8%A7%A3%E5%BC%80%E5%8F%91/image-20240406154226144.png) 

### 小结 

![image-20240406154616073](spring%E6%B3%A8%E8%A7%A3%E5%BC%80%E5%8F%91/image-20240406154616073.png) 

多个包如何配？数组的形式写

![image-20240406154733820](spring%E6%B3%A8%E8%A7%A3%E5%BC%80%E5%8F%91/image-20240406154733820.png) 

意义

![image-20240406154754168](spring%E6%B3%A8%E8%A7%A3%E5%BC%80%E5%8F%91/image-20240406154754168.png) 

----

![image-20240406154852332](spring%E6%B3%A8%E8%A7%A3%E5%BC%80%E5%8F%91/image-20240406154852332.png) 





## Bean管理

































































































































