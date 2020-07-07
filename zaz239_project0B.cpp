#include <stdio.h>
#include <assert.h>

#define SIZE 26

int are_anagrams(char[], char[]);

int main() {
    printf("running test 'iceman' and 'cinema'...\n");
    char iceman[] = "iceman";
    char cinema[] = "cinema";

    assert(are_anagrams(iceman, cinema));
    printf("passed!\n");

    printf("running test 'raganam' and 'anagram'...\n");
    char raganam[] = "raganam";
    char anagram[] = "anagram";

    assert(are_anagrams(raganam, anagram));
    printf("passed!\n");
    
    printf("running test 'listen' and 'silent'...\n");
    char listen[] = "listen";
    char silent[] = "silent";

    assert(are_anagrams(listen, silent));
    printf("passed!\n");

    printf("running test 'mole' and 'meal'...\n");
    char mole[] = "mole";
    char meal[] = "meal";

    assert(!are_anagrams(mole, meal));
    printf("passed!\n");

    printf("running test 'happy' and 'sad'...\n");
    char happy[] = "happy";
    char sad[] = "sad";

    assert(!are_anagrams(happy, sad));
    printf("passed!\n");
}

int are_anagrams(char first_word[], char second_word[]) {
    /* your code goes here */
    int i = 0;//array pointer for letters in first_word
    int x = 0;//array pointer for letters in second_word
    int len1 = -1;
    int len2 = -1;
    while (first_word [i] != 0) {
        len1++;
        i ++;
    }
    while (second_word[x]) {
        len2++;
        x++;
    }
    if (len1 == len2) {
        i = 0;
        x = 0;
        int tru_fal = 0;
        while (first_word[i] != 0) {
            if (first_word[i] == second_word[x]) {
                i++;
                x = 0;
                tru_fal = 1;
            }else{
                x++;
                tru_fal = 0;
                if (second_word[x] == 0){
                    first_word[i] = 0;
                }
            }


        }
        if (tru_fal == 1){
            return 1;
        }else{
            return 0;
        }
    }else{

        return 0;
    }
    return 0;
}
