const a1 = require('./a1');
const prompt = require('prompt');

console.log('Enter a number: ');

prompt.start();

prompt.get('height', (err, res) => {
  console.log(a1(res.height));
});
