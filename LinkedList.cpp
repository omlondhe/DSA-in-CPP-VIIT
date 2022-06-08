#include <bits/stdc++.h>

using namespace std;

// Employee datatype consist of 
/*
	Employee name
	Employee ID
	Employee age
	Employee salary
*/
typedef struct Employee {
	int employee_id;
	string name;
	int age;
	double salary;
	struct Employee* next;
}Employee;

// Function to get Employee details from user
void getEmployeeData(Employee* employee) {
	cout << "Enter employee id: \t";
	cin >> employee->employee_id;
	cout << "Enter employee name: \t";
	cin >> employee->name;
	cout << "Enter employee age: \t";
	cin >> employee->age;
	cout << "Enter employee salary: \t";
	cin >> employee->salary;
}

// Add the first employee (Creating the head of the linked list)
Employee* addFirstEmployee(Employee* head) {
	head = new Employee();
	getEmployeeData(head);
	head->next = NULL;
	return head;
}

// Inserting the employee at the beginning (Linked List insert at te beginning operation)
Employee* insertEmployeeAtBeginning(Employee* head) {
	// creating first employee (head) if it is teh first employee (node/head)
	if (head == NULL) {
		return addFirstEmployee(head);
	} 
	// creating and adding employee at the start of already existing linked list
	Employee* employee = new Employee();
	getEmployeeData(employee);
	employee->next = head;
	head = employee;
	return head;
}

// Inserting the employee at the end (Linked List insert at te end operation)
Employee* insertEmployeeAtEnd(Employee* head) {
	// creating first employee (head) if it is teh first employee (node/head)
	if (head == NULL) {
		return addFirstEmployee(head);
	}
	// insert the employee at the end of the linked list 
	Employee* tempHead = head;
	while (tempHead->next != NULL) tempHead = tempHead->next;
	Employee* employee = new Employee();
	getEmployeeData(employee);
	tempHead->next = employee;
	return head;
}

// Inserting the employee at the given position (Linked list insert at the given position operation)
Employee* insertEmployeeAtThePosition(Employee* head) {
	// get the position to insert form the user
	int position;
	cout << "Enter the position where you want to insert the employee node: \t";
	cin >> position;


	// if user is trying to add to the position less than 2 then add the employee to the first position
	if (position <= 1) {
		cout << "You are requesting to add the employee at the position '" << position << "'.\nAdding employee at the beginning!\n\n";
		return insertEmployeeAtBeginning(head);
	}

	// adding employee to the given position if it is in the linked list bounds
	Employee* employee = new Employee();
	Employee* tempHead = head;
	position = position - 2;
	while (tempHead != NULL) {
		if (!position--) {
			getEmployeeData(employee);
			employee->next = tempHead->next;
			tempHead->next = employee;
			return head;
		}
		tempHead = tempHead->next;
	}

	// adding employee at the end of the linked list if the given position is out of bounds
	cout << "You are requesting the position which is out of the bounds of the Linked list so adding the employee at the end of the linked list.\n";
	return insertEmployeeAtEnd(head);
}

// Deleting the employee at the beginning (Linked List delete from the beginning operation)
Employee* deleteFirstEmployee(Employee* head) {
	// returning if head is null
	if (head == NULL) return head;

	// deleting employee at the start of already existing linked list
	Employee* employee = head;
	head = head->next;
	free(employee);
	return head;
}

// Deleting the employee at the end (Linked List insert at te end operation)
Employee* deleteLastEmployee(Employee* head) {
	// returning if head is null
	if (head == NULL) return head;

	// deleting the head if it is the only node present
	if (head->next == NULL) {
		free(head);
		return NULL;
	}

	// delete the employee at the end of the linked list 
	Employee* tempHead = head;
	while (tempHead->next->next != NULL) tempHead = tempHead->next;
	Employee* employee = tempHead->next;
	free(employee);
	tempHead->next = NULL;
	return head;
}

// Deleting the employee at the given position (Linked list delete at the given position operation)
Employee* deleteEmployeeAtThePosition(Employee* head) {
	// get the position to insert form the user
	int position;
	cout << "Enter the position of the employee you want to delete: \t";
	cin >> position;


	// if user is trying to delete the employee at the position less than 2 then delete the first employee
	if (position <= 1) {
		cout << "You are requesting to delete the employee at the position '" << position << "'.\nDeleting the employee at the beginning!\n\n";
		return deleteFirstEmployee(head);
	}

	// deleting employee at the given position if it is in the Linked list bounds
	Employee* employee;
	Employee* tempHead = head;
	position = position - 2;
	while (tempHead != NULL) {
		if (!position--) {
			employee = tempHead->next;
			tempHead->next = tempHead->next->next;
			free(employee);
			return head;
		}
		tempHead = tempHead->next;
	}

	// deleting employee at the end of the linked list if the given position is out of bounds
	cout << "You are requesting the position which is out of the bounds of the Linked list so deleting the employee at the end of the Linked list.\n";
	return deleteLastEmployee(head);
}

// Search employee by ID
void searchEmployeeById(Employee* head) {
	int id;
	cout << "Enter employee id: \t";
	cin >> id; 
	Employee* tempHead = head;
	
	while (tempHead != NULL) {
		if (tempHead->employee_id == id) {
			cout << tempHead->employee_id << " | " << tempHead->name << " | " << tempHead->age << " | " << tempHead->salary << "\n";
			cout << "---------------------------------------";
			return;
		}
		tempHead = tempHead->next;
	}
} 

