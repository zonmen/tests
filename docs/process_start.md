# Process start
Back to [README.md](../README.md)



## Description:
//Scheme


## Syntax:


## Parameters:
set_prog_start - Reference on structure contains information about process, that we need to start

## Returns:
1. On success - pid_t,process id, which was launched.
2. On error - 0, if we couldn't do fork. 

If we have some errors in child-part, child process will: 
* indicate another program wasn't laucnhed(change program.pid to zero)
* print error logs
* do exit(1)

## Example Code: