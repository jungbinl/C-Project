import numpy as np


#class Node is defined for you so just read the specifics
class Node:
    def __init__(self, name=None, balance = None):
        self.data = Account(name,balance)
        self.next = None

#complete the AccountLinkedlist based on the fucntion needed
class AccountLinkedList:
    def __init__(self):
        self.head = None

    def Add(self, name_in = None, balance_in=None):
        # Question1: add new node by an instance object of account class then update the next and head node (15points)
        new_node = Node(name_in, balance_in)
        if self.head is None:
            self.head = new_node
            return
        
        current = self.head
        while current.next is not None:
            current = current.next
        
        current.next = new_node   
    #Question2: remove based on just the name of the account (consider the name is unique)-->(15 points)
    def Remove(self, RemoveName):
        Head = self.head
        if Head.data.name == RemoveName:
            self.head = Head.next
            return
        while Head is not None and Head.next is not None:
            if Head.next.data.name == RemoveName:
                Head.next = Head.next.next
                return
            Head = Head.next    
    #Question3: update account by type whether it is withrawal or deposit
    def UpdateAccount(self,Name,type,amount): #first find the name then do the operation (10 points)
        # Initialize current to head
        current = self.head

        # loop till current not equal to None then use if statements if type is "D" or "Deposit" then you
        #use deposit method of class account, if the type is "W" or "Withrawal" then use withraw method
        #you should update nodes (figure out yourself)
        while current is not None:
            if current.data.name == Name:
                break
            current = current.next
            
        if current is None:
            print(f"Account '{Name}' not found.")
            return
        if type in ("D", "Deposit"):
            current.data.deposit(amount)
        elif type in ("W", "Withrawal"):
            current.data.withdraw(amount)
        else:
            print("Error!")
    #Question4: print account info based on the overloaded string method of class account, so you have to traverse the list to use print (5 points)
    def PrintAccount(self):
        printval = self.head
        a = []
        while printval is not None:
            a.append(printval.data.__str__())
            printval = printval.next
        print("\n".join(a))

class Account:

    #constructor is given
    def __init__(self, name = None, balance = None):
        self.name = name
        self.__balance = balance #convention for private variables in python is __


    #Question5: update the balance using a positive deposit value, if value is negative raise an error (5 points)
    def deposit(self, amount):
        if amount < 0:
            raise ValueError("Deposit amount cannot be negative.")
        self.__balance += amount

    #Question6: accordingly do the same approach to withdraw  (5points)
    def withdraw(self, amount):
        if amount < 0:
            raise ValueError("Withdrawal amount cannot be negative.")
        self.__balance -= amount

    def show_info(self):
        print("Name: " + str(self.name) + " with balance $" + str(self.__balance))

    #this is also given to you. this is how you overload string class so that you can use print the object of class account
    def __str__(self):
        rep = "Name: " + str(self.name) + " with balance $" + str(self.__balance)
        return rep



#Question7: main fucntion to define. Please complete all the parts you are asked to complete  --> total 20 points

def main():

    #use the imported numpy array (with alias np) here, the first one is given but you have to read the
    #methods of numpy package so that you can convert list b and c to numpy array and then add it to list a
    #using the method vstack --> you have to use the right dtype like what is given in list a
    #values are in US dollars
    a = np.array([["Micheal",100]],dtype=object)  #since the pair are not both the same type we use object
    b = np.array([["Mohammad", 200]], dtype=object)
    c = np.array([["James", 350]], dtype=object)
    #place your code here
    a = np.vstack((a, b, c))

    #print the size of array a here
    print(a.size)

    #do a for loop to convert us dollar amounts to canadian using the rate US$ = 1.26 CA$ then use numpy rounding function to round it
    #update the values in list
    for i in range(a.shape[0]):
        usd = a[i][1]
        cad = np.round(usd * 1.26)
        a[i][1] = cad


    #create an instance of AccountLinkedlist
    llist = AccountLinkedList()
    
    #do a loop to add the pair values (name and amount) to the linkedlist
    for name, money in a:
        llist.Add(name, money)

    #remove Mohammad from the list
    llist.Remove("Mohammad")

    #deposit 100 dollars (canadian so no worries for conversion here) to James Account
    llist.UpdateAccount("James", 'D', 100)

    #withraw 40 dollars from Micheal's Account
    llist.UpdateAccount("Micheal", 'W', 40)
    
    #print the whole list
    llist.PrintAccount()

if __name__ == "__main__":
    main()
