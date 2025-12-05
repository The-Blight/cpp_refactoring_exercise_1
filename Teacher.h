#ifndef UNIVERSITY_TEACHER_H
#define UNIVERSITY_TEACHER_H

#include <string>
#include <vector>

#include "Person.h"

using namespace std;

class Teacher : public Person {
private:
    vector<string>* _subjects;
    string _faculty;

public:
    Teacher(const string& last_name, const string& first_name, Date* date_of_birth, Sex sex, const string& faculty)
        : Person(last_name, first_name, date_of_birth, sex),
          _faculty(faculty) {
        _subjects = new vector<string>();
    }

    ~Teacher() {
        delete _subjects;

        ~Person();
    }

    void add_subject(const string& subject) {
        _subjects->push_back(subject);
    }

    vector<string>* get_subjects() const {
        return _subjects;
    }

    string get_faculty() const {
        return _faculty;
    }
};


#endif //UNIVERSITY_TEACHER_H