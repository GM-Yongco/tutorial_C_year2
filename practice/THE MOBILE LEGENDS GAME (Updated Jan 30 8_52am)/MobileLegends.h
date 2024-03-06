/**
 * INSTRUCTIONS:
 * THIS IS A HEADER (.h) FILE.
 * THIS FILE CONTAINS THE FOLLOWING:
 * - Data structure definitions
 * - Function prototypes
 * 
 * Note: Impelementations for the functions defined below are
 *       found in the "MobileLegends.c" file.        
 */
 

#ifndef MOBILELEGENDS_H
#define MOBILELEGENDS_H

/* Macro definition */
#define PIA_MAGIC_NUMBER 72453

/* Data structure definition */

/***** STUDENT INFO - ARRAY *****/

typedef struct{
	char email[30]; 	// "<IDNumber>@usc.edu.ph"
	char name[100]; 	// "FirstName MI. LastName" or "LastName, FirstName MI."
	char progYear[100]; // "BS Computer Science - 3" or "BSCS-3" (varied spacings)
}StudentType;  			// Information of a student

typedef struct{
	StudentType *students;
	int studentCount;  	// Stores the number of active students
}*StudentList; 			// Student list using array implementation version 4, sorted by email.

/***** STUDENT PAYMENTS - ARRAY *****/

typedef struct{
	char ID[10];
	char transactionNumber[40];
}StudentPaymentPartialType; 

typedef struct{
	StudentPaymentPartialType list[PIA_MAGIC_NUMBER];
	int studentCount;       	// Stores the number of active elements
}StudentPaymentTempArrayList; 	// Temporary array implementation of payments (sorting not needed) which 
   								// will be transformed into a filtered linked list shown below. 

/***** STUDENT PAYMENTS - LINKED LIST *****/

typedef struct{
	char firstName[30], MI, lastName[30];
}NameType;

typedef struct{
	char email[30];
	NameType name;
	char transactionNumber[40];
	char timestamp[100]; 	// Format: "YYYY-MM-DD HH:MM:SS"
}StudentPaymentType;

typedef struct SPNode{
	StudentPaymentType studPayment;
	struct SPNode* prev;	// Address of the previous node
    struct SPNode* next;	// Address of the current node
}StudentPaymentNode, *StudentPaymentList;	// Note: Doubly linked list

typedef enum{
  // Constants - Format in new CSV file
	BSCS, 	 // BS Computer Science 
	BSIT, 	 // BS Information Technology
	BSIS  	 // BS Information Systems
}program; // Recall the equivalent integer values

typedef struct{
	StudentPaymentList lists[4][3]; 
	int paymentCounts[4][3];
}PaymentLinkedLists;  
 
/* 
   Definition of PaymentLinkedLists:
 
 - lists is a 2D array of pointers to the head of the linked list of student nodes,  
   grouped by year level and then by program. 
 - paymentCounts is a 2D array of integers storing the count of payment nodes for 
   each linked list in the 2D pointer array. 
 - First index represents the year level (0:first year, 1:second year, 2:third 
   year, 3:fourth year), and second index represents the integer value of the 
   program enum type defined above.
 - Example: Payments from BSCS-1 students are stored in a linked list whose head 
   pointer is in lists[0][0]. The # of BSCS-1 payments is in paymentCounts[0][0].
 - Each list will be sorted in ascending alphabetical order of last name followed by 
   the first name.
*/

/***** TRANSACTONS - CURSOR-BASED *****/

typedef struct{
	char transactionNumber[40]; 
	float amount;     // P750.00 per person/node 
	int timestamp[6]; // 0:year, 1:month, 2:day, 3:hour, 4:minute, 5:second
	StudentPaymentList *paymentNodes[10]; // Addresses of the payment nodes 
                                             // having the given transaction number
	int nodesCount;       // Number of payment nodes currently referenced.
}TransactionType; // Info for each transaction.
  // If amount is less than P750 times number of nodes, means the transaction ID is 
  // overused. Invalidate or remove all the payment nodes that used this transaction 
  // number by accessing appropriately from the nodes field.

typedef struct{
	TransactionType data;
	int next; 		// index of the next transaction node
}TransactionVHNode;

typedef struct{
	TransactionVHNode transactions[PIA_MAGIC_NUMBER];
	int avail; 		// index of the first free transaction node
}VirtualHeapForTransactions;

typedef struct{
	int head;
	VirtualHeapForTransactions *VHptr;
}TransactionSet; 	// index of the node in virtual heap storing the first item of the
  					// transaction set using cursor based implementation, sorted by timestamp.

/* Function prototypes - Number 1 */
void initStudentList(StudentList* L);
void displayStudentList(StudentList L);
void initTempArrayList(StudentPaymentTempArrayList *L);
void displayTempArrayList(StudentPaymentTempArrayList L);
void initPaymentLinkedLists(PaymentLinkedLists *L);
void displayLinkedList(StudentPaymentList L);
void displayPaymentLinkedLists(PaymentLinkedLists L);

/* Function prototypes - Number 2 */
void initVirtualHeap(VirtualHeapForTransactions *VH);
void displayVirtualHeap(VirtualHeapForTransactions VH);
void initTransactionSet(TransactionSet *S, VirtualHeapForTransactions *ptr);
void displayTransactionSet(TransactionSet S);
int allocSpace(VirtualHeapForTransactions *VH);
void deallocSpace(VirtualHeapForTransactions *VH, int node);

/* Function prototypes - Number 3 */
int emailContainsID(char email[], char ID[]);
NameType extractNames(char name[]);
program extractProgram(char progYear[]);
int extractYear(char progYear[]);
int compareTimestamps(int time1[], int time2[]);
char* toDateTimeString(int timestamp[]);

/* Function prototypes - Number 4 */
void insertToStudentList(StudentList *list, char email[], char name[], char progYear[]);
void populateStudentList(StudentList *list);
void insertToPaymentTempArray(StudentPaymentTempArrayList *list, char ID[], char transactionID[]);
void populatePaymentTempArray(StudentPaymentTempArrayList *list);
void insertToTransactionSet(TransactionSet *set, char transactionID[], float amount, int timestamp[]);
void populateTransactionSet(TransactionSet *set);
StudentType* searchStudentByID(StudentList list, char studID[]);
TransactionType* searchTransactionByID(TransactionSet set, char transactionID[]);

/* Function prototypes - Number 5 */
void createPaymentLinkedLists(
	StudentPaymentTempArrayList payments,
	StudentList students,
	TransactionSet transactions,
	PaymentLinkedLists *output);
TransactionSet getInvalidTransactions(TransactionSet *allTransactions);
StudentPaymentList getInvalidPayments(TransactionSet dupTransactions);
void displayValidPayments(PaymentLinkedLists lists);
void displayInvalidPayments(StudentPaymentList list);
void displayValidPaymentPercentage(
	StudentPaymentTempArrayList allPayments,
	PaymentLinkedLists validPayments);
void generateEmailLists(
	PaymentLinkedLists validPayments,
	StudentPaymentList invalidPayments);


#endif
