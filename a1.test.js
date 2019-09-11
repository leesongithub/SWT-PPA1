const a1 = require('./a1');
const a1_1 = require('./a1_1');

describe('Assignment 1 returns the appropriate outputs for given inputs', function() {
  
  it('should add 100', () => {
	  expect(a1('80')).toBe(180);
  });
  
  it('should double the value entered', () => {
	  expect(a1_1('80')).toBe(160);
  });
  
});

test('jest framework runs correctly', () => {
  expect(true).toBeTruthy();
});



