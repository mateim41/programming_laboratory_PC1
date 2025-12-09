#include <stdio.h>
#include <stdlib.h>

struct Person
{
    char name[50]; // = 50 bytes
    int age;       // = 4 bytes
    float height;  // = 4 bytes
                   // = 58 bytes
};

int main(void)
{
    struct Person person = {
        .name = "John",
        .age = 31,
        .height = 1.89};
    printf("sizeof(person) = %ld\n", sizeof(person));

    void *p1 = person.name;
    void *p2 = &person.age;
    void *p3 = &person.height;

    printf("%p\n%p\n%p\n", p1, p2, p3);

    return EXIT_SUCCESS;
}