# android编程题

## 界面布局

使用TableLayout布局实现一个简单的计算器界面。





## 常见控件

1. 开发一个整数加法的程序，实现将计算结果显示到界面上的功能。

2. 开发一个自定义对话框，其界面中显示标题、提示内容、确定和取消按钮。当点击回退健时，用于提示用户是否退出应用。

















## 编程题1

1、在MainActivity组件对应的布局文件里，定义了两个Button按钮，其id分别设置为button1和button2，单击按钮后，分别启动对应的SecondActivity组件和ThirdActivity组件。从MainActivity跳转到ThirdActivity时，往ThirdActivity传递一个Bundle类型的数据。当从ThirdActivity返回到MainActivity时，同时返回给MainActivity一个字符串数据。



1）调用其他Activity的主调组件MainActivity的代码如下：

```java
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 获取id为button1的按钮控件
        Button button1 = findViewById(R.id.button1); // (1-1)
        
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                // 隐式调用SecondActivity
                intent.setAction("android.intent.action.ysdy"); // (1-2)
                // 启动SecondActivity，第2个参数为请求码
                startActivityForResult(intent, 2); // (1-3)
            }
        });

        // 获取id为button2的按钮控件
        Button button2 = findViewById(R.id.button2); // (1-4)
        
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                // 显示调用ThirdActivity
                intent.setClass(MainActivity.this, ThirdActivity.class); // (1-5)
                
                // 设置Bundle类型数据
                Bundle bundle = new Bundle();
                bundle.putString("name", "张三");
                bundle.putInt("age", 20); // (1-6)
                
                // 通过意图对象携带数据
                intent.putExtra("data", bundle);
                
                // 启动ThirdActivity并请求数据回传，第2个参数为请求码
                startActivityForResult(intent, 3);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        
        // 判断是哪个Activity返回的数据，使用结果码
        if (resultCode == 3) {
            // 获取返回的数据
            String string = data.getStringExtra("hello");
            Toast.makeText(this, string, Toast.LENGTH_SHORT).show();
        }
    }
}

```



（2）其中，在清单文件里，对被调用的第2个Activity组件配置如下

```java
<activity
    android:name=".SecondActivity"
    android:label="隐式调用SecondActivity">
    <intent-filter>
        <action android:name="android.intent.action.ysdy" />
        <category android:name="android.intent.category.DEFAULT" />
    </intent-filter>
</activity>

```

（3）第2个Activity组件的代码如下：

```java
public class SecondActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
    }
}

```



（4）第3个Activity组件接收从MainActivity传递的捆绑数据，返回前设置非捆绑数据和结果码，其代码如下：

```java
public class ThirdActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_third);

        String receiver = "接收的数据如下: \n";
        Intent intent = getIntent();
        Bundle data = intent.getBundleExtra("data");  // 获取捆绑数据
        receiver += "name: " + data.getString("name") + "\n";
        receiver += "age: " + data.getInt("age");

        // 在屏幕上显示接收到的数据
        Toast.makeText(this, receiver, Toast.LENGTH_LONG).show();

        // 通过意图对象携带返回数据
        intent = new Intent();
        intent.putExtra("hello", "How are you?"); // (1-7)
        
        // 设置返回数据和结果码
        setResult(3, intent); // (1-8)
        
        // 结束Activity
        finish();
    }
}

```

> **(1-1) findViewById(R.id.button1)**: 用来获取id为button1的按钮控件。
>
> **(1-2) "android.intent.action.ysdy"**: 隐式调用SecondActivity时使用的动作名称，对应于清单文件中的 `<action android:name="android.intent.action.ysdy" />`。
>
> **(1-3) startActivityForResult(intent, 2)**: 启动SecondActivity，并传入请求码2。
>
> **(1-4) R.id.button2**: 用来获取id为button2的按钮控件。
>
> **(1-5) ThirdActivity.class**: 用于显示调用ThirdActivity。
>
> **(1-6) bundle.putInt("age", 20)**: 将年龄数据存入Bundle中。
>
> **(1-7) intent.putExtra("hello", "How are you?")**: 将返回的数据放入Intent中。
>
> **(1-8) setResult(3, intent)**: 设置结果码和返回数据。





## 编程题2

编写一个程序，根据不同的Uri获取联系人表中的相关信息如下所示：

（1）通过ContactsContract.Contacts.CONTENT_URI的Uri获取Contacts表中的联系人id和姓名，其字段分别为ContactsContract.Contacts._ID、ContactsContract.Contacts.DISPLAY_NAME。

