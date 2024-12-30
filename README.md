BUS TICKET MANAGEMENT SYSTEM


Technologies and Tools Used:
Programming Language: C  
Development Environment:Code::Blocks,VS Code.   
Libraries:  
Standard Input/Output Library (<stdio.h>)  
Standard Library (<stdlib.h>)  
String Manipulation Library (<string.h>)      
Standard Boolean Library (<stdbool.h>)  

Storage:  

(i) Text file (userdata.txt) for storing user information.  
System Structure:  
(I)SEAT_NUMBER defined as 30 for the total available seats.  
(ii) Modular functions for login, signup, seat booking, cancellation, and display.  
Project Overview  
The Bus Ticket Booking System is designed to simulate the functionality of a bus service booking system. 
The system allows users to book, cancel, and check the status of bus seats, as well as register and log in 
to their accounts.  

Key Features:  
1. User Registration and Login  
2. Seat Booking  
3. Seat Cancellation  
4. Display Booking Information  
5. Available Seats Display  
6. Logout

Project Functionality:
The system operates based on the following functionalities:  
1. User Registration and Login:  - Email Validation    - Login Verification  
2. Seat Booking:  - Validation to ensure that only available seats can be booked.  - Real-time seat status updates.  
3. Seat Cancellation:  - Users can cancel previously booked seats, updating the seat status to available.  
4. Seat Status Display:  - Displays all seat statuses (Booked/Available).  
5. Seat Availability Display:  - Displays only available seats.  
6. Logout:  - User logs out securely, ending their session.  
System Design  - File Storage:  - userdata.txt: A text file storing user details like name, email, and password.  - Seat Management:  - The bus has 30 seats, stored in an integer array. Each index corresponds to a seat, where `1` means 
booked, and `0` means available.  - Functions:  - login(): Checks user credentials by reading the user data file.  - signup(): Registers new users and appends their data to the file.  - bookSeat(): Books a seat by marking the corresponding array index as `1` (booked).    - 
cancelBooking(): Cancels a booking by setting the array index back to `0`.  
- displayBookingInfo(): Displays the status of all seats.  - displayAvailableSeats(): Displays only the seats that are available.

Conclusion:

The Bus Ticket Booking System provides a simple yet effective solution for bus seat management. It  
implements core functionalities such as user login, sign-up, seat booking, cancellation, and display of  
seat statuses. The system offers real-time seat management, preventing double bookings, and allows  
users to interact with the bus service in an intuitive way. # Bus-Ticket-Management-System
