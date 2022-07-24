import fs from 'fs'; /* es module scope, in package.json, {"type": "module"} 
let fs = require('fs'); "type" not set */

function my_read_file(file_name, success_fn, error_fn)
{
    fs.readFile(file_name, 'utf-8', (err, data) => {
        if(!err)
            success_fn(data);
        else
            error_fn(err);
    });
}

function success_fn()
{
    console.log("success_fn");
}

function error_fn()
{
    console.log("error_fn");
}

my_read_file('0.txt', success_fn, error_fn);
my_read_file('1.txt', success_fn, error_fn);
