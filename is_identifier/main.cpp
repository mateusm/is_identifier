//
//  main.cpp
//  is_identifier
//
//  Created by Mateus Mesturini Meruvia on 2/19/16.
//  Copyright © 2016 Mateus Mesturini Meruvia. All rights reserved.
//

#include <iostream>
#include <string>

bool is_identifier(std::string str){
    int n,i, current=0;
    n = str.length();
    
    for(i=0; i<n; i++){
        
        
        if( (str[i]>= 65 && str[i]<= 90) || (str[i]>= 97 && str[i]<= 122) || str[i] == 95 ){ // check if is a letter or underscore using ASCII table
            
            current++; // if char =  use this variable to skip the next if
        }
        
        if (i != 0) { // numbers are not allowed in the first position
            if( str[i]>= 48 && str[i]<= 57 ){ // check if is a number
                if (current == i) { // check if the current position is equal to the 'i' position, if not skips
                    current++;
                }
            }
        }
        
        if(current == i) { // if 'current' and 'i' have the same value at this point it means that
            return false;  // none of the previous conditions were fullfilled, so its not a integer, returns FALSE
        }
        
        
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    std::string identifier;
    
    while (1) {
        
        std::cout << "Input: ";
        std::getline (std::cin,identifier); // reads a string from the standart input
        
        
        if(is_identifier(identifier)==true){
            printf("Output: ACCEPTED\n\n");
        }else{
            printf("Output: NOT ACCEPTED\n\n");}
    }
    return 0;
}