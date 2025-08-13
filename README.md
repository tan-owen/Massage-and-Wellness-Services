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
# C++ Core & Standard Library Functions

## I. Core C++ Functions
These are fundamental functions in C++ programming:

- **`main()`**: The starting point of every C++ program. Execution begins here.
- **`return 0;`**: Indicates successful program termination (typically at the end of `main()`).

---

## II. Standard Library Functions
Predefined functions available in C++ through various header files.

### A. Input/Output Functions & Manipulators (`<iostream>`, `<iomanip>`)
- **`cin`**: Reads input from the keyboard (`>>` operator).
- **`cout`**: Outputs data to the screen (`<<` operator).
- **`cin.get(varChar)`**: Reads the next character, including spaces.
- **`cin.ignore(num, char)`**: Ignores input until `num` characters or a specified character is reached.
- **`endl`**: Inserts a newline.
- **`setw(n)`**: Sets output width to `n` columns (right-justified by default).
- **`setfill(ch)`**: Fills unused columns with a character.
- **`setprecision(n)`**:
  - Default: Displays up to `n` significant digits.
  - With `fixed`: Displays up to `n` decimal places.
- **`fixed`**: Forces fixed-point notation for floating-point output.
- **`showpoint`**: Displays decimal point and trailing zeros.
- **`left`** / **`right`**: Left or right justify output.
- **`unsetf(ios::fixed)`** / **`unsetf(ios::left)`**: Disables `fixed` or `left` formatting.
- **`showpos`** / **`noshowpos`**: Show or hide `+` for positive numbers.
- **`noshowpoint`**: Removes decimal point and trailing zeros.
- **`scientific`**: Displays floating-point numbers in scientific notation.
- **`dec`**, **`hex`**, **`oct`**: Display numbers in decimal, hexadecimal, or octal format.

---

### B. Mathematical Functions (`<cmath>`, `<cstdlib>`)
- **`abs(x)`** / **`fabs(x)`**: Absolute value (`abs` for integers, `fabs` for floats).
- **`pow(x, y)`**: `x` raised to the power of `y`.
- **`sqrt(x)`**: Square root.
- **`ceil(x)`**: Rounds up to next integer (in `double`).
- **`floor(x)`**: Rounds down to previous integer (in `double`).
- **`sin(x)`**, **`asin(x)`**: Sine and arcsine (in radians).
- **`fmod(x, y)`**: Floating-point remainder.
- **`exp(x)`**: Exponential function.
- **`log(x)`**, **`log10(x)`**: Natural log (`e`) and base-10 log.

---

### C. Random Functions (`<cstdlib>`, `<ctime>`)
- **`srand(seed)`**: Seeds the random number generator.
- **`time(NULL)` / `time(0)`**: Current time in seconds (often used as `srand` seed).
- **`rand()`**: Returns a pseudo-random integer between `0` and `RAND_MAX`.

---

### D. Character Functions (`<cctype>`)
- **`isalpha(ch)`**, **`isdigit(ch)`**, **`isalnum(ch)`**, **`isspace(ch)`**
- **`islower(ch)`**, **`isupper(ch)`**
- **`toupper(ch)`**, **`tolower(ch)`**

---

### E. String Class Functions (`<string>`)
- **`str.length()`** / **`str.size()`**: Returns string length.
- **`str.empty()`**: Checks if string is empty.
- **Comparison Operators**: `==`, `!=`, `<`, `>`.
- **`s1.at(i)`**: Access character at index `i`.
- **`s1.find("word")`** / **`s1.find('c')`**: Finds substring/character position.
- **`s1.insert(pos, str)`**: Inserts string at position.
- **`s1.replace(start, num_char, "new")`**: Replaces characters.
- **`s1.append(num_char, 'c')`**, **`s1.append(", text")`**: Appends to string.
- **`s1.erase(start, num_char)`**: Removes characters.

---

### F. C-String Functions (`<cstdlib>`, `<cstring>`)
**Conversion Functions**:
- `atof(str)`, `atoi(str)`, `atol(str)`

**Manipulation Functions**:
- `strcpy(s1, s2)`, `strncpy(s1, s2, n)`
- `strcat(s1, s2)`, `strncat(s1, s2, n)`

**Comparison Functions**:
- `strcmp(s1, s2)`, `strncmp(s1, s2, n)`

**Other Functions**:
- `strlen(s1)`: String length.
- `strpbrk(s1, s2)`: Finds first occurrence of any character from `s2` in `s1`.

---

### G. File I/O Functions (`<fstream>`)
- `file.open(source, mode)`
- `file.close()`
- `file.fail()`: Checks if file opening failed.
- `file.eof()`: Checks end-of-file.

---

## III. User-Defined Function Concepts
- **Function Declaration/Prototype**: Specifies return type, name, and parameters.
- **Function Definition**: Contains header and body.
- **Void Functions**: No return value.
- **Value-returning Functions**: Return a value via `return`.
- **Function Call**: Invokes the function.
- **Variable Scope**: Local vs Global variables.
- **Parameters**:
  - **Pass by Value**: Copy of data.
  - **Pass by Reference (`&`)**: Direct reference to variable.
  - **Pass by Address (`*`)**: Uses pointers.
- **Function Overloading**: Same name, different parameters.
- **Returning Arrays**: Return pointers instead of full arrays.

---

## IV. Examples of User-Defined Functions
```cpp
void header();                      // Prints "Function"
void Print_result(int ans);         // Prints integer result
int sum_num(int x1, int x2);        // Returns sum of two integers
double multiply(double num);        // Returns double the number
string get_response(bool F);        // Returns string based on boolean
void print_res(string Result);      // Prints string
int calculate(int x);               // Demonstrates variable scope

// Pass by Value, Reference, and Address
void fun(int x);
void fun(int &x);
void fun(int *x);

// Swap functions
void exchange(int &num1, int &num2);
void exchange(int *num1, int *num2);

// Overloading examples
void divide(int a, int b);
void divide(float a, float b);

// Overloaded swap
void swap(char &x, char &y);
void swap(int &x, int &y);
void swap(float &x, float &y);

// Menu functions
void displayMenu();
void Addition();
void Subtraction();
void Multiplication();
void Division();

// Array examples
int findLargest(int, int);
int findLargest(int arr[]);
void multiply2(int x[], int size);

// C-string examples
void fun1(char x[]);
void fun2(char y[]);

// 2D array example
void display(int x[10][10]);

// Returning array from function
int* getRandom();

// Enum examples
Weekday stringToDay(string d);
Mood getMood(int m);

// Struct passing
void update();
Record askRecord();
