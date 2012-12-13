var sv = require('../index.js');
var eq = require('assert').strictEqual;
var op = require('os').platform();
var nv = require('validator').check;


var t='<body><div id="{$userid}">{$username}</div><div id="userid">{$usersex}</div></body></html>';

var i=2;
var tpl='';
while(i--){
	tpl += t;
}


function toxss(text){
	text = text.replace(/&/g, "&amp;");
	text = text.replace(/"/g, "&quot;");
	text = text.replace(/</g, "&lt;");
	text = text.replace(/>/g, "&gt;");
	text = text.replace(/'/g, "&#146;");
	return  text;
}



var n=10000;
console.time('nodejs');
while(n--){
	var s = tpl+n;
	s = toxss(s);
}
console.timeEnd('nodejs')
var nodes = s;




var n=10000;
var toXss = sv.toXss;

console.time('c++')
while(n--){
	var s = tpl+n;
	s = toXss(s)
}
console.timeEnd('c++')
var cs = s;

eq(nodes,cs)