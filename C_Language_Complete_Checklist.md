# C语言标准功能完整清单

## 一、关键字（Keywords）

### 1.1 数据类型相关
- [ ] `char`
- [ ] `short`
- [ ] `int`
- [ ] `long`
- [ ] `float`
- [ ] `double`
- [ ] `void`
- [ ] `signed`
- [ ] `unsigned`
- [ ] `_Bool` / `bool`（C99 引入，C23 升级为关键字）
- [ ] `_Complex` / `complex`（C99）
- [ ] `_Imaginary` / `imaginary`（C99，可选）
- [ ] `_BitInt`（C23）
- [ ] `typeof` / `typeof_unqual`（C23）

### 1.2 存储类别说明符
- [ ] `auto`
- [ ] `static`
- [ ] `extern`
- [ ] `register`
- [ ] `thread_local`（C23 关键字，C11 为 `_Thread_local`）
- [ ] `constexpr`（C23）

### 1.3 类型限定符
- [ ] `const`
- [ ] `volatile`
- [ ] `restrict`（C99）
- [ ] `_Atomic` / `atomic`（C11）

### 1.4 函数与声明相关
- [ ] `inline`（C99）
- [ ] `_Noreturn` / `noreturn`（C11，C23 已废弃，改用属性）
- [ ] `return`
- [ ] `sizeof`
- [ ] `alignof` / `_Alignof`（C11）
- [ ] `alignas` / `_Alignas`（C11）
- [ ] `static_assert` / `_Static_assert`（C11，C23 升级为关键字）

### 1.5 控制结构
- [x] `if`
- [x] `else`
- [ ] `switch`
- [ ] `case`
- [ ] `default`
- [x] `while`
- [ ] `do`
- [x] `for`
- [ ] `break`
- [ ] `continue`
- [ ] `goto`

### 1.6 用户自定义类型
- [ ] `struct`
- [ ] `union`
- [ ] `enum`
- [ ] `typedef`

### 1.7 特殊常量与值
- [ ] `true`（C23 关键字，C99 为宏）
- [ ] `false`（C23 关键字，C99 为宏）
- [ ] `nullptr`（C23）
- [ ] `NULL`（标准宏，非关键字）

---

## 二、数据类型系统

### 2.1 基本类型（Fundamental Types）
- [ ] `char`（字符型）
- [ ] `signed char`（有符号字符型）
- [ ] `unsigned char`（无符号字符型）
- [ ] `short` / `short int` / `signed short` / `signed short int`
- [ ] `unsigned short` / `unsigned short int`
- [ ] `int` / `signed` / `signed int`
- [ ] `unsigned` / `unsigned int`
- [ ] `long` / `long int` / `signed long` / `signed long int`
- [ ] `unsigned long` / `unsigned long int`
- [ ] `long long` / `long long int` / `signed long long` / `signed long long int`（C99）
- [ ] `unsigned long long` / `unsigned long long int`（C99）
- [ ] `float`（单精度浮点）
- [ ] `double`（双精度浮点）
- [ ] `long double`（扩展精度浮点）
- [ ] `_Bool`（布尔型，C99）
- [ ] `void`（无类型/空类型）

### 2.2 位精确整数（C23）
- [ ] `_BitInt(N)`（N 位有符号整数）
- [ ] `unsigned _BitInt(N)`（N 位无符号整数）

### 2.3 十进制浮点（C23，可选）
- [ ] `_Decimal32`
- [ ] `_Decimal64`
- [ ] `_Decimal128`

### 2.4 复数类型（C99，可选）
- [ ] `float _Complex`
- [ ] `double _Complex`
- [ ] `long double _Complex`

### 2.5 虚数类型（C99，可选）
- [ ] `float _Imaginary`
- [ ] `double _Imaginary`
- [ ] `long double _Imaginary`

### 2.6 派生类型（Derived Types）
- [ ] 数组类型（`T[N]`）
- [ ] 指针类型（`T*`）
- [ ] 函数类型（`T (*)(args)`）
- [ ] 结构体类型（`struct`）
- [ ] 联合体类型（`union`）
- [ ] 枚举类型（`enum`）
- [ ] 原子类型（`_Atomic(T)`，C11）

### 2.7 定宽整数类型（C99，`<stdint.h>`）
- [ ] `int8_t`、`int16_t`、`int32_t`、`int64_t`
- [ ] `uint8_t`、`uint16_t`、`uint32_t`、`uint64_t`
- [ ] `int_least8_t` 至 `int_least64_t`
- [ ] `uint_least8_t` 至 `uint_least64_t`
- [ ] `int_fast8_t` 至 `int_fast64_t`
- [ ] `uint_fast8_t` 至 `uint_fast64_t`
- [ ] `intptr_t`、`uintptr_t`
- [ ] `intmax_t`、`uintmax_t`

### 2.8 其他标准类型
- [ ] `size_t`（`<stddef.h>`）
- [ ] `ptrdiff_t`（`<stddef.h>`）
- [ ] `max_align_t`（C11，`<stddef.h>`）
- [ ] `nullptr_t`（C23，`<stddef.h>`）
- [ ] `char8_t`（C23，`<uchar.h>`）
- [ ] `char16_t`（C11，`<uchar.h>`）
- [ ] `char32_t`（C11，`<uchar.h>`）
- [ ] `wchar_t`（`<stddef.h>` 或 `<wchar.h>`）
- [ ] `wint_t`（`<wchar.h>` / `<wctype.h>`）
- [ ] `time_t`（`<time.h>`）
- [ ] `clock_t`（`<time.h>`）
- [ ] `va_list`（`<stdarg.h>`）
- [ ] `jmp_buf`（`<setjmp.h>`）
- [ ] `sig_atomic_t`（`<signal.h>`）
- [ ] `FILE`（`<stdio.h>`）
- [ ] `fpos_t`（`<stdio.h>`）
- [ ] `div_t`、`ldiv_t`、`lldiv_t`、`imaxdiv_t`
- [ ] `lconv`（`<locale.h>`）
- [ ] `tm`（`<time.h>`）
- [ ] `timespec`（C11，`<time.h>`）
- [ ] `thrd_t`、`mtx_t`、`cnd_t`、`tss_t`（C11，`<threads.h>`）
- [ ] `once_flag`（C11，`<threads.h>`）
- [ ] `atomic_flag`、原子类型（C11，`<stdatomic.h>`）
- [ ] `memory_order`（C11，`<stdatomic.h>`）
- [ ] `fenv_t`、`fexcept_t`（`<fenv.h>`）

---

## 三、运算符与标点符号

