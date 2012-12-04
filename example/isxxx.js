var sv = require('../index.js');
var op = require('os').platform();

if(op=='win32'){
	console.log(sv.is('aaaa11@aaaa.com',/[_\\.0-9a-z-]+@([0-9a-z][0-9a-z-]+\\.)+[a-z]{2,3}$/));
	console.log(sv.is('1234567',/\\d+/));
	console.log(sv.is('11aa',/^\\d$/));
}
else{
console.log(sv.is('aaaa11@aaaa.com',/[_\.0-9a-z-]+@([0-9a-z][0-9a-z-]+\.)+[a-z]{2,3}$/));
console.log(sv.is('1234567',/\d+/));
console.log(sv.is('11aa',/^\d/$));
}
    

console.log(sv.isArray([]))
console.log(sv.isArray(123))

console.log(sv.isRegExp(/\d/))
console.log(sv.isRegExp(123))

console.log(sv.isNumber(123))
console.log(sv.isNumber('abc'))

console.log(sv.isPositive(122.2))
console.log(sv.isPositive(-1))

console.log(sv.isInt(123))
console.log(sv.isInt(123.2))


console.log(sv.notEmpty("aa"))
console.log(sv.notEmpty(""))


console.log(sv.isDate(new Date()))
console.log(sv.isDate(12321312))

console.log(sv.isString('abc'))
console.log(sv.isString(123))

console.log(sv.isLowercase('abc'))
console.log(sv.isLowercase('a123A1'))

console.log(sv.isUppercase('ABC'))
console.log(sv.isUppercase('a123A1'))


console.log(sv.isIn('ABC','ABCDEFG'))
console.log(sv.isIn('AAA','ABCDEFT'))
console.log(sv.isIn(123,'123456789'))
console.log(sv.isIn(123,'ABCDEFT'))


console.log(sv.isIn('ABC',['ABCDEFG','123','234','ABC']))
console.log(sv.isIn('AAA',['ABCDEFG','123','234','abc']))
console.log(sv.isIn(234,['ABCDEFG','123','234','abc']))
console.log(sv.isIn(123,['ABCDEFG','567','234','abc']))


console.log(sv.isLen('ABC',1,5))
console.log(sv.isLen('aaaaaaaa',1,5))
console.log(sv.isLen(5,1,5))
console.log(sv.isLen(6,1,5))
console.log(sv.isLen([1,2,3],1,5))
console.log(sv.isLen([],1,5))




console.log(sv.isEmail('sfsd@@@fsfas.com'));
console.log(sv.isEmail('sfsd@fsfas.com'));
console.log(sv.isEmail('snoopyxdy@sina.com'));


console.log(sv.isIp('12.12.12.10'));
console.log(sv.isIp('10.10.20.30.50'));

console.log(sv.isUrl('http://bbs.csdn.net/topics/270080323/'));
console.log(sv.isUrl('10.10.20.30'));

