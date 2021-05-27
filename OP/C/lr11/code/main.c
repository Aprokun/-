#include <stdio.h>

struct student {
    char full_name[255];
    size_t exam_score;
};

void fill_student_arr(struct student s[], size_t n) {
    printf("Input full name\n"
           "Then input your exam score\n");

    for (size_t i = 0; i < n; i++) {
        scanf("%s", s[i].full_name);
        scanf("%u", s[i].exam_score);
    }

}


int main() {
    printf("Input number of students\n");
    size_t n;
    scanf("%u", &n);
    struct student students[n];

    fill_student_arr(students, n);
}
