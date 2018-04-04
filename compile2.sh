echo "Compiling..."
g++ -g customer.cpp employee.cpp person.cpp timestamp.cpp customerWriter.cpp -o write
g++ -g customer.cpp person.cpp timestamp.cpp customerReader.cpp -o reader
echo "Compilation finished"