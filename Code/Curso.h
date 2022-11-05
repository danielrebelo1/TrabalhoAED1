//
// Created by Jaime on 31/10/2022.
//

#ifndef PROJETO_AED_CURSO_H
#define PROJETO_AED_CURSO_H

#include <fstream>
#include <set>
#include <string>
#include <queue>
#include "Student.h"
#include "FileReader.h"
#include "PedidoAlteracao.h"
#include "Utils.h"
#include <algorithm>
#include "Menu.h"
#include <climits>

/**
 * The studentComparator2 is a function that compares two students and allows sorting in multiple ways.
 */
struct studentComparator2{
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s2->get_Name() < s1->get_Name());
        return false;
    }
};

/**
 * The studentComparatorCode  is a function that compares two students by student code and allows sorting.
 */
struct studentComparatorCode {
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s1->get_student_Code() < s2->get_student_Code());
        return false;
    }
};
/**
 * The studentComparatorDecreasingCode  is a function that compares two students by student code and allows sorting.
 */
struct studentComparatorDecreasingCode {
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s2->get_student_Code() < s1->get_student_Code());
        return false;
    }
};

class Curso {
    std::set<Student*, studentComparator> allStudents;
    std::set<Turma*, turmaComparator> allTurmas;
    std::vector<Slot *> allSlots;
    std::queue<PedidoAlteracao* > queuePA;
public:
    /**
     * Default constructor for class Curso.
     */
    Curso() = default;

    /**
     * Constructor for class Curso.
     * @param allSlots All lesson slots
     */
    Curso(std::set<Student*, studentComparator> , std::set<Turma*, turmaComparator>, std::vector<Slot *> allSlots );

    /**
     * The getAllStudents function is a getter for all students in a sorted way.
     * @return All students sorted
     */
    std::set<Student*, studentComparator> getAllStudents() const;

    /**
     * The getAllTurmas function is a getter for all classes in a sorted way.
     * @return All classes in a sorted way
     */
    std::set<Turma*, turmaComparator> getAllTurmas() const;

    /**
     * The PrintStudents fuction print students using a user's choice sorting.
     * @param students The students to be printed
     * @param option Type of sorting chosen
     */
    void PrintStudents(std::set<Student* , studentComparator> students , char option);

    /**
     * The PrintHorarioTurma is a function that print a class schedule
     * @param uc Uc chosen is users requests the schedule for a specific UC
     */
    void PrintHorarioTurma(std::vector<Turma*> , std::string uc = "");

    /**
     * The FindTurma is a function that allows user to find a specific class.
     * @param ucCode UC that the class belongs to
     * @return The class requested by the user
     */
    std::vector<Turma*> FindTurma(std::string ucCode = "");

    /**
     * The PrintStudentByName function finds a student by his name and then prints it.
     * @return The student requested by the user
     */
    Student* PrintStudentByName();

    /**
     * The PrintStudentByCode function finds a student by his student code and the prints it.
     * @return The student requested by the user
     */
    Student* PrintStudentByCode();

    /**
     * The getStudentsTurma function returns all students in a certain class
     * @param turmas The class the user wants to see the students from
     * @param ucCode The Uc Code in case the user wants the user in only a specific UC.
     * @return The students requested by the user
     */
    std::set<Student*, studentComparator> getStudentsTurma(std::vector<Turma*> turmas, std::string ucCode = "");

    /**
     * Function that allows sorting of a certain group of students.
     * @param students Students to be sorted
     * @param newstudents Sorted students
     * @return Sorted students
     */
    static std::set<Student* , studentComparator2> StudentReverseSortAlpha(std::set<Student *, studentComparator> students, std::set<Student *, studentComparator2> &newstudents);

    /**
    * Function that allows sorting of a certain group of students.
    * @param students Students to be sorted
    * @param newstudents Sorted students
    * @return Sorted students
    */
    static std::set<Student* , studentComparatorCode> StudentSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorCode> &newstudents);

    /**
    * Function that allows sorting of a certain group of students.
    * @param students Students to be sorted
    * @param newstudents Sorted students
    * @return Sorted students
    */
    static std::set<Student* , studentComparatorDecreasingCode> StudentReverseSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorDecreasingCode> &newstudents);

    /**
     * The SortbyTurmaCapacity function allows sorting of classes in a certain Uc by user choice.
     * @param ucCode Uc that the classes belong to
     * @param option Sorting option
     */
    void SortbyTurmaCapacity( std::string ucCode , int option);

    /**
     * The getStudentsYears function returns all students in a certain year
     * @param students The students to be printed
     * @param year The year chosen by the user
     * @return All students in a certain year
     */
    std::set<Student* , studentComparator> getStudentsYear(std::set<Student* , studentComparator> students , int year);

    /**
     * The getTurmasYear function returns all classes in a certain year.
     * @param year The year chosen by the user
     */
    void getTurmasYear( int year = INT_MAX);

    /**
     * The SortByEnrolledUC function allows sorting by the number of students enrolled in the UC.
     * @param op Controlled for user's choices
     * @param ucCode The UC chosen by the user
     */
    void SortByEnrolledUC( int op = 1 , std::string ucCode= "");

    /**
     * The ucCodeNormalizer function facilitates the user input for UcCodes, automatically making the input in the form given by the files.
     * @return A normalized UcCode
     */
    std::string ucCodeNormalizer();

    /**
     * The AddPA function executes request changes
     * @param s Student involved in the change
     * @param t Class that the student will be changed to
     * @param typeRequest The type of request
     */
    void AddPA(Student* s, Turma* t  , int typeRequest);

    /**
     * The FindTurmaLowestCapacity function returns the class with the most remaining vacancies that is compatible with a student's schedule
     * @param s Student
     * @param ucCode UC code
     * @return The class with the most vacancies that is compatible with the student's schedule
     */
    Turma* FindTurmaLowestCapacity(Student* s , std::string ucCode);

    /**
     * The GetTurma function returns a student's class for a certain UC
     * @param s Student
     * @param ucCode UC Code
     * @return Class in which the student is enrolled
     */
    Turma* GetTurma(Student* s , std::string ucCode);

    /**
     * The setDefaultCap function allows modifying of the class size cap
     * @param newCap The new cap to be set
     */
    void setDefaultCap(int newCap);

    /**
     * The getDefaultCap function is a getter for the current class size cap.
     * @return
     */
    int getDefaultCap();

    /**
     * The ProcessPA function processes all change requests made by the user
     */
    void ProcessPA();

    /**
     * The Save function saves all the changes made ProcessPA runs, must be user called.
     */
    void Save();

    /**
     * The WriteArchive function makes note of all the change request that were impossibe to do.
     * @param p The request that was denied
     */
    void WriteArchive(PedidoAlteracao* p);

    /**
     * The getTurmaMostStudents return the number of students in the class with the most students.
     * @return The number os students in the biggest class
     */
    int getTurmaMostStudents();

    /**
     * The findListStudentsUC function finds and prints all students enrolled in more than/exactly/less than n UCs.
     * @param n The number of UCs chosen by the user
     * @param exactN The user's choice ( more than / exactly / less than )
     * @param orderType The type of sorting to use in the print
     */
    void findListStudentsUC(int n, int exactN, int orderType);

};

#endif //PROJETO_AED_CURSO_H
