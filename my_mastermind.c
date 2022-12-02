#include "my_headers.h"

int main(int argc, char *argv[]){

    char* master_code = malloc(16);
    master_code[0] = '\0';
    int gimmick_int[5] = {8};
    int* int_mastercode;
    int_mastercode = &gimmick_int[0];
    char* guess = malloc(16);
    guess[0] = '\0';  

    check_c_opt(argc, argv, master_code);
    int attempts = check_t_opt(argc, argv);
    
    if(*master_code == '\0'){
        my_secretcode(int_mastercode);
        my_itoa(master_code, int_mastercode);
        printf("We generated code for you!\n");
    }
    
    printf(COLOR_YELLOW "Will you find the secret code?" COLOR_RESET "\n");
      
    int round = 1;
    bool valid_code = false;
    char* my_buf = malloc(16);

    while(attempts != 0){
        printf(COLOR_BLUE "\t---***---" COLOR_RESET "\n");
        printf(COLOR_YELLOW "\t-Round %d-" COLOR_RESET "\n", round);
        
        if(attempts == 1){
            printf(COLOR_YELLOW "Last attempt left! You're gonna lose! :D" COLOR_RESET "\n");
        }
      
        while(valid_code == false){
            if(guess[0] != '\0'){
               my_emptystr(guess);  
            }
            my_guess_reader(guess, my_buf);
            int length = my_strlen(guess);
            
            if(length != 4){
                printf(COLOR_RED "Wrong input!" COLOR_RESET "\n");
                continue;
            }
            else{
                valid_code = code_validator(guess);
            }           
        }

        if(my_guess_check(master_code, guess)){
            break;
        }

        attempts--;
        round++;
        valid_code = false;

    }

    if(attempts == 0){
        printf("The secret code was " COLOR_RED "%s, Looser" COLOR_RESET "!\n", master_code);
    }

    free(master_code);
    free(guess);
    free(my_buf);
    
    return EXIT_SUCCESS;      
}
