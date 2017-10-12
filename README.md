# CO2003 CTDL&GT Fall 2017

## About

Bài tập về môn cấu trúc dữ liệu và giải thuật

## Licensing

---

#### BUILD HELP

* for mingw user

```
for debug
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug

for release
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release

for test with debug
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug -DTEST=ON

for test with release
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -DTEST=ON
```

* for clang user

```
to be updated
```

* for Visual Studio user

```
used to be able to create project files for Visual Studio
but now not sure
i dont have Visual Studio to test on
run this to build for Visual Studio

I don't know how to make Visual Studio create a test build
Maybe in future I will try to make the recipe

for debug
cmake -G "Visual Studio <Version number>" -DCMAKE_BUILD_TYPE=Debug

for release
cmake -G "Visual Studio <Version number>" -DCMAKE_BUILD_TYPE=Release

for test with debug
cmake -G "Visual Studio <Version number>" -DCMAKE_BUILD_TYPE=Debug -DTEST=ON

for test with release
cmake -G "Visual Studio <Version number>" -DCMAKE_BUILD_TYPE=Release -DTEST=ON



| Visual Studio | Vesion number |
|---------------|---------------|
| 2005          | 8             |
| 2008          | 9             |
| 2010          | 10            |
| 2012          | 11            |
| 2013          | 12            |
| 2015          | 14            |
| 2017          | 15            |
```


* Other build files

```
Not yet configured
```


#### Note

This program is only for Windows and Linux console only

This program is not (yet) configured for OS