### 3.1 算术运算符
- [x] `+`（一元正号 / 二元加法）
- [x] `-`（一元负号 / 二元减法）
- [x] `*`（乘法 / 解引用）
- [x] `/`（除法）
- [ ] `%`（取模/求余）
- [ ] `++`（自增，前缀与后缀）
- [ ] `--`（自减，前缀与后缀）

### 3.2 关系运算符
- [x] `<`（小于）
- [x] `>`（大于）
- [x] `<=`（小于等于）
- [x] `>=`（大于等于）
- [x] `==`（等于）
- [x] `!=`（不等于）

### 3.3 逻辑运算符
- [ ] `!`（逻辑非）
- [ ] `&&`（逻辑与）
- [ ] `||`（逻辑或）

### 3.4 位运算符
- [ ] `~`（按位取反）
- [ ] `&`（按位与 / 取地址）
- [ ] `|`（按位或）
- [ ] `^`（按位异或）
- [ ] `<<`（左移）
- [ ] `>>`（右移）

### 3.5 赋值运算符
- [x] `=`（简单赋值）
- [ ] `+=`（加赋值）
- [ ] `-=`（减赋值）
- [ ] `*=`（乘赋值）
- [ ] `/=`（除赋值）
- [ ] `%=`（模赋值）
- [ ] `&=`（与赋值）
- [ ] `|=`（或赋值）
- [ ] `^=`（异或赋值）
- [ ] `<<=`（左移赋值）
- [ ] `>>=`（右移赋值）

### 3.6 条件与序列运算符
- [ ] `?:`（条件/三目运算符）
- [ ] `,`（逗号运算符）

### 3.7 成员与指针运算符
- [ ] `.`（结构体/联合体成员访问）
- [ ] `->`（通过指针的成员访问）
- [ ] `[]`（下标/数组访问）
- [ ] `()`（函数调用 / 类型转换 / 改变优先级）
- [ ] `&`（取地址）
- [ ] `*`（解引用 / 指针声明）

### 3.8 其他运算符与关键字操作
- [ ] `sizeof`（获取大小）
- [ ] `_Alignof` / `alignof`（获取对齐要求，C11）
- [ ] `typeof` / `typeof_unqual`（获取表达式类型，C23）
- [ ] `_Generic`（泛型选择，C11）
- [ ] `&`（取地址运算符）
- [ ] `*`（间接寻址运算符）
- [ ] `(类型)`（强制类型转换）
- [ ] `_Atomic`（原子类型限定）

### 3.9 标点与分隔符
- [ ] `;`（语句结束符）
- [ ] `:`（标号/位域/条件运算符分隔）
- [ ] `{ }`（复合语句/初始化列表）
- [ ] `[ ]`（数组声明/下标）
- [ ] `( )`（函数声明/调用/优先级）
- [ ] `...`（可变参数/省略号）
- [ ] `#`（预处理指令标记）
- [ ] `##`（预处理拼接运算符）

---

## 四、常量与字面量

### 4.1 整数常量
- [ ] 十进制整数常量（`123`）
- [ ] 八进制整数常量（`0123`）
- [ ] 十六进制整数常量（`0x7B`、`0X7B`）
- [ ] 二进制整数常量（`0b1010`、`0B1010`，C23）
- [ ] 整数后缀：`u`/`U`、`l`/`L`、`ll`/`LL`、组合后缀
- [ ] 数字分隔符（`1'000'000`，C23）

### 4.2 浮点常量
- [ ] 十进制浮点常量（`3.14`、`1e10`）
- [ ] 十六进制浮点常量（`0x1.2p3`，C99）
- [ ] 浮点后缀：`f`/`F`、`l`/`L`

### 4.3 字符常量
- [ ] 普通字符常量（`'a'`）
- [ ] 宽字符常量（`L'a'`）
- [ ] UTF-8 字符常量（`u8'a'`，C23）
- [ ] UTF-16 字符常量（`u'a'`，C11）
- [ ] UTF-32 字符常量（`U'a'`，C11）
- [ ] 转义序列：`
`、`	`、`\`、`'`、`"`、`\?`
- [ ] 八进制转义（`A`）
- [ ] 十六进制转义（`A`）
- [ ] 通用字符名（`A`、 `A`，C99）

### 4.4 字符串字面量
- [ ] 普通字符串字面量（`"hello"`）
- [ ] 宽字符串字面量（`L"hello"`）
- [ ] UTF-8 字符串字面量（`u8"hello"`，C11）
- [ ] UTF-16 字符串字面量（`u"hello"`，C11）
- [ ] UTF-32 字符串字面量（`U"hello"`，C11）

### 4.5 其他常量
- [ ] `true` / `false`（布尔常量）
- [ ] `nullptr`（空指针常量，C23）
- [ ] `NULL`（空指针宏）
- [ ] 枚举常量

---

## 五、声明与定义

### 5.1 声明说明符
- [ ] 类型说明符
- [ ] 存储类说明符（`auto`、`static`、`extern`、`register`、`thread_local`、`constexpr`）
- [ ] 类型限定符（`const`、`volatile`、`restrict`、`_Atomic`）
- [ ] 函数说明符（`inline`、`_Noreturn`）
- [ ] 对齐说明符（`_Alignas` / `alignas`）

### 5.2 声明器（Declarators）
- [ ] 标识符声明
- [ ] 指针声明器（`*`）
- [ ] 数组声明器（`[]`、`[N]`、`[*]`）
- [ ] 函数声明器（`()`、`(参数列表)`）
- [ ] 初始化器（`=`）
- [ ] 复合字面量（`(类型){初始化列表}`，C99）
- [ ] 指定初始化（`[索引]=值`、`.成员=值`，C99）
- [ ] 空初始化器（`{}`，C23）

### 5.3 特殊声明
- [ ] 函数定义（原型形式）
- [ ] 位域声明（`: 宽度`）
- [ ] 柔性数组成员（`[]`，C99）
- [ ] 匿名结构体/联合体成员（C11）
- [ ] `typedef` 声明
- [ ] `extern` 声明
- [ ] 类型定义（`typedef`）

---

## 六、语句（Statements）

### 6.1 标号语句
- [ ] 标识符标号（`label:`）
- [ ] `case` 标号
- [ ] `default` 标号

### 6.2 表达式语句
- [ ] 表达式后跟分号

### 6.3 复合语句（块）
- [ ] `{ 声明列表 语句列表 }`

### 6.4 选择语句
- [ ] `if (表达式) 语句`
- [ ] `if (表达式) 语句 else 语句`
- [ ] `switch (表达式) 语句`
- [ ] `case` 常量表达式 `:` 语句
- [ ] `default :` 语句

### 6.5 迭代语句
- [ ] `while (表达式) 语句`
- [ ] `do 语句 while (表达式);`
- [ ] `for (表达式; 表达式; 表达式) 语句`
- [ ] `for (声明 表达式; 表达式) 语句`（C99）

