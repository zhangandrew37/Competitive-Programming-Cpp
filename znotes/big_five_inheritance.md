# Big Five
## **Inheritance**:
- move now requires std::move(other) in place of other
  
**Constructor**
```cpp
Text(const string &title, const string &author, int length, const string &topic): Book{title, author, length}, topic{topic}{}
 ```

**Copy Constructor**
 ```cpp
 Text(const Text &other): Book{other}, topic{other.topic}{}
 ```
 
**Move Constructor**
```cpp
Text(const Text&&other): Book{std::move(other)}, topic{std::move(other.topic)}{}
 ```

**Copy Assignment**
 ```cpp
Text &operator=(const Text &other){
    // if (this == &other) return *this;
    Book::operator=(other);
    topic = other.topic;
    return *this;
}
 ```

**Move Assignment**
```cpp
Text &operator=(const Text &other){
    // if (this == &other) return *this;
    Book::operator=(std::move(other));
    topic = std::move(other.topic);
    return *this;
    
}
 ```



 Note: we must fix the copy/move assignment operators to fix polymorphic (mixed) assignment with dynamic casting and exception handlers

Copy Assignment
 ```cpp
 Text &operator=(Book &other){
    if (this == &other) return *this
    Book::operator=(other);
    //check if text
    Text &tmp = dynamic_cast<Text&>(other);
    topic = tmp.topic
     return *this;

 }
 ```

  Note: we must fix the copy/move assignment operators to fix polymorphic (mixed) assignment with dynamic casting and exception handlers

Move Assignment
 ```cpp
 Text &operator=(Book &&other){
    if (this == &other) return *this;
    Book::operator=(std::move(other));
    //check if Text
    Text &tmp = dynamic_cast<Text&>(other);
    topic = std::move(tmp.topic)
    return (*this)
}
 ```