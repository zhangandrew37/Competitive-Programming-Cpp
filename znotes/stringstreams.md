# stringstreams

- given string s1{"The quick brown fox\njumped over the lazy\t dog."}; print word by word

```cpp
#include <string>
#include <sstream>
#include <iostream>

string s1{"The quick brown fox\njumped over the lazy\t dog."};
istringstream ss1{s1};

string s;
while (ss1 >> s){
    cout << s << endl;
}

 string s2{ "Smith,Jane,99999999,Yu,Yaoliang,99999998" };
 istringstream ss2{s2};
 while (getline(ss2, s2, ',')){
    cout << s2 << endl;
 }
 ```

output:

```cpp
ostringstream ss;
 int lo {1}, hi {100};
 ss << "Enter a # between " << lo << " and " << hi;
 string s {ss.str()};
 cout << s << endl;
```
- treat as cout 

file:

```cpp
#include <fstream>
int main() {
 std::ifstream infile{ "input.txt" };
 std::ofstream outfile{ "output.txt" };
 int i;
 while ( true ) {
    infile >> i;
    if (infile.fail()) break;
    outfile << i << std::endl;
}
```