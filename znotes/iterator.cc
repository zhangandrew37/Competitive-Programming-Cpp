#include <iostream>

using namespace std;

class CharRange {
 char first, last;
 public:
    CharRange(char first, char last): first{first}, last{last} {}
 // Add the implementation of the Iterator here
    class Iterator{
        char cur;
        explicit Iterator(char cur): cur{cur}{}
        public:
            char &operator*(){
                return cur;
            }

            Iterator operator++(){
                cur = cur +1;
                return *this;
            }

            bool operator==(const Iterator &other) const {
                return (cur == other.cur);
            }

            bool operator!=(const Iterator &other) const {
                return !(*this==other);
            }
            friend class CharRange;
    };
        Iterator begin(){
            return Iterator{first};
        }

        Iterator end(){
            char tmp = last+1;
            return Iterator{tmp};
        }
};

int main() {
 CharRange range1{'A', 'E'};
 for (auto c : range1) {
 cout << c << endl; // prints: A B C D E
 }
 CharRange range2{'l', 't'};
 for (auto c : range2) {
 cout << c << endl; // prints: l m n o p q r s t
 }
}