### Description:
A survey was carried out to record the ages of dogs in a given town. The records are made in the format; \
### **14571259254.83**
- where the number 14571259254 represents 11 age entries of the dogs in the town and the number 83 captures 2 entries representing the number of male and female dogs in that town.\
- In the entries made, some are valid and others are invalid. \
- **An entry is invalid if the number of age entries (number of digits before decimal point) is not equal to the sum of male and female number entries (sum of digits after decimal point).**\

### Tasks:
Given a double with two decimal places, write functions that;
1. Return the number of entries made
2. Extracts the female and male entries (the decimal value) and returns it as an integer
3. Finds the total of the male and female dog entries (sum of digits of integer value)
4. Determines if an entry is valid or invalid and returns a boolean (0 or 1).

### Sample Cases:
- 123.12 : This is a valid record in which 3 age entries were made. 
	   The entries 1 and 2 represent the number of male and female dogs respectively in the records.
	   The decimal value extracted as an integer is 12.

- 13478.49 : This is a valid record in which 5 age entries were made. 
	     The entries 4 and 9 represent the number of male and female dogs respectively in the records.
	     The decimal value extracted as an integer is 49.
