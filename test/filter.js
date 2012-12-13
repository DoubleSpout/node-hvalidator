
var sv = require('../index.js');
var eq = require('assert').strictEqual;
var op = require('os').platform();



eq(sv.trim(''),'');
eq(sv.trim('   aaa    '),'aaa');
eq(sv.trim('  aa aa  '),'aa aa');


eq(sv.ltrim(''),'');
eq(sv.ltrim('   aaa    '),'aaa    ');
eq(sv.ltrim('  aa aa  '),'aa aa  ');


eq(sv.rtrim(''),'');
eq(sv.rtrim('   aaa    '),'   aaa');
eq(sv.rtrim('  aa aa  '),'  aa aa');




eq(sv.trim('bbbbaaabbbb',"b"),'aaa');
eq(sv.trim('bbbbaa aabbb',"b"),'aa aa');



eq(sv.ltrim('bbbbaaabbbb',"b"),'aaabbbb');
eq(sv.ltrim('bbbbaa aabbb',"b"),'aa aabbb');



eq(sv.rtrim('bbbbbaaabbbb',"b"),'bbbbbaaa');
eq(sv.rtrim('bbbbaa aabbbb',"b"),'bbbbaa aa');



eq(sv.toXss('<a href="http" id=\'\'>&</a>'),'&lt;a href=&quot;http&quot; id=&#146;&#146;&gt;&amp;&lt;/a&gt;');


console.log('test done')