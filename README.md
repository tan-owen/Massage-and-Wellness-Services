**1. Customer Functionalities Description**
   
	i. View Beauty Centre Information
	• Displays general information about the beauty service provider.

	• May include:
		o Company name and logo.
		o Business vision and mission.
		o Operating hours and contact details.
		o Available categories of services.

	ii. View Services and Experts
	• Customers can explore the services offered and view expert profiles.

	• Each group must define at least 3 distinct services (e.g., Facial, Hair Spa,
	Massage).

	• Up to 3 experts should be shown, including:
		o Expert name
		o Specializations
		o Working hours (Monday–Friday only)
		o Service availability

	iii. Check Appointment Availability (December Only)
	• Customers can view available time slots for the month of December only.

	• Slots are organized by week (Week 1 to Week 4).

	• Each day includes a set of available time slots.

	• A time slot is shown as:
		o Available: [ ]
		o Booked: [X]
	
	iv. Book Appointments
	• Customers can proceed to booking only if a slot is available.

	• Steps:
		o Select preferred service
		o Select expert
		o Choose an available time slot
		o Enter personal details
		o Confirm booking
	
	• If selected slot is fully booked, the system will prevent the booking and prompt to
	choose another slot.
	v. Make Payment
	• Displays total cost = Service price + Service charge
	
		o E.g., RM500 (treatment) + RM100 (service charge) = RM600	
	
	• System will prompt for payment amount.

	• Booking is only confirmed upon successful payment.

	vi. View My Bookings
	• Customers can view their current and past bookings.

	• Information includes:
		o Service name
		o Expert assigned
		o Date and time
		o Payment amount and status

**3. Admin Functionalities – Beauty Service Booking Application**

	The admin (Owner of the Beauty Centre) must log in to the system to manage and monitor
	the business operations. The admin has access to the following features:
	i. View Individual Expert Schedule
	• View schedules of any selected expert.

	• Weekly and daily breakdown of working hours and service sessions.

	i. View Overall Schedule
	• See a combined schedule of all experts.

	• Useful for tracking slot availability and workload distribution.

	ii. View Customer List
	• Access the full list of customers.

	• View customer details such as booking info, payment status, assigned expert,
	and service type.
	
	iii. Generate Sales Reports
	• View total sales by date range, service category, or expert.

	• Includes breakdown of service types: consultations, treatments, and packages.

	iv. View Expert Bonus Entitlements
	• Admins can view bonus entitlement details for each expert based on their
	performance in a selected month.

	• Display includes:
		o Expert’s name
		o Total treatment hours
		o Total consultation hours
		o Total combined hours
		o Total value of services completed (in RM)
		o Bonus rate (based on hour threshold)
		o Bonus amount earned (RM)

	• Bonus Rules Recap:
		o ≥ 30 hours → 50% of total service charges
		o 25 to <30 hours → 25% bonus
		o <25 hours → No bonus

**5. Expert Functionalities – Beauty Service Booking Application**

	Each Expert (employee providing treatments and consultations) must log in to the system
	to access their personalized dashboard. The following functionalities are available only to
	the logged-in expert:
	i. View Individual Schedule
	• View daily and weekly appointments.

	• Display only assigned customers and sessions (treatment/consultation).

	• Show available and booked slots clearly.
	
	• Experts work Monday–Friday and daily work limit: 6 hours max
	(treatments: 3 hrs/session, consultations: 1 hr/session). Weekly work limit
	30 hours per expert.
   
	• Once limits are reached, expert slots become unavailable, and the booking
	system should disable further bookings for that expert.

	ii. View Assigned Customer List
	• View a list of customers booked under this expert only.

	• Display customer name, service type, date/time, and duration.

	iii. View Earnings Bonus Entitlement
	• Experts are entitled to a performance-based bonus depending on the
	number of hours worked in a month and the total value of services
	completed.
	Bonus Rules:
	• If total hours ≥ 30 hours → Bonus = 50% of total service charges

	• If 25 ≤ hours < 30 → Bonus = 25% of total service charges

	• If hours < 25 → No bonus

	System should display:
	• Total treatment hours completed

	• Total consultation hours completed

	• Total combined hours

	• Total value of services completed (treatment + consultation)

	• Bonus percentage

	• Bonus amount earned


**MUST ONLY USE THESE FUNCTIONS**
I. Core C++ Functions
These are fundamental functions in C++ programming:
• main(): This is the starting point of every C++ program
. It serves as the primary function where program execution begins
.
• return 0;: This statement is typically used at the end of the main() function to indicate successful program termination
.
II. Standard Library Functions
These are predefined functions available in C++ through various header files.
A. Input/Output Functions and Manipulators (from <iostream> and <iomanip>)
• cin: Stands for common input, used to receive data from the keyboard
. It works with the extraction operator >>
.
• cout: Stands for common output, used to send output to the screen for display
. It works with the insertion operator <<
.
• cin.get(varChar): Inputs the next character, including blank spaces
.
• cin.ignore(num, char): Discards a portion of the input, ignoring a specified number of characters or until a particular character is encountered
.
• endl: A manipulator that starts a new line of output
.
• setw(n): (from <iomanip>) Sets the width for output to n columns, right-justifying the output by default and filling unused columns with spaces
.
• setfill(ch): (from <iomanip>) Used to fill unused columns with a specified character ch instead of a space
.
• setprecision(n): (from <iomanip>)
    ◦ Displays floating-point values up to n significant digits
