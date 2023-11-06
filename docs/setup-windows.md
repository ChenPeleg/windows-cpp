# Installation process for mingw64

1. Go to the official msys2 website: https://www.msys2.org/
2. You will probably want to install some tools like the mingw-w64 GCC to start compiling projects. Run the following command:

```shell
pacman -S mingw-w64-ucrt-x86_64-gcc
```
and then

```shell
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```



# Cahnges from the last installation

looks like the path has changed to 

`C:\msys64\ucrt64\bin`

## Installing mingw64