（2）通过ContactsContract.CommonDataKinds.Phone.CONTENT_URI的Uri获取Data表中的联系人id和电话，其字段分别为ContactsContract.CommonDataKinds.Phone.CONTACT_ID、ContactsContract.CommonDataKinds.Phone.NUMBER。

请根据上述系统联系人数据库的相关信息，编写一个程序，用于读取系统联系人的姓名和电话，并将读取的信息显示在界面中。

```java
public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private TextView textView;
    private Button query_contacts;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        query_contacts = findViewById(R.id.query_contacts);
        query_contacts.setOnClickListener(this);

        textView = findViewById(R.id.tv);
    }

    @Override
    public void onClick(View v) {
        // 动态申请读取手机通讯录权限
        ActivityCompat.requestPermissions(MainActivity.this, new String[]{"android.permission.READ_CONTACTS"}, 1); // (2-1)
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);

        if (requestCode == 1) {
            for (int i = 0; i < permissions.length; i++) {
                if (permissions[i].equals("android.permission.READ_CONTACTS") && grantResults[i] == PackageManager.PERMISSION_GRANTED) { // (2-2)
                    Toast.makeText(MainActivity.this, "已获取权限", Toast.LENGTH_SHORT).show();
                    fetchContactInformation();
                } else {
                    finish();
                }
            }
        }
    }

    // 读取手机联系人信息的方法
    public void fetchContactInformation() {
        String id, name, phoneNumber;

        // 定义一个字符串变量，用于保存查询结果
        String contacts = "";

        // 获取内容解析器对象，用于对内容提供者的数据进行操作
        ContentResolver contentResolver = this.getContentResolver(); // (2-3)

        // 首先查询手机联系人表获取联系人的id和姓名
        Cursor cursor = contentResolver.query(ContactsContract.Contacts.CONTENT_URI, null, null, null, null);

        while (cursor != null && cursor.moveToNext()) {
            // 获取联系人id
            id = cursor.getString(cursor.getColumnIndex(ContactsContract.Contacts._ID)); // (2-4)

            // 获取联系人姓名
            name = cursor.getString(cursor.getColumnIndex(ContactsContract.Contacts.DISPLAY_NAME)); // (2-5)

            contacts += "姓名：" + name + "\n";

            // 然后查询手机联系人数据表获取联系人的电话号码
            // 根据id查询相应联系人的电话
            Cursor phoneCursor = contentResolver.query(
                    ContactsContract.CommonDataKinds.Phone.CONTENT_URI,
                    null,
                    ContactsContract.CommonDataKinds.Phone.CONTACT_ID + " = ?", // (2-6)
                    new String[]{id},
                    null
            );

            contacts += "电话：";

            while (phoneCursor != null && phoneCursor.moveToNext()) {
                phoneNumber = phoneCursor.getString(phoneCursor.getColumnIndex(ContactsContract.CommonDataKinds.Phone.NUMBER)); // (2-7)
                contacts += phoneNumber + " ";
            }

            contacts += "\n\n";
            if (phoneCursor != null) {
                phoneCursor.close();
            }
        }

        // 在界面上显示所查询到的所有手机联系人信息
        textView.setText(contacts);
        if (cursor != null) {
            cursor.close();
        }
    }
}

```

> 1. **(2-1) ActivityCompat.requestPermissions(MainActivity.this, new String[]{"android.permission.READ_CONTACTS"}, 1);**: 这是Android中用于动态申请权限的方法。第一个参数是Activity实例，第二个参数是要申请的权限列表，第三个参数是请求码。
> 2. **(2-2) PackageManager.PERMISSION_GRANTED**: 表示权限被授予的常量。如果用户同意授予权限，`grantResults`数组中的对应位置会是这个值。
> 3. **(2-3) this.getContentResolver()**: 用于获取`ContentResolver`实例。`ContentResolver`是Android中用于访问内容提供者(Content Provider)的数据接口。
> 4. **(2-4) ContactsContract.Contacts._ID**: 用于获取联系人ID的常量字段名。
> 5. **(2-5) ContactsContract.Contacts.DISPLAY_NAME**: 用于获取联系人姓名的常量字段名。
> 6. **(2-6) ContactsContract.CommonDataKinds.Phone.CONTACT_ID + " = ?"**: 用于查询电话时根据联系人ID过滤的查询条件。使用占位符`?`来避免SQL注入风险。
> 7. **(2-7) ContactsContract.CommonDataKinds.Phone.NUMBER**: 用于获取电话号码的常量字段名。
>
> ### 详细步骤
>
> 1. **初始化UI组件**：
>    - 获取按钮和文本视图。
>    - 设置按钮的点击事件。
> 2. **申请权限**：
>    - 在按钮点击事件中，使用`ActivityCompat.requestPermissions`方法动态申请读取联系人权限。
> 3. **处理权限结果**：
>    - 覆写`onRequestPermissionsResult`方法，判断权限是否被授予。如果被授予，则调用`fetchContactInformation`方法读取联系人信息，否则关闭Activity。
> 4. **读取联系人信息**：
>    - 使用`ContentResolver`查询联系人表和电话号码表。
>    - 遍历联系人表，获取每个联系人的ID和姓名。
>    - 使用联系人ID查询电话号码表，获取对应的电话号码。
>    - 将获取到的信息拼接成字符串，并显示在文本视图中。







