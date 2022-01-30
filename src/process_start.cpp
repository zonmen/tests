#include "process_start.h"


int start_process(string name, string path)
{
	pid_t pid;
	//create new process
	pid = fork();
	if( pid == -1 )
	{
		//error of creation process
		cout << "error" << endl;
		exit(1);
	} else if( pid != 0 )
	{
		//parent process
		// wait(nullptr);
		// cout << "parent:: child pid = " << pid << endl;
		// cout << "parent:: parent pid = " << getpid() << endl;;
		// return child pid
		return pid;
	} else 
	{
		//child process
		cout << "child:: child pid = " << getpid() << endl;
		cout << "child:: parent pid = " << getppid() << endl;
		//pointer to program name
		char *program_name = new char [ name.length() + 1 ];
		//copy program name
		strcpy(program_name, name.c_str());
		//number of process arguments(first - program name, last - NULL)
		char *argv[] = {program_name, nullptr};
		//start new process(change current process to new)
		execv(path.c_str(), argv);
		cout << "Process never riches these lines" << endl;
	}
	
}

int start_process(string name, string path, vector<string> arguments)
{
	pid_t pid;
	//create new process
	pid = fork();
	if( pid == -1 )
	{
		//error of creation process
		cout << "error" << endl;
		exit(1);
	} else if( pid != 0 )
	{
		//parent process
		// wait(nullptr);
		// cout << "parent:: child pid = " << pid << endl;
		// cout << "parent:: parent pid = " << getpid() << endl;;
		// return child pid
		return pid;
	} else 
	{
		//child process
		cout << "child:: child pid = " << getpid() << endl;
		cout << "child:: parent pid = " << getppid() << endl;
		//number of process arguments(first - program name, last - NULL)
		int argc = arguments.size() + 2;
		//pointer to process arguments
		char **argv = new char* [ argc ];
		//first argument - program name
		argv[0] = new char[ name.length() + 1 ];
		//copy program name to arguments array
		strcpy( argv[0], name.c_str());
		//copy all arguments to arguments array
		for(int i = 1; i < argc - 1; i++)
		{
			argv[i] = new char [ (arguments[i-1].length() + 1) ];
			strcpy( argv[i], arguments[i-1].c_str() );
		}
		//last arguments - NULL
		argv[argc - 1] =  nullptr;
		//start new process(change current process to new)
		execv(path.c_str(), argv);
		cout << "Process never riches these lines" << endl;
	}
	
}



int start_process(string name, string path, string stdout_file, bool stdout_mode)
{
	pid_t pid;
	//create new process
	pid = fork();
	if( pid == -1 )
	{
		//error of creation process
		cout << "error" << endl;
		exit(1);
	} else if( pid != 0 )
	{
		//parent process
		// wait(nullptr);
		// cout << "parent:: child pid = " << pid << endl;
		// cout << "parent:: parent pid = " << getpid() << endl;;
		// return child pid
		return pid;
	} else 
	{
		//change file mode depending of stdout_mode
		if( stdout_mode )
		{
			freopen( stdout_file.c_str(), "a", stdout);
		} else
		{
			freopen( stdout_file.c_str(), "w", stdout);	
		}
		//child process
		cout << "child:: child pid = " << getpid() << endl;
		cout << "child:: parent pid = " << getppid() << endl;
		//pointer to program name
		char *program_name = new char [ name.length() + 1 ];
		//copy program name
		strcpy(program_name, name.c_str());
		//number of process arguments(first - program name, last - NULL)
		char *argv[] = {program_name, nullptr};
		//start new process(change current process to new)
		execv(path.c_str(), argv);
		cout << "Process never riches these lines" << endl;
	}
}