.
    ◦ When used with fixed manipulator, it displays floating-point values up to n decimal places
.
• fixed: (from <iomanip>) A manipulator that forces floating-point output to display in fixed-point notation, showing a specific number of decimal places when combined with setprecision()
.
• showpoint: (from <iomanip>) Causes a decimal point and trailing zeros to be displayed, even if there is no fractional part
.
• left: (from <iomanip>) A manipulator used to left-justify the output
.
• right: (from <iomanip>) A manipulator used to right-justify the output (default behavior)
.
• unsetf(ios::fixed): Used to disable the fixed manipulator
.
• unsetf(ios::left): Used to disable the left manipulator
.
• showpos: Prints a + sign for positive numbers
.
• noshowpoint: Drops the decimal point and trailing zeros
.
• noshowpos: Does not print a + sign for positive numbers
.
• scientific: Outputs floating-point numbers as scientific notation
.
• dec: Displays subsequent numbers in decimal format
.
• hex: Inputs or outputs numbers in hexadecimal format
.
• oct: Inputs or outputs numbers in octal format
.
B. Mathematical Functions (mostly from <cmath>, some from <cstdlib>)
• abs(x): Returns the absolute value of an integer argument
.
• fabs(x): Returns the absolute value of a floating-point argument
.
• pow(x,y): Returns the value of x raised to the power of y (x^y)
.
• sqrt(x): Returns the square root of the argument
.
• ceil(x): Returns the next higher integer in double
.
• floor(x): Returns the next lower integer in double
.
• sin(x): Returns the sine of the argument (angle in radians)
.
• asin(x): Returns the arcsine of the argument in radians
.
• fmod(x,y): Returns the remainder of x divided by y (both doubles)
.
• exp(x): Returns the exponential function of the argument
.
• log(x): Returns the natural logarithm (base-e) of the argument
.
• log10(x): Returns the base-10 logarithm of the argument
.
C. Random Functions (from <cstdlib> and <ctime>)
• srand(): Seeds the random number generator to produce a different series of pseudorandom numbers each time
. It should be called only once
.
• time(NULL) / time(0): (from <ctime>) Returns the current time in seconds, often used as a seed for srand() to ensure varying random number sequences
.
• rand(): Returns a pseudorandom integer between 0 and RAND_MAX
.
D. Character Functions (from <cctype>)
• isalpha(ch): Returns true (non-zero) if ch is a letter; otherwise, false (zero)
.
• isdigit(ch): Returns true if ch is a digit; otherwise, false
.
• isalnum(ch): Returns true if ch is an alphanumeric character (letter or digit); otherwise, false
.
• isspace(ch): Returns true if ch is a whitespace character (\n, , \t); otherwise, false
.
• islower(ch): Returns true if ch is a lowercase letter; otherwise, false
.
• isupper(ch): Returns true if ch is an uppercase letter; otherwise, false
.
• toupper(ch): Converts ch to its uppercase equivalent
.
• tolower(ch): Converts ch to its lowercase equivalent
.
E. String Class Functions (from <string>)
• str.length() / str.size(): Returns the length of the string str, including spaces
.
• str.empty(): Returns true if the string str is empty; otherwise, false
.
• String comparison operators (==, !=, <, >): Used to compare strings lexicographically
.
• s1.at(i): Prints character by character from string
.
• s1.find("Wong") / s1.find('g'): Finds the position of a substring or character within a string
.
• s1.insert(pos, str): Inserts a string at a specified position
.
• s1.replace(start, num_char, "replace string"): Replaces a specified number of characters within a string with another string
.
• s1.append(num_char, 'character') / s1.append(", Dr."): Appends characters or another string to the end of a string
.
• s1.erase(start_position, num_characters): Removes characters from a string starting at a given position
.
F. C-String Functions (from <cstdlib> and <cstring>)
• Conversion Functions (from <cstdlib>):
    ◦ atof(string): Converts a numeric string to a double
.
    ◦ atoi(string): Converts a numeric string to an integer
.
    ◦ atol(string): Converts a numeric string to a long integer
.
• Manipulation Functions (from <cstring>):
    ◦ strcpy(s1,s2): Copies string s2 to string s1
.
    ◦ strncpy(s1,s2,n): Copies up to n characters from s2 to s1
