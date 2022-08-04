## Pimpl - Pointer to Implementation

- idiom (programmign technique)
- fixes **recompilation**
  - any time we change implementation details, the client has to recompile all their code that includes the header file

### Solution
- **replace** all **private data fields** with a **pointer to a class** 
  - will be forward-declared in header file
- if some data field were of an imported type, can move include statement to implementation file
- define XWindowImpl as a struct
  -  take advantage of public accessibility of data fields
- now, every reference to the original data fields in the implementation file now need to go through the **pointer to the struct class** to acccess the fields declared there

**File:** xwindow.h

```cpp
class XWindowImpl; // forward declaration in .h
class Xwindow {
 XWindowImpl * pImpl; // pointer to our implementation class
 ```

 **File:** xwindow.cc

 ```cpp
 struct XWindowImpl{
    // contains all private data fields
    Display *d
    Window *w
    ...
 }

// recall: pimpl is a pointer to our implementation class, so use -> to access fields
 Xwindow::Xwindow(int width, int height): pimpl{new WindowImpl}{
    pImpl->d = XOpenDisplay(nullptr);
    ...
 }

 Xwindow::~Xwindow(){
    XCloseDisplay(pImpl->d);
    delete pImpl; // remember to delete pointer
 }
 ```

 Note: we can also nest XWindowImpl class in XWindow
- can help reduce naming conflicts
  
**File:** xwindow.h

```cpp
class XWindow {
 class XWindowImpl; // forward declaration nested
 XWindowImpl * pImpl; // pointer to our implementation class
 ```

 **File:** xwindow.cc

 ```cpp

struct XWindow::XWindowImpl{
    // contains all private data fields
    Display *d
    Window *w
    ...
 }
// recall: pimpl is a pointer to our implementation class, so use -> to access fields
 Xwindow::Xwindow(int width, int height): pimpl{new WindowImpl}{
    pImpl->d = XOpenDisplay(nullptr);
    ...
 }

 Xwindow::~Xwindow(){
    XCloseDisplay(pImpl->d);
    delete pImpl; // remember to delete pointer
 }
 ```

 ## Bridge Design Pattern

 - decouple abstraction from implementation
 - take "pimpl" class and turn into a superclass if there are multiple possible window implementations