### 6.6 跳转语句
- [ ] `goto 标识符;`
- [ ] `continue;`
- [ ] `break;`
- [ ] `return 表达式;` / `return;`

---

## 七、预处理指令（Preprocessor Directives）

### 7.1 文件包含
- [ ] `#include <头文件>`
- [ ] `#include "头文件"`

### 7.2 宏定义
- [ ] `#define 标识符 替换列表`
- [ ] `#define 标识符(参数列表) 替换列表`
- [ ] `#define 标识符(...) 替换列表`（可变参数宏，C99）
- [ ] `#undef 标识符`
- [ ] `#`（字符串化运算符）
- [ ] `##`（标记粘贴运算符）
- [ ] `__VA_ARGS__`（可变参数，C99）
- [ ] `__VA_OPT__`（可变参数可选处理，C23）

### 7.3 条件编译
- [ ] `#if 常量表达式`
- [ ] `#ifdef 标识符`
- [ ] `#ifndef 标识符`
- [ ] `#elif 常量表达式`
- [ ] `#elifdef 标识符`（C23）
- [ ] `#elifndef 标识符`（C23）
- [ ] `#else`
- [ ] `#endif`
- [ ] `defined(标识符)` / `defined 标识符`

### 7.4 其他指令
- [ ] `#line 行号`
- [ ] `#line 行号 "文件名"`
- [ ] `#error 消息`
- [ ] `#warning 消息`（C23）
- [ ] `#pragma 指令`
- [ ] `#embed`（二进制数据嵌入，C23）
- [ ] `#pragma once`（非标准但广泛支持）
- [ ] `_Pragma(字符串)`（C99）

### 7.5 标准预定义宏
- [ ] `__DATE__`
- [ ] `__TIME__`
- [ ] `__FILE__`
- [ ] `__LINE__`
- [ ] `__func__`（C99，局部预定义标识符）
- [ ] `__STDC__`
- [ ] `__STDC_VERSION__`
- [ ] `__STDC_HOSTED__`
- [ ] `__STDC_ISO_10646__`
- [ ] `__STDC_MB_MIGHT_NEQ_WC__`
- [ ] `__STDC_UTF_16__`
- [ ] `__STDC_UTF_32__`
- [ ] `__STDC_ANALYZABLE__`
- [ ] `__STDC_LIB_EXT1__`
- [ ] `__STDC_NO_ATOMICS__`
- [ ] `__STDC_NO_COMPLEX__`
- [ ] `__STDC_NO_THREADS__`
- [ ] `__STDC_NO_VLA__`
- [ ] `__has_include`（C23）

---

## 八、属性（Attributes，C23）

- [ ] `[[deprecated]]`
- [ ] `[[deprecated("理由")]]`
- [ ] `[[fallthrough]]`
- [ ] `[[maybe_unused]]`
- [ ] `[[nodiscard]]`
- [ ] `[[nodiscard("理由")]]`
- [ ] `[[noreturn]]`
- [ ] `[[reproducible]]`
- [ ] `[[unsequenced]]`

---

## 九、标准库头文件（Headers）

### 9.1 C89/C90 必备头文件
- [ ] `<assert.h>`
- [ ] `<ctype.h>`
- [ ] `<errno.h>`
- [ ] `<float.h>`
- [ ] `<limits.h>`
- [ ] `<locale.h>`
- [ ] `<math.h>`
- [ ] `<setjmp.h>`
- [ ] `<signal.h>`
- [ ] `<stdarg.h>`
- [ ] `<stddef.h>`
- [ ] `<stdio.h>`
- [ ] `<stdlib.h>`
- [ ] `<string.h>`
- [ ] `<time.h>`

### 9.2 C95 新增
- [ ] `<iso646.h>`
- [ ] `<wchar.h>`
- [ ] `<wctype.h>`

### 9.3 C99 新增
- [ ] `<complex.h>`
- [ ] `<fenv.h>`
- [ ] `<inttypes.h>`
- [ ] `<stdbool.h>`
- [ ] `<stdint.h>`
- [ ] `<tgmath.h>`

### 9.4 C11 新增
- [ ] `<stdalign.h>`
- [ ] `<stdatomic.h>`
- [ ] `<stdnoreturn.h>`
- [ ] `<threads.h>`
- [ ] `<uchar.h>`

### 9.5 C23 新增
- [ ] `<stdbit.h>`
- [ ] `<stdckdint.h>`

---

## 十、标准库函数与宏（按头文件分类）

### 10.1 `<assert.h>` — 诊断
- [ ] `assert(表达式)`
- [ ] `static_assert(表达式, 消息)`（C11）
- [ ] `static_assert(表达式)`（C23）

### 10.2 `<ctype.h>` — 字符分类
- [ ] `isalnum(int c)`
- [ ] `isalpha(int c)`
- [ ] `isblank(int c)`（C99）
- [ ] `iscntrl(int c)`
- [ ] `isdigit(int c)`
- [ ] `isgraph(int c)`
- [ ] `islower(int c)`
- [ ] `isprint(int c)`
- [ ] `ispunct(int c)`
- [ ] `isspace(int c)`
- [ ] `isupper(int c)`
- [ ] `isxdigit(int c)`
- [ ] `tolower(int c)`
- [ ] `toupper(int c)`

### 10.3 `<errno.h>` — 错误号
- [ ] `errno`（宏/外部变量）
- [ ] `EDOM`
- [ ] `EILSEQ`
- [ ] `ERANGE`

### 10.4 `<fenv.h>` — 浮点环境（C99）
- [ ] `feclearexcept(int excepts)`
- [ ] `fegetexceptflag(fexcept_t *flagp, int excepts)`
- [ ] `feraiseexcept(int excepts)`
- [ ] `fesetexceptflag(const fexcept_t *flagp, int excepts)`
- [ ] `fetestexcept(int excepts)`
- [ ] `fesetexcept(int excepts)`（C23）
- [ ] `fegetround(void)`
- [ ] `fesetround(int round)`
- [ ] `fegetenv(fenv_t *envp)`
- [ ] `feholdexcept(fenv_t *envp)`
- [ ] `fesetenv(const fenv_t *envp)`
- [ ] `feupdateenv(const fenv_t *envp)`
- [ ] `FENV_ACCESS`（pragma）
- [ ] `FENV_ROUND`（pragma，C23）
- [ ] `FENV_DEC_ROUND`（pragma，C23）

