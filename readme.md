

# node-hvalidator —— HIgh performance nodejs validator moudle with C++.

目前正在编码中...

Currently coding...

##Install

   npm install hvalidator

   var hv = require('hvalidator')

##API(isxxx function return bool)

   
   hv.is(arg1,regexp);//arg1:string or number; arg:regexp

   hv.isArray(arg1);//arg1:array will be true, others will be false;

   hv.isRegExp(arg1);//arg1:regexp will be true, others will be false;

   hv.isNumber(arg1);//arg1:number will be true, others will be false;

   hv.isPositive(arg1);//arg1:the number>0 will be true, others will be false;

   hv.isInt(arg1);//arg1:the int will be true, others will be false;

   hv.notEmpty(arg1);//arg1:string or number; others will be false; this function can't trim;

   hv.isDate(arg1);//arg1:the date will be true, others will be false;

   hv.isString(arg1);//arg1:the string will be true, others will be false;

   hv.isLowercase(arg1);//arg1:string and lowercasen will be true, others will be false;

   hv.isUppercase(arg1);//arg1:string and uppercase will be true, others will be false;

   hv.isIn(arg1,contain);//arg1 is string or number; arg2 is array or string

   hv.isLen(arg1,min,max);//arg1:string or number or array;

   hv.isEmail(arg1);//arg1:string match for email

   hv.isUrl(arg1);//arg1:string match for url

   hv.isIp(arg1);//arg1:string match for ipaddr
 

##Example:

	eq(hv.is('aaaa11@aaaa.com',/[_\.0-9a-z-]+@([0-9a-z][0-9a-z-]+\.)+[a-z]{2,3}$/), true);
	eq(hv.is('1234567',/\d+/),false);
	eq(hv.is('1',/^1$/),true);
	eq(hv.is('11aa',/\d/),false);

	eq(hv.isArray([]),true)
	eq(hv.isArray(123),false)

	eq(hv.isRegExp(/\d/),true)
	eq(hv.isRegExp(123),false)

	eq(hv.isNumber(123),true)
	eq(hv.isNumber('abc'),false)

	eq(hv.isPositive(122.2),true)
	eq(hv.isPositive(-1),false)

	eq(hv.isInt(123),true)
	eq(hv.isInt(123.2),false)

	eq(hv.notEmpty("aa"),true)
	eq(hv.notEmpty(""),false)

	eq(hv.isDate(new Date()),true)
	eq(hv.isDate(12321312),false)

	eq(hv.isString('abc'),true)
	eq(hv.isString(123),false)

	eq(hv.isLowercase('abc'),true)
	eq(hv.isLowercase('a123A1'),false)

	eq(hv.isUppercase('ABC'),true)
	eq(hv.isUppercase('a123A1'),false)


	eq(hv.isIn('ABC','ABCDEFG'),true)
	eq(hv.isIn('AAA','ABCDEFT'),false)
	eq(hv.isIn(123,'123456789'),true)
	eq(hv.isIn(123,'ABCDEFT'),false)

	eq(hv.isIn('ABC',['ABCDEFG','123','234','ABC']),true)
	eq(hv.isIn('AAA',['ABCDEFG','123','234','abc']),false)
	eq(hv.isIn(234,['ABCDEFG','123','234','abc']),true)
	eq(hv.isIn(123,['ABCDEFG','567','234','abc']),false)

	eq(hv.isLen('ABC',1,5),true)
	eq(hv.isLen('aaaaaaaa',1,5),false)
	eq(hv.isLen(5,1,5),true)
	eq(hv.isLen(6,1,5),false)
	eq(hv.isLen([1,2,3],1,5),true)
	eq(hv.isLen([],1,5),false)

	eq(hv.isEmail('sfsd@fsfas.com'),true);
	eq(hv.isEmail('sfsd@@@fsfas.com'),false);

	eq(hv.isUrl('http://bbs.csdn.net/topics/270080323/'),true);
	eq(hv.isUrl('fasfdfdas'),false);

	eq(hv.isIp('10.10.10.10'),true);
	eq(hv.isIp('12.12.12.10.10'),false);
  
##performance
   
   see ./benchmark/benchmark.js

   result is:

   nodejs: 8ms

   c++: 1ms


## 授权协议

基于MIT协议发布：

```
Copyright (c) 2012 Lei Zongmin(吴中骅) <snoopyxdy@gmail.com>

The MIT License

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```