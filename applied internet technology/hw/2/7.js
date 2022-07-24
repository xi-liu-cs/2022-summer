import fs from 'fs'

function read_extract(extractor)
{
	return function(file_name, success_fn, err_fn)
	{
		fs.readFile(file_name, 'utf-8', (err, data) =>
		{
			if(!err)
			{
				data = extractor(data);
				success_fn(data);
			}
			else
				err_fn(err);
		});
	}
}

const getWords = (s) => s.trim().split('\n').reduce((words, line) => [...words, ...line.split(' ')], []);
const f = read_extract(getWords);

const success = (data) => console.log(data); 
const failure = (err) => console.log('Error opening file:', err);

/* assuming the contents of the file, tests/words.txt is:
 ant bat
 cat dog emu
 fox */

f('tests/words.txt', success, failure); 
/* output is: ['ant', 'bat', 'cat', 'dog',  'emu', 'fox'] */
