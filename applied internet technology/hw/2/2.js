/* call_fn(fn, n, arg)
fn - the function to be called repeatedly
n - the number of times to call function, fn
arg - the argument to pass to function, fn, when it is called */

function call_fn(fn, n, arg)
{
	if(n <= 0) return;
	fn(arg);
	--n;
	call_fn(fn, n, arg);
}

function f(s)
{
	console.log(s);
}

call_fn(f, 3, "a");
