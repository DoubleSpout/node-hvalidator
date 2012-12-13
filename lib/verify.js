var verify = require('../build/Release/verify.node');


//isxxx
verify.is = function(str, pattern, modifiers) {
	str += '';
	if (Object.prototype.toString.call(pattern).slice(8, -1) !== 'RegExp') {
		pattern = new RegExp(pattern, modifiers);
	}
	return pattern.test(str);
}

//filter
verify.ifNull = function(str, replace) {
	return str ? str : replace;
}

verify.toFloat = function(num,dnum) {
	if(isNaN(num)) return dnum?dnum:0;
	return num;
	
}

verify.toInt = function(num,dnum) {
	if(isNaN(num)) return dnum?dnum:0;
	return parseInt(num,10);
}

verify.toBoolean = function(bl){
	return !!bl;
}

module.exports = verify;