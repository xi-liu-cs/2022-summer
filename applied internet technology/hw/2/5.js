function add_permissions(old_fn)
{                                                                        
    return function(obj, num, base) 
    {
        if(obj && obj.admin)
            return old_fn(num, base);
        else
            return undefined;
    }    
}                                                                     
const myParseInt = add_permissions(parseInt);                             
console.log(myParseInt(null, '101', 2));
console.log(myParseInt({admin: false}, '101', 2));
console.log(myParseInt({admin: true}, '101', 2));
