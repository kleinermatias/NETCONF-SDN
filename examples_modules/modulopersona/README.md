Sysrepo plugin for testing.

## Crosscompile

```
$ mkdir build
$ cd build
$ CC={TARGET-COMPILER}-gcc CXX={TARGET-COMPILER}-g++ cmake -DCMAKE_INSTALL_PREFIX=/root/usrapp ..
$ make
```

## netopeer2-cli example

You have netopeer2-cli command content examples in the folder example.
```
user-rpc --content ./example/ls.xml
```
