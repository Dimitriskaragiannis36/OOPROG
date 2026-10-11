# Ορισμός του compiler και των flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Ονομασία του τελικού εκτελέσιμου
TARGET = my_program

# Αντικειμενικά αρχεία (object files)
OBJS = main.o Person.o Secretary.o

# Βασικός κανόνας για τη δημιουργία του εκτελέσιμου
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Κανόνες για τη δημιουργία των object files
main.o: main.cpp Secretary.h Person.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Secretary.o: Secretary.cpp Secretary.h Person.h
	$(CXX) $(CXXFLAGS) -c Secretary.cpp

Person.o: Person.cpp Person.h
	$(CXX) $(CXXFLAGS) -c Person.cpp

# Κανόνας για άμεση εκτέλεση του προγράμματος
run: $(TARGET)
	./$(TARGET)

# Κανόνας για καθαρισμό των παραγόμενων αρχείων
clean:
	rm -f $(OBJS) $(TARGET)