
var sv = require('../index.js');
var eq = require('assert').strictEqual;
var op = require('os').platform();
var sanitize = require('validator').sanitize;
var nv = require('validator').check;







var n=10000;
console.time('nodejs')
while(n--){

sanitize('').trim()
sanitize('   aaa    ').trim()
sanitize('  aa aa  ').trim()




}
console.timeEnd('nodejs')





var n=10000;
console.time('c++')
while(n--){


sv.trim('')
sv.trim('   aaa    ')
sv.trim('  aa aa  ')

}
console.timeEnd('c++')






