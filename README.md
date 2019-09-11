# Assignment 1

To run the code you need Nodejs and yarn or npm installed globally.
Run either `yarn` or `npm install` 

Run `node a1index.js` to run the app

Run `yarn run test` or `npm run test` to execute tests

NOTE

So I wrote the app (as in, the BMI / Tip / Distance / Retirement age calculator) in C++.
However, I was having problems with writing unit tests for C++ (in Boost.Test). Boost would 
not run correctly, and I did not know how to write unit tests that navigated the multiple
inputs for our command line app (e.g. selecting the menu item, then entering four numbers).
This is mainly because the demo only demonstrated single-input unit tests for Javascript. 

Because the in-class demo only showed us how to write unit tests for Javascript / Jest 
with single inputs and outputs, I decided to write unit tests in Jest since that was 
what we were taught. 

However, lacking a Javascript app, I just wrote a few simple functions in Javascript, and
correspondingly simple tests in Jest, so that the grader knows that I understand the TDD
process and how to write JS unit tests-- I just didn't have the ability to rewrite the 
app in JS, or write C++ Boost unit tests.

So the first screen recording demonstrates my C++ app's functionality. This file is assignment1.cpp

But the unit tests fall under a1.test.js which tests a1index.js and a1_1index.js
As the PDF spec states, the "Objective is to show process conformance".
My screen recording of a1.test.js and associated code demonstrates that I have conformed
to the TDD process of 
1. RED (write test that fails)
2. GREEN (write code so test passes)
3. REFACTOR (integrate)

Additionally, 'assignment1.cpp' demonstrates that I was able to write the app in C++. 

Thanks,

Leeson