### 10.5 `<float.h>` — 浮点特性
- [ ] `FLT_RADIX`
- [ ] `FLT_ROUNDS`
- [ ] `FLT_EVAL_METHOD`
- [ ] `FLT_DECIMAL_DIG`（C11）
- [ ] `FLT_DIG`、`FLT_MANT_DIG`、`FLT_MIN_EXP`、`FLT_MIN_10_EXP`、`FLT_MAX_EXP`、`FLT_MAX_10_EXP`、`FLT_MAX`、`FLT_EPSILON`、`FLT_MIN`、`FLT_TRUE_MIN`（C11）
- [ ] `DBL_...` 系列宏
- [ ] `LDBL_...` 系列宏
- [ ] `DECIMAL_DIG`（C23 已废弃）
- [ ] `FLT16_...`（C23，若支持）
- [ ] `FLT32_...` / `FLT64_...` / `FLT128_...`（C23，若支持）
- [ ] `DEC32_...` / `DEC64_...` / `DEC128_...`（C23，若支持）

### 10.6 `<inttypes.h>` — 整数类型格式（C99）
- [ ] `imaxabs(intmax_t j)`
- [ ] `imaxdiv(intmax_t numer, intmax_t denom)`
- [ ] `strtoimax(const char *nptr, char **endptr, int base)`
- [ ] `strtouimax(const char *nptr, char **endptr, int base)`
- [ ] `wcstoimax(const wchar_t *nptr, wchar_t **endptr, int base)`
- [ ] `wcstouimax(const wchar_t *nptr, wchar_t **endptr, int base)`
- [ ] `PRId8`、`PRIi8`、`PRIo8`、`PRIu8`、`PRIx8`、`PRIX8` 等格式宏
- [ ] `SCNd8`、`SCNi8`、`SCNo8`、`SCNu8`、`SCNx8` 等扫描宏

### 10.7 `<iso646.h>` — 替代拼写（C95）
- [ ] `and`
- [ ] `and_eq`
- [ ] `bitand`
- [ ] `bitor`
- [ ] `compl`
- [ ] `not`
- [ ] `not_eq`
- [ ] `or`
- [ ] `or_eq`
- [ ] `xor`
- [ ] `xor_eq`

### 10.8 `<limits.h>` — 整数极限
- [ ] `CHAR_BIT`
- [ ] `SCHAR_MIN`、`SCHAR_MAX`
- [ ] `UCHAR_MAX`
- [ ] `CHAR_MIN`、`CHAR_MAX`
- [ ] `MB_LEN_MAX`
- [ ] `SHRT_MIN`、`SHRT_MAX`、`USHRT_MAX`
- [ ] `INT_MIN`、`INT_MAX`、`UINT_MAX`
- [ ] `LONG_MIN`、`LONG_MAX`、`ULONG_MAX`
- [ ] `LLONG_MIN`、`LLONG_MAX`、`ULLONG_MAX`（C99）
- [ ] `BOOL_WIDTH`、`BOOL_MAX`（C23）
- [ ] `CHAR_WIDTH`、`SCHAR_WIDTH`、`UCHAR_WIDTH`（C23）
- [ ] `SHRT_WIDTH`、`USHRT_WIDTH`（C23）
- [ ] `INT_WIDTH`、`UINT_WIDTH`（C23）
- [ ] `LONG_WIDTH`、`ULONG_WIDTH`（C23）
- [ ] `LLONG_WIDTH`、`ULLONG_WIDTH`（C23）
- [ ] `BITINT_MAXWIDTH`（C23）

### 10.9 `<locale.h>` — 本地化
- [ ] `setlocale(int category, const char *locale)`
- [ ] `localeconv(void)`
- [ ] `struct lconv`
- [ ] `LC_ALL`、`LC_COLLATE`、`LC_CTYPE`、`LC_MONETARY`、`LC_NUMERIC`、`LC_TIME`

### 10.10 `<math.h>` — 数学函数
#### 分类与查询
- [ ] `fpclassify(x)`
- [ ] `isfinite(x)`
- [ ] `isinf(x)`
- [ ] `isnan(x)`
- [ ] `isnormal(x)`
- [ ] `signbit(x)`
- [ ] `isgreater(x,y)`
- [ ] `isgreaterequal(x,y)`
- [ ] `isless(x,y)`
- [ ] `islessequal(x,y)`
- [ ] `islessgreater(x,y)`
- [ ] `isunordered(x,y)`
- [ ] `iseqsig(x,y)`（C23）

#### 三角函数
- [ ] `cos`、`sin`、`tan`
- [ ] `acos`、`asin`、`atan`、`atan2`

#### 双曲函数
- [ ] `cosh`、`sinh`、`tanh`
- [ ] `acosh`、`asinh`、`atanh`（C99）

#### 指数与对数
- [ ] `exp`、`exp2`、`expm1`（C99）
- [ ] `log`、`log10`、`log1p`、`log2`（C99）
- [ ] `ilogb`（C99）
- [ ] `logb`（C99）
- [ ] `frexp`、`ldexp`、`modf`
- [ ] `scalbn`、`scalbln`（C99）

#### 幂与绝对值
- [ ] `pow`、`sqrt`、`cbrt`（C99）
- [ ] `fabs`、`hypot`（C99）

#### 误差与伽马
- [ ] `erf`、`erfc`（C99）
- [ ] `lgamma`、`tgamma`（C99）

#### 最近整数
- [ ] `ceil`、`floor`、`trunc`（C99）
- [ ] `round`、`roundeven`（C99/C23）
- [ ] `nearbyint`、`rint`、`lrint`、`llrint`（C99）
- [ ] `lround`、`llround`（C99）

#### 余数
- [ ] `fmod`、`remainder`、`remquo`（C99）

#### 操作与提取
- [ ] `copysign`（C99）
- [ ] `nan`、`nanf`、`nanl`（C99）
- [ ] `nextafter`、`nexttoward`（C99）
- [ ] `nextup`、`nextdown`（C23）

#### 最大最小正差
- [ ] `fdim`、`fmax`、`fmin`（C99）
- [ ] `fmaxmag`、`fminmag`（C23）

#### 融合乘加
- [ ] `fma`（C99）

#### 窄化舍入（C23）
- [ ] `f16add`、`f16sub`、`f16mul`、`f16div`、`f16fma`（若支持）
- [ ] `f32add`、`f32sub`、`f32mul`、`f32div`、`f32fma`（若支持）

#### 十进制浮点相关（C23，若支持）
- [ ] `quantizedN`、`samequantumdN`、`quantumdN`、`llquantexpdN`
- [ ] `encodedec`、`decodedec`、`encodebin`、`decodebin`

### 10.11 `<setjmp.h>` — 非局部跳转
- [ ] `setjmp(jmp_buf env)`
- [ ] `longjmp(jmp_buf env, int val)`
- [ ] `jmp_buf`

