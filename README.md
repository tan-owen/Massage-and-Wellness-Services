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
