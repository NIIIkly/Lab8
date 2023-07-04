#include <stdio.h>
#include <string.h>

// Функція для підрахунку кількості анаграм
unsigned long long countAnagrams(char* word, int length, int* count) {
    if (length <= 1) {
        return 1;
    }

    unsigned long long totalAnagrams = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            count[i]--;
            totalAnagrams += countAnagrams(word, length - 1, count);
            count[i]++;
        }
    }

    return totalAnagrams;
}

int main() {
    char word[15];

    printf("Введіть слово: ");
    scanf("%s", word);

    int count[26] = {0};
    int length = strlen(word);

    // Обчислення кількості входжень кожної букви у слово
    for (int i = 0; i < length; i++) {
        count[word[i] - 'A']++;
    }

    unsigned long long result = countAnagrams(word, length, count);

    printf("Кількість анаграм: %llu\n", result);

    return 0;
}