### 10.12 `<signal.h>` — 信号处理
- [ ] `signal(int sig, void (*func)(int))`
- [ ] `raise(int sig)`
- [ ] `sig_atomic_t`
- [ ] `SIG_DFL`、`SIG_IGN`、`SIG_ERR`
- [ ] `SIGABRT`、`SIGFPE`、`SIGILL`、`SIGINT`、`SIGSEGV`、`SIGTERM`

### 10.13 `<stdalign.h>` — 对齐支持（C11）
- [ ] `alignas`（宏/关键字）
- [ ] `alignof`（宏/关键字）

### 10.14 `<stdarg.h>` — 可变参数
- [ ] `va_list`
- [ ] `va_start(va_list ap, parmN)`
- [ ] `va_arg(va_list ap, type)`
- [ ] `va_copy(va_list dest, va_list src)`（C99）
- [ ] `va_end(va_list ap)`

### 10.15 `<stdatomic.h>` — 原子操作（C11）
- [ ] `atomic_bool` 等原子类型
- [ ] `ATOMIC_BOOL_LOCK_FREE` 等宏
- [ ] `memory_order_relaxed`、`memory_order_consume`、`memory_order_acquire`、`memory_order_release`、`memory_order_acq_rel`、`memory_order_seq_cst`
- [ ] `atomic_init(v, c)`
- [ ] `atomic_is_lock_free(obj)`
- [ ] `atomic_store(obj, desired)`
- [ ] `atomic_load(obj)`
- [ ] `atomic_exchange(obj, desired)`
- [ ] `atomic_compare_exchange_strong(obj, expected, desired)`
- [ ] `atomic_compare_exchange_weak(obj, expected, desired)`
- [ ] `atomic_fetch_add`、`atomic_fetch_sub`、`atomic_fetch_or`、`atomic_fetch_xor`、`atomic_fetch_and`
- [ ] `atomic_thread_fence(order)`
- [ ] `atomic_signal_fence(order)`
- [ ] `atomic_flag_test_and_set(obj)`
- [ ] `atomic_flag_clear(obj)`
- [ ] `ATOMIC_VAR_INIT(value)`
- [ ] `ATOMIC_FLAG_INIT`
- [ ] `kill_dependency(y)`

### 10.16 `<stdbit.h>` — 位与字节操作（C23）
- [ ] `stdc_count_ones` 系列
- [ ] `stdc_leading_zeros` 系列
- [ ] `stdc_trailing_zeros` 系列
- [ ] `stdc_first_trailing_one` 系列
- [ ] `stdc_count_zeros` 系列
- [ ] `stdc_leading_ones` 系列
- [ ] `stdc_trailing_ones` 系列
- [ ] `stdc_first_leading_zero` 系列
- [ ] `stdc_bit_width` 系列
- [ ] `stdc_bit_ceil` 系列
- [ ] `stdc_bit_floor` 系列

### 10.17 `<stdbool.h>` — 布尔类型（C99）
- [ ] `bool`（C23 前为宏，现为关键字）
- [ ] `true`
- [ ] `false`
- [ ] `__bool_true_false_are_defined`

### 10.18 `<stdckdint.h>` — 检查整数算术（C23）
- [ ] `ckd_add(result, a, b)`
- [ ] `ckd_sub(result, a, b)`
- [ ] `ckd_mul(result, a, b)`

### 10.19 `<stddef.h>` — 通用定义
- [ ] `NULL`
- [ ] `offsetof(type, member)`
- [ ] `ptrdiff_t`
- [ ] `size_t`
- [ ] `max_align_t`（C11）
- [ ] `nullptr_t`（C23）
- [ ] `wchar_t`
- [ ] `unreachable()`（C23）

### 10.20 `<stdint.h>` — 定宽整数（C99）
- [ ] `int8_t`、`int16_t`、`int32_t`、`int64_t`
- [ ] `uint8_t`、`uint16_t`、`uint32_t`、`uint64_t`
- [ ] `int_least8_t` 至 `int_least64_t`
- [ ] `uint_least8_t` 至 `uint_least64_t`
- [ ] `int_fast8_t` 至 `int_fast64_t`
- [ ] `uint_fast8_t` 至 `uint_fast64_t`
- [ ] `intptr_t`、`uintptr_t`
- [ ] `intmax_t`、`uintmax_t`
- [ ] `INT8_MIN`、`INT8_MAX`、`UINT8_MAX` 等极限宏
- [ ] `INT8_C`、`INT16_C`、`INT32_C`、`INT64_C` 等常量宏

### 10.21 `<stdio.h>` — 标准输入输出
#### 文件操作
- [ ] `fopen(const char *filename, const char *mode)`
- [ ] `freopen(const char *filename, const char *mode, FILE *stream)`
- [ ] `fflush(FILE *stream)`
- [ ] `fclose(FILE *stream)`
- [ ] `remove(const char *filename)`
- [ ] `rename(const char *old, const char *new)`
- [ ] `tmpfile(void)`
- [ ] `tmpnam(char *s)`
- [ ] `setbuf(FILE *stream, char *buf)`
- [ ] `setvbuf(FILE *stream, char *buf, int mode, size_t size)`

#### 格式化输入输出
- [ ] `fprintf(FILE *stream, const char *format, ...)`
- [ ] `fscanf(FILE *stream, const char *format, ...)`
- [ ] `printf(const char *format, ...)`
- [ ] `scanf(const char *format, ...)`
- [ ] `sprintf(char *s, const char *format, ...)`
- [ ] `sscanf(const char *s, const char *format, ...)`
- [ ] `snprintf(char *s, size_t n, const char *format, ...)`（C99）
- [ ] `vfprintf(FILE *stream, const char *format, va_list arg)`
- [ ] `vfscanf(FILE *stream, const char *format, va_list arg)`（C99）
- [ ] `vprintf(const char *format, va_list arg)`
- [ ] `vscanf(const char *format, va_list arg)`（C99）
- [ ] `vsprintf(char *s, const char *format, va_list arg)`
- [ ] `vsscanf(const char *s, const char *format, va_list arg)`（C99）
- [ ] `vsnprintf(char *s, size_t n, const char *format, va_list arg)`（C99）
- [ ] `vfprintf_s`、`vfscanf_s` 等边界检查版本（C11 可选）

#### 字符输入输出
- [ ] `fgetc(FILE *stream)`
- [ ] `fgets(char *s, int n, FILE *stream)`
- [ ] `fputc(int c, FILE *stream)`
- [ ] `fputs(const char *s, FILE *stream)`
- [ ] `getc(FILE *stream)`
- [ ] `getchar(void)`
- [ ] `putc(int c, FILE *stream)`
- [ ] `putchar(int c)`
- [ ] `puts(const char *s)`
- [ ] `ungetc(int c, FILE *stream)`
- [ ] `getchar_unlocked`、`putchar_unlocked` 等（POSIX 扩展，非标准 C）

