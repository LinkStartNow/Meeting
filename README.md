# Meeting

## 2024.4.20

实现json传递数组的客户端与服务端封装

### 问题

> 服务端内存泄漏出现bug，由于json数组无法回收内存

### 解决

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

