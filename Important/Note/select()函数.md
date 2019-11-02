# select()函数 



### 1.函数原型

```int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);```

### 2.描述

​	select() 能够监视多个文件描述符的变化情况，直到其中的一个或多个文件描述符变为“就绪”的状态。所谓就绪状态，指的是“可读”“可写”或“异常”的状态。

### 3.参数

1. ``` int nfds```

   ​	select监视的文件数，一般设置为你要监视的各文件中最大文件号+1。

   -----

   ​	先来介绍struct fd_set 结构体：

``` c
                #define __FD_SETSIZE    1024
                typedef __kernel_fd_set     fd_set;

                typedef struct {
                    unsigned long fds_bits[__FD_SETSIZE / (8 * sizeof(long))];
                } __kernel_fd_set;

```

​		fd_set结构体实际上是一个long类型的数组，用来存放文件描述符。每个数组元素都能与一个文件描述符建立联系！

2. ``` fd_set *readfds```

   ​	select 监视的可读文件句柄集合。

3. ```fd_set *writefds```

   ​	select 监视的可写文件句柄集合。

4. fd_set *exceptfds

   ​	select监视的异常文件句柄集合。

-----------

5. struct timeval *timeout

   ​	先来介绍timeval结构体：

```c

                        struct timeval {

                            long tv_sec; //秒数

                            long tv_usec; //微秒数

                        }
```

​		对于该参数，有三种可能出现的情况：

1. 永远等待下去，直到有一个或多个描述符准就绪时返回。

   ​	此时，需要将参数timeout设置为空指针NULL。

2. 等待固定时长，在有一个或多个描述符就绪时返回，若超过timeout中所设定的时长则返回0；

   ​	此时，需要将参数timeout指向的结构体中的时间设置为要等待的最长时间。

3. 根本不等待，检查描述符之后立即返回，这种方式称为“轮询”。

   ​	此时，需要将参数timeout指向的结构体中的时间设置为0。

### 4.返回值

 	1. 若成功，则返回“就绪” 的文件描述符数量。
 	2. 若超时，或没有“就绪”状态的文件，则返回0。
 	3. 若出错，则返回-1。

​	