# Mess Management System

**Session:** 2023 - 2027  

**Submitted by:**  
Sumaira Hafeez  
2023-CS-01  

**Supervised by:**  
Sir Dr. Awais Hassan  

**Course:**  
CSC-102 Programming Fundamentals  

**Department of Computer Science**  
University of Engineering and Technology  
Lahore Pakistan  

## Table of Contents

1. [Short Description](#short-description)
2. [Users of Application](#users-of-application)
3. [Functional Requirements](#functional-requirements)
4. [Wireframes](#wireframes)
5. [Data Structures](#data-structures)
6. [Function Prototypes](#function-prototypes)
7. [Functions Working Flow](#functions-working-flow)
8. [Complete Code](#complete-code)
9. [Weakness in the Application](#weakness-in-the-application)
10. [Future Directions](#future-directions)

## Short Description

The Mess Management System is designed to address the dining issues faced by hostel students, enhancing the use of computer science in daily life. It aims to streamline hostel systems digitally, reducing paperwork and manpower. The application serves both mess managers and students, facilitating better management and service provision.

## Users of Application

1. **Student:** Hostel residents.
2. **Mess Manager:** Responsible for mess operations.

## Functional Requirements

| User Story ID | As a | I want to perform | So that I can |
| --- | --- | --- | --- |
| 1 | Student | Add Mess Attendance | Students will be able to mark off days | Students can update attendance in case of an emergency |
|  |  | Update Mess Attendance | Students can update attendance in case of an emergency |  |
|  |  | View Attendance | Students can view their attendance |  |
|  |  | Check Bill | Students can check their mess bill |  |
|  |  | Vote for Menu | Students can contribute to menu decisions |  |
|  |  | Complaint | Students can register complaints |  |
|  |  | Edit Account | Students can modify account details |  |
|  |  | Log Out | Students can log out |  |
| 2 | Manager | Menu | Manager can manage menu items |  |
|  |  | Add Stock | Manager can update stock for meals |  |
|  |  | View Stock | Manager can check stock availability |  |
|  |  | View Votes | Manager can review menu votes |  |
|  |  | Billing | Manager can generate bills |  |
|  |  | Profit | Manager can calculate profit |  |
|  |  | View Complaints | Manager can monitor student complaints |  |
|  |  | Log Out | Manager can log out |  |

## Wireframes

Wireframes and UI designs are available in the [YouTube video](https://youtu.be/ii4RChlXX8k?feature=shared).

## Data Structures

The application utilizes various data structures including parallel arrays for managing user data, attendance, menu, stock, and complaints.

## Function Prototypes

The application contains function prototypes for various functionalities including user authentication, menu management, attendance tracking, billing, and complaint handling.

## Functions Working Flow

Detailed flow diagrams of function interactions are available [here](https://link-to-diagrams).

## Complete Code

The complete code of the application is available in the GitHub repository.

## Weakness in the Application

1. Some validations are not functioning properly.
2. Arrays are declared within functions, leading to inefficiencies.
3. Limited file handling, focused only on sign-in information.
4. GUI needs improvement.
5. Missing functionality for paying bills.
6. Single responsibility principle not strictly followed in some functions.
7. Certain manager functionalities require student registration beforehand.
8. File handling issues reset student index after each exit, affecting data consistency.
9. Empty boxes for voting menu and complaints due to incomplete file handling.

## Future Directions

1. Implement arrow buttons for navigation instead of manual input.
2. Expand functionalities to cover more aspects of mess management.
3. Enhance user interface for improved user experience.
4. Refactor code for better modularity and flexibility.
5. Extend file handling to include all data components.
6. Address and resolve identified weaknesses for a more robust application.
