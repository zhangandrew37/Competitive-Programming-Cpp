# Visitor Design Pattern

Motivation:
- want to perform operations on objects depending on their type
- visitor class: allows you to have one class to handle all the operations
  - just need to overload visit method of visitor to handle diff params (one for each different type of objected operated on)
### Comments:

```cpp
struct Visitor{
    virtual void visit(Book b) = 0;
};

struct Book{
    virtual void accept(Printer);
    virtual void accept(Printer);
}

Comic::accept(Printer &p){  
    p.visit(*this); // here, *this has type Comic
}

Text::accept(Printer &p){  
    p.visit(*this); // here, *this has type Text
}

```