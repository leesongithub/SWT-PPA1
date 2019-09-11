const a1_1 = require('./a1_1');
const prompt = require('prompt');

console.log('Enter height (inches) and weight (pounds) for BMI:');

prompt.start();

prompt.get('height', (err, res) => {
  console.log(a1_1(res.height));
});
