#ifndef UNIVERSITY_PERSON_H
#define UNIVERSITY_PERSON_H

#include <string>

#include "Date.h"
#include "Exceptions.h"
using namespace std;

enum Sex { M, F };


class Person {
private:
    string _last_name;
    string _first_name;
    Date* _date_of_birth;
    Sex _sex;

public:
    Person(const string& last_name, const string& first_name, Date* date_of_birth, Sex sex)
        : _last_name(last_name),
          _first_name(first_name),
          _date_of_birth(date_of_birth),
          _sex(sex) {
    }
    ~Person() {
        delete _date_of_birth;
    }

    string get_last_name() const {
        return _last_name;
    }

    string get_first_name() const {
        return _first_name;
    }

    Date* get_date_of_birth() const {
        return _date_of_birth;
    }

    Sex get_sex() const {
        return _sex;
    }

    string get_full_name() const {
        return get_last_name() + " " + get_first_name();
    }
};


#endif //UNIVERSITY_PERSON_H