#include "my_headers.h"

// checks for -c flag, returns secret code if it's given
 char *check_c_opt(int argc, char *argv[], char* master_code){
    int i = 1;
    while(i < argc){
        if(my_strcmp(argv[i], "-c")){
            i++;
            if(my_strlen(argv[i]) != 4){ 
                printf(COLOR_RED "Wrong input! The code must be 4 digits!" COLOR_RESET "\n");
                break;
            }
            else{
                if(code_validator(argv[i])){
                    my_strcpy(master_code, argv[i]);
                }
            }
        }
        i++;
    }
    
    return master_code;
}

//checks for -t flag, returns number of attempts
int check_t_opt(int argc, char *argv[]){
    int attempts = 10;
    int i = 1;
    while(i < argc){
        if(my_strcmp(argv[i], "-t")){
            i++;
            if((atoi(argv[i])) > 10 || (atoi(argv[i])) < 1){
                printf(COLOR_RED "The number of attempts was set to 10!" COLOR_RESET "\n");
                break;
            }
            else{
                attempts = atoi(argv[i]);
                break; 
            }
        }

        i++;
    }

    return attempts;
}

//reads from standard input, returns user's guess str
char *my_guess_reader(char *guess, char *my_buf){    
    int i = 0;
    while (1){
        read(0, my_buf, 1);
        if(*my_buf == '\n'){
            break;
        }
        guess[i] = *my_buf;
        i++;       
    }
    guess[i] = '\0';

    return guess;
}

//compares secret code to user's guess
bool my_guess_check(char *master_code, char *guess){
    int well_placed = 0;
    int misplaced_pieces = 0;
    for(int i=0; i<4; i++){
        if(master_code[i]==guess[i]){
            well_placed++;
        }
        else{
            for(int j=0; j<4; j++){
                if(master_code[i]==guess[j]){
                misplaced_pieces++;
                }
            }
        }
    }
    if(well_placed == 4){
        printf(COLOR_YELLOW "WOWZA! You guessed it!" COLOR_RESET "\n");
        return true;
    }
    else{
        printf("Well placed pieces: %d\n", well_placed);        
        printf("Misplaced pieces: %d\n", misplaced_pieces);
        return false;
    }
}

//compares if two strings are of an equal value 
bool my_strcmp(char* param_1, char* param_2){
    int i = 0;
    while(param_1[i] != '\0' || param_2[i] != '\0'){
        if(param_1[i]>param_2[i]){
            return false;
        }
        if(param_1[i]<param_2[i]){
            return false;
        }
        if(param_1[i]==param_2[i]){
            i++;
        }
    }

    return true;
}

//calculates the length of a string
int my_strlen(char* param_1){
    int length = 0;
    int i = 0;
    while (param_1[i] != '\0'){
        length++;
        i++;
    }

    return length;  
}

//copies the string pointed to by param_2 to the buffer pointed by param_1
char* my_strcpy(char* param_1, char* param_2){

    int length = my_strlen(param_1);
    int length_2str = my_strlen(param_2); 
    int k = 0;
    
    while (k < length_2str) {
        param_1[length] = param_2[k];
        k++;
        length++;
    }
    param_1[length] = '\0';

    return param_1;
}

//searches for the first occurrence of the character c in the string. Returns true if present
bool my_strchr(char* param_1, char param_2){
    while(*param_1){
        if(param_2 == *param_1){
            return true;
        }
        param_1++;
    }

    return false;
}

//checks if the char occurs twice in array
bool my_duplchr(char* param_1, char param_2){
    int count = 0;
    while(*param_1){
        if(param_2 == *param_1){
            count++;
        }
        param_1++;
    }
    if(count>1){
        return true;
    }

    return false;
}

//checks if int is not present in the array
bool my_strint(int* param_1, int param_2){
    int i = 0;
    while(i<4){
        if(param_2 == param_1[i]){
            return false;
        }
        i++;
    }

    return true;
}

//generates an array of random unique numbers in the range from 0 to 7
int *my_secretcode(int* secret_code){
    srand(time(0));
    int i = 0;
    int number;
        while(i < 4){
            number = rand() % 8;
            if(i==0){
                secret_code[i] = number;
                i++;  
            }
            else if(my_strint(secret_code, number)){
                secret_code[i] = number;
                i++;
            }         
        }

    return secret_code;
}
 
//converts int data type to string data type in the range from 0 to 7, default length 4
char* my_itoa(char* master_code, int *secret_code){
    int i=0;
    while(i<4){
        char number;
        if(secret_code[i]==0){
            number = 48;
        }
        else if(secret_code[i]==1){
            number = 49;
        }
        else if(secret_code[i]==2){
            number = 50;
        }
        else if(secret_code[i]==3){
            number = 51;
        }
        else if(secret_code[i]==4){
            number = 52;
        }
        else if(secret_code[i]==5){
            number = 53;
        }
        else if(secret_code[i]==6){
            number = 54;
        }
        else if(secret_code[i]==7){
            number = 55;
        }
        master_code[i] = number;
        i++;
    }
    master_code[i] = '\0';

    return master_code;
}

//checks if a secret code is of a valid length
bool valid_length (char *master_code){
    if(my_strlen(master_code) != 4){ 
        printf(COLOR_RED "Wrong input! The code must be 4 digits!" COLOR_RESET "\n");
        return false;
    }
    return true;
}

//checks if a string is a valid input: made of valid digits and doesn't contain duplicates
bool code_validator(char *master_code){
    
    int i = 0;
    while(master_code[i] != '\0'){
        if(master_code[i] < 48 || master_code[i] > 55){
            printf(COLOR_RED "Wrong input! Only digits from 0 to 7 are allowed!" COLOR_RESET "\n");
            return false;
        }
        else if(my_duplchr(master_code, master_code[i])){
            printf(COLOR_RED "Wrong input! No duplicates allowed!" COLOR_RESET "\n");
            return false;
        }   
        i++;
    }
    
    return true;
}

//returns a pointer to a string that has been emptied
char *my_emptystr(char* param){
    int i =0;
    int length = my_strlen(param);
    while(i < length){
        param[i] = '\0';
        i++;
    }

    return param;
}