## 广播机制

为了实现无序广播的发送和接收，我们需要编写两个主要部分的代码：发送广播的代码和接收广播的代码。以下是一个简单的例子，展示了如何在Android中发送和接收无序广播。

### 1. 定义广播接收器

首先，我们需要定义一个广播接收器，用于接收无序广播。可以在一个新的Java类中实现这个接收器：

```java
public class MyBroadcastReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        // 获取广播的数据
        String message = intent.getStringExtra("message");
        Toast.makeText(context, "Received Broadcast: " + message, Toast.LENGTH_SHORT).show();
    }
}
```

### 2. 注册广播接收器

接着，我们需要在`AndroidManifest.xml`文件中注册这个广播接收器，以便系统能够在应用未运行时接收广播：

```xml
<application
    ...>
    
    <receiver android:name=".MyBroadcastReceiver">
        <intent-filter>
            <action android:name="com.example.broadcast.MY_BROADCAST" />
        </intent-filter>
    </receiver>
    
</application>
```

### 3. 发送广播

接下来，我们需要编写代码来发送广播。可以在`MainActivity`中添加一个按钮，点击按钮后发送广播：

```java
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button sendBroadcastButton = findViewById(R.id.send_broadcast_button);
        sendBroadcastButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 创建广播意图
                Intent intent = new Intent("com.example.broadcast.MY_BROADCAST");
                intent.putExtra("message", "Hello, this is an unordered broadcast!");

                // 发送无序广播
                sendBroadcast(intent);
            }
        });
    }
}
```

### 4. 布局文件

在`res/layout/activity_main.xml`文件中添加一个按钮，用于触发广播发送：

```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <Button
        android:id="@+id/send_broadcast_button"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Send Broadcast"
        android:layout_centerInParent="true"/>
</RelativeLayout>
```

### 解释

1. **MyBroadcastReceiver**:
   - 继承自`BroadcastReceiver`类，并覆写`onReceive`方法。`onReceive`方法中获取广播携带的数据，并显示一个Toast消息。

2. **AndroidManifest.xml**:
   - 注册了`MyBroadcastReceiver`，并定义了接收的广播动作`com.example.broadcast.MY_BROADCAST`。

3. **MainActivity**:
   - 在`onCreate`方法中设置了一个按钮的点击监听器，点击按钮时创建一个广播意图并发送无序广播。

### 运行流程

1. 应用启动后，用户点击“Send Broadcast”按钮。
2. `MainActivity`中的点击事件触发，创建一个广播意图并调用`sendBroadcast`方法发送无序广播。
3. 系统接收到广播后，查找注册了匹配意图过滤器的所有接收器，并调用它们的`onReceive`方法。
4. `MyBroadcastReceiver`的`onReceive`方法被调用，显示一个Toast消息，表明广播已被接收。

通过这种方式，我们实现了无序广播的发送和接收。





## 服务

在准备服务这一章节的编程题时，你可以重点掌握以下知识点和对应的代码挖空，这些内容可以帮助你在考试中更好地应对：

1. **服务的基本概念和生命周期**：
   - **知识点**：了解服务的基本概念，包括服务的类型（前台服务、后台服务）、生命周期方法（`onCreate()`, `onStartCommand()`, `onBind()`, `onDestroy()`）的调用顺序。
   - **代码挖空**：在理解了服务生命周期的基础上，实现一个简单的服务类，包括必要的生命周期方法。

   ```java
   public class MyService extends Service {
       @Override
       public void onCreate() {
           // TODO: 在服务创建时执行的操作
       }
   
       @Override
       public int onStartCommand(Intent intent, int flags, int startId) {
           // TODO: 在服务启动时执行的操作，如后台任务等
           return START_STICKY; // 返回适当的启动模式
       }
   
       @Override
       public IBinder onBind(Intent intent) {
           // TODO: 返回用于与Activity通信的Binder对象，如果不需要绑定则返回null
           return null;
       }
   
       @Override
       public void onDestroy() {
           // TODO: 在服务销毁时执行的清理操作
       }
   }
   ```

