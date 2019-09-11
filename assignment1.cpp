// Software Testing TDD Assignment 1

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <vector>
#include <stdlib.h>
#include <math.h>

// custom data struct for returning double and a string from GetBMI function
struct BMI_vector {
	double BMI_value;
	std::string BMI_category;
};

BMI_vector GetBMI(int height_inches, int weight_pounds) {
	
	// convert height_inches to metric
	double metric_height = height_inches * 0.025;
	
	// convert weight_pounds to metric
	double metric_weight = weight_pounds * 0.45;
	
	// calculate BMI
	double BMI_value = metric_weight / (metric_height * metric_height);
	
	// categorize BMI value
	std::string BMI_category;
	if (BMI_value < 18.5) {
		BMI_category = "Underweight";
	} else if ((18.5 <= BMI_value) && (BMI_value <= 24.9)) {
		BMI_category = "Normal weight";
	} else if ((25 <= BMI_value) && (BMI_value <= 29.9)) {
		BMI_category = "Overweight";
	} else if (BMI_value > 29.9) {
		BMI_category = "Obese";
	}

	// debugging output
	std::cout << "For height " << height_inches << " inches and weight " << weight_pounds << " pounds:\n";
	std::cout << "BMI is: " << BMI_value << " | " << BMI_category << std::endl;
	
	std::cout << "\n- - - - - - - - - -\n\n";
	
	// put data into custom struct and return
	BMI_vector result = {BMI_value, BMI_category};
	return result;
}

int GetRetirementAge(int current_age, double annual_salary, double percentage_saved, double savings_goal) {
	// percentage_saved enters as a whole number (e.g., 20 means 20%, or 0.20)
	
	// assume savings account starts at $0
	double savings_account = 0.00;
	
	// start retirement age at current age
	int retirement_age = current_age;
	
	do {
		
		// for every year, add percentage saved of annual salary to savings account
		double yearly_addition = annual_salary * (percentage_saved / 100);
		savings_account += yearly_addition;
		
		// additionally, add another 35% of that yearly addition to the savings account
		double employer_match = yearly_addition * 0.35;
		savings_account += employer_match;
		
		// increase retirement age by one
		retirement_age++;
	
		// if age reaches 100 or more, break. You died.
		if (retirement_age >= 100) {
			std::cout << "Age reached 100 years old. You died before retiring.\n";
			return 100;
		}
		
		// debugging output:
		// std::cout << retirement_age << " | savings: " << savings_account << " | yearly +: " << yearly_addition << std::endl;
	
	// loop while savings account < savings goal
	} while (savings_account < savings_goal);

	// debugging output
	std::cout << "Assuming you save " << percentage_saved << "% of $" << annual_salary << " every year.\n";
	std::cout << "If you want to have " << savings_goal << " saved by the time you retire,\n";
	std::cout << "You will retire at age: " << retirement_age << std::endl;
	
	std::cout << "\n- - - - - - - - - -\n\n";
	
	return retirement_age;
}

double GetShortestDistance(int x1, int y1, int x2, int y2) {
	
	// determine horizontal distance from x1 to x2
	double horizontal_distance = abs(x1 - x2);
	
	// determine vertical distance from y1 to y2
	double vertical_distance = abs(y1 - y2);
	
	// apply Pythagorean formula
	double shortest_distance = pow( (pow(horizontal_distance, 2) + pow(vertical_distance, 2)), 0.5 );
	
	std::cout << "For coordinates (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ")\n";
	std::cout << "Horizontal dist. = " << horizontal_distance << " and vertical dist. = " << vertical_distance << std::endl;
	std::cout << "Shortest distance = " << shortest_distance << std::endl;
	
	std::cout << "\n- - - - - - - - - -\n\n";
	
	// return
	return shortest_distance;
}

std::vector<double> SplitTip(double bill, int num_guests) {
	
	// add 15% gratuity to total
	double total = bill + (bill * 0.15);
	
	// divide total by number of guests
	double guest_bill = total / num_guests;
	
	// round down to two decimal places (cents)
	guest_bill = floorf(guest_bill * 100) / 100;
	
	// put all guest bills into vector
	std::vector<double> bills;
	for (int i = 0; i < num_guests; i++) {
		bills.push_back(guest_bill);
	}
	
	// if all guest bills don't sum to total, add correct cents to guest 1's bill
	double check_total = guest_bill * num_guests;
	//std::cout << "check total = " << check_total << std::endl;
	if (check_total <= total) {
		double cents_added = ceil((total - check_total) * 100);
		//std::cout << "cents added = " << cents_added << std::endl;
		for (int j = 0; j < cents_added; j++) {
			bills[j] = bills[j] + 0.01;
		}
	}
	
	// debugging output (print vector)
	for (int k = 0; k < num_guests; k++) {
		std::cout << "Guest " << k+1 << " pays $" << bills[k] << std::endl;
	}
	std::cout << "Total bill (including 15% tip): $";
	printf("%.2f", total);
	
	std::cout << "\n\n- - - - - - - - - -\n\n";
	
	// return vector
	return bills;
}

