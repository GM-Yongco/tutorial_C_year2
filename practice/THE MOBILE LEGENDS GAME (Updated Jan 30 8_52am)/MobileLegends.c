/**
 * INSTRUCTIONS:
 * THIS IS A FILE COMPLEMENTING THE "MobileLegends.h" FILE.
 *
 * THIS FILE CONTAINS THE FOLLOWING:
 * - Implementations for the functions defined in the "MobileLegends.h" file
 * 
 * REFER TO THE DOCUMENTATION FOR THE FUNCTION SPECIFICATIONS.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "MobileLegends.h"

/* Function Definitions - Number 1 */
void initStudentList(StudentList* L){
	
}

void displayStudentList(StudentList L){
	
}

void initTempArrayList(StudentPaymentTempArrayList *L){
	
}

void displayTempArrayList(StudentPaymentTempArrayList L){
	
}

void initPaymentLinkedLists(PaymentLinkedLists *L){
	
}

void displayLinkedList(StudentPaymentList L){
	
}

void displayPaymentLinkedLists(PaymentLinkedLists L){
	
}

/* Function Definitions - Number 2 */
void initVirtualHeap(VirtualHeapForTransactions *VH){
	
}

void displayVirtualHeap(VirtualHeapForTransactions VH){
	
}

void initTransactionSet(TransactionSet *S, VirtualHeapForTransactions *ptr){
	
}

void displayTransactionSet(TransactionSet S){
	
}

int allocSpace(VirtualHeapForTransactions *VH){
	
}

void deallocSpace(VirtualHeapForTransactions *VH, int node){
	
}

/* Function Definitions - Number 3 */
int emailContainsID(char email[], char ID[]){
	
}

NameType extractNames(char name[]){
	
}

program extractProgram(char progYear[]){
	
}

int extractYear(char progYear[]){
	
}

int compareTimestamps(int time1[], int time2[]){
	
}

char* toDateTimeString(int timestamp[]){
	
}

/* Function Definitions - Number 4 */
void insertToStudentList(StudentList *list, char email[], char name[], char progYear[]){
	
}

void populateStudentList(StudentList *list){
	
}

void insertToPaymentTempArray(StudentPaymentTempArrayList *list, char ID[], char transactionID[]){
	
}

void populatePaymentTempArray(StudentPaymentTempArrayList *list){
	
}

void insertToTransactionSet(TransactionSet *set, char transactionID[], float amount, int timestamp[]){
	
}

void populateTransactionSet(TransactionSet *set){
	
}

StudentType* searchStudentByID(StudentList list, char studID[]){
	
}

TransactionType* searchTransactionByID(TransactionSet set, char transactionID[]){
	
}

/* Function prototypes - Number 5 */
void createPaymentLinkedLists(
	StudentPaymentTempArrayList payments,
	StudentList students,
	TransactionSet transactions,
	PaymentLinkedLists *output)
{
		
}

TransactionSet getInvalidTransactions(TransactionSet *allTransactions){
	
}

StudentPaymentList getInvalidPayments(TransactionSet dupTransactions){
	
}

void displayValidPayments(PaymentLinkedLists lists){
	
}

void displayInvalidPayments(StudentPaymentList list){
	
}

void displayValidPaymentPercentage(
	StudentPaymentTempArrayList allPayments,
	PaymentLinkedLists validPayments)
{
	
}

void generateEmailLists(
	PaymentLinkedLists validPayments,
	StudentPaymentList invalidPayments)
{
	
}
