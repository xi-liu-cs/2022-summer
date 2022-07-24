/* betterCallFn(fn, n, arg1, ..., argn)
fn - the function to be called repeatedly
n - the number of times to call function, fn
arg1, ..., argn - all of the arguments to pass in to the function fn when it is called */

function better_call_fn(fn, n, ...argv)
{
	if(n <= 0) return;
	fn(...argv);
	--n;
	better_call_fn(fn, n, ...argv);
}

function f(...argv)
{
	sum = 0;
	sum = argv.reduce((pre, cur) => pre + cur, sum);
	console.log(sum);
}

n = 3;
better_call_fn(f, n, 1, 2, 3);
