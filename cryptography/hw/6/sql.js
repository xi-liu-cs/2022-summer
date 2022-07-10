var sqlite3 = require('sqlite3');
db = new sqlite3.Database('./msgdb');
db.each('select * from tb1',
	(err, row) => 
	{
		console.log(`${row.one}`);
	});
