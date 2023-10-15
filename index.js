var addon = require('bindings')('url');

const URL = addon.URL;

const url = new URL('https://www.google.com/search?q=hello+world&oq=hello+world&aqs=chrome..69i57j0l5.1771j0j7&sourceid=chrome&ie=UTF-8#test');

console.log(url.hostname);
url.hostname = 'm.baidu.com';
console.log(url.hostname);
// console.log(JSON.stringify(url));
// console.log(url.searchParams);
console.log(url.searchParams.toString());
console.log(url.searchParams.append('meixg', '123'));
console.log(url.searchParams.toString());

// console.log(url.searchParams);