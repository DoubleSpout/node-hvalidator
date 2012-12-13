var sv = require('../index.js');
var eq = require('assert').strictEqual;
var op = require('os').platform();


	eq(sv.is('aaaa11@aaaa.com',/[_\.0-9a-z-]+@([0-9a-z][0-9a-z-]+\.)+[a-z]{2,3}$/), true);
	eq(sv.is('1234567',/\d+/),true);
	eq(sv.is('1',/^1$/),true);
	eq(sv.is('11aa',/\d/),true);



    

eq(sv.isArray([]),true)
eq(sv.isArray(123),false)

eq(sv.isRegExp(/111/),true)
eq(sv.isRegExp(123),false)

eq(sv.isNumber(123),true)
eq(sv.isNumber('abc'),false)

eq(sv.isPositive(122.2),true)
eq(sv.isPositive(-1),false)

eq(sv.isInt(123),true)
eq(sv.isInt(123.2),false)


eq(sv.notEmpty("aa"),true)
eq(sv.notEmpty(""),false)


eq(sv.isDate(new Date()),true)
eq(sv.isDate(12321312),false)

eq(sv.isString('abc'),true)
eq(sv.isString(123),false)

eq(sv.isLowercase('abc'),true)
eq(sv.isLowercase('a123A1'),false)

eq(sv.isUppercase('ABC'),true)
eq(sv.isUppercase('a123A1'),false)


eq(sv.isIn('ABC','ABCDEFG'),true)
eq(sv.isIn('AAA','ABCDEFT'),false)
eq(sv.isIn(123,'123456789'),true)
eq(sv.isIn(123,'ABCDEFT'),false)


eq(sv.isIn('ABC',['ABCDEFG','123','234','ABC']),true)
eq(sv.isIn('AAA',['ABCDEFG','123','234','abc']),false)
eq(sv.isIn(234,['ABCDEFG','123','234','abc']),true)
eq(sv.isIn(123,['ABCDEFG','567','234','abc']),false)


eq(sv.isLen('ABC',1,5),true)
eq(sv.isLen('aaaaaaaa',1,5),false)
eq(sv.isLen(5,1,5),true)
eq(sv.isLen(6,1,5),false)
eq(sv.isLen([1,2,3],1,5),true)
eq(sv.isLen([],1,5),false)


eq(sv.isEmail('sfsd@fsfas.com'),true);
eq(sv.isEmail('sfsd@@@fsfas.com'),false);


eq(sv.isUrl('http://bbs.csdn.net/topics/270080323/'),true);
eq(sv.isUrl('fasfdfdas'),false);


eq(sv.isIp('10.10.10.10'),true);
eq(sv.isIp('12.12.12.10.10'),false);




eq(sv.isAlpha('abcdeft'),true);
eq(sv.isAlpha(''),false);
eq(sv.isAlpha('12345abc'),false);
eq(sv.isAlpha(1234),false);
eq(sv.isAlpha({}),false);


eq(sv.isAlphanumeric('abdefg'),true);
eq(sv.isAlphanumeric('123'),true);
eq(sv.isAlphanumeric('abdefg123'),true);
eq(sv.isAlphanumeric(12312312),true);
eq(sv.isAlphanumeric(''),false);
eq(sv.isAlphanumeric([]),false);
eq(sv.isAlphanumeric({}),false);













console.log('test done')