2. **启动服务和绑定服务**：
   - **知识点**：了解如何通过`startService()`启动服务和通过`bindService()`绑定服务，理解它们的区别和使用场景。
   - **代码挖空**：在活动中实现按钮点击事件，通过`startService()`启动服务并展示相关的UI更新。

   ```java
   // 在MainActivity中的按钮点击事件中
   Intent serviceIntent = new Intent(MainActivity.this, MyService.class);
   startService(serviceIntent);
   ```

3. **服务与广播的配合使用**：
   - **知识点**：了解如何在服务中发送广播并在活动中注册接收广播，实现服务与界面的通信和数据更新。
   - **代码挖空**：在服务中实现发送广播的逻辑，并在活动中注册广播接收器处理服务发送的广播。

   ```java
   // 在服务中发送广播
   Intent broadcastIntent = new Intent("custom_action");
   broadcastIntent.putExtra("data", "Hello from service!");
   sendBroadcast(broadcastIntent);
   ```

4. **后台任务和计时器的使用**：
   - **知识点**：了解如何在服务中执行后台任务，使用计时器（如`CountDownTimer`）实现定时任务。
   - **代码挖空**：在服务中实现一个定时任务，如倒计时功能，更新UI或发送广播通知状态变化。

   ```java
   // 在服务中使用CountDownTimer实现倒计时
   CountDownTimer countDownTimer = new CountDownTimer(60000, 1000) {
       @Override
       public void onTick(long millisUntilFinished) {
           // TODO: 更新UI显示剩余时间
       }
   
       @Override
       public void onFinish() {
           // TODO: 倒计时结束后的操作
       }
   };
   countDownTimer.start();
   ```

5. **权限管理**：
   - **知识点**：了解如何在Android应用中动态申请权限，以及处理权限请求的结果。
   - **代码挖空**：在活动中实现权限申请的逻辑，确保应用在需要时能正确请求和处理权限。

   ```java
   // 在活动中动态申请权限的代码
   if (checkSelfPermission(Manifest.permission.READ_CONTACTS) != PackageManager.PERMISSION_GRANTED) {
       requestPermissions(new String[]{Manifest.permission.READ_CONTACTS}, 1);
   }
   ```







## JSON数据解析



请写出使用JSONArray类解析JSON数据的主要逻辑代码，JSON数据如下所示。

```json
[
    {"name":"LiLi", "score":"95"},
    {"name":"LiLei", "score":"99"},
    {"name":"王小明", "score":"100"},
    {"name":"LiLei", "score":"89"}
]

```



```java
import org.json.JSONArray;
import org.json.JSONObject;

public class JSONParsingExample {

    public static void main(String[] args) {
        // 假设这里是从某个接口或文件中获取到的 JSON 字符串
        String jsonString = "[{\"name\":\"LiLi\", \"score\":\"95\"},{\"name\":\"LiLei\", \"score\":\"99\"},{\"name\":\"王小明\", \"score\":\"100\"},{\"name\":\"LiLei\", \"score\":\"89\"}]";

        try {
            // 创建 JSONArray 对象
            JSONArray jsonArray = new JSONArray(jsonString);

            // 遍历 JSONArray
            for (int i = 0; i < jsonArray.length(); i++) {
                // 获取每个对象
                JSONObject jsonObject = jsonArray.getJSONObject(i);

                // 从对象中获取需要的字段
                String name = jsonObject.getString("name");
                String score = jsonObject.getString("score");

                // 输出结果
                System.out.println("Name: " + name + ", Score: " + score);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

```

**导入相关类**：

- `org.json.JSONArray`：用于表示JSON数组的类。
- `org.json.JSONObject`：用于表示JSON对象的类。

**JSON解析逻辑**：

- 创建一个 `JSONArray` 对象，并将从接口或文件中获取的 JSON 字符串传入构造方法。
- 使用 `JSONArray` 的 `getJSONObject()` 方法逐个获取数组中的 JSON 对象。
- 对每个 JSON 对象，通过 `getString()` 方法获取指定字段（例如 `"name"` 和 `"score"`）的值。
- 在控制台或其他输出方式中打印结果。