#### 直接输入输出
- [ ] `fread(void *ptr, size_t size, size_t nmemb, FILE *stream)`
- [ ] `fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)`

#### 文件定位
- [ ] `fgetpos(FILE *stream, fpos_t *pos)`
- [ ] `fseek(FILE *stream, long int offset, int whence)`
- [ ] `fsetpos(FILE *stream, const fpos_t *pos)`
- [ ] `ftell(FILE *stream)`
- [ ] `rewind(FILE *stream)`

#### 错误处理
- [ ] `clearerr(FILE *stream)`
- [ ] `feof(FILE *stream)`
- [ ] `ferror(FILE *stream)`
- [ ] `perror(const char *s)`

#### 标准流
- [ ] `stdin`
- [ ] `stdout`
- [ ] `stderr`
- [ ] `EOF`
- [ ] `BUFSIZ`
- [ ] `FILENAME_MAX`
- [ ] `FOPEN_MAX`
- [ ] `L_tmpnam`
- [ ] `SEEK_CUR`、`SEEK_END`、`SEEK_SET`
- [ ] `_IOFBF`、`_IOLBF`、`_IONBF`
- [ ] `TMP_MAX`

### 10.22 `<stdlib.h>` — 通用工具
#### 数值转换
- [ ] `atof(const char *nptr)`
- [ ] `atoi(const char *nptr)`
- [ ] `atol(const char *nptr)`
- [ ] `atoll(const char *nptr)`（C99）
- [ ] `strtod(const char *nptr, char **endptr)`
- [ ] `strtof(const char *nptr, char **endptr)`（C99）
- [ ] `strtold(const char *nptr, char **endptr)`（C99）
- [ ] `strtol(const char *nptr, char **endptr, int base)`
- [ ] `strtoll(const char *nptr, char **endptr, int base)`（C99）
- [ ] `strtoul(const char *nptr, char **endptr, int base)`
- [ ] `strtoull(const char *nptr, char **endptr, int base)`（C99）
- [ ] `strfromd`、`strfromf`、`strfroml`（C23）

#### 伪随机数
- [ ] `rand(void)`
- [ ] `srand(unsigned int seed)`
- [ ] `RAND_MAX`

#### 内存管理
- [ ] `malloc(size_t size)`
- [ ] `calloc(size_t nmemb, size_t size)`
- [ ] `realloc(void *ptr, size_t size)`
- [ ] `free(void *ptr)`
- [ ] `aligned_alloc(size_t alignment, size_t size)`（C11）
- [ ] `memalignment(const void *p)`（C23）

#### 进程控制
- [ ] `abort(void)`
- [ ] `atexit(void (*func)(void))`
- [ ] `at_quick_exit(void (*func)(void))`（C11）
- [ ] `exit(int status)`
- [ ] `_Exit(int status)`（C99）
- [ ] `quick_exit(int status)`（C11）
- [ ] `getenv(const char *name)`
- [ ] `system(const char *string)`

#### 搜索与排序
- [ ] `bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))`
- [ ] `qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))`
- [ ] `qsort_s`（C11 可选）

#### 整数算术
- [ ] `abs(int n)`
- [ ] `labs(long int n)`
- [ ] `llabs(long long int n)`（C99）
- [ ] `div(int numer, int denom)`
- [ ] `ldiv(long int numer, long int denom)`
- [ ] `lldiv(long long int numer, long long int denom)`（C99）

#### 多字节/宽字符转换
- [ ] `mblen(const char *s, size_t n)`
- [ ] `mbtowc(wchar_t *pwc, const char *s, size_t n)`
- [ ] `wctomb(char *s, wchar_t wchar)`
- [ ] `mbstowcs(wchar_t *pwcs, const char *s, size_t n)`
- [ ] `wcstombs(char *s, const wchar_t *pwcs, size_t n)`

#### 宏
- [ ] `EXIT_FAILURE`
- [ ] `EXIT_SUCCESS`
- [ ] `MB_CUR_MAX`
- [ ] `NULL`

### 10.23 `<stdnoreturn.h>` — noreturn 支持（C11，C23 已废弃）
- [ ] `noreturn`

### 10.24 `<string.h>` — 字符串处理
#### 复制
- [ ] `memcpy(void *dest, const void *src, size_t n)`
- [ ] `memmove(void *dest, const void *src, size_t n)`
- [ ] `strcpy(char *dest, const char *src)`
- [ ] `strncpy(char *dest, const char *src, size_t n)`
- [ ] `memccpy(void *dest, const void *src, int c, size_t n)`（C23）
- [ ] `strdup(const char *s)`（C23）
- [ ] `strndup(const char *s, size_t size)`（C23）

#### 连接
- [ ] `strcat(char *dest, const char *src)`
- [ ] `strncat(char *dest, const char *src, size_t n)`

#### 比较
- [ ] `memcmp(const void *s1, const void *s2, size_t n)`
- [ ] `strcmp(const char *s1, const char *s2)`
- [ ] `strcoll(const char *s1, const char *s2)`
- [ ] `strncmp(const char *s1, const char *s2, size_t n)`
- [ ] `strxfrm(char *dest, const char *src, size_t n)`

#### 搜索
- [ ] `memchr(const void *s, int c, size_t n)`
- [ ] `strchr(const char *s, int c)`
- [ ] `strcspn(const char *s, const char *reject)`
- [ ] `strpbrk(const char *s, const char *accept)`
- [ ] `strrchr(const char *s, int c)`
- [ ] `strspn(const char *s, const char *accept)`
- [ ] `strstr(const char *haystack, const char *needle)`
- [ ] `strtok(char *str, const char *delim)`
- [ ] `strtok_r(char *str, const char *delim, char **saveptr)`（C23）

#### 其他
- [ ] `memset(void *s, int c, size_t n)`
- [ ] `memset_explicit(void *s, int c, size_t n)`（C23）
- [ ] `strerror(int errnum)`
- [ ] `strlen(const char *s)`
- [ ] `strerrorlen_s`（C11 可选）
- [ ] `strerror_s`（C11 可选）

### 10.25 `<tgmath.h>` — 泛型数学（C99）
- [ ] 类型泛化宏（`acos`、`asin`、`atan`、`atan2`、`cos`、`sin`、`tan` 等）
- [ ] 复数与实数统一调用

### 10.26 `<threads.h>` — 线程支持（C11）
#### 线程管理
- [ ] `thrd_create(thrd_t *thr, thrd_start_t func, void *arg)`
- [ ] `thrd_current(void)`
- [ ] `thrd_detach(thrd_t thr)`
- [ ] `thrd_equal(thrd_t thr0, thrd_t thr1)`
- [ ] `thrd_exit(int res)`
- [ ] `thrd_join(thrd_t thr, int *res)`
- [ ] `thrd_sleep(const struct timespec *duration, struct timespec *remaining)`
- [ ] `thrd_yield(void)`

