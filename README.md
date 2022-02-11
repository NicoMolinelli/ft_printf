
# ft_printf

My implementation of the printf() function from libc.

> Because ft_putnbr() and ft_putstr() aren’t enough
## Features

The prototype of ft_printf looks like this:
```C 
int	ft_printf(const char *, ...);
```

It will manage the following conversions: ``c s p d i u x X %``

**Conversions**
```
%                   (% character)
c    char           (character)
s    char *         (string)
p    void *         (pointer's address)
u    unsigned int   (unsigned decimal integer)
x/X: unsigned int   (hexadecimal)
d/i: int            (integer)
```

**Flags:**

``
%[Flags][Width][.Precision][Length]<type>
``

```
-       Left alignment. (default rigth aligned)
0       Field is padded with 0's instead of space.
.       Precision
#       For x and X conversions, a non-zero result has the string `0x' (or '0X') prepended to it
+       Show sign for positive numbers
```
**Width:** Minumum number of characters to output (pads if necessary)

**Precision:** Maximum limit of characters to output (rounds if necessary)


## Installation

Install my-project simply cloning this repo

```bash
  https://github.com/NicoMolinelli/ft_printf.git
```
Then create the library
```bash
    cd ft_printf && make
```
## Usage

Use `ft_printf` as real `printf` by adding in the main

``` C
#include <ft_printf.h>
````

Then compile your file with the generated ``libftprintf.a``

``` C
  gcc main.c libftprintf.a -I includes
```


## License

[MIT](https://choosealicense.com/licenses/mit/)