.
    ◦ strcat(s1,s2): Appends string s2 to string s1
.
    ◦ strncat(s1,s2,n): Appends up to n characters from s2 to s1
.
• Comparison Functions (from <cstring>):
    ◦ strcmp(s1,s2): Compares string s1 to string s2
. Returns 0 if equal, >0 if s1 > s2, <0 if s1 < s2
.
    ◦ strncmp(s1,s2,n): Compares up to n characters of s1 to s2
.
• Length Function (from <cstring>):
    ◦ strlen(s1): Determines the length of string s1
.
• Locate Characters in String Function (from <cstring>):
    ◦ strpbrk(string1, string2): Locates the first occurrence of any character from string2 in string1
.
G. File I/O Functions (from <fstream>)
• fileStreamVariable.open(source, mode): Opens a file. For input files, the file must exist. For output files, a new file will be created, or an existing one erased
.
• fileStreamVariable.close(): Closes a file, ensuring all buffered data is written and releasing system resources
.
• fileStreamVariable.fail(): Checks if a file opening error occurred
.
• fileStreamVariable.eof(): Checks if the end-of-file is reached during reading. It returns true when the read operation encounters the end of the file
.
III. User-Defined Function Concepts
The sources extensively discuss the creation and usage of custom functions:
• Function Declaration / Prototype: Specifies the function's return type, name, and parameter list. It tells the compiler about the function before its definition
.
• Function Definition: Contains the actual code to perform a task. It consists of a function header and a function body
.
    ◦ Function Header: May receive data through its argument list/parameters
.
    ◦ Function Body: Performs specific actions
.
    ◦ Return Statement: May return a function value to the calling module
.
• Void Functions: Functions that do not return a function value (e.g., void Print_result(int ans))
.
• Value-returning Functions: Functions that return a function value to the calling module using a return statement (e.g., int sum_num(int x1, int x2))
.
• Function Call: Invoking a function by its name, passing arguments if defined
.
• Variable Scope: Discusses local variables (declared within a function, not accessible by others) and global variables (declared outside functions, accessible to all)
.
• Functions with Parameters: Describes how data is passed to functions:
    ◦ Pass by Value: A copy of the data is created; changes in the called function do not affect the original data
.
    ◦ Pass by Reference (&): Links the variable in the calling function to the parameter in the called function; changes in the called function affect the original variable
.
    ◦ Pass by Address (*): Uses pointers to pass the memory address of a variable; dereferencing the pointer (*) allows modification of the original data
.
• Function Overloading: Allows several functions to have the same name but different parameter lists (either different number of parameters or same number but different types/order)
. The compiler determines which function to execute based on the parameter types
.
• Function Returns an Array: A function cannot directly return an entire array. Instead, it can return a pointer to an array
.
IV. Examples of User-Defined Functions and their applications
The sources provide several illustrative examples of user-defined functions:
• header(): A simple void function that prints "Function"
.
• Print_result(int ans): A void function that prints the given integer answer
.
• sum_num(int x1, int x2): A value-returning function that calculates and returns the sum of two integers
.
• multiply(double num): A value-returning function that doubles a given number
.
• get_response(bool F): A value-returning function that returns a string based on a boolean flag
.
• print_res(string Result): A void function that prints a given string
.
• calculate(int x): An example function demonstrating local and global variable scope
.
• fun(int x): An example illustrating pass by value
.
• fun(int &x): An example illustrating pass by reference
.
• fun(int *x): An example illustrating pass by address
.
• exchange(int &num1, int &num2): A function demonstrating swapping two variables using pass by reference
.
• exchange(int *num1, int *num2): A function demonstrating swapping two variables using pass by address
.
• divide(int a, int b) and divide(float a, float b): Examples of function overloading with different parameter types
.
• swap(char &x, char &y), swap(int &x, int &y), swap(float &x, float &y): Further examples of function overloading for different data types
.
• displayMenu(): A void function designed to display menu options to the user
.
• Addition(), Subtraction(), Multiplication(), Division(): Placeholder functions mentioned in the context of a single-level menu application
.
• findLargest(int, int): Finds the largest of two individual integer elements passed from an array
.
• findLargest(int []): Finds the largest value in an entire array passed to the function
.
• multiply2(int x[], int size): A void function that modifies the elements of an array passed by reference (implicitly, as arrays are passed as pointers)
.
• fun1(char x[]) and fun2(char y[]): Examples of passing C-strings to functions
.
• display(int x
): An example of passing a 2D array to a function
.
• getRandom(): A function that returns a pointer to a static integer array, demonstrating how to return an array from a function
.
• stringToDay(string d): A function that converts a string to an enumeration type Weekday
.
• getMood(int m): A function that returns an enumeration type Mood based on an integer input
.
• update(): Used in examples for passing whole structures by value, reference, or address
.
• askRecord(): A function that demonstrates returning an entire structure
.