**异常处理**：

- 使用 `try-catch` 块捕获可能抛出的异常，如 `JSONException`，并在异常发生时打印堆栈信息。





## Activity

### 简述Activity、Intent、IntentFilter的作用

1. **Activity**:
   - **作用**：在Android应用中，Activity是用户界面的基本构建块，每个Activity都提供了一个用于展示用户界面的窗口。它通常用于展示一个屏幕上的交互界面，如登录界面、设置界面等。
   - **特点**：每个Activity都是一个单独的类，通过继承 `android.app.Activity` 类来创建。Activity生命周期方法（如 `onCreate()`、`onStart()`、`onResume()`等）可以帮助管理Activity的状态和用户交互。

2. **Intent**:
   - **作用**：Intent在Android中用于在组件之间（如Activity、Service、BroadcastReceiver等）进行通信。它可以用于启动组件、传递数据、启动服务、发送广播等。
   - **分类**：Intent分为显式Intent和隐式Intent。显式Intent指定了要启动的组件的类名，而隐式Intent根据动作、数据或类别来匹配并启动合适的组件。
   - **功能**：Intent可以携带额外的数据（如字符串、整数、Parcelable对象等），通过 `putExtra()` 方法添加数据，通过 `getXXXExtra()` 方法获取数据。

3. **IntentFilter**:
   - **作用**：IntentFilter用于在清单文件（AndroidManifest.xml）中声明，**用于指定某个组件能够响应的Intent的类型和条件**。它定义了哪些Intent可以触发应用中的组件。
   - **配置**：IntentFilter可以配置Intent的动作（Action）、数据（Data）、类别（Category）等属性，以及权限要求。
   - **用途**：在广播接收器（BroadcastReceiver）中常用IntentFilter来过滤特定的广播消息，确保只有特定条件的广播才会触发对应的处理逻辑。

### 总结：
- **Activity** 是用户界面的基本单位，用于展示和处理用户交互。
- **Intent** 是组件之间通信的桥梁，可以启动组件、传递数据等。
- **IntentFilter** 声明了一个组件可以响应的Intent的类型和条件，在清单文件中进行配置。

这些概念是Android开发中非常基础和重要的部分，理解它们的作用和使用方式有助于有效开发和管理Android应用。







## 广播机制

### 广播机制的实现过程

广播机制是Android中用于组件之间进行松耦合通信的重要机制。它允许一个应用发送系统级别的事件或者自定义事件，其他应用或者同一应用内的组件可以接收并响应这些事件。

1. **广播发送过程**：
   - 发送者通过创建一个Intent，并调用 `sendBroadcast(Intent)` 或者 `sendOrderedBroadcast(Intent, String)` 方法发送广播。
   - 系统将这个Intent包装成一个广播消息，广播消息包含Intent的信息以及广播的类型（有序或无序）。

2. **广播接收过程**：
   - 应用或组件在其清单文件（静态注册）或代码中（动态注册）声明一个BroadcastReceiver，并指定它可以接收的IntentFilter。
   - 当符合IntentFilter条件的广播消息到达时，系统会调用BroadcastReceiver的 `onReceive()` 方法，这个方法处理接收到的广播消息。

### 有序广播和无序广播的区别

1. **无序广播**：
   - **特点**：发送者发送广播后，所有注册了匹配IntentFilter的BroadcastReceiver几乎同时收到广播消息。
   - **执行顺序**：接收器的执行顺序不确定，可以并行执行，没有先后顺序。
   - **应用场景**：适合不需要关注广播顺序，只需要快速处理的情况，效率高。

2. **有序广播**：
   - **特点**：发送者发送广播后，系统按照接收器的优先级和注册顺序依次调用BroadcastReceiver的 `onReceive()` 方法。
   - **执行顺序**：广播接收器按照优先级逐个执行，前一个接收器完全处理完广播后，才会传递给下一个接收器。
   - **应用场景**：适合需要确保接收器按照特定顺序处理广播的情况，如应用内部的状态同步、权限检查等。

### 总结

- **广播机制**允许应用组件之间进行松耦合的通信。
- **无序广播**适用于不关心广播接收顺序，追求效率的场景。
- **有序广播**适用于需要按照优先级或注册顺序依次处理广播的场景，确保接收器的执行顺序。

