# throws_cpp
A wrapper class that throws with stream..
Limited to just use std::runtime_error as exception type.

Idea behind this is a post I came up [here](https://stackoverflow.com/a/37191553/1314831)

Example:

```

throws << "hello " << "world" << std::endl;

```