// Search employees by name
vector<Employee*> searchEmployeesByName(Employee* head) {
	string name;
	cout << "Enter the name: \t";
	cin >> name;
	vector<Employee*> employees;
	Employee* tempHead = head;
	
	while (tempHead != NULL) {
		if (tempHead->name == name) {
			employees.push_back(tempHead);
		}
		tempHead = tempHead->next;
	}
	return employees;
} 

// Search employees by age
vector<Employee*> searchEmployeesByAge(Employee* head) {
	int age;
	cout << "Enter the age: \t";
	cin >> age;
	vector<Employee*> employees;
	Employee* tempHead = head;
	
	while (tempHead != NULL) {
		if (tempHead->age == age) {
			employees.push_back(tempHead);
		}
		tempHead = tempHead->next;
	}
	return employees;
} 

// Search employees by salary
vector<Employee*> searchEmployeesBySalary(Employee* head) {
	double salary;
	cout << "Enter the salary: \t";
	cin >> salary;
	vector<Employee*> employees;
	Employee* tempHead = head;

	while (tempHead != NULL) {
		if (tempHead->salary == salary) {
			employees.push_back(tempHead);
		}
		tempHead = tempHead->next;
	}
	return employees;
} 

// Show searched employees
void showSearchedEmployees(vector<Employee*> employees) {
	for (Employee* employee: employees) {
		cout << employee->employee_id << " | " << employee->name << " | " << employee->age << " | " << employee->salary << "\n";
	}
	cout << "---------------------------------------";
}

void showSearchedEmployeesResult(vector<Employee*> employees) {
	if (employees.size() > 0) showSearchedEmployees(employees);
	else cout << "No search results found\n";
}

// Update employee by id
void updateEmployeeById(Employee* head) {
	int id;
	cout << "Enter employee id: \t";
	cin >> id; 
	Employee* tempHead = head;
	
	while (tempHead != NULL) {
		if (tempHead->employee_id == id) {
			int choice;
			while (true) {
				cout << "What you want to update?\n";
				cout << "0.\tDone\n";
				cout << "1.\tName\n";
				cout << "2.\tAge\n";
				cout << "3.\tSalary\n";
				cin >> choice;

				switch (choice) {
					case 0:
						return;
					case 1:
						cout << "Enter new name:\t";
						cin >> tempHead->name;
						cout << "Name updated for employee with id '" << id <<"'!";
						break;
					case 2:
						cout << "Enter new age:\t";
						cin >> tempHead->age;
						cout << "Age updated for employee with id '" << id <<"'!";
						break;
					case 3:
						cout << "Enter new salary:\t";
						cin >> tempHead->salary;
						cout << "Salary updated for employee with id '" << id <<"'!";
						break;
					default:
						cout << "You made a wrong choice!";
						break;
				}
			}
		}
		tempHead = tempHead->next;
	}
	cout << "Employee with id '" << id << "' not found!\n";
} 

// Function to show all the available employee list (show the linked list)
void showEmployees(Employee* head) {
	Employee* tempHead = head;
	cout << "------------------------------------------\n";
	while (tempHead != NULL) {
		cout << "|\t" << tempHead->employee_id << "\t|\t" << tempHead->name << "\t|\t" << tempHead->age << "\t|\t" << tempHead->salary;
		cout << "\t|\n|\n";
		tempHead = tempHead->next;
	}
	cout << "NULL\n";
}


void showOptions() {
	cout << "------------------------------------------\n";
	cout << "Choose any of the follwing option: \n";
	cout << "0.\tShow employees\n";
	cout << "1.\tInsert at the beginning.\n";
	cout << "2.\tInsert at the end.\n";
	cout << "3.\tInsert at the position.\n";
	cout << "4.\tDelete the first employee.\n";
	cout << "5.\tDelete the last employee.\n";
	cout << "6.\tDelete the employee at position.\n";
	cout << "7.\tSearch the employee by id.\n";
	cout << "8.\tSearch the employee by name.\n";
	cout << "9.\tSearch the employee by age.\n";
	cout << "10.\tSearch the employee by salary.\n";
	cout << "11.\tUpdate employee.\n";
	cout << "12.\tExit\n\n";
	cout << "You option:\t";
}

int main() {
	int choice;
	Employee* head = NULL;

	while (true) {
		showOptions();
		cin >> choice;

		switch (choice) {
			case 0:
				showEmployees(head);
				break;
			case 1:
				head = insertEmployeeAtBeginning(head);
				break;
			case 2:
				head = insertEmployeeAtEnd(head);
				break;
			case 3:
				head = insertEmployeeAtThePosition(head);
				break;
			case 4:
				head = deleteFirstEmployee(head);
				break;
			case 5:
				head = deleteLastEmployee(head);
				break;
			case 6:
				head = deleteEmployeeAtThePosition(head);
				break;
			case 7:
				searchEmployeeById(head);
				break;
			case 8:
				showSearchedEmployeesResult(searchEmployeesByName(head));
				break;
			case 9:
				showSearchedEmployeesResult(searchEmployeesByAge(head));
				break;
			case 10:
				showSearchedEmployeesResult(searchEmployeesBySalary(head));
				break;
			case 11:
				updateEmployeeById(head);
				break;
			case 12:
				exit(0);
				break;
			default:
				cout << "Choose any of the given option.\n";
				break;
		}
	}

	return 0;
}

