/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let res=[];
    arr.forEach((item,index)=>{
        res.push(fn(item,index));
    })
    return res;
};