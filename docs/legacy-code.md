# Legacy Code Analysis

This project started last year, achieving some features which now have to be documented.

## Framework module

- ObjectLoader class
  - made by myself in order to fix what was wrong
  - supports `.obj` files
- Input class
  - input support for mouse and keys
- Common Types class
  - vertex, vertex attributes, index (for IBO), FaceIndices (supporting texturing as well)

## Source module
### Framework module
#### Rendering module
- Material class
  - support for texturing
  - static material (manual path provided, also OS-path-dependent)
  - supports `.mtl` files
    - meaning simple attributes, expect to work buggy or unsatisfactory with specularity
- Primitives class
  - defines and draws a cube when called
