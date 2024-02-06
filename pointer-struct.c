#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct _person{
    char* firstName;
    char* lastName;
    char* title;
    unsigned int age;
};

typedef struct _person2{
    char* firstName;
    char* lastName;
    char* title;
    unsigned int age;
}Person;

int main() {
    Person person;
    Person *ptrPerson;
    ptrPerson = (Person *) malloc(sizeof(Person));
    person.firstName = (char *)malloc(strlen("Emily") + 1);
    strcpy(person.firstName, "Emily");
    person.age = 23;
    ptrPerson->firstName = (char *)malloc(strlen("Emily") + 1);

}