// assignment1.test.cpp

//what do i do lol


int main() {
	TEST_METHOD(TestClassInit)
	{
		std::string name = "Bill";
		MyClass mc(name);
		Assert::AreEqual(name, mc.GetName());
	} 
}
