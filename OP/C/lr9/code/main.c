#include <stdio.h>

typedef struct data {
    char second_name[50];
    char city[50];
    char address[50];
} person;

/*возвращает "1", если строки this и other равны, иначе - "0"*/
int is_str_equals(const char *this, const char *other) {
    while (*this != '\0' || *other != '\0') {
        if (*this != *other) {
            return 0;
        }

        this++; other++;
    }

    if (*other != '\0' || *this != '\0') {
        return 0;
    } else {
        return 1;
    }
}

/*ввод данных списка людей list размера size*/
void fill_people_data(person *list, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("Input: <Second name> <City> <Address>\n");
        scanf("%s %s %s", list[i].second_name, list[i].city, list[i].address);
    }
}

/*вывод людей из списка list размера size, адреса которых совпадают, а города - нет*/
void print_people_with_sim_addr(person *list, size_t size) {
    int is_empty = 1;
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if ((is_str_equals(list[i].address, list[j].address)) && !(is_str_equals(list[i].city, list[j].city))) {
                printf("%s --- %s\n", list[i].second_name, list[j].second_name);
                is_empty = 0;
            }
        }
    }

    if (is_empty) {
        printf("No people\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    person people[n];
    fill_people_data(people, n);

    print_people_with_sim_addr(people, n);
}