理解广播机制的实现过程和有序、无序广播的区别，有助于在开发中选择合适的广播类型，并设计更有效的应用通信机制。





## 网络编程

请编写一个程序，实现通过网络请求获取服务器数据并进行处理的功能。具体要求如下：

1. **MainActivity布局文件**（activity_main.xml）包含一个按钮（id为`button_fetch_data`）和一个文本视图（id为`textView_display`）。当点击按钮时，触发网络请求，将获取的数据显示在文本视图中。

2. **主调组件 MainActivity**：

```java
public class MainActivity extends AppCompatActivity {

    private TextView textViewDisplay;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textViewDisplay = findViewById(R.id.textView_display);

        Button buttonFetchData = findViewById(R.id.button_fetch_data);
        buttonFetchData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                fetchDataFromServer();
            }
        });
    }

    private void fetchDataFromServer() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    URL url = new URL("https://api.example.com/data");
                    HttpURLConnection conn = (HttpURLConnection) url.openConnection();
                    conn.setRequestMethod("GET");
                    conn.connect();

                    // 检查响应码是否为 200，表示成功
                    if (conn.getResponseCode() == HttpURLConnection.HTTP_OK) {
                        InputStream inputStream = conn.getInputStream();
                        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
                        StringBuilder stringBuilder = new StringBuilder();
                        String line;
                        while ((line = reader.readLine()) != null) {
                            stringBuilder.append(line);
                        }
                        reader.close();
                        final String responseData = stringBuilder.toString();

                        // 在 UI 线程更新获取到的数据
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                textViewDisplay.setText(responseData);
                            }
                        });
                    } else {
                        Log.e("MainActivity", "HTTP 错误码: " + conn.getResponseCode());
                    }
                    conn.disconnect();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }
}
```

3. **清单文件（AndroidManifest.xml）**：确保添加网络访问权限。

```xml
<uses-permission android:name="android.permission.INTERNET" />
```

### 解析与注意事项：

- **代码解析**：
  - `fetchDataFromServer()` 方法创建了一个新线程，执行网络请求。
  - 使用 `HttpURLConnection` 发送 GET 请求到指定的 URL，并处理响应数据。
  - 在成功获取数据后，通过 `runOnUiThread()` 方法更新主线程上的 UI，显示获取的数据。

- **注意事项**：
  - 在实际开发中，建议使用 `AsyncTask` 或者更高级的网络库（如 Retrofit、Volley）来简化网络请求和处理过程，并处理异步操作。
  - 为了避免在主线程中执行耗时操作，应该将网络请求放在后台线程中执行，以提升应用的响应速度和用户体验。

#### 多线程在Android中的使用

在Android开发中，多线程主要用于处理以下几种情况：

- **网络请求和数据处理**：为了避免在主线程中进行网络请求而阻塞UI，应该使用新的线程或异步任务（AsyncTask）来执行网络请求和数据处理。
- **耗时操作**：如文件读写、数据库操作等耗时任务应该在后台线程中完成，以保持UI的响应性能。
- **定时任务**：通过线程或定时器（Timer）执行定时任务，如轮询检查服务状态等。













## 1

下面是关于JSON解析和网络编程的注释和相关知识点解析：

