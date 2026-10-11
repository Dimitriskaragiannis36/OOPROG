CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = program_part_b

OBJS = main.o Person.o Student.o Professor.o Course.o Secretary.o Academicsemester.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Person.h Student.h Professor.h Course.h Secretary.h Academicsemester.h Department.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Person.o: Person.cpp Person.h
	$(CXX) $(CXXFLAGS) -c Person.cpp

Student.o: Student.cpp Student.h Person.h Department.h Course.h Secretary.h
	$(CXX) $(CXXFLAGS) -c Student.cpp

Professor.o: Professor.cpp Professor.h Person.h Course.h Academicsemester.h
	$(CXX) $(CXXFLAGS) -c Professor.cpp

Course.o: Course.cpp Course.h Professor.h Student.h
	$(CXX) $(CXXFLAGS) -c Course.cpp

Secretary.o: Secretary.cpp Secretary.h Professor.h Student.h Course.h Academicsemester.h
	$(CXX) $(CXXFLAGS) -c Secretary.cpp

Academicsemester.o: Academicsemester.cpp Academicsemester.h Course.h Student.h Secretary.h
	$(CXX) $(CXXFLAGS) -c Academicsemester.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)