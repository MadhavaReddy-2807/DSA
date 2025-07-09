/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let res=[];
    arr.forEach((item,index)=>{
        if(fn(item,index))
        {
            res.push(item);
        }
    })
    return res;
};