int menu() {
	
	// display list of options
	std::cout << "\n\nMENU:\n"
			  << "[1] Calculate BMI\n"
			  << "[2] Calculate retirement age\n"
			  << "[3] Calculate shortest distance\n"
			  << "[4] Split a tip\n"
			  << "[5] Exit program\n";
	std::cout << "Enter a choice (1-5):\n> ";
	
	int choice;
	std::cin >> choice;
	
	if ((isdigit(choice) == 0) || (choice < 1) || (choice > 5)) {
		// user enters a non-integer or out of the 1-5 range
		std::cin.clear();
		std::cin.ignore();
	}
	
	return choice;
}

int GetInt(int lower_bound, int upper_bound){
	int val;
	std::cin >> val;
	
	if (isdigit(val) == 0) {
		std::cin.clear();
		std::cin.ignore();
	}
	
	if ( (val < lower_bound) || (val > upper_bound) ) {
		std::cout << "That value is out of range.\n";
		std::cin.clear();
		std::cin.ignore();
	}
	
	return val;
}

double GetDouble(double lower_bound, double upper_bound){
	double val;
	std::cin >> val;
	
	if (isdigit(val) == 0) {
		std::cin.clear();
		std::cin.ignore();
	}
	
	if ( (val < lower_bound) || (val > upper_bound) ) {
		std::cout << "That value is out of range.\n";
		std::cin.clear();
		std::cin.ignore();
	}
	
	return val;
}

int main() {

	int choice = 0;
	
	while (choice != 5) {
		
		choice = menu();
		
		if (choice == 1) {
			// calculate BMI
			std::cout << "Enter height in INCHES.\n> ";
			int height_inches = GetInt(0, 108);
			std::cout << "Enter weight in POUNDS.\n> ";
			int weight_pounds = GetInt(0, 1400);
			GetBMI(height_inches, weight_pounds);
		} else if (choice == 2) {
			// calculate retirement age
			std::cout << "Enter current age in YEARS.\n> ";
			int current_age = GetInt(0, 100);
			std::cout << "Enter annual salary in 0.00 FORMAT.\n> ";
			double annual_salary = GetDouble(0, 9999999999);
			std::cout << "Enter percentage saved as a WHOLE NUMBER (e.g., enter 10 for 10%).\n> ";
			double percentage_saved = GetDouble(0, 100);
			std::cout << "Enter savings goal in 0.00 FORMAT.\n> ";
			double savings_goal = GetDouble(0.00, 9999999999);
			GetRetirementAge(current_age, annual_salary, percentage_saved, savings_goal);
		} else if (choice == 3) {
			// calculate shortest distance
			std::cout << "Enter x1 coordinate as an INTEGER.\n> ";
			int x1 = GetInt(-999999999, 999999999);
			std::cout << "Enter y1 coordinate as an INTEGER.\n> ";
			int y1 = GetInt(-999999999, 999999999);
			std::cout << "Enter x2 coordinate as an INTEGER.\n> ";
			int x2 = GetInt(-999999999, 999999999);
			std::cout << "Enter y2 coordinate as an INTEGER.\n> ";
			int y2 = GetInt(-999999999, 999999999);
			GetShortestDistance(x1, y1, x2, y2);
		} else if (choice == 4) {
			// split tip
			std::cout << "Enter the bill in 0.00 FORMAT.\n> ";
			double bill = GetDouble(0.00, 9999999999);
			std::cout << "Enter the number of guests as an INTEGER.\n> ";
			int num_guests = GetInt(0, 999999999);
			SplitTip(bill, num_guests);
		} else if (choice == 5) {
			// exit program
			std::cout << "Exiting... \n";
			return 0;
		} else {
			// default
			std::cout << "\n!!! INVALID INPUT !!!\n";
		}
		//sleep(1); // one second pause
	}
	
	return 0;
}



