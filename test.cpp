#include <iostream>

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

// Function to get Employee details
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

// Inserting the employee at the beginning (Linked List insert at te beginnign operation)
Employee* insertAtBeginning(Employee* head) {
	if (head == NULL) {
		return addFirstEmployee(head);
	} 
	Employee* employee = new Employee();
	getEmployeeData(employee);
	employee->next = head;
	head = employee;
	return head;
}

// Inserting the employee at the end (Linked List insert at te end operation)
Employee* insertAtEnd(Employee* head) {
	if (head == NULL) {
		return addFirstEmployee(head);
	}
	Employee* tempHead = head;
	while (tempHead->next != NULL) tempHead = tempHead->next;
	Employee* employee = new Employee();
	getEmployeeData(employee);
	tempHead->next = employee;
	return head;
}

// Inserting the employee at the given position (Linked list insert at the given position operation)
Employee* insertAtThePosition(Employee* head) {
	int position;
	cout << "Enter the position where you want to insert the employee node: \t";
	cin >> position;

	Employee* employee = new Employee();

	if (position <= 0) {
		cout << "You are requesting to add the employee at the position '" << position << "'.\nAdding employee at the beginning!\n\n";
		return insertAtBeginning(employee);
	}

	Employee* tempHead = head;
	while (tempHead != NULL) {
		if (!position--) {
			getEmployeeData(employee);
			employee->next = tempHead->next;
			tempHead->next = employee->next;
			return head;
		}
	}

	cout << "You are requesting teh position which is out of teh bound of the Linked list so adding the employee at the end of the linked list.\n";
	return insertAtEnd(head);
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
	cout << "------------------------------------------\n";
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
	cout << "7.\tDelete the employee at position.\n";
	cout << "8.\tSearch the employee by id.\n";
	cout << "9.\tSearch the employee by name.\n";
	cout << "10.\tSearch the employee by age.\n";
	cout << "11.\tSearch the employee by salary.\n";
	cout << "12.\tUpdate employee.\n";
	cout << "13.\tExit\n\n";
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
				head = insertAtBeginning(head);
				break;
			case 2:
				head = insertAtEnd(head);
				break;
			case 3:
				head = insertAtThePosition(head);
				break;
			case 13:
				exit(0);
				break;
			default:
				break;
		}
	}

	return 0;
}

