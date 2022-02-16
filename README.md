# DeLorean_Team
Source project automotive BASECAMP


## Build and run
```
cd build
cmake ../
make
./main ../tests/example.yml
```

## Create code coverage report
<b> Firstly, you need to install gcovr:</b>
```
sudo apt-get install gcovr
```
<b>Create a report:  </b>
```
cd build
make code_coverage
cd ../tests/code_coverage/report
```

## Before commit   

### Check that your branch updated with main 
```
git checkout main
git pull
git checkout validator
git merge main
git push
```

### Make sure your code matches the Google C++ Style Guide.  
For automatic format of all code you can use command: 
```
find src/ -iname *.hpp -o -iname *.cpp | xargs clang-format -i -style=Google
```

or for one file 
```
clang-format -i -style=Google src/main.cpp
```
(Warning, will modify code in place without any notice)

### Check that tests passed 
```
cd build
cmake ../
make
./tests
```

### Be sure your code passed cppcheck without warnings 
```
cppcheck --enable=all --inconclusive -i./build --std=c++14 main.cpp --suppress=missingIncludeSystem  -I include/ ./
```
