CC_EXEC = g++
CC_FLAGS = -std=c++11

CC = ${CC_EXEC} ${CC_FLAGS}

BUILD_DIR = build

all: 2.out

2.out:  ${BUILD_DIR}/main.o ${BUILD_DIR}/circuit.o ${BUILD_DIR}/Input.o ${BUILD_DIR}/Gate.o ${BUILD_DIR}/Update_Gate.o ${BUILD_DIR}/Wire.o ${BUILD_DIR}/Exceptions.o 
	g++  ${BUILD_DIR}/main.o ${BUILD_DIR}/circuit.o ${BUILD_DIR}/Input.o ${BUILD_DIR}/Gate.o ${BUILD_DIR}/Update_Gate.o ${BUILD_DIR}/Wire.o ${BUILD_DIR}/Exceptions.o -o ${BUILD_DIR}/2.out


${BUILD_DIR}/main.o: main.cpp circuit.hpp Input.hpp Gate.hpp Update_Gate.hpp Wire.hpp Exceptions.hpp
	${CC} -c main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/Exceptions.o: Exceptions.cpp Exceptions.hpp
	${CC} -c Exceptions.cpp -o ${BUILD_DIR}/Exceptions.o

${BUILD_DIR}/Input.o: Input.cpp Input.hpp Exceptions.hpp Wire.hpp Gate.hpp circuit.hpp
	${CC} -c Input.cpp -o ${BUILD_DIR}/Input.o

${BUILD_DIR}/Update_Gate.o: Update_Gate.cpp Update_Gate.hpp Exceptions.hpp Input.hpp Gate.hpp Wire.hpp circuit.hpp
	${CC} -c Update_Gate.cpp -o ${BUILD_DIR}/Update_Gate.o

${BUILD_DIR}/Gate.o: Gate.cpp Gate.hpp Wire.hpp circuit.hpp Input.hpp Update_Gate.hpp Exceptions.hpp
	${CC} -c Gate.cpp -o ${BUILD_DIR}/Gate.o

${BUILD_DIR}/Wire.o: Wire.cpp Wire.hpp circuit.hpp Exceptions.hpp Gate.hpp Input.hpp Update_Gate.hpp 
	${CC} -c Wire.cpp -o ${BUILD_DIR}/Wire.o

${BUILD_DIR}/circuit.o: circuit.cpp circuit.hpp Gate.hpp Update_Gate.hpp Input.hpp Exceptions.hpp Wire.hpp
	${CC} -c circuit.cpp -o ${BUILD_DIR}/circuit.o

.PHONY: clean
clean:
	rm -rf build/ && mkdir -p build