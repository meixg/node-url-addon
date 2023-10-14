var addon = require('bindings')('url');

const URL = addon.URL;

const url = new URL('https://www.google.com/search?q=hello+world&oq=hello+world&aqs=chrome..69i57j0l5.1771j0j7&sourceid=chrome&ie=UTF-8');

console.log(url.hostname);
url.hostname = 'm.baidu.com';
console.log(url.hostname);