echo "Compiling..."
g++ customer.cpp employee.cpp person.cpp timestamp.cpp customerWriter.cpp -o write
g++ customer.cpp person.cpp timestamp.cpp customerReader.cpp -o reader
echo "Compilation finished"