```java

/**
 * A simple {@link Fragment} subclass.
 * Use the  factory method to
 * create an instance of this fragment.
 */
public class HomeFragment extends Fragment {

    // 轮播图数据列表
    private List<Carousels> carouselses = new ArrayList<>();
    // 商品列表
    private List<Goods> hotGoods = new ArrayList<>();
    private List<Goods> newGoods = new ArrayList<>();
    private List<Goods> tjGoods = new ArrayList<>();
    private TextView tv_search;
    private GoodsAdapter newAdapter,hotAdapter,recommendAdapter;
    private GridView gv_hot,gv_recommend;
    private TextView tv_login;
    private String[] names = {"新蜂超市", "新蜂服饰", "全球购", "新蜂生鲜", "新蜂到家",
            "充值缴费", "9.9元拼", "领券", "省钱", "全部"};
    private int[] icons = {R.mipmap.chaoshi, R.mipmap.cloth, R.mipmap.gloabel, R.mipmap.xian, R.mipmap.tohome, R.mipmap.chong, R.mipmap.ping, R.mipmap.juan, R.mipmap.money, R.mipmap.all};

    private Banner banner;
    private String link = "http://47.99.134.126:28019/api/v1/index-infos";

    // 处理网络请求结果的Handler
    private Handler handler = new Handler() {
        @Override
        public void handleMessage(@NonNull Message msg) {
            // 设置轮播图数据
            banner.setAdapter(new BannerImageAdapter<Carousels>(carouselses) {
                @Override
                public void onBindView(BannerImageHolder holder, Carousels data, int position, int size) {
                    // 使用Glide加载图片
                    Glide.with(holder.itemView)
                            .load(data.getCarouselUrl())
                            .into(holder.imageView);
                }
            })
            .setIndicator(new CircleIndicator(getContext()));

            // 设置新品、热门商品、推荐商品列表数据
            newAdapter.setGoodsList(newGoods);
            hotAdapter.setGoodsList(hotGoods);
            recommendAdapter.setGoodsList(tjGoods);
        }
    };

    public HomeFragment() {
        // Required empty public constructor
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_home, container, false);

        // 初始化视图组件
        initViews(view);

        // 检查用户登录状态
        checkUserLoginStatus();

        // 加载轮播图和商品数据
        loadBannerAndGoodsData();

        return view;
    }

    // 初始化视图组件
    private void initViews(View view) {
        tv_login = view.findViewById(R.id.tv_login);
        tv_search = view.findViewById(R.id.search);
        banner = view.findViewById(R.id.banner);
        gv_hot = view.findViewById(R.id.hotproduct);
        gv_recommend = view.findViewById(R.id.recommendproduct);
    }

    // 检查用户登录状态，根据登录状态显示不同UI
    private void checkUserLoginStatus() {
        SharedPreferences info = getContext().getSharedPreferences("info", Context.MODE_PRIVATE);
        String token = info.getString("token","");
        if (token.isEmpty()) {
            tv_login.setVisibility(View.VISIBLE);
        } else {
            tv_login.setVisibility(View.GONE);
        }
    }

    // 加载轮播图和商品数据
    private void loadBannerAndGoodsData() {
        new Thread() {
            @Override
            public void run() {
                try {
                    // 发起网络请求获取数据
                    URL url = new URL(link);
                    HttpURLConnection cn = (HttpURLConnection) url.openConnection();
                    if (cn.getResponseCode()==200) {
                        InputStream inputStream = cn.getInputStream();
                        int len = 0;
                        byte[] bytes = new  byte[1024];
                        ByteArrayOutputStream baos = new ByteArrayOutputStream();
                        while ((len=inputStream.read(bytes))>0) {
                            baos.write(bytes,0,len);
                        }
                        String str = baos.toString();

                        // 解析JSON数据
                        JSONObject obj = new JSONObject(str);
                        if (obj.optInt("resultCode")==200) {
                            JSONObject data = obj.optJSONObject("data");

                            // 解析轮播图数据
                            JSONArray carousels = data.optJSONArray("carousels");
                            for (int i = 0; i < carousels.length(); i++) {
                                JSONObject jsonObject = carousels.optJSONObject(i);
                                String carouselUrl = jsonObject.optString("carouselUrl");
                                String redirectUrl = jsonObject.optString("redirectUrl");
                                carouselses.add(new Carousels(carouselUrl, redirectUrl));
                            }

                            // 解析热门商品数据
                            JSONArray hotGood = data.optJSONArray("hotGoodses");
                            for (int i = 0; i < hotGood.length(); i++) {
                                JSONObject jsonObject = hotGood.optJSONObject(i);
                                long goodsId = jsonObject.optLong("goodsId");
                                String goodsName = jsonObject.optString("goodsName");
                                String goodsIntro = jsonObject.optString("goodsIntro");
                                String goodsCoverImg = jsonObject.optString("goodsCoverImg");
                                long sellingPrice = jsonObject.optLong("sellingPrice");
                                String tag = jsonObject.optString("tag");

                                hotGoods.add(new Goods(goodsId, goodsName, goodsIntro, goodsCoverImg, tag, sellingPrice));
                            }

                            // 解析新品数据
                            JSONArray newGood = data.optJSONArray("newGoodses");
                            for (int i = 0; i < newGood.length(); i++) {
                                JSONObject jsonObject = newGood.optJSONObject(i);
                                long goodsId = jsonObject.optLong("goodsId");
                                String goodsName = jsonObject.optString("goodsName");
                                String goodsIntro = jsonObject.optString("goodsIntro");
                                String goodsCoverImg = jsonObject.optString("goodsCoverImg");
                                long sellingPrice = jsonObject.optLong("sellingPrice");
                                String tag = jsonObject.optString("tag");

                                newGoods.add(new Goods(goodsId, goodsName, goodsIntro, goodsCoverImg, tag, sellingPrice));
                            }

                            // 解析推荐商品数据
                            JSONArray tjGood = data.optJSONArray("recommendGoodses");
                            for (int i = 0; i < tjGood.length(); i++) {
                                JSONObject jsonObject = tjGood.optJSONObject(i);
                                long goodsId = jsonObject.optLong("goodsId");
                                String goodsName = jsonObject.optString("goodsName");
                                String goodsIntro = jsonObject.optString("goodsIntro");
                                String goodsCoverImg = jsonObject.optString("goodsCoverImg");
                                long sellingPrice = jsonObject.optLong("sellingPrice");
                                String tag = jsonObject.optString("tag");

                                tjGoods.add(new Goods(goodsId, goodsName, goodsIntro, goodsCoverImg, tag, sellingPrice));
                            }

                            // 发送消息给Handler，更新UI
                            handler.sendEmptyMessage(100);
                        }
                    }

                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }
}
```

