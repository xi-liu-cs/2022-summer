/* bucket(ary, fn)
ary - an array
fn - a function that returns true or false
fn has one argument, a value to test
returns:
an array containing two arrays:
one with all elements that passed the test, fn
the other with all elements that did not pass the test, fn */

function bucket(ary, fn)
{
	return ary.reduce
	(
		(ret, cur) =>
		{
			fn(cur) ? ret[0].push(cur) : ret[1].push(cur);
			return ret;
		}, [[], []]
	);
}

num = [1, 2, 3, 4, 5, 6];
[evens, odds] = bucket(num, n => n % 2 == 0);
console.log("evens", evens, "| odds", odds);	
