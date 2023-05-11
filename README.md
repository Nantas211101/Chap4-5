How to build

The first time ^^
```pwsh

mkdir build
cd build

cmake ..
cd ../

cmake --build ./build --config=Release -j 8
```


Build again

```
cmake --build ./build --config=Release -j 8
```

