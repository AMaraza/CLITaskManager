#include <iostream>
#include <vector>
#include <sstream>
#include <string>


class Task{
	public:
	 std::string taskName;
	 int taskCategory;
	 Task(std::string name, int category){
		taskName = name;
		taskCategory = category;
	 }
};

std::vector<std::string> splitString(const std::string& str, char delimiter);
void resolveCommand(std::vector<std::string>& command, std::vector<Task>& tasks, bool& isRunning);
void displayTasks(std::vector<Task>& tasks);

int main(){
	bool isRunning = true;
	std::vector<Task> tasks;

	do{
		displayTasks(tasks);

		//Commands: help, new, delete, move
		std::string command;
		std::getline(std::cin, command);
		std::vector<std::string> deconstructedCommand = splitString(command, ' ');

		resolveCommand(deconstructedCommand, tasks, isRunning);
	}
	while(isRunning);


	return 0; 
}

std::vector<std::string> splitString(const std::string& str , char delimiter){
	std::vector<std::string>tokens;
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delimiter)){
		tokens.push_back(token);
	}
	return tokens;
}



void displayTasks(std::vector<Task>& tasks){
	system("clear");
	int numCategories = 3;
	int toDoTaskCount = 0;
	int inProgressTaskCount = 0;
	int completeTaskCount = 0;
	std::cout << "-------------TO DO-------------\n";
	
	for (int i = 0; i < tasks.size(); i++){
		if (tasks[i].taskCategory == 0){
			toDoTaskCount++;
			std::cout << toDoTaskCount << ". "  << tasks[i].taskName + "\n\n";
		}
	}
	
	std::cout << "----------IN PROGRESS----------\n";
	for (int i = 0; i < tasks.size(); i++){
		if (tasks[i].taskCategory == 1){
			inProgressTaskCount++;
			std::cout << inProgressTaskCount << ". " << tasks[i].taskName + "\n\n";
		}
	}	

	std::cout << "------------COMPLETE-----------\n";


	std::cout << "\n\nEnter Command or Type Help Command (help, h)\n";
}


void resolveCommand(std::vector<std::string>& command, std::vector<Task>& tasks, bool& isRunning){
	if (command[0] == "n"){
		Task newTask("", 0);
		for (int i = 1; i < command.size(); i++){
			newTask.taskName += command[i] + " ";
		}
		tasks.push_back(newTask);
	}
	else if (command[0] == d){
		try{
			int categoryNum;
			int taskNum;
		}
	}
	else if (command[0] == "q"){
		isRunning = false;
	}	
}
