## RAII: Resource Acquisition is Key

- idiom (a way of structuring code)
- commonly enabled by **smart pointers**
- **more generally** is a concept that you should always design your classes so that **object lifetimes are bound to other objects**
  - lifetimes of all obejcts in a system are connected

### Recall GraphNode example
- fix cyclic references (which resulted from adding vertex from n2->root and root->n2 and both not being deleted when going out of scope)

Solution:
- create a (surrounding) Graph type, and bind the nodes to Graph
- have GraphNodes refer to indices instead of GraphNodes
  - association between indices and actual GraphNode is only in a single, surrounding Graph object
- **lifetime** of all nodes bound to Graph, which can be bound to something with fixed lifetime (i.e. shared_ptr)

### Consider 4 uses of vector
- observe interaction with RAII and memory allocation
```c
vector<Graph> a;
```

- adheres to RAII
- difficult to use
  - destroying vector will destroy every Graph
  - using vector (i.e. ```Graph g = a[x]```) copies the Graph
    - this then copies a vector (because Graph contains vector of shared pointers to GraphNodes) which increments a reference count for every GraphNode **(expensive!)**

```c
vector<Graph *> b;
```

- does not adhere to RAII
- when b destroyed, all pointers are lost
  - underlying heap-allocated Graphs are not deleted

```c
vector<unique_ptr<Graph>> c;
```

- adheres to RAII
  - difficult to use
    - can't copy pointer out of vector (``` auto g = u[x] ``` fails)
    - could use u[x].get()


```c
vector<shared_ptr<Graph>> d;
```

- adheres to RAII
- relatively easy to use
- ```auto g = u[x] ``` increases reference count
- Graph only destroyed when *all* references out of scope
- using Graph itself only increases that single reference count




