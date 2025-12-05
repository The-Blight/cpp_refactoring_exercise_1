#ifndef UNIVERSITY_DATE_H
#define UNIVERSITY_DATE_H

enum ErrorType {
    MonthError, DayError
};
enum DAYS {
    BEGIN_DAY = 1, END_DAY_28 = 28, END_DAY_30 = 30, END_DAY_31 = 31
};

class Date {
private:
    unsigned int _day;
    unsigned int _month;
    int _year;

    void CheckDay(int day, int end) {
        if (day > end || day < DAYS::BEGIN_DAY) {
            throw ErrorType::DayError;
        }
    }

public:
    void Init(int day, int month, int year) {
        if (month > 12 || month < 1) {
            throw ErrorType::MonthError;
        }

        switch (month) {
            case 1:
                CheckDay(day, DAYS::END_DAY_31);
                break;
            case 2:
                CheckDay(day, DAYS::END_DAY_28);
                break;
            case 3:
                CheckDay(day, DAYS::END_DAY_31);
                break;
            case 4:
                CheckDay(day, DAYS::END_DAY_30);
                break;
            case 5:
                CheckDay(day, DAYS::END_DAY_31);
                break;
            case 6:
                CheckDay(day, DAYS::END_DAY_30);
                break;
            case 7:
                CheckDay(day, DAYS::END_DAY_31);
                break;
            case 8:
                CheckDay(day, DAYS::END_DAY_31);
                break;
            case 9:
                CheckDay(day, DAYS::END_DAY_30);
                break;
            case 10:
                CheckDay(day, DAYS::END_DAY_31);
                break;
            case 11:
                CheckDay(day, DAYS::END_DAY_30);
                break;
            case 12:
                CheckDay(day, DAYS::END_DAY_31);
                break;
        }

        _day = day;
        _month = month;
        _year = year;
    }

    int GetDay() {
        return _day;
    }

    int GetMonth() {
        return _month;
    }
    int GetYear() {
        return _year;
    }
};

#endif //UNIVERSITY_DATE_H