### 注释和知识点解析：

1. **网络请求部分**：
   - 使用 `HttpURLConnection` 发起网络请求获取服务器数据。
   - 通过 `InputStream` 和 `ByteArrayOutputStream` 进行数据读取和处理。

2. **JSON解析部分**：
   - 使用 `JSONObject` 和 `JSONArray` 解析从服务器获取的JSON数据。
   - 解析不同类型的数据结构（如轮播图、热门商品、新品商品、推荐商品）。

3. **Handler处理UI更新**：
   - 使用 `Handler` 在主线程（UI线程）处理从网络请求获取的数据，更新UI组件（如轮播图和商品列表）。

4. **界面交互和用户状态管理**：
   - 根据用户登录状态显示不同的UI，如显示登录按钮或用户头像。
   - 点击事件处理，如商品点击跳转到商品详情页面等。

这段代码涵盖了Android开发中涉及到网络请求、JSON解析、多线程处理和UI更新





## 单击事件的绑定

1. **通过匿名内部类实现监听器**：

   ```java
   Button button = findViewById(R.id.button_id);
   button.setOnClickListener(new View.OnClickListener() {
       @Override
       public void onClick(View v) {
           // 在这里编写点击事件的处理逻辑
           // 例如：跳转到新的Activity
           Intent intent = new Intent(CurrentActivity.this, TargetActivity.class);
           startActivity(intent);
       }
   });
   ```

   这种方法直接在设置点击监听时，通过匿名内部类实现 `View.OnClickListener` 接口，可以直接在 `onClick` 方法中编写点击事件的处理逻辑。

2. **通过实现接口实现监听器**：

   ```java
   public class MainActivity extends AppCompatActivity implements View.OnClickListener {

       @Override
       protected void onCreate(Bundle savedInstanceState) {
           super.onCreate(savedInstanceState);
           setContentView(R.layout.activity_main);

           Button button = findViewById(R.id.button_id);
           button.setOnClickListener(this);
       }

       @Override
       public void onClick(View v) {
           // 在这里编写点击事件的处理逻辑
           // 例如：显示Toast消息
           Toast.makeText(this, "Button Clicked!", Toast.LENGTH_SHORT).show();
       }
   }
   ```

   在这种方法中，Activity 实现了 `View.OnClickListener` 接口，并在 `onClick` 方法中处理点击事件。通过将 `this` 传递给 `setOnClickListener` 方法，将当前Activity作为监听器，实现了事件处理方法。

3. **在布局文件中直接指定点击事件**：

   ```xml
   <Button
       android:id="@+id/button_id"
       android:layout_width="wrap_content"
       android:layout_height="wrap_content"
       android:text="Click Me"
       android:onClick="onButtonClick" />
   ```

   在布局文件中通过 `android:onClick` 属性指定点击事件处理方法的名称：

   ```java
   public class MainActivity extends AppCompatActivity {
   
       @Override
       protected void onCreate(Bundle savedInstanceState) {
           super.onCreate(savedInstanceState);
           setContentView(R.layout.activity_main);
       }
   
       public void onButtonClick(View view) {
           // 在这里编写点击事件的处理逻辑
           // 例如：弹出对话框
           AlertDialog.Builder builder = new AlertDialog.Builder(this);
           builder.setMessage("Button Clicked!");
           builder.setPositiveButton("OK", null);
           builder.show();
       }
   }
   ```

   这种方式不需要显式设置点击监听器，但必须确保方法的签名与 `android:onClick` 属性指定的方法名称和参数一致。

