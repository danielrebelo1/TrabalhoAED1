//
// Created by Daniel Rebelo on 14/10/2022.
//

#ifndef AEDTP1_STUDENT_H
#define AEDTP1_STUDENT_H

#include <string>


class Student {
public:
    Student(std::string& Name, int StudentCode);
    std::string get_Name() const;
    int get_StudentCode() const;
private:
    std::string Name_;
    int StudentCode_;
};

#endif //AEDTP1_STUDENT_H
