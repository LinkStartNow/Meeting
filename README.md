# Meeting

## 2024.4.20

### 进展

> 实现json传递数组的客户端与服务端封装

---

### 问题

> 服务端内存泄漏出现bug，由于json数组无法回收内存

#### 解决

> 服务端的json库也是基于引用计数的，所以在json数组对象归属到大的对象后，就能回收该内存
>
> 但是要注意的是我们不能直接传递，这样总的大json对象指针对于该数组空间的引用计数是不会增加的，我们需要调用`json_object_get`来实现所有权的传递，让引用计数+1
>
> 然后我们再回收掉数组就不会出现问题

```c++
void json_add_value( const char * key,  std::vector<int>& value){
    json_object *jarray = json_object_new_array();
    for (const int& x: value) {
        json_object_array_add(jarray, json_object_new_int(x));
    }
    json_object_object_add(m_str,key, json_object_get(jarray));

    // 回收空间
    json_object_put(jarray);
}
```

---

## 2024.6.12

### 进展

> 实现音频通信

---

### 问题

> 用json封装发送音频的网络包，服务端出现崩溃现象

#### 解决

> 经过排查发现是json对音频数据的解析出现了问题，我们需要先通过base64进行编码再将音频数据进行发送，最终解决了问题

---

### 缺陷

> 通过Json封装发送的音频包大小比较大，占用网络资源较高

#### 优化

> 单独将音频包通过序列化的方式来传播发送，再通过反序列化来解析

---

## 2024.6.13

### 进展

> 云服务器搭建

---

### 搭建步骤

#### 1、配置MySQL

1. 安装MySQL

	1. 更新apt

		输入命令`apt-get update`

	2. 安装服务端

		输入命令` apt-get install mysql-server`

	3. 安装客户端

		输入命令`apt-get install mysql-client`

	4. 安装开发库

		输入命令`apt-get install libmysqlclient-dev`

	5. 检查是否安装成功

		输入命令`netstat -tap | grep mysql`

		如果处于监听状态则说明安装成功了

2. 配置MySQL（让MySQL支持中文）

	1. 检查当前编码

		输入命令`show variables like '%char%';`

		发现数据库的数据集为latin1，我们需要改成utf8

	2. 修改配置文件

		`vi /etc/mysql/mysql.conf.d/mysqld.cnf`

		[mysqld]后面添加 `character_set_server=utf8 `，保存并退出

	3. 重启MySQL

		输入命令`service mysql restart`

	4. 重新登录MySQL检查一遍编码

		发现对应的`character_set_database`已经变成了`utf8`

3. 建表

	```mysql
	create table t_user (
		id int primary key auto_increment,
		tel varchar(15)	unique,
		pass varchar(40),
		icon int default 0,
		feeling varchar(100) default '这个人很懒，什么也没写',
		name varchar(45) unique
	);
	```

4. 修改表的字符集

	```mysql
	alter table t_user convert to charset utf8;
	```

---

#### 2、配置Json环境

1. 安装json

	1. 将json安装包移动到远程机上去

	2. 将json的安装包拷贝到`/usr/local`去

	3. 到目标目录下去解压

		`tar -xvf json-c-0.9.tar.gz`

		如果移动过去的是一个zip文件，则先解压zip文件，`unzip 文件名`

		也许unzip都没有安装，则先安装unzip，`apt install unzip`

	4. 进入到解压后的目录中

		`cd json-c-0.9`

	5. 配置文件并安装

		先`./configure`，然后`make`，最后`make install`

2. 配置动态库文件

	我们这是第一次安装库，所以操作系统并不知道从哪找动态库文件

	所以我们可以手动配置一下

	1. 打开配置文件：`sudo vim  /etc/ld.so.conf`

	2. 添加对应库所在路径：`include /etc/ld.so.conf.d/*.conf 
		/usr/local/lib`

	3. 保存退出，并加载

		`ldconfig`


---

### 问题（未成功解决）

> 音频通话卡顿，延迟巨高

#### 优化方案

1. 非阻塞通信

2. UDP通信

	需要克服内网穿透问题，因为本地的主机为私网，而云服务器为公网IP，所以需要做内网穿透才能实现服务端与本地通信

---

### 功能优化

> 添加了复制房间号的功能
>
> 优化目的：方便用户邀请其他用户加入当前会议，而不用手动一个个去输入会议号，减少了错误的可能性，同时降低了用户邀请的难度

---

## 2024.6.15

### 进展

> 完成了视频通话部分

### 功能优化

> 去除新成员加入会议时对所有用户的欢迎通知，改为了单一的欢迎。并继续保持了原会议成员对新用户加入的欢迎通知。
>
> 优化目的：原会议成员对新加入成员有知情权，所以直接提示新用户xxx加入。而新加入会议成员本就不需要在一加入会议时就获取所有原会议成员有哪些（包括对自己的欢迎），这样一加入就疯狂弹出一堆提示弹窗也许会对用户造成糟糕的使用体验，而目前改成了单一的普通欢迎保持了一定的用户交互功能。

---

## 2024.6.16

### 进展

> 完成共享桌面
>
> 新增放大预览功能，点击某个成员可以将其视频播放页面放到展示框中

### 缺陷

> - 共享桌面清晰度不够高

### 功能优化

> 开启桌面显示等功能后，由于数据量的增大导致网络传输的阻塞，而致使拖动窗口时无法及时响应，影响用户体验，采用多线程的方式，单独让另一个线程用来发送网络包，配合智能指针完成空间回收
