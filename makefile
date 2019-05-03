OBJECTS = skill.o date.o experience.o job.o JobReq.o user.o company.o database.o interface.o main.o

all : a.out
a.out : $(OBJECTS)
	g++ $(OBJECTS)
skill.o : skill.cpp
	g++ -c skill.cpp
date.o : date.cpp
	g++ -c date.cpp
experience.o : experience.cpp
	g++ -c experience.cpp
job.o : job.cpp
	g++ -c job.cpp
JobReq.o : JobReq.cpp
	g++ -c JobReq.cpp
user.o : user.cpp
	g++ -c user.cpp
company.o : company.cpp
	g++ -c company.cpp
database.o : database.cpp
	g++ -c database.cpp
interface.o : interface.cpp
	g++ -c interface.cpp
main.o : main.cpp
	g++ -c main.cpp
clean:
	rm -f $(OBJECTS) a.out