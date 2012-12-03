var hv = require('../index.js');
var nv = require('validator').check;







console.time('nodejs')


	nv('aaaa11@aaaa.com').is(/[_\.0-9a-z-]+@([0-9a-z][0-9a-z-]+\.)+[a-z]{2,3}$/)

    nv('123').isNumeric()

	nv(122.2).isFloat()
	
	nv('123').isInt()

	nv('aa').notEmpty()

	nv(new Date()).isDate()

	nv('abc').isAlpha()

	nv('abc').isLowercase()

	nv('ABC').isUppercase()

	nv('ABC').isIn('ABCDEFG')

	nv('123').isIn('123456789')

	nv('ABC').isIn(['ABCDEFG','123','234','ABC'])

	nv('234').isIn(['ABCDEFG','123','234','abc'])


	nv('sfsd@fsfas.com').isEmail()

	nv('http://bbs.csdn.net/topics/270080323/').isUrl()

	nv('10.10.10.10').isIP()

	console.timeEnd('nodejs')





console.time('c++')

	hv.is('aaaa11@aaaa.com',/[_\.0-9a-z-]+@([0-9a-z][0-9a-z-]+\.)+[a-z]{2,3}$/)

	hv.isArray([])

	hv.isRegExp(/\d/)

	hv.isNumber(123)

	hv.isPositive(122.2)
	
	hv.isInt(123)

	hv.notEmpty("aa")

	hv.isDate(new Date())

	hv.isString('abc')

	hv.isLowercase('abc')

	hv.isUppercase('ABC')

	hv.isIn('ABC','ABCDEFG')

	hv.isIn(123,'123456789')

	hv.isIn('ABC',['ABCDEFG','123','234','ABC'])

	hv.isIn(234,['ABCDEFG','123','234','abc'])

	hv.isLen('ABC',1,5)

	hv.isLen(5,1,5)

	hv.isLen([1,2,3],1,5)

	hv.isEmail('sfsd@fsfas.com')

	hv.isUrl('http://bbs.csdn.net/topics/270080323/')

	hv.isIp('10.10.10.10')


console.timeEnd('c++')



