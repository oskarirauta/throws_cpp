[![License:MIT](https://img.shields.io/badge/License-MIT-blue?style=plastic)](LICENSE)
[![C++ CI build](../../actions/workflows/build.yml/badge.svg)](../../actions/workflows/build.yml)
### throws_cpp

A wrapper class that throws with stream..

Limited to just use std::runtime_error as exception type.
Idea behind this is a post I came up [here](https://stackoverflow.com/a/37191553/1314831).

### <sub>Usage</sub>
```

throws << "hello " << "world" << std::endl;

```

## <sub>Example</sub>

Example code is provided