#### 互斥锁
- [ ] `mtx_init(mtx_t *mtx, int type)`
- [ ] `mtx_lock(mtx_t *mtx)`
- [ ] `mtx_timedlock(mtx_t *mtx, const struct timespec *ts)`
- [ ] `mtx_trylock(mtx_t *mtx)`
- [ ] `mtx_unlock(mtx_t *mtx)`
- [ ] `mtx_destroy(mtx_t *mtx)`
- [ ] `mtx_plain`、`mtx_recursive`、`mtx_timed`

#### 条件变量
- [ ] `cnd_init(cnd_t *cond)`
- [ ] `cnd_signal(cnd_t *cond)`
- [ ] `cnd_broadcast(cnd_t *cond)`
- [ ] `cnd_wait(cnd_t *cond, mtx_t *mtx)`
- [ ] `cnd_timedwait(cnd_t *cond, mtx_t *mtx, const struct timespec *ts)`
- [ ] `cnd_destroy(cnd_t *cond)`

#### 线程本地存储
- [ ] `tss_create(tss_t *key, tss_dtor_t dtor)`
- [ ] `tss_delete(tss_t key)`
- [ ] `tss_get(tss_t key)`
- [ ] `tss_set(tss_t key, void *val)`
- [ ] `TSS_DTOR_ITERATIONS`

#### 一次性初始化
- [ ] `call_once(once_flag *flag, void (*func)(void))`
- [ ] `ONCE_FLAG_INIT`

#### 返回值宏
- [ ] `thrd_success`、`thrd_timedout`、`thrd_busy`、`thrd_error`、`thrd_nomem`

### 10.27 `<time.h>` — 日期与时间
- [ ] `clock(void)`
- [ ] `difftime(time_t time1, time_t time0)`
- [ ] `mktime(struct tm *timeptr)`
- [ ] `time(time_t *timer)`
- [ ] `timespec_get(struct timespec *ts, int base)`（C11）
- [ ] `timespec_getres(struct timespec *ts, int base)`（C23）
- [ ] `asctime(const struct tm *timeptr)`（C23 已废弃）
- [ ] `ctime(const time_t *timer)`（C23 已废弃）
- [ ] `gmtime(const time_t *timer)`
- [ ] `gmtime_r(const time_t *timer, struct tm *result)`（C23）
- [ ] `localtime(const time_t *timer)`
- [ ] `localtime_r(const time_t *timer, struct tm *result)`（C23）
- [ ] `timegm(struct tm *timeptr)`（C23）
- [ ] `strftime(char *s, size_t max, const char *format, const struct tm *tm)`
- [ ] `wcsftime`（`<wchar.h>`）

#### 类型与宏
- [ ] `CLOCKS_PER_SEC`
- [ ] `TIME_UTC`
- [ ] `TIME_MONOTONIC`（C23）
- [ ] `clock_t`、`time_t`、`size_t`、`timespec`、`tm`

### 10.28 `<uchar.h>` — Unicode 工具（C11）
- [ ] `mbstate_t`
- [ ] `size_t`
- [ ] `char16_t`、`char32_t`、`char8_t`（C23）
- [ ] `mbrtoc16(char16_t *pc16, const char *s, size_t n, mbstate_t *ps)`
- [ ] `c16rtomb(char *s, char16_t c16, mbstate_t *ps)`
- [ ] `mbrtoc32(char32_t *pc32, const char *s, size_t n, mbstate_t *ps)`
- [ ] `c32rtomb(char *s, char32_t c32, mbstate_t *ps)`
- [ ] `mbrtoc8(char8_t *pc8, const char *s, size_t n, mbstate_t *ps)`（C23）
- [ ] `c8rtomb(char *s, char8_t c8, mbstate_t *ps)`（C23）

### 10.29 `<wchar.h>` — 宽字符处理（C95）
#### 宽字符 I/O
- [ ] `fgetwc(FILE *stream)`
- [ ] `fgetws(wchar_t *s, int n, FILE *stream)`
- [ ] `fputwc(wchar_t c, FILE *stream)`
- [ ] `fputws(const wchar_t *s, FILE *stream)`
- [ ] `getwc(FILE *stream)`
- [ ] `getwchar(void)`
- [ ] `putwc(wchar_t c, FILE *stream)`
- [ ] `putwchar(wchar_t c)`
- [ ] `ungetwc(wint_t c, FILE *stream)`

#### 宽字符串数值转换
- [ ] `wcstod(const wchar_t *nptr, wchar_t **endptr)`
- [ ] `wcstof(const wchar_t *nptr, wchar_t **endptr)`（C99）
- [ ] `wcstold(const wchar_t *nptr, wchar_t **endptr)`（C99）
- [ ] `wcstol(const wchar_t *nptr, wchar_t **endptr, int base)`
- [ ] `wcstoll(const wchar_t *nptr, wchar_t **endptr, int base)`（C99）
- [ ] `wcstoul(const wchar_t *nptr, wchar_t **endptr, int base)`
- [ ] `wcstoull(const wchar_t *nptr, wchar_t **endptr, int base)`（C99）

#### 宽字符串操作
- [ ] `wcscpy(wchar_t *dest, const wchar_t *src)`
- [ ] `wcsncpy(wchar_t *dest, const wchar_t *src, size_t n)`
- [ ] `wmemcpy(wchar_t *dest, const wchar_t *src, size_t n)`
- [ ] `wmemmove(wchar_t *dest, const wchar_t *src, size_t n)`
- [ ] `wcscat(wchar_t *dest, const wchar_t *src)`
- [ ] `wcsncat(wchar_t *dest, const wchar_t *src, size_t n)`
- [ ] `wcscmp(const wchar_t *s1, const wchar_t *s2)`
- [ ] `wcscoll(const wchar_t *s1, const wchar_t *s2)`
- [ ] `wcsncmp(const wchar_t *s1, const wchar_t *s2, size_t n)`
- [ ] `wcsxfrm(wchar_t *dest, const wchar_t *src, size_t n)`
- [ ] `wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n)`
- [ ] `wcschr(const wchar_t *s, wchar_t c)`
- [ ] `wcscspn(const wchar_t *s, const wchar_t *reject)`
- [ ] `wcspbrk(const wchar_t *s, const wchar_t *accept)`
- [ ] `wcsrchr(const wchar_t *s, wchar_t c)`
- [ ] `wcsspn(const wchar_t *s, const wchar_t *accept)`
- [ ] `wcsstr(const wchar_t *haystack, const wchar_t *needle)`
- [ ] `wcstok(wchar_t *str, const wchar_t *delim, wchar_t **ptr)`（C99）
- [ ] `wmemchr(const wchar_t *s, wchar_t c, size_t n)`
- [ ] `wmemset(wchar_t *s, wchar_t c, size_t n)`
- [ ] `wcslen(const wchar_t *s)`
- [ ] `wcsftime(wchar_t *s, size_t maxsize, const wchar_t *format, const struct tm *timeptr)`

