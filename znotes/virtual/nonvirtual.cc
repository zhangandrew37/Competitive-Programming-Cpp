#include <iostream>

class Book {
    public:
        void sayHello() {
            std::cout << "Hi I'm a book" << std::endl;
        }
};

class TextBook : public Book {
    public:
        void sayHello() {
            std::cout << "Hi I'm a textbook" << std::endl;
        }
};
void sayHelloTB(TextBook &t){
    t.sayHello();
}

void sayHello(Book &b){
    b.sayHello();
}

int main () {

    Book b;
    TextBook t;
    Book *pb = new Book();
    TextBook *pt = new TextBook();
    sayHello(b);
    // sayHelloTB(b); doesn't work
    // sayHelloTB(dynamic_cast<TextBook*>(pb)); Book is not polymorphic
    sayHello(t); // treated as a book
    
    pb->sayHello();
    pt->sayHello(); // pointers work 
    delete pb;
}