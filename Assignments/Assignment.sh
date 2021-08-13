#! /bin/bash

: '
 a) Create address book. 
 b) View address book. 
 c) Insert a record. 
 d) Delete a record. 
 e) Modify a record. 
 f) Exit
'

echo "Welcome to the Address Book";

echo "Press 1 : To create a address book";
echo "Press 2 : To View the address book";
echo "Press 3 : To insert record into the address book";
echo "Press 4 : To delete record from the address book";
echo "Press 5 : To modify a record in the address book";
echo "Press 6 : To EXIT";

echo -n "Enter your choice : ";
read -r choice;

case $choice in
   1) echo -n "Name your address book : ";
      read -r address_book;
      touch "$address_book.txt"; 
      echo "$address_book address book created";
   ;;
   2) echo -n "Enter the address book name : " ;
      read -r address_book;
      if [ -e "$address_book.txt" ]
        then
            cat "$address_book.txt";
        else
            echo "Address book with this name is not available."
      fi
   ;;
   3) echo -n "Enter the address book name to insert the record " ;
      read -r address_book; 
      if [ -e "$address_book.txt" ]
        then
            echo "Enter the record details to be inserted" ;
            echo -n "Enter the name of address holder : "
            read -r address_holder;
            echo -n "Enter the address : ";
            read -r address;
            echo "$address_holder $address" >> "$address_book.txt";
        else
            echo "Address book with this name is not available. Make one."
      fi
   ;;
   4) echo -n "Enter the address book name to delete the record " ;
      read -r address_book; 
      if [ -e "$address_book.txt" ]
        then
            echo -n "Enter the address holder's name : " ;
            read -r name;
            file_content= grep "$name" "$address_book.txt";
            echo $file_content;
            if [ -z "$file_content" ];
            then
                echo "No match found";
            else
            echo "match found"
                #grep -v  "$name" "$address_book.txt" >> temp.txt;
                #mv temp.txt "$address_book.txt";
            fi 
        else
            echo "Address book with this name is not available. Make one."
      fi 
   


   ;;
   5) echo "I like banana nut bread." 
   ;;
   6) echo "New Zealand is famous for kiwi." 
   ;;
   *) echo "Wrong Choice Entered" 
   ;;
esac