#### 宽字符与多字节转换
- [ ] `btowc(int c)`
- [ ] `wctob(wint_t c)`
- [ ] `mbsinit(const mbstate_t *ps)`
- [ ] `mbrlen(const char *s, size_t n, mbstate_t *ps)`
- [ ] `mbrtowc(wchar_t *pwc, const char *s, size_t n, mbstate_t *ps)`
- [ ] `wcrtomb(char *s, wchar_t wc, mbstate_t *ps)`
- [ ] `mbsrtowcs(wchar_t *dest, const char **src, size_t len, mbstate_t *ps)`
- [ ] `wcsrtombs(char *dest, const wchar_t **src, size_t len, mbstate_t *ps)`

#### 格式化 I/O
- [ ] `fwprintf(FILE *stream, const wchar_t *format, ...)`
- [ ] `fwscanf(FILE *stream, const wchar_t *format, ...)`
- [ ] `swprintf(wchar_t *s, size_t n, const wchar_t *format, ...)`
- [ ] `swscanf(const wchar_t *s, const wchar_t *format, ...)`
- [ ] `vfwprintf(FILE *stream, const wchar_t *format, va_list arg)`
- [ ] `vfwscanf(FILE *stream, const wchar_t *format, va_list arg)`（C99）
- [ ] `vswprintf(wchar_t *s, size_t n, const wchar_t *format, va_list arg)`
- [ ] `vswscanf(const wchar_t *s, const wchar_t *format, va_list arg)`（C99）
- [ ] `vwprintf(const wchar_t *format, va_list arg)`
- [ ] `vwscanf(const wchar_t *format, va_list arg)`（C99）
- [ ] `wprintf(const wchar_t *format, ...)`
- [ ] `wscanf(const wchar_t *format, ...)`

### 10.30 `<wctype.h>` — 宽字符分类（C95）
- [ ] `iswalnum(wint_t wc)`
- [ ] `iswalpha(wint_t wc)`
- [ ] `iswblank(wint_t wc)`（C99）
- [ ] `iswcntrl(wint_t wc)`
- [ ] `iswdigit(wint_t wc)`
- [ ] `iswgraph(wint_t wc)`
- [ ] `iswlower(wint_t wc)`
- [ ] `iswprint(wint_t wc)`
- [ ] `iswpunct(wint_t wc)`
- [ ] `iswspace(wint_t wc)`
- [ ] `iswupper(wint_t wc)`
- [ ] `iswxdigit(wint_t wc)`
- [ ] `iswctype(wint_t wc, wctype_t desc)`
- [ ] `wctype(const char *property)`
- [ ] `towlower(wint_t wc)`
- [ ] `towupper(wint_t wc)`
- [ ] `towctrans(wint_t wc, wctrans_t desc)`
- [ ] `wctrans(const char *property)`

### 10.31 `<complex.h>` — 复数运算（C99，可选）
- [ ] `complex`（宏/关键字）
- [ ] `_Complex_I`、`I`
- [ ] `CMPLX(x,y)`、`CMPLXF(x,y)`、`CMPLXL(x,y)`（C11）
- [ ] `creal`、`cimag`、`cabs`、`carg`、`conj`、`cproj`、`cexp`、`clog`、`csqrt`、`cpow`、`csin`、`ccos`、`ctan`、`casin`、`cacos`、`catan`、`csinh`、`ccosh`、`ctanh`、`casinh`、`cacosh`、`catanh`

### 10.32 边界检查接口（C11 可选，`<stdio.h>`、`<stdlib.h>`、`<string.h>`、`<wchar.h>` 等）
- [ ] `errno_t`
- [ ] `rsize_t`
- [ ] `RSIZE_MAX`
- [ ] `fopen_s`、`freopen_s`、`tmpfile_s`、`tmpnam_s`
- [ ] `fprintf_s`、`fscanf_s`、`printf_s`、`scanf_s`、`sprintf_s`、`sscanf_s`、`snprintf_s`
- [ ] `gets_s`
- [ ] `strcpy_s`、`strncpy_s`、`strcat_s`、`strncat_s`、`strerror_s`、`strnlen_s`
- [ ] `wcscpy_s`、`wcsncpy_s`、`wcscat_s`、`wcsncat_s`、`wcsnlen_s`
- [ ] `memcpy_s`、`memmove_s`、`memset_s`
- [ ] `bsearch_s`、`qsort_s`

---

## 十一、其他语言特性

### 11.1 类型系统
- [ ] 隐式类型转换（整型提升、算术转换）
- [ ] 显式类型转换（强制转换）
- [ ] 指针算术
- [ ] 不完整类型
- [ ] 兼容类型规则
- [ ] 类型 punning（`union` 或指针转换）
- [ ] `_Generic` 泛型选择（C11）
- [ ] 变长数组 VLA（C99，C11 降为可选）

### 11.2 作用域与链接
- [ ] 块作用域
- [ ] 文件作用域
- [ ] 函数作用域（仅标号）
- [ ] 函数原型作用域
- [ ] 外部链接
- [ ] 内部链接
- [ ] 无链接

### 11.3 存储期
- [ ] 自动存储期
- [ ] 静态存储期
- [ ] 线程存储期（C11）
- [ ] 动态分配存储期

### 11.4 对齐（C11）
- [ ] `_Alignas` / `alignas`
- [ ] `_Alignof` / `alignof`
- [ ] `max_align_t`
- [ ] `aligned_alloc`

### 11.5 内存顺序与并发（C11）
- [ ] 内存模型与数据竞争
- [ ] `happens-before` 关系
- [ ] 顺序一致性

### 11.6 主函数要求
- [ ] `int main(void)`
- [ ] `int main(int argc, char *argv[])`
- [ ] `int main(int argc, char *argv[], char *envp[])`（常见扩展）

### 11.7 程序终止
- [ ] `return` 从 `main`
- [ ] `exit` 正常终止
- [ ] `_Exit` / `_exit` 立即终止
- [ ] `abort` 异常终止
- [ ] `quick_exit`（C11）
- [ ] 未捕获信号

---

*本清单覆盖 C89/C90 至 C23 全部标准要求功能，包括关键字、类型、运算符、预处理、标准库头文件与函数、宏及核心语言机制。部分功能在特定标准版本为可选（如复数、十进制浮点、边界检查接口），已在括号中标注。*
