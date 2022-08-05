#include <iostream>

class Book {
    public:
        virtual void sayHello() const {
            std::cout << "Hi I'm a book" << std::endl;
        }
};

class TextBook : public Book {
    public:
        void sayHello() const override {
            std::cout << "Hi I'm a textbook" << std::endl;
        }
};

void sayHelloTB(TextBook& t) {
    t.sayHello();
}

void sayHello(Book& b) {
    b.sayHello();
}

int main () {
    Book b;
    TextBook t;
    Book *pb = new Book();
    Book *pbt = new TextBook();
    Book *pt = new TextBook();
    Book *ptb = new Book();

    // if not virtual: Textbook would not be passed as book
    sayHello(t); // pass Textbook as book
    // sayHelloTB(b); // pass Book as Textbook; not allowed
    //if not virtual: pbt resolved according to type of pointer
    pbt->sayHello(); // becomes Textbook
    ptb->sayHello();
    sayHello(*pt);
    sayHello(*pbt);
    


    // Book b;
    // b.sayHello();
    // TextBook t;
    // t.sayHello();
    // sayHello(t);
    // sayHelloTB(t);
    // Book* pb = new TextBook();
    // pb->sayHello(); 
    // delete pb;
}