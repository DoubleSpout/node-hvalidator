var sv = require('../index.js');
var eq = require('assert').strictEqual;
var op = require('os').platform();
var nv = require('validator').check;







var n=1000;
console.time('nodejs')
while(n--){

nv('sfsd@fsfas.com').isEmail()


nv('http://bbs.csdn.net/topics/270080323/').isUrl()


nv('10.10.10.10').isIP()


}
console.timeEnd('nodejs')





var n=1000;
console.time('c++')
while(n--){
sv.isEmail('sfsd@fsfas.com')
//sv.isEmail('sfsd@@@fsfas.com')


sv.isUrl('http://bbs.csdn.net/topics/270080323/')
//sv.isUrl('fasfdfdas')


sv.isIp('10.10.10.10')
//sv.isIp('12.12.12.10.10')

}
console.timeEnd('c++')